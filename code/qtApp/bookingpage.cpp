#include "bookingPage.h"
#include "ui_bookingPage.h"

bookingPage::bookingPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bookingPage)
{
    ui->setupUi(this);
}

bookingPage::~bookingPage()
{
    delete ui;
}
