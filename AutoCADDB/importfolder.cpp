#include "importfolder.h"
#include "ui_importfolder.h"

ImportFolder::ImportFolder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImportFolder)
{
    ui->setupUi(this);
    setWindowTitle("Import data folder");
}

ImportFolder::~ImportFolder()
{
    delete ui;
}

void ImportFolder::on_rdAdd_clicked()
{
    ui->cmbExistingStn->clear();
    ui->btnImport->setEnabled(false);
    ui->cmbExistingStn->setEnabled(false);
    ui->leFolder->setEnabled(false);
    //ui->lineEdit->setEnabled(true);
    ui->btnEnable->setEnabled(true);
}


void ImportFolder::on_rdModify_clicked()
{
    QDirIterator iter( "Data", QDir::Dirs | QDir::NoDotAndDotDot);
    while(iter.hasNext())
    {
        QString val = iter.next();
        ui->cmbExistingStn->addItem(val.remove("Data/"));
    }
    ui->cmbExistingStn->setEnabled(true);
    ui->btnEnable->setEnabled(true);
}


void ImportFolder::on_btnEnable_clicked() {}

void ImportFolder::on_btnImport_clicked()
{
    QString allMsg;
    foreach (QString val, msg) allMsg.append(val+"\n");
    QMessageBox::information(this, "Success", allMsg);
    close();
}

