#include "reservationModel.h"

reservationModel::reservationModel(QObject* parent, const viewParameters* parameters)
    :QSqlTableModel(parent)
{
    db = parameters->dbConnection->getDbPtr();
//    readCurrentReservationsTable();

    setTable("Current_reservation");
//    setEditStrategy(QSqlTableModel::OnManualSubmit);
    setEditStrategy(QSqlTableModel::OnFieldChange);
    select();
}




int reservationModel::rowCount(const QModelIndex & /*parent*/) const
{
    if(QSqlTableModel::rowCount() < 99)
        return 99;
    else
        return QSqlTableModel::rowCount();

}

int reservationModel::columnCount(const QModelIndex & /*parent*/) const
{
    if(QSqlTableModel::columnCount() < 9)
        return 9;
    else
        return QSqlTableModel::columnCount();
}

QVariant reservationModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal)
        {
            switch (section)
            {
            case 0:
                return QString("Booking nr");
            case 1:
                return QString("Room nr");
            case 2:
                return QString("SSN");
            case 3:
                return QString("Check-In date");
            case 4:
                return QString("Check-Out date");
            case 5:
                return QString("Total Price");
            case 6:
                return QString("Extra bed");
            case 7:
                return QString("Actually check-In date");
            case 8:
                return QString("Added by user");
            }
        }

        if (orientation == Qt::Vertical)
            return section + 1;
    }
    return QVariant();
}

QVariant reservationModel::data(const QModelIndex & index, int role) const
{
    int row = index.row();
    int column = index.column();

    if(Qt::DisplayRole == role || Qt::EditRole == role)
    {
        if(6 == column && Qt::DisplayRole == role)
            return QVariant();

        return QSqlTableModel::data(index, role);
    }

    if( Qt::CheckStateRole == role && 6 == column && row < QSqlTableModel::rowCount() )
    {
        if( 1 == QSqlTableModel::data(index, role).toInt() )
        {
            return Qt::Checked;
        }
        else if( 0 == QSqlTableModel::data(index, role).toInt() )
            return Qt::Unchecked;
    }

    return QVariant();
}

reservationModel::~reservationModel()
{

}

Qt::ItemFlags reservationModel::flags(const QModelIndex & /*index*/) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled;
}


int reservationModel::calculateTotalPrice(int price, QDate checkInDate, QDate checkOutDate)
{
    int daysBetweenDates = checkInDate.daysTo(checkOutDate);
    int totalPrice = price*daysBetweenDates;

    return totalPrice;
}

