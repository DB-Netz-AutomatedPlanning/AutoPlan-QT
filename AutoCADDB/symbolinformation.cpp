#include "symbolinformation.h"
#include "ui_symbolinformation.h"
#include <QTimer>
#include "symbolcontainer.h"
SymbolInformation::SymbolInformation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SymbolInformation)
{
    ui->setupUi(this);


 }



SymbolInformation::~SymbolInformation()
{
    delete ui;
}


void SymbolInformation::updateLabel()
{
    qInfo() << "ok";

    QPaintEvent *e;
    paintEvent(e);

    updateUi();



}
void SymbolInformation::updateUi(){

    QPaintEvent *event;
    paintEvent(event);
}

void SymbolInformation:: paintEvent(QPaintEvent *event) {
    ui->label->setText(defaultObjectName);

}
