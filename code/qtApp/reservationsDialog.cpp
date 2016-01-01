#include "reservationsDialog.h"
#include "ui_reservationsDialog.h"

reservationsDialog::reservationsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reservationsDialog)
{
    ui->setupUi(this);
}

reservationsDialog::~reservationsDialog()
{
    delete ui;
}
