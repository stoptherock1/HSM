#include "roomsDialog.h"
#include "ui_roomsDialog.h"
#include <roomModel.h>

roomsDialog::roomsDialog(QWidget *parent, viewParameters *parameters_) :
    QDialog(parent),
    ui(new Ui::roomsDialog),
    parameters(parameters_)
{
    ui->setupUi(this);
    initializeTable();
}

void roomsDialog::initializeTable()
{
    ui->tableView->setModel(parameters->roomMdl);

    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(5, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(6, QHeaderView::Stretch);

    ui->tableView->horizontalHeader()->setMinimumSectionSize(50);
}

roomsDialog::~roomsDialog()
{
    delete ui;
}

void roomsDialog::updateWindowTitle()
{
    QString title = "HSM: Romms browser";

    if(parameters->loggedInUser != "")
    {
        title.append( QString( "  |  Logged in user: %1")
                      .arg(parameters->loggedInUser) );

        if(parameters->isAdmin)
            title.append(" (admin)");
    }

    setWindowTitle(title);
}

void roomsDialog::showEvent(QShowEvent * event)
{
    updateWindowTitle();
    QDialog::showEvent(event);
}
