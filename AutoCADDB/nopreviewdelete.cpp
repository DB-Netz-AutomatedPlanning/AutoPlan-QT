#include "nopreviewdelete.h"
#include "ui_nopreviewdelete.h"

NoPreviewDelete::NoPreviewDelete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NoPreviewDelete)
{
    ui->setupUi(this);
    setWindowTitle("Remove Existing Data");
    QDirIterator iter( "Data", QDir::Dirs | QDir::NoDotAndDotDot);
    while(iter.hasNext() )
    {
        QString val = iter.next();
        ui->comboAllFolder->addItem(val.remove("Data/"));
    }
}

NoPreviewDelete::~NoPreviewDelete()
{
    delete ui;
}

void NoPreviewDelete::checkButtonStatus(bool isON)
{
    ui->checkBoxGleiskanten->setEnabled(isON);
    ui->checkBoxGleisknoten->setEnabled(isON);
    ui->checkBoxHoehe->setEnabled(isON);
    ui->checkBoxKMLine->setEnabled(isON);
    ui->checkBoxLage->setEnabled(isON);
    ui->checkBoxUeberhoehung->setEnabled(isON);
}

void NoPreviewDelete::on_btnLoad_clicked()
{
    QString location = ui->comboAllFolder->currentText();
    QString path = "Data/"+location;
    QDir dir (path);
    QFileInfoList files = dir.entryInfoList(QDir::Files);
    if  (files.length() ==0) {
        QMessageBox::information(this, "No Data", "No Existing Data for the selected Station");
        ui->checkBoxEntireStation->setEnabled(true);
        checkButtonStatus(false);
    }

    foreach(QFileInfo fi, files){
        QString file = fi.fileName();
        if (file == "Gleiskanten.geojson") ui->checkBoxGleiskanten->setEnabled(true);
        if (file == "Gleisknoten.geojson") ui->checkBoxGleisknoten->setEnabled(true);
        if (file == "Entwurfselement_Hoehe.geojson") ui->checkBoxHoehe->setEnabled(true);
        if (file == "Entwurfselement_KMLinie.geojson") ui->checkBoxKMLine->setEnabled(true);
        if (file == "Entwurfselement_Lage.geojson") ui->checkBoxLage->setEnabled(true);
        if (file == "Entwurfselement_Ueberhoehung.geojson") ui->checkBoxUeberhoehung->setEnabled(true);
    }
    ui->checkBoxEntireStation->setEnabled(true);
    ui->btnDelete->setEnabled(true);
}


void NoPreviewDelete::on_comboAllFolder_currentTextChanged()
{
    checkButtonStatus(false);
    ui->btnDelete->setEnabled(false);
    ui->checkBoxEntireStation->setEnabled(false);
}


void NoPreviewDelete::on_checkBoxEntireStation_toggled(bool checked)
{
    if (checked){
        checkButtonStatus(false);
        ui->btnDelete->setEnabled(true);
    }
    else{
        on_btnLoad_clicked();
    }
}


void NoPreviewDelete::on_btnCancel_clicked()
{
    close();
}


void NoPreviewDelete::on_btnDelete_clicked()
{
    QString all;
    QString location = ui->comboAllFolder->currentText();
    if (ui->checkBoxEntireStation->isEnabled() && ui->checkBoxEntireStation->isChecked()){
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Info", "Are you sure? ...\n Deleted data cannot be retrieved!!", QMessageBox::Yes |QMessageBox::No);
        if (reply == QMessageBox::No) return;
        QDir dir ("Data/"+location);
        if (dir.removeRecursively()) {
            QMessageBox::information(this, "Deleted", "Successfully Deleted !!");
            close();
        }
        else{
            QMessageBox::warning(this, "Error", "Cannot Delete Selected Data!");
        }
    }

    else{
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Warning", "Delete Selected File(s)? ...\n Are you sure?!!", QMessageBox::Yes |QMessageBox::No);
        if (reply == QMessageBox::No) return;
        if (ui->checkBoxGleiskanten->isChecked() && ui->checkBoxGleiskanten->isEnabled()){
            QString fileName = "Gleiskanten.geojson";
            QFile file ("Data/"+location+"/" +fileName);
            if (!file.remove()){
                QMessageBox::information(this, "Fatal", file.errorString());
            }
            else{
                file.remove();
                all.append("Gleiskanten Successfully Deleted ...\n");
            }
        }

        if (ui->checkBoxGleisknoten->isChecked() && ui->checkBoxGleisknoten->isEnabled()){
            QString fileName = "Gleisknoten.geojson";
            QFile file ("Data/"+location+"/" +fileName);
            if (!file.remove()){
                QMessageBox::information(this, "Fatal", file.errorString());
            }
            else{
                file.remove();
                all.append("Gleisknoten Successfully Deleted ...\n");
            }
        }


        if (ui->checkBoxHoehe->isChecked() && ui->checkBoxHoehe->isEnabled()){
            QString fileName = "Entwurfselement_Hoehe.geojson";
            QFile file ("Data/"+location+"/" +fileName);
            if (!file.remove()){
                QMessageBox::information(this, "Fatal", file.errorString());
            }
            else{
                file.remove();
                all.append("Entwurfselement_Hoehe Successfully Deleted ...\n");
            }
        }


        if (ui->checkBoxKMLine->isChecked() && ui->checkBoxKMLine->isEnabled()){
            QString fileName = "Entwurfselement_KMLinie.geojson";
            QFile file ("Data/"+location+"/" +fileName);
            if (!file.remove()){
                QMessageBox::information(this, "Fatal", file.errorString());
            }
            else{
                file.remove();
                all.append("Entwurfselement_KMLinie Successfully Deleted ...\n");
            }
        }


        if (ui->checkBoxLage->isChecked() && ui->checkBoxLage->isEnabled()){
            QString fileName = "Entwurfselement_Lage.geojson";
            QFile file ("Data/"+location+"/" +fileName);
            if (!file.remove()){
                QMessageBox::information(this, "Fatal", file.errorString());
            }
            else{
                file.remove();
                all.append("Entwurfselement_Lage Successfully Deleted ...\n");
            }
        }

        if (ui->checkBoxUeberhoehung->isChecked() && ui->checkBoxUeberhoehung->isEnabled()){
            QString fileName = "Entwurfselement_Ueberhoehung.geojson";
            QFile file ("Data/"+location+"/" +fileName);
            if (!file.remove()){
                QMessageBox::information(this, "Fatal", file.errorString());
            }
            else{
                file.remove();
                all.append("Entwurfselement_Ueberhoehung Successfully Deleted ...\n");
            }
        }
        QMessageBox::information(this, "Info",all);
        close();
    }
}

