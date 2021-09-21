/********************************************************************************
** Form generated from reading UI file 'removedata.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOVEDATA_H
#define UI_REMOVEDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_RemoveData
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QPushButton *btnDelete;
    QPushButton *btnCancel;
    QGridLayout *gridLayout;
    QComboBox *comboAllFolder;
    QComboBox *comboFiles;
    QPushButton *btnLoad;
    QPushButton *btnPreview;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QTextBrowser *textBrowserPreview;

    void setupUi(QDialog *RemoveData)
    {
        if (RemoveData->objectName().isEmpty())
            RemoveData->setObjectName(QString::fromUtf8("RemoveData"));
        RemoveData->resize(570, 478);
        gridLayout_3 = new QGridLayout(RemoveData);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        btnDelete = new QPushButton(RemoveData);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));
        btnDelete->setEnabled(false);

        gridLayout_2->addWidget(btnDelete, 0, 0, 1, 1);

        btnCancel = new QPushButton(RemoveData);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        gridLayout_2->addWidget(btnCancel, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 4, 2, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        comboAllFolder = new QComboBox(RemoveData);
        comboAllFolder->setObjectName(QString::fromUtf8("comboAllFolder"));

        gridLayout->addWidget(comboAllFolder, 0, 0, 1, 1);

        comboFiles = new QComboBox(RemoveData);
        comboFiles->setObjectName(QString::fromUtf8("comboFiles"));
        comboFiles->setEnabled(false);

        gridLayout->addWidget(comboFiles, 2, 0, 1, 2);

        btnLoad = new QPushButton(RemoveData);
        btnLoad->setObjectName(QString::fromUtf8("btnLoad"));

        gridLayout->addWidget(btnLoad, 0, 1, 1, 1);

        btnPreview = new QPushButton(RemoveData);
        btnPreview->setObjectName(QString::fromUtf8("btnPreview"));
        btnPreview->setEnabled(false);

        gridLayout->addWidget(btnPreview, 3, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 1, 1, 2);

        label = new QLabel(RemoveData);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 4, 0, 1, 2);

        textBrowserPreview = new QTextBrowser(RemoveData);
        textBrowserPreview->setObjectName(QString::fromUtf8("textBrowserPreview"));
        textBrowserPreview->setEnabled(false);

        gridLayout_3->addWidget(textBrowserPreview, 3, 0, 1, 3);


        retranslateUi(RemoveData);

        QMetaObject::connectSlotsByName(RemoveData);
    } // setupUi

    void retranslateUi(QDialog *RemoveData)
    {
        RemoveData->setWindowTitle(QCoreApplication::translate("RemoveData", "Dialog", nullptr));
        btnDelete->setText(QCoreApplication::translate("RemoveData", "Delete", nullptr));
        btnCancel->setText(QCoreApplication::translate("RemoveData", "Cancel", nullptr));
        btnLoad->setText(QCoreApplication::translate("RemoveData", "Load", nullptr));
        btnPreview->setText(QCoreApplication::translate("RemoveData", "Preview", nullptr));
        label->setText(QCoreApplication::translate("RemoveData", "Preview and / Remove Existing Data", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RemoveData: public Ui_RemoveData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOVEDATA_H
