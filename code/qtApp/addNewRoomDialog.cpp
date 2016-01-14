#include "addNewRoomDialog.h"
#include "ui_addNewRoomDialog.h"

addNewRoomDialog::addNewRoomDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addNewRoomDialog)
{
    ui->setupUi(this);
    setWindowTitle("Add new room");
}

addNewRoomDialog::~addNewRoomDialog()
{
    delete ui;
}

void addNewRoomDialog::on_pushButton_clicked()
{
    room.roomNr = ui->roomNumberLineEdit->text();
    room.roomName = ui->roomNameLineEdit->text();
    room.price = ui->priceLineEdit->text();
    room.nrOfBeds = ui->numberOfBedsLineEdit->text();
    room.roomType = ui->roomTypeLineEdit->text();
    room.balcony = ui->balconyCheckBox->isChecked();
    room.additionalNotes = ui->additionalNotes_textEdit->toPlainText();

    emit newRoomAdded(room);
    done(1);
}

void addNewRoomDialog::showEvent(QShowEvent * event)
{
    ui->roomNumberLineEdit->clear();
    ui->roomNameLineEdit->clear();
    ui->priceLineEdit->clear();
    ui->numberOfBedsLineEdit->clear();
    ui->roomTypeLineEdit->clear();
    ui->balconyCheckBox->setChecked(false);
    ui->additionalNotes_textEdit->clear();

    ui->roomNumberLineEdit->setFocus();

    QDialog::showEvent(event);
}
