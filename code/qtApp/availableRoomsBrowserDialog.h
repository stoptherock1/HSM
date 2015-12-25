#ifndef AVAILABLEROOMSBROWSERDIALOG_H
#define AVAILABLEROOMSBROWSERDIALOG_H

#include <QDebug>
#include <QDateTime>
#include <QDialog>
#include <QDataWidgetMapper>
#include <QDesktopWidget>

#include <hsmMetaData.h>
#include <availableRoomsModel.h>
#include <loginDialog.h>

namespace Ui {
class availableRoomsBrowserDialog;
}

class availableRoomsBrowserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit availableRoomsBrowserDialog(QWidget *parent = 0,
                          viewParameters* parameters = 0);
    ~availableRoomsBrowserDialog();

private:
    Ui::availableRoomsBrowserDialog *ui;
    const QSqlDatabase* db;
    availableRoomsModel *model;
    loginDialog* loginWnd;
    QRegExpValidator* dateValidator;
    QDataWidgetMapper* widgetMapper;
    viewParameters *parameters;

    void initializeTable();
    void configureLineEdits();

public slots:
    void checkAvailableRooms();
    void selectionChanged(const QItemSelection& selected, const QItemSelection& deselected);
};

#endif // AVAILABLEROOMSBROWSERDIALOG_H
