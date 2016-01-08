#include "reservationsDialog.h"
#include "ui_reservationsDialog.h"

reservationsDialog::reservationsDialog(QWidget *parent, viewParameters* parameters_) :
    QDialog(parent),
    ui(new Ui::reservationsDialog),
    parameters(parameters_)
{
    ui->setupUi(this);

    ui->tableView_2->setModel(parameters->reservationMdl);
}

reservationsDialog::~reservationsDialog()
{
    delete ui;
}
