/********************************************************************************
** Form generated from reading UI file 'symbolcontainer.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYMBOLCONTAINER_H
#define UI_SYMBOLCONTAINER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SymbolContainer
{
public:
    QLabel *radsensor;
    QLabel *hauptsignal;
    QLabel *ragier;

    void setupUi(QWidget *SymbolContainer)
    {
        if (SymbolContainer->objectName().isEmpty())
            SymbolContainer->setObjectName(QString::fromUtf8("SymbolContainer"));
        SymbolContainer->resize(400, 300);
        radsensor = new QLabel(SymbolContainer);
        radsensor->setObjectName(QString::fromUtf8("radsensor"));
        radsensor->setGeometry(QRect(30, 30, 71, 21));
        radsensor->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/smallSvgs/Hauptsignal.svg")));
        hauptsignal = new QLabel(SymbolContainer);
        hauptsignal->setObjectName(QString::fromUtf8("hauptsignal"));
        hauptsignal->setGeometry(QRect(30, 60, 47, 14));
        hauptsignal->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/smallSvgs/Radsensor.svg")));
        ragier = new QLabel(SymbolContainer);
        ragier->setObjectName(QString::fromUtf8("ragier"));
        ragier->setGeometry(QRect(30, 90, 61, 31));
        ragier->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/smallSvgs/Ragierhalttafel.svg")));

        retranslateUi(SymbolContainer);

        QMetaObject::connectSlotsByName(SymbolContainer);
    } // setupUi

    void retranslateUi(QWidget *SymbolContainer)
    {
        SymbolContainer->setWindowTitle(QCoreApplication::translate("SymbolContainer", "Form", nullptr));
        radsensor->setText(QString());
        hauptsignal->setText(QString());
        ragier->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SymbolContainer: public Ui_SymbolContainer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYMBOLCONTAINER_H
