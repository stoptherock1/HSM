#ifndef STAFFMODEL_H
#define STAFFMODEL_H

#include <QSqlTableModel>
#include "hsmMetaData.h"
#include <QSqlQueryModel>


class staffModel: public QSqlTableModel
{
    Q_OBJECT;

public:
    staffModel(QObject *parent = 0, viewParameters* parameters = 0);
    int rowCount( const QModelIndex &parent = QModelIndex() ) const ;
    int columnCount( const QModelIndex &parent = QModelIndex() ) const ;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex & index) const;

public slots:
    void addNewUser(newUser &user);

private:
    const QSqlDatabase* db;
    QSqlQuery sqlQuery;
    viewParameters *parameters;

signals:
    void editCompleted(const QString &);
};

#endif // STAFFMODEL_H
