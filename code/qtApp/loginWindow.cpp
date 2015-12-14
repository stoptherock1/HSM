#include "loginWindow.h"
#include "ui_loginWindow.h"

loginWindow::loginWindow(QWidget *parent, const viewParameters *parameters, QString *loggedinUser_) :
    QDialog(parent),
    ui(new Ui::loginWindow),
    loggedinUser(loggedinUser_)
{
    ui->setupUi(this);
    db = parameters->dbConnection->getDbPtr();

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
        //        qDebug() <<
//        qDebug() << loggedinUser
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
/*
<<<<<<< HEAD
//        qDebug() << loggedinUser
//       ui->status_label->setHidden(true);
>>>>>>> origin/master
*/

    adjustSize();
    adjustSize();

}
