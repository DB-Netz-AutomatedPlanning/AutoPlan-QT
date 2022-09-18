#ifndef PLANNINGTABLE_H
#define PLANNINGTABLE_H

#include <QMainWindow>
#include <QFile>
#include <QDialog>
#include <QFileDialog>
#include <QDebug>
#include "connect2csharp.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QtGui>
#include <QtCore>
#include <QTimer>

namespace Ui { class PlanningTable; }
QT_END_NAMESPACE
class MainWindow;
//class MyOpenglWidget;

class PlanningTable : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlanningTable(QWidget *parent = nullptr);
    ~PlanningTable();

    void displayResultTable();

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

    void on_btnSelectFolder_clicked();
    void timeout();

private:
    Ui::PlanningTable *ui;
    Connect2CSharp *csharp;
    QString kmLinePath;
    QString gleiskantenPath;
    QString gleisknotenPath;
    QString hoehePath;
    QString UH_Path;
    QString LA_Path;
    QString ** table;
    int rows;
    int cols;

    //ProgressBar
    int progressBarValue;
    bool isStart;
    bool isEnd;
    QTimer *timer;


    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event) override;
};

#endif // PLANNINGTABLE_H
