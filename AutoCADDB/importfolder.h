#ifndef IMPORTFOLDER_H
#define IMPORTFOLDER_H

#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QStringList>
#include <QFile>
#include <QResource>
#include <QDirIterator>
#include<QDir>


namespace Ui {
class ImportFolder;
}

class ImportFolder : public QDialog
{
    Q_OBJECT

public:
    explicit ImportFolder(QWidget *parent = nullptr);
    ~ImportFolder();

private slots:
    void on_rdAdd_clicked();

    void on_rdModify_clicked();

    void on_btnEnable_clicked();

    void on_btnImport_clicked();

private:
    Ui::ImportFolder *ui;
    QStringList msg;
};

#endif // IMPORTFOLDER_H
