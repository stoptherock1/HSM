#include <QApplication>
#include "BrowseWindow.h"
#include "databaseConnection.h"
#include <loginWindow.h>
#include <memory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    std::shared_ptr<databaseConnection> dbConnection = std::make_shared<databaseConnection>();
    dbConnection->establish();

    loginWindow login;
    login.exec();

    BrowseWindow browse(0, dbConnection);
    browse.show();

    return a.exec();
}
