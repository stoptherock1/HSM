#ifndef BOOKINGDIALOG_H
#define BOOKINGDIALOG_H

#include <QDialog>
#include <QDate>
#include <QStyle>
#include <QDesktopWidget>
#include <QDataWidgetMapper>

#include <hsmMetaData.h>

namespace Ui {
class bookingDialog;
}

class bookingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit bookingDialog(QWidget *parent = 0, viewParameters* parameters = 0);
    ~bookingDialog();

    QDataWidgetMapper *getWidgetMapper() const;
    void setWidgetMapper(QDataWidgetMapper *value);

    int getRoomPrice() const;
    void setRoomPrice(int value);

private:
    Ui::bookingDialog *ui;
    viewParameters* parameters;
    QDataWidgetMapper* widgetMapper;
    int roomPrice;
    QDate from;
    QDate till;

    void setReservationTotalPrice();
    void updateWindowTitle();
    void clearInputs();

public slots:
    void setFromTillDates(QDate from, QDate till);
    void setMaximumGuestsNumber(int maxGuestsNumber);
    int exec();
private slots:
    void on_book_pushButton_clicked();
};

#endif // BOOKINGDIALOG_H
