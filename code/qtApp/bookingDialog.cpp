#include "bookingDialog.h"
#include "ui_bookingDialog.h"

bookingDialog::bookingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bookingDialog)
{
    ui->setupUi(this);
    setGeometry( QStyle::alignedRect( Qt::LeftToRight,
                                      Qt::AlignCenter,
                                      size(),
                                      qApp->desktop()->availableGeometry() ) );
}

bookingDialog::~bookingDialog()
{
    delete ui;
}
