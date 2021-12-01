#include "previeweulynxxml.h"
#include "ui_previeweulynxxml.h"
#include "ui_exportdialog.h"
#include "symbolcontainer.h"
#include <QDesktopServices>
#include <QUrl>

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

//void PreviewEulynxXml::updateText(const QString &newText)
//{
//    ui->tePreview->setText(newText);
//}

void PreviewEulynxXml::on_btnOk_clicked()
{
    this->close();
}


void PreviewEulynxXml::on_btnValidateXML_clicked()
{
    QMessageBox::StandardButton option = QMessageBox::question( this, "Information",
                                                                    tr("Not Available! \nDid you want to use external Validator ?"),
                                                                    QMessageBox::No | QMessageBox::Yes);
//    QMessageBox::information(this, "Information", "Not Available! \nDid you want to use external Validatorr");
    if (option== QMessageBox::No) return;
    if (option == QMessageBox::Yes){
        QDesktopServices::openUrl(QUrl("https://www.oxygenxml.com/doc/versions/24.0/ug-editor/topics/validating-XML-documents-against-schema.html"));
    }
}

