#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "hsmMetaData.h"

namespace Ui {
class loginDialog;
}

class loginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit loginDialog(QWidget *parent = 0,
                         viewParameters *parameters = 0);
    ~loginDialog();

private:
    Ui::loginDialog *ui;
    const QSqlDatabase* db;
    viewParameters *parameters;

    const QString normalLabelText = "Provide credentials";
    const QString emptyFieldsLabelText = "<font color='Red'>Username and Password cannot be empty</font>";
    const QString wrongUsernameOrPasswordText = "<font color='Red'>Wrong Username or Password</font>";

private slots:
    void login();
};

#endif // LOGINDIALOG_H
