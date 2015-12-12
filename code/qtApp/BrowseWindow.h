#ifndef BROWSEWINDOW_H
#define BROWSEWINDOW_H

#include <QDialog>
#include <QDebug>
#include "databaseConnection.h"
#include <memory>

namespace Ui {
class browseWindow;
}

class browseWindow : public QDialog
{
    Q_OBJECT

public:
    explicit browseWindow(QWidget *parent = 0, std::shared_ptr<databaseConnection> dbConnection = 0);
    ~browseWindow();

private:
    Ui::browseWindow *ui;
    const QSqlDatabase* db;

    void initializeTable();
    void executeQuery();
};

#endif // BROWSEWINDOW_H
