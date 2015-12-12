#include "loginWindow.h"
#include "ui_loginWindow.h"

loginWindow::loginWindow(QWidget *parent, std::shared_ptr<databaseConnection> dbConnection) :
    QDialog(parent),
    ui(new Ui::loginWindow)
{
    ui->setupUi(this);


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

//       @Mousa: your code goes here
//        if (password is wrong)
//            change status_label text to 'Username or Password is wrong' (red color)
//        else
//            change status_label text to 'Username and Password are ok' (green color)

//        EXAMPLE
//        QSqlQueryModel model;
//        model.setQuery("SELECT username, password FROM Staff "
//                       "WHERE username='%1' AND password='mousaZB'", *db);
//        qDebug() << "Result: " << model.record(1).value("username").toString();
//        some comment

        ui->status_label->setHidden(true);
    }

    adjustSize();
    adjustSize();

    qDebug() << username << " " << password;
}
