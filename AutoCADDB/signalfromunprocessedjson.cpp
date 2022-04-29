#include "signalfromunprocessedjson.h"
#include "symbolcontainer.h"
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>

SignalFromUnprocessedJson::SignalFromUnprocessedJson(QObject *parent, QString filePath, const QString &newFilePath)
    : QObject{parent}
{
    this->filePath = filePath;
    this->newFilePath = newFilePath;

    QFile file (filePath);
    if (!file.exists()){
        qInfo() << "File Not exist ... Also check that you've entered correct file name";
        return;
    }
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qInfo()<< file.errorString();
        return;
    }
    QString allData = file.readAll();
    file.close();
    document = QJsonDocument::fromJson(allData.toUtf8());
}

void SignalFromUnprocessedJson::searchName()
{
    std::vector<QString> name;
    //    std::vector<QString> id;
    int i=0;
    while (!document["hasDataContainer"][0]["ownsRsmEntities"]["ownsSignal"][i].isUndefined()){
        qDebug()<< "NAME: " << document["hasDataContainer"][0]["ownsRsmEntities"]["ownsSignal"][i]["name"].toString();
        name.push_back(document["hasDataContainer"][0]["ownsRsmEntities"]["ownsSignal"][i]["name"].toString());
        i+=1;
    }
    setName(name);
}

void SignalFromUnprocessedJson::searchLocation()
{
    std::vector<QString> kmValues;
    int j=0;
    while (!document["hasDataContainer"][0]["ownsRsmEntities"]["ownsSignal"][j].isUndefined()){

        // first get the ref of the location
        QString locationRef = document["hasDataContainer"][0]["ownsRsmEntities"]["ownsSignal"][j]["locations"][0]["ref"].toString();
        qDebug()<< "Location ref: "<< locationRef;
        QString usesLocationRef;

        // Match current locationRef with usesLocationRef;
        int l=0;
        while (!document["hasDataContainer"][0]["ownsRsmEntities"]["usesLocation"][l].isUndefined()){
            QString locationID = document["hasDataContainer"][0]["ownsRsmEntities"]["usesLocation"][l]["id"].toString();

            if(locationRef == locationID){
                qDebug()<< "Same with ID: "<< locationID;
                usesLocationRef = document["hasDataContainer"][0]["ownsRsmEntities"]["usesLocation"][l]["coordinates"][0]["ref"].toString();
                qDebug()<< "UsesLocationRef: "<< usesLocationRef;
                break;
            }
            l++;
        }
        qDebug()<< "UsesLocationRef: "<< usesLocationRef;
        if (usesLocationRef != ""){
            std::vector <QString> coordValue = lookForCoord(usesLocationRef);
    //        qDebug()<< "Entering...";
    //        qDebug()<< "0000 :";
    //        qDebug()<< "0 :"<< coordValue[0].toDouble();

            kmValues.push_back(coordValue[0]);

        }
        j++;
    }
    qDebug()<< "FEL";
    setLocation(kmValues);
}

void SignalFromUnprocessedJson::searchLateralSideAndDirection()
{
    std::vector<QString> side;
    std::vector<QString> direction;
    int j=0;
    while (!document["hasDataContainer"][0]["ownsRsmEntities"]["ownsSignal"][j].isUndefined()){

        // first get the ref of the location
        QString locationRef = document["hasDataContainer"][0]["ownsRsmEntities"]["ownsSignal"][j]["locations"][0]["ref"].toString();
        QString lateralSide;

        // Match current locationRef with usesLocationRef;
        int l=0;
        while (!document["hasDataContainer"][0]["ownsRsmEntities"]["usesLocation"][l].isUndefined()){
            QString locationID = document["hasDataContainer"][0]["ownsRsmEntities"]["usesLocation"][l]["id"].toString();

            // Get the enum of sides and direction
            if(locationRef == locationID){
                QString tempSide = "";
                QString tempDir = "";
                tempSide = QString::number(document["hasDataContainer"][0]["ownsRsmEntities"]["usesLocation"][l]["associatedNetElements"][0]["isLocatedToSide"].toDouble());
                qDebug()<< "TempSide: " << tempSide;
                if (tempSide == "1"){
                    lateralSide = "left";
                } else if (tempSide == "2") {
                    lateralSide = "right";
                } else lateralSide = "null";
                tempDir = QString::number(document["hasDataContainer"][0]["ownsRsmEntities"]["usesLocation"][l]["associatedNetElements"][0]["appliesInDirection"].toDouble());
                qDebug()<< "TempDir "<< tempDir;
                side.push_back(lateralSide);
                direction.push_back(tempDir);
                break;
            }
            l++;
        }
        j++;
    }
    setLateralSide(side);
    setDirection(direction);
}

