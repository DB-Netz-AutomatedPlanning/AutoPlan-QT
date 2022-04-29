#include "readeulynxsignals.h"
#include "symbolcontainer.h"
#include <QFile>
#include <QJsonDocument>


ReadEulnxSignals::ReadEulnxSignals(QString pPath, QString pName)
{
    this->pPath = pPath;
    this->pName = pName;
}

void ReadEulnxSignals::readMainSignals()
{
    QFile file (pPath+"/"+pName+"/temp/Signal.dbahn");
    if (!file.exists()){
        qInfo() << "File Not exist ... Also check that you've entered correct file name";
        return;
    }
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qInfo()<< file.errorString();
        return;
    }

    QByteArray data = file.readAll();  //&file);
    QByteArray decoded = QByteArray::fromHex(data);
    QString allData = QString(decoded);
    file.close();
    QJsonDocument document = QJsonDocument::fromJson(allData.toUtf8());
    int count =0;
    while(!document["features"][count].isUndefined()){
        count = count+1;
    }
    if (count == 0){
        qInfo() << "No Signal found !";
        return;
    }
    int counter =0;
    while(counter < count){
        QMap<QString, QString> object;

        QString DBSignalFunction = document["features"][counter]["DB Signal Function"].toString();
//        qDebug()<< "DBSIGNAL " << DBSignalFunction;
        QString direction = document["features"][counter]["Direction"].toString();
//        qDebug()<< "dir " << direction;
        QString lateralDistance = document["features"][counter]["Lateral Distance"].toString();
//        qDebug()<< "latDist " << lateralDistance;
        QString lateralSide = document["features"][counter]["Lateral Side"].toString();
//        qDebug()<< "LAT_SID " << lateralSide;
        QString linearCoordinate = document["features"][counter]["Linear Coordinate"].toString();
//        qDebug()<< "LIN_COORD " << linearCoordinate;

        object.insert("DB Signal Function", DBSignalFunction);
        object.insert("Direction", direction);
        object.insert("Lateral Distance", lateralDistance);
        object.insert("Lateral Side", lateralSide);
        object.insert("Linear Coordinate", linearCoordinate);
        parameters.push_back(object);
        counter++;
    }
    this->setParameters(parameters);
}

const std::vector<QMap<QString, QString> > &ReadEulnxSignals::getParameters() const
{
    return parameters;
}

void ReadEulnxSignals::setParameters(const std::vector<QMap<QString, QString> > &newParameters)
{
    parameters = newParameters;
}
