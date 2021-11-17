#include "qgraphicssymbolcontainer.h"
#include "ui_qgraphicssymbolcontainer.h"
#include "symbolcontainer.h"

QGraphicsSymbolContainer::QGraphicsSymbolContainer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QGraphicsSymbolContainer)
{
    ui->setupUi(this);



}

QGraphicsSymbolContainer::~QGraphicsSymbolContainer()
{
    delete ui;
}


void QGraphicsSymbolContainer::on_pb1_clicked()
{
    tracks->addSymbol("Abfahrsignal");
}


void QGraphicsSymbolContainer::on_pb2_clicked()
{
    tracks->addSymbol("Achszahlkontakt");
}


void QGraphicsSymbolContainer::on_pb3_clicked()
{
    tracks->addSymbol("AutomatikETSchild");
}

