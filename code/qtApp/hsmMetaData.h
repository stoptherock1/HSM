#ifndef HSMMETADATA
#define HSMMETADATA

#include <memory>
#include <databaseConnection.h>
#include <QAbstractTableModel>

class reservationModel;
class availableRoomsModel;
class roomModel;
class reservationHistoryModel;
class staffModel;

struct viewParameters
{
    std::shared_ptr<databaseConnection> dbConnection;
    QString loggedInUser;
    bool isAdmin;
    availableRoomsModel* availableRoomsMdl;
    reservationModel* reservationMdl;
    roomModel* roomMdl;
    reservationHistoryModel* reservationHistoryMdl;
    staffModel* staffMdl;

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
        staffMdl = NULL;
    }
};

struct newUser
{
    QString name;
    QString username;
    QString password;
    QString ssn;
    bool isAdmin;

    newUser()
    {
        isAdmin = false;
    }
};

#endif // HSMMETADATA

