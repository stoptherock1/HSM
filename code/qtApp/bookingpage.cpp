#include "bookingpage.h"
#include "ui_bookingpage.h"

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
