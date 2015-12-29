#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <QtSql>
#include <QMessageBox>
#include <QString>

// Change to the path to the database file on your computer
#define PATH_TO_THE_DATABASE "/D:/BTH/PA2515 Applied software project management/Team13.sqlite"

class databaseConnection
{
    QSqlDatabase db;

public:
    databaseConnection();
    ~databaseConnection();

    void establish();

    const QSqlDatabase* getDbPtr() const;
};

#endif // DATABASECONNECTION_H
