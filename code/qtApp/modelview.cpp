#include "modelview.h"



ModelView::ModelView(QObject *parent):QAbstractTableModel(parent)
{
    db = dbConnection->getDbPtr();
//    this->model= new QSqlRelationalTableModel(parent, this->dbConnection);
//    this->model->setTable("Staff");
//    this->model->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
//    this->model->setHeaderData(0, Qt::Horizontal, tr("ssNr"));
//    this->model->setHeaderData(1,Qt::Horizontal, tr("name"));
//    this->model->setHeaderData(2,Qt::Horizontal, tr("username"));
//    this->model->setHeaderData(3,Qt::Horizontal, tr("password"));
//    model->select();
//    QTableView *view = new QTableView;
//    view->setModel(model);
//    view->hideColumn(3); // don't show the password
//    view->show();
}
int ModelView::rowCount(const QModelIndex &/*parent*/) const
{
    return 2;
}
int ModelView::columnCount(const QModelIndex &/*parent*/) const
{
    return 3;
}
QVariant ModelView::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
       return QString("Row%1, Column%2")
                   .arg(index.row() + 1)
                   .arg(index.column() +1);
    }
    return QVariant();
}
//ModelView::ModelView(QWidget *parent, std::shared_ptr<databaseConnection> dbConnection_) :
//    QDialog(parent),
//    ui(new Ui::login),
//    dbConnection(dbConnection_)
//{
//    ui->setupUi(this);
//    db = dbConnection->getDbPtr();
//}
void ModelView::login()
{/*
    dbConnection.get()->establish();
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    qDebug()<< username << " " << password;
//    QSqlQueryModel model;
//    model.setQuery("SELECT * FROM employee");
//    int salary = model.record(4).value("salary").toInt();
    QSqlQuery *qry = new QSqlQuery();

    QString qryLogin = QString("select * from Staff where username=\'%1\' and password=\'%2\'").arg(username, password);
    qry->exec(qryLogin);
    if(qry->next())
    {
        qDebug() << qry->value(2) <<" is logged in";
    }
    else
    {
        qDebug()<<username << ": Not logged in";
    }

    QString DBusername = qry->value(2).toString(); //The number 2 value(2)is the column in the database counting from 0.

    ui->textBrowserTEST->setText(DBusername);
*/
}
