#include "roomModel.h"

roomModel::roomModel(QObject* parent, viewParameters *parameters_)
    :QSqlTableModel(parent),
      parameters(parameters_)
{
    db = parameters->dbConnection->getDbPtr();

    setTable("Room");
    setEditStrategy(QSqlTableModel::OnFieldChange);
    select();
}

bool roomModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if( Qt::CheckStateRole == role && 5 == index.column() )
    {
        if(0 == value)
            return QSqlTableModel::setData(index, "0", Qt::EditRole);
        else
            return QSqlTableModel::setData(index, "1", Qt::EditRole);
    }
    return QSqlTableModel::setData(index, value, role);
}

QVariant roomModel::data(const QModelIndex & index, int role) const
{
    int row = index.row();
    int column = index.column();

    if(Qt::DisplayRole == role || Qt::EditRole == role)
    {
        if(5 == column && Qt::DisplayRole == role)
            return QVariant();

        return QSqlTableModel::data(index, role);
    }

    if( Qt::CheckStateRole == role && 5 == column && row < QSqlTableModel::rowCount() )
    {
        if( 1 == QSqlTableModel::data(index, Qt::DisplayRole).toInt() )
            return Qt::Checked;

        else if( 0 == QSqlTableModel::data(index, Qt::DisplayRole).toInt() )
            return Qt::Unchecked;
    }

    return QVariant();
}

int roomModel::rowCount(const QModelIndex & /*parent*/) const
{
    if(QSqlTableModel::rowCount() < 99)
        return 99;
    else
        return QSqlTableModel::rowCount();
}

int roomModel::columnCount(const QModelIndex & /*parent*/) const
{
    if(QSqlTableModel::columnCount() < 7)
        return 7;
    else
        return QSqlTableModel::columnCount();
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
                return QString("Room nr");
            case 1:
                return QString("Room name");
            case 2:
                return QString("Price");
            case 3:
                return QString("Nr of beds");
            case 4:
                return QString("Room type");
            case 5:
                return QString("Balcony");
            case 6:
                return QString("Additional notes");
            }
        }

        if (orientation == Qt::Vertical)
            return section + 1;
    }
    return QVariant();
}

Qt::ItemFlags roomModel::flags(const QModelIndex & index) const
{
    Qt::ItemFlags result = Qt::ItemIsSelectable | Qt::ItemIsEnabled;

    if( 5 == index.column() )
        result |= Qt::ItemIsUserCheckable;

        result |= Qt::ItemIsEditable;

    return result;
}

void roomModel::addNewRoom(newRoom &room)
{
    QString balcony = room.balcony ? "1" : "0";
    QString addNewRoomQuery = QString("INSERT into Room "
                                      "VALUES ('%1', '%2', '%3', '%4', '%5', '%6', '%7')")
            .arg(room.roomNr,
                 room.roomName,
                 room.price,
                 room.nrOfBeds,
                 room.roomType,
                 balcony,
                 room.additionalNotes);

    sqlQuery.exec(addNewRoomQuery);

    if( sqlQuery.lastError().isValid() )
    {
        qDebug() << sqlQuery.lastError();
        QMessageBox::critical(0,
                              "Cannot set query",
                              QString("Unable to set query."
                                      "\nReason: %1\nClick Cancel to "
                                      "exit.").arg( sqlQuery.lastError().text() ),
                              QMessageBox::Cancel);
    }

    select();
}
