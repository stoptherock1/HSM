#include "databaseConnection.h"


const QSqlDatabase *databaseConnection::getDbPtr() const
{
    return &db;
}

databaseConnection::databaseConnection()
{
    qDebug() << Q_FUNC_INFO;

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(PATH_TO_THE_DATABASE);
}

databaseConnection::~databaseConnection()
{
    if( db.isOpen() )
        db.close();

    qDebug() << Q_FUNC_INFO;
}

void databaseConnection::establish()
{
    qDebug() << Q_FUNC_INFO;

    QString tableName = "Room";
    /*
     * Here it's a little bit tricky: normally, if database could not be opened (file does not
     * exist, etc), db.open() function will return 'false'. But in case of sqlite, if you
     * provide the wrong filename, an empty file with such filemane will be created
     * (I'm not sure about the reasons), the db.open() will return 'true' and no error will
     * be shown. The solution here could be the following: check, if the database has a
     * specific table, by calling db.tables().contains() function,
     * so in case of created, but empty file, an error will be raised.
    */
    if( !db.open() || !db.tables().contains(tableName) )
    {
        QMessageBox::critical(0, "Cannot open database",
                              QString("Unable to establish a database connection."
                              "\nReason: %1\nClick Cancel to "
                              "exit.").arg( db.lastError().text() ),
                              QMessageBox::Cancel);
        db.close();
    }
}
