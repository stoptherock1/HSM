#include "bookingDialog.h"
#include "ui_bookingDialog.h"
#include "availableRoomsModel.h"
#include "reservationModel.h"


bookingDialog::bookingDialog(QWidget *parent, viewParameters* parameters_) :
    QDialog(parent),
    ui(new Ui::bookingDialog),
    parameters(parameters_),
    roomPrice(0)
{
    ui->setupUi(this);
    setGeometry( QStyle::alignedRect( Qt::LeftToRight,
                                      Qt::AlignCenter,
                                      size(),
                                      qApp->desktop()->availableGeometry() ) );

    this->setFixedSize(this->width(),this->height());

    widgetMapper = new QDataWidgetMapper(this);
    widgetMapper->setModel(parameters->availableRoomsMdl);

    widgetMapper->addMapping(ui->roomNumber_lineEdit, 0);
    widgetMapper->addMapping(ui->numberOfBeds_lineEdit, 3);
    widgetMapper->addMapping(ui->roomType_lineEdit, 4);
    widgetMapper->addMapping(ui->balcony_checkBox, 5);

    ui->extraBedYes_radioButton->setChecked(true);
}

void bookingDialog::updateWindowTitle()
{
    QString title = "HSM: Make a reservation";

    if(parameters->loggedInUser != "")
    {
        title.append( QString( "  |  Logged in user: %1")
                      .arg(parameters->loggedInUser) );

        if(parameters->isAdmin)
            title.append(" (admin)");
    }

    setWindowTitle(title);
}

bookingDialog::~bookingDialog()
{
    delete ui;
}

QDataWidgetMapper *bookingDialog::getWidgetMapper() const
{
    return widgetMapper;
}

void bookingDialog::setWidgetMapper(QDataWidgetMapper *value)
{
    widgetMapper = value;
}

int bookingDialog::getRoomPrice() const
{
    return roomPrice;
}

void bookingDialog::setRoomPrice(int value)
{
    roomPrice = value;
}

void bookingDialog::setReservationTotalPrice()
{
    int totalPrice = parameters->reservationMdl->calculateTotalPrice(roomPrice, from, till);
    ui->totalPrice_lineEdit->setText( QString::number(totalPrice) );
}


void bookingDialog::setMaximumGuestsNumber(int maxGuestsNumber)
{
    ui->numberOfGuests_SpinBox->setMaximum(maxGuestsNumber);
    ui->numberOfGuests_SpinBox->setValue(maxGuestsNumber);
}

void bookingDialog::setFromTillDates(QDate from_, QDate till_)
{
    from = from_;
    till = till_;

    ui->from_dateEdit->setDate(from);
    ui->till_dateEdit->setDate(till);
}

void bookingDialog::clearInputs()
{
    ui->name_lineEdit->setText("");
    ui->surname_lineEdit->setText("");
    ui->socialSecurityNumber_lineEdit->setText("");
    ui->phoneNumber_lineEdit->setText("");
    ui->address_lineEdit->setText("");
    ui->email_lineEdit->setText("");
}

int bookingDialog::exec()
{
    setReservationTotalPrice();

    ui->name_lineEdit->setFocus();
    return QDialog::exec();
}

void bookingDialog::on_book_pushButton_clicked()
{
    QString numberOfGuests = QString::number( ui->numberOfGuests_SpinBox->value() );
    QString name = ui->name_lineEdit->text();
    QString surname = ui->surname_lineEdit->text();
    QString ssn = ui->socialSecurityNumber_lineEdit->text();
    QString phone = ui->phoneNumber_lineEdit->text();
    QString address = ui->address_lineEdit->text();
    QString email = ui->email_lineEdit->text();

    QString from = ui->from_dateEdit->date().toString("yyyy-MM-dd");
    QString till = ui->till_dateEdit->date().toString("yyyy-MM-dd");
    QString roomType = ui->roomType_lineEdit->text();

    QString roomNr = ui->roomNumber_lineEdit->text();

    QString extraBed = ui->extraBedYes_radioButton->isChecked() ? "true" : "false";

    qDebug() << "NEW BOOKING: " <<
                "numberOfGuests " << numberOfGuests << ", " <<
                "name " << name << ", " <<
                "surname " << surname << ", " <<
                "ssn " << ssn << ", " <<
                "phone " << phone << ", " <<
                "address " << address << ", " <<
                "email " << email << ", " <<
                "from " << from << ", " <<
                "till " << till << ", " <<
                "roomType " << roomType << ", " <<
                "extraBed " << extraBed <<
                "roomNr " << roomNr << ". ";

    parameters->reservationMdl->insertCurrent_Reservation(roomNr,
                                                          ssn,
                                                          ui->from_dateEdit->date(),
                                                          ui->till_dateEdit->date(),
                                                          ui->extraBedYes_radioButton->isChecked(),
                                                          parameters->loggedInUser);

    clearInputs();
    done(1);
}
