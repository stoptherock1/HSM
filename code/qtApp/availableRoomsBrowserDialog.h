#ifndef AVAILABLEROOMSBROWSERDIALOG_H
#define AVAILABLEROOMSBROWSERDIALOG_H

#include <QDebug>
#include <QDialog>
#include <QDataWidgetMapper>
#include <QDesktopWidget>

#include <hsmMetaData.h>
#include <availableRoomsModel.h>
#include <loginDialog.h>
#include <bookingDialog.h>

namespace Ui {
class availableRoomsBrowserDialog;
}

class availableRoomsBrowserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit availableRoomsBrowserDialog(QWidget *parent = 0,
                          viewParameters* parameters = 0);
    ~availableRoomsBrowserDialog();

private:
    Ui::availableRoomsBrowserDialog *ui;
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

public slots:
    void checkAvailableRooms();
    void selectionChanged(const QItemSelection& selected, const QItemSelection& deselected);
    void updateDate();
};

#endif // AVAILABLEROOMSBROWSERDIALOG_H
