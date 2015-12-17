#include "updateInformation.h"
#include "ui_updateInformation.h"

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
