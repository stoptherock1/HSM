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
