#include "exportdialog.h"
#include "ui_exportdialog.h"

ExportDialog::ExportDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExportDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Export file");
}

ExportDialog::~ExportDialog()
{
    delete ui;
}
