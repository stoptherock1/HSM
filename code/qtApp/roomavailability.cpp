#include "roomAvailability.h"
#include "ui_roomAvailability.h"

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
