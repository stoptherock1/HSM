#ifndef TABLEEDITOR_H
#define TABLEEDITOR_H
class QDialogButtonBox;
class QPushButton;
class QSqlTableModel;
class QLineEdit;

#include <QDialog>

class TableEditor : public QWidget
{
    Q_OBJECT

public:
    explicit TableEditor(const QString &tableName, QWidget *parent = 0);


private slots:
    void submit();
    void login();

private:
    QLineEdit *userName;
    QLineEdit *passWord;
    QPushButton *submitButton;
    QPushButton *revertButton;
    QPushButton *quitButton;
    QPushButton *loginButton;
    QDialogButtonBox *buttonBox;
    QSqlTableModel *model;
};

#endif // TABLEEDITOR_H
