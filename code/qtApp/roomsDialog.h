#ifndef ROOMSDIALOG_H
#define ROOMSDIALOG_H

#include <QDialog>
#include <hsmMetaData.h>
#include <addNewRoomDialog.h>

namespace Ui {
class roomsDialog;
}

class roomsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit roomsDialog(QWidget *parent = 0,
                         viewParameters *parameters = 0);
    ~roomsDialog();

private slots:
    void on_pushButton_clicked();

public slots:
    void addNewRoom(newRoom& room);

private:
    Ui::roomsDialog *ui;
    viewParameters* parameters;
    addNewRoomDialog* addNewRoomDlg;

    void initializeTable();
    void updateWindowTitle();
    void showEvent(QShowEvent * event);
};

#endif // ROOMSDIALOG_H
