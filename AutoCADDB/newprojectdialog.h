#ifndef NEWPROJECTDIALOG_H
#define NEWPROJECTDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QRegularExpression>
#include <QProgressDialog>
#include <QTimer>
#include <QTime>


namespace Ui {
class NewProjectDialog;
}

class NewProjectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewProjectDialog(QWidget *parent = nullptr);
    ~NewProjectDialog();
    void findOS();

    const QString &getApp() const;
    void setApp(const QString &newApp);

    const QString &getEndl() const;
    void setEndl(const QString &newEndl);
    int numberOfFileProduces();

    // Prepare functions for Concurrent running
    static void runKanten(QString unprocessed_File_Path, QString kanten_Path);
    static void runLage(QString unprocessed_File_Path, QString lage_Path);
    static void runHO(QString unprocessed_File_Path, QString ho_Path);
    static void runUH(QString unprocessed_File_Path, QString uh_Path);
    static void runKnoten(QString unprocessed_File_Path, QString knoten_Path);
    static void runKMLinie(QString unprocessed_File_Path, QString km_Path);

public slots:
//    void cancelProgressDialog();
    void timeout();

private slots:
    void on_btnBrowseProjectPath_clicked();
//    void btnBrowseProjectPath_clicked();
    void on_btnBrowseProjectData_clicked();

    void on_btnCreateNewProject_clicked();

    void on_btnCancel_clicked();

private:
    Ui::NewProjectDialog *ui;
    QStringList msg;
    QStringList fileNames;
    QString fileName;
    QString unprocessedFilePath;
//    bool isEuXml;

    QString app;
    QString endl;

    QProgressDialog *progress;
    QTimer timer;
};

#endif // NEWPROJECTDIALOG_H
