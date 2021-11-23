#ifndef CONNECT2CSHARP_H
#define CONNECT2CSHARP_H

#include "symbolcontainer.h"
#include <type_traits>
#include <QObject>
#include<QSysInfo>
#include<QProcess>
#include<QDebug>
#include<QRegularExpression>
#include <QMessageBox>

class Connect2CSharp : public QObject
{
    Q_OBJECT
public:
    //Connect2CSharp();
    bool isAvailable = true; // to know if the CSharp app exist o the running PC
    QByteArray state = "plan";
    explicit Connect2CSharp(QByteArray mdbFilePath ="", QByteArray kmLinePath = "", QByteArray gleiskantenPath = "",
                            QByteArray gleisknotenPath ="", QByteArray hoehePath ="", QByteArray UH_Path ="",
                            QByteArray LA_Path ="");

    const QString &getApp() const;
    void setApp(const QString &newApp);

    const QString &getEndl() const;
    void setEndl(const QString &newEndl);

    void findOS();
    void cSharp();

    const QString &getAntwort() const;
    void setAntwort(const QString &newAntwort);
    QStringList solutionsList();
    void mainSolution();

    QString **getMainAntwort() const;
    void setMainAntwort(QString **newMainAntwort);

    int getNumberOfRows() const;
    void setNumberOfRows(int newNumberOfRows);

    int getNumberofCols() const;
    void setNumberofCols(int newNumberofCols);

private:
    QString** mainAntwort;
    QString antwort;
    QString app;
    QString endl; 
    QByteArray mdbFilePath;
    QByteArray kmLinePath;
    QByteArray gleiskantenPath;
    QByteArray gleisknotenPath;
    QByteArray hoehePath;
    QByteArray UH_Path;
    QByteArray LA_Path;
    int NumberOfRows;
    int NumberofCols;



};

#endif // CONNECT2CSHARP_H
