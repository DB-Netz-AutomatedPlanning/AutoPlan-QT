#include "lagefromunprocessedjson.h"
#include "symbolcontainer.h"
#include <QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>

LageFromUnprocessedJson::LageFromUnprocessedJson(QObject *parent, QString filePath, const QString &newFilePath)
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



void LageFromUnprocessedJson::searchNameAndID()
{
    std::vector<QString> name;
    std::vector<QString> id;
    int i=0;

    while (!document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]["usesHorizontalAlignmentSegment"][i].isUndefined()){
        try {
            id.push_back(document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]["usesHorizontalAlignmentSegment"][i]["id"].toString());
            //name.push_back(document["hasDataContainer"][0]["ownsRsmEntities"]["usesTrackTopology"]["usesNetElement"][i]["id"].toString());

        }  catch (_exception ex) {
        }
        i+=1;
    }
    setName(name);
    setId(id);
}


void LageFromUnprocessedJson::searchStartRefAndStartKm()
{
    std::vector<QString> startRef;
    std::vector<QString> endRef;

    std::vector<QString> startValues;
    std::vector<QString> endValues;
    int i=0;
    while (!document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]["usesHorizontalAlignmentSegment"][i].isUndefined()){
        QString refStart = document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]["usesHorizontalAlignmentSegment"][i]
                ["hasLinearLocation"]["polyLines"][0]["coordinates"][0]["ref"].toString();
        startRef.push_back(refStart);

        QString refEnd = document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]["usesHorizontalAlignmentSegment"][i]
                ["hasLinearLocation"]["polyLines"][0]["coordinates"][1]["ref"].toString();
        endRef.push_back(refEnd);

        // Search for the actual value
        std::vector<QString> startValue = lookForCoord(refStart);
        std::vector<QString> endValue = lookForCoord(refEnd);

        startValues.push_back(startValue[0]);
        endValues.push_back(endValue[0]);
        i+=1;
    }
    setStartRef(startRef);
    setEndRef(endRef);
    setStartValues(startValues);
    setEndValues(endValues);
}


// ToDo: This function needs to be optimized
std::vector<QString> LageFromUnprocessedJson::lookForCoord(QString currentRef)
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
//                if(document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
//                        ["usesPositioningSystemCoordinate"][j]["z"].isString()){
//                    values.push_back(document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
//                            ["usesPositioningSystemCoordinate"][j]["z"].toString());
//                } else {
//                    values.push_back(QString::number(document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]
//                            ["usesPositioningSystemCoordinate"][j]["z"].toDouble(), 'f', 8));
//                }
            }
            break;
        }
        j++;
    }
    return values;
}


// return array of coordinates based on each segment
std::vector<std::vector<double> > LageFromUnprocessedJson::arrayOfCoordinates()
{
    qDebug()<< "Entering -- Lage . ";
    qDebug()<< "Look up -- for Lage . . . ";
    std::vector<std::vector<double> > allCoord;

//    int segmentCount=0;
//    while (!document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]["usesHorizontalAlignmentSegment"][segmentCount].isUndefined()){
//        segmentCount++;
//    }
//    totalValue+=segmentCount;
//    qDebug()<< "TOTALFROM_LA" << totalValue;

    int i=0;
    while (!document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]["usesHorizontalAlignmentSegment"][i].isUndefined()){
        std::vector<double> segmentData;
        int j =0;
        while (!document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]["usesHorizontalAlignmentSegment"][i]["hasLinearLocation"]["polyLines"][1]["coordinates"][j].isUndefined()){
            QString ref = document["hasDataContainer"][0]["ownsRsmEntities"]["usesTopography"]["usesHorizontalAlignmentSegment"][i]
                    ["hasLinearLocation"]["polyLines"][1]["coordinates"][j]["ref"].toString();
            std::vector<QString> coordValue = lookForCoord(ref);
            //qDebug()<< "0 :"<< coordValue[0].toDouble() << "   1 :  "<< coordValue[1]<< "     2 :   " << coordValue[2];
            segmentData.push_back(coordValue[0].toDouble());
            segmentData.push_back(coordValue[1].toDouble());
//            segmentData.push_back(coordValue[2].toDouble());
            j++;
        }
//        progressValue++;
//        qDebug()<< "Progress Bar "<< progressValue<< " of " <<totalValue;
//        qDebug()<< "Processing Lage . . . "<< i << " of "<< segmentCount;
        allCoord.push_back(segmentData);
        i++;
    }
    qDebug()<< "Lage : .. . 100% Completed!!!";
    return allCoord;
}


