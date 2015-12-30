#ifndef AVAILABLEROOMSMODEL_H
#define AVAILABLEROOMSMODEL_H

#include <QAbstractTableModel>
#include "hsmMetaData.h"
#include <QSqlQueryModel>

const int COLS= 0;
const int ROWS= 0;

class availableRoomsModel: public QAbstractTableModel
{
    Q_OBJECT;

public:
    availableRoomsModel(QObject *parent = 0, const viewParameters* parameters = 0);

    int rowCount( const QModelIndex &parent = QModelIndex() ) const ;
    int columnCount( const QModelIndex &parent = QModelIndex() ) const ;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex & index) const;

    void searchForAvailableRooms(QString &from, QString &to);


    int getBedsNumber(int row);
private:
    const QSqlDatabase* db;
    QSqlQueryModel model;
    QString m_gridData[ROWS][COLS];  //holds text entered into QTableView
signals:
    void editCompleted(const QString &);
};

#endif // AVAILABLEROOMSMODEL_H
