#include "loginWindow.h"
#include "ui_loginWindow.h"

loginWindow::loginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginWindow)
{
    ui->setupUi(this);

    setWindowTitle("HSM: Log in");
}

loginWindow::~loginWindow()
{
    delete ui;
}
