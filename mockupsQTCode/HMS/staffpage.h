#ifndef STAFFPAGE_H
#define STAFFPAGE_H

#include <QDialog>

namespace Ui {
class staffPage;
}

class staffPage : public QDialog
{
    Q_OBJECT

public:
    explicit staffPage(QWidget *parent = 0);
    ~staffPage();

private:
    Ui::staffPage *ui;
};

#endif // STAFFPAGE_H
