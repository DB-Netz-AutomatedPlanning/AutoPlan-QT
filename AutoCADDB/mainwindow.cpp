#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calculator.h"
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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), scribbleArea(new OpenGLClass(this))

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

    ui->comboBox_31->setEditable(true);
    ui->comboBox_31->lineEdit()->setReadOnly(true);
    ui->comboBox_31->lineEdit()->setAlignment(Qt::AlignLeft);

    ui->comboBox_32->setEditable(true);
    ui->comboBox_32->lineEdit()->setReadOnly(true);
    ui->comboBox_32->lineEdit()->setAlignment(Qt::AlignLeft);

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
    connect(ui->widget_153, SIGNAL(xRotationChanged(int)), ui->rotXSlider, SLOT(setValue(int)));
    connect(ui->widget_153, SIGNAL(yRotationChanged(int)), ui->rotYSlider, SLOT(setValue(int)));
    connect(ui->widget_153, SIGNAL(zRotationChanged(int)), ui->rotZSlider, SLOT(setValue(int)));


    //Home->Properties
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(penColor()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(penWidth()));
    connect(ui->calculator, SIGNAL(clicked(bool)), this, SLOT(openCalculator()));

    //View - Interface
    connect(ui->fileTab, SIGNAL(clicked()), this, SLOT(hideFile()));
    connect(ui->hideTabBtn,SIGNAL(clicked()),this,SLOT(hideTab()));

// OpenGLClass scribbleArea;
    //MENU actionOpen
    connect(ui->actionSave_As, SIGNAL(triggered()), this, SLOT(save()));
    connect(ui->actionNew_2, SIGNAL(triggered()), this, SLOT(addTab()));
    connect(ui->actionPrint, SIGNAL(triggered()), this, SLOT(print()));
   // connect(ui->actionPrint, SIGNAL(triggered()), scribbleArea, SLOT(&OpenGLClass::print()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(exit()));

    //connect(ui->actionNew_2, SIGNAL(triggered()), this, SLOT(open()));
//    QPushButton *button = new QPushButton;
//    button->setIcon(QIcon(":/icons/assets/line.png"));
//    button->setIconSize(QSize(20, 20));



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
    QColor newColor = QColorDialog::getColor(scribbleArea->penColor());
//    if (newColor.isValid())
//        scribbleArea->setPenColor(newColor);
}


void MainWindow::penWidth()
//! [9] //! [10]
{
    bool ok;
    int newWidth = QInputDialog::getInt(this, tr("Scribble"),
                                        tr("Select pen width:"),
                                        scribbleArea->penWidth(),
                                        1, 50, 1, &ok);
    if (ok)
        scribbleArea->setPenWidth(newWidth);
}

void MainWindow::openCalculator(){

    disconnect(ui->calculator, SIGNAL(pressed()), this, SLOT(openCalculator()));
      Calculator *calc;
    calc = new Calculator();
   // Calculator calc;
    calc->show();
    //calc->show();

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
            scribbleArea->openImage(fileName);
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
    if (fileName.isEmpty())
        return false;
    return scribbleArea->saveImage(fileName, fileFormat.constData());
}


bool MainWindow::maybeSave()
//! [17] //! [18]
{
    if (scribbleArea->isModified()) {
       QMessageBox::StandardButton ret;
       ret = QMessageBox::warning(this, tr("DB"),
                          tr("The image has been modified.\n"
                             "Do you want to save your changes?"),
                          QMessageBox::Save | QMessageBox::Discard
                          | QMessageBox::Cancel);
        if (ret == QMessageBox::Save)
            return saveFile("png");
        else if (ret == QMessageBox::Cancel)
            return false;
    }
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
            QRect rect = painter.viewport();
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
