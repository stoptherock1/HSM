#include "bookingDialog.h"
#include "ui_bookingDialog.h"

bookingDialog::bookingDialog(QWidget *parent, viewParameters* parameters_) :
    QDialog(parent),
    ui(new Ui::bookingDialog),
    parameters(parameters_)
{
    ui->setupUi(this);
    setGeometry( QStyle::alignedRect( Qt::LeftToRight,
                                      Qt::AlignCenter,
                                      size(),
                                      qApp->desktop()->availableGeometry() ) );

    this->setFixedSize(this->width(),this->height());

    widgetMapper = new QDataWidgetMapper(this);
    widgetMapper->setModel(parameters->model);

    widgetMapper->addMapping(ui->roomNumber_lineEdit, 0);
    widgetMapper->addMapping(ui->numberOfBeds_lineEdit, 3);
    widgetMapper->addMapping(ui->roomType_lineEdit, 4);
    widgetMapper->addMapping(ui->balcony_checkBox, 5);

    QString title = "HSM: Make a reservation";

    ui->roomServiceYes_radioButton->setChecked(true);

    if(parameters->loggedInUser != "")
        title.append( QString( "  |  Logged in user: %1")
                      .arg(parameters->loggedInUser) );

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

void bookingDialog::setMaximumGuestsNumber(int maxGuestsNumber)
{
    ui->numberOfGuests_SpinBox->setMaximum(maxGuestsNumber);
    ui->numberOfGuests_SpinBox->setValue(maxGuestsNumber);
}

void bookingDialog::setFromTillDates(QDate from, QDate till)
{
    ui->from_dateEdit->setDate(from);
    ui->till_dateEdit->setDate(till);
}

int bookingDialog::exec()
{
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

    QString roomService = ui->roomServiceYes_radioButton->isChecked() ? "true" : "false";

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
                "roomService " << roomService << ". ";
}
