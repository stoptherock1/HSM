#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include "databaseConnection.h"
#include <memory>

namespace Ui {
class loginWindow;
}

class loginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit loginWindow(QWidget *parent = 0,
                         std::shared_ptr<databaseConnection> dbConnection = 0,
                         QString* loggedinUser=0);
    ~loginWindow();

private:
    Ui::loginWindow *ui;
    const QSqlDatabase* db;
    QString* loggedinUser;

    const QString normalLabelText = "Provide credentials";
    const QString emptyFieldsLabelText = "<font color='Red'>Username and Password cannot be empty</font>";

private slots:
    void login();
};

#endif // LOGINWINDOW_H
