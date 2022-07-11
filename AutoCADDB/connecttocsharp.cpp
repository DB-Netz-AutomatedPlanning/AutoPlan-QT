#include "connecttocsharp.h"
#include <QMessageBox>
#include<QDir>

// Eulynx Validator
//QByteArray xsdPath
ConnectToCSharp::ConnectToCSharp(QObject *parent, QByteArray xsdPath, QByteArray inputXML, QByteArray outputPath) : QObject(parent)
{
    this->xsdPath = xsdPath;
    this->inputXML = inputXML;
    this->outputPath = outputPath;
}

void ConnectToCSharp::cSharp()
{
    QDir div (xsdPath);
    QFile file1 (xsdPath + "/EulynxSchemaOld/Eulynx_Schema/Generic.xsd"); //
    QFile file2 (xsdPath + "/EulynxSchemaOld/Eulynx_Schema/Signalling.xsd");
    QFile file3 (xsdPath + "/EulynxSchemaOld/RSM_Schema/Common.xsd");
    QFile file4 (xsdPath + "/Schematron/schxslt-1.8.6/2.0/pipeline-for-svrl.xsl");

    // Start the A-Plan Core application through network process (QProcess)
    QProcess c_sharp;
    findOS();   //determine the operating system
    QByteArray filePath = "eulynx-validator.exe";

    c_sharp.start(filePath);

    if(!c_sharp.waitForStarted(3000)) {
        qDebug()<< "Problem opening Validator App \n ...some linking file(s) are missing";
        return;
    }
    // write data(each parameter) to the terminal, followed by Enter key
    if(!xsdPath.endsWith(endl.toLatin1())) xsdPath.append(endl.toUtf8());
    c_sharp.write(xsdPath);
    c_sharp.waitForBytesWritten(1000);

    if(!inputXML.endsWith(endl.toLatin1())) inputXML.append(endl.toUtf8());
    c_sharp.write(inputXML);
    c_sharp.waitForBytesWritten(1000);

    if(!outputPath.endsWith(endl.toLatin1())) outputPath.append(endl.toUtf8());
    c_sharp.write(outputPath);
    c_sharp.waitForBytesWritten(1000);

    c_sharp.closeWriteChannel();
//    csharp.waitForFinished();

    if(!c_sharp.waitForFinished()) {
        // Giving maximum of 15 seconds to execute the program
        qInfo() << "The program is taking too long to close the Channel";
//        return;
    }
    this->setAntwort(c_sharp.readAll());
    QString ans = getAntwort();
    qDebug()<< "\n\n\n All<< " << ans;
}


QChar ConnectToCSharp::solutions()
{
    if (this->getAntwort().size() >0) return this->getAntwort().at(0);
    else return 'n';     // else return 'n' for no valid output
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
