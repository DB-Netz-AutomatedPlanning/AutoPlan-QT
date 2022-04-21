#include "mainwindow.h"
#include "importfolder.h"
#include "ui_mainwindow.h"
#include "myopenglwidget.h"
#include "newprojectdialog.h"
//#include "calculator.h"
#include "planningtable.h"
#include "constructsvgdialog.h"
#include "iconslist.h"
#include "symboloptions.h"
#include "symbolcontainer.h"
#include "uploadnewdata.h"
#include "removedata.h"
#include "nopreviewdelete.h"
#include "exportdialog.h"
#include "qgraphicsmainwindow.h"
#include "qgraphicssymbolcontainer.h"
#include <QComboBox>
#include<QDebug>
#include <QTabBar>
#include<QToolButton>
#include <QComboBox>
#include <QLineEdit>
#include <QFileDialog>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTableWidget>
#include <QOpenGLWidget>
#include <QColorDialog>
#include <QInputDialog>
#include <QColorDialog>
#include <QFileDialog>
#include <QImageWriter>
#include <QInputDialog>
#include <QMenuBar>
#include <QMessageBox>
#include <QCloseEvent>
#include <QSvgGenerator>
#include <QPainterPath>

#include <QPainter>
#include <QPrinter>

#include <QtGui>
#include <QtWidgets>
#include <QtPrintSupport>

#include <iostream>

#if defined(QT_PRINTSUPPORT_LIB)
#include <QtPrintSupport/qtprintsupportglobal.h>
#if QT_CONFIG(printer)
#if QT_CONFIG(printdialog)
#include <QPrintDialog>
#endif // QT_CONFIG(printdialog)
#include <QPrinter>
#endif // QT_CONFIG(printer)
#endif // QT_PRINTSUPPORT_LIB

#include <QtGui/qtguiglobal.h>
#include <QtGui/qpaintdevice.h>
#include <QtGui/qpagelayout.h>
#include <QtGui/qpageranges.h>

#include <QTableView>
bool isChecked = true;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    scribbleArea= new MyOpenglWidget(this);
    setCentralWidget(scribbleArea);
    ui->setupUi(this);
    ui->toolBar->setIconSize(QSize(16, 16));

    hideMenuBar = false;
    hideFileTab = false;
    hideTabView = false;

    ui->actionSave->setEnabled(false);
    ui->actionSave_As->setEnabled(false);
    ui->actionPrint->setEnabled(false);


//    ui->f_headerTabs->setGeometry(0,0,100,100);

//    ui->comboBox_10->setEditable(true);
//    ui->comboBox_10->lineEdit()->setReadOnly(true);
//    ui->comboBox_10->lineEdit()->setAlignment(Qt::AlignCenter);

//    ui->comboBox_13->setEditable(true);
//    ui->comboBox_13->lineEdit()->setReadOnly(true);
//    ui->comboBox_13->lineEdit()->setAlignment(Qt::AlignCenter);

//    ui->comboBox_15->setEditable(true);
//    ui->comboBox_15->lineEdit()->setReadOnly(true);
//    ui->comboBox_15->lineEdit()->setAlignment(Qt::AlignCenter);
//    ui->comboBox_15->lineEdit()->adjustSize();

//    ui->comboBox_16->setEditable(true);
//    ui->comboBox_16->lineEdit()->setReadOnly(true);
//    ui->comboBox_16->lineEdit()->setAlignment(Qt::AlignCenter);

//    ui->comboBox_17->setEditable(true);
//    ui->comboBox_17->lineEdit()->setReadOnly(true);
//    ui->comboBox_17->lineEdit()->setAlignment(Qt::AlignCenter);

    //Close button on Tab bar
    // ui->tabWidget_2->removeTab(2);
    ui->tabWidget_2->removeTab(2);
    ui->tabWidget_2->removeTab(1);

    // Create button what must be placed in tabs row
    QToolButton* tb = new QToolButton(this);
    tb->setText("+");

    // Add empty, not enabled tab to tabWidget
    ui->tabWidget_2->setTabEnabled(ui->tabWidget_2->tabBar()->count()-1, false);

    // Add tab button to current tab. Button will be enabled, but tab -- not
    ui->tabWidget_2->tabBar()->setTabButton(ui->tabWidget_2->tabBar()->count()-1, QTabBar::RightSide, tb);

    // Setting tabs closable and movable
    ui->tabWidget_2->setTabsClosable(true);
    ui->tabWidget_2->setMovable(true);

    setStyleSheet("QToolButton { border: none; }");

