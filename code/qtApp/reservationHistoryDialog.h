#ifndef RESERVATIONHISTORYDIALOG_H
#define RESERVATIONHISTORYDIALOG_H

#include <QDialog>
#include <hsmMetaData.h>

namespace Ui {
class reservationHistoryDialog;
}

class reservationHistoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit reservationHistoryDialog(QWidget *parent = 0,
                                      viewParameters *parameters = 0);
    ~reservationHistoryDialog();

private:
    Ui::reservationHistoryDialog *ui;
    viewParameters* parameters;

    void initializeTable();
    void updateWindowTitle();
    void showEvent(QShowEvent * event);
};

#endif // RESERVATIONHISTORYDIALOG_H
