#include "BrowseWindow.h"
#include "ui_BrowseWindow.h"

void BrowseWindow::initializeTable()
{
    qDebug() << Q_FUNC_INFO;

    QTableWidget* table = ui->tableWidget;

    int rowsCount = 99;
    int columnsCount = 4;


    table->setRowCount(rowsCount);
    table->setColumnCount(columnsCount);

    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->horizontalHeader()->setHighlightSections(false);
    table->setAlternatingRowColors(true);

    QStringList headerLabels;
    headerLabels << "Room No" << "Number\nof persons" << "Available from" << "Reserved till";
    table->setHorizontalHeaderLabels(headerLabels);

    table->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    table->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    table->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    table->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);

    for(int i=0; i<rowsCount ; ++i)
    {
        for(int j=0; j<columnsCount; ++j)
        {
            QString itemText = "item " + QString::number(i) + QString::number(j);
            QTableWidgetItem *item = new QTableWidgetItem(itemText);
            table->setItem(i, j, item);
        }
    }
}

void BrowseWindow::executeQuery()
{
    qDebug() << Q_FUNC_INFO;

    // example of query to existing database
    if( db->isOpen() )
    {
        QSqlQuery query( *db );
        query.exec("select * from Room");

        qDebug() << "db =" << db;
        while( query.next() )
            qDebug() << query.value(0);
    }
}

BrowseWindow::BrowseWindow(QWidget *parent, std::shared_ptr<databaseConnection> dbConnection_) :
    QDialog(parent),
    ui(new Ui::BrowseWindow),
  dbConnection(dbConnection_)
{
    ui->setupUi(this);
    db = dbConnection->getDbPtr();

    initializeTable();
    executeQuery();
}

BrowseWindow::~BrowseWindow()
{
    delete ui;
}
