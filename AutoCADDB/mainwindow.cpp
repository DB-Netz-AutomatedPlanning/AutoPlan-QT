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
#include "qjsonmodel.h"
#include "signalsfromunprocessedjson.h"
#include "connecttocsharp.h"
#include <QTreeView>
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
#include <QHeaderView>
#include <QErrorMessage>

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
    , ui(new Ui::MainWindow), currentSpinNumber(0)
{
    scribbleArea= new MyOpenglWidget(this);
    setCentralWidget(scribbleArea);
    ui->setupUi(this);
    ui->toolBar->setIconSize(QSize(16, 16));

    //Context Menu
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(QPoint)),
            this, SLOT(showContextMenu(QPoint)));
    viewDockSubMenu = ui->menuView->addMenu(tr("Object Parameters"));
    createViewToolBar();

    hideMenuBar = false;
    hideFileTab = false;
    hideTabView = false;
    dockWidgetCreated = false;

    setActionMenus(false);
    readSettings();
    createDock();


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
    connect(ui->actionXML_Json, SIGNAL(triggered()), this, SLOT(onClicked_xml_json()));
    connect(ui->planBtn, SIGNAL(clicked()), this, SLOT(planningFnt()));

//    connect(viewDockSubMenu. SIGNAL(triggered()), this, SLOT(createDock()));

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

void MainWindow::removeGabageData()
{
    QString savedFilePath = projectPath + "/"+ projectName +"/"+ projectName + ".aplan";
    QFile file (savedFilePath);
    if (file.exists()) return;

    if (projectPath == "" || projectName == "") return;

    QDir dir(projectPath + "/"+ projectName);
    if (dir.exists()){
        dir.removeRecursively();
    }
}

void MainWindow::createViewToolBar()
{
    QLabel *label = new QLabel(tr("zoom"));
    ui->viewToolBar->addWidget(label);
    zoomSpinBox = new QSpinBox();
    zoomSpinBox->setRange(0,1000);
    zoomSpinBox->setValue(100);
    zoomSpinBox->setSingleStep(2);
    zoomSpinBox->setEnabled(false);
    ui->viewToolBar->addWidget(zoomSpinBox);
    connect(zoomSpinBox, SIGNAL(valueChanged(int)), this, SLOT(transformation(int)));
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
        setActionMenus(false);
        return;
    }
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Exit Attempt!", "Are you sure? ... \n Unsaved progress would be lost");
    if (reply == QMessageBox::No){
        return;
    } else if (reply == QMessageBox::Yes) {
        delete ui->tabWidget_2->widget(index);
        setActionMenus(false);
    }
    if (dockWidgetCreated) {
        viewDockSubMenu->removeAction(dock1->toggleViewAction());
        viewDockSubMenu->removeAction(dock2->toggleViewAction());
        dockWidgetCreated = !dockWidgetCreated;
    }
    removeGabageData();
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
    removeGabageData();
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
    static QRegularExpression re("\n");
    QStringList getOtherData = allData.split(re);
    fileFormat = getOtherData.at(0);
    countryCode = getOtherData.at(1);
    delete ui->tabWidget_2->widget(ui->tabWidget_2->currentIndex());
    delete ui->tabWidget_2->widget(ui->tabWidget_2->currentIndex());
    delete ui->tabWidget_2->widget(ui->tabWidget_2->currentIndex());
    addTab();   // for legacy data
    tracks->ReadOperator(selectedFile); // for symbols
    readSettings();

    // Enable Save, SaveAs, zoom, and Print button
    ui->actionSave->setEnabled(true);
    ui->actionSave_As->setEnabled(true);
    ui->actionPrint->setEnabled(true);
    zoomSpinBox->setEnabled(true);
    if (fileFormat == ".euxml") ui->actionXML_Json->setEnabled(true);
    else ui->actionXML_Json->setEnabled(false);   // to fix the condition if .euxml has previously been opened
    // Create dock widget
    if (dockWidgetCreated) {
        viewDockSubMenu->removeAction(dock1->toggleViewAction());
        viewDockSubMenu->removeAction(dock2->toggleViewAction());
        dock2->close();
        dock1->close();
        dockWidgetCreated = !dockWidgetCreated;
    }
    createDock();
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
    writeSettings();
    // Interraction: Display an indicator to the user on status bar to show that file is being saved
    ui->statusbar->setStyleSheet("QStatusBar{padding-left:8px;background:rgba(0,185,0,150);color:black;font-weight:bold;}");
    ui->statusbar->showMessage("Project saving in progress. . . ", 5000);
    QTimer::singleShot(4500, [this]{ui->statusbar->setStyleSheet("QStatusBar{padding-left:8px;background:"
                                                                 "rgba(0,0,0,0);color:black;font-weight:bold;}");});
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
{
    return true;
}