void SignalFromUnprocessedJson::createSignalJson()
{
    searchLocation();
    searchName();
    searchLateralSideAndDirection();

    std::vector<QString> names = getName();
    std::vector<QString> locations = getLocation();
    std::vector<QString> sides = getLateralSide();
    std::vector<QString> directions = getDirection();

    if ((name.size() != locations.size()) || (name.size() != sides.size()) || (name.size() != directions.size())) {
        progressValue++;  // increment the progress bar counter and exit
        qDebug()<< "Progress : " << progressValue;
        return;
    }
    QJsonArray allFeatures;
    for (int i=0; i< (int)names.size(); i++){
        QJsonObject prop = properties (names, locations, sides,directions, i);
        allFeatures.append(prop);
    }

    /* If there is no Topology data (coordinate(s)), there is nothing to
    view, Hence, no need of creating internal json document*/
    if (allFeatures.isEmpty()){
        progressValue++;  // increment the progress bar counter and exit
        qDebug()<< "Progress : " << progressValue;
        return;
    }
    QJsonObject content;
    content.insert("type", "FeatureCollection");
    content.insert("name", "Signal_Contents");
    content.insert("features", allFeatures);

    QJsonDocument document;
    document.setObject( content );
    QByteArray bytes = document.toJson();  //QJsonDocument::Indented
    QFile file( newFilePath );
    if( file.open( QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate ) )
    {
        QTextStream iStream( &file );

        //iStream.setCodec( "utf-8" );
        iStream << bytes;
        file.close();
    }
    else qDebug()<< "File opening failed: " << file.errorString();
    progressValue++;
    qDebug()<< "Progress : " << progressValue;

}

QJsonObject SignalFromUnprocessedJson::properties(std::vector<QString> name,
                                std::vector<QString> location, std::vector<QString> side,
                                                  std::vector<QString> direction, int index)
{
    QJsonObject prop;

    prop.insert("DB Signal Function", name.at(index));
    prop.insert("Linear Coordinate", location.at(index));
    prop.insert("Lateral Side", side.at(index));
    prop.insert("Direction", direction.at(index));
    if (name.at(index) == "Entry Signal" || name.at(index) == "Exit Signal"){
        prop.insert("Lateral Distance", "3.1");
    }
    return prop;
}


std::vector<QString> SignalFromUnprocessedJson::lookForCoord(QString currentRef)
{
    std::vector <QString> values;

    int j =0;
    while (!document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
           ["usesPositioningSystemCoordinate"][j].isUndefined()) {

        QString current = document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
                ["usesPositioningSystemCoordinate"][j]["id"].toString();
        //        qDebug() << "CURRENT"<< current;

        if (current == currentRef){
            if(!document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
                    ["usesPositioningSystemCoordinate"][j]["measure"].isUndefined()){
                if(document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
                        ["usesPositioningSystemCoordinate"][j]["measure"].isString()){
                    values.push_back(document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
                            ["usesPositioningSystemCoordinate"][j]["measure"].toString());
                } else {
                    values.push_back(QString::number(document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
                            ["usesPositioningSystemCoordinate"][j]["measure"].toDouble()));
                }
            } else {
                // x- axis
                if(document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
                        ["usesPositioningSystemCoordinate"][j]["x"].isString()){
                    values.push_back(document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
                            ["usesPositioningSystemCoordinate"][j]["x"].toString());
                } else {
                    values.push_back(QString::number(document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
                            ["usesPositioningSystemCoordinate"][j]["x"].toDouble(), 'f', 8));
                }

                // y-axis
                if(document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
                        ["usesPositioningSystemCoordinate"][j]["y"].isString()){
                    values.push_back(document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
                            ["usesPositioningSystemCoordinate"][j]["y"].toString());
                } else {
                    values.push_back(QString::number(document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
                            ["usesPositioningSystemCoordinate"][j]["y"].toDouble(), 'f', 8));
                }

                // z-axis
                if(document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
                        ["usesPositioningSystemCoordinate"][j]["z"].isString()){
                    values.push_back(document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
                            ["usesPositioningSystemCoordinate"][j]["z"].toString());
                } else {
                    values.push_back(QString::number(document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
                            ["usesPositioningSystemCoordinate"][j]["z"].toDouble(), 'f', 8));
                }
            }
            break;
        }
        j++;
    }
    return values;
}

const std::vector<QString> &SignalFromUnprocessedJson::getName() const
{
    return name;
}

void SignalFromUnprocessedJson::setName(const std::vector<QString> &newName)
{
    name = newName;
}

const std::vector<QString> &SignalFromUnprocessedJson::getLocation() const
{
    return location;
}

void SignalFromUnprocessedJson::setLocation(const std::vector<QString> &newLocation)
{
    location = newLocation;
}

const std::vector<QString> &SignalFromUnprocessedJson::getLateralSide() const
{
    return lateralSide;
}

void SignalFromUnprocessedJson::setLateralSide(const std::vector<QString> &newLateralSide)
{
    lateralSide = newLateralSide;
}

const std::vector<QString> &SignalFromUnprocessedJson::getDirection() const
{
    return direction;
}

void SignalFromUnprocessedJson::setDirection(const std::vector<QString> &newDirection)
{
    direction = newDirection;
}
