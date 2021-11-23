#include "planningtable.h"
#include "ui_planningtable.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "myopenglwidget.h"
#include "symbolcontainer.h"

PlanningTable::PlanningTable(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlanningTable)
{
    ui->setupUi(this);

//    QDirIterator iter( "Data", QDir::Dirs | QDir::NoDotAndDotDot);
//    while(iter.hasNext())
//    {
//        QString val = iter.next();
//        ui->comboBoxStations->addItem(val.remove("Data/"));
//    }
    ui->comboBoxStations->addItem(projectName);

//    if (!ui->comboBoxStations->currentText().isEmpty() || !ui->comboBoxStations->currentText().isNull()){
//        QString location = ui->comboBoxStations->currentText();
//        QString path = "Data/"+location;
//        QDir dir (path);
//        QFileInfoList files = dir.entryInfoList(QDir::Files);
//        if  (files.length() ==0) {
//            QMessageBox::information(this, "No Data", "No Existing Data for the selected Station");
//            return;
//        }
//        foreach(QFileInfo fi, files){
//            ui->comboBoxSelectFile->addItem(fi.fileName());
//        }
//    }
}

PlanningTable::~PlanningTable()
{
    delete ui;
}


void PlanningTable::on_btnAutoPLAN_clicked()
{
    if (fileFormat == ".mdb"){
        QMessageBox::warning(this, "Warning", "Planning of .mdb data source/file was temporarily disabled");
        return;
    }

    if (!QDir(ui->lineEdit->text()).exists()){
        QMessageBox::warning(this, "Information", "Invalid folder selected... \n Please use a valid folder");
        ui->btnAutoPLAN->setEnabled(false);
        return;
    }


    if (ui->comboBoxStations->currentText().isNull() || ui->comboBoxStations->currentText().isEmpty()) {
        QMessageBox::warning(this, "Warning", "Unable to process ... \n Please create a project");
        ui->tableWidget->setEnabled(false);
        ui->btnAutoPLAN->setEnabled(false);
        ui->lblLocation->setEnabled(false);
        return;
    }
    else {

        QString location = ui->comboBoxStations->currentText();
        QString kmLinePath = projectPath+"/"+location+"/temp/Entwurfselement_KM.dbahn";

        QString gleiskantenPath = projectPath+"/"+location+"/temp/Gleiskanten.dbahn";
        QString gleisknotenPath = projectPath+"/"+location+"/temp/Gleisknoten.dbahn";
        QString hoehePath = projectPath+"/"+location+"/temp/Entwurfselement_HO.dbahn";

        QString UH_Path = projectPath+"/"+location+"/temp/Entwurfselement_UH.dbahn";
        QString LA_Path = projectPath+"/"+location+"/temp/Entwurfselement_LA.dbahn";
        if (!QFile::exists(kmLinePath)|| !QFile::exists(gleiskantenPath) || !QFile::exists(gleisknotenPath) ||
                !QFile::exists(hoehePath) || !QFile::exists(UH_Path) || !QFile::exists(LA_Path) ){
            QMessageBox::information(this, "Missing Data", "One or More Important Data is missing ...\n Please visit Data section");
            ui->tableWidget->setEnabled(false);
            ui->btnAutoPLAN->setEnabled(false);
            ui->lblLocation->setEnabled(false);
            return;
        }

        std::vector<QString> filePaths;

        filePaths.push_back(kmLinePath);
        filePaths.push_back(gleiskantenPath);
        filePaths.push_back(gleisknotenPath);
        filePaths.push_back(hoehePath);
        filePaths.push_back(UH_Path);
        filePaths.push_back(LA_Path);

        foreach (auto fi, filePaths){
            QFile file (fi);
            QFileInfo info (fi);
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
                QMessageBox::information(this, "info", file.errorString());
                return;
            }

            QString current = fi.remove(projectPath+"/"+projectName+"/temp/");
            current = current.remove("."+ info.completeSuffix());

            QFile fileToSave (projectPath+"/"+projectName+"/temp/"+current+".geojson");

            if (!fileToSave.open(QIODevice::WriteOnly)){
                QMessageBox::warning(this, "Warning", fileToSave.errorString());
                return;
            }

            QByteArray data = file.readAll();
            QByteArray decoded = QByteArray::fromHex(data);

    //        QString allData;
    //        allData = QString(decoded);
            file.close();

            fileToSave.write(decoded);
            fileToSave.close();
        }
        kmLinePath = projectPath.toLatin1()+"/" +projectName.toLatin1()+"/temp/Entwurfselement_KM.geojson";
        gleiskantenPath =  projectPath.toLatin1()+"/" +projectName.toLatin1()+"/temp/Gleiskanten.geojson";
        gleisknotenPath = projectPath.toLatin1()+"/" +projectName.toLatin1()+"/temp/Gleisknoten.geojson";
        hoehePath = projectPath.toLatin1()+"/" +projectName.toLatin1()+"/temp/Entwurfselement_HO.geojson";
        UH_Path = projectPath.toLatin1()+"/" +projectName.toLatin1()+"/temp/Entwurfselement_UH.geojson";
        LA_Path = projectPath.toLatin1()+"/" +projectName.toLatin1()+"/temp/Entwurfselement_LA.geojson";

        this->setKmLinePath(kmLinePath);
        this->setGleiskantenPath(gleiskantenPath);
        this->setGleisknotenPath(gleisknotenPath);
        this->setHoehePath(hoehePath);
        this->setUH_Path(UH_Path);
        this->setLA_Path(LA_Path);

        Connect2CSharp *csharp = new Connect2CSharp ("",this->getKmLinePath().toLatin1(), this->getGleiskantenPath().toLatin1(),
                                                     this->getGleisknotenPath().toLatin1(), this->getHoehePath().toLatin1(), this->getUH_Path().toLatin1(),
                                                     this->getLA_Path().toLatin1(), ui->lineEdit->text().toLatin1());
        csharp->cSharp();

        // remove all the input files

        kmLinePath = projectPath.toLatin1()+"/" +projectName.toLatin1()+"/temp/Entwurfselement_KM.geojson";
        gleiskantenPath =  projectPath.toLatin1()+"/" +projectName.toLatin1()+"/temp/Gleiskanten.geojson";
        gleisknotenPath = projectPath.toLatin1()+"/" +projectName.toLatin1()+"/temp/Gleisknoten.geojson";
        hoehePath = projectPath.toLatin1()+"/" +projectName.toLatin1()+"/temp/Entwurfselement_HO.geojson";
        UH_Path = projectPath.toLatin1()+"/" +projectName.toLatin1()+"/temp/Entwurfselement_UH.geojson";
        LA_Path = projectPath.toLatin1()+"/" +projectName.toLatin1()+"/temp/Entwurfselement_LA.geojson";

//        gleiskantenPath =  projectPath.toLatin1()+"/" +projectName.toLatin1()+"/temp/Gleiskanten.geojson";
//        gleisknotenPath = projectPath.toLatin1()+"/" +projectName.toLatin1()+"/temp/Gleisknoten.geojson";
//        hoehePath = projectName.toLatin1()+"/" +projectName.toLatin1()+"/temp/Entwurfselement_HO.geojson";

        std::vector<QString> paths;
        paths.push_back(kmLinePath);
        paths.push_back(gleiskantenPath);
        paths.push_back(gleisknotenPath);
        paths.push_back(hoehePath);
        paths.push_back(UH_Path);
        paths.push_back(LA_Path);

        foreach(QString val, paths){
            QFile file (val);
            file.remove();
        }
        if (!csharp->isAvailable){
            QMessageBox::warning(this, "Warning", "Problem opening APlan_Core App \n ... some linking file(s) are missing. "
                                                  "Please contact your administrator");
            return;
        }
        csharp->mainSolution();
        this->table = csharp->getMainAntwort();
        this->rows = csharp->getNumberOfRows();
        this->cols = csharp->getNumberofCols();
        ui->lblLocation->hide();
        ui->lblLocation->setText(location.toUpper());
        ui->btnAutoPLAN->setEnabled(true);
        QMessageBox::information(this, "Info", "Successful !");
    }

    // Display output on TableWidget
    QStringList headers;
    QStringList rows;

    headers <<"Type" << "Position(Km)"<< "Lateral Distance(Km)" << "Orientation" << "Belogs To";
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->horizontalHeader()->frameStyle();

