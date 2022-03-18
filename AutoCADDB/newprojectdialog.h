#ifndef NEWPROJECTDIALOG_H
#define NEWPROJECTDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QRegularExpression>


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

    QString app;
    QString endl;
};

#endif // NEWPROJECTDIALOG_H
