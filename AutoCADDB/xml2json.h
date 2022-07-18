#ifndef XML2JSON_H
#define XML2JSON_H

#include <QObject>

class Xml2Json : public QObject
{
    Q_OBJECT

public:
    explicit Xml2Json(QObject *parent = nullptr, QString xml_Path = "", const QString &output_JsonPath ="");
    void serializeXml2Json();


private:
    QString xml_Path ="";
    QString output_JsonPath = "";
};

#endif
