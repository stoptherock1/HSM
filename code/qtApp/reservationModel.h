#ifndef RESERVATIONMODEL_H
#define RESERVATIONMODEL_H

#include <QAbstractTableModel>
#include "hsmMetaData.h"
#include <QSqlQueryModel>


class reservationModel: public QAbstractTableModel
{
    Q_OBJECT;

public:
    reservationModel(QObject *parent = 0, const viewParameters* parameters = 0);
    int rowCount( const QModelIndex &parent = QModelIndex() ) const ;
    int columnCount( const QModelIndex &parent = QModelIndex() ) const ;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex & index,
                 const QVariant & value,
                 int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex & index) const;

    int calculateTotalPrice(int price, QDate checkInDate, QDate checkOutDate);

    void insertCurrent_Reservation(QString roomNr,
                                   QString ssNr,
                                   QDate checkInDateInt,
                                   QDate checkOutDateInt,
                                   int extraBedInt,
                                   QString addedByUser);

    void insertOld_Reservation(int bookingNrInt);
    void deleteCurrent_Reservation(int bookingNrInt);
    void deleteOld_Reservation(int bookingNrInt);
    void readCurrentReservationsTable();

private:
//    int COLS= 3;
//    int ROWS= 2;
    const QSqlDatabase* db;
    QSqlQueryModel model;
//    QString m_gridData[ROWS][COLS];  //holds text entered into QTableView
signals:
    void editCompleted(const QString &);
};

#endif // RESERVATIONMODEL_H

