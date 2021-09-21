#include "uploadnewdata.h"
#include "ui_uploadnewdata.h"

UploadNewData::UploadNewData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UploadNewData)
{
    ui->setupUi(this);
    setWindowTitle("Update And Add Data");

    QDirIterator iter( "Data", QDir::Dirs | QDir::NoDotAndDotDot);
    while(iter.hasNext() )
    {
        QString val = iter.next();
        ui->comboBox->addItem(val.remove("Data/"));
    }
}

UploadNewData::~UploadNewData()
{
    delete ui;
}

void UploadNewData::lblState(bool isON)
{
    ui->lblGleisknoten->setEnabled(isON);
    ui->lblGleiskanten->setEnabled(isON);
    ui->lblHoehe->setEnabled(isON);
    ui->lblKMLine->setEnabled(isON);
    ui->lblLage->setEnabled(isON);
    ui->lblUberhohung->setEnabled(isON);
    ui->lineEditGleiskanten->setEnabled(isON);
    ui->lineEditGleisknoten->setEnabled(isON);
    ui->lineEditHoehe->setEnabled(isON);
    ui->lineEditKMLine->setEnabled(isON);
    ui->lineEditLage->setEnabled(isON);
    ui->lineEditUberhohung->setEnabled(isON);
    ui->btnGleiskanten->setEnabled(isON);
    ui->btnGleisknoten->setEnabled(isON);
    ui->btnHoehe->setEnabled(isON);
    ui->btnKMLine->setEnabled(isON);
    ui->btnLage->setEnabled(isON);
    ui->btnUberhohung->setEnabled(isON);
}


void UploadNewData::on_btnClickHere_clicked()
{
    if (ui->radioModify->isChecked()) {
        lblState(true);
    }


   else {
        if (QDir("Data/"+ui->lineEditLocation->text()).exists() && !ui->lineEditLocation->text().isEmpty()){
            QMessageBox::warning(this, "Information", "Location already exist... \n Please select from existing values");
            return;
        }

        if (ui->lineEditLocation->text().isNull()){
            QMessageBox::warning(this, "Information", "You have not enter any Location/station... \n Please select from existing values");
            return;
        }

        if (!QDir("Data/"+ui->lineEditLocation->text()).exists() && ui->lineEditLocation->text().length() >= 3){
            QDir().mkpath("Data/"+ui->lineEditLocation->text());
            lblState(true);
        }

        else {
            QMessageBox::information(this, "Information", "Please enter a valid Location");
        }
    }
}



void UploadNewData::on_btnGleisknoten_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Add File", "");
    if (!ui->lineEditGleiskanten->text().isEmpty() || !ui->lineEditGleisknoten->text().isEmpty() || !ui->lineEditHoehe->text().isEmpty() ||
            !ui->lineEditKMLine->text().isEmpty() || !ui->lineEditLage->text().isEmpty() || !ui->lineEditUberhohung->text().isEmpty()){

        ui->btnOK->setEnabled(true);
    }
    else{
        ui->btnOK->setEnabled(false);

    }
    if (fileName.isEmpty()){
        QMessageBox::warning(this, "Warning", "No file selected");
    }

    else{
        QFileInfo file (fileName);
        QString file_extension = file.completeSuffix();
        if (file_extension != "json" && file_extension != "geojson"){
            QMessageBox::warning(this, "Warning", "Please Enter a valid file \n Only Json format is acceptable");
        }
        else{
            ui->lineEditGleisknoten->setText(fileName);
            ui->btnOK->setEnabled(true);
        }
    }
}



void UploadNewData::on_btnCancel_clicked()
{
    close();
}



void UploadNewData::on_btnHoehe_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Add File", "");
    if (!ui->lineEditGleiskanten->text().isEmpty() || !ui->lineEditGleisknoten->text().isEmpty() || !ui->lineEditHoehe->text().isEmpty() ||
            !ui->lineEditKMLine->text().isEmpty() || !ui->lineEditLage->text().isEmpty() || !ui->lineEditUberhohung->text().isEmpty()){
        ui->btnOK->setEnabled(true);
    }
    else{
        ui->btnOK->setEnabled(false);

    }
    if (fileName.isEmpty()){
        QMessageBox::warning(this, "Warning", "No file selected");
    }

    else{
        QFileInfo file (fileName);
        QString file_extension = file.completeSuffix();
        if (file_extension != "json" && file_extension != "geojson"){
            QMessageBox::warning(this, "Warning", "Please Enter a valid file \n Only Json format is acceptable");
        }
        else{
            ui->lineEditHoehe->setText(fileName);
            ui->btnOK->setEnabled(true);
        }
    }
}


