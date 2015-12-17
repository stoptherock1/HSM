#include "browseWindow.h"
#include "ui_browseWindow.h"


browseWindow::browseWindow(QWidget *parent, const viewParameters *parameters) :
    QDialog(parent),
    ui(new Ui::browseWindow)
{
    ui->setupUi(this);
    db = parameters->dbConnection->getDbPtr();
    QString title = "HSM: Room browser";

    if(parameters->loggedInUser != "")
        title.append( QString( ": %1 is logged in").arg(parameters->loggedInUser) );

    QRegExp rx("[0-9]{4}-[0-9]{2}-[0-9]{2}");

    //memory leak
    ui->availableFrom_lineEdit->setValidator( new QRegExpValidator(rx, this) );
    ui->availableTo_lineEdit->setValidator( new QRegExpValidator(rx, this) );

    setWindowTitle(title);

    model = new availableRoomsModel(0, parameters);

    initializeTable();

    connect(ui->search_pushButton, SIGNAL(clicked()),
            this, SLOT(checkAvailableRooms()));
}

browseWindow::~browseWindow()
{
    delete ui;
}

void browseWindow::initializeTable()
{
    qDebug() << Q_FUNC_INFO;

    QTableView* tableView = ui->tableView;
    tableView->setModel(model);

//    left as an example for a model design
//    the tableWidget is now replaced with the tableView

//    QTableWidget* tableView = ui->tableWidget;
//    int rowsCount = 99;
//    int columnsCount = 4;
//    tableView->setRowCount(rowsCount);
//    tableView->setColumnCount(columnsCount);

    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->horizontalHeader()->setHighlightSections(false);
    tableView->setAlternatingRowColors(true);
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);

//    QStringList headerLabels;
//    headerLabels << "Room No" << "Number\nof persons" << "Available from" << "Reserved till";
//    tableView->setHorizontalHeaderLabels(headerLabels);

//    tableView->hideColumn(0);

    tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);

    tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void browseWindow::checkAvailableRooms()
{
    QString from = ui->availableFrom_lineEdit->text();
    QString to = ui->availableTo_lineEdit->text();

    QRegExp rx("[0-9]{4}-[0-9]{2}-[0-9]{2}");
    QDateTime todaysDate = todaysDate.currentDateTime();

    //set todays date to 'from', if provided date has improper format or is emty
    if( !rx.exactMatch(from) )
    {
        from = todaysDate.toString("yyyy-MM-dd");
        ui->availableFrom_lineEdit->setText(from);
    }


    //set date from 'from' + 7 days, if provided date has improper format or is emty
    if( !rx.exactMatch(to) )
    {
        QDate fromDate = fromDate.fromString(from, "yyyy-MM-dd");
        QDateTime toDate( fromDate.addDays(7) );
        to = toDate.toString("yyyy-MM-dd");
        ui->availableTo_lineEdit->setText(to);
    }

    model->searchForAvailableRooms(from, to);
}
