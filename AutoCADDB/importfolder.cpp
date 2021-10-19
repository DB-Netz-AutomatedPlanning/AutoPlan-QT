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


void ImportFolder::on_btnEnable_clicked()
{





//    int count =0;

//    QStringList fileNames;
//    // Enter Project Name/ Location
//    QString location = ui->lineEdit->text();
//    if (location.isNull() || location.isEmpty()){
//        QMessageBox::warning(this, "No Project Name", "Please Enter a Project Name");
//        return;
//    }

//    if (!QDir("Data/"+location).exists() && location.length() >= 3){
//        QDir().mkpath("Data/"+location);
//    }


//    fileNames = QFileDialog::getOpenFileNames(this,"Choose Files","", "(*.geojson *.json)");
//    foreach (QString val, fileNames){
//        QString fileName = val;



//        QStringList each = val.split(QRegularExpression("/"));
//        // Naming Convention
////        "Entwurfselement_HO.geojson"
////        "Entwurfselement_KM.geojson"
////        "Entwurfselement_LA.geojson"
////        "Entwurfselement_UH.geojson"
////        "Gleiskanten.geojson"
////        "Gleisknoten.geojson"

//        QFile file (val);
//        if (file.open(QIODevice::ReadOnly)){

//            QString current = each.back().remove(".geojson");
//            if (current == "Entwurfselement_HO" || current == "Entwurfselement_KM" || current == "Entwurfselement_LA" ||
//                    current == "Entwurfselement_UH" || current == "Gleiskanten" || current == "Gleisknoten"){

//                QString resourcefileName = "Data/"+location+"/" + each.back()+".geojson";
//                qInfo()<< resourcefileName;

//                if (QFile::exists(resourcefileName)){
//                    QFile::remove(resourcefileName);
//                }
//                if (QFile::copy(fileName, resourcefileName)){
//                    count++;
//                    msg.append(current+" successfully updated \n");
//                }
//            }
//        }
//    }
//    if (fileNames.length() <1){
//        QMessageBox::warning(this, "File Not Found", "No File Selected");
//    }
//    else {
//        ui->btnImport->setEnabled(true);
//        ui->leFolder->setText("  You have selected "+QString::number(count)+" files");
//    }
}


void ImportFolder::on_btnImport_clicked()
{
    QString allMsg;
    foreach (QString val, msg) allMsg.append(val+"\n");
    QMessageBox::information(this, "Success", allMsg);
    close();
}

