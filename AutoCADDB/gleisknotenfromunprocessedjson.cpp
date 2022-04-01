#include "gleisknotenfromunprocessedjson.h"
#include "symbolcontainer.h"
#include <QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>

GleisknotenFromUnprocessedJson::GleisknotenFromUnprocessedJson(QObject *parent, QString filePath, const QString &newFilePath)
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

void GleisknotenFromUnprocessedJson::searchNameAndID()
{
    std::vector<QString> name;
    std::vector<QString> id;
    int i=0;

    // Ownspoints
    while (!document["hasDataContainer"][0]["ownsRsmEntities"]["ownsPoint"][i].isUndefined()){
        try {
            id.push_back(document["hasDataContainer"][0]["ownsRsmEntities"]["ownsPoint"][i]["id"].toString());
            name.push_back(document["hasDataContainer"][0]["ownsRsmEntities"]["ownsPoint"][i]["name"].toString());

        }  catch (_exception ex) {
        }
        i+=1;
    }

    // OwnsVehicleStop
    int j=0;
    while (!document["hasDataContainer"][0]["ownsRsmEntities"]["ownsVehicleStop"][j].isUndefined()){
        try {
            id.push_back(document["hasDataContainer"][0]["ownsRsmEntities"]["ownsVehicleStop"][j]["id"].toString());
            name.push_back(document["hasDataContainer"][0]["ownsRsmEntities"]["ownsVehicleStop"][j]["name"].toString());

        }  catch (_exception ex) {
        }
        j+=1;
    }
    setName(name);
    setId(id);
}


void GleisknotenFromUnprocessedJson::searchStartRefAndStartKm()
{
    std::vector<QString> kmValues;

    int i=0;
    while (!document["hasDataContainer"][0]["ownsRsmEntities"]["ownsPoint"][i].isUndefined()){

        // first get the ref of the location
        QString locationRef = document["hasDataContainer"][0]["ownsRsmEntities"]["ownsPoint"][i]["locations"][0]["ref"].toString();

        QString usesLocationRef;

        // Match current locationRef with usesLocationRef;
        int k =0;
        while (!document["hasDataContainer"][0]["ownsRsmEntities"]["usesLocation"][k].isUndefined()){
            QString locationID = document["hasDataContainer"][0]["ownsRsmEntities"]["usesLocation"][k]["id"].toString();

            if(locationRef == locationID){
                usesLocationRef = document["hasDataContainer"][0]["ownsRsmEntities"]["usesLocation"][k]["coordinates"][0]["ref"].toString();
                break;
            }
            k++;
        }
        std::vector <QString> coordValue = lookForCoord(usesLocationRef);

        //qDebug()<< "0 :"<< coordValue[0].toDouble() ;
        kmValues.push_back(coordValue[0]);
        i++;
    }


    // OwnsVehiclePoint

    int j=0;
    while (!document["hasDataContainer"][0]["ownsRsmEntities"]["ownsVehicleStop"][j].isUndefined()){

        // first get the ref of the location
        QString locationRef = document["hasDataContainer"][0]["ownsRsmEntities"]["ownsVehicleStop"][j]["locations"][0]["ref"].toString();
        QString usesLocationRef;

        // Match current locationRef with usesLocationRef;
        int l=0;

        while (!document["hasDataContainer"][0]["ownsRsmEntities"]["usesLocation"][l].isUndefined()){
            QString locationID = document["hasDataContainer"][0]["ownsRsmEntities"]["usesLocation"][l]["id"].toString();

            if(locationRef == locationID){
                usesLocationRef = document["hasDataContainer"][0]["ownsRsmEntities"]["usesLocation"][l]["coordinates"][0]["ref"].toString();
                break;
            }
            l++;
        }
        std::vector <QString> coordValue = lookForCoord(usesLocationRef);

        //qDebug()<< "0 :"<< coordValue[0].toDouble();
        kmValues.push_back(coordValue[0]);
        j++;
    }
    setStartValues(kmValues);
}


