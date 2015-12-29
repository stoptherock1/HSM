#include "reservationModel.h"

reservationModel::reservationModel(QObject* parent, const viewParameters* parameters)
    :QAbstractTableModel(parent)
{
    db = parameters->dbConnection->getDbPtr();
}

QVariant reservationModel::data(const QModelIndex & index, int role) const
{
    int row = index.row();
    int column = index.column();

    if(Qt::DisplayRole == role || Qt::EditRole == role)
    {
        if(5 == column && Qt::DisplayRole == role)
            return QVariant();

        return model.record(row).value(column);
    }

    if( Qt::CheckStateRole == role && 5 == column && row < model.rowCount() )
    {
        if( 1 == model.record(row).value(column).toInt() )
            return Qt::Checked;
        else if( 0 == model.record(row).value(column).toInt() )
            return Qt::Unchecked;
    }

    return QVariant();
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
    if(model.columnCount() < 14)
        return 14;
    else
        return model.columnCount();
}

void reservationModel::insertCurrent_Reservation(QString bookingNr, QString roomNr, int ssNr, QDate checkInDate, QDate checkOutDate, int totalPrice, int extraBed, QDate actuallyCheckInDate, QString addedByUser)
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

void reservationModel::insertOld_Reservation(QString bookingNr, QString roomNr, int ssNr, QDate checkInDate, QDate checkOutDate, int totalPrice, int extraBed, QDate actuallyCheckInDate, QDate actuallyCheckOutDate, bool ifDeleted, QDate whenDeletedDate, QString addedByUser, QString deletedByUser)
{

}
