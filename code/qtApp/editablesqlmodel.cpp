#include "editablesqlmodel.h"
#include <QtSql>
#include <QtWidgets>
EditableSqlModel::EditableSqlModel(QObject *parent)
    : QSqlQueryModel(parent)
{

}

Qt::ItemFlags EditableSqlModel::flags(
        const QModelIndex &index) const
{
    Qt::ItemFlags flags = QSqlQueryModel::flags(index);
    if (index.column() == 1 || index.column() == 2||index.column() == 3)
        flags |= Qt::ItemIsEditable;
    return flags;
}

bool EditableSqlModel::setData(const QModelIndex &index, const QVariant &value, int /* role */)
{
    if (index.column() < 0 || index.column() > 3)
        return false;

    QModelIndex primaryKeyIndex = QSqlQueryModel::index(index.row(), 0);
    int ssNR = data(primaryKeyIndex).toInt();

    clear();

    bool ok;
    if (index.column() == 1) {
        ok = setName(ssNR, value.toString());
    }
    if(index.column() == 2)
    {
        ok = setUserName(ssNR, value.toString());
    }
    if(index.column() == 3)
    {
        ok = setPassword(ssNR, value.toString());
    }
    refresh();
    return ok;
}

void EditableSqlModel::refresh()
{
    setQuery("select * from Staff");
    setHeaderData(0, Qt::Horizontal, QObject::tr("ssNR"));
    setHeaderData(1, Qt::Horizontal, QObject::tr("name"));
    setHeaderData(2, Qt::Horizontal, QObject::tr("username"));
    setHeaderData(3, Qt::Horizontal, QObject::tr("password"));
}

bool EditableSqlModel::setName(int ssNR, const QString &name)
{
    QSqlQuery query;
    query.prepare("Update Staff Set name = ? Where ssNR = ?");
    query.addBindValue(name);
    query.addBindValue(ssNR);
    return query.exec();
}

bool EditableSqlModel::setPassword(int ssNR, const QString &password)
{
    QSqlQuery query;
    query.prepare("Update Staff Set password = ? Where ssNR = ?");
    query.addBindValue(password);
    query.addBindValue(ssNR);
    return query.exec();
}


bool EditableSqlModel::setUserName(int ssNR, const QString &username)
{
    QSqlQuery query;
    query.prepare("Update Staff Set username = ? Where ssNR = ?");
    query.addBindValue(username);
    query.addBindValue(ssNR);
    return query.exec();
}
