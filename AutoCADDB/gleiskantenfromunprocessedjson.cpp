#include "gleiskantenfromunprocessedjson.h"
#include "symbolcontainer.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QVector>
#include <QTextStream>
#include <QDebug>

GleiskantenFromUnprocessedJson::GleiskantenFromUnprocessedJson(QObject *parent, QString filePath, const QString &newFilePath)
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

void GleiskantenFromUnprocessedJson::searchNameAndID()
{
    std::vector<QString> name;
    std::vector<QString> id;
    int i=0;
    while (!document["hasDataContainer"][0]["ownsRsmEntities"]["usesTrackTopology"]["usesNetElement"][i].isUndefined()){

        QString currentName = document["hasDataContainer"][0]["ownsRsmEntities"]["usesTrackTopology"]["usesNetElement"][i]["name"].toString();
        if (currentName != "kilometerLineSegment" && currentName != "kilometerLine"){
            try {
                name.push_back(document["hasDataContainer"][0]["ownsRsmEntities"]["usesTrackTopology"]
                        ["usesNetElement"][i]["name"].toString());
                id.push_back(document["hasDataContainer"][0]["ownsRsmEntities"]["usesTrackTopology"]
                        ["usesNetElement"][i]["id"].toString());

            }  catch (_exception ex) {
            }
        }

        i+=1;
    }
    setName(name);
    setId(id);
}

void GleiskantenFromUnprocessedJson::searchElementLength()
{
    std::vector<QString> elementLength;
    int i=0;
    while (!document["hasDataContainer"][0]["ownsRsmEntities"]["usesTrackTopology"]["usesNetElement"][i].isUndefined()){

        QString name = document["hasDataContainer"][0]["ownsRsmEntities"]["usesTrackTopology"]["usesNetElement"][i]["name"].toString();
        if (name != "kilometerLineSegment" && name != "kilometerLine"){

            if (document["hasDataContainer"][0]["ownsRsmEntities"]["usesTrackTopology"]["usesNetElement"]
                    [i]["elementLength"]["quantity"][0]["value"].isString()){
                elementLength.push_back(document["hasDataContainer"][0]["ownsRsmEntities"]["usesTrackTopology"]
                        ["usesNetElement"][i]["elementLength"]["quantity"][0]["value"].toString());
            } else {
                elementLength.push_back(QString::number(document["hasDataContainer"][0]["ownsRsmEntities"]
                        ["usesTrackTopology"]["usesNetElement"][i]["elementLength"]["quantity"][0]["value"].toDouble()));
            }
        }
        i++;
    }
    setElementLength(elementLength);
}


void GleiskantenFromUnprocessedJson::searchStartRefAndStartKm()
{

    std::vector<QString> startRef;
    std::vector<QString> endRef;

    std::vector<QString> startValues;
    std::vector<QString> endValues;
    int i=0;
    while (!document["hasDataContainer"][0]["ownsRsmEntities"]["usesTrackTopology"]["usesNetElement"][i].isUndefined()){

        QString name = document["hasDataContainer"][0]["ownsRsmEntities"]["usesTrackTopology"]["usesNetElement"][i]["name"].toString();
        if (name != "kilometerLineSegment" && name != "kilometerLine"){

            QString refStart = document["hasDataContainer"][0]["ownsRsmEntities"]["usesTrackTopology"]
                    ["usesNetElement"][i]["associatedPositioning"][0]["intrinsicCoordinates"][0]
                    ["coordinates"][0]["ref"].toString();
            startRef.push_back(refStart);
            QString refEnd = document["hasDataContainer"][0]["ownsRsmEntities"]["usesTrackTopology"]["usesNetElement"]
                    [i]["associatedPositioning"][0]["intrinsicCoordinates"][1]["coordinates"][0]["ref"].toString();
            endRef.push_back(refEnd);

            // Search for the actual value
            std::vector<QString> startValue = lookForCoord(refStart);
            std::vector<QString> endValue = lookForCoord(refEnd);
            startValues.push_back(startValue[0]);
            endValues.push_back(endValue[0]);
        }
        i+=1;
    }
    setStartRef(startRef);
    setEndRef(endRef);
    setStartValues(startValues);
    setEndValues(endValues);
}


