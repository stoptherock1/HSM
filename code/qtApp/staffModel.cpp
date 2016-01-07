#include "staffModel.h"

staffModel::staffModel(QObject* parent, const viewParameters* parameters)
    :QAbstractTableModel(parent)
{
    db = parameters->dbConnection->getDbPtr();
}

int staffModel::rowCount(const QModelIndex & /*parent*/) const
{
    if(model.rowCount() < 99)
        return 99;
    else
        return model.rowCount();
}

int staffModel::columnCount(const QModelIndex & /*parent*/) const
{
    if(model.columnCount() < 14)
        return 14;
    else
        return model.columnCount();
}

QVariant staffModel::data(const QModelIndex & index, int role) const
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

QVariant staffModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal)
        {
            switch (section)
            {
            case 0:
                return QString("Social secirity number");
            case 1:
                return QString("Name");
            case 2:
                return QString("If admin");
            case 3:
                return QString("Username");
            case 4:
                return QString("Password");
            }
        }

        if (orientation == Qt::Vertical)
            return section + 1;
    }
    return QVariant();
}

bool staffModel::setData(const QModelIndex &index, const QVariant &value, int role)
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

Qt::ItemFlags staffModel::flags(const QModelIndex & /*index*/) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled;
}


void staffModel::getUserInfo(QString userName)
{
    QString getUserInfoQuery = QString("SELECT * FROM Staff WHERE userName = '%1'").arg(userName);

    model.setQuery(getUserInfoQuery);

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

void staffModel::getOtherStaffOveralInfo()
{
    QString getOtherStaffOveralInfoQuery = QString("SELECT name, username, ifAdmin FROM Staff");

    model.setQuery(getOtherStaffOveralInfoQuery);

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

QString staffModel::getPassword(QString userName)
{
    QString getPasswordQuery = QString("SELECT password FROM Staff WHERE userName = '%1'").arg(userName);

    model.setQuery(getPasswordQuery);

    QString password ="";
    password = model.record(0).value("password").toString();

    return password;

}

void staffModel::setPassword(QString userName, QString password)
{
    QString setPasswordQuery = QString("Update Staff "
                                       "SET password = '%1' "
                                       "WHERE username = '%2'").arg(password, userName);

    model.setQuery(setPasswordQuery);

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

void staffModel::setNewUser(QString ssNr, QString name, QString username, QString password, QString ifAdmin)
{

    QString setNewUserQuery = QString("INSERT into Staff "
                                      "VALUES ('%1', '%2', '%3', '%4', '%5')").arg(ssNr, name, username, password, ifAdmin);

    model.setQuery(setNewUserQuery);

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
