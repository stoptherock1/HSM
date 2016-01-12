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
    void on_checkOut_pushButton_clicked();

    void on_checkIn_pushButton_clicked();

    void on_filter_lineEdit_textEdited(const QString &arg1);

    void on_delete_pushButton_clicked();

    void updateSelection();

private:
    Ui::reservationsDialog *ui;
    reservationModel* model;
    viewParameters* parameters;
    int selectedRow;

    void initializeTable();
    int getSelectedBookingNumber();
    void updateButtons();

    void showEvent(QShowEvent * event);
    void updateWindowTitle();

public slots:
    void selectionChanged(const QItemSelection& selected, const QItemSelection&);
};

#endif // RESERVATIONSDIALOG_H
