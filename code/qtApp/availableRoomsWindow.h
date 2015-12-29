#ifndef AVAILABLEROOMSWINDOW_H
#define AVAILABLEROOMSWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QDataWidgetMapper>
#include <QDesktopWidget>

#include <hsmMetaData.h>
#include <availableRoomsModel.h>
#include <loginDialog.h>
#include <bookingDialog.h>

namespace Ui {
class availableRoomsWindow;
}

class availableRoomsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit availableRoomsWindow(QWidget *parent = 0,
                          viewParameters* parameters = 0);
    ~availableRoomsWindow();

private:
    Ui::availableRoomsWindow *ui;
    availableRoomsModel *model;
    loginDialog* loginDlg;
    QRegExpValidator* dateValidator;
    QDataWidgetMapper* widgetMapper;
    viewParameters* parameters;
    bookingDialog* bookingDlg;

    void initializeTable();
    void configureInputs();

private slots:
    void updateBookButton();
    void updateMaxGuestNumber();
    void on_book_pushButton_clicked();
    void manageReservationsTriggered();
    void editUsersDataTriggered();

public slots:
    void checkAvailableRooms();
    void selectionChanged(const QItemSelection& selected, const QItemSelection& deselected);
    void updateDate();
};

#endif // AVAILABLEROOMSWINDOW_H
