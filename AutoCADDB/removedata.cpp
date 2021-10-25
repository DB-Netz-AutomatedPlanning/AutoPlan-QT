#include "removedata.h"
#include "ui_removedata.h"
#include "symbolcontainer.h"

// This class allow for prevew of data before deleting
RemoveData::RemoveData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveData)
{
    ui->setupUi(this);
    setWindowTitle("Preview Data");
//    QDirIterator iter( "Data", QDir::Dirs | QDir::NoDotAndDotDot);
//    while(iter.hasNext() )
//    {
//        QString val = iter.next();
//        ui->comboAllFolder->addItem(val.remove("Data/"));
//    }
    ui->comboAllFolder->addItem(projectName);

}

RemoveData::~RemoveData()
{
    delete ui;
}




void RemoveData::on_btnLoad_clicked()
{
    QString location = ui->comboAllFolder->currentText();
    QString path = projectPath+"/"+location+"/temp";
    QDir dir (path);
    QFileInfoList files = dir.entryInfoList(QDir::Files);
    if (ui->comboAllFolder->currentText().isEmpty()) {
        QMessageBox::information(this, "No Data Found!", "Nothing to Preview... Please create a project");
        close();
        return;
    }



    if (files.length() ==0) {
        QMessageBox::information(this, "No Data", "No Existing Data for the selected Station");
        return;
    }

    foreach(QFileInfo fi, files){
        ui->comboFiles->addItem(fi.fileName().remove("."+fi.completeSuffix()));
    }

    ui->comboFiles->setEnabled(true);
    ui->btnPreview->setEnabled(true);

}


void RemoveData::on_btnPreview_clicked()
{
    QString fileName = ui->comboFiles->currentText();
    QString location = ui->comboAllFolder->currentText();
    QFile file (projectPath+"/"+location+"/temp/" +fileName+".dbahn");
    if (!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(this, "Fatal", file.errorString());
        return;
    }

    QByteArray data = file.readAll();
    file.close();
    QByteArray decoded = QByteArray::fromHex(data);
    QTextStream in (decoded);
    ui->textBrowserPreview->setText(in.readAll());
    ui->textBrowserPreview->setEnabled(true);
    ui->btnDelete->setEnabled(true);
}


void RemoveData::on_comboAllFolder_currentTextChanged()
{
    ui->btnDelete->setEnabled(false);
    ui->textBrowserPreview->clear();
    ui->textBrowserPreview->setEnabled(false);
    ui->comboFiles->setEnabled(false);
    ui->btnPreview->setEnabled(false);
}


void RemoveData::on_comboFiles_currentTextChanged()
{
    ui->btnDelete->setEnabled(false);
    ui->textBrowserPreview->clear();
    ui->textBrowserPreview->setEnabled(false);

}


void RemoveData::on_btnDelete_clicked()
{
    QMessageBox::StandardButton response = QMessageBox::question(this, "Info", "Are you sure? ...\n Deleted file CANNOT be retrieved!!", QMessageBox::Yes |QMessageBox::No);
    if (response == QMessageBox::No) return;

    QString fileName = ui->comboFiles->currentText();
    QString location = ui->comboAllFolder->currentText();
    QFile file (projectPath+"/"+location+"/temp/" +fileName+".dbahn");
    if (!file.remove()){
        QMessageBox::information(this, "Fatal", file.errorString());
        close();
    }
    file.remove();
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Info", "Deleted Successfully !! ...\n Did you want to perform another operation?", QMessageBox::Yes |QMessageBox::No);
    if (reply == QMessageBox::No) close();

    ui->btnDelete->setEnabled(false);
    ui->textBrowserPreview->setEnabled(false);
    ui->comboFiles->setEnabled(false);
    ui->btnPreview->setEnabled(false);
}


void RemoveData::on_btnCancel_clicked()
{
    close();
}