// SaveAs
void MainWindow::save()
{
    if (projectPath == "" || projectName == ""){
        QMessageBox::information(this, "No Project Detected", "Please create a project");
        ui->actionSave->setEnabled(false);
        ui->actionSave_As->setEnabled(false);
        ui->actionPrint->setEnabled(false);
        zoomSpinBox->setEnabled(false);
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
    removeGabageData();
    if (dockWidgetCreated) {
        viewDockSubMenu->removeAction(dock1->toggleViewAction());
        dock1->close();
        viewDockSubMenu->removeAction(dock2->toggleViewAction());
        dock2->close();
        dockWidgetCreated = !dockWidgetCreated;
    }
    NewProjectDialog newProjDialog;
    newProjDialog.setModal(true);
    newProjDialog.exec();
    readSettings();

    // Create dock widget
    if (dockWidgetCreated) {
        viewDockSubMenu->removeAction(dock1->toggleViewAction());
        viewDockSubMenu->removeAction(dock2->toggleViewAction());
        dock2->close();
        dock1->close();
        dockWidgetCreated = !dockWidgetCreated;
    } else createDock();
}

void MainWindow::setActionMenus(bool activate)
{
    ui->actionSave->setEnabled(activate);
    ui->actionSave_As->setEnabled(activate);
    ui->actionPrint->setEnabled(activate);
    ui->actionXML_Json->setEnabled(activate);
    zoomSpinBox->setEnabled(activate);
    viewDockSubMenu->setEnabled(activate);
}

void MainWindow::writeSettings()
{
    QSettings *settings = new QSettings("DB_Netz", "APlan");
    settings->beginGroup("outputPaths");
    settings->setValue("exportOutputPath", exportPath);
    settings->setValue("planningOutputPath", planningOutputPath);
    settings->setValue("newProjectPath", newProjectPath);

    settings->endGroup();

//    settings->beginGroup("MainWindow");
//    settings->setValue("size", size());
//    settings->setValue("position",pos());
//    settings->setValue("windowState", saveState());
//    settings->endGroup();
}

void MainWindow::readSettings()
{
    QSettings *settings = new QSettings("DB_Netz", "APlan");

    settings->beginGroup("outputPaths");
    exportPath = settings->value("exportOutputPath").toString();
    planningOutputPath = settings->value("planningOutputPath").toString();
    newProjectPath = settings->value("newProjectPath").toString();
    settings->endGroup();

//    settings->beginGroup("MainWindow");
//    resize(settings->value("size",QSize(600,500)).toSize());
//    move(settings->value("position", QPoint(200,200)).toPoint());
//    restoreState(settings->value("windowState").toByteArray());
//    settings->endGroup();
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
            writeSettings();
            QCoreApplication::quit();
        } else if (resBtn == QMessageBox::Cancel){
            event->ignore();
        }
    }
    else {
        event->ignore();
        QCoreApplication::quit();
    }
    removeGabageData();
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
        createDock();

        // Enable Save, SaveAs, and Print button
        ui->actionSave->setEnabled(true);
        ui->actionSave_As->setEnabled(true);
        ui->actionPrint->setEnabled(true);
        zoomSpinBox->setEnabled(true);
        if (fileFormat == ".euxml") ui->actionXML_Json->setEnabled(true);
        else ui->actionXML_Json->setEnabled(false);
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
//        setCursor(Qt::IBeamCursor);
    }else{
        isChecked = !isChecked;
        ui->grabBtn_2->setStyleSheet("QPushButton { background-color: green; border:none; }");
//        setCursor(Qt::ArrowCursor);
    }
}

