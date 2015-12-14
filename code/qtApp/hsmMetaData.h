#ifndef HSMMETADATA
#define HSMMETADATA

#include <memory>
#include "databaseConnection.h"

struct viewParameters
{
    std::shared_ptr<databaseConnection> dbConnection;
    QString loggedinUser;
    bool isAdmin;


    viewParameters()
    {
        dbConnection = std::make_shared<databaseConnection>();
        dbConnection->establish();
        loggedinUser = "";
        isAdmin = false;
    }
};

#endif // HSMMETADATA

