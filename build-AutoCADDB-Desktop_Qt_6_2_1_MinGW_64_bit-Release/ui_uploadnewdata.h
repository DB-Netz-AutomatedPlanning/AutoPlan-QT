/********************************************************************************
** Form generated from reading UI file 'uploadnewdata.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPLOADNEWDATA_H
#define UI_UPLOADNEWDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_UploadNewData
{
public:
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QGridLayout *gridLayout_2;
    QComboBox *comboBox;
    QPushButton *btnClickHere;
    QLabel *lblEnableData;
    QLabel *lblSelection;
    QGridLayout *gridLayout;
    QLabel *lblUberhohung;
    QLineEdit *lineEditUberhohung;
    QPushButton *btnLage;
    QPushButton *btnKMLine;
    QPushButton *btnGleisknoten;
    QLabel *lblGleiskanten;
    QLabel *lblGleisknoten;
    QLineEdit *lineEditGleisknoten;
    QPushButton *btnGleiskanten;
    QLabel *lblLage;
    QPushButton *btnHoehe;
    QLineEdit *lineEditHoehe;
    QLabel *lblHoehe;
    QLineEdit *lineEditGleiskanten;
    QLineEdit *lineEditKMLine;
    QLabel *lblKMLine;
    QPushButton *btnUberhohung;
    QLineEdit *lineEditLage;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnOK;
    QPushButton *btnCancel;

    void setupUi(QDialog *UploadNewData)
    {
        if (UploadNewData->objectName().isEmpty())
            UploadNewData->setObjectName(QString::fromUtf8("UploadNewData"));
        UploadNewData->resize(532, 335);
        gridLayout_3 = new QGridLayout(UploadNewData);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(UploadNewData);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        comboBox = new QComboBox(UploadNewData);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setEnabled(false);
        comboBox->setEditable(false);

        gridLayout_2->addWidget(comboBox, 0, 1, 1, 2);

        btnClickHere = new QPushButton(UploadNewData);
        btnClickHere->setObjectName(QString::fromUtf8("btnClickHere"));
        btnClickHere->setEnabled(false);

        gridLayout_2->addWidget(btnClickHere, 3, 2, 1, 1);

        lblEnableData = new QLabel(UploadNewData);
        lblEnableData->setObjectName(QString::fromUtf8("lblEnableData"));

        gridLayout_2->addWidget(lblEnableData, 3, 1, 1, 1);

        lblSelection = new QLabel(UploadNewData);
        lblSelection->setObjectName(QString::fromUtf8("lblSelection"));
        lblSelection->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(lblSelection, 0, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_2);


        gridLayout_3->addLayout(horizontalLayout_2, 0, 0, 1, 2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lblUberhohung = new QLabel(UploadNewData);
        lblUberhohung->setObjectName(QString::fromUtf8("lblUberhohung"));
        lblUberhohung->setEnabled(false);
        lblUberhohung->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblUberhohung, 5, 0, 1, 1);

        lineEditUberhohung = new QLineEdit(UploadNewData);
        lineEditUberhohung->setObjectName(QString::fromUtf8("lineEditUberhohung"));
        lineEditUberhohung->setEnabled(false);

        gridLayout->addWidget(lineEditUberhohung, 5, 1, 1, 1);

        btnLage = new QPushButton(UploadNewData);
        btnLage->setObjectName(QString::fromUtf8("btnLage"));
        btnLage->setEnabled(false);

        gridLayout->addWidget(btnLage, 4, 2, 1, 1);

        btnKMLine = new QPushButton(UploadNewData);
        btnKMLine->setObjectName(QString::fromUtf8("btnKMLine"));
        btnKMLine->setEnabled(false);

        gridLayout->addWidget(btnKMLine, 2, 2, 1, 1);

        btnGleisknoten = new QPushButton(UploadNewData);
        btnGleisknoten->setObjectName(QString::fromUtf8("btnGleisknoten"));
        btnGleisknoten->setEnabled(false);

        gridLayout->addWidget(btnGleisknoten, 0, 2, 1, 1);

        lblGleiskanten = new QLabel(UploadNewData);
        lblGleiskanten->setObjectName(QString::fromUtf8("lblGleiskanten"));
        lblGleiskanten->setEnabled(false);
        lblGleiskanten->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblGleiskanten, 3, 0, 1, 1);

        lblGleisknoten = new QLabel(UploadNewData);
        lblGleisknoten->setObjectName(QString::fromUtf8("lblGleisknoten"));
        lblGleisknoten->setEnabled(false);
        lblGleisknoten->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblGleisknoten, 0, 0, 1, 1);

        lineEditGleisknoten = new QLineEdit(UploadNewData);
        lineEditGleisknoten->setObjectName(QString::fromUtf8("lineEditGleisknoten"));
        lineEditGleisknoten->setEnabled(false);

        gridLayout->addWidget(lineEditGleisknoten, 0, 1, 1, 1);

        btnGleiskanten = new QPushButton(UploadNewData);
        btnGleiskanten->setObjectName(QString::fromUtf8("btnGleiskanten"));
        btnGleiskanten->setEnabled(false);

        gridLayout->addWidget(btnGleiskanten, 3, 2, 1, 1);

        lblLage = new QLabel(UploadNewData);
        lblLage->setObjectName(QString::fromUtf8("lblLage"));
        lblLage->setEnabled(false);
        lblLage->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblLage, 4, 0, 1, 1);

        btnHoehe = new QPushButton(UploadNewData);
        btnHoehe->setObjectName(QString::fromUtf8("btnHoehe"));
        btnHoehe->setEnabled(false);

        gridLayout->addWidget(btnHoehe, 1, 2, 1, 1);

        lineEditHoehe = new QLineEdit(UploadNewData);
        lineEditHoehe->setObjectName(QString::fromUtf8("lineEditHoehe"));
        lineEditHoehe->setEnabled(false);

        gridLayout->addWidget(lineEditHoehe, 1, 1, 1, 1);

        lblHoehe = new QLabel(UploadNewData);
        lblHoehe->setObjectName(QString::fromUtf8("lblHoehe"));
        lblHoehe->setEnabled(false);
        lblHoehe->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblHoehe, 1, 0, 1, 1);

        lineEditGleiskanten = new QLineEdit(UploadNewData);
        lineEditGleiskanten->setObjectName(QString::fromUtf8("lineEditGleiskanten"));
        lineEditGleiskanten->setEnabled(false);

        gridLayout->addWidget(lineEditGleiskanten, 3, 1, 1, 1);

        lineEditKMLine = new QLineEdit(UploadNewData);
        lineEditKMLine->setObjectName(QString::fromUtf8("lineEditKMLine"));
        lineEditKMLine->setEnabled(false);

        gridLayout->addWidget(lineEditKMLine, 2, 1, 1, 1);

        lblKMLine = new QLabel(UploadNewData);
        lblKMLine->setObjectName(QString::fromUtf8("lblKMLine"));
        lblKMLine->setEnabled(false);
        lblKMLine->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblKMLine, 2, 0, 1, 1);

        btnUberhohung = new QPushButton(UploadNewData);
        btnUberhohung->setObjectName(QString::fromUtf8("btnUberhohung"));
        btnUberhohung->setEnabled(false);

        gridLayout->addWidget(btnUberhohung, 5, 2, 1, 1);

        lineEditLage = new QLineEdit(UploadNewData);
        lineEditLage->setObjectName(QString::fromUtf8("lineEditLage"));
        lineEditLage->setEnabled(false);

        gridLayout->addWidget(lineEditLage, 4, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 1, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(392, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnOK = new QPushButton(UploadNewData);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));
        btnOK->setEnabled(false);

        horizontalLayout->addWidget(btnOK);

        btnCancel = new QPushButton(UploadNewData);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setEnabled(true);

        horizontalLayout->addWidget(btnCancel);


        gridLayout_3->addLayout(horizontalLayout, 2, 1, 1, 1);


        retranslateUi(UploadNewData);

        QMetaObject::connectSlotsByName(UploadNewData);
    } // setupUi

    void retranslateUi(QDialog *UploadNewData)
    {
        UploadNewData->setWindowTitle(QCoreApplication::translate("UploadNewData", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("UploadNewData", "Modify Imported Data", nullptr));
        btnClickHere->setText(QCoreApplication::translate("UploadNewData", "here", nullptr));
        lblEnableData->setText(QCoreApplication::translate("UploadNewData", "To Enable Data Field, Click", nullptr));
        lblSelection->setText(QCoreApplication::translate("UploadNewData", "Project Name", nullptr));
        lblUberhohung->setText(QCoreApplication::translate("UploadNewData", "Entwurfselement \303\234berh\303\266hung", nullptr));
        btnLage->setText(QCoreApplication::translate("UploadNewData", "Add File", nullptr));
        btnKMLine->setText(QCoreApplication::translate("UploadNewData", "Add File", nullptr));
        btnGleisknoten->setText(QCoreApplication::translate("UploadNewData", "Add File", nullptr));
        lblGleiskanten->setText(QCoreApplication::translate("UploadNewData", "Gleiskanten", nullptr));
        lblGleisknoten->setText(QCoreApplication::translate("UploadNewData", "Gleisknoten", nullptr));
        btnGleiskanten->setText(QCoreApplication::translate("UploadNewData", "Add File", nullptr));
        lblLage->setText(QCoreApplication::translate("UploadNewData", "Entwurfselement_Lage", nullptr));
        btnHoehe->setText(QCoreApplication::translate("UploadNewData", "Add File", nullptr));
        lblHoehe->setText(QCoreApplication::translate("UploadNewData", "Entwurfselement_Hoehe", nullptr));
        lblKMLine->setText(QCoreApplication::translate("UploadNewData", "Entwurfselement_KMLine", nullptr));
        btnUberhohung->setText(QCoreApplication::translate("UploadNewData", "Add File", nullptr));
        btnOK->setText(QCoreApplication::translate("UploadNewData", "Save Ok", nullptr));
        btnCancel->setText(QCoreApplication::translate("UploadNewData", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UploadNewData: public Ui_UploadNewData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPLOADNEWDATA_H
