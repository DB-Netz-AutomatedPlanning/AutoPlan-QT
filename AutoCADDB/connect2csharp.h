#ifndef CONNECT2CSHARP_H
#define CONNECT2CSHARP_H
#include <type_traits>

#include <QObject>
#include<QSysInfo>
#include<QProcess>
#include<QDebug>
#include<QRegularExpression>

class Connect2CSharp : public QObject
{
    Q_OBJECT
public:
    //Connect2CSharp();
    explicit Connect2CSharp(QByteArray gleiskantenPath = "", QByteArray gleisknotenPath ="", QByteArray hoehePath ="");

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
    QByteArray gleiskantenPath;
    QByteArray gleisknotenPath;
    QByteArray hoehePath;
    int NumberOfRows;
    int NumberofCols;


};

#endif // CONNECT2CSHARP_H