//    connect(tb,SIGNAL(clicked()),this,SLOT(addTab()));
    connect(ui->tabWidget_2,SIGNAL(tabCloseRequested(int)),this,SLOT(closeTab(int)));

//    //Home->Properties
//    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(penColor()));
//    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(penWidth()));
//    connect(ui->calculator, SIGNAL(clicked(bool)), this, SLOT(openCalculator()));
//    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(fetchObjectProps()));

//    //View - Interface
//    connect(ui->fileTab, SIGNAL(clicked()), this, SLOT(hideFile()));
//    connect(ui->hideTabBtn,SIGNAL(clicked()),this,SLOT(hideTab()));




    //MENU actionOpen
    connect(ui->actionSave_As, SIGNAL(triggered()), this, SLOT(save()));
    connect(ui->actionNew_2, SIGNAL(triggered()), this, SLOT(onNewProjectClicked()));
    connect(ui->actionPrint, SIGNAL(triggered()), this, SLOT(print()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(exit()));
    connect(ui->actionAdd_symbol, SIGNAL(triggered()), this, SLOT(openSvgDialog()));
    connect(ui->actionAdd_symbol_options, SIGNAL(triggered()), this, SLOT(openSvgOptions()));

    connect(ui->planBtn, SIGNAL(clicked()), this, SLOT(planningFnt()));

    // ui->widget_147->hide();
    ui->widget_146->hide();

    ui->tabWidget_2->setCurrentIndex(0);

    //Left area for symbol information
    ui->tableWidget->setRowCount(2);

    QTableWidgetItem *newItem = new QTableWidgetItem(tr("%0").arg("Symbol"));
    ui->tableWidget->setItem(0, 0, newItem);
    QTableWidgetItem *newItem1 = new QTableWidgetItem(tr("%1").arg(defaultObjectName));
    ui->tableWidget->setItem(0, 1, newItem1);
    QTableWidgetItem *newItem2 = new QTableWidgetItem(tr("%1").arg("Position"));
    ui->tableWidget->setItem(1, 0, newItem2);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setObjNameTW(QString str){


    QTableWidgetItem *newItem1 = new QTableWidgetItem(tr("%1").arg(str));
    ui->tableWidget->setItem(0, 1, newItem1);

    ui->tableWidget->show();
    qInfo() << "in ui"+str;
    ui->tableWidget->item(0, 1)->setText(str);

    update();
}

void MainWindow::hideFile()
{
    hideFileTab =! hideFileTab;
    if(hideFileTab){
        ui->menubar->hide();
    }else{
        ui->menubar->show();
    }
}

void MainWindow::hideTab()
{
    QTabBar *tabBar = ui->tabWidget_2->findChild<QTabBar *>();
    hideTabView =! hideTabView;
    if(hideTabView){
        tabBar->hide();
    }else{
        qInfo() << "pressed1";
        tabBar->show();
    }
}

void MainWindow::fetchObjectProps()
{
    btnSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    QString buttonText = btnSender->objectName(); // retrive the object name from the clicked button
}

bool MainWindow::writeFooBar()
{
    QSaveFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation));
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;
    if (-1 == file.write("foo bar"))
        return false;
    return file.commit();
}

//Add new tab
void MainWindow::addTab()
{
    ui->tabWidget_2->insertTab(ui->tabWidget_2->count() - 1,new QGraphicsMainWindow(),QString(projectName).arg(ui->tabWidget_2->count() + 1));
    ui->tabWidget_2->setCurrentIndex(ui->tabWidget_2->count() - 2);
}

void MainWindow::closeTab(int index)
{
    if (index ==0 && isFirstTab){
        isFirstTab = false;
        delete ui->tabWidget_2->widget(index);
        return;
    }
//    ui->tabWidget_2->currentIndex();
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Exit Attempt!", "Are you sure? ... \n Unsaved progress would be lost");
    if (reply == QMessageBox::No){
        return;
    } else if (reply == QMessageBox::Yes) delete ui->tabWidget_2->widget(index);
}

void MainWindow::on_actionOpen_triggered()
{
    if (ui->tabWidget_2->tabText(ui->tabWidget_2->currentIndex()) != "Welcome" &&
             !ui->tabWidget_2->tabText(ui->tabWidget_2->currentIndex()).isEmpty()){ //     ui->tabWidget_2->tabText(ui->tabWidget_2->currentIndex()) != ""){
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Exit Attempt!", "Did you want to save your project ? ... \n  Unsaved progress would be lost",
                                                                    QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes);

        if (reply == QMessageBox::Yes){
            on_actionSave_triggered();
//            delete ui->tabWidget_2->widget(ui->tabWidget_2->currentIndex());
//        } else if (reply == QMessageBox::No) delete ui->tabWidget_2->widget(ui->tabWidget_2->currentIndex());
        }else if (reply == QMessageBox::Cancel ) return;
    }
    QString selectedFile = QFileDialog::getOpenFileName(this, "Open the file");
    if(selectedFile.isNull() || selectedFile.isEmpty() || selectedFile == "") return;
    QFile file(selectedFile);
    // Check the existence of the file
    if(!file.exists()) {
        QMessageBox::warning(this, "File Not Exists", "Cannot open file: " + file.errorString());
        return;
    }
    // check to ensure file selected is .aplan readable
    QFileInfo info (selectedFile);
    if(info.completeSuffix() != "aplan"){
        QMessageBox::warning(this, "Wrong File Selected ! ", "Please open your project with '.aplan' file");
        return;
    }
    // Get the projectPath and the projectName information
    QString completePath = info.absolutePath();
    QStringList regEx = completePath.split(QRegularExpression("/"));
    projectPath = completePath.remove("/"+regEx.back());
    projectName = regEx.back();
    // Check if the temp folder exists in the selected directory
    QDir dir (info.path() +"/temp");
    if (!dir.exists()){
        QMessageBox::warning(this, "Missing files", "Important directory missing ");
        return;
    }
    QString iniFile =  info.filePath().remove(info.suffix()) + "ini";
    QFile file2(iniFile);
    if(!file2.exists()) {
        QMessageBox::warning(this, "File Not Exists", "Important file missing from your directory \n" + file2.errorString());
//        qDebug() << "Missing File2: " + file2.errorString();
        return;
    }
    if(!file2.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Failed !", "Cannot open file: \n" + file.errorString());
        return;
    }
    QByteArray data = file2.readAll();
    QByteArray decoded = QByteArray::fromHex(data);
    QString allData;
    allData = QString(decoded);
    file2.close();

    QStringList getOtherData = allData.split(QRegularExpression("\n"));
    fileFormat = getOtherData.at(0);
    countryCode = getOtherData.at(1);
    delete ui->tabWidget_2->widget(ui->tabWidget_2->currentIndex());
    delete ui->tabWidget_2->widget(ui->tabWidget_2->currentIndex());
    delete ui->tabWidget_2->widget(ui->tabWidget_2->currentIndex());
    addTab();   // for legacy data
    tracks->ReadOperator(selectedFile); // for symbols

    // Enable Save, SaveAs, and Print button
    ui->actionSave->setEnabled(true);
    ui->actionSave_As->setEnabled(true);
    ui->actionPrint->setEnabled(true);
}


