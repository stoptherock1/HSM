#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <QtSql>
#include <QMessageBox>
#include <QString>
#include <memory>
#include <QDebug>

// Change to the path to the database file on your computer
#define PATH_TO_THE_DATABASE "/D:/temp/GIT Team13/HSM/database/Team13.sqlite"
//#define PATH_TO_THE_DATABASE "/Users/str1/repo/hsm/database/Team13.sqlite"
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