// ToDo: This function needs to be optimized
std::vector<QString> GleisknotenFromUnprocessedJson::lookForCoord(QString currentRef)
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
std::vector<std::vector<double> > GleisknotenFromUnprocessedJson::arrayOfCoordinates()
{
    qDebug()<< "Entering -- Knoten . ";
    qDebug()<< "Look up -- for knoten . . . ";
    std::vector<std::vector<double> > allCoord;

//    int segmentCount=0;
//    while (!document["hasDataContainer"][0]["ownsRsmEntities"]["ownsPoint"][segmentCount].isUndefined()){
//        segmentCount++;
//    }
//    totalValue+=segmentCount;
//    qDebug()<< "TOTALFROMKNO1" << totalValue;

//    int segmentCount1=0;
//    while (!document["hasDataContainer"][0]["ownsRsmEntities"]["ownsVehicleStop"][segmentCount1].isUndefined()){
//        segmentCount1++;
//    }
//    totalValue+=segmentCount1;
//    qDebug()<< "TOTALFROMKNO2" << totalValue;

    int i=0;
    while (!document["hasDataContainer"][0]["ownsRsmEntities"]["ownsPoint"][i].isUndefined()){
        std::vector<double> segmentData;

        // first get the ref of the location
        QString locationRef = document["hasDataContainer"][0]["ownsRsmEntities"]["ownsPoint"][i]["locations"][0]["ref"].toString();

        QString usesLocationRef;

        // Match current locationRef with usesLocationRef;
        int k =0;
        while (!document["hasDataContainer"][0]["ownsRsmEntities"]["usesLocation"][k].isUndefined()){
            QString locationID = document["hasDataContainer"][0]["ownsRsmEntities"]["usesLocation"][k]["id"].toString();

            if(locationRef == locationID){
                usesLocationRef = document["hasDataContainer"][0]["ownsRsmEntities"]["usesLocation"][k]["coordinates"][1]["ref"].toString();
                break;
            }
            k++;
        }
        std::vector <QString> coordValue = lookForCoord(usesLocationRef);

        //qDebug()<< "0 :"<< coordValue[0].toDouble() << "   1 :  "<< coordValue[1]<< "     2 :   " << coordValue[2];
        segmentData.push_back(coordValue[0].toDouble());
        segmentData.push_back(coordValue[1].toDouble());
        segmentData.push_back(coordValue[2].toDouble());
        allCoord.push_back(segmentData);
//        progressValue++;
//        qDebug()<< "Progress Bar "<< progressValue<< " of " <<totalValue;
//        qDebug()<< "Processing Knoten . . . "<< i << " of "<< segmentCount + segmentCount1;
        i++;
    }


    // OwnsVehiclePoint

    int j=0;
    while (!document["hasDataContainer"][0]["ownsRsmEntities"]["ownsVehicleStop"][j].isUndefined()){
        std::vector<double> segmentData;

        // first get the ref of the location
        QString locationRef = document["hasDataContainer"][0]["ownsRsmEntities"]["ownsVehicleStop"][j]["locations"][0]["ref"].toString();
        QString usesLocationRef;

        // Match current locationRef with usesLocationRef;
        int l=0;

        while (!document["hasDataContainer"][0]["ownsRsmEntities"]["usesLocation"][l].isUndefined()){
            QString locationID = document["hasDataContainer"][0]["ownsRsmEntities"]["usesLocation"][l]["id"].toString();

            if(locationRef == locationID){
                usesLocationRef = document["hasDataContainer"][0]["ownsRsmEntities"]["usesLocation"][l]["coordinates"][1]["ref"].toString();
                break;
            }
            l++;
        }
        std::vector <QString> coordValue = lookForCoord(usesLocationRef);

        //qDebug()<< "0 :"<< coordValue[0].toDouble() << "   1 :  "<< coordValue[1]<< "     2 :   " << coordValue[2];
        segmentData.push_back(coordValue[0].toDouble());
        segmentData.push_back(coordValue[1].toDouble());
        segmentData.push_back(coordValue[2].toDouble());
        allCoord.push_back(segmentData);
//        progressValue++;
//        qDebug()<< "Progress Bar "<< progressValue<< " of " <<totalValue;
//        qDebug()<< "Processing Knoten . . . "<< (i + j+1) << " of " << segmentCount+segmentCount1;

        j++;
    }

    qDebug()<< "Knoten : .. . 100% Completed!!!";
    return allCoord;
}


