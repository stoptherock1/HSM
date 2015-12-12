#include <QApplication>
#include "browseWindow.h"
#include "databaseConnection.h"
#include <loginWindow.h>
#include <memory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    std::shared_ptr<databaseConnection> dbConnection = std::make_shared<databaseConnection>();
    dbConnection->establish();

    loginWindow login(0, dbConnection);
    login.exec();

    browseWindow browse(0, dbConnection);
    browse.show();

    return a.exec();
}
