#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calculator.h"
#include "planningtable.h"
#include "constructsvgdialog.h"
#include "iconslist.h"
#include "symboloptions.h"
#include "uploadnewdata.h"
#include "nopreviewdelete.h"
#include "removedata.h"
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


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), scribbleArea(new MyOpenglWidget(this))

{
    setCentralWidget(scribbleArea);

    ui->setupUi(this);
    ui->toolBar->setIconSize(QSize(16, 16));



    hideMenuBar = false;
    hideFileTab = false;
    hideTabView = false;
    ui->f_headerTabs->setGeometry(0,0,100,100);

    ui->comboBox_10->setEditable(true);
    ui->comboBox_10->lineEdit()->setReadOnly(true);
    ui->comboBox_10->lineEdit()->setAlignment(Qt::AlignCenter);

    ui->comboBox_13->setEditable(true);
    ui->comboBox_13->lineEdit()->setReadOnly(true);
    ui->comboBox_13->lineEdit()->setAlignment(Qt::AlignCenter);

    ui->comboBox_15->setEditable(true);
    ui->comboBox_15->lineEdit()->setReadOnly(true);
    ui->comboBox_15->lineEdit()->setAlignment(Qt::AlignCenter);
    ui->comboBox_15->lineEdit()->adjustSize();


    ui->comboBox_16->setEditable(true);
    ui->comboBox_16->lineEdit()->setReadOnly(true);
    ui->comboBox_16->lineEdit()->setAlignment(Qt::AlignCenter);

    ui->comboBox_17->setEditable(true);
    ui->comboBox_17->lineEdit()->setReadOnly(true);
    ui->comboBox_17->lineEdit()->setAlignment(Qt::AlignCenter);

    ui->comboBox_30->setEditable(true);
    ui->comboBox_30->lineEdit()->setReadOnly(true);
    ui->comboBox_30->lineEdit()->setAlignment(Qt::AlignCenter);

//    ui->comboBox_31->setEditable(true);
//    ui->comboBox_31->lineEdit()->setReadOnly(true);
//    ui->comboBox_31->lineEdit()->setAlignment(Qt::AlignLeft);

//    ui->comboBox_32->setEditable(true);
//    ui->comboBox_32->lineEdit()->setReadOnly(true);
//    ui->comboBox_32->lineEdit()->setAlignment(Qt::AlignLeft);

    //Close button on Tab bar
//    QToolButton *tb = new QToolButton();
//    tb->setText("+");
//    connect(tb, SIGNAL(clicked()), this, SLOT(addTab()));
//    ui->tabWidget_2->tabBar()->setTabButton(ui->tabWidget_2->tabBar()->count()-1, QTabBar::LeftSide, tb);

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

    connect(tb,SIGNAL(clicked()),this,SLOT(addTab()));
    connect(ui->tabWidget_2,SIGNAL(tabCloseRequested(int)),this,SLOT(closeTab(int)));

    //OPENGL
  //  connect(ui->widget_153, SIGNAL(xRotationChanged(int)), ui->rotXSlider, SLOT(setValue(int)));

    //connect(ui->widget_153, SIGNAL(yRotationChanged(int)), ui->rotYSlider, SLOT(setValue(int)));
    //connect(ui->widget_153, SIGNAL(zRotationChanged(int)), ui->rotZSlider, SLOT(setValue(int)));


    //Home->Properties
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(penColor()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(penWidth()));
    connect(ui->calculator, SIGNAL(clicked(bool)), this, SLOT(openCalculator()));

    //View - Interface
    connect(ui->fileTab, SIGNAL(clicked()), this, SLOT(hideFile()));
    connect(ui->hideTabBtn,SIGNAL(clicked()),this,SLOT(hideTab()));

    //Output
     connect(ui->exportBtn, SIGNAL(clicked()), this, SLOT(exportToPicture()));

// OpenGLClass scribbleArea;
    //MENU actionOpen
    connect(ui->actionSave_As, SIGNAL(triggered()), this, SLOT(save()));
    connect(ui->actionNew_2, SIGNAL(triggered()), this, SLOT(addTab()));
    connect(ui->actionPrint, SIGNAL(triggered()), this, SLOT(print()));
   // connect(ui->actionPrint, SIGNAL(triggered()), scribbleArea, SLOT(&OpenGLClass::print()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(exit()));
    connect(ui->actionAdd_symbol, SIGNAL(triggered()), this, SLOT(openSvgDialog()));
    connect(ui->actionAdd_symbol_options, SIGNAL(triggered()), this, SLOT(openSvgOptions()));

    //connect(ui->actionNew_2, SIGNAL(triggered()), this, SLOT(open()));
//    QPushButton *button = new QPushButton;
//    button->setIcon(QIcon(":/icons/assets/line.png"));
//    button->setIconSize(QSize(20, 20));
    connect(ui->planBtn, SIGNAL(clicked()), this, SLOT(planningFnt()));


   view = new QGraphicsView(scribbleArea);

}

MainWindow::~MainWindow()
{
    delete ui;
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
            qInfo() << "pressed";
            tabBar->hide();
        }else{
            qInfo() << "pressed1";
              tabBar->show();
        }
}

