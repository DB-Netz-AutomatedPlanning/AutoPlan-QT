#include "symbolcontainer.h"
#include "ui_symbolcontainer.h"



QString glbObjectName = "sayli";
QString defaultObjectName = "default name";


SymbolContainer::SymbolContainer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SymbolContainer)
{
    ui->setupUi(this);
   glbObjectName = "sayli";
}

SymbolContainer::~SymbolContainer()
{

     glbObjectName = "sayli";
    delete ui ;
}