void MainWindow::on_actionSave_triggered()
{
    QString savePath = projectPath + "/"+ projectName +"/"+ projectName + ".aplan";
    QFile file(savePath);

    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        if (projectPath == "" || projectName == ""){
            QMessageBox::information(this, "No Project Detected", "Please create a project");
            return;
        }
        QMessageBox::warning(this, "Warning", "Cannot save file: /n" + file.errorString());
        return;
    }
    file.close();

    /* If the file already exist, remove/delete the file, and create a new one to write
    the data-stream afresh*/
    if (file.exists()){
        if (!file.remove()){
            QMessageBox::information(this, "Technical Error !", "Project might have been saved incorrectly");
        }
    }
    // If it get to this stage, the data needs to be written to the file for saving as datastream
    bool writeData = tracks->writeOperator(savePath);
    if (!writeData) return;

    // Save other relevant data in the .ini file (to be located inside the project folder)
    QString savePath2 = projectPath + "/"+ projectName +"/"+ projectName + ".ini";
    QFile file2(savePath2);
    if (!file2.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Failed !", "Cannot save file: /n" + file.errorString());
        return;
    }
    QString data;
    data.append(fileFormat+"\n"+countryCode);
    QByteArray bytes (data.toUtf8().toHex());

    file2.write(bytes);
    file2.close();
    // Interraction: Display an indicator ro the user on statuc bar to show that file is being saved
    ui->statusbar->setStyleSheet("QStatusBar{padding-left:8px;background:rgba(0,185,0,150);color:black;font-weight:bold;}");
    ui->statusbar->showMessage("Project saving in progress. . . ", 5000);
//    QTimer::singleShot(5000, [this]{ui->statusbar->setStyleSheet("color: black");});
    QTimer::singleShot(4500, [this]{ui->statusbar->setStyleSheet("QStatusBar{padding-left:8px;background:"
                                                                 "rgba(0,0,0,0);color:black;font-weight:bold;}");});
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
}


void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape)
        close();
    else
        QWidget::keyPressEvent(e);
}

//Home -> Properties
void MainWindow::penColor()
//! [7] //! [8]
{   glClearColor(1,0,0,1);
    //QColor newColor = QColorDialog::getColor(scribbleArea->penColor());
    //    if (newColor.isValid())
    // scribbleArea->setPenColor(newColor);
}


void MainWindow::penWidth()
//! [9] //! [10]
{
    // int newWidth = QInputDialog::getInt(this, tr("Scribble"),
    //tr("Select pen width:"),
    //scribbleArea->penWidth(),
    //1, 50, 1, &ok);
    //if (ok)
    //   scribbleArea->setPenWidth(newWidth);
}

//void MainWindow::openCalculator(){
//    disconnect(ui->calculator, SIGNAL(pressed()), this, SLOT(openCalculator()));
//    Calculator *calc;
//    calc = new Calculator();
//    // Calculator calc;
//    calc->show();
//}


//Open dialog box of SVG
void MainWindow::openSvgDialog(){
    disconnect(ui->actionAdd_symbol, SIGNAL(triggered()), this, SLOT(openSvgDialog()));
    IconsList *svgDialog;
    svgDialog = new IconsList();
    svgDialog->show();
}

void MainWindow::openSvgOptions(){
    disconnect(ui->actionAdd_symbol_options, SIGNAL(triggered()), this, SLOT(openSvgOptions()));
    SymbolOptions *svgOptions;
    svgOptions = new SymbolOptions();
    svgOptions->show();
}

//MENU
//! [3]
void MainWindow::open()
//! [3] //! [4]
{
    if (maybeSave()) {
        QString fileName = QFileDialog::getOpenFileName(this,
                                                        tr("Open File"), QDir::currentPath());
        if (!fileName.isEmpty())
            //scribbleArea->openImage(fileName);
            qInfo() << "hello";
    }
}

//! [19]
bool MainWindow::saveFile(const QByteArray &fileFormat)
//! [19] //! [20]
{
    QString initialPath = QDir::currentPath() + "/untitled." + fileFormat;
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
                                                    initialPath,
                                                    tr("%1 Files (*.%2);;All Files (*)")
                                                    .arg(QString::fromLatin1(fileFormat.toUpper()))
                                                    .arg(QString::fromLatin1(fileFormat)));
    return true;
    //if (fileName.isEmpty())
    //  return false;
    //return scribbleArea->saveImage(fileName, fileFormat.constData());
}

