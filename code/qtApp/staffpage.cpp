#include "staffPage.h"
#include "ui_staffPage.h"

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
