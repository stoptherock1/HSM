#include "loginWindow.h"
#include "ui_loginWindow.h"

loginWindow::loginWindow(QWidget *parent, std::shared_ptr<databaseConnection> dbConnection) :
    QDialog(parent),
    ui(new Ui::loginWindow)
{
    ui->setupUi(this);
    db = dbConnection->getDbPtr();

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
        QString getPasswordQuery = QString("SELECT password FROM Staff WHERE username='%1'").arg(username);
        QSqlQueryModel model;

        model.setQuery(getPasswordQuery, *db);
        dbPassword = model.record(0).value("password").toString();


        if (password != dbPassword)
        {
            ui->status_label->setText(wrongUsernameOrPasswordText);
            ui->status_label->setHidden(false);
            qDebug() << getPasswordQuery;
            qDebug() << username << " " << dbPassword;
        }

        else
        {
            qDebug() << username << " " << dbPassword;
            ui->status_label->setText(correctUsernameAndPasswordText);
            ui->status_label->setHidden(false);
        }




    }

    adjustSize();
    adjustSize();

}
