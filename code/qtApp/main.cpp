#include <QApplication>
#include <browseWindow.h>
#include <loginWindow.h>
#include <hsmMetaData.h>
#include <bookingPage.h>
#include <firstPage.h>
#include <roomAvailability.h>
#include <staffPage.h>
#include <updateInformation.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    viewParameters parameters;

//    bookingPage window1;
//    window1.exec();

    firstPage window2(0, &parameters);
    window2.show();

//    roomAvailability window3;
//    window3.exec();

//    staffPage window4;
//    window4.exec();

//    updateInformation window5;
//    window5.exec();

//    loginWindow login(0, &parameters);
//    login.exec();

//    browseWindow browse(0, &parameters);
//    browse.show();

    return a.exec();
}