void UploadNewData::on_btnKMLine_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Add File", "");
    if (!ui->lineEditGleiskanten->text().isEmpty() || !ui->lineEditGleisknoten->text().isEmpty() || !ui->lineEditHoehe->text().isEmpty() ||
            !ui->lineEditKMLine->text().isEmpty() || !ui->lineEditLage->text().isEmpty() || !ui->lineEditUberhohung->text().isEmpty()){
        ui->btnOK->setEnabled(true);
    }
    else{
        ui->btnOK->setEnabled(false);

    }
    if (fileName.isEmpty()){
        QMessageBox::warning(this, "Warning", "No file selected");
    }

    else{
        QFileInfo file (fileName);
        QString file_extension = file.completeSuffix();
        if (file_extension != "json" && file_extension != "geojson"){
            QMessageBox::warning(this, "Warning", "Please Enter a valid file \n Only Json format is acceptable");
        }
        else{
            ui->lineEditKMLine->setText(fileName);
            ui->btnOK->setEnabled(true);
        }
    }
}


void UploadNewData::on_btnGleiskanten_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Add File", "");
    if (!ui->lineEditGleiskanten->text().isEmpty() || !ui->lineEditGleisknoten->text().isEmpty() || !ui->lineEditHoehe->text().isEmpty() ||
            !ui->lineEditKMLine->text().isEmpty() || !ui->lineEditLage->text().isEmpty() || !ui->lineEditUberhohung->text().isEmpty()){
        ui->btnOK->setEnabled(true);
    }
    else{
        ui->btnOK->setEnabled(false);

    }
    if (fileName.isEmpty()){
        QMessageBox::warning(this, "Warning", "No file selected");
    }

    else{
        QFileInfo file (fileName);
        QString file_extension = file.completeSuffix();
        if (file_extension != "json" && file_extension != "geojson"){
            QMessageBox::warning(this, "Warning", "Please Enter a valid file \n Only Json format is acceptable");
        }
        else{
            ui->lineEditGleiskanten->setText(fileName);
            ui->btnOK->setEnabled(true);
        }
    }
}


void UploadNewData::on_btnLage_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Add File", "");
    if (!ui->lineEditGleiskanten->text().isEmpty() || !ui->lineEditGleisknoten->text().isEmpty() || !ui->lineEditHoehe->text().isEmpty() ||
           !ui->lineEditKMLine->text().isEmpty() || !ui->lineEditLage->text().isEmpty() || !ui->lineEditUberhohung->text().isEmpty()){
        ui->btnOK->setEnabled(true);
    }
    else{
        ui->btnOK->setEnabled(false);

    }
    if (fileName.isEmpty()){
        QMessageBox::warning(this, "Warning", "No file selected");
    }

    else{
        QFileInfo file (fileName);
        QString file_extension = file.completeSuffix();
        if (file_extension != "json" && file_extension != "geojson"){
            QMessageBox::warning(this, "Warning", "Please Enter a valid file \n Only Json format is acceptable");
        }
        else{
            ui->lineEditLage->setText(fileName);
            ui->btnOK->setEnabled(true);
        }
    }
}


void UploadNewData::on_btnUberhohung_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Add File", "");
    if (!ui->lineEditGleiskanten->text().isEmpty() || !ui->lineEditGleisknoten->text().isEmpty() || !ui->lineEditHoehe->text().isEmpty() ||
            !ui->lineEditKMLine->text().isEmpty() || !ui->lineEditLage->text().isEmpty() || !ui->lineEditUberhohung->text().isEmpty()){
        ui->btnOK->setEnabled(true);
    }
    else{
        ui->btnOK->setEnabled(false);

    }
    if (fileName.isEmpty()){
        QMessageBox::warning(this, "Warning", "No file selected");
    }

    else{
        QFileInfo file (fileName);
        QString file_extension = file.completeSuffix();
        if (file_extension != "json" && file_extension != "geojson"){
            QMessageBox::warning(this, "Warning", "Please Enter a valid file \n Only Json format is acceptable");
        }
        else{
            ui->lineEditUberhohung->setText(fileName);
            ui->btnOK->setEnabled(true);
        }
    }
}


