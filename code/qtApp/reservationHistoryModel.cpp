#include "reservationHistoryModel.h"

reservationHistoryModel::reservationHistoryModel(QObject* parent, viewParameters *parameters_)
    :QSqlTableModel(parent),
      parameters(parameters_)
{
    setTable("Old_Reservation");
    select();
}


QVariant reservationHistoryModel::data(const QModelIndex & index, int role) const
{
    int row = index.row();
    int column = index.column();

    if(Qt::DisplayRole == role)
    {
        if(6 == column && Qt::DisplayRole == role)
            return QVariant();

        return QSqlTableModel::data(index, role);
    }

    if( Qt::CheckStateRole == role && 6 == column && row < QSqlTableModel::rowCount() )
    {
        if( 1 == QSqlTableModel::data(index, Qt::DisplayRole).toInt() )
            return Qt::Checked;

        else if( 0 == QSqlTableModel::data(index, Qt::DisplayRole).toInt() )
            return Qt::Unchecked;
    }

    return QVariant();
}

int reservationHistoryModel::rowCount(const QModelIndex & /*parent*/) const
{
    if(QSqlTableModel::rowCount() < 99)
        return 99;
    else
        return QSqlTableModel::rowCount();
}

int reservationHistoryModel::columnCount(const QModelIndex & /*parent*/) const
{
    if(QSqlTableModel::columnCount() < 10)
        return 10;
    else
        return QSqlTableModel::columnCount();
}

QVariant reservationHistoryModel::headerData(int section, Qt::Orientation orientation, int role) const
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
                return QString("SSNr");
            case 3:
                return QString("Check in date");
            case 4:
                return QString("Check out date");
            case 5:
                return QString("Total price");
            case 6:
                return QString("Extra Bed");
            case 7:
                return QString("Actual\ncheck in date");
            case 8:
                return QString("Actual\ncheck out date");
            case 9:
                return QString("ifDeleted");
            case 10:
                return QString("When deleted");
            case 11:
                return QString("Added by user");
            case 12:
                return QString("Deleted by user");
            }
        }

        if (orientation == Qt::Vertical)
            return section + 1;
    }
    return QVariant();
}

Qt::ItemFlags reservationHistoryModel::flags(const QModelIndex & /*index*/) const
{
    Qt::ItemFlags result = Qt::ItemIsSelectable | Qt::ItemIsEnabled;

    return result;

}

