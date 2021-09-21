/********************************************************************************
** Form generated from reading UI file 'nopreviewdelete.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
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
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout;
    QComboBox *comboAllFolder;
    QPushButton *btnLoad;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnDelete;
    QPushButton *btnCancel;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBoxHoehe;
    QCheckBox *checkBoxGleisknoten;
    QCheckBox *checkBoxKMLine;
    QCheckBox *checkBoxGleiskanten;
    QCheckBox *checkBoxLage;
    QCheckBox *checkBoxUeberhoehung;
    QSpacerItem *verticalSpacer;
    QCheckBox *checkBoxEntireStation;

    void setupUi(QDialog *NoPreviewDelete)
    {
        if (NoPreviewDelete->objectName().isEmpty())
            NoPreviewDelete->setObjectName(QString::fromUtf8("NoPreviewDelete"));
        NoPreviewDelete->resize(380, 364);
        gridLayout_2 = new QGridLayout(NoPreviewDelete);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(153, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 5, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        comboAllFolder = new QComboBox(NoPreviewDelete);
        comboAllFolder->setObjectName(QString::fromUtf8("comboAllFolder"));

        gridLayout->addWidget(comboAllFolder, 0, 0, 1, 1);

        btnLoad = new QPushButton(NoPreviewDelete);
        btnLoad->setObjectName(QString::fromUtf8("btnLoad"));

        gridLayout->addWidget(btnLoad, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 2);

        label = new QLabel(NoPreviewDelete);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(8);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnDelete = new QPushButton(NoPreviewDelete);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));
        btnDelete->setEnabled(false);

        horizontalLayout->addWidget(btnDelete);

        btnCancel = new QPushButton(NoPreviewDelete);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);


        gridLayout_2->addLayout(horizontalLayout, 5, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        checkBoxHoehe = new QCheckBox(NoPreviewDelete);
        checkBoxHoehe->setObjectName(QString::fromUtf8("checkBoxHoehe"));
        checkBoxHoehe->setEnabled(false);

        verticalLayout->addWidget(checkBoxHoehe);

        checkBoxGleisknoten = new QCheckBox(NoPreviewDelete);
        checkBoxGleisknoten->setObjectName(QString::fromUtf8("checkBoxGleisknoten"));
        checkBoxGleisknoten->setEnabled(false);

        verticalLayout->addWidget(checkBoxGleisknoten);

        checkBoxKMLine = new QCheckBox(NoPreviewDelete);
        checkBoxKMLine->setObjectName(QString::fromUtf8("checkBoxKMLine"));
        checkBoxKMLine->setEnabled(false);

        verticalLayout->addWidget(checkBoxKMLine);

        checkBoxGleiskanten = new QCheckBox(NoPreviewDelete);
        checkBoxGleiskanten->setObjectName(QString::fromUtf8("checkBoxGleiskanten"));
        checkBoxGleiskanten->setEnabled(false);

        verticalLayout->addWidget(checkBoxGleiskanten);

        checkBoxLage = new QCheckBox(NoPreviewDelete);
        checkBoxLage->setObjectName(QString::fromUtf8("checkBoxLage"));
        checkBoxLage->setEnabled(false);

        verticalLayout->addWidget(checkBoxLage);

        checkBoxUeberhoehung = new QCheckBox(NoPreviewDelete);
        checkBoxUeberhoehung->setObjectName(QString::fromUtf8("checkBoxUeberhoehung"));
        checkBoxUeberhoehung->setEnabled(false);

        verticalLayout->addWidget(checkBoxUeberhoehung);


        gridLayout_2->addLayout(verticalLayout, 2, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 4, 0, 1, 1);

        checkBoxEntireStation = new QCheckBox(NoPreviewDelete);
        checkBoxEntireStation->setObjectName(QString::fromUtf8("checkBoxEntireStation"));
        checkBoxEntireStation->setEnabled(false);

        gridLayout_2->addWidget(checkBoxEntireStation, 3, 1, 1, 1);


        retranslateUi(NoPreviewDelete);

        QMetaObject::connectSlotsByName(NoPreviewDelete);
    } // setupUi

    void retranslateUi(QDialog *NoPreviewDelete)
    {
        NoPreviewDelete->setWindowTitle(QCoreApplication::translate("NoPreviewDelete", "Dialog", nullptr));
        btnLoad->setText(QCoreApplication::translate("NoPreviewDelete", "Load", nullptr));
        label->setText(QCoreApplication::translate("NoPreviewDelete", "Delete Existing File", nullptr));
        btnDelete->setText(QCoreApplication::translate("NoPreviewDelete", "Delete", nullptr));
        btnCancel->setText(QCoreApplication::translate("NoPreviewDelete", "Cancel", nullptr));
        checkBoxHoehe->setText(QCoreApplication::translate("NoPreviewDelete", "Entwurfselement_Hoehe", nullptr));
        checkBoxGleisknoten->setText(QCoreApplication::translate("NoPreviewDelete", "Gleisknoten", nullptr));
        checkBoxKMLine->setText(QCoreApplication::translate("NoPreviewDelete", "Entwurfselement_KMLinie", nullptr));
        checkBoxGleiskanten->setText(QCoreApplication::translate("NoPreviewDelete", "Gleiskanten", nullptr));
        checkBoxLage->setText(QCoreApplication::translate("NoPreviewDelete", "Entwurfselement_Lage", nullptr));
        checkBoxUeberhoehung->setText(QCoreApplication::translate("NoPreviewDelete", "Entwurfselement_Ueberhoehung", nullptr));
        checkBoxEntireStation->setText(QCoreApplication::translate("NoPreviewDelete", "Entire Station Data", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NoPreviewDelete: public Ui_NoPreviewDelete {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOPREVIEWDELETE_H
