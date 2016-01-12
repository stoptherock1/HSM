#include <QApplication>
#include <availableRoomsWindow.h>
#include <loginDialog.h>
#include <hsmMetaData.h>
#include <bookingDialog.h>
#include <staffPage.h>
#include <updateInformation.h>
#include <reservationsDialog.h>
#include <roomModel.h>
#include <reservationHistoryModel.h>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    viewParameters parameters;

    //models initialization
    reservationModel reservationMdl(0, &parameters);
    availableRoomsModel availableRoomsMdl(0, &parameters);
    roomModel roomMdl(0, &parameters);
    reservationHistoryModel reservationHistoryMdl(0, &parameters);
    staffModel staffMdl(0, &parameters);

    parameters.reservationMdl = &reservationMdl;
    parameters.availableRoomsMdl = &availableRoomsMdl;
    parameters.roomMdl = &roomMdl;
    parameters.reservationHistoryMdl = &reservationHistoryMdl;
    parameters.staffMdl = &staffMdl;

//    reservationsDialog dialog(0, &parameters);
//    dialog.show();

    availableRoomsWindow availableRoomsWnd(0, &parameters);

//    availableRoomsWnd.show();
//    availableRoomsWnd.login();

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


    return a.exec();
}
