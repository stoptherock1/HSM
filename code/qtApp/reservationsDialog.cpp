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

    ui->checkOut_pushButton->setEnabled(false);
    ui->delete_pushButton->setEnabled(false);
    ui->modify_pushButton->setEnabled(false);
    ui->checkIn_pushButton->setEnabled(false);

    QString title = "HSM: Manage current reservations";

    if(parameters->loggedInUser != "")
        title.append( QString( "  |  Logged in user: %1")
                      .arg(parameters->loggedInUser) );

    setWindowTitle(title);

    connect( ui->tableView->selectionModel(),
             SIGNAL( selectionChanged(const QItemSelection&, const QItemSelection&) ),
             this,
             SLOT( selectionChanged( const QItemSelection&, const QItemSelection&) ) );

    connect( ui->checkIn_pushButton,
             SIGNAL( clicked() ),
             this,
             SLOT( updateSelection() ) );

    connect( ui->checkOut_pushButton,
             SIGNAL( clicked() ),
             this,
             SLOT( updateSelection() ) );

    connect( ui->delete_pushButton,
             SIGNAL( clicked() ),
             this,
             SLOT( updateSelection() ) );

    connect( ui->modify_pushButton,
             SIGNAL( clicked() ),
             this,
             SLOT( updateSelection() ) );

    connect( ui->filter_lineEdit,
             SIGNAL( textEdited(QString) ),
             this,
             SLOT( updateSelection() ) );
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

int reservationsDialog::getSelectedReservationNumber()
{
    int reservationNr = -1;

    QList<QModelIndex> indexes = ui->tableView->selectionModel()->selection().indexes();
    if( indexes.size() > 0 &&  "" != parameters->reservationMdl->data( indexes.at(0) ).toString() )
        reservationNr = parameters->reservationMdl->data( indexes.at(0) ).toInt();

    return reservationNr;
}

void reservationsDialog::on_checkOut_pushButton_clicked()
{
    int reservationNr = getSelectedReservationNumber();

    if(0 < reservationNr)
        parameters->reservationMdl->insertOld_Reservation(reservationNr);
}

void reservationsDialog::updateButtons()
{
    QModelIndex selectedIndex = parameters->reservationMdl->index(selectedRow, 0);

    // enable/disable buttons, depending on the selection
    if("" != parameters->reservationMdl->data(selectedIndex).toString() )
    {
        ui->checkOut_pushButton->setEnabled(true);
        ui->checkIn_pushButton->setEnabled(true);
//        ui->delete_pushButton->setEnabled(true);
//        ui->modify_pushButton->setEnabled(true);
    }
    else
    {
        ui->checkOut_pushButton->setEnabled(false);
        ui->checkIn_pushButton->setEnabled(false);
        ui->delete_pushButton->setEnabled(false);
        ui->modify_pushButton->setEnabled(false);
    }
}

void reservationsDialog::selectionChanged(const QItemSelection& selected, const QItemSelection&)
{
    QList<QModelIndex> indexes = selected.indexes();

    if(indexes.size() > 0)
        selectedRow = indexes.at(0).row();

    qDebug() << selectedRow;

    updateButtons();
}

void reservationsDialog::on_checkIn_pushButton_clicked()
{
    int reservationNr = getSelectedReservationNumber();

    if(0 < reservationNr)
        parameters->reservationMdl->performActualCheckIn(reservationNr);
}

void reservationsDialog::on_filter_lineEdit_textEdited(const QString &arg1)
{
    if("" != arg1)
        parameters->reservationMdl->setFilter( QString("ssNr LIKE '%1%'").arg(arg1) );
    else
        parameters->reservationMdl->setFilter("");

    qDebug() << parameters->reservationMdl->query().lastQuery();

    parameters->reservationMdl->select();
}


void reservationsDialog::updateSelection()
{
    QModelIndex selectedIndex;
    QString selectedText;

    //try to select 1 row
    selectedIndex = parameters->reservationMdl->index(0,0);
    selectedText = parameters->reservationMdl->data(selectedIndex).toString();
    if(selectedRow < 0 && "" != selectedText)
    {
        selectedRow = 0;
        ui->tableView->selectRow(selectedRow);
        return;
    }

    do
    {
        selectedIndex = parameters->reservationMdl->index(selectedRow,0);
        selectedText = parameters->reservationMdl->data(selectedIndex).toString();

        if("" != selectedText)
            break;

        --selectedRow;
        if(selectedRow < 0)
        {
            ui->tableView->clearSelection();
            return;
        }

        selectedText = parameters->reservationMdl->data(selectedIndex).toString();
    }
    while("" == selectedText);

    ui->tableView->selectRow(selectedRow);
}

void reservationsDialog::on_delete_pushButton_clicked()
{

}
