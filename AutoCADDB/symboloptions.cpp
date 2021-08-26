#include "symboloptions.h"
#include "ui_symboloptions.h"

SymbolOptions::SymbolOptions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SymbolOptions)
{
    ui->setupUi(this);
}

SymbolOptions::~SymbolOptions()
{
    delete ui;
}
