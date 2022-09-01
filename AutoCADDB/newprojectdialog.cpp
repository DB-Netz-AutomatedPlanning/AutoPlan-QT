#include "newprojectdialog.h"
#include "ui_newprojectdialog.h"
#include "mainwindow.h"
#include "symbolcontainer.h"
#include "gleiskantenfromunprocessedjson.h"
#include "gleisknotenfromunprocessedjson.h"
#include "kmliniefromunprocessedjson.h"
#include "hofromunprocessedjson.h"
#include "uberhohungfromunprocessedjson.h"
#include "lagefromunprocessedjson.h"
#include "signalfromunprocessedjson.h"
#include "readeulynxsignals.h"
#include "xml2json.h"
#include "planproelements.h"
#include <QPushButton>
#include<QSysInfo>
#include <QDir>
#include <QDirIterator>
#include <QtConcurrent>
#include <QFuture>
#include <QProgressDialog>


NewProjectDialog::NewProjectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProjectDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Create New Project");
    ui->leEnterProjectPath->setPlaceholderText("Add a folder to save the project");
    ui->leImportProjectData->setPlaceholderText("Include your project data");

//    timer.setInterval(3000);

    //    connect (ui->btnBrowseProjectPath , & QPushButton::clicked, this, & NewProjectDialog::btnBrowseProjectPath_clicked);

    progress = new QProgressDialog("Operation in progress ...", "Cancel", 0, 8, this);
    progressValue =1;
    progress->move(-10000,-10000);

//    connect(&timer, &QTimer::timeout, this, &NewProjectDialog::timeout, Qt::QueuedConnection);

//    timer.start();
}