// ToDo: This function needs to be optimized
std::vector<QString> GleiskantenFromUnprocessedJson::lookForCoord(QString currentRef)
{
    std::vector <QString> values;


//    for (int i=0; i<50; i++){
//        int k =i;
//        while (!document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
//               ["usesPositioningSystemCoordinate"][k].isUndefined()){
//            QString current = document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
//                    ["usesPositioningSystemCoordinate"][k]["id"].toString();
//            if (current == currentRef){
//                if(!document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
//                        ["usesPositioningSystemCoordinate"][k]["measure"].isUndefined()){
//                    if(document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
//                            ["usesPositioningSystemCoordinate"][k]["measure"].isString()){
//                        values.push_back(document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
//                                ["usesPositioningSystemCoordinate"][k]["measure"].toString());
//                    } else {
//                        values.push_back(QString::number(document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
//                                ["usesPositioningSystemCoordinate"][k]["measure"].toDouble()));
//                    }
//                } else {
//                    // x- axis
//                    if(document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
//                            ["usesPositioningSystemCoordinate"][k]["x"].isString()){
//                        //                    qDebug() <<"String:"<< document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
//                        //                            ["usesPositioningSystemCoordinate"][j]["x"].toString();
//                        values.push_back(document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
//                                ["usesPositioningSystemCoordinate"][k]["x"].toString());
//                    } else {
//                        values.push_back(QString::number(document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
//                                ["usesPositioningSystemCoordinate"][k]["x"].toDouble(), 'f', 8));
//                        //                    qDebug()<< "Double: "<< document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
//                        //                            ["usesPositioningSystemCoordinate"][j]["x"].toDouble();
//                    }

//                    // y-axis
//                    if(document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
//                            ["usesPositioningSystemCoordinate"][k]["y"].isString()){
//                        values.push_back(document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
//                                ["usesPositioningSystemCoordinate"][k]["y"].toString());
//                    } else {
//                        values.push_back(QString::number(document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
//                                ["usesPositioningSystemCoordinate"][k]["y"].toDouble(), 'f', 8));
//                    }

//                    // z-axis
//                    if(document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
//                            ["usesPositioningSystemCoordinate"][k]["z"].isString()){
//                        values.push_back(document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
//                                ["usesPositioningSystemCoordinate"][k]["z"].toString());
//                    } else {
//                        values.push_back(QString::number(document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
//                                ["usesPositioningSystemCoordinate"][k]["z"].toDouble(), 'f', 8));
//                    }
//                }
//                return values;

//            }
//        k = k+50;
//        }
//    }
//    return values;


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
                    //                    qDebug() <<"String:"<< document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
                    //                            ["usesPositioningSystemCoordinate"][j]["x"].toString();
                    values.push_back(document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
                            ["usesPositioningSystemCoordinate"][j]["x"].toString());
                } else {
                    values.push_back(QString::number(document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
                            ["usesPositioningSystemCoordinate"][j]["x"].toDouble(), 'f', 8));
                    //                    qDebug()<< "Double: "<< document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
                    //                            ["usesPositioningSystemCoordinate"][j]["x"].toDouble();
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


// return array of coordinates based on each segment
std::vector<std::vector<double> > GleiskantenFromUnprocessedJson::arrayOfCoordinates()
{
    qDebug()<< "Look up -- Gleiskanten . ";
    qDebug()<< "Look up -- for Gleiskanten . . . ";
    std::vector<std::vector<double> > allCoord;

//    int segmentCount=0;
//    while (!document["hasDataContainer"][0]["ownsRsmEntities"]["usesTrackTopology"]["usesNetElement"][segmentCount].isUndefined()){
//        segmentCount++;
//    }
//    totalValue+=segmentCount;
//    qDebug()<< "TOTALFROMKANTEN" << totalValue;

    int i=0;
    while (!document["hasDataContainer"][0]["ownsRsmEntities"]["usesTrackTopology"]["usesNetElement"][i].isUndefined()){
        QString name = document["hasDataContainer"][0]["ownsRsmEntities"]["usesTrackTopology"]["usesNetElement"][i]["name"].toString();
        if (name == "kilometerLineSegment" || name == "kilometerLine"){
            i++;
        } else {

            std::vector<double> segmentData;
            int j =0;
            while (!document["hasDataContainer"][0]["ownsRsmEntities"]["usesTrackTopology"]
                   ["usesNetElement"][i]["associatedPositioning"][1]["intrinsicCoordinates"][j].isUndefined()){
                QString ref = document["hasDataContainer"][0]["ownsRsmEntities"]["usesTrackTopology"]
                        ["usesNetElement"][i]["associatedPositioning"][1]["intrinsicCoordinates"][j]
                        ["coordinates"][0]["ref"].toString();
                std::vector<QString> coordValue = lookForCoord(ref);
                //qDebug()<< "0 :"<< coordValue[0].toDouble() << "   1 :  "<< coordValue[1]<< "     2 :   " << coordValue[2];
                segmentData.push_back(coordValue[0].toDouble());
                segmentData.push_back(coordValue[1].toDouble());
                segmentData.push_back(coordValue[2].toDouble());
                j++;
            }
//            progressValue++;
//            qDebug()<< " KANTEN Progress Bar "<< progressValue<< " of " <<totalValue;
//            qDebug()<< "Processing Gleiskanten . . . "<< i << " of " <<segmentCount;
            allCoord.push_back(segmentData);
            i++;
        }
    }
    return allCoord;
}


const std::vector<QString> &GleiskantenFromUnprocessedJson::getName() const
{
    return name;
}

void GleiskantenFromUnprocessedJson::setName(const std::vector<QString> &newName)
{
    name = newName;
}

const std::vector<QString> &GleiskantenFromUnprocessedJson::getId() const
{
    return id;
}

void GleiskantenFromUnprocessedJson::setId(const std::vector<QString> &newId)
{
    id = newId;
}

const std::vector<QString> &GleiskantenFromUnprocessedJson::getElementLength() const
{
    return elementLength;
}

void GleiskantenFromUnprocessedJson::setElementLength(const std::vector<QString> &newElementLength)
{
    elementLength = newElementLength;
}

const std::vector<QString> &GleiskantenFromUnprocessedJson::getStartRef() const
{
    return startRef;
}

void GleiskantenFromUnprocessedJson::setStartRef(const std::vector<QString> &newStartRef)
{
    startRef = newStartRef;
}

const std::vector<QString> &GleiskantenFromUnprocessedJson::getEndRef() const
{
    return endRef;
}

void GleiskantenFromUnprocessedJson::setEndRef(const std::vector<QString> &newEndRef)
{
    endRef = newEndRef;
}

const std::vector<QString> &GleiskantenFromUnprocessedJson::getStartValues() const
{
    return startValues;
}

void GleiskantenFromUnprocessedJson::setStartValues(const std::vector<QString> &newStartValues)
{
    startValues = newStartValues;
}

const std::vector<QString> &GleiskantenFromUnprocessedJson::getEndValues() const
{
    return endValues;
}

void GleiskantenFromUnprocessedJson::setEndValues(const std::vector<QString> &newEndValues)
{
    endValues = newEndValues;
}


QJsonObject GleiskantenFromUnprocessedJson::geometry(std::vector<double> coord){
    QJsonObject geom;
    QJsonArray allCoord;


    for (int i=0; i< (int)coord.size(); i=i+3){
        QJsonArray currentArr;
        currentArr.append(coord.at(i));
        currentArr.append(coord.at(i+1));
        currentArr.append(coord.at(i+2));
        allCoord.append(currentArr);
    }
    geom.insert("type", "LineString");
    geom.insert("coordinates", allCoord);
    return geom;
}

QJsonObject GleiskantenFromUnprocessedJson::properties (std::vector<QString> name, std::vector<QString> id, std::vector<QString> elementLength,
                                        std::vector<QString> startRef, std::vector<QString> endRef, std::vector<QString> startValue,
                                        std::vector<QString> endValue, int index){
    QJsonObject prop;

    prop.insert("Name", name.at(index));
    prop.insert("ID", id.at(index));
    prop.insert("Element Length", elementLength.at(index));
    prop.insert("StartRef", startRef.at(index));
    prop.insert("EndRef", endRef.at(index));
    prop.insert("KM_A_KM", startValue.at(index));
    prop.insert("KM_E_KM", endValue.at(index));

    return prop;
}

// return each segment (Feature, Properties, and Geometry)
QJsonObject GleiskantenFromUnprocessedJson::Features(QJsonObject properties, QJsonObject geometry){

    QJsonObject eachFeature;

    eachFeature.insert("type", "Feature");
    eachFeature.insert("properties", properties);
    eachFeature.insert("geometry", geometry);
    return eachFeature;
}

void GleiskantenFromUnprocessedJson::createJson()
{
    searchNameAndID();
    searchElementLength();
    searchStartRefAndStartKm();

    std::vector<std::vector<double> > allCoord = arrayOfCoordinates();
    std::vector<QString> name = getName();
    std::vector<QString> id = getId();
    std::vector<QString> elementLength = getElementLength();
    std::vector<QString> startRef = getStartRef();
    std::vector<QString> endRef = getEndRef();
    std::vector<QString> startValues = getStartValues();
    std::vector<QString> endValues = getEndValues();

    QJsonArray allFeatures;
    for (int i=0; i< (int)allCoord.size(); i++){

        QJsonObject prop = properties (name, id, elementLength, startRef, endRef, startValues,
                                       endValues, i);
        QJsonObject geom = geometry(allCoord.at(i));
        QJsonObject features = Features(prop, geom);
        allFeatures.append(features);
    }
    /* If there is no Topology data (coordinate(s)), there is nothing to
    view, Hence, no need of creating internal json document*/
    if (allFeatures.isEmpty()) {
        progressValue++;
        qDebug()<< "Progress : " << progressValue;
        return;
    }
    QJsonObject content;
    content.insert("type", "FeatureCollection");
    content.insert("name", "Gleiskanten");
    content.insert("features", allFeatures);

    QJsonDocument document;
    document.setObject( content );
    QByteArray bytes = document.toJson( QJsonDocument::Indented );
    QFile file( newFilePath );
    if( file.open( QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate ) )
    {
        QTextStream iStream( &file );

        //iStream.setCodec( "utf-8" );
        iStream << bytes;
        file.close();
    }
    else
    {
        qDebug()<< "File opening failed: " << file.errorString();
        //        std::cout << "file open failed: " << path.toStdString() << std::endl;
    }
    progressValue++;
    qDebug()<< "Progress : " << progressValue;
}
