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

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setAlternatingRowColors(true);

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableView->verticalHeader()->setDefaultSectionSize(23);


    ui->tableView->horizontalHeader()->setHighlightSections(false);
    ui->tableView->horizontalHeader()->setSectionResizeMode(6, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setMinimumSectionSize(50);
}

roomsDialog::~roomsDialog()
{
    delete ui;
}

void roomsDialog::updateWindowTitle()
{
    QString title = "HSM: Rooms browser";

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
