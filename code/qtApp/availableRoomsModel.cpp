#include "availableRoomsModel.h"

availableRoomsModel::availableRoomsModel(QObject* parent, const viewParameters* parameters)
    :QAbstractTableModel(parent)
{
    db = parameters->dbConnection->getDbPtr();
}

QVariant availableRoomsModel::data(const QModelIndex & index, int role) const
{
    if(role == Qt::DisplayRole | role == Qt::EditRole)
    {
        return model.record(index.row()).value(index.column()).toString();
    }

    return QVariant();
}

QVariant availableRoomsModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("Room nr");
            case 1:
                return QString("Name");
            case 2:
                return QString("Price per night");
            case 3:
                return QString("Nr of beds");
            case 4:
                return QString("Type of room");
            case 5:
                return QString("Balcony");
            }
        }
    }
    return QVariant();
}

int availableRoomsModel::rowCount(const QModelIndex & /*parent*/) const
{
    if(model.rowCount() < 99)
        return 99;
    else
        return model.rowCount();
}

int availableRoomsModel::columnCount(const QModelIndex & /*parent*/) const
{
    if(model.columnCount() < 14)
        return 14;
    else
        return model.columnCount();
}

void availableRoomsModel::searchForAvailableRooms(QString &from, QString &to)
{
    QString availableRoomQuery = QString("SELECT * FROM Room "
                                 "Left OUTER JOIN Current_Reservation "
                                 "ON Current_Reservation.roomNr = Room.roomNr "
                                 "WHERE '%1T00:00:00.000' < checkInDate "
                                         "AND '%2T00:00:00.000' < checkInDate "
                                 "OR '%1T00:00:00.000' > checkOutDate "
                                         "AND '%2T00:00:00.000' > checkOutDate "
                                 "OR checkInDate is NULL").arg(from, to);

    model.setQuery(availableRoomQuery);

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

    //inform table, that data have changed in the whole table
    QModelIndex topLeft = createIndex(0,0);
    QModelIndex bottomRight = createIndex( model.rowCount(), model.columnCount() );

    emit dataChanged(topLeft, bottomRight);
}

void availableRoomsModel::insertCurrent_Reservation(QString bookingNr, QString roomNr, int ssNr, QDate checkInDate, QDate checkOutDate, int totalPrice, int extraBed, QDate actuallyCheckInDate, QString addedByUser)
{
    /*QString createBookingQuery = QString("INSERT into Current_Reservation "
                                         "VALUES ('%1', '%2', '%3', '%4', '%5', '%6', '%7', '%8', '%9')").arg(bookingNr, roomNr, ssNr, checkInDate, checkOutDate, totalPrice, extraBed, actuallyCheckInDate, addedByUser);*/
    //model.setQuery(createBookingQuery);

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
}

void availableRoomsModel::insertOld_Reservation(QString bookingNr, QString roomNr, int ssNr, QDate checkInDate, QDate checkOutDate, int totalPrice, int extraBed, QDate actuallyCheckInDate, QDate actuallyCheckOutDate, bool ifDeleted, QDate whenDeletedDate, QString addedByUser, QString deletedByUser)
{

}

int availableRoomsModel::calculateTotalPrice(int price, QDate checkInDate, QDate checkOutDate)
{
    int daysBetweenDates = checkInDate.daysTo(checkOutDate);
    int totalPrice = price*daysBetweenDates;

    return totalPrice;
}
