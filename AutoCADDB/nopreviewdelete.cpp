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
        ui->comboAllFolder_6->addItem(val.remove("Data/"));
    }
}

NoPreviewDelete::~NoPreviewDelete()
{
    delete ui;
}

void NoPreviewDelete::checkButtonStatus(bool isON)
{
    ui->checkBoxGleiskanten_6->setEnabled(isON);
    ui->checkBoxGleisknoten_6->setEnabled(isON);
    ui->checkBoxHoehe_6->setEnabled(isON);
    ui->checkBoxKMLine_6->setEnabled(isON);
    ui->checkBoxLage_6->setEnabled(isON);
    ui->checkBoxUeberhoehung_6->setEnabled(isON);
}

void NoPreviewDelete::on_btnLoad_6_clicked()
{
    QString location = ui->comboAllFolder_6->currentText();
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
        if (file == "Gleiskanten.geojson") ui->checkBoxGleiskanten_6->setEnabled(true);
        if (file == "Gleisknoten.geojson") ui->checkBoxGleisknoten_6->setEnabled(true);
        if (file == "Entwurfselement_Hoehe.geojson") ui->checkBoxHoehe_6->setEnabled(true);
        if (file == "Entwurfselement_KMLinie.geojson") ui->checkBoxKMLine_6->setEnabled(true);
        if (file == "Entwurfselement_Lage.geojson") ui->checkBoxLage_6->setEnabled(true);
        if (file == "Entwurfselement_Ueberhoehung.geojson") ui->checkBoxUeberhoehung_6->setEnabled(true);
    }
    ui->checkBoxEntireStation->setEnabled(true);
    ui->btnDelete_6->setEnabled(true);
}


void NoPreviewDelete::on_comboAllFolder_6_currentTextChanged()
{
    checkButtonStatus(false);
    ui->btnDelete_6->setEnabled(false);
    ui->checkBoxEntireStation->setEnabled(false);
}


void NoPreviewDelete::on_checkBoxEntireStation_toggled(bool checked)
{
    if (checked){
        checkButtonStatus(false);
        ui->btnDelete_6->setEnabled(true);
    }
    else{
        on_btnLoad_6_clicked();
    }
}


void NoPreviewDelete::on_btnCancel_6_clicked()
{
    close();
}


void NoPreviewDelete::on_btnDelete_6_clicked()
{
    QString all;
    QString location = ui->comboAllFolder_6->currentText();
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
        if (ui->checkBoxGleiskanten_6->isChecked() && ui->checkBoxGleiskanten_6->isEnabled()){
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

        if (ui->checkBoxGleisknoten_6->isChecked() && ui->checkBoxGleisknoten_6->isEnabled()){
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


        if (ui->checkBoxHoehe_6->isChecked() && ui->checkBoxHoehe_6->isEnabled()){
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


        if (ui->checkBoxKMLine_6->isChecked() && ui->checkBoxKMLine_6->isEnabled()){
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


        if (ui->checkBoxLage_6->isChecked() && ui->checkBoxLage_6->isEnabled()){
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

        if (ui->checkBoxUeberhoehung_6->isChecked() && ui->checkBoxUeberhoehung_6->isEnabled()){
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

