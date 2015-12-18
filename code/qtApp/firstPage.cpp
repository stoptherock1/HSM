#include "firstPage.h"
#include "ui_firstPage.h"

firstPage::firstPage(QWidget *parent, viewParameters *parameters) :
    QMainWindow(parent),
    ui(new Ui::firstPage)
{
    ui->setupUi(this);


}

firstPage::~firstPage()
{
    delete ui;
}
