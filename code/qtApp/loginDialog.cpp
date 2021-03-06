#include "loginDialog.h"
#include "ui_loginDialog.h"

loginDialog::loginDialog(QWidget *parent,  viewParameters *parameters_) :
    QDialog(parent),
    ui(new Ui::loginDialog),
    parameters(parameters_)
{
    ui->setupUi(this);
    db = parameters->dbConnection->getDbPtr();

    this->setMaximumSize(this->width(), this->height() + 20);

    ui->password_lineEdit->setEchoMode(QLineEdit::Password);

    ui->label->setText(normalLabelText);

    ui->status_label->setText(emptyFieldsLabelText);
    ui->status_label->setHidden(true);
    ui->status_label->setWordWrap(true);
    ui->status_label->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);

    adjustSize();

    setWindowTitle("HSM: Log in");

    connect( ui->login_pushButton, SIGNAL( clicked() ),
             this, SLOT( login() ) );
}

loginDialog::~loginDialog()
{
    delete ui;
}


void loginDialog::login()
{
    QString username = ui->usename_lineEdit->text();
    QString password = ui->password_lineEdit->text();

    if(username == "" || password == "")
    {
        ui->status_label->setText(emptyFieldsLabelText);
        ui->status_label->setHidden(false);
    }
    else
    {
        QString dbPassword = "";
        QString getPasswordQuery = QString("SELECT password FROM Staff "
                                           "WHERE username='%1'").arg(username);
        QSqlQueryModel model;

        model.setQuery(getPasswordQuery, *db);
        dbPassword = model.record(0).value("password").toString();

        if (password != dbPassword)
        {
            ui->status_label->setText(wrongUsernameOrPasswordText);
            ui->status_label->setHidden(false);
        }
        else
        {
            parameters->loggedInUser = username;

            QSqlQuery sqlQuery( *parameters->dbConnection->getDbPtr() );
            QString isAdminQuery = QString("SELECT * FROM Staff WHERE username='%1'").arg(username);
            sqlQuery.exec(isAdminQuery);
            if( sqlQuery.next() && 1 == sqlQuery.record().value("ifAdmin").toInt() )
                parameters->isAdmin = true;
            else
                parameters->isAdmin = false;

            done(1);
        }
    }

}


void loginDialog::showEvent(QShowEvent * /*event*/)
{
    ui->usename_lineEdit->setFocus();
    ui->usename_lineEdit->clear();
    ui->password_lineEdit->clear();
    ui->status_label->clear();
    ui->status_label->setHidden(true);

    adjustSize();
}