//    output();
    ui->tableWidget->setRowCount(this->rows);
    for (int i = 0; i< this->rows; i++){
        rows.append(QString::number(i+1));
    }
    ui->tableWidget->setVerticalHeaderLabels(rows);
    ui->tableWidget->setColumnWidth(2, 150);
    ui->tableWidget->setEnabled(true);
    ui->lblLocation->show();


    for (int i =0; i< this->rows; i++){
        for (int j=0; j<5; j++){
            QTableWidgetItem *item = new QTableWidgetItem(this->table[i][j]);
            item->setTextAlignment(Qt::AlignCenter);

            ui->tableWidget->setItem(i,j, item);
        }
    }
}

const QString &PlanningTable::getHoehePath() const
{
    return hoehePath;
}

void PlanningTable::setHoehePath(const QString &newHoehePath)
{
    hoehePath = newHoehePath;
}



const QString &PlanningTable::getGleisknotenPath() const
{
    return gleisknotenPath;
}

void PlanningTable::setGleisknotenPath(const QString &newGleisknotenPath)
{
    gleisknotenPath = newGleisknotenPath;
}

const QString &PlanningTable::getGleiskantenPath() const
{
    return gleiskantenPath;
}

void PlanningTable::setGleiskantenPath(const QString &newGleiskantenPath)
{
    gleiskantenPath = newGleiskantenPath;
}


