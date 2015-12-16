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
    tableView->setModel(&model);

//    left as an example for a model design
//    the tableWidget is now replaced with the tableView

//    QTableWidget* table = ui->tableWidget;
//    int rowsCount = 99;
//    int columnsCount = 4;
//    table->setRowCount(rowsCount);
//    table->setColumnCount(columnsCount);

//    table->setSelectionBehavior(QAbstractItemView::SelectRows);
//    table->horizontalHeader()->setHighlightSections(false);
//    table->setAlternatingRowColors(true);
//    table->setSelectionMode(QAbstractItemView::SingleSelection);

//    QStringList headerLabels;
//    headerLabels << "Room No" << "Number\nof persons" << "Available from" << "Reserved till";
//    table->setHorizontalHeaderLabels(headerLabels);

//    table->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
//    table->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
//    table->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
//    table->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);

//    table->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

//    for(int i=0; i<rowsCount ; ++i)
//    {
//        for(int j=0; j<columnsCount; ++j)
//        {
//            QString itemText = "item " + QString::number(i) + QString::number(j);
//            QTableWidgetItem *item = new QTableWidgetItem(itemText);
//            table->setItem(i, j, item);
//        }
//    }
}

void browseWindow::checkAvailableRooms()
{
    QString from = ui->availableFrom_lineEdit->text();
    QString to = ui->availableTo_lineEdit->text();
    model.searchForAvailableRooms(from, to);
    //call model
}
