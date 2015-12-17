#include "updateinformation.h"
#include "ui_updateinformation.h"

updateInformation::updateInformation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::updateInformation)
{
    ui->setupUi(this);
}

updateInformation::~updateInformation()
{
    delete ui;
}
