#ifndef EXPORTDIALOG_H
#define EXPORTDIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QDirIterator>
#include <QMessageBox>
#include<QSysInfo>
#include<QProcess>
#include<QDebug>
#include<QRegularExpression>
#include <previeweulynxxml.h>

namespace Ui {
class ExportDialog;
}

class ExportDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExportDialog(QWidget *parent = nullptr);
    ~ExportDialog();
    bool isAvailable = true;
    void findOS();
    void cSharp();
    const QString &getApp() const;
    void setApp(const QString &newApp);

    const QString &getEndl() const;
    void setEndl(const QString &newEndl);

private slots:
    void on_btnOpenFolder_clicked();

    void on_btnExport_clicked();

    void on_cmbStation_currentTextChanged();

    void on_btnCancel_clicked();

signals:

private:
    Ui::ExportDialog *ui;
    QString app;
    QString endl;

};

#endif // EXPORTDIALOG_H