//void PlanningTable::on_btnLoad_clicked()
//{
//    if (fileFormat == ".mdb"){
//        QMessageBox::warning(this, "Warning", "Planning of .mdb data source/file was temporarily disabled");
//        return;
//    }
//    if (ui->comboBoxStations->currentText().isNull() || ui->comboBoxStations->currentText().isEmpty()) {
//        QMessageBox::warning(this, "Warning", "Unable to process ... \n Please create a project");
//        ui->tableWidget->setEnabled(false);
//        ui->btnAutoPLAN->setEnabled(false);
//        ui->lblLocation->setEnabled(false);
//        return;
//    }
//    else {

//        QString location = ui->comboBoxStations->currentText();
//        QString kmLinePath = projectPath+"/"+location+"/temp/Entwurfselement_KM.dbahn";

//        QString gleiskantenPath = projectPath+"/"+location+"/temp/Gleiskanten.dbahn";
//        QString gleisknotenPath = projectPath+"/"+location+"/temp/Gleisknoten.dbahn";
//        QString hoehePath = projectPath+"/"+location+"/temp/Entwurfselement_HO.dbahn";

//        QString UH_Path = projectPath+"/"+location+"/temp/Entwurfselement_UH.dbahn";
//        QString LA_Path = projectPath+"/"+location+"/temp/Entwurfselement_LA.dbahn";
//        if (!QFile::exists(kmLinePath)|| !QFile::exists(gleiskantenPath) || !QFile::exists(gleisknotenPath) ||
//                !QFile::exists(hoehePath) || !QFile::exists(UH_Path) || !QFile::exists(LA_Path) ){
//            QMessageBox::information(this, "Missing Data", "One or More Important Data is missing ...\n Please visit Data section");
//            ui->tableWidget->setEnabled(false);
//            ui->btnAutoPLAN->setEnabled(false);
//            ui->lblLocation->setEnabled(false);
//            return;
//        }

//        std::vector<QString> filePaths;

//        filePaths.push_back(kmLinePath);
//        filePaths.push_back(gleiskantenPath);
//        filePaths.push_back(gleisknotenPath);
//        filePaths.push_back(hoehePath);
//        filePaths.push_back(UH_Path);
//        filePaths.push_back(LA_Path);

//        foreach (auto fi, filePaths){
//            QFile file (fi);
//            QFileInfo info (fi);
//            if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
//                QMessageBox::information(this, "info", file.errorString());
//                return;
//            }

//            QString current = fi.remove(projectPath+"/"+projectName+"/temp/");
//            current = current.remove("."+ info.completeSuffix());

//            QFile fileToSave (projectPath+"/"+projectName+"/temp/"+current+".geojson");

//            if (!fileToSave.open(QIODevice::WriteOnly)){
//                QMessageBox::warning(this, "Warning", fileToSave.errorString());
//                return;
//            }

//            QByteArray data = file.readAll();
//            QByteArray decoded = QByteArray::fromHex(data);

//    //        QString allData;
//    //        allData = QString(decoded);
//            file.close();

//            fileToSave.write(decoded);
//            fileToSave.close();
//        }
//        kmLinePath = projectPath.toLatin1()+"/" +projectName.toLatin1()+"/temp/Entwurfselement_KM.geojson";
//        gleiskantenPath =  projectPath.toLatin1()+"/" +projectName.toLatin1()+"/temp/Gleiskanten.geojson";
//        gleisknotenPath = projectPath.toLatin1()+"/" +projectName.toLatin1()+"/temp/Gleisknoten.geojson";
//        hoehePath = projectPath.toLatin1()+"/" +projectName.toLatin1()+"/temp/Entwurfselement_HO.geojson";
//        UH_Path = projectPath.toLatin1()+"/" +projectName.toLatin1()+"/temp/Entwurfselement_UH.geojson";
//        LA_Path = projectPath.toLatin1()+"/" +projectName.toLatin1()+"/temp/Entwurfselement_LA.geojson";

