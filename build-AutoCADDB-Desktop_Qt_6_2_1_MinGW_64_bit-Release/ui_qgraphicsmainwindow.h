/********************************************************************************
** Form generated from reading UI file 'qgraphicsmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGRAPHICSMAINWINDOW_H
#define UI_QGRAPHICSMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QGraphicsMainWindow
{
public:
    QFormLayout *formLayout_3;
    QGridLayout *gridLayout_5;
    QLabel *label_2;
    QGridLayout *gridLayout;
    QCheckBox *checkBoxKMDP;
    QCheckBox *checkBoxHO;
    QCheckBox *checkBoxLADP;
    QCheckBox *checkBoxUH;
    QCheckBox *checkBoxKanten;
    QCheckBox *checkBoxKnoten;
    QCheckBox *checkBoxKantenDP;
    QLabel *label;
    QCheckBox *checkBoxKM;
    QCheckBox *checkBoxGridLine;
    QCheckBox *checkBoxKnotenDP;
    QCheckBox *checkBoxLA;
    QCheckBox *checkBoxUHDP;
    QCheckBox *checkBoxHODP;
    QCheckBox *checkBoxGridLine2;
    QSlider *horizontalSlider;
    QGridLayout *gridLayout_4;
    QFormLayout *formLayout;
    QGridLayout *gridLayout_3;
    QLabel *lblXCoord;
    QLabel *lblYCoord;
    QGridLayout *gridLayout_2;
    QLabel *valueXCoord;
    QLabel *valueYCoord;
    QSpacerItem *verticalSpacer;
    QFormLayout *formLayout_2;
    QLabel *label_3;
    QSpinBox *spinBox_RotateView;
    QFrame *line;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *QGraphicsMainWindow)
    {
        if (QGraphicsMainWindow->objectName().isEmpty())
            QGraphicsMainWindow->setObjectName(QString::fromUtf8("QGraphicsMainWindow"));
        QGraphicsMainWindow->resize(532, 536);
        formLayout_3 = new QFormLayout(QGraphicsMainWindow);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_2 = new QLabel(QGraphicsMainWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_5->addWidget(label_2, 2, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        checkBoxKMDP = new QCheckBox(QGraphicsMainWindow);
        checkBoxKMDP->setObjectName(QString::fromUtf8("checkBoxKMDP"));

        gridLayout->addWidget(checkBoxKMDP, 3, 0, 1, 1);

        checkBoxHO = new QCheckBox(QGraphicsMainWindow);
        checkBoxHO->setObjectName(QString::fromUtf8("checkBoxHO"));

        gridLayout->addWidget(checkBoxHO, 4, 1, 1, 1);

        checkBoxLADP = new QCheckBox(QGraphicsMainWindow);
        checkBoxLADP->setObjectName(QString::fromUtf8("checkBoxLADP"));

        gridLayout->addWidget(checkBoxLADP, 5, 0, 1, 1);

        checkBoxUH = new QCheckBox(QGraphicsMainWindow);
        checkBoxUH->setObjectName(QString::fromUtf8("checkBoxUH"));

        gridLayout->addWidget(checkBoxUH, 6, 1, 1, 1);

        checkBoxKanten = new QCheckBox(QGraphicsMainWindow);
        checkBoxKanten->setObjectName(QString::fromUtf8("checkBoxKanten"));

        gridLayout->addWidget(checkBoxKanten, 2, 1, 1, 1);

        checkBoxKnoten = new QCheckBox(QGraphicsMainWindow);
        checkBoxKnoten->setObjectName(QString::fromUtf8("checkBoxKnoten"));
        checkBoxKnoten->setEnabled(false);

        gridLayout->addWidget(checkBoxKnoten, 1, 1, 1, 1);

        checkBoxKantenDP = new QCheckBox(QGraphicsMainWindow);
        checkBoxKantenDP->setObjectName(QString::fromUtf8("checkBoxKantenDP"));

        gridLayout->addWidget(checkBoxKantenDP, 2, 0, 1, 1);

        label = new QLabel(QGraphicsMainWindow);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        checkBoxKM = new QCheckBox(QGraphicsMainWindow);
        checkBoxKM->setObjectName(QString::fromUtf8("checkBoxKM"));

        gridLayout->addWidget(checkBoxKM, 3, 1, 1, 1);

        checkBoxGridLine = new QCheckBox(QGraphicsMainWindow);
        checkBoxGridLine->setObjectName(QString::fromUtf8("checkBoxGridLine"));

        gridLayout->addWidget(checkBoxGridLine, 7, 1, 1, 1);

        checkBoxKnotenDP = new QCheckBox(QGraphicsMainWindow);
        checkBoxKnotenDP->setObjectName(QString::fromUtf8("checkBoxKnotenDP"));

        gridLayout->addWidget(checkBoxKnotenDP, 1, 0, 1, 1);

        checkBoxLA = new QCheckBox(QGraphicsMainWindow);
        checkBoxLA->setObjectName(QString::fromUtf8("checkBoxLA"));

        gridLayout->addWidget(checkBoxLA, 5, 1, 1, 1);

        checkBoxUHDP = new QCheckBox(QGraphicsMainWindow);
        checkBoxUHDP->setObjectName(QString::fromUtf8("checkBoxUHDP"));

        gridLayout->addWidget(checkBoxUHDP, 6, 0, 1, 1);

        checkBoxHODP = new QCheckBox(QGraphicsMainWindow);
        checkBoxHODP->setObjectName(QString::fromUtf8("checkBoxHODP"));

        gridLayout->addWidget(checkBoxHODP, 4, 0, 1, 1);

        checkBoxGridLine2 = new QCheckBox(QGraphicsMainWindow);
        checkBoxGridLine2->setObjectName(QString::fromUtf8("checkBoxGridLine2"));
        checkBoxGridLine2->setEnabled(false);

        gridLayout->addWidget(checkBoxGridLine2, 7, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalSlider = new QSlider(QGraphicsMainWindow);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMaximum(360);
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout_5->addWidget(horizontalSlider, 3, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        lblXCoord = new QLabel(QGraphicsMainWindow);
        lblXCoord->setObjectName(QString::fromUtf8("lblXCoord"));
        lblXCoord->setAutoFillBackground(false);
        lblXCoord->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblXCoord, 0, 0, 1, 1);

        lblYCoord = new QLabel(QGraphicsMainWindow);
        lblYCoord->setObjectName(QString::fromUtf8("lblYCoord"));
        lblYCoord->setAutoFillBackground(false);
        lblYCoord->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblYCoord, 1, 0, 1, 1);


        formLayout->setLayout(0, QFormLayout::LabelRole, gridLayout_3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        valueXCoord = new QLabel(QGraphicsMainWindow);
        valueXCoord->setObjectName(QString::fromUtf8("valueXCoord"));
        valueXCoord->setAutoFillBackground(false);
        valueXCoord->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(0, 0, 0);"));

        gridLayout_2->addWidget(valueXCoord, 0, 0, 1, 1);

        valueYCoord = new QLabel(QGraphicsMainWindow);
        valueYCoord->setObjectName(QString::fromUtf8("valueYCoord"));
        valueYCoord->setAutoFillBackground(false);
        valueYCoord->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(0, 0, 0);"));

        gridLayout_2->addWidget(valueYCoord, 1, 0, 1, 1);


        formLayout->setLayout(0, QFormLayout::FieldRole, gridLayout_2);


        gridLayout_4->addLayout(formLayout, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(88, 68, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 1, 0, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_3 = new QLabel(QGraphicsMainWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_3);

        spinBox_RotateView = new QSpinBox(QGraphicsMainWindow);
        spinBox_RotateView->setObjectName(QString::fromUtf8("spinBox_RotateView"));
        spinBox_RotateView->setMinimum(-1000);
        spinBox_RotateView->setMaximum(1000);
        spinBox_RotateView->setSingleStep(10);
        spinBox_RotateView->setValue(0);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, spinBox_RotateView);


        gridLayout_4->addLayout(formLayout_2, 0, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 4, 0, 1, 1);

        line = new QFrame(QGraphicsMainWindow);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShadow(QFrame::Raised);
        line->setFrameShape(QFrame::HLine);

        gridLayout_5->addWidget(line, 1, 0, 1, 1);


        formLayout_3->setLayout(0, QFormLayout::LabelRole, gridLayout_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        formLayout_3->setLayout(0, QFormLayout::FieldRole, verticalLayout);


        retranslateUi(QGraphicsMainWindow);

        QMetaObject::connectSlotsByName(QGraphicsMainWindow);
    } // setupUi

    void retranslateUi(QWidget *QGraphicsMainWindow)
    {
        QGraphicsMainWindow->setWindowTitle(QCoreApplication::translate("QGraphicsMainWindow", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("QGraphicsMainWindow", "Rotate Symbol", nullptr));
        checkBoxKMDP->setText(QString());
        checkBoxHO->setText(QCoreApplication::translate("QGraphicsMainWindow", "HO", nullptr));
        checkBoxLADP->setText(QString());
        checkBoxUH->setText(QCoreApplication::translate("QGraphicsMainWindow", "UH", nullptr));
        checkBoxKanten->setText(QCoreApplication::translate("QGraphicsMainWindow", "Kanten", nullptr));
        checkBoxKnoten->setText(QCoreApplication::translate("QGraphicsMainWindow", "Knoten", nullptr));
        checkBoxKantenDP->setText(QString());
        label->setText(QCoreApplication::translate("QGraphicsMainWindow", "Hide/Show", nullptr));
        checkBoxKM->setText(QCoreApplication::translate("QGraphicsMainWindow", "KM", nullptr));
        checkBoxGridLine->setText(QCoreApplication::translate("QGraphicsMainWindow", "Grid", nullptr));
        checkBoxKnotenDP->setText(QString());
        checkBoxLA->setText(QCoreApplication::translate("QGraphicsMainWindow", "LA", nullptr));
        checkBoxUHDP->setText(QString());
        checkBoxHODP->setText(QString());
        checkBoxGridLine2->setText(QString());
        lblXCoord->setText(QCoreApplication::translate("QGraphicsMainWindow", "X", nullptr));
        lblYCoord->setText(QCoreApplication::translate("QGraphicsMainWindow", "Y", nullptr));
        valueXCoord->setText(QString());
        valueYCoord->setText(QString());
        label_3->setText(QCoreApplication::translate("QGraphicsMainWindow", "Rotate View", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QGraphicsMainWindow: public Ui_QGraphicsMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGRAPHICSMAINWINDOW_H
