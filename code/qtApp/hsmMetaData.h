#ifndef HSMMETADATA
#define HSMMETADATA

#include <memory>
#include "databaseConnection.h"

struct viewParameters
{
    std::shared_ptr<databaseConnection> dbConnection;
    QString loggedInUser;
    bool isAdmin;


    viewParameters()
    {
        dbConnection = std::make_shared<databaseConnection>();
        dbConnection->establish();
        loggedInUser = "";
        isAdmin = false;
    }

    void setLoggedInUser(const QString &username)
    {
        loggedInUser = username;
    }
};

#endif // HSMMETADATA

