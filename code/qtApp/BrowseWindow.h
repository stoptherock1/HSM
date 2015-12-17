#ifndef BROWSEWINDOW_H
#define BROWSEWINDOW_H

#include <QDialog>
#include <QDebug>
#include "hsmMetaData.h"
#include "availableRoomsModel.h"
#include <QDateTime>

namespace Ui {
class browseWindow;
}

class browseWindow : public QDialog
{
    Q_OBJECT

public:
    explicit browseWindow(QWidget *parent = 0,
                          const viewParameters* parameters = 0);
    ~browseWindow();

private:
    Ui::browseWindow *ui;
    const QSqlDatabase* db;
    availableRoomsModel *model;

    void initializeTable();

public slots:
    void checkAvailableRooms();
};

#endif // BROWSEWINDOW_H
