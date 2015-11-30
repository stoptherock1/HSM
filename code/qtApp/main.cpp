#include <QApplication>
#include "BrowseWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BrowseWindow browse;
    browse.show();

    return a.exec();
}
