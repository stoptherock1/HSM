#include <QApplication>
#include "BrowseWindow.h"
#include "databaseConnection.h"
#include "login.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    std::shared_ptr<databaseConnection> dbConnection = std::make_shared<databaseConnection>();
    dbConnection->establish();

    login log(0, dbConnection);
    BrowseWindow browse(0, dbConnection);
    log.show();
    browse.show();

    return a.exec();
}
