#include "planningtable.h"
#include "ui_planningtable.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "myopenglwidget.h"
#include "symbolcontainer.h"
#include "kmtocoordinate.h"

PlanningTable::PlanningTable(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlanningTable)
{
    ui->setupUi(this);
    ui->comboBoxStations->addItem(projectName);

    progressBarValue =0;

    ui->progressBar->setVisible(false);
    // set previous export path only if it exist
    if (QDir(planningOutputPath).exists() && !ui->comboBoxStations->currentText().isEmpty()){
        ui->lineEdit->setText(planningOutputPath);
        ui->btnAutoPLAN->setEnabled(true);
        isStart = true;
    } else planningOutputPath = "";

    timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer, &QTimer::timeout, this, &PlanningTable::timeout);
    timer->start(1000);
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
        ui->progressBar->setVisible(true);
        ui->progressBar->setValue(progressBarValue);
        QApplication::processEvents();
        isStart = true;

        planningOutputPath = ui->lineEdit->text();
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

        /*Check the first row (Lateral Distance, and Positioning ) to know if there are output error
        from the C# appllication. Also, this is used to handle "fail fast Exception"*/

        if (this->rows == 0) {
            QMessageBox::information(this, "Planning Aborted !", "Process aborted mid-way, "
                                                                 "Please ensure \n compliance with the input data specification.");
            close();
            return;
        }
        isEnd = true;
        ui->lblLocation->hide();
        ui->lblLocation->setText(location.toUpper());
        ui->btnAutoPLAN->setEnabled(true);
        QMessageBox::information(this, "Info", "Successful !");
    }

    // Display output on TableWidget
    QStringList headers;
    QStringList rows;

    headers <<"DB Signal Function" << "Linear Coordinate (Km)"<< "Lateral Distance(Km)" << "Lateral Side" << "Direction";
    //    headers <<"Type" << "Position(Km)"<< "Lateral Distance(Km)" << "Orientation" << "Belogs To";
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->horizontalHeader()->frameStyle();

    //    output();
    ui->tableWidget->setRowCount(this->rows);
    for (int i = 0; i< this->rows; i++){
        rows.append(QString::number(i+1));
    }
    ui->tableWidget->setVerticalHeaderLabels(rows);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents); //   setSectionResizeMode(QHeaderView::AdjustToContents);
//    ui->tableWidget->setColumnWidth(2, 150);
//    ui->tableWidget->setColumnWidth(1, 150);
//    ui->tableWidget->setColumnWidth(0, 150);
    ui->tableWidget->setEnabled(true);
    ui->lblLocation->show();
    for (int i =0; i< this->rows; i++){
        for (int j=0; j<5; j++){
            QTableWidgetItem *item = new QTableWidgetItem(this->table[i][j]);
            item->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->setItem(i,j, item);
        }
    }
    // Add Symbols/Signals -- only if KmLine data is available (Json)

    KmToCoordinate *kmToCoord = new KmToCoordinate(projectPath,projectName);
    kmToCoord->mapKmAndCoord();
    kmToCoord->calculateAngles();

    for (int i =0; i<this->rows; i++){
        double val = table[i][1].toDouble();
        QPointF position = kmToCoord->getFinalPosition(val,table[i][2].toDouble(),table[i][3]);  //getNearestCoordFromKmValue(val);
        double angle = kmToCoord->getAngleFromKmValue(val);
        if (table[i][0] == "entry" &&  table[i][4] == "1"){
            tracks->addAutomateSignal("Ankundigungsbake", position, angle, table[i][0],table[i][1],table[i][2],table[i][3],table[i][4]);
        }
        else if (table[i][0] == "entry" && table[i][4] == "2"){
            //Then add 180 to the angle (to make symbol rotate/turn to other direction
            tracks->addAutomateSignal("Ankundigungsbake",position, angle+180, table[i][0],table[i][1],table[i][2],table[i][3],table[i][4]);
        }
        else if (table[i][0] == "exit" && table[i][4] == "1"){
            tracks->addAutomateSignal("Abfahrsignal",position, angle, table[i][0],table[i][1],table[i][2],table[i][3],table[i][4]);
        }
        else if (table[i][0] == "exit" && table[i][4] == "2"){
            //Then add 180 to the angle (to make symbol rotate/turn to other direction
            tracks->addAutomateSignal("Abfahrsignal",position, angle+180, table[i][0],table[i][1],table[i][2],table[i][3],table[i][4]);
        }
        else qDebug()<< "None";
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


void PlanningTable::on_btnSelectFolder_clicked()
{
    QString filePath = QFileDialog::getExistingDirectory(this, ("Select Output Folder"), QDir::currentPath());
    ui->lineEdit->setText(filePath);
    ui->btnAutoPLAN->setEnabled(true);
    if (ui->lineEdit->text().isNull() ||ui->lineEdit->text().isEmpty()){
        ui->btnAutoPLAN->setEnabled(false);
    }
}

void PlanningTable::timeout()
{
    if (isStart || isEnd){
        if (isEnd){
            ui->progressBar->setValue(100);
            QApplication::processEvents();
            timer->stop();
            ui->progressBar->setVisible(false);
            isEnd =false;
            ui->btnAutoPLAN->setEnabled(false);
            qDebug()<< "TORR1";

        } else if (isStart && (progressBarValue <90)){
            progressBarValue+=10;
            ui->progressBar->setValue(progressBarValue);
            QApplication::processEvents();
            qDebug()<< "TORR2";

        } else if (isStart && (progressBarValue == 90)){
            ui->progressBar->setValue(90);
            QApplication::processEvents();
            qDebug()<< "TORR3";
        }
    }
}

void PlanningTable::closeEvent(QCloseEvent *event)
{
    isEnd =true;
    event->accept();
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
