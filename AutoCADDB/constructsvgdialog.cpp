#include "constructsvgdialog.h"
#include "ui_constructsvgdialog.h"

#include <QtWidgets>
#include <QSvgRenderer>
#include <QtGui>
#include <QWidget>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QStringList>
#include <QTextStream>
#include "svgdialogview.h"

#include <QSvgGenerator>

static inline QString picturesLocation()
{
    //    if (!window.loadFile(parser.positionalArguments().value(0, QLatin1String(":/files/bubbles.svg"))))
    //        return -1;
    return QStandardPaths::standardLocations(QStandardPaths::PicturesLocation).value(0, QDir::currentPath());
}

ConstructSvgDialog::ConstructSvgDialog() :
    QMainWindow(),
    m_view(new SvgDialogView),
    m_zoomLabel(new QLabel),
    ui(new Ui::ConstructSvgDialog)
{




    ui->setupUi(this);

    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(openFile()));
     connect(ui->saveSvgBtn, SIGNAL(clicked()), this, SLOT(saveSvg()));

setCentralWidget(m_view);

}


void ConstructSvgDialog::openFile()
{
    QFileDialog fileDialog(this);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setMimeTypeFilters(QStringList() << "image/svg+xml" << "image/svg+xml-compressed");
    fileDialog.setWindowTitle(tr("Open SVG File"));
    if (m_currentPath.isEmpty())
        fileDialog.setDirectory(picturesLocation());

    while (fileDialog.exec() == QDialog::Accepted && !loadFile(fileDialog.selectedFiles().constFirst()))
        ;


}


bool ConstructSvgDialog::loadFile(const QString &fileName)
{
    if (!QFileInfo::exists(fileName) || !m_view->openFile(fileName)) {
        QMessageBox::critical(this, tr("Open SVG File"),
                              tr("Could not open file '%1'.").arg(QDir::toNativeSeparators(fileName)));
        return false;
    }

    if (!fileName.startsWith(":/")) {
        m_currentPath = fileName;
        setWindowFilePath(fileName);
        const QSize size = m_view->svgSize();
        const QString message =
            tr("Opened %1, %2x%3").arg(QFileInfo(fileName).fileName()).arg(size.width()).arg(size.width());
        statusBar()->showMessage(message);
    }

  //  m_outlineAction->setEnabled(true);
  //  m_backgroundAction->setEnabled(true);

    const QSize availableSize = this->screen()->availableGeometry().size();
    resize(m_view->sizeHint().expandedTo(availableSize / 4) + QSize(80, 80 + menuBar()->height()));

    return true;
}

//void ConstructSvgDialog::setRenderer(int renderMode)
//{
//    m_view->setRenderer(static_cast<SvgDialogView::RendererType>(renderMode));
//}

void ConstructSvgDialog::on_checkBox_clicked()
{

      if (ui->checkBox->isChecked()) {
          selectedOption = "Filled";
          m_view->displaySymbol(selectedOption);
      }
      else {
          selectedOption = "noFilled";
          m_view->displaySymbol(selectedOption);
      }
}


void ConstructSvgDialog::on_checkBox_2_clicked()
{


    if (ui->checkBox_2->isChecked()) {
      //  stream << "Option 1 is Checked" ;
        selectedOption = "Mehr";
        m_view->displaySymbol(selectedOption);
    }
    else {
        selectedOption = "noMehr";
        m_view->displaySymbol(selectedOption);
    }
}

void ConstructSvgDialog::on_checkBox_3_clicked()
{

        if (ui->checkBox_3->isChecked()) {
          //  stream << "Option 1 is Checked" ;
            selectedOption = "Hauptsignal";
            m_view->displaySymbol(selectedOption);
        }
        else {
            selectedOption = "noHauptsignal";
            m_view->displaySymbol(selectedOption);
        }
}


void ConstructSvgDialog::on_checkBox_4_clicked()
{

        if (ui->checkBox_4->isChecked()) {
          //  stream << "Option 1 is Checked" ;
            selectedOption = "Arrow";
            m_view->displaySymbol(selectedOption);
        }
        else {
            selectedOption = "noArrow";
            m_view->displaySymbol(selectedOption);
        }
}

//! [save SVG]
void ConstructSvgDialog::saveSvg()
{
    m_view->saveSVG();

//![end painting]
}
//! [save SVG]





