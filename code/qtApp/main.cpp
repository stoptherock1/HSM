#include <QApplication>
#include "databaseConnection.h"
//#include "modelview.h"
#include "tableeditor.h"
#include "editablesqlmodel.h"
#include "sqlquerymodel.h"
#include <QtWidgets>

void initializeModel(QSqlQueryModel *model)
{
    model->setQuery("select * from Staff");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ssNR"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("username"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("password"));
}

QTableView* createView(QSqlQueryModel *model, const QString &title = "")
{
    QTableView *view = new QTableView;
    view->setModel(model);
    static int offset = 0;
    view->setWindowTitle(title);
    view->move(100 + offset, 100 + offset);
    offset += 20;
    view->show();

    return view;
}
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    std::shared_ptr<databaseConnection> dbConnection = std::make_shared<databaseConnection>();
    if(!dbConnection->establish())
    {
        return 1;
    }
    TableEditor editor("Staff");
    editor.show();
//    QSqlQueryModel plainModel;
//    EditableSqlModel editableModel;
//    SqlQueryModel customModel;

//    initializeModel(&plainModel);
//    initializeModel(&editableModel);
//    initializeModel(&customModel);

//    createView(&plainModel, QObject::tr("Plain Query Model"));
//    createView(&editableModel, QObject::tr("Editable Query Model"));
//    createView(&customModel, QObject::tr("Custom Query Model"));
    return app.exec();
   // ModelView * model = new ModelView(0, dbConnection);
}



