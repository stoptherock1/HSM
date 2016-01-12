#include "staffDialog.h"
#include "ui_staffDialog.h"

staffDialog::staffDialog(QWidget *parent, viewParameters *parameters_) :
    QDialog(parent),
    ui(new Ui::staffDialog),
    parameters(parameters_)
{
    ui->setupUi(this);
    initializeTable();
    addUserDlg = new addUserDialog();

    connect( addUserDlg,
             SIGNAL( newUserAdded(newUser&) ),
             parameters->staffMdl,
             SLOT( addNewUser(newUser&) ) );
}

staffDialog::~staffDialog()
{
    delete ui;
    delete addUserDlg;
}

void staffDialog::initializeTable()
{
    ui->tableView->setModel(parameters->staffMdl);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setAlternatingRowColors(true);

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableView->verticalHeader()->setDefaultSectionSize(23);


    ui->tableView->horizontalHeader()->setHighlightSections(false);
    ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setMinimumSectionSize(50);
}

void staffDialog::updateWindowTitle()
{
    QString title = "HSM: Staff browser";

    if(parameters->loggedInUser != "")
    {
        title.append( QString( "  |  Logged in user: %1")
                      .arg(parameters->loggedInUser) );

        if(parameters->isAdmin)
            title.append(" (admin)");
    }

    setWindowTitle(title);
}

void staffDialog::showEvent(QShowEvent * event)
{
    updateWindowTitle();
    QDialog::showEvent(event);
}

void staffDialog::on_pushButton_clicked()
{
    addUserDlg->exec();
}
