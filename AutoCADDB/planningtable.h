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


private slots:

    void on_btnAutoPLAN_clicked();
    void on_btnLoad_clicked();

private:
    Ui::PlanningTable *ui;
    QStandardItemModel *model;
    QString gleiskantenPath;
    QString gleisknotenPath;
    QString hoehePath;
    QString ** table;
    int rows;
    int cols;


};

#endif // PLANNINGTABLE_H
