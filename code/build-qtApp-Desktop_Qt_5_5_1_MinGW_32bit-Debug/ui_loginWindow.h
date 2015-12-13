/********************************************************************************
** Form generated from reading UI file 'loginWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_loginWindow
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *status_label;
    QLineEdit *usename_lineEdit;
    QLineEdit *password_lineEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *login_pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *loginWindow)
    {
        if (loginWindow->objectName().isEmpty())
            loginWindow->setObjectName(QStringLiteral("loginWindow"));
        loginWindow->resize(203, 168);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(loginWindow->sizePolicy().hasHeightForWidth());
        loginWindow->setSizePolicy(sizePolicy);
        loginWindow->setCursor(QCursor(Qt::ArrowCursor));
        loginWindow->setWindowOpacity(1);
        loginWindow->setSizeGripEnabled(false);
        verticalLayout = new QVBoxLayout(loginWindow);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        label = new QLabel(loginWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        status_label = new QLabel(loginWindow);
        status_label->setObjectName(QStringLiteral("status_label"));
        status_label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(status_label);

        usename_lineEdit = new QLineEdit(loginWindow);
        usename_lineEdit->setObjectName(QStringLiteral("usename_lineEdit"));
        usename_lineEdit->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(usename_lineEdit);

        password_lineEdit = new QLineEdit(loginWindow);
        password_lineEdit->setObjectName(QStringLiteral("password_lineEdit"));
        password_lineEdit->setInputMethodHints(Qt::ImhNone);
        password_lineEdit->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(password_lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        login_pushButton = new QPushButton(loginWindow);
        login_pushButton->setObjectName(QStringLiteral("login_pushButton"));

        horizontalLayout->addWidget(login_pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addLayout(verticalLayout_2);


        retranslateUi(loginWindow);

        QMetaObject::connectSlotsByName(loginWindow);
    } // setupUi

    void retranslateUi(QDialog *loginWindow)
    {
        loginWindow->setWindowTitle(QApplication::translate("loginWindow", "Login", 0));
        label->setText(QApplication::translate("loginWindow", "Provide credentials", 0));
        status_label->setText(QApplication::translate("loginWindow", "sdcds", 0));
        usename_lineEdit->setPlaceholderText(QApplication::translate("loginWindow", "Username", 0));
        password_lineEdit->setPlaceholderText(QApplication::translate("loginWindow", "Password", 0));
        login_pushButton->setText(QApplication::translate("loginWindow", "Login", 0));
    } // retranslateUi

};

namespace Ui {
    class loginWindow: public Ui_loginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
