#include "exportdialog.h"
#include "previeweulynxxml.h"
#include "ui_exportdialog.h"
#include <QProgressDialog>
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

void ExportDialog::on_btnExport_clicked()
{
    PreviewEulynxXml preXml;
    preXml.setModal(true);
    preXml.exec();
}

