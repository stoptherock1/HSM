#ifndef RESERVATIONMODEL_H
#define RESERVATIONMODEL_H

#include <QAbstractTableModel>
#include "hsmMetaData.h"
#include <QSqlQueryModel>
#include <QSqlTableModel>


class reservationModel: public QSqlTableModel
{
    Q_OBJECT;

public:
    reservationModel(QObject *parent = 0, viewParameters* parameters = 0);
    ~reservationModel();

    int rowCount( const QModelIndex &parent = QModelIndex() ) const ;
    int columnCount( const QModelIndex &parent = QModelIndex() ) const ;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
    Qt::ItemFlags flags(const QModelIndex & index) const;
    bool setData(const QModelIndex& index, const QVariant& value, int role);

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
    void performActualCheckIn(int bookingNrInt);

private:
    const QSqlDatabase* db;
    viewParameters* parameters;
    QSqlQuery sqlQuery;

signals:
    void editCompleted(const QString &);
};

#endif // RESERVATIONMODEL_H

