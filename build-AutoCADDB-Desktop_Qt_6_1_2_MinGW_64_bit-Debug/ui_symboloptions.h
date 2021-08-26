/********************************************************************************
** Form generated from reading UI file 'symboloptions.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYMBOLOPTIONS_H
#define UI_SYMBOLOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SymbolOptions
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTreeWidget *treeWidget;

    void setupUi(QDialog *SymbolOptions)
    {
        if (SymbolOptions->objectName().isEmpty())
            SymbolOptions->setObjectName(QString::fromUtf8("SymbolOptions"));
        SymbolOptions->resize(400, 300);
        gridLayout = new QGridLayout(SymbolOptions);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(SymbolOptions);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        treeWidget = new QTreeWidget(frame);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem->setCheckState(1, Qt::Checked);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem1->setCheckState(1, Qt::Checked);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem2->setCheckState(1, Qt::Checked);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem3->setCheckState(1, Qt::Checked);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem4->setCheckState(1, Qt::Checked);
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem5->setCheckState(1, Qt::Checked);
        QTreeWidgetItem *__qtreewidgetitem6 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem6->setCheckState(1, Qt::Checked);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));

        verticalLayout->addWidget(treeWidget);


        gridLayout->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(SymbolOptions);

        QMetaObject::connectSlotsByName(SymbolOptions);
    } // setupUi

    void retranslateUi(QDialog *SymbolOptions)
    {
        SymbolOptions->setWindowTitle(QCoreApplication::translate("SymbolOptions", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("SymbolOptions", "TextLabel", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("SymbolOptions", "Values", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("SymbolOptions", "Properties", nullptr));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("SymbolOptions", "Ersatzsignal - arrow", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("SymbolOptions", "Bremswegabstand", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem3->setText(0, QCoreApplication::translate("SymbolOptions", "Sh1", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = treeWidget->topLevelItem(3);
        ___qtreewidgetitem4->setText(0, QCoreApplication::translate("SymbolOptions", "Gegengleisanzeiger", nullptr));
        QTreeWidgetItem *___qtreewidgetitem5 = treeWidget->topLevelItem(4);
        ___qtreewidgetitem5->setText(0, QCoreApplication::translate("SymbolOptions", "Geschwindigkeitsanzeiger", nullptr));
        QTreeWidgetItem *___qtreewidgetitem6 = treeWidget->topLevelItem(5);
        ___qtreewidgetitem6->setText(0, QCoreApplication::translate("SymbolOptions", "Lichtsignal", nullptr));
        QTreeWidgetItem *___qtreewidgetitem7 = treeWidget->topLevelItem(6);
        ___qtreewidgetitem7->setText(0, QCoreApplication::translate("SymbolOptions", "Signalausleger", nullptr));
        treeWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class SymbolOptions: public Ui_SymbolOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYMBOLOPTIONS_H
