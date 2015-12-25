#ifndef BOOKING_DIALOG_H
#define BOOKING_DIALOG_H

#include <QDialog>
#include <QStyle>
#include <QDesktopWidget>

#include <hsmMetaData.h>
#include <availableRoomsBrowserDialog.h>

namespace Ui {
class bookingDialog;
}

class bookingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit bookingDialog(QWidget *parent = 0);
    ~bookingDialog();

private:
    Ui::bookingDialog *ui;
};

#endif // BOOKING_DIALOG_H
