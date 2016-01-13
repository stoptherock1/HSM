#ifndef AVAILABLEROOMSWINDOW_H
#define AVAILABLEROOMSWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QDataWidgetMapper>


#include <hsmMetaData.h>
#include <availableRoomsModel.h>
#include <reservationModel.h>
#include <loginDialog.h>
#include <bookingDialog.h>
#include <reservationsDialog.h>
#include <reservationHistoryDialog.h>
#include <roomsDialog.h>
#include <staffDialog.h>

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
    loginDialog* loginDlg;
    reservationsDialog* reservationsDlg;

    QRegExpValidator* dateValidator;
    QDataWidgetMapper* widgetMapper;
    viewParameters* parameters;
    bookingDialog* bookingDlg;
    roomsDialog* roomsDlg;
    reservationHistoryDialog* reservationHistoryDlg;
    staffDialog* staffDlg;
    QDate from;
    QDate till;

    void initializeTable();
    void configureInputs();
    void updateWindowTitle();

private slots:
    void updateBookButton();
    void updateMaxGuestNumber();
    void updateRoomPrice();
    void on_book_pushButton_clicked();
    void manageReservationsTriggered();
    void editUsersDataTriggered();

    void performAvailableRoomsSearch();

    void resetWindow();
    void resetDate();

    void on_pushButton_clicked();

public slots:
    void login();
    void checkAvailableRooms();
    void selectionChanged(const QItemSelection& selected, const QItemSelection& deselected);
    void updateDate();
    void showRoomsDialog();
    void showReservationHistoryDialog();
    void showStaffDialog();
    bool confirmProvidedDatesCorrectness();
};

#endif // AVAILABLEROOMSWINDOW_H
