#include "fistpage.h"
#include "ui_fistpage.h"

fistpage::fistpage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fistpage)
{
    ui->setupUi(this);
}

fistpage::~fistpage()
{
    delete ui;
}
