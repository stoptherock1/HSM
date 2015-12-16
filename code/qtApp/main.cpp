#include <QApplication>
#include "browseWindow.h"
#include <loginWindow.h>
#include "hsmMetaData.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString loggedinUser = "";

    viewParameters parameters;

    loginWindow login(0, &parameters);
    login.exec();

    browseWindow browse(0, &parameters);
    browse.show();

    return a.exec();
}


void function()
{
    qDebug() << "bla bla bla";
}
