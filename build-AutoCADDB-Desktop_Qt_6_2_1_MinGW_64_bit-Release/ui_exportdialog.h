/********************************************************************************
** Form generated from reading UI file 'exportdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORTDIALOG_H
#define UI_EXPORTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ExportDialog
{
public:
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QGridLayout *gridLayout;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QLabel *lblStation;
    QComboBox *cmbStation;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblFolder;
    QLineEdit *leFolder;
    QPushButton *btnOpenFolder;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *checkBoxRemPath;
    QSpacerItem *verticalSpacer;
    QProgressBar *progressBar;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCancel;
    QPushButton *btnExport;

    void setupUi(QDialog *ExportDialog)
    {
        if (ExportDialog->objectName().isEmpty())
            ExportDialog->setObjectName(QString::fromUtf8("ExportDialog"));
        ExportDialog->resize(416, 187);
        gridLayout_2 = new QGridLayout(ExportDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        frame = new QFrame(ExportDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setSpacing(12);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lblStation = new QLabel(frame_2);
        lblStation->setObjectName(QString::fromUtf8("lblStation"));
        lblStation->setMaximumSize(QSize(72, 16777215));

        horizontalLayout->addWidget(lblStation);

        cmbStation = new QComboBox(frame_2);
        cmbStation->setObjectName(QString::fromUtf8("cmbStation"));

        horizontalLayout->addWidget(cmbStation);


        gridLayout->addWidget(frame_2, 0, 0, 1, 1);

        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setMaximumSize(QSize(16777215, 25));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_3);
        horizontalLayout_2->setSpacing(13);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        lblFolder = new QLabel(frame_3);
        lblFolder->setObjectName(QString::fromUtf8("lblFolder"));
        lblFolder->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(lblFolder);

        leFolder = new QLineEdit(frame_3);
        leFolder->setObjectName(QString::fromUtf8("leFolder"));
        leFolder->setEnabled(false);

        horizontalLayout_2->addWidget(leFolder);

        btnOpenFolder = new QPushButton(frame_3);
        btnOpenFolder->setObjectName(QString::fromUtf8("btnOpenFolder"));
        btnOpenFolder->setEnabled(false);
        btnOpenFolder->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_2->addWidget(btnOpenFolder);


        gridLayout->addWidget(frame_3, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(58, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        checkBoxRemPath = new QCheckBox(frame);
        checkBoxRemPath->setObjectName(QString::fromUtf8("checkBoxRemPath"));

        horizontalLayout_4->addWidget(checkBoxRemPath);


        gridLayout->addLayout(horizontalLayout_4, 2, 0, 1, 1);


        gridLayout_2->addWidget(frame, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 0, 1, 1);

        progressBar = new QProgressBar(ExportDialog);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        gridLayout_2->addWidget(progressBar, 2, 0, 1, 1);

        frame_4 = new QFrame(ExportDialog);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, 11, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        btnCancel = new QPushButton(frame_4);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout_3->addWidget(btnCancel);

        btnExport = new QPushButton(frame_4);
        btnExport->setObjectName(QString::fromUtf8("btnExport"));
        btnExport->setEnabled(false);

        horizontalLayout_3->addWidget(btnExport);


        gridLayout_2->addWidget(frame_4, 3, 0, 1, 1);


        retranslateUi(ExportDialog);

        QMetaObject::connectSlotsByName(ExportDialog);
    } // setupUi

    void retranslateUi(QDialog *ExportDialog)
    {
        ExportDialog->setWindowTitle(QCoreApplication::translate("ExportDialog", "Dialog", nullptr));
        lblStation->setText(QCoreApplication::translate("ExportDialog", "Select Station", nullptr));
        lblFolder->setText(QCoreApplication::translate("ExportDialog", "Output Folder", nullptr));
        btnOpenFolder->setText(QCoreApplication::translate("ExportDialog", "Open", nullptr));
        checkBoxRemPath->setText(QCoreApplication::translate("ExportDialog", "Remember my path next time", nullptr));
        btnCancel->setText(QCoreApplication::translate("ExportDialog", "Cancel", nullptr));
        btnExport->setText(QCoreApplication::translate("ExportDialog", "Export", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExportDialog: public Ui_ExportDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTDIALOG_H
