#include "staffpage.h"
#include "ui_staffpage.h"

staffPage::staffPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::staffPage)
{
    ui->setupUi(this);
}

staffPage::~staffPage()
{
    delete ui;
}
