#include "reservationsDialog.h"
#include "ui_reservationsDialog.h"

reservationsDialog::reservationsDialog(QWidget *parent, viewParameters* parameters_) :
    QDialog(parent),
    ui(new Ui::reservationsDialog),
    parameters(parameters_)
{
    ui->setupUi(this);

    model = new reservationModel(this, parameters);
    ui->tableView_2->setModel(model);
}

reservationsDialog::~reservationsDialog()
{
    delete ui;
}
