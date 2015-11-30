#include <QApplication>
#include "BrowseWindow.h"
#include "databaseConnection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    std::shared_ptr<databaseConnection> dbConnection = std::make_shared<databaseConnection>();
    dbConnection->establish();

    BrowseWindow browse(0, dbConnection);
    browse.show();

    return a.exec();
}
