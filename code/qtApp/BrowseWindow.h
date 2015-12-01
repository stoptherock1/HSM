#ifndef BROWSEWINDOW_H
#define BROWSEWINDOW_H
#include <memory>
#include <QDialog>
#include <QDebug>
#include "databaseConnection.h"

namespace Ui {
class BrowseWindow;
}

class BrowseWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BrowseWindow(QWidget *parent = 0, std::shared_ptr<databaseConnection> dbConnection = 0);
    ~BrowseWindow();

private:
    Ui::BrowseWindow *ui;
    const QSqlDatabase* db;
    std::shared_ptr<databaseConnection> dbConnection;

    void initializeTable();
    void executeQuery();
};

#endif // BROWSEWINDOW_H
