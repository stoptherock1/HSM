#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QtSql>
#include <QDebug>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void func()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/Volumes/USERS_HDD/Users/str1/Downloads/installs/db1");

    if( !db.open() )
    {
        qDebug() << db.lastError();
        qFatal("Failed to connect!");
    }
    else
        qDebug() << "Connected" ;

    QSqlQuery query;
    query.exec("select * from tbl1;");

    while ( query.next() )
    {
        QString result = query.value(0).toString();
        result += " ";
        result += query.value(1).toString();
        qDebug() << result;
    }

    FILE *output = NULL;
    output = popen("touch /Volumes/USERS_HDD/Users/str1/Downloads/installs/file1", "r");
    pclose(output);

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    func();

}

MainWindow::~MainWindow()
{
    delete ui;
}
