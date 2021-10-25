#include "newprojectdialog.h"
#include "ui_newprojectdialog.h"
#include "symbolcontainer.h"

NewProjectDialog::NewProjectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProjectDialog)
{
    setWindowTitle("Create New Project");
    ui->setupUi(this);
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
//            if (!QDir().rmpath(ui->leEnterProjectPath->text()+"/"+ui->leEnterProjectName->text())){
//                qDebug()<< 50000;
//                QMessageBox::information(this, "Fatal", "Cannot remove path");
//            }
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

    fileNames = QFileDialog::getOpenFileNames(this,"Choose Files","", "(*.geojson *.json)");

    if (fileNames.length() <1){
        QMessageBox::warning(this, "File Not Found", "No File Selected");
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



void NewProjectDialog::on_btnCreateNewProject_clicked()
{
    if (!QDir(ui->leEnterProjectPath->text()).exists()) {
        ui->btnBrowseProjectData->setEnabled(false);
        QMessageBox::warning(this, "Invalid Path", "Please Enter a valid save path in 'Create in' Section");
        return;
    }

    QString location = ui->leEnterProjectPath->text()+"/"+ui->leEnterProjectName->text();
    QDir().mkpath(location+"/temp");

    foreach (QString fileName, fileNames){
        //QString fileName = val;
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

    QString allMsg;
    foreach(QString eachMsg, msg){
        allMsg.append(eachMsg);
    }

    projectPath = ui->leEnterProjectPath->text();
    projectName = ui->leEnterProjectName->text();
    QMessageBox::information(this, "Successfull", allMsg);
    createNewProject = true;
    close();
}


void NewProjectDialog::on_btnCancel_clicked()
{
    close();
}

