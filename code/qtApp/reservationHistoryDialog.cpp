#include "reservationHistoryDialog.h"
#include "ui_reservationHistoryDialog.h"
#include "reservationHistoryModel.h"


reservationHistoryDialog::reservationHistoryDialog(QWidget *parent, viewParameters *parameters_) :
    QDialog(parent),
    ui(new Ui::reservationHistoryDialog),
    parameters(parameters_)
{
    ui->setupUi(this);
    initializeTable();
    this->setFixedSize(this->width(),this->height());
}

void reservationHistoryDialog::initializeTable()
{
    ui->tableView->setModel(parameters->reservationHistoryMdl);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setAlternatingRowColors(true);

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);


    ui->tableView->horizontalHeader()->setHighlightSections(false);
    ui->tableView->horizontalHeader()->setSectionResizeMode(6, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setMinimumSectionSize(50);
    ui->tableView->horizontalHeader()->hideSection(9);
    ui->tableView->horizontalHeader()->hideSection(10);
    ui->tableView->horizontalHeader()->hideSection(12);
}

reservationHistoryDialog::~reservationHistoryDialog()
{
    delete ui;
}

void reservationHistoryDialog::updateWindowTitle()
{
    QString title = "HSM: Reservation history";

    if(parameters->loggedInUser != "")
    {
        title.append( QString( "  |  Logged in user: %1")
                      .arg(parameters->loggedInUser) );

        if(parameters->isAdmin)
            title.append(" (admin)");
    }

    setWindowTitle(title);
}

void reservationHistoryDialog::showEvent(QShowEvent * event)
{
    updateWindowTitle();
    parameters->reservationHistoryMdl->select();

    QDialog::showEvent(event);
}
