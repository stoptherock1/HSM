#ifndef HSMMETADATA
#define HSMMETADATA

#include <memory>
#include <databaseConnection.h>
#include <QAbstractTableModel>

class reservationModel;


struct viewParameters
{
    std::shared_ptr<databaseConnection> dbConnection;
    QString loggedInUser;
    bool isAdmin;
    QAbstractTableModel* availableRoomsMdl;
    reservationModel* reservationMdl;


    viewParameters()
    {
        dbConnection = std::make_shared<databaseConnection>();
        dbConnection->establish();
        loggedInUser = "";
        isAdmin = false;
        availableRoomsMdl = NULL;
        reservationMdl = NULL;
    }
};

#endif // HSMMETADATA

