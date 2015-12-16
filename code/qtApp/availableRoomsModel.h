#ifndef MYMODEL_H
#define MYMODEL_H

#include <QObject>
#include <QAbstractTableModel>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlRecord>
#include <QModelIndex>


class availableRoomsModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    QSqlQueryModel model;

    availableRoomsModel(QObject *parent=0);
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

public slots:
    void searchForAvailableRooms(QString& from, QString& to);
};


#endif // MYMODEL_H
