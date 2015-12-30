#include "availableRoomsWindow.h"
#include "ui_availableRoomsWindow.h"


availableRoomsWindow::availableRoomsWindow(QWidget *parent, viewParameters *parameters_) :
    QMainWindow(parent),
    ui(new Ui::availableRoomsWindow),
    parameters(parameters_)
{
    ui->setupUi(this);
    model = new availableRoomsModel(0, parameters);

    parameters->model = model;

    setGeometry( QStyle::alignedRect( Qt::LeftToRight,
                                      Qt::AlignCenter,
                                      size(),
                                      qApp->desktop()->availableGeometry() ) );
    initializeTable();
    configureInputs();
    updateBookButton();

    this->setFixedSize(this->width(),this->height());

    //login window
    loginDlg = new loginDialog(this, parameters);
//    int result = loginDlg->exec();
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

    bookingDlg = new bookingDialog(this, parameters);

    connect( ui->tableView->selectionModel(),
             SIGNAL( selectionChanged(const QItemSelection&, const QItemSelection&) ),
             this, SLOT( selectionChanged( const QItemSelection&, const QItemSelection&) ) );

    connect( model, SIGNAL( dataChanged(QModelIndex,QModelIndex) ),
             this, SLOT( updateBookButton() ) );

    connect( model, SIGNAL( dataChanged(QModelIndex,QModelIndex) ),
             this, SLOT( updateMaxGuestNumber() ) );

    connect( ui->actionManage_reservations,
             SIGNAL( triggered() ),
             this,
             SLOT( manageReservationsTriggered() ) );

    connect( ui->actionEdit_users__data,
             SIGNAL( triggered() ),
             this,
             SLOT( editUsersDataTriggered() ) );
}

void availableRoomsWindow::manageReservationsTriggered()
{
    qDebug() << "manageReservationsTriggered";
}

void availableRoomsWindow::editUsersDataTriggered()
{
    qDebug() << "editUsersDataTriggered";
}

void availableRoomsWindow::selectionChanged(const QItemSelection& selected, const QItemSelection&)
{
    QList<QModelIndex> indexes = selected.indexes();

    if(indexes.size() == 0)
        return;

    widgetMapper->setCurrentIndex( indexes.at(0).row() );
    bookingDlg->getWidgetMapper()->setCurrentIndex( indexes.at(0).row() );

    updateMaxGuestNumber();
    updateBookButton();
    updateRoomPrice();
}

void availableRoomsWindow::updateMaxGuestNumber()
{
    QList<QModelIndex> indexes = ui->tableView->selectionModel()->selection().indexes();

    // set 'maxGuestsNumber' for the 'bookingDlg'
    if(indexes.size() > 0)
    {
        int maxGuestsNumber = model->data( indexes.at(3) ).toInt();
        bookingDlg->setMaximumGuestsNumber(maxGuestsNumber);
    }
    else
        bookingDlg->setMaximumGuestsNumber(0);
}

void availableRoomsWindow::updateRoomPrice()
{
    QList<QModelIndex> indexes = ui->tableView->selectionModel()->selection().indexes();

    // set 'roomPrice' for the 'bookingDlg'
    if(indexes.size() > 0)
    {
        int roomPrice = model->data( indexes.at(2) ).toInt();
        bookingDlg->setRoomPrice(roomPrice);
    }
    else
        bookingDlg->setRoomPrice(0);
}

void availableRoomsWindow::updateBookButton()
{
    QList<QModelIndex> indexes = ui->tableView->selectionModel()->selection().indexes();
    // enable/disable 'Book' button, depending on the selection
    if( indexes.size() > 0 &&  "" != model->data( indexes.at(0) ).toString() )
        ui->book_pushButton->setEnabled(true);
    else
        ui->book_pushButton->setEnabled(false);
}

availableRoomsWindow::~availableRoomsWindow()
{
    delete loginDlg;
    delete bookingDlg;
    delete widgetMapper;
    delete model;
    delete ui;
}

void availableRoomsWindow::initializeTable()
{
    qDebug() << Q_FUNC_INFO;

    QTableView* tableView = ui->tableView;
    tableView->setModel(model);

    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->setAlternatingRowColors(true);
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    tableView->horizontalHeader()->setHighlightSections(false);
    tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    tableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
    tableView->horizontalHeader()->setSectionResizeMode(5, QHeaderView::ResizeToContents);

    tableView->hideColumn(1);
    tableView->hideColumn(6);
    tableView->hideColumn(7);
    tableView->hideColumn(8);
    tableView->hideColumn(9);
    tableView->hideColumn(10);
    tableView->hideColumn(11);
    tableView->hideColumn(12);
    tableView->hideColumn(13);

    tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void availableRoomsWindow::checkAvailableRooms()
{
    QString from = ui->from_dateEdit->date().toString("yyyy-MM-dd");
    QString till = ui->till_dateEdit->date().toString("yyyy-MM-dd");

    model->searchForAvailableRooms(from, till);
}

void availableRoomsWindow::configureInputs()
{
    widgetMapper = new QDataWidgetMapper(this);
    widgetMapper->setModel(model);
    widgetMapper->addMapping(ui->roomNumber_lineEdit, 0);
    widgetMapper->addMapping(ui->roomName_lineEdit, 1);
    widgetMapper->addMapping(ui->numberOfBeds_lineEdit, 3);
    widgetMapper->addMapping(ui->roomType_lineEdit, 4);
    widgetMapper->addMapping(ui->price_lineEdit, 2);
    widgetMapper->addMapping(ui->balcony_checkBox, 5);
    widgetMapper->addMapping(ui->additionalNotes_plainTextEdit, 6);

    ui->roomNumber_lineEdit->setReadOnly(true);
    ui->roomName_lineEdit->setReadOnly(true);
    ui->numberOfBeds_lineEdit->setReadOnly(true);
    ui->roomType_lineEdit->setReadOnly(true);
    ui->price_lineEdit->setReadOnly(true);
    ui->additionalNotes_plainTextEdit->setReadOnly(true);
    ui->balcony_checkBox->setDisabled(true);

    ui->roomNumber_lineEdit->setPlaceholderText("");
    ui->roomName_lineEdit->setPlaceholderText("");
    ui->numberOfBeds_lineEdit->setPlaceholderText("");
    ui->roomType_lineEdit->setPlaceholderText("");
    ui->price_lineEdit->setPlaceholderText("");

    QDate todaysDate = todaysDate.currentDate();
    ui->from_dateEdit->setDate( todaysDate );
    ui->till_dateEdit->setDate( todaysDate.addDays(7) );
}

void availableRoomsWindow::updateDate()
{
    bookingDlg->setFromTillDates( ui->from_dateEdit->date(),
                                  ui->till_dateEdit->date() );
}

void availableRoomsWindow::on_book_pushButton_clicked()
{
    updateDate();
    bookingDlg->exec();
}

void availableRoomsWindow::on_search_pushButton_clicked()
{
    checkAvailableRooms();

    QItemSelection selection = ui->tableView->selectionModel()->selection();

    selectionChanged(selection, selection);
}
