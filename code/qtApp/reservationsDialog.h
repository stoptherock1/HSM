#ifndef RESERVATIONSDIALOG_H
#define RESERVATIONSDIALOG_H

#include <QDialog>

namespace Ui {
class reservationsDialog;
}

class reservationsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit reservationsDialog(QWidget *parent = 0);
    ~reservationsDialog();

private:
    Ui::reservationsDialog *ui;
};

#endif // RESERVATIONSDIALOG_H