void MainWindow::onClicked_xml_json()
{
    QTreeView * view   = new QTreeView;
    QJsonModel * model = new QJsonModel;

    view->setModel(model);
//    view->setColumnWidth(0, 100);
    view->setFont(QFont("Helvetica [Cronyx]", 10));
    view->header()->setDefaultAlignment(Qt::AlignHCenter);
    QFile file (projectPath +"/"+ projectName + "/temp2/UnprocessedJson.json");
    if (!file.exists()){
        qInfo() << "XML_JSON: File Not exist ... Also check that you've entered correct file name";
        QMessageBox::information(this, "EULYNX Object Not Found", "EULYNX XML to be converted Not Found !");
        return;
    }
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qInfo()<< "XML_JSON: " << file.errorString();
        return;
    }
    QByteArray json = file.readAll();
    model->loadJson(json);
    view->show();
//    QByteArray mjson = model->json();
//    qDebug() << mjson;
}


void MainWindow::on_grabBtn_toggled(bool checked)
{
    Q_UNUSED(checked);
}

void MainWindow::on_actionDelete_Items_triggered()
{
    if (projectName.isNull() || projectPath.isNull() || ui->tabWidget_2->tabBar()->count() <1)QMessageBox::warning(this, "Project Not Found", "No active projet found !!");
    else tracks->deleteSelectedItems();
}


void MainWindow::on_actionSelection_Mode_toggled(bool arg1)
{
    if (arg1) tracks->setDragMode(QGraphicsView::RubberBandDrag);
    else tracks->setDragMode(QGraphicsView::NoDrag);
    tracks->setInteractive(true);
}

void MainWindow::showContextMenu(QPoint pos)
{
    QMenu contextMenu(tr("Context menu"), this);

    QAction action1("Save", this);
    connect(&action1, SIGNAL(triggered()), this, SLOT(on_actionSave_triggered()));
    contextMenu.addAction(&action1);

    QAction action2("Open", this);
    connect(&action2, SIGNAL(triggered()), this, SLOT(on_actionOpen_triggered()));
    contextMenu.addAction(&action2);

    contextMenu.exec(mapToGlobal(pos));
}

void MainWindow::createDock()
{
//    if (dockWidgetCreated) {
//        createSignalObjects();
//        return;
//    }
//    QString filePath = projectPath + "/" + projectName + "/temp2/UnprocessedJson.json";
//    QFile file (filePath);
//    if(!file.exists()) {
//        qDebug()<< "UnprocessedJson not exist";
//        viewDockSubMenu->setEnabled(false);
//        return;
//    }
    createSignalObjects();
    dock1 = new QDockWidget(tr("Signal Object Info ("+projectName.toLocal8Bit()+")"), this);
    dock1->setObjectName("Signal Object Info");
    dock1->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);
    dock1->setWidget(table);

    svgDialog = new QGraphicsSymbolContainer(this);
    dock2 = new QDockWidget(tr("Symbols"));
    dock2->setObjectName("Signal Symbols");
    dock2->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    dock2->setWidget(svgDialog);

    if (!dockWidgetCreated) {
        addDockWidget(Qt::BottomDockWidgetArea,dock1);
        viewDockSubMenu->addAction(dock1->toggleViewAction());
        addDockWidget(Qt::RightDockWidgetArea, dock2);
        viewDockSubMenu->addAction(dock2->toggleViewAction());
        dockWidgetCreated = !dockWidgetCreated;
    }
    viewDockSubMenu->setEnabled(true);
}

