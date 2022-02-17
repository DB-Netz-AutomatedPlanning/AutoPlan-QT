#include "newprojectdialog.h"
#include "ui_newprojectdialog.h"
#include "symbolcontainer.h"

NewProjectDialog::NewProjectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProjectDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Create New Project");
}

NewProjectDialog::~NewProjectDialog()
{
    delete ui;
}

void NewProjectDialog::on_btnBrowseProjectPath_clicked()
{
    if (ui->leEnterProjectName->text().isEmpty() || ui->leEnterProjectName->text().isNull()){
        QMessageBox::warning(this, "No Project Name", "Please Enter a Project Name");
        return;
    }

    QString filePath = QFileDialog::getExistingDirectory(this, ("Select Output Folder"), QDir::currentPath());



    if (QDir(filePath+"/"+ui->leEnterProjectName->text()).exists()){
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Already Exist", "Project Name Already Exist... \n Did you want to override the project?");
        if (reply == QMessageBox::No){
            return;
        }
        else{
            QDir dir(filePath+"/"+ui->leEnterProjectName->text());
            dir.removeRecursively();
        }
    }

    ui->leEnterProjectPath->setText(filePath);

    if (ui->leEnterProjectPath->text().isNull() || ui->leEnterProjectPath->text().isEmpty()){
        ui->btnBrowseProjectData->setEnabled(false);
    }
    else  ui->btnBrowseProjectData->setEnabled(true);


}


void NewProjectDialog::on_btnBrowseProjectData_clicked()
{
    if (!QDir(ui->leEnterProjectPath->text()).exists()) {
        ui->btnBrowseProjectData->setEnabled(false);
        QMessageBox::warning(this, "Invalid Path", "Please Enter a valid save path in 'Create in' Section");
        return;
    }

    if (ui->fileFormatComboBox->currentText() == ".json"){
        fileNames = QFileDialog::getOpenFileNames(this,"Choose Files","", "(*.geojson *.json)");

        if (fileNames.length() <1){
            QMessageBox::warning(this, "File Not Found", "No File Selected");
            ui->leImportProjectData->clear();
            ui->btnCreateNewProject->setEnabled(false);
        }
        else if (fileNames.length() == 1){
            ui->btnCreateNewProject->setEnabled(true);
            ui->leImportProjectData->setText(fileNames[0]);
        }
        else {
            ui->btnCreateNewProject->setEnabled(true);
            ui->leImportProjectData->setText("Multiple files selected*");
        }
    }
    else if (ui->fileFormatComboBox->currentText() == ".mdb"){
        fileName = QFileDialog::getOpenFileName(this, "Add File", "", "(*.mdb)" );
        if (fileName.isEmpty()){
            ui->leImportProjectData->clear();
            QMessageBox::warning(this, "Warning", "No file selected");
            ui->btnCreateNewProject->setEnabled(false);
        }
        else {
            ui->btnCreateNewProject->setEnabled(true);
            ui->leImportProjectData->setText(fileName);
        }
    }
}


void NewProjectDialog::on_btnCreateNewProject_clicked()
{
    if (ui->leEnterProjectName->text().isEmpty() || ui->leEnterProjectName->text().isNull()){
        QMessageBox::warning(this, "No Project Name", "Please Enter a Project Name");
        return;
    }

    if (!QDir(ui->leEnterProjectPath->text()).exists()) {
        ui->btnBrowseProjectData->setEnabled(false);
        QMessageBox::warning(this, "Invalid Path", "Please Enter a valid save path in 'Create in' Section");
        return;
    }
    QString location = ui->leEnterProjectPath->text()+"/"+ui->leEnterProjectName->text();
    QDir().mkpath(location+"/temp");

    if (ui->fileFormatComboBox->currentText() == ".json"){
        foreach (QString fileName, fileNames){
            QStringList each = fileName.split(QRegularExpression("/"));
            // Naming Convention
            //  "Entwurfselement_HO.(extension)"
            //  "Entwurfselement_KM.(extension)"
            //  "Entwurfselement_LA.(extension)"
            //  "Entwurfselement_UH.(extension)"
            //  "Gleiskanten.(extension)"
            //  "Gleisknoten.(extension)"

            QFile file (fileName);
            QFileInfo info (fileName);
            if (!file.open(QIODevice::ReadOnly)){
                QMessageBox::warning(this, "Warning", file.errorString());
                return;
            }

            //if (file.open(QIODevice::ReadOnly)){
            QString current = each.back().remove("."+info.completeSuffix());
            if (current == "Entwurfselement_HO" || current == "Entwurfselement_KM" || current == "Entwurfselement_LA" ||
                    current == "Entwurfselement_UH" || current == "Gleiskanten" || current == "Gleisknoten"){


                QString allData = file.readAll();
                file.close();

                // create a .dbahn file corresponding to the json file into the saving folder
                QFile fileToSave (ui->leEnterProjectPath->text()+"/"+ui->leEnterProjectName->text() +"/temp/" + current+".dbahn");

                if (!fileToSave.open(QIODevice::WriteOnly)){
                    QMessageBox::warning(this, "Warning", fileToSave.errorString());
                    return;
                }
                QByteArray bytes(allData.toUtf8());
                QByteArray encoded = bytes.toHex();
                fileToSave.write(encoded);
                fileToSave.close();
                msg.append(current +"successfully updated \n");
            }
        }
    }

    else if (ui->fileFormatComboBox->currentText() == ".mdb"){
        QStringList each = fileName.split(QRegularExpression("/"));
        QFile file (fileName);
        QFileInfo info (fileName);

        if (!file.open(QIODevice::ReadOnly)){
            QMessageBox::warning(this, "Warning", file.errorString());
            return;
        }

        //if (file.open(QIODevice::ReadOnly)){
        QString current = each.back().remove("."+info.completeSuffix());
        //        if (current == "Entwurfselement_HO" || current == "Entwurfselement_KM" || current == "Entwurfselement_LA" ||
        //              current == "Entwurfselement_UH" || current == "Gleiskanten" || current == "Gleisknoten"){


        QString fileToSave = ui->leEnterProjectPath->text()+"/"+ui->leEnterProjectName->text() +"/temp/" + current+".MDB";
        if (!QFile::copy(fileName,fileToSave)){
            QMessageBox::information(this, "Fatal!", "Poblem accessing your file");
            return;
        }

        msg.append(current +"successfully updated \n");
    }
    QString allMsg;
    foreach(QString eachMsg, msg){
        allMsg.append(eachMsg);
    }

    if (allMsg.isEmpty() || allMsg.isNull() || allMsg ==""){
        QMessageBox::warning(this, "Fatal !", "Please upload appropriate file with correct Naming Convention");
        ui->leImportProjectData->clear();
        return;
    }else {
        QMessageBox::information(this, "Successfull", allMsg);
        // set Important global parameters
        projectPath = ui->leEnterProjectPath->text();
        projectName = ui->leEnterProjectName->text();
        fileFormat = ui->fileFormatComboBox->currentText();
        countryCode = ui->countryCodeComboBox->currentText();
        createNewProject = true;
        close();
    }

    projectName = ui->leEnterProjectName->text();
}

void NewProjectDialog::on_btnCancel_clicked()
{
    close();
}
