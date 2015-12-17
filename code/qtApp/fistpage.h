#ifndef FISTPAGE_H
#define FISTPAGE_H

#include <QMainWindow>

namespace Ui {
class fistPage;
}

class fistPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit fistPage(QWidget *parent = 0);
    ~fistPage();

private:
    Ui::fistPage *ui;
};

#endif // FISTPAGE_H
