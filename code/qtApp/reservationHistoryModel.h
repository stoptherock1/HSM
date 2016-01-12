#ifndef RESERVATIONHISTORYMODEL_H
#define RESERVATIONHISTORYMODEL_H

#include <QObject>
#include <QSqlTableModel>
#include <hsmMetaData.h>

class reservationHistoryModel : public QSqlTableModel
{
    Q_OBJECT;

private:
    viewParameters* parameters;

public:
    reservationHistoryModel(QObject *parent = 0, viewParameters* parameters = 0);

    int rowCount( const QModelIndex &parent = QModelIndex() ) const ;
    int columnCount( const QModelIndex &parent = QModelIndex() ) const ;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    Qt::ItemFlags flags(const QModelIndex & index) const;
};

#endif // RESERVATIONHISTORYMODEL_H
