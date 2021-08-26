#include "iconslist.h"
#include "ui_iconslist.h"
#include <QRegularExpression>
IconsList::IconsList(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IconsList)
{
    ui->setupUi(this);
    this->setWindowTitle("Symbols");



}

IconsList::~IconsList()
{
    delete ui;
}



