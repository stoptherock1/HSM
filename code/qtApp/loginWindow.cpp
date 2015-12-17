#include "loginWindow.h"
#include "ui_loginWindow.h"

loginWindow::loginWindow(QWidget *parent,  viewParameters *parameters_) :
    QDialog(parent),
    ui(new Ui::loginWindow),
    parameters(parameters_)
{
    ui->setupUi(this);
    db = parameters->dbConnection->getDbPtr();

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

loginWindow::~loginWindow()
{
    delete ui;
}


void loginWindow::login()
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
            parameters->setLoggedInUser(username);

            ui->status_label->setHidden(false);
            done(1);
        }
    }

    adjustSize();
    adjustSize();
}
