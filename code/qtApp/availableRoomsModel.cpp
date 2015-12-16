#include "availableRoomsModel.h"

availableRoomsModel::availableRoomsModel(QObject* parent/*, const viewParameters* parameters*/)
    :QAbstractTableModel(parent)
{

    //db = dbConnection->getDbPtr();
    QString availableRoomQuery = "SELECT * FROM Room ";
                                 "Left OUTER JOIN Current_Reservation "
                                 "ON Current_Reservation.roomNr = Room.roomNr "
                                 "WHERE checkInDate < '2015-12-01T00:00:00.000' "
                                 "or checkInDate is NULL";
    qDebug() << availableRoomQuery;

    model.setQuery(availableRoomQuery);

}

int availableRoomsModel::rowCount(const QModelIndex & /*parent*/) const
{
    return model.rowCount();
}

int availableRoomsModel::columnCount(const QModelIndex & /*parent*/) const
{
    return model.columnCount();
}

void availableRoomsModel::searchForAvailableRooms(QString &from, QString &to)
{
    //QModelIndex topLeft = createIndex(0,0);

    QString availableRoomQuery = QString("SELECT * FROM Room "
                                 "Left OUTER JOIN Current_Reservation "
                                 "ON Current_Reservation.roomNr = Room.roomNr "
                                 "WHERE '%1T00:00:00.000' < checkInDate AND '%2T00:00:00.000' < checkInDate "
                                 "OR '%1T00:00:00.000' > checkOutDate AND '%2T00:00:00.000' > checkOutDate "
                                 "OR checkInDate is NULL").arg(from, to);

    model.setQuery(availableRoomQuery);
    //emit dataChanged(topLeft, topLeft);
}


QVariant availableRoomsModel::data(const QModelIndex & index, int role) const
{
    qDebug() << Q_FUNC_INFO;


    if (role == Qt::DisplayRole)
    {
       return model.record(index.row()).value(index.column()).toString();
    }
    return QVariant();
}

