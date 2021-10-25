#include "uploadnewdata.h"
#include "ui_uploadnewdata.h"
#include "symbolcontainer.h"

UploadNewData::UploadNewData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UploadNewData)
{
    ui->setupUi(this);
    setWindowTitle("Update And Add Data");

//    QDirIterator iter( "Data", QDir::Dirs | QDir::NoDotAndDotDot);
//    while(iter.hasNext())
//    {
//        QString val = iter.next();
//        ui->comboBox->addItem(val.remove("Data/"));
//    }
    ui->comboBox->addItem(projectName);
    if (!ui->comboBox->currentText().isNull() || !ui->comboBox->currentText().isEmpty()){
        ui->btnClickHere->setEnabled(true);
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

bool UploadNewData::modifyData(QString fileName, QString resourceFileName, bool isAlreadyAvailable)
{
    QFile file (fileName);
    QFile fileToSave (resourceFileName);
    QFileInfo info(fileToSave);
    QString current = info.fileName().remove("."+info.completeSuffix());

    if (isAlreadyAvailable){
        QFile::remove(resourceFileName);
        if (!file.open(QIODevice::ReadOnly)){
            QMessageBox::warning(this, "Warning", current+"\n" +file.errorString());
            return false;
        }

        QString allData = file.readAll();
        file.close();

        if (!fileToSave.open(QIODevice::WriteOnly)){
            QMessageBox::warning(this, "Warning", fileToSave.errorString());
            return false;
        }
        QByteArray bytes(allData.toUtf8());
        QByteArray encoded = bytes.toHex();
        fileToSave.write(encoded);
        fileToSave.close();
        return true;

    }

    else{
        if (!file.open(QIODevice::ReadOnly)){
            QMessageBox::warning(this, "Warning", current+"\n" +file.errorString());
            return false;
        }

        QString allData = file.readAll();
        file.close();
        if (!fileToSave.open(QIODevice::WriteOnly)){
            QMessageBox::warning(this, "Warning", fileToSave.errorString());
            return false;
        }
        QByteArray bytes(allData.toUtf8());
        QByteArray encoded = bytes.toHex();
        fileToSave.write(encoded);
        fileToSave.close();
        return true;
    }
}


void UploadNewData::on_btnClickHere_clicked()
{
    if (!ui->comboBox->currentText().isEmpty()){
        lblState(true);
    }
    else {
        QMessageBox::warning(this, "Project Not Found!!!", "Nothing to modify \n ...Please create a project");
        close();
    }
}



void UploadNewData::on_btnGleisknoten_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Add File", "");
    if (fileName.isEmpty()){
        ui->lineEditGleisknoten->clear();
        QMessageBox::warning(this, "Warning", "No file selected");

    }

    else{
        QFileInfo file (fileName);
        QString file_extension = file.completeSuffix();
        if (file_extension != "json" && file_extension != "geojson"){
            QMessageBox::warning(this, "Warning", "Please Enter a valid file \n Only json/geojson format is acceptable");
        }
        else{
            ui->lineEditGleisknoten->setText(fileName);
            ui->btnOK->setEnabled(true);
        }
    }


    if (!ui->lineEditGleiskanten->text().isEmpty() || !ui->lineEditGleisknoten->text().isEmpty() || !ui->lineEditHoehe->text().isEmpty() ||
            !ui->lineEditKMLine->text().isEmpty() || !ui->lineEditLage->text().isEmpty() || !ui->lineEditUberhohung->text().isEmpty()){

        ui->btnOK->setEnabled(true);
    }
    else{
        ui->btnOK->setEnabled(false);

    }

}



void UploadNewData::on_btnCancel_clicked()
{
    close();
}



void UploadNewData::on_btnHoehe_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Add File", "");
    if (fileName.isEmpty()){
        ui->lineEditHoehe->clear();
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

    if (!ui->lineEditGleiskanten->text().isEmpty() || !ui->lineEditGleisknoten->text().isEmpty() || !ui->lineEditHoehe->text().isEmpty() ||
            !ui->lineEditKMLine->text().isEmpty() || !ui->lineEditLage->text().isEmpty() || !ui->lineEditUberhohung->text().isEmpty()){
        ui->btnOK->setEnabled(true);
    }
    else{
        ui->btnOK->setEnabled(false);

    }

}


void UploadNewData::on_btnKMLine_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Add File", "");
    if (fileName.isEmpty()){
        ui->lineEditKMLine->clear();
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

    if (!ui->lineEditGleiskanten->text().isEmpty() || !ui->lineEditGleisknoten->text().isEmpty() || !ui->lineEditHoehe->text().isEmpty() ||
            !ui->lineEditKMLine->text().isEmpty() || !ui->lineEditLage->text().isEmpty() || !ui->lineEditUberhohung->text().isEmpty()){
        ui->btnOK->setEnabled(true);
    }
    else{
        ui->btnOK->setEnabled(false);

    } 
}


void UploadNewData::on_btnGleiskanten_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Add File", "");
    if (fileName.isEmpty()){
        ui->lineEditGleiskanten->clear();
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

    if (!ui->lineEditGleiskanten->text().isEmpty() || !ui->lineEditGleisknoten->text().isEmpty() || !ui->lineEditHoehe->text().isEmpty() ||
            !ui->lineEditKMLine->text().isEmpty() || !ui->lineEditLage->text().isEmpty() || !ui->lineEditUberhohung->text().isEmpty()){
        ui->btnOK->setEnabled(true);
    }
    else{
        ui->btnOK->setEnabled(false);

    }
}


void UploadNewData::on_btnLage_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Add File", "");
    if (fileName.isEmpty()){
        ui->lineEditLage->clear();
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

    if (!ui->lineEditGleiskanten->text().isEmpty() || !ui->lineEditGleisknoten->text().isEmpty() || !ui->lineEditHoehe->text().isEmpty() ||
           !ui->lineEditKMLine->text().isEmpty() || !ui->lineEditLage->text().isEmpty() || !ui->lineEditUberhohung->text().isEmpty()){
        ui->btnOK->setEnabled(true);
    }
    else{
        ui->btnOK->setEnabled(false);

    }

}


void UploadNewData::on_btnUberhohung_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Add File", "");
    if (fileName.isEmpty()){
        ui->lineEditUberhohung->clear();
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

    if (!ui->lineEditGleiskanten->text().isEmpty() || !ui->lineEditGleisknoten->text().isEmpty() || !ui->lineEditHoehe->text().isEmpty() ||
            !ui->lineEditKMLine->text().isEmpty() || !ui->lineEditLage->text().isEmpty() || !ui->lineEditUberhohung->text().isEmpty()){
        ui->btnOK->setEnabled(true);
    }
    else{
        ui->btnOK->setEnabled(false);

    }

}


void UploadNewData::on_btnOK_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Warning", "Are you sure... \n You want to save all selected data?", QMessageBox::Yes |QMessageBox::No);
    if (reply == QMessageBox::No) return;
    QString msg;
    if (!ui->lineEditGleiskanten->text().isEmpty()){
        QString fileName = ui->lineEditGleiskanten->text();

        QString resourcefileName = projectPath+ "/"+ projectName+"/temp/Gleiskanten.dbahn";

        if (QFile::exists(resourcefileName)){
            QMessageBox::StandardButton reply = QMessageBox::question(this, "Warning", "Gleiskanten already exist... \n Did you want to override the data?", QMessageBox::Yes |QMessageBox::No);
            if (reply == QMessageBox::No) return;
            else{
                if (modifyData(fileName, resourcefileName, true)){
                    msg.append("Gleiskanten successfully updated \n");
                }
                else QMessageBox::warning(this, "Warning", "Error: Problem updating Gleiskanten");
            }
        }
        else{
            if(modifyData(fileName, resourcefileName, false)){
                msg.append("Gleiskanten successfully updated \n");
            }
            else QMessageBox::warning(this, "Warning", "Error: Problem updating Gleiskanten");
        }
    }

    if (!ui->lineEditGleisknoten->text().isEmpty()){
        QString fileName = ui->lineEditGleisknoten->text();
        QString resourcefileName = projectPath+ "/"+ projectName+"/temp/Gleisknoten.dbahn";

        if (QFile::exists(resourcefileName)){
            QMessageBox::StandardButton reply = QMessageBox::question(this, "Warning", "Gleisknoten already exist... \n Did you want to override the data?", QMessageBox::Yes |QMessageBox::No);
            if (reply == QMessageBox::No) return;

            else{
                if (modifyData(fileName, resourcefileName, true)){
                    msg.append("Gleisknoten successfully updated \n");
                }
                else QMessageBox::warning(this, "Warning", "Error: Problem updating Gleisknoten");
            }
        }
        else{
            if(modifyData(fileName, resourcefileName, false)){
                msg.append("Gleisknoten successfully updated \n");
            }
            else QMessageBox::warning(this, "Warning", "Error: Problem updating Gleisknoten");
        }
    }



    if (!ui->lineEditHoehe->text().isEmpty()){
        QString fileName = ui->lineEditHoehe->text();
        QString resourcefileName = projectPath+ "/"+ projectName+"/temp/Entwurfselement_HO.dbahn";

        if (QFile::exists(resourcefileName)){
            QMessageBox::StandardButton reply = QMessageBox::question(this, "Warning", "Entwurfselement_HO already exist... \n Did you want to override the data?", QMessageBox::Yes |QMessageBox::No);
            if (reply == QMessageBox::No) return;

            else{
                if (modifyData(fileName, resourcefileName, true)){
                    msg.append("Entwurfselement_HO successfully updated \n");
                }
                else QMessageBox::warning(this, "Warning", "Error: Problem updating Entwurfselement_HO");
            }
        }

        else{
            if(modifyData(fileName, resourcefileName, false)){
                msg.append("Entwurfselement_HO successfully updated \n");
            }
            else QMessageBox::warning(this, "Warning", "Error: Problem updating Entwurfselement_HO");
        }
    }


    if (!ui->lineEditKMLine->text().isEmpty()){
        QString fileName = ui->lineEditKMLine->text();
        QString resourcefileName = projectPath+ "/"+ projectName+"/temp/Entwurfselement_KM.dbahn";

        if (QFile::exists(resourcefileName)){
            QMessageBox::StandardButton reply = QMessageBox::question(this, "Warning", "Entwurfselement_KM already exist... \n Did you want to override the data?", QMessageBox::Yes |QMessageBox::No);
            if (reply == QMessageBox::No) return;
            else{
                if (modifyData(fileName, resourcefileName, true)){
                    msg.append("Entwurfselement_KM successfully updated \n");
                }
                else QMessageBox::warning(this, "Warning", "Error: Problem updating Entwurfselement_KM");
            }
        }
        else{

            if(modifyData(fileName, resourcefileName, false)){
                msg.append("Entwurfselement_KM successfully updated \n");
            }
            else QMessageBox::warning(this, "Warning", "Error: Problem updating Entwurfselement_KM");
        }
    }


    if (!ui->lineEditLage->text().isEmpty()){
        QString fileName = ui->lineEditLage->text();
        QString resourcefileName = projectPath+ "/"+ projectName+"/temp/Entwurfselement_LA.dbahn";

        if (QFile::exists(resourcefileName)){
            QMessageBox::StandardButton reply = QMessageBox::question(this, "Warning", "Entwurfselement_Lage already exist... \n Did you want to override the data?", QMessageBox::Yes |QMessageBox::No);
            if (reply == QMessageBox::No) return;
            else{
                if (modifyData(fileName, resourcefileName, true)){
                    msg.append("Entwurfselement_LA successfully updated \n");
                }
                else QMessageBox::warning(this, "Warning", "Error: Problem updating Entwurfselement_LA");
            }
        }
        else{
            if(modifyData(fileName, resourcefileName, false)){
                msg.append("Entwurfselement_LA successfully updated \n");
            }
            else QMessageBox::warning(this, "Warning", "Error: Problem updating Entwurfselement_LA");
        }
    }

    if (!ui->lineEditUberhohung->text().isEmpty()){
        QString fileName = ui->lineEditUberhohung->text();
        QString resourcefileName = projectPath+ "/"+ projectName+"/temp/Entwurfselement_UH.dbahn";

        if (QFile::exists(resourcefileName)){
            QMessageBox::StandardButton reply = QMessageBox::question(this, "Warning", "Entwurfselement_Ueberhoehung already exist... \n Did you want to override the data?", QMessageBox::Yes |QMessageBox::No);
            if (reply == QMessageBox::No) return;
            else{
                if (modifyData(fileName, resourcefileName, true)){
                    msg.append("Entwurfselement_UH successfully updated \n");
                }
                else QMessageBox::warning(this, "Warning", "Error: Problem updating Entwurfselement_UH");
            }
        }
        else{
            if(modifyData(fileName, resourcefileName, false)){
                msg.append("Entwurfselement_UH successfully updated \n");
            }
            else QMessageBox::warning(this, "Warning", "Error: Problem updating Entwurfselement_UH");
        }
    }
    if (!msg.isEmpty() && !msg.isNull()){
        QMessageBox::information(this, "Saved", msg);
        close();
    }
//    else {
//        QMessageBox::information(this, "Saved", msg);
//    }
}

