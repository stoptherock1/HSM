#ifndef BROWSEWINDOW_H
#define BROWSEWINDOW_H

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
    explicit BrowseWindow(QWidget *parent = 0);
    ~BrowseWindow();

private:
    Ui::BrowseWindow *ui;
    databaseConnection dbConnection;
    QSqlDatabase* db;


    void initializeTable();
    void executeQuery();
};

#endif // BROWSEWINDOW_H
