#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <QtSql>
#include <QMessageBox>
#include <QString>


class databaseConnection
{
public:
    QSqlDatabase* db;

    databaseConnection();
    ~databaseConnection();

    QSqlDatabase* establish();

};

#endif // DATABASECONNECTION_H
