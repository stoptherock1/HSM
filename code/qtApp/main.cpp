#include <QApplication>
#include "browseWindow.h"
#include <loginWindow.h>
#include "hsmMetaData.h"

int main(int argc, char *argv[])
{
    /* some comments
     * sdnchvdnskdfv]df
     * v
     * dfs
     * vdf
     * sv
     * df
     * v
     * dfsv
     * dfs
     * v
     * dfs*/

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
