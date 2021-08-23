/********************************************************************************
** Form generated from reading UI file 'test.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_H
#define UI_TEST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Test
{
public:
    QAction *actionhori;
    QAction *actionver;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton;
    QWidget *tab_3;
    QGridLayout *gridLayout_3;
    QWidget *tab_2;
    QGridLayout *gridLayout_4;
    QWidget *tab_4;
    QGridLayout *gridLayout_2;
    QMenuBar *menubar;
    QMenu *menuH;
    QMenu *menuv;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Test)
    {
        if (Test->objectName().isEmpty())
            Test->setObjectName(QString::fromUtf8("Test"));
        Test->resize(828, 442);
        actionhori = new QAction(Test);
        actionhori->setObjectName(QString::fromUtf8("actionhori"));
        actionver = new QAction(Test);
        actionver->setObjectName(QString::fromUtf8("actionver"));
        centralwidget = new QWidget(Test);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setLayoutDirection(Qt::RightToLeft);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setElideMode(Qt::ElideMiddle);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tab->setFocusPolicy(Qt::TabFocus);
        tab->setLayoutDirection(Qt::LeftToRight);
        gridLayout_5 = new QGridLayout(tab);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_5->addWidget(pushButton, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_3 = new QGridLayout(tab_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_4 = new QGridLayout(tab_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_2 = new QGridLayout(tab_4);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(11, -1, -1, -1);
        tabWidget->addTab(tab_4, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        Test->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Test);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 828, 25));
        menuH = new QMenu(menubar);
        menuH->setObjectName(QString::fromUtf8("menuH"));
        menuv = new QMenu(menubar);
        menuv->setObjectName(QString::fromUtf8("menuv"));
        Test->setMenuBar(menubar);
        statusbar = new QStatusBar(Test);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Test->setStatusBar(statusbar);

        menubar->addAction(menuH->menuAction());
        menubar->addAction(menuv->menuAction());
        menuH->addAction(actionhori);
        menuH->addAction(actionver);

        retranslateUi(Test);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Test);
    } // setupUi

    void retranslateUi(QMainWindow *Test)
    {
        Test->setWindowTitle(QCoreApplication::translate("Test", "MainWindow", nullptr));
        actionhori->setText(QCoreApplication::translate("Test", "hori", nullptr));
        actionver->setText(QCoreApplication::translate("Test", "ver", nullptr));
        pushButton->setText(QCoreApplication::translate("Test", "PushButton", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("Test", "Page", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("Test", "Page", nullptr));
        menuH->setTitle(QCoreApplication::translate("Test", "H", nullptr));
        menuv->setTitle(QCoreApplication::translate("Test", "v", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Test: public Ui_Test {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_H