const std::vector<QString> &LageFromUnprocessedJson::getName() const
{
    return name;
}

void LageFromUnprocessedJson::setName(const std::vector<QString> &newName)
{
    name = newName;
}

const std::vector<QString> &LageFromUnprocessedJson::getId() const
{
    return id;
}

void LageFromUnprocessedJson::setId(const std::vector<QString> &newId)
{
    id = newId;
}

const std::vector<QString> &LageFromUnprocessedJson::getStartRef() const
{
    return startRef;
}

void LageFromUnprocessedJson::setStartRef(const std::vector<QString> &newStartRef)
{
    startRef = newStartRef;
}

const std::vector<QString> &LageFromUnprocessedJson::getEndRef() const
{
    return endRef;
}

void LageFromUnprocessedJson::setEndRef(const std::vector<QString> &newEndRef)
{
    endRef = newEndRef;
}

const std::vector<QString> &LageFromUnprocessedJson::getStartValues() const
{
    return startValues;
}

void LageFromUnprocessedJson::setStartValues(const std::vector<QString> &newStartValues)
{
    startValues = newStartValues;
}

const std::vector<QString> &LageFromUnprocessedJson::getEndValues() const
{
    return endValues;
}

void LageFromUnprocessedJson::setEndValues(const std::vector<QString> &newEndValues)
{
    endValues = newEndValues;
}


QJsonObject LageFromUnprocessedJson::geometry(std::vector<double> coord){
    QJsonObject geom;
    QJsonArray allCoord;

    for (int i=0; i< (int)coord.size(); i=i+2){
        QJsonArray currentArr;
        currentArr.append(coord.at(i));
        currentArr.append(coord.at(i+1));
//        currentArr.append(coord.at(i+2));
        allCoord.append(currentArr);
    }
    geom.insert("type", "LineString");
    geom.insert("coordinates", allCoord);

    return geom;
}

QJsonObject LageFromUnprocessedJson::properties (std::vector<QString> id, std::vector<QString> startRef, std::vector<QString> endRef,
                                 std::vector<QString> startValue, std::vector<QString> endValue, int index){
    QJsonObject prop;

    prop.insert("ID", id.at(index));
    prop.insert("StartRef", startRef.at(index));
    prop.insert("EndRef", endRef.at(index));
    prop.insert("KM_A_KM", startValue.at(index));
    prop.insert("KM_E_KM", endValue.at(index));

    return prop;
}

// return each segment (Feature, Properties, and Geometry)
QJsonObject LageFromUnprocessedJson::Features(QJsonObject properties, QJsonObject geometry){

    QJsonObject eachFeature;

    eachFeature.insert("type", "Feature");
    eachFeature.insert("properties", properties);
    eachFeature.insert("geometry", geometry);
    return eachFeature;
}



void LageFromUnprocessedJson::createJson()
{
    searchNameAndID();
    //    searchElementLength();
    searchStartRefAndStartKm();

    std::vector<std::vector<double> > allCoord = arrayOfCoordinates();
    //    std::vector<QString> name = getName();
    std::vector<QString> id = getId();
    //    std::vector<QString> elementLength = getElementLength();
    std::vector<QString> startRef = getStartRef();
    std::vector<QString> endRef = getEndRef();
    std::vector<QString> startValues = getStartValues();
    std::vector<QString> endValues = getEndValues();

    QJsonArray allFeatures;

    for (int i=0; i< (int)allCoord.size(); i++){
        QJsonObject prop = properties (id, startRef, endRef, startValues, endValues, i);
        QJsonObject geom = geometry(allCoord.at(i));
        QJsonObject features = Features(prop, geom);
        allFeatures.append(features);
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
    content.insert("name", "Entwurfselement_Lage");
    content.insert("features", allFeatures);

    QJsonDocument document;
    document.setObject( content );
    QByteArray bytes = document.toJson( QJsonDocument::Indented );
    QFile file( newFilePath );
    if( file.open( QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate ) )
    {
        QTextStream iStream( &file );
        iStream << bytes;
        file.close();
    }
    else
    {
        qDebug()<< "File opening failed: " << file.errorString();
    }
    progressValue++; // increment the progress bar counter and exit
    qDebug()<< "Progress : " << progressValue;
}