const std::vector<QString> &GleisknotenFromUnprocessedJson::getName() const
{
    return name;
}

void GleisknotenFromUnprocessedJson::setName(const std::vector<QString> &newName)
{
    name = newName;
}

const std::vector<QString> &GleisknotenFromUnprocessedJson::getId() const
{
    return id;
}

void GleisknotenFromUnprocessedJson::setId(const std::vector<QString> &newId)
{
    id = newId;
}

//const std::vector<QString> &GleisknotenFromUnprocessedJson::getElementLength() const
//{
//    return elementLength;
//}

//void GleisknotenFromUnprocessedJson::setElementLength(const std::vector<QString> &newElementLength)
//{
//    elementLength = newElementLength;
//}

const std::vector<QString> &GleisknotenFromUnprocessedJson::getStartRef() const
{
    return startRef;
}

void GleisknotenFromUnprocessedJson::setStartRef(const std::vector<QString> &newStartRef)
{
    startRef = newStartRef;
}

const std::vector<QString> &GleisknotenFromUnprocessedJson::getEndRef() const
{
    return endRef;
}

void GleisknotenFromUnprocessedJson::setEndRef(const std::vector<QString> &newEndRef)
{
    endRef = newEndRef;
}

const std::vector<QString> &GleisknotenFromUnprocessedJson::getStartValues() const
{
    return startValues;
}

void GleisknotenFromUnprocessedJson::setStartValues(const std::vector<QString> &newStartValues)
{
    startValues = newStartValues;
}

const std::vector<QString> &GleisknotenFromUnprocessedJson::getEndValues() const
{
    return endValues;
}

void GleisknotenFromUnprocessedJson::setEndValues(const std::vector<QString> &newEndValues)
{
    endValues = newEndValues;
}


QJsonObject GleisknotenFromUnprocessedJson::geometry(std::vector<double> coord){
    QJsonObject geom;
    QJsonArray allCoord;

    allCoord.append(coord.at(0));
    allCoord.append(coord.at(0+1));
    allCoord.append(coord.at(0+2));

    geom.insert("type", "LineString");
    geom.insert("coordinates", allCoord);

    return geom;
}


QJsonObject GleisknotenFromUnprocessedJson::properties (std::vector<QString> id, std::vector<QString> name, std::vector<QString> startValue, int index){
    QJsonObject prop;

    prop.insert("Name", name.at(index));
    prop.insert("ID", id.at(index));
    prop.insert("KM_KM", startValue.at(index));

    return prop;
}

// return each segment (Feature, Properties, and Geometry)
QJsonObject GleisknotenFromUnprocessedJson::Features(QJsonObject properties, QJsonObject geometry){

    QJsonObject eachFeature;

    eachFeature.insert("type", "Feature");
    eachFeature.insert("properties", properties);
    eachFeature.insert("geometry", geometry);
    return eachFeature;
}

void GleisknotenFromUnprocessedJson::createJson()
{
    searchNameAndID();
    //    searchElementLength();
    searchStartRefAndStartKm();
    std::vector<std::vector<double> > allCoord = arrayOfCoordinates();
    std::vector<QString> name = getName();
    std::vector<QString> id = getId();
    std::vector<QString> startValues = getStartValues();  // Here, start value indicate the spot value, because node exists on a spot (no endValue)

    QJsonArray allFeatures;

    for (int i=0; i< (int)allCoord.size(); i++){
        QJsonObject prop = properties (id, name, startValues, i);
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
    content.insert("name", "Entwurfselement_Ueberhoehung");
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
    else
    {
        qDebug()<< "File opening failed: " << file.errorString();
        //        std::cout << "file open failed: " << path.toStdString() << std::endl;
    }
    progressValue++;
    qDebug()<< "Progress : " << progressValue;
}
