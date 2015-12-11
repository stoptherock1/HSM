#ifndef FISTPAGE_H
#define FISTPAGE_H

#include <QMainWindow>

namespace Ui {
class fistpage;
}

class fistpage : public QMainWindow
{
    Q_OBJECT

public:
    explicit fistpage(QWidget *parent = 0);
    ~fistpage();

private:
    Ui::fistpage *ui;
};

#endif // FISTPAGE_H