//Add new tab
void MainWindow::addTab()
{
     ui->tabWidget_2->insertTab(ui->tabWidget_2->count() - 1,new QOpenGLWidget(),QString("Tab %0").arg(ui->tabWidget_2->count() + 1));
     ui->tabWidget_2->setCurrentIndex(ui->tabWidget_2->count() - 2);
}

void MainWindow::closeTab(int index)
{
    delete ui->tabWidget_2->widget(index);
}


void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
        QFile file(fileName);
        readFile = fileName;
        if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
            QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
            return;
        }
        setWindowTitle(fileName);
        QTextStream in(&file);
        QString text = in.readAll();
        ui->textEdit->setText(text);
        file.close();
}



void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
      QFile file(fileName);

      if (!file.open(QFile::WriteOnly | QFile::Text)) {
          QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
          return;
      }
      readFile = fileName;
      setWindowTitle(fileName);
      QTextStream out(&file);
      QString text = ui->textEdit->toPlainText();
      out << text;
      file.close();
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

void MainWindow::openCalculator(){

    disconnect(ui->calculator, SIGNAL(pressed()), this, SLOT(openCalculator()));
      Calculator *calc;
    calc = new Calculator();
   // Calculator calc;
    calc->show();
    //calc->show();

}


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


void MainWindow::save()
//! [5] //! [6]
{
   // QAction *action = qobject_cast<QAction *>(sender());
    QByteArray fileFormat = ui->actionSave_As->data().toByteArray();
    saveFile(fileFormat);
}

void MainWindow::print()
{

    #if defined(QT_PRINTSUPPORT_LIB) && QT_CONFIG(printdialog)
        QPrinter printer(QPrinter::HighResolution);

        QPrintDialog printDialog(&printer, this);
    //! [21] //! [22]
        if (printDialog.exec() == QDialog::Accepted) {
            QPainter painter(&printer);

//            QSize size = image.size();
//            size.scale(rect.size(), Qt::KeepAspectRatio);
//            painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
//            painter.setWindow(image.rect());
//            painter.drawImage(0, 0, image);
        }
    #endif // QT_CONFIG(printdialog)

   // scribbleArea->print();
//     qInfo() << "pressed";
//    QPrinter printer(QPrinter::HighResolution);
//           printer.setOutputFormat(QPrinter::PdfFormat);
//           printer.setOutputFileName("output.pdf");
//           printer.setFullPage(true);
//           printer.setPageMargins(QMarginsF(0,0,0,0));


//           QSize minSize = ui->widget_152->minimumSizeHint();
//           int minWidth = minSize.width();
//           int minHeight = minSize.height();

//           QPainter painter(&printer);
//           painter.begin(&printer);
//           QRect rect = painter.viewport();
//            double xscale = rect.width()/double(minWidth);
//            double yscale = rect.height()/double(minHeight);
//            double scale = qMin(xscale, yscale);
//            painter.translate(rect.x() + rect.width()/2,
//              rect.y() + rect.height()/2);
//              painter.scale(scale, scale);
//           painter.translate(-width()/2, -height()/2);

//                  ui->widget_152->render(&painter);


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
                    QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
                    return;
                }
                setWindowTitle(fileName);
                QTextStream in(&file);
                QString text = in.readAll();
                ui->textEdit->setText(text);
                file.close();
}

void MainWindow::exportToPicture()
{
    QString defaultFileName = fileName;
    int index = defaultFileName.lastIndexOf(".");
    defaultFileName = defaultFileName.left(index);
    defaultFileName += ".png";
    QString s = QFileDialog::getSaveFileName(
        this, tr("Export to PNG"), defaultFileName,
        tr("Portable Network Graphics (*.png)"));

    if (!s.isEmpty())
    {
      QImage image(view->width(), view->height(), QImage::Format_RGB32);
      image.fill(QColor(Qt::white));
      QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
      QPainter painter(&image);
      view->render(&painter);
      image.save(s, "PNG");
      QApplication::restoreOverrideCursor();
    }
}

void MainWindow::planningFnt()
{
    PlanningTable *plan;
    plan = new PlanningTable();
    plan->show();
}



//void MainWindow::exportToPdf()
//{
//    QString defaultPdfFileName = fileName;
//    int index = defaultPdfFileName.lastIndexOf(".");
//    defaultPdfFileName = defaultPdfFileName.left(index);
//    defaultPdfFileName += ".pdf";
//    QString s = QFileDialog::getSaveFileName(
//        this, tr("Export to PDF"), defaultPdfFileName,
//        tr("PDF files (*.pdf)"));

//    if (!s.isEmpty())
//    {
//      QPrinter printer;
//      printer.setOutputFormat(QPrinter::PdfFormat);
//      printer.setOutputFileName(s);
//      printer.setDocName(fileName);
//      QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
//      QPainter painter(&printer);
//      view->render(&painter);
//      QApplication::restoreOverrideCursor();
//    }
//}



void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this, "About Qt");
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


void MainWindow::on_actionAdd_Data_triggered()
{
    UploadNewData uploadNewData;
    uploadNewData.setModal(true);
    uploadNewData.exec();
}

