#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <databaseConnection.h>
namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    void on_pushButton_Login_clicked();

private:
    Ui::login *ui;

};

#endif // LOGIN_H
