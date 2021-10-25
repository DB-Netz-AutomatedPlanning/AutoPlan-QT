#ifndef UPLOADNEWDATA_H
#define UPLOADNEWDATA_H

#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QStringList>
#include <QFile>
#include <QResource>
#include <QDirIterator>

namespace Ui {
class UploadNewData;
}

class UploadNewData : public QDialog
{
    Q_OBJECT

public:
    explicit UploadNewData(QWidget *parent = nullptr);
    ~UploadNewData();
    void lblState(bool isON);
    bool modifyData(QString fileName, QString resourceFileName, bool isAlreadyAvailable);

private slots:
    void on_btnClickHere_clicked();

    void on_btnGleisknoten_clicked();

    void on_btnCancel_clicked();


    void on_btnHoehe_clicked();

    void on_btnKMLine_clicked();

    void on_btnGleiskanten_clicked();

    void on_btnLage_clicked();

    void on_btnUberhohung_clicked();

    void on_btnOK_clicked();

//    void on_radioAddNew_clicked();

//    void on_radioModify_clicked();

private:

    Ui::UploadNewData *ui;
    QStringList path;
};

#endif // UPLOADNEWDATA_H
