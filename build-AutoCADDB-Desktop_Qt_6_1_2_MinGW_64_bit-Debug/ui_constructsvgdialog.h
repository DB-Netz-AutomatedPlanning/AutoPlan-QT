/********************************************************************************
** Form generated from reading UI file 'constructsvgdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSTRUCTSVGDIALOG_H
#define UI_CONSTRUCTSVGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConstructSvgDialog
{
public:
    QAction *actionOpen;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout;
    QFrame *frame_7;
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QCheckBox *checkBox;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QCheckBox *checkBox_2;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QCheckBox *checkBox_3;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QCheckBox *checkBox_4;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *saveSvgBtn;
    QPushButton *pushButton;

    void setupUi(QMainWindow *ConstructSvgDialog)
    {
        if (ConstructSvgDialog->objectName().isEmpty())
            ConstructSvgDialog->setObjectName(QString::fromUtf8("ConstructSvgDialog"));
        ConstructSvgDialog->resize(271, 600);
        actionOpen = new QAction(ConstructSvgDialog);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        centralwidget = new QWidget(ConstructSvgDialog);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        ConstructSvgDialog->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ConstructSvgDialog);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 271, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        ConstructSvgDialog->setMenuBar(menubar);
        statusbar = new QStatusBar(ConstructSvgDialog);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ConstructSvgDialog->setStatusBar(statusbar);
        dockWidget = new QDockWidget(ConstructSvgDialog);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        gridLayout = new QGridLayout(dockWidgetContents);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame_7 = new QFrame(dockWidgetContents);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_7);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        frame = new QFrame(frame_7);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(0, 165));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(11, 0, 11, 0);
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        checkBox = new QCheckBox(frame_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout->addWidget(checkBox);


        verticalLayout_3->addWidget(frame_2);

        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, 0);
        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        checkBox_2 = new QCheckBox(frame_3);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        horizontalLayout_2->addWidget(checkBox_2);


        verticalLayout_3->addWidget(frame_3);

        frame_4 = new QFrame(frame);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, 0);
        label_3 = new QLabel(frame_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        checkBox_3 = new QCheckBox(frame_4);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        horizontalLayout_3->addWidget(checkBox_3);


        verticalLayout_3->addWidget(frame_4);

        frame_6 = new QFrame(frame);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(11, 0, 11, 0);
        label_4 = new QLabel(frame_6);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        checkBox_4 = new QCheckBox(frame_6);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        horizontalLayout_5->addWidget(checkBox_4);


        verticalLayout_3->addWidget(frame_6);

        frame_5 = new QFrame(frame);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_5);
        horizontalLayout_4->setSpacing(7);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(11, 0, 11, 0);
        saveSvgBtn = new QPushButton(frame_5);
        saveSvgBtn->setObjectName(QString::fromUtf8("saveSvgBtn"));

        horizontalLayout_4->addWidget(saveSvgBtn);

        pushButton = new QPushButton(frame_5);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_4->addWidget(pushButton);


        verticalLayout_3->addWidget(frame_5);


        gridLayout_2->addWidget(frame, 0, 0, 1, 1);


        gridLayout->addWidget(frame_7, 0, 0, 1, 1);

        dockWidget->setWidget(dockWidgetContents);
        ConstructSvgDialog->addDockWidget(Qt::BottomDockWidgetArea, dockWidget);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);

        retranslateUi(ConstructSvgDialog);

        QMetaObject::connectSlotsByName(ConstructSvgDialog);
    } // setupUi

    void retranslateUi(QMainWindow *ConstructSvgDialog)
    {
        ConstructSvgDialog->setWindowTitle(QCoreApplication::translate("ConstructSvgDialog", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("ConstructSvgDialog", "Open", nullptr));
        menuFile->setTitle(QCoreApplication::translate("ConstructSvgDialog", "File", nullptr));
        label->setText(QCoreApplication::translate("ConstructSvgDialog", "Filled", nullptr));
        checkBox->setText(QString());
        label_2->setText(QCoreApplication::translate("ConstructSvgDialog", "Mehrabschnittssignalschirm", nullptr));
        checkBox_2->setText(QString());
        label_3->setText(QCoreApplication::translate("ConstructSvgDialog", "Hauptsignal", nullptr));
        checkBox_3->setText(QString());
        label_4->setText(QCoreApplication::translate("ConstructSvgDialog", "Arrow", nullptr));
        checkBox_4->setText(QString());
        saveSvgBtn->setText(QCoreApplication::translate("ConstructSvgDialog", "Add", nullptr));
        pushButton->setText(QCoreApplication::translate("ConstructSvgDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConstructSvgDialog: public Ui_ConstructSvgDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSTRUCTSVGDIALOG_H
