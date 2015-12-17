#ifndef ROOMAVAILABILITY_H
#define ROOMAVAILABILITY_H

#include <QDialog>

namespace Ui {
class roomAvailability;
}

class roomAvailability : public QDialog
{
    Q_OBJECT

public:
    explicit roomAvailability(QWidget *parent = 0);
    ~roomAvailability();

private:
    Ui::roomAvailability *ui;
};

#endif // ROOMAVAILABILITY_H
