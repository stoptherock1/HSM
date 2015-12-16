#ifndef AVAILABLEROOMSMODEL_H
#define AVAILABLEROOMSMODEL_H

#include <QAbstractTableModel>
#include "hsmMetaData.h"
#include <QSqlQueryModel>


class availableRoomsModel: public QAbstractTableModel
{
    Q_OBJECT

public:
    availableRoomsModel(QObject *parent = 0/*, const viewParameters* parameters = 0*/);

    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const ;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    void searchForAvailableRooms(QString &from, QString &to);

private:
    const QSqlDatabase* db;
    QSqlQueryModel model;

};

#endif // AVAILABLEROOMSMODEL_H
