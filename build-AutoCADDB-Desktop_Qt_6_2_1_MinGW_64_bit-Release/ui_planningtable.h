/********************************************************************************
** Form generated from reading UI file 'planningtable.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlanningTable
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QTableWidget *tableWidget;
    QLabel *lblLocation;
    QGridLayout *gridLayout;
    QLabel *lblSelectFile;
    QPushButton *btnSelectFolder;
    QLineEdit *lineEdit;
    QLabel *lblSelectStation;
    QPushButton *btnAutoPLAN;
    QComboBox *comboBoxStations;
    QProgressBar *progressBar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PlanningTable)
    {
        if (PlanningTable->objectName().isEmpty())
            PlanningTable->setObjectName(QString::fromUtf8("PlanningTable"));
        PlanningTable->setWindowModality(Qt::NonModal);
        PlanningTable->resize(477, 264);
        centralwidget = new QWidget(PlanningTable);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEnabled(false);
        QFont font;
        font.setPointSize(8);
        font.setBold(true);
        tableWidget->setFont(font);
        tableWidget->setFrameShape(QFrame::HLine);
        tableWidget->setLineWidth(1);
        tableWidget->setGridStyle(Qt::CustomDashLine);
        tableWidget->setWordWrap(true);

        gridLayout_2->addWidget(tableWidget, 1, 0, 1, 2);

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


        gridLayout_3->addLayout(gridLayout_2, 3, 0, 1, 2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(13);
        gridLayout->setVerticalSpacing(6);
        lblSelectFile = new QLabel(centralwidget);
        lblSelectFile->setObjectName(QString::fromUtf8("lblSelectFile"));
        lblSelectFile->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lblSelectFile, 1, 0, 1, 1);

        btnSelectFolder = new QPushButton(centralwidget);
        btnSelectFolder->setObjectName(QString::fromUtf8("btnSelectFolder"));
        btnSelectFolder->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnSelectFolder->sizePolicy().hasHeightForWidth());
        btnSelectFolder->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnSelectFolder, 1, 2, 1, 1);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 1, 1, 1);

        lblSelectStation = new QLabel(centralwidget);
        lblSelectStation->setObjectName(QString::fromUtf8("lblSelectStation"));
        lblSelectStation->setMaximumSize(QSize(100, 16777215));
        lblSelectStation->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lblSelectStation->setMargin(0);

        gridLayout->addWidget(lblSelectStation, 2, 0, 1, 1);

        btnAutoPLAN = new QPushButton(centralwidget);
        btnAutoPLAN->setObjectName(QString::fromUtf8("btnAutoPLAN"));
        btnAutoPLAN->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnAutoPLAN->sizePolicy().hasHeightForWidth());
        btnAutoPLAN->setSizePolicy(sizePolicy1);
        btnAutoPLAN->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(btnAutoPLAN, 2, 2, 1, 1);

        comboBoxStations = new QComboBox(centralwidget);
        comboBoxStations->setObjectName(QString::fromUtf8("comboBoxStations"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBoxStations->sizePolicy().hasHeightForWidth());
        comboBoxStations->setSizePolicy(sizePolicy2);
        comboBoxStations->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(comboBoxStations, 2, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 2);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        gridLayout_3->addWidget(progressBar, 1, 0, 1, 1);

        PlanningTable->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PlanningTable);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 477, 17));
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
        lblLocation->setText(QString());
        lblSelectFile->setText(QCoreApplication::translate("PlanningTable", "Output folder", nullptr));
        btnSelectFolder->setText(QCoreApplication::translate("PlanningTable", "Select Folder", nullptr));
        lblSelectStation->setText(QCoreApplication::translate("PlanningTable", "Project", nullptr));
        btnAutoPLAN->setText(QCoreApplication::translate("PlanningTable", "AutoPLAN", nullptr));
        comboBoxStations->setPlaceholderText(QString());
    } // retranslateUi

};

namespace Ui {
    class PlanningTable: public Ui_PlanningTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLANNINGTABLE_H
