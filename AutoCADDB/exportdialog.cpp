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
    QDirIterator iter( "Data", QDir::Dirs | QDir::NoDotAndDotDot);
    while(iter.hasNext() )
    {
        QString val = iter.next();
        ui->cmbStation->addItem(val.remove("Data/"));
    }
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
    QString station_ = ui->cmbStation->currentText();
    QByteArray state = "export";
    QByteArray gleiskantenPath = "Data/"+ui->cmbStation->currentText().toLatin1()+"/Gleiskanten.geojson";
    QByteArray gleisknotenPath = "Data/"+ui->cmbStation->currentText().toLatin1()+ "/Gleisknoten.geojson";
    QByteArray hoehePath = "Data/"+ui->cmbStation->currentText().toLatin1()+ "/Entwurfselement_HO.geojson";
    QByteArray kMliniePath = "Data/"+ui->cmbStation->currentText().toLatin1()+ "/Entwurfselement_KM.geojson";
    QByteArray uberholenPath = "Data/"+ui->cmbStation->currentText().toLatin1()+ "/Entwurfselement_UH.geojson";
    QByteArray lagePath = "Data/"+ui->cmbStation->currentText().toLatin1()+ "/Entwurfselement_LA.geojson";
    QByteArray outputPath = ui->leFolder->text().toLatin1();
    QByteArray station = ui->cmbStation->currentText().toLatin1();
    if (!QFile::exists(gleiskantenPath) || !QFile::exists(gleisknotenPath) || !QFile::exists(hoehePath) || !QFile::exists(kMliniePath)
            || !QFile::exists(uberholenPath) || !QFile::exists(lagePath)){
        QMessageBox::information(this, "Missing File", "Required file Missing... \n Please import appropriate files");
        return;
    }
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

    if(!gleiskantenPath.endsWith(endl.toLatin1())) gleiskantenPath.append(endl.toUtf8());
    csharp.write(gleiskantenPath);
    csharp.waitForBytesWritten(1000);

    if(!gleisknotenPath.endsWith(endl.toLatin1())) gleisknotenPath.append(endl.toUtf8());
    csharp.write(gleisknotenPath);
    csharp.waitForBytesWritten(1000);

    if(!hoehePath.endsWith(endl.toLatin1())) hoehePath.append(endl.toUtf8());
    csharp.write(hoehePath);
    csharp.waitForBytesWritten(1000);

    if(!kMliniePath.endsWith(endl.toLatin1())) kMliniePath.append(endl.toUtf8());
    csharp.write(kMliniePath);
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

    if(!station.endsWith(endl.toLatin1())) station.append(endl.toUtf8());
    csharp.write(station);
    csharp.waitForBytesWritten(1000);

    csharp.closeWriteChannel();
    if(!csharp.waitForFinished(10000)) {
        // Giving maximum of 6 seconds to execute the program
        qInfo() << "The program is taking too long to close the Channel";
        QMessageBox::warning(this, "Warning", "The program is taking too long to execute\n ... "
                                              "the channel has been terminated before conversion");
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

// PreviewEulynxXml preXml;
// preXml.setModal(true);
//preXml.exec();
