#include "newprojectdialog.h"
#include "ui_newprojectdialog.h"
#include "symbolcontainer.h"
#include "gleiskantenfromunprocessedjson.h"
#include "gleisknotenfromunprocessedjson.h"
#include "kmliniefromunprocessedjson.h"
#include "hofromunprocessedjson.h"
#include "uberhohungfromunprocessedjson.h"
#include "lagefromunprocessedjson.h"
#include <QPushButton>
#include<QSysInfo>
#include<QProcess>
#include <QTime>
#include <QDir>
#include <QDirIterator>


NewProjectDialog::NewProjectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProjectDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Create New Project");
//    connect (ui->btnBrowseProjectPath , & QPushButton::clicked, this, & NewProjectDialog::btnBrowseProjectPath_clicked);
}

NewProjectDialog::~NewProjectDialog()
{
    delete ui;
}

void NewProjectDialog::findOS()
{
    // Linux
    this->setApp("bash");
    this->setEndl("\n");

#ifdef Q_OS_WIN
    //Windows
    this->setApp("cmd");
    this->setEndl("\n");
    //    this->setEndl("\r\n");

#elif Q_OS_MACOS
    //Mac
    this->setApp("zsh");
    this->setEndl("\n");
#endif
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



//void NewProjectDialog::btnBrowseProjectPath_clicked()
//{
//    if (ui->leEnterProjectName->text().isEmpty() || ui->leEnterProjectName->text().isNull()){
//        QMessageBox::warning(this, "No Project Name", "Please Enter a Project Name");
//        return;
//    }

//    QString filePath = QFileDialog::getExistingDirectory(this, ("Select Output Folder"), QDir::currentPath());

//    if (QDir(filePath+"/"+ui->leEnterProjectName->text()).exists()){
//        QMessageBox::StandardButton reply = QMessageBox::question(this, "Already Exist", "Project Name Already Exist... \n Did you want to override the project?");
//        if (reply == QMessageBox::No){
//            return;
//        }
//        else{
//            QDir dir(filePath+"/"+ui->leEnterProjectName->text());
//            dir.removeRecursively();
//        }
//    }
//    ui->leEnterProjectPath->setText(filePath);

//    if (ui->leEnterProjectPath->text().isNull() || ui->leEnterProjectPath->text().isEmpty()){
//        ui->btnBrowseProjectData->setEnabled(false);
//    }
//    else  ui->btnBrowseProjectData->setEnabled(true);

//}


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
    // mdb format
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
    // euxml format
    else if (ui->fileFormatComboBox->currentText() == ".euxml"){
        fileName = QFileDialog::getOpenFileName(this, "Add File", "", "(*.euxml)" );
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
    QDir().mkpath(location+"/temp2");

    if (ui->fileFormatComboBox->currentText() == ".json"){
        foreach (QString fileName, fileNames){
            QStringList each = fileName.split(QRegularExpression("/"));
            /* Naming Convention
              "Entwurfselement_HO.(extension)"
              "Entwurfselement_KM.(extension)"
              "Entwurfselement_LA.(extension)"
              "Entwurfselement_UH.(extension)"
              "Gleiskanten.(extension)"
              "Gleisknoten.(extension)"*/

            QFile file (fileName);
            QFileInfo info (fileName);
            if (!file.open(QIODevice::ReadOnly)){
                QMessageBox::warning(this, "Warning", file.errorString());
                return;
            }
//            file.close();
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
                msg.append(current +" successfully updated \n");
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
        file.close();

        QString current = each.back().remove("."+info.completeSuffix());

        QString fileToSave = ui->leEnterProjectPath->text()+"/"+ui->leEnterProjectName->text() +"/temp/" + current+".MDB";
        if (!QFile::copy(fileName,fileToSave)){
            QMessageBox::information(this, "Fatal!", "Problem accessing your file");
            return;
        }

        msg.append(current +" successfully updated \n");
    }

    else if (ui->fileFormatComboBox->currentText() == ".euxml"){

        QStringList each = fileName.split(QRegularExpression("/"));
        QFile file (fileName);
        QFileInfo info (fileName);

        if (!file.open(QIODevice::ReadOnly)){
            QMessageBox::warning(this, "Warning", file.errorString());
            return;
        }
        file.close();
        QString current = each.back().remove("."+info.completeSuffix());

        QString fileToSave = ui->leEnterProjectPath->text()+"/"+ui->leEnterProjectName->text() +"/temp/" + current+".euxml";
        if (!QFile::copy(fileName,fileToSave)){
            QMessageBox::information(this, "Fatal!", "Problem accessing your input file");
            return;
        }

        if (!QFile::exists(fileToSave)){
            QMessageBox::information(this, "Missing File", "Required file Missing... \n Please import appropriate file");
            return;
        }

        // Start the A-Plan Core application through network process (QProcess)

        QProcess csharp;
        findOS();   //determine the operating system

        QByteArray state = "read";
        QByteArray euFilePath = fileToSave.toUtf8();
        QByteArray outputFoler = ui->leEnterProjectPath->text().toLatin1() +"/"+ui->leEnterProjectName->text().toLatin1() +"/temp2";

        // replace this with corresponding filepath when necessary
        QString filePath = "APLAN-CORE.exe";
        csharp.start(filePath);

        if(!csharp.waitForStarted(3000)) {
            QMessageBox::warning(this, "Warning", "Problem opening APlan_Core App \n ... "
                                                  "some linking file(s) are missing. Please contact your administrator");
            return;
        }

        // write data(each parameter) to the terminal, followed by Enter key
        if(!state.endsWith(endl.toLatin1())) state.append(endl.toUtf8());
        csharp.write(state);
        csharp.waitForBytesWritten(1000);

        if(!euFilePath.endsWith(endl.toLatin1())) euFilePath.append(endl.toUtf8());
        csharp.write(euFilePath);
        csharp.waitForBytesWritten(1000);

        if(!outputFoler.endsWith(endl.toLatin1())) outputFoler.append(endl.toUtf8());
        csharp.write(outputFoler);
        csharp.waitForBytesWritten(1000);

        csharp.closeWriteChannel();
        if(!csharp.waitForFinished(10000)) {
            // Giving maximum of 10 seconds to execute the program
            qInfo() << "The program is taking too long to close the Channel";
            QMessageBox::warning(this, "Warning", "The program is taking too long to execute\n ... "
                                                  "the channel has been terminated");
            return;
        }

        QString unprocessedFilePath = ui->leEnterProjectPath->text() + "/" + ui->leEnterProjectName->text() + "/temp2/UnprocessedJson.json";

        if (!QFile::exists(unprocessedFilePath)){
            QMessageBox::information(this, "Missing File", "Process Aborted !! ");
            return;
        }
//        QFile unprocessedFile (unprocessedFilePath);
        // Create paths to store the internally-used generated files
        QString kantenPath = ui->leEnterProjectPath->text() + "/" + ui->leEnterProjectName->text() + "/temp2/Gleiskanten.json";
        QString lagePath = ui->leEnterProjectPath->text() + "/" + ui->leEnterProjectName->text() + "/temp2/Entwurfselement_LA.json";
        QString hoPath = ui->leEnterProjectPath->text() + "/" + ui->leEnterProjectName->text() + "/temp2/Entwurfselement_HO.json";
        QString uhPath = ui->leEnterProjectPath->text() + "/" + ui->leEnterProjectName->text() + "/temp2/Entwurfselement_UH.json";
        QString knotenPath = ui->leEnterProjectPath->text() + "/" + ui->leEnterProjectName->text() + "/temp2/Gleisknoten.json";
        QString kmPath = ui->leEnterProjectPath->text() + "/" + ui->leEnterProjectName->text() + "/temp2/Entwurfselement_KM.json";

        GleiskantenFromUnprocessedJson *tryKanten = new GleiskantenFromUnprocessedJson(nullptr, unprocessedFilePath, kantenPath);
        LageFromUnprocessedJson * tryLage = new LageFromUnprocessedJson (nullptr, unprocessedFilePath, lagePath);
        HOFromUnprocessedJson * tryHO = new HOFromUnprocessedJson(nullptr, unprocessedFilePath, hoPath);
        UberhohungFromUnprocessedJson * tryUH = new UberhohungFromUnprocessedJson(nullptr, unprocessedFilePath, uhPath);
        GleisknotenFromUnprocessedJson *tryKnoten = new GleisknotenFromUnprocessedJson(nullptr, unprocessedFilePath, knotenPath);
        KmLinieFromUnprocessedJson *tryKmLinie = new KmLinieFromUnprocessedJson (nullptr, unprocessedFilePath, kmPath);

        qDebug() << "Start : " << QTime::currentTime();
        tryKanten->createJson();
        qDebug() << "KantenDone : " << QTime::currentTime();
        tryLage->createJson();
        qDebug() << "LageDone : " << QTime::currentTime();
        tryHO->createJson();
        qDebug() << "HODone : " << QTime::currentTime();
        tryUH->createJson();
        qDebug() << "UHDone : " << QTime::currentTime();
        tryKnoten->createJson();
        qDebug() << "KnotenDone : " << QTime::currentTime();
        tryKmLinie->createJson();
        qDebug() << "KMDone : " << QTime::currentTime();



        QString tempFolder = ui->leEnterProjectPath->text()+"/"+ui->leEnterProjectName->text()+"/temp2";
        QDir dir (tempFolder);
        QFileInfoList files = dir.entryInfoList(QDir::Files);

        foreach(QFileInfo fi, files){
            QString file_name = fi.fileName();
            QFile file (fi.filePath());

            if (!file.open(QIODevice::ReadOnly)){
                QMessageBox::warning(this, "Warning", file.errorString());
                return;
            }
            QString current = file_name.remove(".json");
            if (current == "Entwurfselement_HO" || current == "Entwurfselement_KM" || current == "Entwurfselement_LA" ||
                     current == "Entwurfselement_UH" || current == "Gleiskanten" || current == "Gleisknoten"){
                QString allData = file.readAll();

                // create a .dbahn file corresponding to the json file into the saving folder
                QFile fileToSave  (ui->leEnterProjectPath->text()+"/"+ui->leEnterProjectName->text() +"/temp/" + current+".dbahn");
                if (!fileToSave.open(QIODevice::WriteOnly)){
                    QMessageBox::warning(this, "Warning", fileToSave.errorString());
                    return;
                }
                QByteArray bytes(allData.toUtf8());
                QByteArray encoded = bytes.toHex();
                fileToSave.write(encoded);
                fileToSave.close();
            }
            file.close();
        }


//        QString tempFolder = ui->leEnterProjectPath->text()+"/"+ui->leEnterProjectName->text()+"/temp2";
//        QDir dir (tempFolder);
//        QFileInfoList files = dir.entryInfoList(QDir::Files);

//        foreach(QFileInfo fi, files){
//            QString file = fi.fileName();
//            QString current = file.remove(".json");
//            QFile file1 (ui->leEnterProjectPath->text()+"/"+ui->leEnterProjectName->text()+"/temp2/"+file);
//            if (!file1.open(QIODevice::ReadOnly)){
//                QMessageBox::warning(this, "Warning", file1.errorString());
//                return;
//            }
//            if (current == "Entwurfselement_HO" || current == "Entwurfselement_KM" || current == "Entwurfselement_LA" ||
//                    current == "Entwurfselement_UH" || current == "Gleiskanten" || current == "Gleisknoten"){

//                QString allData = file1.readAll();
//                file1.close();

//                // create a .dbahn file corresponding to the json file into the saving folder
//                QFile fileToSave (ui->leEnterProjectPath->text()+"/"+ui->leEnterProjectName->text() +"/temp/" + current+".dbahn");

//                if (!fileToSave.open(QIODevice::WriteOnly)){
//                    QMessageBox::warning(this, "Warning", fileToSave.errorString());
//                    return;
//                }
//                QByteArray bytes(allData.toUtf8());
//                QByteArray encoded = bytes.toHex();
//                fileToSave.write(encoded);
//                fileToSave.close();
//            }

//        }
        msg.append(current +" successfully updated \n");
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

const QString &NewProjectDialog::getEndl() const
{
    return endl;
}

void NewProjectDialog::setEndl(const QString &newEndl)
{
    endl = newEndl;
}

const QString &NewProjectDialog::getApp() const
{
    return app;
}

void NewProjectDialog::setApp(const QString &newApp)
{
    app = newApp;
}
