#include "availableRoomsBrowserDialog.h"
#include "ui_availableRoomsBrowserDialog.h"


availableRoomsBrowserDialog::availableRoomsBrowserDialog(QWidget *parent, viewParameters *parameters_) :
    QDialog(parent),
    ui(new Ui::availableRoomsBrowserDialog)
{
    ui->setupUi(this);
    parameters = parameters_;

    setGeometry( QStyle::alignedRect( Qt::LeftToRight,
                                      Qt::AlignCenter,
                                      size(),
                                      qApp->desktop()->availableGeometry() ) );

    model = new availableRoomsModel(0, parameters);

    initializeTable();
    configureLineEdits();

    //login window
    loginWnd = new loginDialog(this, parameters);
//    int result = loginWnd->exec();
//    if(1 != result)
//    {
//        qDebug() << "Unsuccessfull login";
//        exit(1);
//    }
//    else
    {
        QString title = "HSM: Available rooms browser";

        if(parameters->loggedInUser != "")
            title.append( QString( "  |  Logged in user: %1")
                          .arg(parameters->loggedInUser) );

        setWindowTitle(title);
    }


    connect(ui->search_pushButton, SIGNAL(clicked()),
            this, SLOT(checkAvailableRooms()));

    connect(ui->tableView->selectionModel(),
            SIGNAL( selectionChanged(const QItemSelection&, const QItemSelection&) ),
            this, SLOT(selectionChanged(const QItemSelection&, const QItemSelection&)) );
}

void availableRoomsBrowserDialog::selectionChanged(const QItemSelection& selected, const QItemSelection&)
{
    QList<QModelIndex> indexes = selected.indexes();
    widgetMapper->setCurrentIndex(indexes.at(0).row());
}

availableRoomsBrowserDialog::~availableRoomsBrowserDialog()
{
    delete loginWnd;
    delete widgetMapper;
    delete model;
    delete dateValidator;
    delete ui;
}

void availableRoomsBrowserDialog::initializeTable()
{
    qDebug() << Q_FUNC_INFO;

    QTableView* tableView = ui->tableView;
    tableView->setModel(model);

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

void availableRoomsBrowserDialog::checkAvailableRooms()
{
    QString from = ui->searchFrom_lineEdit->text();
    QString to = ui->searchTo_lineEdit->text();

    QRegExp rx("[0-9]{4}-[0-9]{2}-[0-9]{2}");
    QDateTime todaysDate = todaysDate.currentDateTime();

    //set todays date to 'from', if provided date has improper format or is emty
    if( !rx.exactMatch(from) )
    {
        from = todaysDate.toString("yyyy-MM-dd");
        ui->searchFrom_lineEdit->setText(from);
    }


    //set date from 'from' + 7 days, if provided date has improper format or is emty
    if( !rx.exactMatch(to) )
    {
        QDate fromDate = fromDate.fromString(from, "yyyy-MM-dd");
        QDateTime toDate( fromDate.addDays(7) );
        to = toDate.toString("yyyy-MM-dd");
        ui->searchTo_lineEdit->setText(to);
    }

    model->searchForAvailableRooms(from, to);
}


void availableRoomsBrowserDialog::configureLineEdits()
{
    QRegExp rx("[0-9]{4}-[0-9]{2}-[0-9]{2}");
    dateValidator = new QRegExpValidator(rx, this);

    ui->searchFrom_lineEdit->setValidator(dateValidator);
    ui->searchTo_lineEdit->setValidator(dateValidator);

    widgetMapper = new QDataWidgetMapper(this);
    widgetMapper->setModel(model);
    widgetMapper->addMapping(ui->roomNumber_lineEdit, 0);
    widgetMapper->addMapping(ui->roomName_lineEdit, 1);
    widgetMapper->addMapping(ui->numberOfBeds_lineEdit, 3);
    widgetMapper->addMapping(ui->roomType_lineEdit, 4);
    widgetMapper->addMapping(ui->price_lineEdit, 2);
    widgetMapper->addMapping(ui->balcony_checkBox, 5);

    ui->roomNumber_lineEdit->setReadOnly(true);
    ui->roomName_lineEdit->setReadOnly(true);
    ui->numberOfBeds_lineEdit->setReadOnly(true);
    ui->roomType_lineEdit->setReadOnly(true);
    ui->price_lineEdit->setReadOnly(true);
    ui->plainTextEdit->setReadOnly(true);
    ui->balcony_checkBox->setDisabled(true);

    ui->roomNumber_lineEdit->setPlaceholderText("");
    ui->roomName_lineEdit->setPlaceholderText("");
    ui->numberOfBeds_lineEdit->setPlaceholderText("");
    ui->roomType_lineEdit->setPlaceholderText("");
    ui->price_lineEdit->setPlaceholderText("");
}
