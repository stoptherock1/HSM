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
    explicit loginWindow(QWidget *parent = 0, std::shared_ptr<databaseConnection> dbConnection = 0);
    ~loginWindow();

private:
    Ui::loginWindow *ui;
    const QSqlDatabase* db;
};

#endif // LOGINWINDOW_H
