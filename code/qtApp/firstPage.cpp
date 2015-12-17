#include "firstPage.h"
#include "ui_firstPage.h"

firstPage::firstPage(QWidget *parent, viewParameters *parameters) :
    QMainWindow(parent),
    ui(new Ui::firstPage)
{
    ui->setupUi(this);

    login = new loginWindow(this, parameters);
    int result = login->exec();
    if(1 != result)
    {
        qDebug() << "Unsuccessfull login";
        exit(1);
    }
}

firstPage::~firstPage()
{
    delete ui;
}
