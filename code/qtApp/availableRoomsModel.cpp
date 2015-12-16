#include "availableRoomsModel.h"

availableRoomsModel::availableRoomsModel(QObject *parent) /*: QAbstractTableModel(parent)*/
{
    model.setQuery("SELECT * FROM Room "
                   "Left OUTER JOIN Current_Reservation "
                   "ON Current_Reservation.roomNr = Room.roomNr "

                   "WHERE checkInDate < '2015-12-01T00:00:00.000'"
                   " or checkInDate is NULL");
}

int availableRoomsModel::rowCount(const QModelIndex &parent) const
{
    qDebug() << Q_FUNC_INFO << model.rowCount();
    return model.rowCount();
}

int availableRoomsModel::columnCount(const QModelIndex &parent) const
{
    qDebug() << Q_FUNC_INFO << model.columnCount();
    return model.columnCount();
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

void availableRoomsModel::searchForAvailableRooms(QString& from, QString& to)
{
    model.setQuery(QString("SELECT * FROM Room "
                           "Left OUTER JOIN Current_Reservation "
                           "ON Current_Reservation.roomNr = Room.roomNr "
                           "WHERE checkInDate < '%1T00:00:00.000'"
                           " or checkInDate is NULL").arg(from));
    QModelIndex topLeft = createIndex(0,0);
    //emit a signal to make the view reread identified data
    emit dataChanged(topLeft, topLeft);
}

