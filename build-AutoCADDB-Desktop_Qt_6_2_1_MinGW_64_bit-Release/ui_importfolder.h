/********************************************************************************
** Form generated from reading UI file 'importfolder.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPORTFOLDER_H
#define UI_IMPORTFOLDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ImportFolder
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QRadioButton *rdAdd;
    QRadioButton *rdModify;
    QSpacerItem *horizontalSpacer_3;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *cmbExistingStn;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *leFolder;
    QPushButton *btnEnable;
    QSpacerItem *verticalSpacer;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnCancel;
    QPushButton *btnImport;

    void setupUi(QDialog *ImportFolder)
    {
        if (ImportFolder->objectName().isEmpty())
            ImportFolder->setObjectName(QString::fromUtf8("ImportFolder"));
        ImportFolder->resize(479, 202);
        gridLayout = new QGridLayout(ImportFolder);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(ImportFolder);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMinimumSize(QSize(0, 30));
        frame_2->setMaximumSize(QSize(16777215, 30));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        rdAdd = new QRadioButton(frame_2);
        rdAdd->setObjectName(QString::fromUtf8("rdAdd"));

        horizontalLayout->addWidget(rdAdd);

        rdModify = new QRadioButton(frame_2);
        rdModify->setObjectName(QString::fromUtf8("rdModify"));
        rdModify->setEnabled(false);

        horizontalLayout->addWidget(rdModify);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(frame_2);

        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setMinimumSize(QSize(0, 30));
        frame_3->setMaximumSize(QSize(16777215, 30));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_3);
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(frame_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(120, 0));
        label->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_2->addWidget(label);

        cmbExistingStn = new QComboBox(frame_3);
        cmbExistingStn->setObjectName(QString::fromUtf8("cmbExistingStn"));

        horizontalLayout_2->addWidget(cmbExistingStn);


        verticalLayout->addWidget(frame_3);

        frame_6 = new QFrame(frame);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setMinimumSize(QSize(0, 30));
        frame_6->setMaximumSize(QSize(16777215, 30));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_6);
        horizontalLayout_4->setSpacing(5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(frame_6);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(120, 0));
        label_3->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_4->addWidget(label_3);

        leFolder = new QLineEdit(frame_6);
        leFolder->setObjectName(QString::fromUtf8("leFolder"));
        leFolder->setEnabled(false);

        horizontalLayout_4->addWidget(leFolder);

        btnEnable = new QPushButton(frame_6);
        btnEnable->setObjectName(QString::fromUtf8("btnEnable"));
        btnEnable->setEnabled(false);

        horizontalLayout_4->addWidget(btnEnable);


        verticalLayout->addWidget(frame_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        frame_7 = new QFrame(frame);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setMinimumSize(QSize(0, 30));
        frame_7->setMaximumSize(QSize(16777215, 30));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_7);
        horizontalLayout_6->setSpacing(5);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        btnCancel = new QPushButton(frame_7);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout_6->addWidget(btnCancel);

        btnImport = new QPushButton(frame_7);
        btnImport->setObjectName(QString::fromUtf8("btnImport"));
        btnImport->setEnabled(false);

        horizontalLayout_6->addWidget(btnImport);


        verticalLayout->addWidget(frame_7);


        gridLayout->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(ImportFolder);

        QMetaObject::connectSlotsByName(ImportFolder);
    } // setupUi

    void retranslateUi(QDialog *ImportFolder)
    {
        ImportFolder->setWindowTitle(QCoreApplication::translate("ImportFolder", "Dialog", nullptr));
        rdAdd->setText(QCoreApplication::translate("ImportFolder", "Add New Data", nullptr));
        rdModify->setText(QCoreApplication::translate("ImportFolder", "Modify Existing Data", nullptr));
        label->setText(QCoreApplication::translate("ImportFolder", "Select Existing Project", nullptr));
        label_3->setText(QCoreApplication::translate("ImportFolder", "Folder Path", nullptr));
        btnEnable->setText(QCoreApplication::translate("ImportFolder", "Browse", nullptr));
        btnCancel->setText(QCoreApplication::translate("ImportFolder", "Cancel", nullptr));
        btnImport->setText(QCoreApplication::translate("ImportFolder", "Import", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImportFolder: public Ui_ImportFolder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPORTFOLDER_H
