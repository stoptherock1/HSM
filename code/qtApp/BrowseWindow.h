#ifndef BROWSEWINDOW_H
#define BROWSEWINDOW_H

#include <QDebug>
#include <QDateTime>
#include <QDialog>
#include <QDataWidgetMapper>

#include <hsmMetaData.h>
#include <availableRoomsModel.h>
#include <loginWindow.h>

namespace Ui {
class browseWindow;
}

class browseWindow : public QDialog
{
    Q_OBJECT

public:
    explicit browseWindow(QWidget *parent = 0,
                          viewParameters* parameters = 0);
    ~browseWindow();

private:
    Ui::browseWindow *ui;
    const QSqlDatabase* db;
    availableRoomsModel *model;
    loginWindow* loginWnd;
    QRegExpValidator* dateValidator;
    QDataWidgetMapper* widgetMapper;

    void initializeTable();

public slots:
    void checkAvailableRooms();
    void selectionChanged(const QItemSelection& selected, const QItemSelection& deselected);
};

#endif // BROWSEWINDOW_H
