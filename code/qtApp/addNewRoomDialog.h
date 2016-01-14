#ifndef ADDNEWROOMDIALOG_H
#define ADDNEWROOMDIALOG_H

#include <QDialog>
#include <hsmMetaData.h>

namespace Ui {
class addNewRoomDialog;
}

class addNewRoomDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addNewRoomDialog(QWidget *parent = 0);
    ~addNewRoomDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::addNewRoomDialog *ui;
    void showEvent(QShowEvent * event);
    newRoom room;

signals:
    void newRoomAdded(newRoom &room);
};

#endif // ADDNEWROOMDIALOG_H
