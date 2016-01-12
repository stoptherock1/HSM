#ifndef STAFFDIALOG_H
#define STAFFDIALOG_H

#include <QDialog>
#include <hsmMetaData.h>
#include <staffModel.h>
#include "addUserDialog.h"


namespace Ui {
class staffDialog;
}

class staffDialog : public QDialog
{
    Q_OBJECT

public:
    explicit staffDialog(QWidget *parent = 0,
                         viewParameters *parameters = 0);

    ~staffDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::staffDialog *ui;
    viewParameters *parameters;
    addUserDialog* addUserDlg;

    void initializeTable();
    void updateWindowTitle();
    void showEvent(QShowEvent * event);
};

#endif // STAFFDIALOG_H
