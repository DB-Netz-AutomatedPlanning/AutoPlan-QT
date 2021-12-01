#include "exportdialog.h"
#include "ui_exportdialog.h"
#include "ui_previeweulynxxml.h"
#include "previeweulynxxml.h"
#include "symbolcontainer.h"

ExportDialog::ExportDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExportDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Export file");
    //QDirIterator iter( "Data", QDir::Dirs | QDir::NoDotAndDotDot);
    //    QDirIterator iter( projectPath+"/"+projectName, QDir::Dirs | QDir::NoDotAndDotDot);  //+"/temp"
    //    while(iter.hasNext() )
    //    {
    //        QString val = iter.next();
    //        ui->cmbStation->addItem(val.remove(projectPath+"/"+projectName+"/"));  //temp/
    //    }
    ui->cmbStation->addItem(projectName);
    ui->cmbStation->setCurrentText(projectName);
    if(!ui->cmbStation->currentText().isNull() && !ui->cmbStation->currentText().isEmpty()){
        ui->leFolder->setEnabled(true);
        ui->btnOpenFolder->setEnabled(true);
    }
}


ExportDialog::~ExportDialog()
{
    delete ui;
}


void ExportDialog::findOS()
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

void ExportDialog::waitToFinish(int miliSeconds)
{
    QElapsedTimer timer;
    timer.start();
    while (timer.elapsed() < miliSeconds){
        QCoreApplication::processEvents();
    }
}


void ExportDialog::on_btnOpenFolder_clicked()
{
    QString filePath = QFileDialog::getExistingDirectory(this, ("Select Output Folder"), QDir::currentPath());
    ui->leFolder->setText(filePath);
    ui->btnExport->setEnabled(true);
    if (ui->leFolder->text().isNull() ||ui->leFolder->text().isEmpty()){
        ui->btnExport->setEnabled(false);
    }
}


