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

private slots:
    void on_checkout_pushButton_clicked();

private:
    Ui::reservationsDialog *ui;
    reservationModel* model;
    viewParameters* parameters;

    void initializeTable();

public slots:
    void selectionChanged(const QItemSelection& selected, const QItemSelection&);
};

#endif // RESERVATIONSDIALOG_H
