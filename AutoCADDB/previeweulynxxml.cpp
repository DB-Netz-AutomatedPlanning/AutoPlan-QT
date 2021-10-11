#include "previeweulynxxml.h"
#include "ui_previeweulynxxml.h"
#include "ui_exportdialog.h"
#include "symbolcontainer.h"

PreviewEulynxXml::PreviewEulynxXml(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreviewEulynxXml)
{
    ui->setupUi(this);
    this->setWindowTitle("Success");

    QFile file (folderPath+"/eulynx"+stationLocation+".euxml");
    if (!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(this, "Fatal", file.errorString());
        return;
    }
    QTextStream in (&file);
    ui->tePreview->setText(in.readAll());
}

PreviewEulynxXml::~PreviewEulynxXml()
{
    delete ui;
}

void PreviewEulynxXml::on_btnOk_clicked()
{
    this->close();
}