bool MainWindow::maybeSave()
//! [17] //! [18]
{
    return true;
}
//! [18]

// SaveAs
void MainWindow::save()
{
    if (projectPath == "" || projectName == ""){
        QMessageBox::information(this, "No Project Detected", "Please create a project");
        ui->actionSave->setEnabled(false);
        ui->actionSave_As->setEnabled(false);
        ui->actionPrint->setEnabled(false);
        return;
    }
    QString fileName = QFileDialog::getSaveFileName(this, "Save As", "", "Windows Bitmap(*.BMP);;Joint Photographic Experts Group(*.JPG);;Joint Photographic Experts Group(*.JPEG);;"
                                                                         "Portable Network Graphics(*.PNG);;Portable Bitmap(*.PBM);;"
                                                                         "Portable Graymap(*.PGM);;Portable Pixmap(*.PPM);;"
                                                                         "X11 Bitmap(*.XBM);;X11 Pixmap(*.XPM);;Scalable Vector Graphics(*.SVG)" );
    if (fileName.isEmpty()) return;
    QFileInfo info(fileName);
    if(info.completeSuffix() == "SVG"){
        QSvgGenerator svgGenerator;
        svgGenerator.setFileName(fileName);
        int width = qCeil(qreal(tracks->scene()->width()/1.25));
        int height = qCeil(qreal(tracks->scene()->height()/1.25));
        svgGenerator.setSize(QSize(width, height));
        svgGenerator.setViewBox(QRect(0,0,width, height));
        svgGenerator.setTitle(info.completeBaseName());
        svgGenerator.setDescription("File created from APlan Tool");

        QPainter painter;
        painter.begin(&svgGenerator);
        painter.setRenderHint(QPainter::Antialiasing);
        tracks->scene()->render(&painter);
        painter.end();
    } else {
        QPixmap pixmap = tracks->grab();
        pixmap.save(fileName); //Automatically detect the format
    }


//    // QAction *action = qobject_cast<QAction *>(sender());
//    QByteArray fileFormat = ui->actionSave_As->data().toByteArray();
//    saveFile(fileFormat);
}

void MainWindow::print()
{
#if defined(QT_PRINTSUPPORT_LIB) && QT_CONFIG(printdialog)
    QPrinter printer(QPrinter::HighResolution);
    QPrintDialog printDialog(&printer, this);
    //! [21] //! [22]
    if (printDialog.exec() == QDialog::Accepted) {

        QPainter painter(&printer);
    }
#endif // QT_CONFIG(printdialog)

    ////          QPainter painter(&printer);
    ////            painter.begin(&printer);
    ////          double xscale = printer.pageRect().width() / double(minWidth);
    //////           double yscale = printer.pageRect().height() / double(minHeight);
    //////           double scale = qMin(xscale, yscale);
    //////           painter.translate(printer.paperRect().center());
    //////           painter.scale(scale, scale);
    ////         painter.translate(-minWidth/ 2, -minHeight/ 2);
    ////           ui->widget_152->render(&painter);
}

void MainWindow::exit()
{
    QCoreApplication::quit();
}


//Rayhan's code

void MainWindow::importShapeFiles()
{
    //    FileChooser fileChooser = new FileChooser();
    //            fileChooser.setTitle("Import Multiple Files");
    //            fileChooser.getExtensionFilters().addAll(
    //                    new FileChooser.ExtensionFilter("All Shapefiles", "*.*"),
    //                    new FileChooser.ExtensionFilter("DBF", "*.dbf"),
    //                    new FileChooser.ExtensionFilter("CPG", "*.cpg"),
    //                    new FileChooser.ExtensionFilter("SHX", "*.shx"),
    //                    new FileChooser.ExtensionFilter("PRJ", "*.prj"),
    //                    new FileChooser.ExtensionFilter("QPJ", "*.qpj"),
    //                    new FileChooser.ExtensionFilter("SHP", "*.shp")
    //            );
    //            Stage stage = (Stage) gridPane.getScene().getWindow();

    //            files = fileChooser.showOpenMultipleDialog(stage);
    //            db.setFiles(files);
    //            db.copyData();

    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    readFile = fileName;
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        // QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    //ui->textEdit->setText(text);
    file.close();
}

