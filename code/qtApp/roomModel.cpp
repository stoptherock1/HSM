#include "roomModel.h"

roomModel::roomModel(QObject* parent, const viewParameters* parameters)
    :QAbstractTableModel(parent)
{
     db = parameters->dbConnection->getDbPtr();
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

bool roomModel::setData(const QModelIndex &index, const QVariant &value, int role)
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

Qt::ItemFlags roomModel::flags(const QModelIndex & /*index*/) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

