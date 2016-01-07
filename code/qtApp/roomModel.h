#ifndef ROOMMODEL_H
#define ROOMMODEL_H

#include <QAbstractTableModel>
#include "hsmMetaData.h"
#include <QSqlQueryModel>


class roomModel: public QAbstractTableModel
{
        Q_OBJECT;

public:
    roomModel(QObject *parent = 0, const viewParameters* parameters = 0);
    int rowCount( const QModelIndex &parent = QModelIndex() ) const ;
    int columnCount( const QModelIndex &parent = QModelIndex() ) const ;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex & index) const;

private:
//    const int COLS= 3;
//    const int ROWS= 2;
    const QSqlDatabase* db;
    QSqlQueryModel model;
//    QString m_gridData[ROWS][COLS];  //holds text entered into QTableView
signals:
    void editCompleted(const QString &);
};

#endif // ROOMMODEL_H