void ExportDialog::on_btnExport_clicked()
{
    if (!QDir(ui->leFolder->text()).exists()){
        QMessageBox::warning(this, "Information", "Invalid folder selected... \n Please use a valid folder");
        return;
    }
    QString outputPath_ = ui->leFolder->text();
    //    QString station_ = ui->cmbStation->currentText();
    QString station_ = projectName;
    QString path_ = projectPath;
    QByteArray state = "export";
    QByteArray code = countryCode.toUtf8();
    QByteArray format = fileFormat.toUtf8();
    QByteArray mdbPath;

    if (fileFormat== ".mdb"){
        QString dataPath = path_.toLatin1()+"/" +station_.toLatin1()+"/temp";
        QDir dir (dataPath);
        QFileInfoList files = dir.entryInfoList(QDir::Files);

        QByteArray outputPath = ui->leFolder->text().toLatin1();

        QByteArray station = ui->cmbStation->currentText().toLatin1();

        foreach (QFileInfo fi, files){
            if (fi.completeSuffix() == "mdb" || fi.completeSuffix() == "MDB"){
                mdbPath = fi.filePath().toUtf8();
//                qDebug()<< "NOW";
//                qDebug()<< "See Path: "<< mdbPath;
                break;
            }
        }

        if (!QFile::exists(mdbPath)){
            QMessageBox::information(this, "Missing File", "Required file Missing... \n Please import appropriate files");
            return;
        }

//        //        foreach (auto fi, filePaths){
//        QFile file (mdbPath);
//        QFileInfo info (mdbPath);
//        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
//            QMessageBox::information(this, "info", file.errorString());
//            return;
//        }

//        QString current = QString::fromUtf8(mdbPath).remove(path_+"/"+station_+"/temp/");
//        qDebug()<< "current:" << current;
//        current = current.remove("."+ info.completeSuffix());
//        qDebug()<< "current2:" << current;

//        QFile fileToSave (path_+"/"+station_+"/temp/"+current+".MDB");

//        if (!fileToSave.open(QIODevice::WriteOnly)){
//            QMessageBox::warning(this, "Warning", fileToSave.errorString());
//            return;
//        }

//        QByteArray data = file.readAll();
//        QByteArray decoded = QByteArray::fromHex(data);

//        //        QString allData;
//        //        allData = QString(decoded);
//        file.close();

//        fileToSave.write(decoded);
//        fileToSave.close();
//        //        }


//        mdbPath = (path_+"/"+station_+"/temp/"+current+".MDB").toUtf8();
//        qDebug()<< "Another mdbPath: " <<mdbPath;



        QProcess csharp;
        findOS();   //determine the operating system

        // replace this with corresponding filepath
        QString filePath = "APLAN-CORE.exe";
        csharp.start(filePath);

        if(!csharp.waitForStarted(3000)) {
            this->isAvailable = false;
            QMessageBox::warning(this, "Warning", "Problem opening APlan_Core App \n ... "
                                                  "some linking file(s) are missing. Please contact your administrator");
            return;
        }

        // write data(each parameter) to the terminal, followed by Enter key
        if(!state.endsWith(endl.toLatin1())) state.append(endl.toUtf8());
        csharp.write(state);
        csharp.waitForBytesWritten(1000);

        if(!code.endsWith(endl.toLatin1())) code.append(endl.toUtf8());
        csharp.write(code);
        csharp.waitForBytesWritten(1000);

        if(!format.endsWith(endl.toLatin1())) format.append(endl.toUtf8());
        csharp.write(format);
        csharp.waitForBytesWritten(1000);

        if(!station.endsWith(endl.toLatin1())) station.append(endl.toUtf8());
        csharp.write(station);
        csharp.waitForBytesWritten(1000);

        if(!mdbPath.endsWith(endl.toLatin1())) mdbPath.append(endl.toUtf8());
        csharp.write(mdbPath);
        csharp.waitForBytesWritten(1000);

        if(!outputPath.endsWith(endl.toLatin1())) outputPath.append(endl.toUtf8());
        csharp.write(outputPath);
        csharp.waitForBytesWritten(1000);

//        waitToFinish(10000);

        csharp.closeWriteChannel();
        if(!csharp.waitForFinished(15000)) {
            // Giving maximum of 15 seconds to execute the program
            qInfo() << "The program is taking too long to close the Channel";
            QMessageBox::warning(this, "Warning", "The program is taking too long to execute\n ... "
                                                  "the channel has been terminated after conversion");
            return;
        }

    }

    else if (fileFormat == ".json"){
        std::vector<QString> filePaths;
        QByteArray kMliniePath = path_.toLatin1()+"/" +station_.toLatin1()+"/temp/Entwurfselement_KM.dbahn";
        QByteArray gleiskantenPath =  path_.toLatin1()+"/" +station_.toLatin1()+"/temp/Gleiskanten.dbahn";
        QByteArray gleisknotenPath = path_.toLatin1()+"/" +station_.toLatin1()+"/temp/Gleisknoten.dbahn";
        QByteArray hoehePath = path_.toLatin1()+"/" +station_.toLatin1()+"/temp/Entwurfselement_HO.dbahn";
        QByteArray uberholenPath = path_.toLatin1()+"/" +station_.toLatin1()+"/temp/Entwurfselement_UH.dbahn";
        QByteArray lagePath = path_.toLatin1()+"/" +station_.toLatin1()+"/temp/Entwurfselement_LA.dbahn";
        QByteArray outputPath = ui->leFolder->text().toLatin1();
        QByteArray station = ui->cmbStation->currentText().toLatin1();

        if (countryCode == "de"){
            if (!QFile::exists(gleiskantenPath) || !QFile::exists(gleisknotenPath) || !QFile::exists(hoehePath) || !QFile::exists(kMliniePath)
                    || !QFile::exists(uberholenPath) || !QFile::exists(lagePath)){

                QMessageBox::information(this, "Missing File", "Required file Missing... \n Please import all appropriate files");
                return;
            }

            filePaths.push_back(gleiskantenPath);
            filePaths.push_back(gleisknotenPath);
            filePaths.push_back(hoehePath);
            filePaths.push_back(kMliniePath);
            filePaths.push_back(uberholenPath);
            filePaths.push_back(lagePath);

            foreach (auto fi, filePaths){
                QFile file (fi);
                QFileInfo info (fi);
                if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
                    QMessageBox::information(this, "info", file.errorString());
                    return;
                }

                QString current = fi.remove(path_+"/"+station_+"/temp/");
                current = current.remove("."+ info.completeSuffix());

                QFile fileToSave (path_+"/"+station_+"/temp/"+current+".geojson");


                if (!fileToSave.open(QIODevice::WriteOnly)){
                    QMessageBox::warning(this, "Warning", fileToSave.errorString());
                    return;
                }

                QByteArray data = file.readAll();
                QByteArray decoded = QByteArray::fromHex(data);
                file.close();

                fileToSave.write(decoded);
                fileToSave.close();
            }
            kMliniePath = path_.toLatin1()+"/" +station_.toLatin1()+"/temp/Entwurfselement_KM.geojson";
            gleiskantenPath =  path_.toLatin1()+"/" +station_.toLatin1()+"/temp/Gleiskanten.geojson";
            gleisknotenPath = path_.toLatin1()+"/" +station_.toLatin1()+"/temp/Gleisknoten.geojson";
            hoehePath = path_.toLatin1()+"/" +station_.toLatin1()+"/temp/Entwurfselement_HO.geojson";

            uberholenPath = path_.toLatin1()+"/" +station_.toLatin1()+"/temp/Entwurfselement_UH.geojson";
            lagePath = path_.toLatin1()+"/" +station_.toLatin1()+"/temp/Entwurfselement_LA.geojson";

            QProcess csharp;
            findOS();   //determine the operating system

            // replace this with corresponding filepath
            QString filePath = "APLAN-CORE.exe";
            csharp.start(filePath);
            if(!csharp.waitForStarted(3000)) {
                this->isAvailable = false;
                QMessageBox::warning(this, "Warning", "Problem opening APlan_Core App \n ... "
                                                      "some linking file(s) are missing. Please contact your administrator");
                return;
            }

            // write data(each parameter) to the terminal, followed by Enter key
            if(!state.endsWith(endl.toLatin1())) state.append(endl.toUtf8());
            csharp.write(state);
            csharp.waitForBytesWritten(1000);

            if(!code.endsWith(endl.toLatin1())) code.append(endl.toUtf8());
            csharp.write(code);
            csharp.waitForBytesWritten(1000);

            if(!format.endsWith(endl.toLatin1())) format.append(endl.toUtf8());
            csharp.write(format);
            csharp.waitForBytesWritten(1000);

            if(!station.endsWith(endl.toLatin1())) station.append(endl.toUtf8());
            csharp.write(station);
            csharp.waitForBytesWritten(1000);

            if(!kMliniePath.endsWith(endl.toLatin1())) kMliniePath.append(endl.toUtf8());
            csharp.write(kMliniePath);
            csharp.waitForBytesWritten(1000);

            if(!gleiskantenPath.endsWith(endl.toLatin1())) gleiskantenPath.append(endl.toUtf8());
            csharp.write(gleiskantenPath);
            csharp.waitForBytesWritten(1000);

            if(!gleisknotenPath.endsWith(endl.toLatin1())) gleisknotenPath.append(endl.toUtf8());
            csharp.write(gleisknotenPath);
            csharp.waitForBytesWritten(1000);

            if(!hoehePath.endsWith(endl.toLatin1())) hoehePath.append(endl.toUtf8());
            csharp.write(hoehePath);
            csharp.waitForBytesWritten(1000);

            if(!uberholenPath.endsWith(endl.toLatin1())) uberholenPath.append(endl.toUtf8());
            csharp.write(uberholenPath);
            csharp.waitForBytesWritten(1000);

            if(!lagePath.endsWith(endl.toLatin1())) lagePath.append(endl.toUtf8());
            csharp.write(lagePath);
            csharp.waitForBytesWritten(1000);

            if(!outputPath.endsWith(endl.toLatin1())) outputPath.append(endl.toUtf8());
            csharp.write(outputPath);
            csharp.waitForBytesWritten(1000);

            csharp.closeWriteChannel();
            if(!csharp.waitForFinished(15000)) {
                // Giving maximum of 15 seconds to execute the program
                qInfo() << "The program is taking too long to close the Channel";
                QMessageBox::warning(this, "Warning", "The program is taking too long to execute\n ... "
                                                      "the channel has been terminated after conversion");
                return;
            }

            // remove all the input files
            gleiskantenPath =  path_.toLatin1()+"/" +station_.toLatin1()+"/temp/Gleiskanten.geojson";
            gleisknotenPath = path_.toLatin1()+"/" +station_.toLatin1()+"/temp/Gleisknoten.geojson";
            hoehePath = path_.toLatin1()+"/" +station_.toLatin1()+"/temp/Entwurfselement_HO.geojson";
            kMliniePath = path_.toLatin1()+"/" +station_.toLatin1()+"/temp/Entwurfselement_KM.geojson";
            uberholenPath = path_.toLatin1()+"/" +station_.toLatin1()+"/temp/Entwurfselement_UH.geojson";
            lagePath = path_.toLatin1()+"/" +station_.toLatin1()+"/temp/Entwurfselement_LA.geojson";
            std::vector<QString> paths;
            paths.push_back(gleiskantenPath);
            paths.push_back(gleisknotenPath);
            paths.push_back(hoehePath);
            paths.push_back(kMliniePath);
            paths.push_back(uberholenPath);
            paths.push_back(lagePath);

            foreach(QString val, paths){
                QFile file (val);
                file.remove();
            }

        }
        else if (countryCode == "fr"){
            if (!QFile::exists(gleiskantenPath)){
                QMessageBox::information(this, "Missing File", "Required file Missing... \n Please import all appropriate files");
                return;
            }
            filePaths.push_back(gleiskantenPath);

            foreach (auto fi, filePaths){
                QFile file (fi);
                QFileInfo info (fi);
                if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
                    QMessageBox::information(this, "info", file.errorString());
                    return;
                }

                QString current = fi.remove(path_+"/"+station_+"/temp/");
                current = current.remove("."+ info.completeSuffix());

                QFile fileToSave (path_+"/"+station_+"/temp/"+current+".geojson");
                if (!fileToSave.open(QIODevice::WriteOnly)){
                    QMessageBox::warning(this, "Warning", fileToSave.errorString());
                    return;
                }
                QByteArray data = file.readAll();
                QByteArray decoded = QByteArray::fromHex(data);
                file.close();

                fileToSave.write(decoded);
                fileToSave.close();
            }
            QByteArray empty = "";
            gleiskantenPath =  path_.toLatin1()+"/" +station_.toLatin1()+"/temp/Gleiskanten.geojson";

            QProcess csharp;
            findOS();   //determine the operating system

            // replace this with corresponding filepath
            QString filePath = "APLAN-CORE.exe";
            csharp.start(filePath);
            if(!csharp.waitForStarted(3000)) {
                this->isAvailable = false;
                QMessageBox::warning(this, "Warning", "Problem opening APlan_Core App \n ... "
                                                      "some linking file(s) are missing. Please contact your administrator");
                return;
            }

            // write data(each parameter) to the terminal, followed by Enter key
            if(!state.endsWith(endl.toLatin1())) state.append(endl.toUtf8());
            csharp.write(state);
            csharp.waitForBytesWritten(1000);

            if(!code.endsWith(endl.toLatin1())) code.append(endl.toUtf8());
            csharp.write(code);
            csharp.waitForBytesWritten(1000);

            if(!format.endsWith(endl.toLatin1())) format.append(endl.toUtf8());
            csharp.write(format);
            csharp.waitForBytesWritten(1000);

            if(!station.endsWith(endl.toLatin1())) station.append(endl.toUtf8());
            csharp.write(station);
            csharp.waitForBytesWritten(1000);

            if(!empty.endsWith(endl.toLatin1())) empty.append(endl.toUtf8());
            csharp.write(empty);
            csharp.waitForBytesWritten(1000);

            if(!gleiskantenPath.endsWith(endl.toLatin1())) gleiskantenPath.append(endl.toUtf8());
            csharp.write(gleiskantenPath);
            csharp.waitForBytesWritten(1000);

            if(!empty.endsWith(endl.toLatin1())) empty.append(endl.toUtf8());
            csharp.write(empty);
            csharp.waitForBytesWritten(1000);

            if(!empty.endsWith(endl.toLatin1())) empty.append(endl.toUtf8());
            csharp.write(empty);
            csharp.waitForBytesWritten(1000);

            if(!empty.endsWith(endl.toLatin1())) empty.append(endl.toUtf8());
            csharp.write(empty);
            csharp.waitForBytesWritten(1000);

            if(!empty.endsWith(endl.toLatin1())) empty.append(endl.toUtf8());
            csharp.write(empty);
            csharp.waitForBytesWritten(1000);

            if(!outputPath.endsWith(endl.toLatin1())) outputPath.append(endl.toUtf8());
            csharp.write(outputPath);
            csharp.waitForBytesWritten(1000);

            csharp.closeWriteChannel();
            if(!csharp.waitForFinished(15000)) {
                // Giving maximum of 15 seconds to execute the program
                qInfo() << "The program is taking too long to close the Channel";
                QMessageBox::warning(this, "Warning", "The program is taking too long to execute\n ... "
                                                      "the channel has been terminated after conversion");
                return;
            }

            // remove all the input files
            gleiskantenPath =  path_.toLatin1()+"/" +station_.toLatin1()+"/temp/Gleiskanten.geojson";
            QFile file (gleiskantenPath);
            file.remove();
        }

    }
    else {

        QMessageBox::warning(this, "Warning", "Only .json/geojson and .mdb data format is acceptable");
        return;
    }




    if (QFile::exists(outputPath_+"/eulynx"+station_+".euxml")){
        QMessageBox::information(this, "Successful", "EulynxXML Successfully Generated...\n"
                                                     "check ->"+outputPath_);
        folderPath = outputPath_;
        stationLocation = station_;

        PreviewEulynxXml preview;
        preview.setModal(true);
        preview.exec();
        close();
    }
    else{
        QMessageBox::warning(this, "Fatal", "Process Failed\n ... "
                                            "the channel has been terminated before conversion");
        close();
    }
}


const QString &ExportDialog::getEndl() const
{
    return endl;
}

void ExportDialog::setEndl(const QString &newEndl)
{
    endl = newEndl;
}

const QString &ExportDialog::getApp() const
{
    return app;
}

void ExportDialog::setApp(const QString &newApp)
{
    app = newApp;
}

void ExportDialog::on_cmbStation_currentTextChanged()
{
    ui->btnExport->setEnabled(false);
    ui->leFolder->clear();
}

void ExportDialog::on_btnCancel_clicked()
{
    close();
}
