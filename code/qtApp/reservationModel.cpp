#include "reservationModel.h"

reservationModel::reservationModel(QObject* parent, const viewParameters* parameters)
    :QAbstractTableModel(parent)
{
    db = parameters->dbConnection->getDbPtr();
    readCurrentReservationsTable();
}

void reservationModel::readCurrentReservationsTable()
{
    model.setQuery("SELECT * FROM Current_reservation");

    qDebug() << "model.rowCount(): " << model.rowCount();

    //inform table, that data have changed in the whole table
    QModelIndex topLeft = createIndex(0,0);
    QModelIndex bottomRight = createIndex( model.rowCount(),
                                           model.columnCount() );

    emit dataChanged(topLeft, bottomRight);
}

int reservationModel::rowCount(const QModelIndex & /*parent*/) const
{
    if(model.rowCount() < 99)
        return 99;
    else
        return model.rowCount();
}

int reservationModel::columnCount(const QModelIndex & /*parent*/) const
{
    if(model.columnCount() < 9)
        return 9;
    else
        return model.columnCount();
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
        return model.record(row).value(column);

    return QVariant();
}

bool reservationModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role == Qt::EditRole)
      {
          //save value from editor to member m_gridData
//          m_gridData[index.row()][index.column()] = value.toString();
          //for presentation purposes only: build and emit a joined string
          QString result;
//          for(int row= 0; row < ROWS; row++)
//          {
//              for(int col= 0; col < COLS; col++)
//              {
//                  result += m_gridData[row][col] + " ";
//              }
//          }
          emit editCompleted( result );
      }
      return true;
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
    model.setQuery(getLastBookingNrQuery);
    if( 0 != model.rowCount() )
        currentBookingNrInt = model.record(0).value(0).toInt();

    getLastBookingNrQuery = QString("SELECT MAX(bookingNr) FROM Old_Reservation");
    model.setQuery(getLastBookingNrQuery);
    if( 0 != model.rowCount() )
        oldBookingNrInt = model.record(0).value(0).toInt();

    int bookingNrInt = (oldBookingNrInt >= currentBookingNrInt) ? oldBookingNrInt : currentBookingNrInt;
    ++bookingNrInt;


    //Get the total price
    QString getRoomPriceQuery = QString("SELECT price FROM Room WHERE roomNr = '%1'").arg(roomNr);
    model.setQuery(getRoomPriceQuery);
    int price = model.record(0).value(0).toInt();
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
    model.setQuery(createBookingQuery);

    if( model.lastError().isValid() )
    {
        qDebug() << model.lastError();
        QMessageBox::critical(0,
                              "Cannot set query",
                              QString("Unable to set query."
                                      "\nReason: %1\nClick Cancel to "
                                      "exit.").arg( model.lastError().text() ),
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
    model.setQuery(getDataFromCurrent_ReservationQuery);

    if( 0 ==  model.rowCount() )
    {
        QMessageBox::critical(0,
                              "",
                              QString("An error occured while checking out; check the code."),
                              QMessageBox::Cancel);
        return;
    }


    QString bookingNr = QString::number(bookingNrInt);
    QString roomNr = model.record(0).value("roomNr").toString();
    QString ssNr = model.record(0).value("ssNr").toString();
    QString checkInDate = model.record(0).value("checkInDate").toString();
    QString checkOutDate = model.record(0).value("checkOutDate").toString();
    QString totalPrice = model.record(0).value("totalPrice").toString();
    QString extraBed = model.record(0).value("extraBed").toString();
    QString actuallyCheckInDate = model.record(0).value("actuallyCheckInDate").toString();
    QString addedByUser= model.record(0).value("addedByUser").toString();

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

    model.setQuery(insertOld_ReservationQuery);

    if( model.lastError().isValid() )
    {
        qDebug() << model.lastError();
        QMessageBox::critical(0,
                              "Cannot set query",
                              QString("Unable to set query."
                                      "\nReason: %1\nClick Cancel to "
                                      "exit.").arg( model.lastError().text() ),
                              QMessageBox::Cancel);
    }

    //Check out from Current_Reservation
    this->deleteCurrent_Reservation(bookingNrInt);

    //replace with readCurrentReservationsTable() call
    //inform table, that data have changed in the whole table
    QModelIndex topLeft = createIndex(0,0);
    QModelIndex bottomRight = createIndex( model.rowCount(), model.columnCount() );

    emit dataChanged(topLeft, bottomRight);
}

void reservationModel::deleteCurrent_Reservation(int bookingNrInt)
{
    QString deleteCurrent_ReservationQuery = QString("DELETE FROM Current_Reservation WHERE bookingNr = '%1'").arg(bookingNrInt);
    model.setQuery(deleteCurrent_ReservationQuery);

    if( model.lastError().isValid() )
    {
        qDebug() << model.lastError();
        QMessageBox::critical(0,
                              "Cannot set query",
                              QString("Unable to set query."
                                      "\nReason: %1\nClick Cancel to "
                                      "exit.").arg( model.lastError().text() ),
                              QMessageBox::Cancel);
    }

    readCurrentReservationsTable();

    //inform table, that data have changed in the whole table
    QModelIndex topLeft = createIndex(0,0);
    QModelIndex bottomRight = createIndex( model.rowCount(), model.columnCount() );

    emit dataChanged(topLeft, bottomRight);
}

void reservationModel::deleteOld_Reservation(int bookingNrInt)
{
    QString deleteCurrent_ReservationQuery = QString("DELETE FROM Old_Reservation WHERE bookingNr = '%1'").arg(bookingNrInt);
    model.setQuery(deleteCurrent_ReservationQuery);

    if( model.lastError().isValid() )
    {
        qDebug() << model.lastError();
        QMessageBox::critical(0,
                              "Cannot set query",
                              QString("Unable to set query."
                                      "\nReason: %1\nClick Cancel to "
                                      "exit.").arg( model.lastError().text() ),
                              QMessageBox::Cancel);
    }

    //replace with readCurrentReservationsTable() call
    //inform table, that data have changed in the whole table
    QModelIndex topLeft = createIndex(0,0);
    QModelIndex bottomRight = createIndex( model.rowCount(), model.columnCount() );

    emit dataChanged(topLeft, bottomRight);
}