// Destructor
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
        fileName = QFileDialog::getOpenFileName(this, "Add File", "", "(*.euxml *.xml)" );
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

    // ppxml format
    else if (ui->fileFormatComboBox->currentText() == ".ppxml"){
        fileName = QFileDialog::getOpenFileName(this, "Add File", "", "(*.ppxml)" );
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
        progress->move(550,275);

        progress->setWindowModality(Qt::WindowModal);
        progress->setWindowTitle("Please wait ...");
        progress->setValue(progressValue);

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
        csharp = new QProcess(this);
        findOS();   //determine the operating system

        QByteArray state = "read";
        QByteArray euFilePath = fileToSave.toUtf8();
        QByteArray outputFoler = ui->leEnterProjectPath->text().toLatin1() +"/"+ui->leEnterProjectName->text().toLatin1() +"/temp2";

        // replace this with corresponding filepath when necessary
        QString filePath = "APLAN-CORE.exe";
        csharp->start(filePath);

        if(!csharp->waitForStarted(3000)) {
            QMessageBox::warning(this, "Warning", "Problem opening APlan_Core App \n ... "
                                                  "some linking file(s) are missing. Please contact your administrator");
            return;
        }
        // write data(each parameter) to the terminal, followed by Enter key
        if(!state.endsWith(endl.toLatin1())) state.append(endl.toUtf8());
        csharp->write(state);
        csharp->waitForBytesWritten(1000);

        if(!euFilePath.endsWith(endl.toLatin1())) euFilePath.append(endl.toUtf8());
        csharp->write(euFilePath);
        csharp->waitForBytesWritten(1000);

        if(!outputFoler.endsWith(endl.toLatin1())) outputFoler.append(endl.toUtf8());
        csharp->write(outputFoler);
        csharp->waitForBytesWritten(1000);

        csharp->closeWriteChannel();
        csharp->waitForFinished();
//        if(!csharp.waitForFinished(10000)) {
//            // Giving maximum of 10 seconds to execute the program
//            qInfo() << "The program is taking too long to close the Channel";
//            QMessageBox::warning(this, "Warning", "The program is taking too long to execute\n ... "
//                                                  "the channel has been terminated");
//            return;
//        }
        unprocessedFilePath = ui->leEnterProjectPath->text() + "/" + ui->leEnterProjectName->text() + "/temp2/UnprocessedJson.json";

        if (!QFile::exists(unprocessedFilePath)){
            QMessageBox::information(this, "Missing File", "Process Aborted !! ");
            return;
        }
        /*timer.start();*/ // Start the timer, so as to fire on the timeout() slot at every intervals as declared in the constructor

        /* Running all the six classes on seperate Thread with the aid of QtConcurrent, based on the
         * numbers of available thread(s) on the CPU at the particular time. Similarly QFuture allow
         * the output to be stored and give flexibility to asking the main thread to wait for output
         * from the other running thread*/

        // Create paths to store the internally-used generated files
        QString kantenPath = ui->leEnterProjectPath->text() + "/" + ui->leEnterProjectName->text() + "/temp2/Gleiskanten.json";
        QString lagePath = ui->leEnterProjectPath->text() + "/" + ui->leEnterProjectName->text() + "/temp2/Entwurfselement_LA.json";
        QString hoPath = ui->leEnterProjectPath->text() + "/" + ui->leEnterProjectName->text() + "/temp2/Entwurfselement_HO.json";
        QString uhPath = ui->leEnterProjectPath->text() + "/" + ui->leEnterProjectName->text() + "/temp2/Entwurfselement_UH.json";
        QString knotenPath = ui->leEnterProjectPath->text() + "/" + ui->leEnterProjectName->text() + "/temp2/Gleisknoten.json";
        QString kmPath = ui->leEnterProjectPath->text() + "/" + ui->leEnterProjectName->text() + "/temp2/Entwurfselement_KM.json";
        QString sigPath = ui->leEnterProjectPath->text() + "/" + ui->leEnterProjectName->text() + "/temp2/Signal.json";

        QFuture<void> kanten = QtConcurrent::run(runKanten, unprocessedFilePath, kantenPath);
        QFuture<void> lage = QtConcurrent::run(runLage, unprocessedFilePath, lagePath);
        QFuture<void> ho = QtConcurrent::run(runHO, unprocessedFilePath, hoPath);

        progress->setValue(progressValue);
        kanten.waitForFinished();
        progress->setValue(progressValue);
        lage.waitForFinished();
        progress->setValue(progressValue);
        ho.waitForFinished();

        // If the user decided to cancel the progress mid-way, remove the created project, and return;
        if (progress->wasCanceled()){
            QMessageBox::StandardButton reply = QMessageBox::question(this, "Cancellation detected !!", "Are you sure? \n This will reverse any already processed data...");
            if (reply == QMessageBox::Yes){
                QDir dir(ui->leEnterProjectPath->text()+"/"+ui->leEnterProjectName->text());
                dir.removeRecursively();
                return;
            }
        }
        QFuture<void> sig = QtConcurrent::run(runSignal, unprocessedFilePath, sigPath);
        QFuture<void> uh = QtConcurrent::run(runUH, unprocessedFilePath, uhPath);
        QFuture<void> knoten = QtConcurrent::run(runKnoten, unprocessedFilePath, knotenPath);
        QFuture<void> km = QtConcurrent::run(runKMLinie, unprocessedFilePath, kmPath);
        progress->setValue(progressValue);
        sig.waitForFinished();
        progress->setValue(progressValue);
        uh.waitForFinished();
        progress->setValue(progressValue);
        knoten.waitForFinished();
        progress->setValue(progressValue);
        km.waitForFinished();
        progress->setValue(progressValue);

        if (progress->wasCanceled()){
            QMessageBox::StandardButton reply = QMessageBox::question(this, "Cancellation detected !!", "Are you sure? \n This will reverse any already processed data...");
            if (reply == QMessageBox::Yes){
                QDir dir(ui->leEnterProjectPath->text()+"/"+ui->leEnterProjectName->text());
                dir.removeRecursively();
                close();
                return;
            }
        }
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
                    current == "Entwurfselement_UH" || current == "Gleiskanten" || current == "Gleisknoten"  || current == "Signal"){
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
        msg.append(current +" successfully updated \n");
    }


    else if (ui->fileFormatComboBox->currentText() == ".ppxml") {

        QStringList each = fileName.split(QRegularExpression("/"));
        QFile file (fileName);
        QFileInfo info (fileName);

        if (!file.open(QIODevice::ReadOnly)){
            QMessageBox::warning(this, "Warning", file.errorString());
            return;
        }
        file.close();
        QString current = each.back().remove("."+info.completeSuffix());
        QString output = ui->leEnterProjectPath->text() +"/"+ ui->leEnterProjectName->text() +"/temp2/planPro.json";

        Xml2Json *json = new Xml2Json(nullptr, fileName, output);
        json->serializeXml2Json();

//        projectPath = "D:/Users/BKU/OlatunjiAjala/Documents";
//        projectName = "output";
        QString kantenPath = ui->leEnterProjectPath->text() + "/" + ui->leEnterProjectName->text() + "/temp2/Gleiskanten.json";
        QString knotenPath = ui->leEnterProjectPath->text() + "/" + ui->leEnterProjectName->text() + "/temp2/Gleisknoten.json";

        PlanProElements *pp = new PlanProElements(nullptr, kantenPath, knotenPath);
        pp->createJson();
        pp->createKnotenJson();

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
                    current == "Entwurfselement_UH" || current == "Gleiskanten" || current == "Gleisknoten"  || current == "Signal"){
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
        if (ui->fileFormatComboBox->currentText() == ".euxml" && (numberOfFileProduces() <= 0)) {
            QMessageBox::information(this, "No useful data detected !", "input data did not contain any useful/valid information... \n Please review your input");
            close();
            return;
        }
        QMessageBox::information(this, "Successfull", allMsg);
        // set Important global parameters
        projectPath = ui->leEnterProjectPath->text();
        projectName = ui->leEnterProjectName->text();
        fileFormat = ui->fileFormatComboBox->currentText();
        countryCode = ui->countryCodeComboBox->currentText();
        createNewProject = true;
        close();
        return;
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

int NewProjectDialog::numberOfFileProduces()
{
    int num = 0;   // the folder will contain one file by default
    QString tempFolder = ui->leEnterProjectPath->text()+"/"+ui->leEnterProjectName->text()+"/temp";
    QDir dir (tempFolder);
    QFileInfoList files = dir.entryInfoList(QDir::Files);
    foreach(QFileInfo fi, files){

        QString file_name = fi.fileName();

        QString current = file_name.remove(".dbahn");
        if (current == "Entwurfselement_HO" || current == "Entwurfselement_KM" || current == "Entwurfselement_LA" ||
                current == "Entwurfselement_UH" || current == "Gleiskanten" || current == "Gleisknoten"){
        qDebug()<< "Num: "<< num;
        num++;
        }
    }
    return num;
}

//void NewProjectDialog::setProgressValue()
//{
//    if(progressValue <= 7){
//        progress->setValue(progressValue);
//    }
//    else {
//        qDebug()<< "PROGRESS Complete";
//        return;
//    }
//    setProgressValue();
//}

//void NewProjectDialog::getProgressValue(bool is_EuXml, int progress_Value)
//{
//    QProgressDialog * progress1 = new QProgressDialog("Operation in progress ...", "Cancel", 0, 7);
//    progress1->setWindowModality(Qt::WindowModal);

//    while(is_EuXml && progressValue <= 7){
//        progress1->setValue(progress_Value);
//        if (progress1->wasCanceled()) break;
//    }
//    qDebug()<< "PROGRESS Complete";
//    //progress.setValue(7);
//}


void NewProjectDialog::runKanten(QString unprocessed_File_Path, QString kanten_Path)
{
    GleiskantenFromUnprocessedJson *tryKanten = new GleiskantenFromUnprocessedJson(nullptr, unprocessed_File_Path, kanten_Path);
    qDebug() << "Start : " << QTime::currentTime();
    tryKanten->createJson();
}

void NewProjectDialog::runLage(QString unprocessed_File_Path, QString lage_Path)
{
    LageFromUnprocessedJson * tryLage = new LageFromUnprocessedJson (nullptr, unprocessed_File_Path, lage_Path);
    qDebug() << "Start : " << QTime::currentTime();
    tryLage->createJson();
}

void NewProjectDialog::runHO(QString unprocessed_File_Path, QString ho_Path)
{
    HOFromUnprocessedJson * tryHO = new HOFromUnprocessedJson(nullptr, unprocessed_File_Path, ho_Path);
    qDebug() << "Start : " << QTime::currentTime();
    tryHO->createJson();
}

void NewProjectDialog::runUH(QString unprocessed_File_Path, QString uh_Path)
{
    UberhohungFromUnprocessedJson * tryUH = new UberhohungFromUnprocessedJson(nullptr, unprocessed_File_Path, uh_Path);
    qDebug() << "Start : " << QTime::currentTime();
    tryUH->createJson();
}

void NewProjectDialog::runKnoten(QString unprocessed_File_Path, QString knoten_Path)
{
    GleisknotenFromUnprocessedJson *tryKnoten = new GleisknotenFromUnprocessedJson(nullptr, unprocessed_File_Path, knoten_Path);
    qDebug() << "Start : " << QTime::currentTime();
    tryKnoten->createJson();
}

void NewProjectDialog::runKMLinie(QString unprocessed_File_Path, QString km_Path)
{
    KmLinieFromUnprocessedJson *tryKmLinie = new KmLinieFromUnprocessedJson (nullptr, unprocessed_File_Path, km_Path);
    qDebug() << "Start : " << QTime::currentTime();
    tryKmLinie->createJson();
}

void NewProjectDialog::runSignal(QString unprocessed_File_Path, QString sig_Path)
{
    SignalFromUnprocessedJson *trySignal = new SignalFromUnprocessedJson(nullptr, unprocessed_File_Path, sig_Path);
    qDebug() << "Start : " << QTime::currentTime();
    trySignal->createSignalJson();
}

// Update progress value every 5000 milliseconds
void NewProjectDialog::timeout()
{
    if(progressValue <= 8){
        progress->setValue(progressValue);
        qDebug() << "Progress : "<< progressValue;
    }
    else {
        timer.stop();
        qDebug()<< "PROGRESS Complete";
    }
}


const QString &NewProjectDialog::getApp() const
{
    return app;
}

void NewProjectDialog::setApp(const QString &newApp)
{
    app = newApp;
}
