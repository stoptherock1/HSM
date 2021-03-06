#ifndef ADDUSERDIALOG_H
#define ADDUSERDIALOG_H

#include <QDialog>
#include <hsmMetaData.h>

namespace Ui {
class addUserDialog;
}

class addUserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addUserDialog(QWidget *parent = 0);
    ~addUserDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::addUserDialog *ui;
    void showEvent(QShowEvent * event);
    newUser user;

signals:
    void newUserAdded(newUser &user);
};

#endif // ADDUSERDIALOG_H
