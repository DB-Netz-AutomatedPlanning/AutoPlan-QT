/********************************************************************************
** Form generated from reading UI file 'newprojectdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPROJECTDIALOG_H
#define UI_NEWPROJECTDIALOG_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NewProjectDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QFrame *frame;
    QGridLayout *gridLayout;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QLabel *lblProjectName;
    QLineEdit *leEnterProjectName;
    QFrame *frame_8;
    QVBoxLayout *verticalLayout;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblProjectPath;
    QLineEdit *leEnterProjectPath;
    QPushButton *btnBrowseProjectPath;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QComboBox *countryCodeComboBox;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QComboBox *fileFormatComboBox;
    QFrame *frame_9;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lblProjectData;
    QLineEdit *leImportProjectData;
    QPushButton *btnBrowseProjectData;
    QSpacerItem *verticalSpacer;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCancel;
    QPushButton *btnCreateNewProject;

    void setupUi(QDialog *NewProjectDialog)
    {
        if (NewProjectDialog->objectName().isEmpty())
            NewProjectDialog->setObjectName(QString::fromUtf8("NewProjectDialog"));
        NewProjectDialog->resize(470, 276);
        verticalLayout_3 = new QVBoxLayout(NewProjectDialog);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        frame = new QFrame(NewProjectDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
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
        lblProjectName = new QLabel(frame_2);
        lblProjectName->setObjectName(QString::fromUtf8("lblProjectName"));
        lblProjectName->setMinimumSize(QSize(100, 0));
        lblProjectName->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(lblProjectName);

        leEnterProjectName = new QLineEdit(frame_2);
        leEnterProjectName->setObjectName(QString::fromUtf8("leEnterProjectName"));

        horizontalLayout->addWidget(leEnterProjectName);


        gridLayout->addWidget(frame_2, 0, 0, 1, 1);

        frame_8 = new QFrame(frame);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_8);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame_3 = new QFrame(frame_8);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setMinimumSize(QSize(0, 30));
        frame_3->setMaximumSize(QSize(16777215, 30));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_3);
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        lblProjectPath = new QLabel(frame_3);
        lblProjectPath->setObjectName(QString::fromUtf8("lblProjectPath"));
        lblProjectPath->setMinimumSize(QSize(100, 0));
        lblProjectPath->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_2->addWidget(lblProjectPath);

        leEnterProjectPath = new QLineEdit(frame_3);
        leEnterProjectPath->setObjectName(QString::fromUtf8("leEnterProjectPath"));

        horizontalLayout_2->addWidget(leEnterProjectPath);

        btnBrowseProjectPath = new QPushButton(frame_3);
        btnBrowseProjectPath->setObjectName(QString::fromUtf8("btnBrowseProjectPath"));

        horizontalLayout_2->addWidget(btnBrowseProjectPath);


        verticalLayout->addWidget(frame_3);


        gridLayout->addWidget(frame_8, 1, 0, 1, 1);

        frame_6 = new QFrame(frame);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_6);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(frame_6);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(106, 16777215));

        horizontalLayout_5->addWidget(label_3);

        countryCodeComboBox = new QComboBox(frame_6);
        countryCodeComboBox->addItem(QString());
        countryCodeComboBox->addItem(QString());
        countryCodeComboBox->setObjectName(QString::fromUtf8("countryCodeComboBox"));

        horizontalLayout_5->addWidget(countryCodeComboBox);


        gridLayout->addWidget(frame_6, 2, 0, 1, 1);

        frame_7 = new QFrame(frame);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_7);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(frame_7);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(106, 16777215));

        horizontalLayout_6->addWidget(label_4);

        fileFormatComboBox = new QComboBox(frame_7);
        fileFormatComboBox->addItem(QString());
        fileFormatComboBox->addItem(QString());
        fileFormatComboBox->addItem(QString());
        fileFormatComboBox->addItem(QString());
        fileFormatComboBox->setObjectName(QString::fromUtf8("fileFormatComboBox"));

        horizontalLayout_6->addWidget(fileFormatComboBox);


        gridLayout->addWidget(frame_7, 3, 0, 1, 1);

        frame_9 = new QFrame(frame);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_9);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame_4 = new QFrame(frame_9);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setMinimumSize(QSize(0, 30));
        frame_4->setMaximumSize(QSize(16777215, 30));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_4);
        horizontalLayout_3->setSpacing(5);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        lblProjectData = new QLabel(frame_4);
        lblProjectData->setObjectName(QString::fromUtf8("lblProjectData"));
        lblProjectData->setMinimumSize(QSize(100, 0));
        lblProjectData->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_3->addWidget(lblProjectData);

        leImportProjectData = new QLineEdit(frame_4);
        leImportProjectData->setObjectName(QString::fromUtf8("leImportProjectData"));

        horizontalLayout_3->addWidget(leImportProjectData);

        btnBrowseProjectData = new QPushButton(frame_4);
        btnBrowseProjectData->setObjectName(QString::fromUtf8("btnBrowseProjectData"));
        btnBrowseProjectData->setEnabled(false);

        horizontalLayout_3->addWidget(btnBrowseProjectData);


        verticalLayout_2->addWidget(frame_4);


        gridLayout->addWidget(frame_9, 4, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 43, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 0, 1, 1);

        frame_5 = new QFrame(frame);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setMinimumSize(QSize(0, 30));
        frame_5->setMaximumSize(QSize(16777215, 30));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_5);
        horizontalLayout_4->setSpacing(5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        btnCancel = new QPushButton(frame_5);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout_4->addWidget(btnCancel);

        btnCreateNewProject = new QPushButton(frame_5);
        btnCreateNewProject->setObjectName(QString::fromUtf8("btnCreateNewProject"));
        btnCreateNewProject->setEnabled(false);

        horizontalLayout_4->addWidget(btnCreateNewProject);


        gridLayout->addWidget(frame_5, 6, 0, 1, 1);


        verticalLayout_3->addWidget(frame);


        retranslateUi(NewProjectDialog);

        QMetaObject::connectSlotsByName(NewProjectDialog);
    } // setupUi

    void retranslateUi(QDialog *NewProjectDialog)
    {
        NewProjectDialog->setWindowTitle(QCoreApplication::translate("NewProjectDialog", "Dialog", nullptr));
        lblProjectName->setText(QCoreApplication::translate("NewProjectDialog", "New Project Name", nullptr));
        lblProjectPath->setText(QCoreApplication::translate("NewProjectDialog", "Create in", nullptr));
        btnBrowseProjectPath->setText(QCoreApplication::translate("NewProjectDialog", "Add Path", nullptr));
        label_3->setText(QCoreApplication::translate("NewProjectDialog", "Country Code", nullptr));
        countryCodeComboBox->setItemText(0, QCoreApplication::translate("NewProjectDialog", "de", nullptr));
        countryCodeComboBox->setItemText(1, QCoreApplication::translate("NewProjectDialog", "fr", nullptr));

        label_4->setText(QCoreApplication::translate("NewProjectDialog", "File Format", nullptr));
        fileFormatComboBox->setItemText(0, QCoreApplication::translate("NewProjectDialog", ".json", nullptr));
        fileFormatComboBox->setItemText(1, QCoreApplication::translate("NewProjectDialog", ".ppxml", nullptr));
        fileFormatComboBox->setItemText(2, QCoreApplication::translate("NewProjectDialog", ".mdb", nullptr));
        fileFormatComboBox->setItemText(3, QCoreApplication::translate("NewProjectDialog", ".euxml", nullptr));

        lblProjectData->setText(QCoreApplication::translate("NewProjectDialog", "Add Project Data", nullptr));
        btnBrowseProjectData->setText(QCoreApplication::translate("NewProjectDialog", "Browse", nullptr));
        btnCancel->setText(QCoreApplication::translate("NewProjectDialog", "Cancel", nullptr));
        btnCreateNewProject->setText(QCoreApplication::translate("NewProjectDialog", "Create", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewProjectDialog: public Ui_NewProjectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPROJECTDIALOG_H
