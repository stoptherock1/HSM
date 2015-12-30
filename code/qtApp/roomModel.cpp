#include "roomModel.h"

roomModel::roomModel(QObject* parent, const viewParameters* parameters)
    :QAbstractTableModel(parent)
{
     db = parameters->dbConnection->getDbPtr();
}

QVariant roomModel::data(const QModelIndex & index, int role) const
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

int roomModel::rowCount(const QModelIndex & /*parent*/) const
{
    if(model.rowCount() < 99)
        return 99;
    else
        return model.rowCount();
}

int roomModel::columnCount(const QModelIndex & /*parent*/) const
{
    if(model.columnCount() < 14)
        return 14;
    else
        return model.columnCount();
}

QVariant roomModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal)
        {
            switch (section)
            {
            case 0:
                return QString("");
            case 1:
                return QString("");
            case 2:
                return QString("");
            case 3:
                return QString("");
            case 4:
                return QString("");
            case 5:
                return QString("");
            }
        }

        if (orientation == Qt::Vertical)
            return section + 1;
    }
    return QVariant();
}
