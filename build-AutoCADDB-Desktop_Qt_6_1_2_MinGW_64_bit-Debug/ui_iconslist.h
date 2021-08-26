/********************************************************************************
** Form generated from reading UI file 'iconslist.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ICONSLIST_H
#define UI_ICONSLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IconsList
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QListWidget *listWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *IconsList)
    {
        if (IconsList->objectName().isEmpty())
            IconsList->setObjectName(QString::fromUtf8("IconsList"));
        IconsList->resize(240, 500);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(IconsList->sizePolicy().hasHeightForWidth());
        IconsList->setSizePolicy(sizePolicy);
        IconsList->setMinimumSize(QSize(240, 500));
        IconsList->setMaximumSize(QSize(500, 1000));
        centralwidget = new QWidget(IconsList);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        listWidget = new QListWidget(centralwidget);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/assets/fifteenSvgs/Schutzhalt.svg"), QSize(), QIcon::Normal, QIcon::On);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setIcon(icon);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/assets/fifteenSvgs/Haltetafel.svg"), QSize(), QIcon::Normal, QIcon::On);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setIcon(icon1);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/assets/fifteenSvgs/hauptsignalmain.svg"), QSize(), QIcon::Normal, QIcon::On);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listWidget);
        __qlistwidgetitem2->setIcon(icon2);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/assets/fifteenSvgs/vorsignal.svg"), QSize(), QIcon::Normal, QIcon::On);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(listWidget);
        __qlistwidgetitem3->setIcon(icon3);
        __qlistwidgetitem3->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/assets/fifteenSvgs/Rangierhalttafel.svg"), QSize(), QIcon::Normal, QIcon::On);
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(listWidget);
        __qlistwidgetitem4->setIcon(icon4);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/assets/fifteenSvgs/Radsensor.svg"), QSize(), QIcon::Normal, QIcon::On);
        QListWidgetItem *__qlistwidgetitem5 = new QListWidgetItem(listWidget);
        __qlistwidgetitem5->setIcon(icon5);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/assets/fifteenSvgs/Hauptsignal.svg"), QSize(), QIcon::Normal, QIcon::On);
        QListWidgetItem *__qlistwidgetitem6 = new QListWidgetItem(listWidget);
        __qlistwidgetitem6->setIcon(icon6);
        __qlistwidgetitem6->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QFont font;
        font.setPointSize(11);
        listWidget->setFont(font);
        listWidget->setIconSize(QSize(30, 30));

        gridLayout->addWidget(listWidget, 0, 0, 1, 1);

        IconsList->setCentralWidget(centralwidget);
        menubar = new QMenuBar(IconsList);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 240, 21));
        IconsList->setMenuBar(menubar);
        statusbar = new QStatusBar(IconsList);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        IconsList->setStatusBar(statusbar);

        retranslateUi(IconsList);

        QMetaObject::connectSlotsByName(IconsList);
    } // setupUi

    void retranslateUi(QMainWindow *IconsList)
    {
        IconsList->setWindowTitle(QCoreApplication::translate("IconsList", "MainWindow", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("IconsList", "Schutzhalt", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("IconsList", "Haltetafel", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("IconsList", "Mehrabschnittssignal", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("IconsList", "Vorsignal", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("IconsList", "Rangierhalttafel", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = listWidget->item(5);
        ___qlistwidgetitem5->setText(QCoreApplication::translate("IconsList", "Radsensor", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = listWidget->item(6);
        ___qlistwidgetitem6->setText(QCoreApplication::translate("IconsList", "Hauptsignal", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class IconsList: public Ui_IconsList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ICONSLIST_H
