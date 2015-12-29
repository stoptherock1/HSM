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

    void insertCurrent_Reservation(QString bookingNr, QString roomNr, int ssNr, QDate checkInDate, QDate checkOutDate, int totalPrice, int extraBed, QDate actuallyCheckInDate, QString addedByUser);
    void insertOld_Reservation(QString bookingNr, QString roomNr, int ssNr, QDate checkInDate, QDate checkOutDate, int totalPrice, int extraBed, QDate actuallyCheckInDate, QDate actuallyCheckOutDate, bool ifDeleted, QDate whenDeletedDate, QString addedByUser, QString deletedByUser);
private:
    const QSqlDatabase* db;
    QSqlQueryModel model;
};

#endif // RESERVATIONMODEL_H

