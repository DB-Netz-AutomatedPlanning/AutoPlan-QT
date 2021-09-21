#include "planningtable.h"
#include "ui_planningtable.h"

PlanningTable::PlanningTable(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlanningTable)
{
    ui->setupUi(this);

    QDirIterator iter( "Data", QDir::Dirs | QDir::NoDotAndDotDot);
    while(iter.hasNext() )
    {
        QString val = iter.next();
        ui->comboBoxStations->addItem(val.remove("Data/"));
    }
}

PlanningTable::~PlanningTable()
{
    delete ui;
}

//void PlanningTable::readFromFile(QString fileName)
//{
//    QFile file(fileName);
//    if (!QFile::exists(fileName)){
//        QMessageBox::information(this, "Notice...", "You have no output to view this time");
//        return;
//    }
//    else{
//        if (file.open(QIODevice::ReadOnly)){
//            this->setAllFile(file.readAll());
//            file.close();
//        }
//        else
//            QMessageBox::information(this, "Information", file.errorString());
//    }

//}

//void PlanningTable::output()
//{
//    QStringList values;
//    readFromFile("solution.txt");
//    if (this->getAllFile().length() >1){
//        QStringList sol = this->getAllFile().split(QRegularExpression("\r\n"), Qt::SkipEmptyParts);
//        foreach(QString vv, sol){
//            QStringList final = vv.split(" ");
//            foreach(QString vv1, final){
//                values.append(vv1);
//            }
//        }
//    }
//    this->setAllRows(values.length()/5);
//    //int rows = values.length()/5;
//    int cols = 5;

//    allTable = new QString*[this->getAllRows()];
//    for(int i = 0; i<this->getAllRows(); i++){
//        allTable[i] = new QString[cols];
//    }
//    // Fill the table
//    int count =0;
//    for(int i = 0; i<this->getAllRows(); i++){
//        for (int j=0; j<cols; j++){
//            allTable[i][j] = values[count];
//            count++;
//        }
//    }
//    this->setAllTable(allTable);
//}

//const QString &PlanningTable::getAllFile() const
//{
//    return allFile;
//}

//void PlanningTable::setAllFile(const QString &newAllFile)
//{
//    allFile = newAllFile;
//}

//QString **PlanningTable::getAllTable() const
//{
//    return allTable;
//}

//void PlanningTable::setAllTable(QString **newAllTable)
//{
//    allTable = newAllTable;
//}

//int PlanningTable::getAllRows() const
//{
//    return allRows;
//}

//void PlanningTable::setAllRows(int newAllRows)
//{
//    allRows = newAllRows;
//}



void PlanningTable::on_btnAutoPLAN_clicked()
{
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


void PlanningTable::on_btnLoad_clicked()
{
    if (ui->comboBoxStations->currentText().isNull() || ui->comboBoxStations->currentText().isEmpty()) {
        QMessageBox::warning(this, "Warning", "Unable to process ... \n Please specify Station");
        ui->tableWidget->setEnabled(false);
        ui->btnAutoPLAN->setEnabled(false);
        ui->lblLocation->setEnabled(false);
        return;
    }
    else {
        QString location = ui->comboBoxStations->currentText();
        QString gleiskantenPath = "Data/"+location+"/Gleiskanten.geojson";
        QString gleisknotenPath = "Data/"+location+"/Gleisknoten.geojson";
        QString hoehePath = "Data/"+location+"/Entwurfselement_Hoehe.geojson";
        if (!QFile::exists(gleiskantenPath) || !QFile::exists(gleisknotenPath) || !QFile::exists(hoehePath)){
            QMessageBox::information(this, "Missing Data", "One or More Important Data is missing ...\n Please visit Data section");
            ui->tableWidget->setEnabled(false);
            ui->btnAutoPLAN->setEnabled(false);
            ui->lblLocation->setEnabled(false);
            return;
        }

        this->setGleiskantenPath(gleiskantenPath);
        this->setGleisknotenPath(gleisknotenPath);
        this->setHoehePath(hoehePath);

        Connect2CSharp *csharp = new Connect2CSharp(this->getGleiskantenPath().toLatin1(), this->getGleisknotenPath().toLatin1(), this->getHoehePath().toLatin1());
        csharp->cSharp();

        csharp->mainSolution();
        this->table = csharp->getMainAntwort();
        this->rows = csharp->getNumberOfRows();
        this->cols = csharp->getNumberofCols();
        ui->lblLocation->hide();
        ui->lblLocation->setText(location.toUpper());
        ui->btnAutoPLAN->setEnabled(true);
    }
}




