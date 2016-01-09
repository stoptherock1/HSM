#include "reservationsDialog.h"
#include "ui_reservationsDialog.h"
#include <QDesktopWidget>

reservationsDialog::reservationsDialog(QWidget *parent, viewParameters* parameters_) :
    QDialog(parent),
    ui(new Ui::reservationsDialog),
    parameters(parameters_)
{
    ui->setupUi(this);

    setGeometry( QStyle::alignedRect( Qt::LeftToRight,
                                      Qt::AlignCenter,
                                      size(),
                                      qApp->desktop()->availableGeometry() ) );


    initializeTable();

    ui->checkout_pushButton->setEnabled(false);
    ui->delete_pushButton->setEnabled(false);
    ui->modify_pushButton->setEnabled(false);

    QString title = "HSM: Manage current reservations";

    if(parameters->loggedInUser != "")
        title.append( QString( "  |  Logged in user: %1")
                      .arg(parameters->loggedInUser) );

    setWindowTitle(title);

    connect( ui->tableView->selectionModel(),
             SIGNAL( selectionChanged(const QItemSelection&, const QItemSelection&) ),
             this, SLOT( selectionChanged( const QItemSelection&, const QItemSelection&) ) );
}

void reservationsDialog::initializeTable()
{
    ui->tableView->setModel(parameters->reservationMdl);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setAlternatingRowColors(true);

    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setHighlightSections(false);
    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(5, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(6, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(7, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(8, QHeaderView::Stretch);

}

reservationsDialog::~reservationsDialog()
{
    delete ui;
}

void reservationsDialog::on_checkout_pushButton_clicked()
{
    QList<QModelIndex> indexes = ui->tableView->selectionModel()->selection().indexes();
    if( indexes.size() > 0 &&  "" != parameters->reservationMdl->data( indexes.at(0) ).toString() )
    {
        int reservationNr = parameters->reservationMdl->data( indexes.at(0) ).toInt();

        parameters->reservationMdl->insertOld_Reservation(reservationNr);
    }

}

void reservationsDialog::selectionChanged(const QItemSelection& selected, const QItemSelection&)
{
    QList<QModelIndex> indexes = ui->tableView->selectionModel()->selection().indexes();
    // enable/disable buttons, depending on the selection
    if( indexes.size() > 0 &&  "" != parameters->reservationMdl->data( indexes.at(0) ).toString() )
    {
        ui->checkout_pushButton->setEnabled(true);
        ui->delete_pushButton->setEnabled(true);
        ui->modify_pushButton->setEnabled(true);
    }
    else
    {
        ui->checkout_pushButton->setEnabled(false);
        ui->delete_pushButton->setEnabled(false);
        ui->modify_pushButton->setEnabled(false);
    }
}

void reservationsDialog::on_checkIn_pushButton_clicked()
{

}
