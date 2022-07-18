#include "xml2json.h"
#include <QFile>
#include "xml2json.hpp"
#include <QDebug>
#include <QJsonDocument>


Xml2Json::Xml2Json(QObject *parent, QString xml_Path, const QString &output_JsonPath) : QObject{parent}

{
    this->xml_Path = xml_Path;
    this->output_JsonPath = output_JsonPath;
}

void Xml2Json::serializeXml2Json()
{
    QFile file (this->xml_Path);
    if (!file.exists()) return;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<< file.errorString();
        return;
    }
    QString allXMLData = file.readAll();
    file.close();
    std::string allData = allXMLData.toStdString();
    std::string data2Json = xml2json(allData.c_str());

    QJsonDocument doc = QJsonDocument::fromJson(data2Json.data());
    QByteArray bytes = doc.toJson(QJsonDocument::Indented);

    QFile output_file( this->output_JsonPath );
    if( output_file.open( QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate ) )
    {
        QTextStream iStream( &output_file );
        iStream << bytes;
        file.close();
    }
    else { qDebug()<< "Output File opening failed (xml2Json): " << file.errorString();}
}
