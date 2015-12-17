#include "fistPage.h"
#include "ui_fistPage.h"

fistPage::fistPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fistPage)
{
    ui->setupUi(this);
}

fistPage::~fistPage()
{
    delete ui;
}
