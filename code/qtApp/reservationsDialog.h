#ifndef RESERVATIONSDIALOG_H
#define RESERVATIONSDIALOG_H

#include <QDialog>
#include <reservationModel.h>
#include <hsmMetaData.h>

namespace Ui {
class reservationsDialog;
}

class reservationsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit reservationsDialog(QWidget *parent = 0,
                                viewParameters *parameters = 0);
    ~reservationsDialog();

private:
    Ui::reservationsDialog *ui;
    reservationModel* model;
    viewParameters* parameters;
};

#endif // RESERVATIONSDIALOG_H
