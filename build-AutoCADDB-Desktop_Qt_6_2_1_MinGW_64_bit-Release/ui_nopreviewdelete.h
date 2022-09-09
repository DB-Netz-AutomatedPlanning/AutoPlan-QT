/********************************************************************************
** Form generated from reading UI file 'nopreviewdelete.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOPREVIEWDELETE_H
#define UI_NOPREVIEWDELETE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NoPreviewDelete
{
public:
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_6;
    QPushButton *btnLoad_6;
    QSpacerItem *horizontalSpacer_6;
    QComboBox *comboAllFolder_6;
    QVBoxLayout *verticalLayout_6;
    QCheckBox *checkBoxHoehe_6;
    QCheckBox *checkBoxGleisknoten_6;
    QCheckBox *checkBoxKMLine_6;
    QCheckBox *checkBoxGleiskanten_6;
    QCheckBox *checkBoxLage_6;
    QCheckBox *checkBoxUeberhoehung_6;
    QCheckBox *checkBoxEntireStation;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *btnDelete_6;
    QPushButton *btnCancel_6;
    QSpacerItem *verticalSpacer;
    QLabel *label;

    void setupUi(QDialog *NoPreviewDelete)
    {
        if (NoPreviewDelete->objectName().isEmpty())
            NoPreviewDelete->setObjectName(QString::fromUtf8("NoPreviewDelete"));
        NoPreviewDelete->resize(344, 365);
        gridLayout_7 = new QGridLayout(NoPreviewDelete);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        btnLoad_6 = new QPushButton(NoPreviewDelete);
        btnLoad_6->setObjectName(QString::fromUtf8("btnLoad_6"));

        gridLayout_6->addWidget(btnLoad_6, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_6, 2, 0, 1, 1);

        comboAllFolder_6 = new QComboBox(NoPreviewDelete);
        comboAllFolder_6->setObjectName(QString::fromUtf8("comboAllFolder_6"));

        gridLayout_6->addWidget(comboAllFolder_6, 0, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 1, 0, 1, 3);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        checkBoxHoehe_6 = new QCheckBox(NoPreviewDelete);
        checkBoxHoehe_6->setObjectName(QString::fromUtf8("checkBoxHoehe_6"));
        checkBoxHoehe_6->setEnabled(false);

        verticalLayout_6->addWidget(checkBoxHoehe_6);

        checkBoxGleisknoten_6 = new QCheckBox(NoPreviewDelete);
        checkBoxGleisknoten_6->setObjectName(QString::fromUtf8("checkBoxGleisknoten_6"));
        checkBoxGleisknoten_6->setEnabled(false);

        verticalLayout_6->addWidget(checkBoxGleisknoten_6);

        checkBoxKMLine_6 = new QCheckBox(NoPreviewDelete);
        checkBoxKMLine_6->setObjectName(QString::fromUtf8("checkBoxKMLine_6"));
        checkBoxKMLine_6->setEnabled(false);

        verticalLayout_6->addWidget(checkBoxKMLine_6);

        checkBoxGleiskanten_6 = new QCheckBox(NoPreviewDelete);
        checkBoxGleiskanten_6->setObjectName(QString::fromUtf8("checkBoxGleiskanten_6"));
        checkBoxGleiskanten_6->setEnabled(false);

        verticalLayout_6->addWidget(checkBoxGleiskanten_6);

        checkBoxLage_6 = new QCheckBox(NoPreviewDelete);
        checkBoxLage_6->setObjectName(QString::fromUtf8("checkBoxLage_6"));
        checkBoxLage_6->setEnabled(false);

        verticalLayout_6->addWidget(checkBoxLage_6);

        checkBoxUeberhoehung_6 = new QCheckBox(NoPreviewDelete);
        checkBoxUeberhoehung_6->setObjectName(QString::fromUtf8("checkBoxUeberhoehung_6"));
        checkBoxUeberhoehung_6->setEnabled(false);

        verticalLayout_6->addWidget(checkBoxUeberhoehung_6);


        gridLayout_7->addLayout(verticalLayout_6, 2, 0, 1, 3);

        checkBoxEntireStation = new QCheckBox(NoPreviewDelete);
        checkBoxEntireStation->setObjectName(QString::fromUtf8("checkBoxEntireStation"));
        checkBoxEntireStation->setEnabled(false);

        gridLayout_7->addWidget(checkBoxEntireStation, 3, 2, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(143, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_7, 5, 0, 1, 2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        btnDelete_6 = new QPushButton(NoPreviewDelete);
        btnDelete_6->setObjectName(QString::fromUtf8("btnDelete_6"));
        btnDelete_6->setEnabled(false);

        horizontalLayout_6->addWidget(btnDelete_6);

        btnCancel_6 = new QPushButton(NoPreviewDelete);
        btnCancel_6->setObjectName(QString::fromUtf8("btnCancel_6"));

        horizontalLayout_6->addWidget(btnCancel_6);


        gridLayout_7->addLayout(horizontalLayout_6, 5, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer, 3, 0, 1, 1);

        label = new QLabel(NoPreviewDelete);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(8);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label, 0, 1, 1, 1);


        retranslateUi(NoPreviewDelete);

        QMetaObject::connectSlotsByName(NoPreviewDelete);
    } // setupUi

    void retranslateUi(QDialog *NoPreviewDelete)
    {
        NoPreviewDelete->setWindowTitle(QCoreApplication::translate("NoPreviewDelete", "Dialog", nullptr));
        btnLoad_6->setText(QCoreApplication::translate("NoPreviewDelete", "Load", nullptr));
        checkBoxHoehe_6->setText(QCoreApplication::translate("NoPreviewDelete", "Entwurfselement_Hoehe", nullptr));
        checkBoxGleisknoten_6->setText(QCoreApplication::translate("NoPreviewDelete", "Gleisknoten", nullptr));
        checkBoxKMLine_6->setText(QCoreApplication::translate("NoPreviewDelete", "Entwurfselement_KMLinie", nullptr));
        checkBoxGleiskanten_6->setText(QCoreApplication::translate("NoPreviewDelete", "Gleiskanten", nullptr));
        checkBoxLage_6->setText(QCoreApplication::translate("NoPreviewDelete", "Entwurfselement_Lage", nullptr));
        checkBoxUeberhoehung_6->setText(QCoreApplication::translate("NoPreviewDelete", "Entwurfselement_Ueberhoehung", nullptr));
        checkBoxEntireStation->setText(QCoreApplication::translate("NoPreviewDelete", "Entire Station Data", nullptr));
        btnDelete_6->setText(QCoreApplication::translate("NoPreviewDelete", "Delete", nullptr));
        btnCancel_6->setText(QCoreApplication::translate("NoPreviewDelete", "Cancel", nullptr));
        label->setText(QCoreApplication::translate("NoPreviewDelete", "Delete Existing File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NoPreviewDelete: public Ui_NoPreviewDelete {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOPREVIEWDELETE_H
