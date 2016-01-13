#include "addUserDialog.h"
#include "ui_addUserDialog.h"

addUserDialog::addUserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addUserDialog)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());
    setWindowTitle("Add new user");
}

addUserDialog::~addUserDialog()
{
    delete ui;
}

void addUserDialog::showEvent(QShowEvent * event)
{
    ui->administratorCheckBox->setChecked(false);
    ui->usernameLineEdit->clear();
    ui->passwordLineEdit->clear();
    ui->fullNameLineEdit->clear();
    ui->sSNLineEdit->clear();
    ui->usernameLineEdit->setFocus();

    QDialog::showEvent(event);
}

void addUserDialog::on_pushButton_clicked()
{
    user.name = ui->fullNameLineEdit->text();
    user.password = ui->passwordLineEdit->text();
    user.ssn = ui->sSNLineEdit->text();
    user.username = ui->usernameLineEdit->text();
    user.isAdmin = ui->administratorCheckBox->isChecked() ? true : false;

    emit newUserAdded(user);
    done(1);
}
