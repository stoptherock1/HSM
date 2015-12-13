/********************************************************************************
** Form generated from reading UI file 'browseWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BROWSEWINDOW_H
#define UI_BROWSEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_browseWindow
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QCheckBox *checkBox;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_2;
    QPlainTextEdit *plainTextEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *browseWindow)
    {
        if (browseWindow->objectName().isEmpty())
            browseWindow->setObjectName(QStringLiteral("browseWindow"));
        browseWindow->resize(773, 468);
        verticalLayout = new QVBoxLayout(browseWindow);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tableWidget = new QTableWidget(browseWindow);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        horizontalLayout->addWidget(tableWidget);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit_4 = new QLineEdit(browseWindow);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 2, 0, 1, 1);

        lineEdit_5 = new QLineEdit(browseWindow);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 0, 0, 1, 1);

        checkBox = new QCheckBox(browseWindow);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout->addWidget(checkBox, 4, 0, 1, 1);

        lineEdit_6 = new QLineEdit(browseWindow);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        gridLayout->addWidget(lineEdit_6, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(browseWindow);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 3, 0, 1, 1);

        plainTextEdit = new QPlainTextEdit(browseWindow);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        gridLayout->addWidget(plainTextEdit, 5, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton = new QPushButton(browseWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        gridLayout->addLayout(horizontalLayout_2, 6, 0, 1, 1);

        gridLayout->setRowStretch(0, 1);

        horizontalLayout->addLayout(gridLayout);

        horizontalLayout->setStretch(0, 1);

        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(browseWindow);

        QMetaObject::connectSlotsByName(browseWindow);
    } // setupUi

    void retranslateUi(QDialog *browseWindow)
    {
        browseWindow->setWindowTitle(QApplication::translate("browseWindow", "Dialog", 0));
        lineEdit_4->setPlaceholderText(QApplication::translate("browseWindow", "Available from", 0));
        lineEdit_5->setPlaceholderText(QApplication::translate("browseWindow", "Room number", 0));
        checkBox->setText(QApplication::translate("browseWindow", "Balcony", 0));
        lineEdit_6->setPlaceholderText(QApplication::translate("browseWindow", "Number of persons", 0));
        lineEdit_2->setPlaceholderText(QApplication::translate("browseWindow", "Reserved till", 0));
        plainTextEdit->setPlaceholderText(QApplication::translate("browseWindow", "Additional notes", 0));
        pushButton->setText(QApplication::translate("browseWindow", "Edit", 0));
    } // retranslateUi

};

namespace Ui {
    class browseWindow: public Ui_browseWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BROWSEWINDOW_H