void MainWindow::createSignalObjects()
{
    QString filePath = projectPath + "/" + projectName + "/temp2/UnprocessedJson.json";
    QFile file (filePath);
    if(!file.exists()) {
//        viewDockSubMenu->setEnabled(false);
        table = new QTableWidget(this);
        table->setColumnCount(8);
        table->setRowCount(2);

        QStringList horizontalLabel;
    //    Type " << "  Function" << "  Lateral Side " << "  Direction" << "  Linear Km" << " coordX" << "  CoordY " << "  CoordZ "
        horizontalLabel << "DB Signal Type" << "DB Signal Function" << "Lateral Side" << "Direction" << "Linear Coordinate" << "XCoord" << "YCoord " << "ZCoord";
        table->setHorizontalHeaderLabels(horizontalLabel);
        for (int i=0; i< 2; i++){
            for (int j=0; j < 8; j++){
                QTableWidgetItem *itemKey = new QTableWidgetItem(0);
                itemKey->setTextAlignment(Qt::AlignCenter);
                table->setItem(i,j, itemKey);
            }
        }
        return;
    }
    SignalsFromUnprocessedJson *signal = new SignalsFromUnprocessedJson(nullptr, filePath); //D:/Users/BKU/OlatunjiAjala/Documents/pdf/new2/temp2/UnprocessedJson.json  ; D:/Users/BKU/OlatunjiAjala/Documents/pdf/ETCS/temp2/UnprocessedJson.json
    std::vector< std::vector<QString>> allSignals = signal->signalInfos();

    table = new QTableWidget(this);
    table->setColumnCount(8);
    table->setRowCount((int)allSignals.size());

    QStringList horizontalLabel;
//    Type " << "  Function" << "  Lateral Side " << "  Direction" << "  Linear Km" << " coordX" << "  CoordY " << "  CoordZ "
    horizontalLabel << "DB Signal Type" << "DB Signal Function" << "Lateral Side" << "Direction" << "Linear Coordinate" << "XCoord" << "YCoord " << "ZCoord";
    table->setHorizontalHeaderLabels(horizontalLabel);

    for (int i=0; i< (int)allSignals.size(); i++){
        for (int j=0; j < 8; j++){
            QTableWidgetItem *itemKey = new QTableWidgetItem(allSignals.at(i)[j]);
            itemKey->setTextAlignment(Qt::AlignCenter);
            table->setItem(i,j, itemKey);
        }
    }
    table->horizontalHeader()->setVisible(true);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    table->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    table->setAlternatingRowColors(true);
    table->setSelectionMode(QAbstractItemView::ExtendedSelection);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setTextElideMode(Qt::ElideRight);

    table->setShowGrid(true);
    table->setGridStyle(Qt::DotLine);
    table->setSortingEnabled(true);
    table->setCornerButtonEnabled(true);
//    table->horizontalHeader()->setStretchLastSection(true);
}

// Function to show/hide entire tabWidget
void MainWindow::on_actionPlanning_Tab_toggled(bool arg1)
{
    if (!arg1) ui->tabWidget->hide();
    else ui->tabWidget->show();
}

void MainWindow::transformation(int)
{
    qreal factor;
    factor = (zoomSpinBox->value() > currentSpinNumber) ? 1.1 : 0.9;
    tracks->scale(factor, factor);
    currentSpinNumber = zoomSpinBox->value();
}


void MainWindow::on_actionEULYNX_Validator_triggered()
{
    QDialog dialog(this);
    dialog.setWindowTitle("Validator");
    QFormLayout form (&dialog);
    error = new QErrorMessage(&dialog);
    error2 = new QErrorMessage(&dialog);

    form.addRow(new QLabel("VALIDATE EULYNX XML"));

    // xsdPath
    xsdPath = new QLineEdit(&dialog);
    xsdPath->setPlaceholderText("Select xsd folder");
    xsdPath->setMinimumSize(QSize(300,25));
    QPushButton *btnAddXSD = new QPushButton(&dialog);
    btnAddXSD->setText("Add XSD");
    QObject::connect(btnAddXSD, SIGNAL(clicked()), this, SLOT(setxsdPath()));
    form.addRow(xsdPath, btnAddXSD);

    // xmlPath
    xmlPath = new QLineEdit(&dialog);
    xmlPath->setPlaceholderText("Path to your input (EULYNX XML)");
    xmlPath->setMinimumSize(QSize(300,25));

    QPushButton *btnAddXML = new QPushButton(&dialog);
    btnAddXML->setText("Add xml");
    QObject::connect(btnAddXML, SIGNAL(clicked()), this, SLOT(setXMLPath()));
    form.addRow(xmlPath, btnAddXML);

    // outputPath
    outputPath = new QLineEdit(&dialog);
    outputPath->setPlaceholderText("Select output folder");
    outputPath->setMinimumSize(QSize(300,25));

    QPushButton *btnAddFolder = new QPushButton(&dialog);
    btnAddFolder->setText("Add Path");
    QObject::connect(btnAddFolder, SIGNAL(clicked()), this, SLOT(setOutputpath()));
    form.addRow(outputPath, btnAddFolder);

//     Add Cancel and OK button
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
        Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);

    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    error->setWindowTitle("Info/Hint");
    error->showMessage("EULYNX Validator here was based on the first release (OLD) of the EULYNX Data Preparation model as can be found at https://www.eulynx.eu/index.php/dataprep.\n  Expected Encoding:    UTF-8 \n\n"
                       "Ensure you have correct input (including path to the xsd) \n\n   Also, wait for few seconds to process your input");
