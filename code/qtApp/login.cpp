#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_Login_clicked()
{

    databaseConnection.db->open();
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    //QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(databaseConnection.db);
    qry->prepare("SELECT username FROM Staff WHERE username = :BVusername");
    qry->bindValue(":BVusername", username);


    qry->exec();
    QString DBusername = qry->value(0).toString();

    ui->textBrowserTEST->setText(DBusername);

    /*
    if(username == DBusername && password == DBpassword)
    {

    }
    */
}
