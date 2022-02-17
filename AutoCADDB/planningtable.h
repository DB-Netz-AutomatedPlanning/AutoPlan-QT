#ifndef PLANNINGTABLE_H
#define PLANNINGTABLE_H

#include <QMainWindow>
#include <QFile>
#include <QDialog>
#include <QFileDialog>
#include<QDebug>
#include "connect2csharp.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QtGui>
#include <QtCore>

namespace Ui { class PlanningTable; }
QT_END_NAMESPACE
class MainWindow;
class MyOpenglWidget;

class PlanningTable : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlanningTable(QWidget *parent = nullptr);
    ~PlanningTable();

    const QString &getGleiskantenPath() const;
    void setGleiskantenPath(const QString &newGleiskantenPath);

    const QString &getGleisknotenPath() const;
    void setGleisknotenPath(const QString &newGleisknotenPath);

    const QString &getHoehePath() const;
    void setHoehePath(const QString &newHoehePath);


    const QString &getKmLinePath() const;
    void setKmLinePath(const QString &newKmLinePath);

    const QString &getUH_Path() const;
    void setUH_Path(const QString &newUH_Path);

    const QString &getLA_Path() const;
    void setLA_Path(const QString &newLA_Path);

private slots:

    void on_btnAutoPLAN_clicked();
//    void on_btnLoad_clicked();

    void on_btnSelectFolder_clicked();

private:
    Ui::PlanningTable *ui;
    QStandardItemModel *model;
    QString kmLinePath;
    QString gleiskantenPath;
    QString gleisknotenPath;
    QString hoehePath;
    QString UH_Path;
    QString LA_Path;
    QString ** table;
    int rows;
    int cols;


};

#endif // PLANNINGTABLE_H
