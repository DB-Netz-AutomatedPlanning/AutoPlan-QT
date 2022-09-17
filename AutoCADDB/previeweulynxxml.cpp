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
    ui->lblStationName->setText(projectName);
}

PreviewEulynxXml::~PreviewEulynxXml()
{
    delete ui;
}

void PreviewEulynxXml::on_btnOk_clicked()
{
//    this->close();
    this->accept();
}


void PreviewEulynxXml::on_btnValidateXML_clicked()
{
    QMessageBox::information(this, "Information", "Validate generated EUXML with the aid of "
                              "EULNX XML validator! \nGo to \n      * Tools -> EULYNX Validator");
}

