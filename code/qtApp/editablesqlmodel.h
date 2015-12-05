#ifndef EDITABLESQLMODEL_H
#define EDITABLESQLMODEL_H

class QDialogButtonBox;
class QPushButton;
#include <QSqlQueryModel>
class EditableSqlModel :public QSqlQueryModel
{
    Q_OBJECT

public:
    EditableSqlModel(QObject *parent = 0);

    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
    bool setData(const QModelIndex &index, const QVariant &value, int role) Q_DECL_OVERRIDE;

private:
    bool setName(int ssNR, const QString &name);
    bool setPassword(int ssNR, const QString &password);
    bool setUserName(int ssNR, const QString &username);
    void refresh();
};

#endif // EDITABLESQLMODEL_H