void MainWindow::exportToPicture()
{
    //QString defaultFileName = fileName;
    //int index = defaultFileName.lastIndexOf(".");
    //defaultFileName = defaultFileName.left(index);
    //defaultFileName += ".png";
    //QString s = QFileDialog::getSaveFileName(
    //  this, tr("Export to PNG"), defaultFileName,
    //tr("Portable Network Graphics (*.png)"));

    //if (!s.isEmpty())
    //{
    //QImage image(view->width(), view->height(), QImage::Format_RGB32);
    //image.fill(QColor(Qt::white));
    //QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
    //QPainter painter(&image);
    //view->render(&painter);
    //image.save(s, "PNG");
    //QApplication::restoreOverrideCursor();
    //}


    //------------------------------------------------------------

    // Condition needs to be modified as soon as other version is available
    // if (ui->comboBox_30->currentText() != "Eulynx"){
    //   QMessageBox::warning(this, "File Format", "Selected format '"+ui->comboBox_30->currentText()+"' is currently not available");

    //}
    //else{
    //  ExportDialog exportDialog;
    //exportDialog.setModal(true);
    //exportDialog.exec();
    //}
}

void MainWindow::planningFnt()
{
    if (fileFormat == ".mdb"){
        QMessageBox::warning(this, "File Format", "Planning of .mdb data source/file was temporarily disabled");
        return;
    }
    if (fileFormat == ".euxml") {
        QMessageBox::warning(this, "File Format", "Planning of .euxml data source/file was temporarily disabled");
        return;
    }
    else{
        PlanningTable *plan;
        plan = new PlanningTable();
        plan->show();
    }
}

void MainWindow::on_actionAdd_Data_triggered()
{
    if (fileFormat == ".mdb"){
        QMessageBox::information(this, "Information", "Cannot change/modify .mdb file after uploading");
        return;
    }
    if (fileFormat == ".euxml"){
        QMessageBox::information(this, "Information", "Cannot change/modify .euxml file after uploading");
        return;
    }
    UploadNewData uploadNewData;
    uploadNewData.setModal(true);
    uploadNewData.exec();
}

void MainWindow::on_actionPreview_Data_triggered()
{
    RemoveData removeData;
    removeData.setModal(true);
    removeData.exec();
}

void MainWindow::on_actionRemove_Data_triggered()
{
    NoPreviewDelete noPreviewDelete;
    noPreviewDelete.setModal(true);
    noPreviewDelete.exec();
}

void MainWindow::on_actionImport_triggered()
{
    ImportFolder uploadNewData;
    uploadNewData.setModal(true);
    uploadNewData.exec();
    //    UploadNewData uploadNewData;
    //    uploadNewData.setModal(true);
    //    uploadNewData.exec();
}

void MainWindow::on_pushButton_77_clicked()
{
    //    ImportFolder uploadNewData;
    //    uploadNewData.setModal(true);
    //    uploadNewData.exec();
    UploadNewData uploadNewData;
    uploadNewData.setModal(true);
    uploadNewData.exec();
}

void MainWindow::on_exportBtnPlan_clicked()
{
    if (fileFormat == ".euxml" && ui->cmbExport->currentText() == "Eulynx"){
        QMessageBox::warning(this, "Nothing to Convert!", "The input data is already Eulynx xml");
        return;
    }
    if (ui->cmbExport->currentText() != "Eulynx"){
        QMessageBox::warning(this, "File Format", "Selected format '"+ui->cmbExport->currentText()+"' is currently not available");
    }
    else{
        ExportDialog exportDialog;
        exportDialog.setModal(true);
        exportDialog.exec();
    }
}

void MainWindow::on_btnSymbol_clicked()
{
    QGraphicsSymbolContainer *svgDialog;
    svgDialog = new QGraphicsSymbolContainer();
    svgDialog->show();
}

