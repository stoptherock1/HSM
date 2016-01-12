#ifndef ROOMSDIALOG_H
#define ROOMSDIALOG_H

#include <QDialog>
#include <hsmMetaData.h>

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

private:
    Ui::roomsDialog *ui;
    viewParameters* parameters;

    void initializeTable();
    void updateWindowTitle();
    void showEvent(QShowEvent * event);
};

#endif // ROOMSDIALOG_H
