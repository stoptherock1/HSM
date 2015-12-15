#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include "hsmMetaData.h"

namespace Ui {
class loginWindow;
}

class loginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit loginWindow(QWidget *parent = 0,
                         viewParameters *parameters = 0);
    ~loginWindow();

private:
    Ui::loginWindow *ui;
    const QSqlDatabase* db;
    viewParameters *parameters;

    const QString normalLabelText = "Provide credentials";
    const QString emptyFieldsLabelText = "<font color='Red'>Username and Password cannot be empty</font>";
    const QString wrongUsernameOrPasswordText = "<font color='Red'>Username or Password wrong</font>";
    const QString correctUsernameAndPasswordText = "<font color='Green'>Username and Password correct</font>";

private slots:
    void login();
};

#endif // LOGINWINDOW_H