//    error->showMessage("No Problem");
//    error->show();



//     Process when OK button is clicked
    if (dialog.exec() == QDialog::Accepted) {

        QDir dir (xsdPath->text());
        if (!dir.exists() || xsdPath->text().isEmpty()) {
            QMessageBox::warning(this,"Invalid XSD Path", "You have entered an invalid input ...\n"
                                                          "please select a valid folder containing your desired xsd files" );
            return on_actionEULYNX_Validator_triggered();
        }
        QDir dir2 (outputPath->text());
        if (!dir2.exists() || outputPath->text().isEmpty()){
            QMessageBox::warning(this,"Invalid Output Folder", "Please select/enter a valid folder to store your report" );
            return on_actionEULYNX_Validator_triggered();
        }
        QFile file (xmlPath->text());
        if (!file.exists()){
            QMessageBox::warning(this,"Wrong XML Input", "Please add a valid xml");
            return on_actionEULYNX_Validator_triggered();
        }
//        error2->setWindowTitle("Hint");
//        error2->showMessage("(1) You need to wait for few seconds to process your input.. (2) Expected Input: EULYNX xml utf-8 encoding )");
//        QApplication::processEvents();
        progressBar = new QProgressBar (&dialog);
        progressBar->move((this->rect().width() /2), (this->rect().height()/2));
        progressBar->setRange(0,8);
        progressValue = 2;
        progressBar->setValue(progressValue);
        progressBar->show();
        progressBar->setWindowFlags(Qt::FramelessWindowHint);
        progressBar->setAlignment(Qt::AlignCenter);
//        progressBar->setWindowTitle("validating xml...");
        progressBar->setTextVisible(true);
        progressBar->setVisible(true);

        timer = new QTimer(this);

//        timer->setInterval(2000);
        connect(timer, &QTimer::timeout, this, &MainWindow::timeOut);
        timer->start();

        ConnectToCSharp *ctsharp = new ConnectToCSharp(nullptr, xsdPath->text().toUtf8(), xmlPath->text().toUtf8(), outputPath->text().toUtf8() );
        ctsharp->cSharp();
        cSharpIsDone = true;

        QChar soln = ctsharp->solutions();
//        QString path = outputPath->text() + "/XML Schema Report.txt";
//        QFile readFile (path);
//        qDebug()<< "PATH: " << path;
//        if (readFile.exists()){
//            qint64 size = readFile.size();
//            qDebug()<< "File Size: " << size;

        if(soln == '1') QMessageBox::information(this, "Not Valid!!", "Status :      Not Valid \nType    :      EULYNX XML\n\nReport Detail: \n       check your selected output folder for detailed report");
        else if (soln== '0') QMessageBox::information(this, " Valid!!", "Status :    GOOD (Valid) \nType    :    EULYNX XML\n\n\n\nReport Detail: \n       check your selected output folder for detailed report");
        else QMessageBox::information(this, "Oooop!", "Status cannot be determined. \nReason :      Unknown Input\nPreffered :     utf-8 Encoding\n Ensure you have made correct input \n\n ... If the problem persists, please report this error" );
        progressBar->close();
    }
}


void MainWindow::setXMLPath()
{
    QString file = QFileDialog::getOpenFileName(this, "Add File", "", "(*.xml *.euxml)" );
    if (file.isEmpty()||file.isNull()) return;
    xmlPath->setText(file);
}

void MainWindow::setOutputpath()
{
    QString path = QFileDialog::getExistingDirectory(this, ("Select Output Folder"), QDir::currentPath());
    if (path.isNull() || path.isEmpty()) return;
    outputPath->setText(path);
}

void MainWindow::setxsdPath()
{
    QString path = QFileDialog::getExistingDirectory(this, ("Select xsd Folder"), QDir::currentPath());
    if (path.isNull() || path.isEmpty()) return;
    xsdPath->setText(path);
}

void MainWindow::timeOut()
{
    if(!cSharpIsDone && progressValue < 7){
        progressValue ++;
        progressBar->setValue(progressValue);
        QApplication::processEvents();
    } else if (!cSharpIsDone && progressValue == 7) {
        progressValue++;
        progressBar->setValue(progressValue);
        QApplication::processEvents();
    }
    else {
        progressBar->setValue(8);
        timer->stop();
        QApplication::processEvents();
    }
}
