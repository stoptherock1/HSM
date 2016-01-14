#ifndef ROOMMODEL_H
#define ROOMMODEL_H

#include <QSqlTableModel>
#include "hsmMetaData.h"
#include <QSqlQueryModel>


class roomModel: public QSqlTableModel
{
    Q_OBJECT;

private:
    const QSqlDatabase* db;
    viewParameters* parameters;
    QSqlQuery sqlQuery;


public:
    roomModel(QObject *parent = 0, viewParameters* parameters = 0);

    int rowCount( const QModelIndex &parent = QModelIndex() ) const ;
    int columnCount( const QModelIndex &parent = QModelIndex() ) const ;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex & index) const;

public slots:
    void addNewRoom(newRoom &room);
};

#endif // ROOMMODEL_H
