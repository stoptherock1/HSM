#ifndef BOOKINGPAGE_H
#define BOOKINGPAGE_H

#include <QDialog>

namespace Ui {
class bookingPage;
}

class bookingPage : public QDialog
{
    Q_OBJECT

public:
    explicit bookingPage(QWidget *parent = 0);
    ~bookingPage();

private:
    Ui::bookingPage *ui;
};

#endif // BOOKINGPAGE_H
