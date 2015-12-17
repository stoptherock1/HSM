#ifndef FIRSTPAGE_H
#define FIRSTPAGE_H

#include <QMainWindow>
#include <loginWindow.h>
#include <hsmMetaData.h>


namespace Ui {
class firstPage;
}

class firstPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit firstPage(QWidget *parent = 0, viewParameters *parameters = 0);
    ~firstPage();

private:
    Ui::firstPage *ui;
    loginWindow *login;
};

#endif // FIRSTPAGE_H
