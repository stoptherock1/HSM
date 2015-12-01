#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent, std::shared_ptr<databaseConnection> dbConnection_) :
    QDialog(parent),
    ui(new Ui::login),
    dbConnection(dbConnection_)
{
    ui->setupUi(this);
    db = dbConnection->getDbPtr();

}

login::~login()
{
    delete ui;
}

void login::on_pushButton_Login_clicked()
{
    dbConnection.get()->establish();
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    //QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery();
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
