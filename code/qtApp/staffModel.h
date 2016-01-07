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
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex & index) const;


    void getUserInfo(QString userName);
    void getOtherStaffOveralInfo();
    QString getPassword(QString userName);
    void setPassword(QString userName, QString password);
    void setNewUser(QString ssNr, QString name, QString username, QString password, QString ifAdmin);
private:
//    const int COLS= 3;
//    const int ROWS= 2;
    const QSqlDatabase* db;
    QSqlQueryModel model;
//    QString m_gridData[ROWS][COLS];  //holds text entered into QTableView
signals:
    void editCompleted(const QString &);
};

#endif // STAFFMODEL_H