void MainWindow::onNewProjectClicked()
{
    if (ui->tabWidget_2->tabText(ui->tabWidget_2->currentIndex()) != "Welcome" &&
             !ui->tabWidget_2->tabText(ui->tabWidget_2->currentIndex()).isEmpty()){
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Exit Current Project?", "You are trying to open a new project. . . \n\t Save ongoing project ? ",
                                                                    QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes);
        if (reply == QMessageBox::Yes){
            on_actionSave_triggered();
        }else if (reply == QMessageBox::Cancel ) return;
    }
    delete ui->tabWidget_2->widget(ui->tabWidget_2->currentIndex());
    delete ui->tabWidget_2->widget(ui->tabWidget_2->currentIndex());
    delete ui->tabWidget_2->widget(ui->tabWidget_2->currentIndex());

    NewProjectDialog newProjDialog;
    newProjDialog.setModal(true);
    newProjDialog.exec();
}

void MainWindow::closeEvent (QCloseEvent *event)
{
    if (ui->tabWidget_2->tabText(ui->tabWidget_2->currentIndex()) != "Welcome" &&
             !ui->tabWidget_2->tabText(ui->tabWidget_2->currentIndex()).isEmpty()){
        QMessageBox::StandardButton resBtn = QMessageBox::question( this, "A Plan",
                                                                    tr("Do you want to save the changes?\n"),
                                                                    QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes);
        if (resBtn == QMessageBox::No) {
            event->ignore();
            QCoreApplication::quit();
        } else if (resBtn == QMessageBox::Yes) {
            on_actionSave_triggered();
            event->accept();
            QCoreApplication::quit();
        } else if (resBtn == QMessageBox::Cancel){
            event->ignore();
        }
    }
    else {
        event->ignore();
        QCoreApplication::quit();
    }
}

// this event loads everytime after specific time interval or anything is updated on the screen
void MainWindow:: paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    if(!rightPanelTable){
        ui->tableWidget_2->setRowCount(0);
        ui->widget_147->hide();
    }
    else{
        ui->lblTrackName->setText(nameOfTrack);
        int rows = tracks->getDataKeys().length();
        ui->tableWidget_2->setRowCount(rows);

        ui->widget_147->show();
        QStringList keys = tracks->getDataKeys();
        QStringList values = tracks->getDataValues();

        //int rows = tracks->getDataKeys().length();
        for (int i=0; i< rows; i++){

            QTableWidgetItem *itemKey = new QTableWidgetItem(keys.at(i));
            itemKey->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget_2->setItem(i,0, itemKey);

            QTableWidgetItem *itemValue = new QTableWidgetItem(values.at(i));
            itemValue->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget_2->setItem(i,1, itemValue);
        }
    }

    // Add new tab while creating New Project
    if(createNewProject){
        createNewProject = false;
        addTab();

        // Enable Save, SaveAs, and Print button
        ui->actionSave->setEnabled(true);
        ui->actionSave_As->setEnabled(true);
        ui->actionPrint->setEnabled(true);
    }
}

//// GrabHang in "View" Tab
//void MainWindow::on_grabBtn_clicked()
//{
//    mouseDragMode = isChecked;
//    tracks->setDragModeMouse();
//    if(!isChecked){
//        isChecked = !isChecked;
//        ui->grabBtn->setStyleSheet("QPushButton { background-color: white; border:none; }");
//    }else{
//        isChecked = !isChecked;
//        ui->grabBtn->setStyleSheet("QPushButton { background-color: green; border:none; }");
//    }
//}

// GrabHand in "Planning" Tab
void MainWindow::on_grabBtn_2_clicked()
{
    mouseDragMode = isChecked;
    tracks->setDragModeMouse();
    if(!isChecked){
        isChecked = !isChecked;
        ui->grabBtn_2->setStyleSheet("QPushButton { background-color: white; border:none; }");
    }else{
        isChecked = !isChecked;
        ui->grabBtn_2->setStyleSheet("QPushButton { background-color: green; border:none; }");
    }
}


void MainWindow::on_grabBtn_toggled(bool checked)
{
    Q_UNUSED(checked);
}
