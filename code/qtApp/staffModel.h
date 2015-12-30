#ifndef STAFFMODEL_H
#define STAFFMODEL_H

#include <QAbstractTableModel>
#include "hsmMetaData.h"
#include <QSqlQueryModel>

class staffModel: public QAbstractTableModel
{
    Q_OBJECT;

public:
    staffModel(QObject *parent = 0, const viewParameters* parameters = 0);
    int rowCount( const QModelIndex &parent = QModelIndex() ) const ;
    int columnCount( const QModelIndex &parent = QModelIndex() ) const ;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

private:
    const QSqlDatabase* db;
    QSqlQueryModel model;
};

#endif // STAFFMODEL_H
