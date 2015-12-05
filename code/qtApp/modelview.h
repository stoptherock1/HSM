#ifndef MODELVIEW_H
#define MODELVIEW_H

#include <QObject>
#include <QAbstractTableModel>
#include <QSqlRelationalTableModel>
#include <QSqlTableModel>
#include <QTableView>
#include "databaseConnection.h"
class ModelView:public QAbstractTableModel
{
    Q_OBJECT
private:
    std::shared_ptr<databaseConnection> dbConnection;
    const QSqlDatabase* db;
     QSqlRelationalTableModel *model;
public:
    ModelView(QObject *parent);
    explicit ModelView(QWidget *parent = 0, std::shared_ptr<databaseConnection> dbConnection = 0);
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    void login();


};

#endif // MODELVIEW_H