/*
void reservationModel::insertCurrent_Reservation(QString roomNr,
                                                 QString ssNr,
                                                 QDate checkInDateInt,
                                                 QDate checkOutDateInt,
                                                 int extraBedInt,
                                                 QString addedByUser)
{
    //Generate booking nr (the gratest number from old and current reservations)
    int currentBookingNrInt = 0;
    int oldBookingNrInt = 0;

    QString getLastBookingNrQuery = QString("SELECT MAX(bookingNr) FROM Current_Reservation");
    oldModel.setQuery(getLastBookingNrQuery);
    if( 0 != oldModel.rowCount() )
        currentBookingNrInt = oldModel.record(0).value(0).toInt();

    getLastBookingNrQuery = QString("SELECT MAX(bookingNr) FROM Old_Reservation");
    oldModel.setQuery(getLastBookingNrQuery);
    if( 0 != oldModel.rowCount() )
        oldBookingNrInt = oldModel.record(0).value(0).toInt();

    int bookingNrInt = (oldBookingNrInt >= currentBookingNrInt) ? oldBookingNrInt : currentBookingNrInt;
    ++bookingNrInt;

    //Get the total price
    QString getRoomPriceQuery = QString("SELECT price FROM Room WHERE roomNr = '%1'").arg(roomNr);
    oldModel.setQuery(getRoomPriceQuery);
    int price = oldModel.record(0).value(0).toInt();
    int totalPriceInt = this->calculateTotalPrice(price, checkInDateInt, checkOutDateInt);

    //Convert ints to strings
    QString bookingNr = QString::number(bookingNrInt);
    QString totalPrice = QString::number(totalPriceInt);
    QString extraBed = QString::number(extraBedInt);
    QString checkInDate = checkInDateInt.toString("yyyy-MM-dd");
    QString checkOutDate = checkOutDateInt.toString("yyyy-MM-dd");

    qDebug() << QString("INSERT INTO Current_Reservation "
                        "(bookingNr, roomNr, ssNr, checkInDate, checkOutDate, totalPrice, extraBed, addedByUser) "
                        "VALUES ('%1', '%2', '%3', '%4', '%5', '%6', '%7', '%8')"
                        ).arg(bookingNr, roomNr, ssNr, checkInDate, checkOutDate, totalPrice, extraBed, addedByUser);

    QString createBookingQuery = QString("INSERT INTO Current_Reservation "
                                         "(bookingNr, roomNr, ssNr, checkInDate, checkOutDate, totalPrice, extraBed, addedByUser) "
                                         "VALUES ('%1', '%2', '%3', '%4', '%5', '%6', '%7', '%8')"
                                         ).arg(bookingNr, roomNr, ssNr, checkInDate, checkOutDate, totalPrice, extraBed, addedByUser);
    oldModel.setQuery(createBookingQuery);

    if( oldModel.lastError().isValid() )
    {
        qDebug() << oldModel.lastError();
        QMessageBox::critical(0,
                              "Cannot set query",
                              QString("Unable to set query."
                                      "\nReason: %1\nClick Cancel to "
                                      "exit.").arg( oldModel.lastError().text() ),
                              QMessageBox::Cancel);
    }

    //replace with readCurrentReservationsTable() call
    readCurrentReservationsTable();
//    //inform table, that data have changed in the whole table
//    QModelIndex topLeft = createIndex(0,0);
//    QModelIndex bottomRight = createIndex( model.rowCount(), model.columnCount() );

//    emit dataChanged(topLeft, bottomRight);
}

void reservationModel::insertOld_Reservation(int bookingNrInt)
{
    //Get data from Current_Reservation table before checkout
    QString getDataFromCurrent_ReservationQuery = QString("SELECT * FROM Current_Reservation WHERE bookingNr = '%1'").arg(bookingNrInt);
    oldModel.setQuery(getDataFromCurrent_ReservationQuery);

    if( 0 ==  oldModel.rowCount() )
    {
        QMessageBox::critical(0,
                              "",
                              QString("An error occured while checking out; check the code."),
                              QMessageBox::Cancel);
        return;
    }


    QString bookingNr = QString::number(bookingNrInt);
    QString roomNr = oldModel.record(0).value("roomNr").toString();
    QString ssNr = oldModel.record(0).value("ssNr").toString();
    QString checkInDate = oldModel.record(0).value("checkInDate").toString();
    QString checkOutDate = oldModel.record(0).value("checkOutDate").toString();
    QString totalPrice = oldModel.record(0).value("totalPrice").toString();
    QString extraBed = oldModel.record(0).value("extraBed").toString();
    QString actuallyCheckInDate = oldModel.record(0).value("actuallyCheckInDate").toString();
    QString addedByUser= oldModel.record(0).value("addedByUser").toString();

    //Set check out date and not deleted
    QString actuallyCheckOutDate = QDate::currentDate().toString("yyyy-MM-dd");
    QString ifDeleted = "0";

    QString insertOld_ReservationQuery = QString("INSERT INTO Old_Reservation "
                                                 "(bookingNr, roomNr, ssNr, checkInDate, checkOutDate, totalPrice, extraBed,"
                                                 " actuallyCheckInDate, actuallyCheckOutDate, ifDeleted, addedByUser) "
                                                 "VALUES ('%1', '%2', '%3', '%4', '%5', '%6', '%7', '%8', '%9', '%10', '%11')"
                                                 ).arg(bookingNr, roomNr, ssNr, checkInDate, checkOutDate, totalPrice, extraBed,
                                                       actuallyCheckInDate, actuallyCheckOutDate).arg(ifDeleted, addedByUser);

    qDebug() << insertOld_ReservationQuery;

    oldModel.setQuery(insertOld_ReservationQuery);

    if( oldModel.lastError().isValid() )
    {
        qDebug() << oldModel.lastError();
        QMessageBox::critical(0,
                              "Cannot set query",
                              QString("Unable to set query."
                                      "\nReason: %1\nClick Cancel to "
                                      "exit.").arg( oldModel.lastError().text() ),
                              QMessageBox::Cancel);
    }

    //Check out from Current_Reservation
    this->deleteCurrent_Reservation(bookingNrInt);

    //replace with readCurrentReservationsTable() call
    //inform table, that data have changed in the whole table
    QModelIndex topLeft = createIndex(0,0);
    QModelIndex bottomRight = createIndex( oldModel.rowCount(), oldModel.columnCount() );

    emit dataChanged(topLeft, bottomRight);
}

void reservationModel::deleteCurrent_Reservation(int bookingNrInt)
{
    QString deleteCurrent_ReservationQuery = QString("DELETE FROM Current_Reservation "
                                                     "WHERE bookingNr = '%1'").arg(bookingNrInt);
    oldModel.setQuery(deleteCurrent_ReservationQuery);

    if( oldModel.lastError().isValid() )
    {
        qDebug() << oldModel.lastError();
        QMessageBox::critical(0,
                              "Cannot set query",
                              QString("Unable to set query."
                                      "\nReason: %1\nClick Cancel to "
                                      "exit.").arg( oldModel.lastError().text() ),
                              QMessageBox::Cancel);
    }

    readCurrentReservationsTable();

    //inform table, that data have changed in the whole table
    QModelIndex topLeft = createIndex(0,0);
    QModelIndex bottomRight = createIndex( oldModel.rowCount(), oldModel.columnCount() );

    emit dataChanged(topLeft, bottomRight);
}

void reservationModel::deleteOld_Reservation(int bookingNrInt)
{
    QString deleteCurrent_ReservationQuery = QString("DELETE FROM Old_Reservation WHERE bookingNr = '%1'").arg(bookingNrInt);
    oldModel.setQuery(deleteCurrent_ReservationQuery);

    if( oldModel.lastError().isValid() )
    {
        qDebug() << oldModel.lastError();
        QMessageBox::critical(0,
                              "Cannot set query",
                              QString("Unable to set query."
                                      "\nReason: %1\nClick Cancel to "
                                      "exit.").arg( oldModel.lastError().text() ),
                              QMessageBox::Cancel);
    }

    //replace with readCurrentReservationsTable() call
    //inform table, that data have changed in the whole table
    QModelIndex topLeft = createIndex(0,0);
    QModelIndex bottomRight = createIndex( oldModel.rowCount(), oldModel.columnCount() );

    emit dataChanged(topLeft, bottomRight);
}


void reservationModel::performActualCheckIn(int bookingNrInt)
{
    QString actuallyCheckInDate =       QDate::currentDate().toString("yyyy-MM-dd");
    QString query = QString("UPDATE Current_reservation "
                            "SET actuallyCheckInDate = '%1' "
                            "WHERE bookingNr = '%2'").arg( actuallyCheckInDate,
                                                           QString::number(bookingNrInt) );
    oldModel.setQuery(query);

    qDebug() << query;


    readCurrentReservationsTable();
}

void reservationModel::readCurrentReservationsTable()
{
    oldModel.setQuery("SELECT * FROM Current_reservation");

    qDebug() << "model.rowCount(): " << oldModel.rowCount();

    //inform table, that data have changed in the whole table
    QModelIndex topLeft = createIndex(0,0);
    QModelIndex bottomRight = createIndex( oldModel.rowCount(),
                                           oldModel.columnCount() );

    emit dataChanged(topLeft, bottomRight);
}
*/

void reservationModel::insertCurrent_Reservation(QString roomNr,
                               QString ssNr,
                               QDate checkInDateInt,
                               QDate checkOutDateInt,
                               int extraBedInt,
                               QString addedByUser)
{

}


void reservationModel::insertOld_Reservation(int bookingNrInt)
{}

void reservationModel::deleteCurrent_Reservation(int bookingNrInt)
{}

void reservationModel::deleteOld_Reservation(int bookingNrInt)
{}

void reservationModel::readCurrentReservationsTable()
{}

void reservationModel::performActualCheckIn(int bookingNrInt)
{}

