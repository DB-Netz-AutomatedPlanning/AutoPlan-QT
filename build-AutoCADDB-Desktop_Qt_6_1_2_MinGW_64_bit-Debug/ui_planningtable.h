/********************************************************************************
** Form generated from reading UI file 'planningtable.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLANNINGTABLE_H
#define UI_PLANNINGTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlanningTable
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *lblSelectStation;
    QComboBox *comboBoxStations;
    QPushButton *btnLoad;
    QPushButton *btnAutoPLAN;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout_2;
    QLabel *lblLocation;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PlanningTable)
    {
        if (PlanningTable->objectName().isEmpty())
            PlanningTable->setObjectName(QString::fromUtf8("PlanningTable"));
        PlanningTable->setWindowModality(Qt::NonModal);
        PlanningTable->resize(623, 365);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PlanningTable->sizePolicy().hasHeightForWidth());
        PlanningTable->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(8);
        font.setBold(false);
        PlanningTable->setFont(font);
        PlanningTable->setFocusPolicy(Qt::StrongFocus);
        PlanningTable->setWindowOpacity(3.000000000000000);
        centralwidget = new QWidget(PlanningTable);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lblSelectStation = new QLabel(centralwidget);
        lblSelectStation->setObjectName(QString::fromUtf8("lblSelectStation"));
        lblSelectStation->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lblSelectStation, 0, 0, 1, 1);

        comboBoxStations = new QComboBox(centralwidget);
        comboBoxStations->setObjectName(QString::fromUtf8("comboBoxStations"));

        gridLayout->addWidget(comboBoxStations, 0, 1, 1, 1);

        btnLoad = new QPushButton(centralwidget);
        btnLoad->setObjectName(QString::fromUtf8("btnLoad"));
        btnLoad->setEnabled(true);

        gridLayout->addWidget(btnLoad, 0, 2, 1, 1);

        btnAutoPLAN = new QPushButton(centralwidget);
        btnAutoPLAN->setObjectName(QString::fromUtf8("btnAutoPLAN"));
        btnAutoPLAN->setEnabled(false);

        gridLayout->addWidget(btnAutoPLAN, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(214, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 2);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(275, 62, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 1, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lblLocation = new QLabel(centralwidget);
        lblLocation->setObjectName(QString::fromUtf8("lblLocation"));
        lblLocation->setEnabled(false);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe Script")});
        font1.setPointSize(10);
        font1.setBold(true);
        lblLocation->setFont(font1);
        lblLocation->setAutoFillBackground(false);
        lblLocation->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lblLocation, 0, 0, 1, 2);

        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEnabled(false);
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(true);
        tableWidget->setFont(font2);
        tableWidget->setFrameShape(QFrame::HLine);
        tableWidget->setLineWidth(1);
        tableWidget->setGridStyle(Qt::CustomDashLine);
        tableWidget->setWordWrap(true);

        gridLayout_2->addWidget(tableWidget, 1, 0, 1, 2);


        gridLayout_3->addLayout(gridLayout_2, 1, 0, 1, 2);

        PlanningTable->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PlanningTable);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 623, 23));
        PlanningTable->setMenuBar(menubar);
        statusbar = new QStatusBar(PlanningTable);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PlanningTable->setStatusBar(statusbar);

        retranslateUi(PlanningTable);

        QMetaObject::connectSlotsByName(PlanningTable);
    } // setupUi

    void retranslateUi(QMainWindow *PlanningTable)
    {
        PlanningTable->setWindowTitle(QCoreApplication::translate("PlanningTable", "Planning", nullptr));
        lblSelectStation->setText(QCoreApplication::translate("PlanningTable", "Select Station", nullptr));
        btnLoad->setText(QCoreApplication::translate("PlanningTable", "Load", nullptr));
        btnAutoPLAN->setText(QCoreApplication::translate("PlanningTable", "AutoPLAN", nullptr));
        lblLocation->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PlanningTable: public Ui_PlanningTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLANNINGTABLE_H
