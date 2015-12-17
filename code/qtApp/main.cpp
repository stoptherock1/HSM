#include <QApplication>
#include <browseWindow.h>
#include <loginWindow.h>
#include <hsmMetaData.h>
#include <bookingpage.h>
#include <fistpage.h>
#include <roomavailability.h>
#include <staffpage.h>
#include <updateinformation.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString loggedinUser = "";

    viewParameters parameters;



//    bookingPage window1;
//    window1.exec();

//    fistpage window2;
//    window2.show();

//    roomAvailability window3;
//    window3.exec();

//    staffPage window4;
//    window4.exec();

//    updateInformation window5;
//    window5.exec();

//    loginWindow login(0, &parameters);
//    login.exec();


    browseWindow browse(0, &parameters);
    browse.show();

    return a.exec();
}
