#ifndef CONNECTTOCSHARP_H
#define CONNECTTOCSHARP_H

#include<QSysInfo>
#include <QObject>
#include<QProcess>
#include<QDebug>
#include<QRegularExpression>

class ConnectToCSharp : public QObject
{
    Q_OBJECT
public:
    explicit ConnectToCSharp(QObject *parent = nullptr, QByteArray xsdPath ="", QByteArray inputXML ="", QByteArray outputPath ="");

    const QString &getApp() const;
    void setApp(const QString &newApp);

    const QString &getEndl() const;
    void setEndl(const QString &newEndl);

    const QString &getAntwort() const;
    void setAntwort(const QString &newAntwort);
    void findOS();
    void cSharp();
    QChar solutions();


signals:

private:
    QString antwort;
    QString app;
    QString endl;
    QByteArray inputXML;
    QByteArray outputPath;
    QByteArray xsdPath;
};

#endif // CONNECTTOCSHARP_H
