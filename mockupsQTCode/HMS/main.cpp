#include "fistpage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    fistpage w;
    w.show();

    return a.exec();
}
