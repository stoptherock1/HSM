#include "tableeditor.h"
#include <QtWidgets>
#include <QtSql>
#include "databaseConnection.h"
TableEditor::TableEditor(const QString &tableName, QWidget *parent)
    : QWidget(parent)
{
    model = new QSqlTableModel(this);
    model->setTable(tableName);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    model->setHeaderData(0, Qt::Horizontal, tr("ssNR"));
    model->setHeaderData(1, Qt::Horizontal, tr("name"));
    model->setHeaderData(2, Qt::Horizontal, tr("username"));
    model->setHeaderData(3, Qt::Horizontal, tr("password"));

    QTableView *view = new QTableView;
    view->setModel(model);
    view->resizeColumnsToContents();

    submitButton = new QPushButton(tr("Submit"));
    submitButton->setDefault(true);
    revertButton = new QPushButton(tr("&Revert"));
    quitButton = new QPushButton(tr("Quit"));
    loginButton = new QPushButton(tr("Login"));

    buttonBox = new QDialogButtonBox(Qt::Vertical);
    buttonBox->addButton(loginButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(submitButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(revertButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

    this->userName = new QLineEdit;
    this->passWord = new QLineEdit;

    connect(loginButton, SIGNAL(clicked()),this , SLOT(login()));
    connect(submitButton, SIGNAL(clicked()), this, SLOT(submit()));
    connect(revertButton, SIGNAL(clicked()), model, SLOT(revertAll()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(view);
    mainLayout->addWidget(buttonBox);
    mainLayout->addWidget(userName);
    mainLayout->addWidget(passWord);
    userName->setMaximumSize(55,20);
    passWord->setMaximumSize(55,20);
    setLayout(mainLayout);

    setWindowTitle(tr("Cached Table"));

}
void TableEditor::submit()
{
    model->database().transaction();
        if (model->submitAll()) {
            model->database().commit();
        }
        else
        {
            model->database().rollback();
            QMessageBox::warning(this, tr("Cached Table"),
                                 tr("The database reported an error: %1")
                                 .arg(model->lastError().text()));
        }
}

void TableEditor::login()
{
    QString DBusername = "";
    QString DBpassword = "";
    QString username = this->userName->text();
    QString password = this->passWord->text();
    bool ok = false;
    QSqlQuery qry ;
    qry.prepare("SELECT username FROM Staff WHERE username = :BVusername");
    qry.bindValue( username,":BVusername");
    qry.exec();
    DBusername = qry.value(0).toString();

    if(DBusername == username){
        ok = true;   }

    qry.prepare("SELECT password FROM Staff WHERE password = :BVpassword");
    qry.bindValue( password, ":BVpassword");
    qry.exec();
    DBpassword = qry.value(0).toString();

    if(ok == true && DBpassword == password)
    {
        printf("\n Password and username ok");
        qDebug() << "ok";
    }
    else{

         printf("\nerror");
         qDebug() << qry.lastError().text();
    }
}
