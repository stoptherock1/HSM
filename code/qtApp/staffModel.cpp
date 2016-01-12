#include "staffModel.h"

staffModel::staffModel(QObject* parent, viewParameters *parameters_)
    :QSqlTableModel(parent),
      parameters(parameters_)
{
    db = parameters->dbConnection->getDbPtr();
    sqlQuery = QSqlQuery("", *db);

    setTable("Staff");
    select();
}

int staffModel::rowCount(const QModelIndex & /*parent*/) const
{
    if(QSqlTableModel::rowCount() < 99)
        return 99;
    else
        return QSqlTableModel::rowCount();
}

int staffModel::columnCount(const QModelIndex & /*parent*/) const
{
    if(QSqlTableModel::columnCount() < 5)
        return 5;
    else
        return QSqlTableModel::columnCount();
}

QVariant staffModel::data(const QModelIndex & index, int role) const
{
    int row = index.row();
    int column = index.column();

    if(Qt::DisplayRole == role || Qt::EditRole == role)
    {
        if(4 == column && Qt::DisplayRole == role)
            return QVariant();

        return QSqlTableModel::data(index, role);
    }

    if( Qt::CheckStateRole == role && 4 == column && row < QSqlTableModel::QSqlTableModel::rowCount() )
    {
        if( 1 == QSqlTableModel::data(index, Qt::DisplayRole).toInt() )
            return Qt::Checked;

        else if( 0 == QSqlTableModel::data(index, Qt::DisplayRole).toInt() )
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
                return QString("Username");
            case 3:
                return QString("Password");
            case 4:
                return QString("Admin");
            }
        }

        if (orientation == Qt::Vertical)
            return section + 1;
    }
    return QVariant();
}

bool staffModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if( Qt::CheckStateRole == role && 4 == index.column() )
    {
        if(0 == value)
            return QSqlTableModel::setData(index, "0", Qt::EditRole);
        else
            return QSqlTableModel::setData(index, "1", Qt::EditRole);
    }
    return QSqlTableModel::setData(index, value, role);
}


//void staffModel::getUserInfo(QString userName)
//{
//    QString getUserInfoQuery = QString("SELECT * FROM Staff WHERE userName = '%1'").arg(userName);

//    setQuery(getUserInfoQuery);

//    if( lastError().isValid() )
//    {
//        qDebug() << lastError();
//        QMessageBox::critical(0,
//                              "Cannot set query",
//                              QString("Unable to set query."
//                                      "\nReason: %1\nClick Cancel to "
//                                      "exit.").arg( lastError().text() ),
//                              QMessageBox::Cancel);
//    }

//    //inform table, that data have changed in the whole table
//    QModelIndex topLeft = createIndex(0,0);
//    QModelIndex bottomRight = createIndex( QSqlTableModel::rowCount(), QSqlTableModel::columnCount() );

//    emit dataChanged(topLeft, bottomRight);
//}

//void staffModel::getOtherStaffOveralInfo()
//{
//    QString getOtherStaffOveralInfoQuery = QString("SELECT name, username, ifAdmin FROM Staff");

//    setQuery(getOtherStaffOveralInfoQuery);

//    if( lastError().isValid() )
//    {
//        qDebug() << lastError();
//        QMessageBox::critical(0,
//                              "Cannot set query",
//                              QString("Unable to set query."
//                                      "\nReason: %1\nClick Cancel to "
//                                      "exit.").arg( lastError().text() ),
//                              QMessageBox::Cancel);
//    }

//    //inform table, that data have changed in the whole table
//    QModelIndex topLeft = createIndex(0,0);
//    QModelIndex bottomRight = createIndex( QSqlTableModel::rowCount(), QSqlTableModel::columnCount() );

//    emit dataChanged(topLeft, bottomRight);
//}

//QString staffModel::getPassword(QString userName)
//{
//    QString getPasswordQuery = QString("SELECT password FROM Staff WHERE userName = '%1'").arg(userName);

//    setQuery(getPasswordQuery);

//    QString password ="";
//    password = record(0).value("password").toString();

//    return password;

//}

//void staffModel::setPassword(QString userName, QString password)
//{
//    QString setPasswordQuery = QString("Update Staff "
//                                       "SET password = '%1' "
//                                       "WHERE username = '%2'").arg(password, userName);

//    setQuery(setPasswordQuery);

//    if( lastError().isValid() )
//    {
//        qDebug() << lastError();
//        QMessageBox::critical(0,
//                              "Cannot set query",
//                              QString("Unable to set query."
//                                      "\nReason: %1\nClick Cancel to "
//                                      "exit.").arg( lastError().text() ),
//                              QMessageBox::Cancel);
//    }

//    //inform table, that data have changed in the whole table
//    QModelIndex topLeft = createIndex(0,0);
//    QModelIndex bottomRight = createIndex( QSqlTableModel::rowCount(), QSqlTableModel::columnCount() );

//    emit dataChanged(topLeft, bottomRight);
//}

void staffModel::addNewUser(newUser &user)
{
    QString ifAdminStr = user.isAdmin ? "1" : "0";
    QString setNewUserQuery = QString("INSERT into Staff "
                                      "VALUES ('%1', '%2', '%3', '%4', '%5')")
            .arg(user.ssn,
                 user.name,
                 user.username,
                 user.password,
                 ifAdminStr);

    sqlQuery.exec(setNewUserQuery);

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

Qt::ItemFlags staffModel::flags(const QModelIndex & index) const
{
    Qt::ItemFlags result = Qt::ItemIsSelectable | Qt::ItemIsEnabled;

    if( 4 == index.column() )
        result |= Qt::ItemIsUserCheckable;

    result |= Qt::ItemIsEditable;

    return result;
}
