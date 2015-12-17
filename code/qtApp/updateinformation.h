#ifndef UPDATEINFORMATION_H
#define UPDATEINFORMATION_H

#include <QDialog>

namespace Ui {
class updateInformation;
}

class updateInformation : public QDialog
{
    Q_OBJECT

public:
    explicit updateInformation(QWidget *parent = 0);
    ~updateInformation();

private:
    Ui::updateInformation *ui;
};

#endif // UPDATEINFORMATION_H
