#include "connecttocsharp.h"


ConnectToCSharp::ConnectToCSharp(QObject *parent, QByteArray data1, QByteArray data2) : QObject(parent)
{
    this->data1 = data1;
    this->data2 = data2;
}


void ConnectToCSharp::cSharp()
{
    QProcess csharp;
    findOS();   //determine the operating system

    // replace this with corresponding filepath
    QString filePath = "D:/Users/BKU/SayliArjunPednekar/Desktop/publish/PhelzApp.exe";
    csharp.start(filePath);
    if(!csharp.waitForStarted(3000)) {
        qInfo()<< "Problem with opening of App";
        return;
    }

    // write data(each parameter) to the terminal, followed by Enter key

    if(!data1.endsWith(endl.toLatin1())) data1.append(endl.toUtf8());
    csharp.write(data1);
    csharp.waitForBytesWritten(1000);

    if(!data2.endsWith(endl.toLatin1())) data2.append(endl.toUtf8());
    csharp.write(data2);
    csharp.waitForBytesWritten(1000);

    csharp.closeWriteChannel();
    if(!csharp.waitForFinished(3000)) {
        // Giving maximum of 3 seconds to execute the program
        qInfo() << "The program is taking too long to close the Channel";
        return;
    }

    QByteArray result = csharp.readAll();
    this->setAntwort(result);
}


QStringList ConnectToCSharp::solutions()
{
    QStringList sol1; // = this->antwort.split("\n");
    QStringList sol = this->getAntwort().split(QRegularExpression("\\n"), Qt::SkipEmptyParts);
    foreach(QString value, sol){
        sol1.append(value.replace('\r',""));
    }
    return sol1;
}

const QString &ConnectToCSharp::getApp() const
{
    return app;
}

void ConnectToCSharp::setApp(const QString &newApp)
{
    app = newApp;
}

const QString &ConnectToCSharp::getEndl() const
{
    return endl;
}

void ConnectToCSharp::setEndl(const QString &newEndl)
{
    endl = newEndl;
}

const QString &ConnectToCSharp::getAntwort() const
{
    return antwort;
}

void ConnectToCSharp::setAntwort(const QString &newAntwort)
{
    antwort = newAntwort;
}

void ConnectToCSharp::findOS()
{
    // Linux
    this->setApp("bash");
    this->setEndl("\n");

#ifdef Q_OS_WIN
    //Windows
    this->setApp("cmd");
    this->setEndl("\n");
//    this->setEndl("\r\n");

#elif Q_OS_MACOS
    //Mac
    this->setApp("zsh");
    this->setEndl("\n");
#endif
}









