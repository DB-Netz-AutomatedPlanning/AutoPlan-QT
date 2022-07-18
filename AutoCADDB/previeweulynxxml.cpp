#include "previeweulynxxml.h"
#include "ui_previeweulynxxml.h"
#include "ui_exportdialog.h"
#include "symbolcontainer.h"
//#include "mainwindow.h"
//#include <QDesktopServices>
//#include <QUrl>

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

//    if (showMessageBox) {
//        QCheckBox *cb = new QCheckBox("Okay I understand");
//        QMessageBox msgbox;
//        msgbox.setText("Am I nerve-wrecking?");
//        msgbox.setIcon(QMessageBox::Icon::Question);
//        msgbox.addButton(QMessageBox::Ok);
//        msgbox.addButton(QMessageBox::Cancel);
//        msgbox.setDefaultButton(QMessageBox::Cancel);
//        msgbox.setCheckBox(cb);

//        QObject::connect(cb, &QCheckBox::stateChanged, [this](int state){
//            if (static_cast<Qt::CheckState>(state) == Qt::CheckState::Checked) {
//                showMessageBox = false;
//            }
//        });

//        msgbox.exec();
//    }





//    MainWindow w;
//    w.on_actionEULYNX_Validator_triggered();

//    QMessageBox::StandardButton option = QMessageBox::question( this, "Information",
//                                                                    tr("Not Available! \nDid you want to use external Validator ?"),
//                                                                    QMessageBox::No | QMessageBox::Yes);
////    QMessageBox::information(this, "Information", "Not Available! \nDid you want to use external Validatorr");
//    if (option== QMessageBox::No) return;
//    if (option == QMessageBox::Yes){
//        QDesktopServices::openUrl(QUrl("https://www.oxygenxml.com/doc/versions/24.0/ug-editor/topics/validating-XML-documents-against-schema.html"));
//    }
}

