#include "roomavailability.h"
#include "ui_roomavailability.h"

roomAvailability::roomAvailability(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::roomAvailability)
{
    ui->setupUi(this);
}

roomAvailability::~roomAvailability()
{
    delete ui;
}