void UploadNewData::on_btnOK_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Warning", "Are you sure... \n You want to save all selected data?", QMessageBox::Yes |QMessageBox::No);
    if (reply == QMessageBox::No) return;
    QString msg;
    if (ui->lineEditLocation->text().isEmpty()) ui->lineEditLocation->setText(ui->comboBox->currentText());
    if (!ui->lineEditGleiskanten->text().isEmpty()){
        QString fileName = ui->lineEditGleiskanten->text();

        QString resourcefileName = "Data/"+ui->lineEditLocation->text()+"/Gleiskanten.geojson";
        QFile file (fileName);
        QFile file2 (resourcefileName);

        if (QFile::exists(resourcefileName)){
            QMessageBox::StandardButton reply = QMessageBox::question(this, "Warning", "Gleiskanten already exist... \n Did you want to override the data?", QMessageBox::Yes |QMessageBox::No);
            if (reply == QMessageBox::No) return;
            else{
                QFile::remove(resourcefileName);
                if (QFile::copy(fileName, resourcefileName)){

                    QMessageBox::information(this, "Information", "Gleiskanten successfully updated");
                }
                else{
                    QMessageBox::warning(this, "Warning", "Error: Problem updating Gleiskanten");
                }
            }
        }
        else{
            if (QFile::copy(fileName, resourcefileName)){
                msg.append("Gleiskanten successfully updated \n");
//                QMessageBox::information(this, "Information", "Gleiskanten successfully updated");
            }
            else{
                QMessageBox::warning(this, "Warning", "Error: Problem updating Gleiskanten");
            }
        }

    }

    if (!ui->lineEditGleisknoten->text().isEmpty()){
        QString fileName = ui->lineEditGleisknoten->text();
        QString resourcefileName = "Data/"+ui->lineEditLocation->text()+"/Gleisknoten.geojson";
        QFile file (fileName);
        QFile file2 (resourcefileName);

        if (QFile::exists(resourcefileName)){
            QMessageBox::StandardButton reply = QMessageBox::question(this, "Warning", "Gleisknoten already exist... \n Did you want to override the data?", QMessageBox::Yes |QMessageBox::No);
            if (reply == QMessageBox::No) return;
            else{
                QFile::remove(resourcefileName);
                if (QFile::copy(fileName, resourcefileName)){
                    QMessageBox::information(this, "Information", "Gleisknoten successfully updated");
                }
                else{
                    QMessageBox::warning(this, "Warning", "Error: Problem updating Gleisknoten");
                }
            }
        }
        else{
            if (QFile::copy(fileName, resourcefileName)){
                msg.append("Gleisknoten successfully updated \n");
//                QMessageBox::information(this, "Information", "Gleisknoten successfully updated");
            }
            else{
                QMessageBox::warning(this, "Warning", "Error: Problem updating Gleisknoten");
            }
        }

    }


    if (!ui->lineEditHoehe->text().isEmpty()){
        QString fileName = ui->lineEditHoehe->text();
        QString resourcefileName = "Data/"+ui->lineEditLocation->text()+"/Entwurfselement_Hoehe.geojson";
        QFile file (fileName);
        QFile file2 (resourcefileName);

        if (QFile::exists(resourcefileName)){
            QMessageBox::StandardButton reply = QMessageBox::question(this, "Warning", "Entwurfselement_Hoehe already exist... \n Did you want to override the data?", QMessageBox::Yes |QMessageBox::No);
            if (reply == QMessageBox::No) return;
            else{
                QFile::remove(resourcefileName);
                if (QFile::copy(fileName, resourcefileName)){
                    QMessageBox::information(this, "Information", "Entwurfselement_Hoehe successfully updated");
                }
                else{
                    QMessageBox::warning(this, "Warning", "Error: Problem updating Entwurfselement_Hoehe");
                }
            }
        }
        else{
            if (QFile::copy(fileName, resourcefileName)){
                msg.append("Entwurfselement_Hoehe successfully updated \n");
//                QMessageBox::information(this, "Information", "Entwurfselement_Hoehe successfully updated");
            }
            else{
                QMessageBox::warning(this, "Warning", "Error: Problem updating Entwurfselement_Hoehe");
            }
        }
    }


    if (!ui->lineEditKMLine->text().isEmpty()){
        QString fileName = ui->lineEditKMLine->text();
        QString resourcefileName = "Data/"+ui->lineEditLocation->text()+"/Entwurfselement_KMLinie.geojson";
        QFile file (fileName);
        QFile file2 (resourcefileName);

        if (QFile::exists(resourcefileName)){
            QMessageBox::StandardButton reply = QMessageBox::question(this, "Warning", "Entwurfselement_KMLinie already exist... \n Did you want to override the data?", QMessageBox::Yes |QMessageBox::No);
            if (reply == QMessageBox::No) return;
            else{
                QFile::remove(resourcefileName);
                if (QFile::copy(fileName, resourcefileName)){
                    QMessageBox::information(this, "Information", "Entwurfselement_KMLinie successfully updated");
                }
                else{
                    QMessageBox::warning(this, "Warning", "Error: Problem updating Entwurfselement_KMLinie");
                }
            }
        }
        else{
            if (QFile::copy(fileName, resourcefileName)){
                msg.append("Entwurfselement_KMLinie successfully updated \n");
//                QMessageBox::information(this, "Information", "Entwurfselement_KMLinie successfully updated");
            }
            else{
                QMessageBox::warning(this, "Warning", "Error: Problem updating Entwurfselement_KMLinie");
            }
        }
    }


    if (!ui->lineEditLage->text().isEmpty()){
        QString fileName = ui->lineEditLage->text();
        QString resourcefileName = "Data/"+ui->lineEditLocation->text()+"/Entwurfselement_Lage.geojson";
        QFile file (fileName);
        QFile file2 (resourcefileName);

        if (QFile::exists(resourcefileName)){
            QMessageBox::StandardButton reply = QMessageBox::question(this, "Warning", "Entwurfselement_Lage already exist... \n Did you want to override the data?", QMessageBox::Yes |QMessageBox::No);
            if (reply == QMessageBox::No) return;
            else{
                QFile::remove(resourcefileName);
                if (QFile::copy(fileName, resourcefileName)){
                    QMessageBox::information(this, "Information", "Entwurfselement_Lage successfully updated");
                }
                else{
                    QMessageBox::warning(this, "Warning", "Error: Problem updating Entwurfselement_Lage");
                }
            }
        }
        else{
            if (QFile::copy(fileName, resourcefileName)){
                msg.append("Entwurfselement_Lage successfully updated");
//                QMessageBox::information(this, "Information", "Entwurfselement_Lage successfully updated");
            }
            else{
                QMessageBox::warning(this, "Warning", "Error: Problem updating Entwurfselement_Lage");
            }
        }
    }


    if (!ui->lineEditUberhohung->text().isEmpty()){
        QString fileName = ui->lineEditUberhohung->text();
        QString resourcefileName = "Data/"+ui->lineEditLocation->text()+"/Entwurfselement_Ueberhoehung.geojson";
        QFile file (fileName);
        QFile file2 (resourcefileName);

        if (QFile::exists(resourcefileName)){
            QMessageBox::StandardButton reply = QMessageBox::question(this, "Warning", "Entwurfselement_Ueberhoehung already exist... \n Did you want to override the data?", QMessageBox::Yes |QMessageBox::No);
            if (reply == QMessageBox::No) return;
            else{
                QFile::remove(resourcefileName);
                if (QFile::copy(fileName, resourcefileName)){
                    QMessageBox::information(this, "Information", "Entwurfselement_Ueberhoehung successfully updated");
                }
                else{
                    QMessageBox::warning(this, "Warning", "Error: Problem updating Entwurfselement_Ueberhoehung");
                }
            }
        }
        else{
            if (QFile::copy(fileName, resourcefileName)){
                msg.append("Entwurfselement_Ueberhoehung successfully updated");
//                QMessageBox::information(this, "Information", "Entwurfselement_Ueberhoehung successfully updated");
            }
            else{
                QMessageBox::warning(this, "Warning", "Error: Problem updating Entwurfselement_Ueberhoehung");
            }
        }
    }
    if (!msg.isEmpty() && !msg.isNull()){
        QMessageBox::information(this, "Saved", msg);
        close();
    }





}


void UploadNewData::on_radioAddNew_clicked()
{
    ui->lineEditLocation->setEnabled(true);
    ui->comboBox->setEnabled(false);
    ui->btnClickHere->setEnabled(true);
    lblState(false);

}


void UploadNewData::on_radioModify_clicked()
{
    ui->lineEditLocation->setEnabled(false);
    ui->comboBox->setEnabled(true);
    ui->btnClickHere->setEnabled(true);
    lblState(false);
}