//        this->setKmLinePath(kmLinePath);
//        this->setGleiskantenPath(gleiskantenPath);
//        this->setGleisknotenPath(gleisknotenPath);
//        this->setHoehePath(hoehePath);
//        this->setUH_Path(UH_Path);
//        this->setLA_Path(LA_Path);

//        Connect2CSharp *csharp = new Connect2CSharp ("",this->getKmLinePath().toLatin1(), this->getGleiskantenPath().toLatin1(),
//                                                     this->getGleisknotenPath().toLatin1(), this->getHoehePath().toLatin1(), this->getUH_Path().toLatin1(),
//                                                     this->getLA_Path().toLatin1());
//        csharp->cSharp();

//        // remove all the input files

//        kmLinePath = projectPath.toLatin1()+"/" +projectName.toLatin1()+"/temp/Entwurfselement_KM.geojson";
//        gleiskantenPath =  projectPath.toLatin1()+"/" +projectName.toLatin1()+"/temp/Gleiskanten.geojson";
//        gleisknotenPath = projectPath.toLatin1()+"/" +projectName.toLatin1()+"/temp/Gleisknoten.geojson";
//        hoehePath = projectPath.toLatin1()+"/" +projectName.toLatin1()+"/temp/Entwurfselement_HO.geojson";
//        UH_Path = projectPath.toLatin1()+"/" +projectName.toLatin1()+"/temp/Entwurfselement_UH.geojson";
//        LA_Path = projectPath.toLatin1()+"/" +projectName.toLatin1()+"/temp/Entwurfselement_LA.geojson";

////        gleiskantenPath =  projectPath.toLatin1()+"/" +projectName.toLatin1()+"/temp/Gleiskanten.geojson";
////        gleisknotenPath = projectPath.toLatin1()+"/" +projectName.toLatin1()+"/temp/Gleisknoten.geojson";
////        hoehePath = projectName.toLatin1()+"/" +projectName.toLatin1()+"/temp/Entwurfselement_HO.geojson";

//        std::vector<QString> paths;
//        paths.push_back(kmLinePath);
//        paths.push_back(gleiskantenPath);
//        paths.push_back(gleisknotenPath);
//        paths.push_back(hoehePath);
//        paths.push_back(UH_Path);
//        paths.push_back(LA_Path);

//        foreach(QString val, paths){
//            QFile file (val);
//            file.remove();
//        }
//        if (!csharp->isAvailable){
//            QMessageBox::warning(this, "Warning", "Problem opening APlan_Core App \n ... some linking file(s) are missing. "
//                                                  "Please contact your administrator");
//            return;
//        }
//        csharp->mainSolution();
//        this->table = csharp->getMainAntwort();
//        this->rows = csharp->getNumberOfRows();
//        this->cols = csharp->getNumberofCols();
//        ui->lblLocation->hide();
//        ui->lblLocation->setText(location.toUpper());
//        ui->btnAutoPLAN->setEnabled(true);
//        QMessageBox::information(this, "Info", "Successful !");
//    }
//}


void PlanningTable::on_btnSelectFolder_clicked()
{
    QString filePath = QFileDialog::getExistingDirectory(this, ("Select Output Folder"), QDir::currentPath());
    ui->lineEdit->setText(filePath);
    ui->btnAutoPLAN->setEnabled(true);
    if (ui->lineEdit->text().isNull() ||ui->lineEdit->text().isEmpty()){
        ui->btnAutoPLAN->setEnabled(false);
    }
}

const QString &PlanningTable::getLA_Path() const
{
    return LA_Path;
}

void PlanningTable::setLA_Path(const QString &newLA_Path)
{
    LA_Path = newLA_Path;
}

const QString &PlanningTable::getUH_Path() const
{
    return UH_Path;
}

void PlanningTable::setUH_Path(const QString &newUH_Path)
{
    UH_Path = newUH_Path;
}

const QString &PlanningTable::getKmLinePath() const
{
    return kmLinePath;
}

void PlanningTable::setKmLinePath(const QString &newKmLinePath)
{
    kmLinePath = newKmLinePath;
}

