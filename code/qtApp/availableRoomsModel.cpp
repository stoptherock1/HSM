#include "availableRoomsModel.h"

availableRoomsModel::availableRoomsModel(QObject* parent, const viewParameters* parameters)
    :QAbstractTableModel(parent)
{
    db = parameters->dbConnection->getDbPtr();
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

QVariant availableRoomsModel::data(const QModelIndex & index, int role) const
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


QVariant availableRoomsModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal)
        {
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

        if (orientation == Qt::Vertical)
            return section + 1;
    }
    return QVariant();
}

bool availableRoomsModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role == Qt::EditRole)
      {
          //save value from editor to member m_gridData
          m_gridData[index.row()][index.column()] = value.toString();
          //for presentation purposes only: build and emit a joined string
          QString result;
          for(int row= 0; row < ROWS; row++)
          {
              for(int col= 0; col < COLS; col++)
              {
                  result += m_gridData[row][col] + " ";
              }
          }
          emit editCompleted( result );
      }
      return true;
}

Qt::ItemFlags availableRoomsModel::flags(const QModelIndex & /*index*/) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled;
}



void availableRoomsModel::searchForAvailableRooms(QString &from, QString &to)
{
    QString availableRoomQuery = QString("SELECT DISTINCT Room.roomNr, Room.name, Room.price, Room.nrOfBeds, Room.typeOfRoom, Room.balcony, Room.additionalNotes "
                                 "FROM Room Left OUTER JOIN Current_Reservation "
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

int availableRoomsModel::getBedsNumber(int row)
{
    return model.record(row).value(3).toInt();
}
