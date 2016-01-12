#ifndef AVAILABLEROOMSMODEL_H
#define AVAILABLEROOMSMODEL_H

#include <QAbstractTableModel>
#include "hsmMetaData.h"
#include <QSqlQueryModel>


class availableRoomsModel: public QAbstractTableModel
{
    Q_OBJECT;

public:
    availableRoomsModel(QObject *parent = 0, const viewParameters* parameters = 0);

    int rowCount( const QModelIndex &parent = QModelIndex() ) const ;
    int columnCount( const QModelIndex &parent = QModelIndex() ) const ;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    Qt::ItemFlags flags(const QModelIndex & index) const;

    void searchForAvailableRooms(QString &from, QString &to);
    void reset();


    int getBedsNumber(int row);
private:
//    const int COLS= 0;
//    const int ROWS= 0;
    const QSqlDatabase* db;
    QSqlQueryModel model;
//    QString m_gridData[ROWS][COLS];  //holds text entered into QTableView
signals:
    void editCompleted(const QString &);
};

#endif // AVAILABLEROOMSMODEL_H
