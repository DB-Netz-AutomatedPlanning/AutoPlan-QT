#include "importfolder.h"
#include "ui_importfolder.h"

ImportFolder::ImportFolder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImportFolder)
{
    ui->setupUi(this);
    setWindowTitle("Import folder");
}

ImportFolder::~ImportFolder()
{
    delete ui;
}
