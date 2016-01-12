#ifndef HSMMETADATA
#define HSMMETADATA

#include <memory>
#include <databaseConnection.h>
#include <QAbstractTableModel>

class reservationModel;
class availableRoomsModel;
class roomModel;
class reservationHistoryModel;

struct viewParameters
{
    std::shared_ptr<databaseConnection> dbConnection;
    QString loggedInUser;
    bool isAdmin;
    availableRoomsModel* availableRoomsMdl;
    reservationModel* reservationMdl;
    roomModel* roomMdl;
    reservationHistoryModel* reservationHistoryMdl;

    viewParameters()
    {
        dbConnection = std::make_shared<databaseConnection>();
        dbConnection->establish();
        loggedInUser = "";
        isAdmin = false;
        availableRoomsMdl = NULL;
        reservationMdl = NULL;
        roomMdl = NULL;
        reservationHistoryMdl = NULL;
    }
};

#endif // HSMMETADATA

