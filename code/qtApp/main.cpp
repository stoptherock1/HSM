#include <QApplication>
#include <availableRoomsWindow.h>
#include <loginDialog.h>
#include <hsmMetaData.h>
#include <bookingDialog.h>
#include <roomAvailability.h>
#include <staffPage.h>
#include <updateInformation.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    viewParameters parameters;

//    bookingDialog window1;
//    window1.exec();

//    firstPage window2(0, &parameters);
//    window2.show();

//    roomAvailability window3;
//    window3.exec();

//    staffPage window4;
//    window4.exec();

//    updateInformation window5;
//    window5.exec();

//    loginDialog login(0, &parameters);
//    login.exec();

    availableRoomsWindow availableRoomsWnd(0, &parameters);
    availableRoomsWnd.show();

    return a.exec();
}
