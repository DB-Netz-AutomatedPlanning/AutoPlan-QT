/********************************************************************************
** Form generated from reading UI file 'previeweulynxxml.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREVIEWEULYNXXML_H
#define UI_PREVIEWEULYNXXML_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PreviewEulynxXml
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLabel *lblStation;
    QLabel *lblStationName;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnValidateXML;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QTextEdit *tePreview;
    QPushButton *btnOk;
    QLabel *lblSuccessMsg;

    void setupUi(QDialog *PreviewEulynxXml)
    {
        if (PreviewEulynxXml->objectName().isEmpty())
            PreviewEulynxXml->setObjectName(QString::fromUtf8("PreviewEulynxXml"));
        PreviewEulynxXml->resize(728, 626);
        gridLayout = new QGridLayout(PreviewEulynxXml);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(PreviewEulynxXml);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lblStation = new QLabel(frame);
        lblStation->setObjectName(QString::fromUtf8("lblStation"));

        gridLayout_2->addWidget(lblStation, 0, 0, 1, 1);

        lblStationName = new QLabel(frame);
        lblStationName->setObjectName(QString::fromUtf8("lblStationName"));

        gridLayout_2->addWidget(lblStationName, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 2, 1, 1);


        gridLayout->addWidget(frame, 1, 0, 1, 1);

        btnValidateXML = new QPushButton(PreviewEulynxXml);
        btnValidateXML->setObjectName(QString::fromUtf8("btnValidateXML"));

        gridLayout->addWidget(btnValidateXML, 3, 2, 1, 1);

        widget = new QWidget(PreviewEulynxXml);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 0));
        widget->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tePreview = new QTextEdit(widget);
        tePreview->setObjectName(QString::fromUtf8("tePreview"));
        tePreview->setReadOnly(true);

        gridLayout_3->addWidget(tePreview, 0, 0, 1, 1);


        gridLayout->addWidget(widget, 2, 0, 1, 4);

        btnOk = new QPushButton(PreviewEulynxXml);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));
        btnOk->setMaximumSize(QSize(60, 16777215));

        gridLayout->addWidget(btnOk, 3, 1, 1, 1);

        lblSuccessMsg = new QLabel(PreviewEulynxXml);
        lblSuccessMsg->setObjectName(QString::fromUtf8("lblSuccessMsg"));

        gridLayout->addWidget(lblSuccessMsg, 0, 0, 1, 1);


        retranslateUi(PreviewEulynxXml);

        QMetaObject::connectSlotsByName(PreviewEulynxXml);
    } // setupUi

    void retranslateUi(QDialog *PreviewEulynxXml)
    {
        PreviewEulynxXml->setWindowTitle(QCoreApplication::translate("PreviewEulynxXml", "Dialog", nullptr));
        lblStation->setText(QCoreApplication::translate("PreviewEulynxXml", "Station :", nullptr));
        lblStationName->setText(QString());
        btnValidateXML->setText(QCoreApplication::translate("PreviewEulynxXml", "Validate XML", nullptr));
        btnOk->setText(QCoreApplication::translate("PreviewEulynxXml", "OK", nullptr));
        lblSuccessMsg->setText(QCoreApplication::translate("PreviewEulynxXml", "Eulynx XML successfully generated.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PreviewEulynxXml: public Ui_PreviewEulynxXml {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREVIEWEULYNXXML_H
