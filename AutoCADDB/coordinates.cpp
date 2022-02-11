#include "coordinates.h"
#include <QPointF>
#include <QRegularExpression>

Coordinates::Coordinates(QString pPath, QString pName)
{
    this->pPath = pPath;
    this->pName = pName;
}

void Coordinates::readCoordinates(QString dataFile, QString countryCode, int dataCodeNumber)
{
    /* readCoordinates(QString dataFile, int dataCodeNumber)
      dataFile can only be ...
      "Gleisknoten.dbahn" corresponding to dataCodeNumber 1
      "Gleiskanten.dbahn" corresponding to dataCodeNumber 2
      "Entwurfselement_Hoehe.dbahn" corresponding to dataCodeNumber 3
      "Entwurfselement_KMLinie.dbahn" corresponding to dataCodeNumber 4
      "Entwurfselement_Ueberhoehung.dbahn" corresponding to dataCodeNumber 5
      "Entwurfselement_Lage.dbahn" corresponding to dataCodeNumber 6

      The dataCodeNumber is neglected if user can produce the intended dataFile name to extract coordinates
    */

    if (dataFile == ""){
        switch (dataCodeNumber) {
        case 1: dataFile = "Gleisknoten.dbahn";
            break;
        case 2: dataFile = "Gleiskanten.dbahn";
            break;
        case 3: dataFile = "Entwurfselement_HO.dbahn";
            break;
        case 4: dataFile = "Entwurfselement_KM.dbahn";
            break;
        case 5: dataFile = "Entwurfselement_UH.dbahn";
            break;
        case 6: dataFile = "Entwurfselement_LA.dbahn";
            break;
        default:
            qInfo()<< "You have entered invalid dataCodeNumber...\n "
                      "Please enter a valid dataCodeNumber between  1 to 5";
            return;
        }
    }

    QFile file (pPath+"/"+pName+"/temp/" + dataFile);
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
    QString allData;
    allData = QString(decoded);
    file.close();
    QJsonDocument document = QJsonDocument::fromJson(allData.toUtf8());
    int count =0;
    while(!document["features"][count].isUndefined()){
        count = count+1;
    }
    if (count == 0){
        qInfo() << "Coordinates cannot be found in your prefered data... Please use data preview section";
        return;
    }
    int value =0; // assign arbitrary value to data seleceted to be used for switch case statement;
    if (dataFile == "Gleisknoten.dbahn"){
        value = 1;
    }else if (dataFile == "Gleiskanten.dbahn" || dataFile =="Entwurfselement_HO.dbahn" || dataFile =="Entwurfselement_KM.dbahn" ||
              dataFile == "Entwurfselement_UH.dbahn" || dataFile == "Entwurfselement_LA.dbahn"){
        value =2;
    }else {
        qInfo()<< "Please enter a valid data name";
        return;
    }
    switch (value) {

    case 1:{
        int counter1 =0;
        while(counter1 < count){
            QMap<QString, QString> object;

            QJsonObject currentObj = document["features"][counter1]["properties"].toObject();
            QJsonObject::Iterator iter;
            for (iter = currentObj.begin(); iter != currentObj.end(); ++iter){
                QString currentKey = iter.key();
                QString currentValue = iter.value().isString() ? iter.value().toString() : QString::number(iter.value().toDouble(), 'f', 0);
                object.insert(currentKey, currentValue);
            }
            map.push_back(object);
            counter1++;
        }
        this->setMap(map);
        std::vector<float> arrayOfCoordinates;
        int counter =0;
        while (counter < count){
            arrayOfCoordinates.push_back(document["features"][counter]["geometry"]["coordinates"][0].toDouble());
            arrayOfCoordinates.push_back(document["features"][counter]["geometry"]["coordinates"][1].toDouble());
            counter++;
        }
        setCoordinateLists(arrayOfCoordinates);
        break;
    }

    case 2: {
        int counter1 =0;
        if (dataFile == "Gleiskanten.dbahn" && countryCode=="de"){

            setupData(count, document);

//            QList<QString> dir; //RITZ
//            while(counter1 < count){
//                QMap<QString, QString> object;
//                QJsonObject currentObj = document["features"][counter1]["properties"].toObject();
//                QJsonObject::Iterator iter;
//                for (iter = currentObj.begin(); iter != currentObj.end(); ++iter){
//                    QString currentKey = iter.key();
//                    QString currentValue = iter.value().isString() ? iter.value().toString() : QString::number(iter.value().toDouble(), 'f', 0);
//                    object.insert(currentKey, currentValue);
//                }
//                double RIKZ = document["features"][counter1]["properties"]["RIKZ"].toDouble();
//                map.push_back(object);

//                // Also set the direction
//                dir.append(QString::number(RIKZ));
//                counter1++;
//            }
//            this->setMap(map);
//            this->setDirection(dir);
        }
        else if (dataFile == "Gleiskanten.dbahn" && countryCode=="fr"){
            setupData(count, document);

////            QList<QString> dir; //RITZ
//            while(counter1 < count){
//                QMap<QString, QString> object;

//                QJsonObject currentObj = document["features"][counter1]["properties"].toObject();
//                QJsonObject::Iterator iter;
//                for (iter = currentObj.begin(); iter != currentObj.end(); ++iter){
//                    QString currentKey = iter.key();
//                    QString currentValue = iter.value().isString() ? iter.value().toString() : QString::number(iter.value().toDouble(), 'f', 0);
//                    object.insert(currentKey, currentValue);
//                }
//                map.push_back(object);

//                // Also set the direction
////                dir.append(QString::number(RIKZ));
//                counter1++;
//            }
//            this->setMap(map);
////            this->setDirection(dir);
        }
        else if (dataFile == "Entwurfselement_HO.dbahn"){
            setupData(count, document);
//            QList<QString> dir; //RITZ
//            while (counter1 < count){
//                QMap<QString, QString> object;

//                QJsonObject currentObj = document["features"][counter1]["properties"].toObject();
//                QJsonObject::Iterator iter;
//                for (iter = currentObj.begin(); iter != currentObj.end(); ++iter){
//                    QString currentKey = iter.key();
//                    QString currentValue = iter.value().isString() ? iter.value().toString() : QString::number(iter.value().toDouble(), 'f', 0);
//                    object.insert(currentKey, currentValue);
//                }
//                map.push_back(object);

//                // Also set the direction
//                dir.append(document["features"][counter1]["properties"]["RIKZ"].toString());
//                counter1++;
//            }
//            this->setMap(map);
//            this->setDirection(dir);
        }
        else if (dataFile == "Entwurfselement_LA.dbahn"){
            setupData(count, document);

//            QList<QString> dir; //RITZ
//            while(counter1 < count){
//                QMap<QString, QString> object;

//                QJsonObject currentObj = document["features"][counter1]["properties"].toObject();
//                QJsonObject::Iterator iter;
//                for (iter = currentObj.begin(); iter != currentObj.end(); ++iter){
//                    QString currentKey = iter.key();
//                    QString currentValue = iter.value().isString() ? iter.value().toString() : QString::number(iter.value().toDouble(), 'f', 0);
//                    object.insert(currentKey, currentValue);
//                }


//                map.push_back(object);

//                // Also set the direction
//                dir.append(document["features"][counter1]["properties"]["RIKZ"].toString());
//                counter1++;
//            }
//            this->setMap(map);
//            this->setDirection(dir);
        }
        else if(dataFile == "Entwurfselement_UH.dbahn"){
            setupData(count, document);

//            QList<QString> dir; //RITZ
//            while (counter1 < count){
//                QMap<QString, QString> object;

//                QJsonObject currentObj = document["features"][counter1]["properties"].toObject();
//                QJsonObject::Iterator iter;
//                for (iter = currentObj.begin(); iter != currentObj.end(); ++iter){
//                    QString currentKey = iter.key();
//                    QString currentValue = iter.value().isString() ? iter.value().toString() : QString::number(iter.value().toDouble(), 'f', 0);
//                    object.insert(currentKey, currentValue);
//                }
//                map.push_back(object);

//                // Also set the direction
//                dir.append(document["features"][counter1]["properties"]["RIKZ"].toString());
//                counter1++;
//            }
//            this->setMap(map);
//            this->setDirection(dir);
        }
        else if (dataFile == "Entwurfselement_KM.dbahn"){
            setupData(count, document);

//            while(counter1 < count){
//                QMap<QString, QString> object;

//                QJsonObject currentObj = document["features"][counter1]["properties"].toObject();
//                QJsonObject::Iterator iter;
//                for (iter = currentObj.begin(); iter != currentObj.end(); ++iter){
//                    QString currentKey = iter.key();
//                    QString currentValue = iter.value().isString() ? iter.value().toString() : QString::number(iter.value().toDouble(), 'f', 0);
//                    object.insert(currentKey, currentValue);
//                }
//                map.push_back(object);
//                counter1++;
//            }
//            this->setMap(map);
        }
        std::vector<float> arrayOfCoordinates;
        std::vector<int> segmentCount;
        std::vector<QPointF> segmentExtremePoints;
        segmentCount.push_back(0);
        int globalCount =0;
        int counter =0;
        while (counter < count){
            int innerCount =0;
            segmentExtremePoints.push_back(QPointF(document["features"][counter]["geometry"]["coordinates"][0][0].toDouble(), document["features"][counter]["geometry"]["coordinates"][0][1].toDouble()));
            while(!document["features"][counter]["geometry"]["coordinates"][innerCount].isUndefined()){
                innerCount++;
            }
            globalCount+=(innerCount*2);
            segmentCount.push_back(globalCount);
            segmentExtremePoints.push_back(QPointF(document["features"][counter]["geometry"]["coordinates"][innerCount-1][0].toDouble(), document["features"][counter]["geometry"]["coordinates"][innerCount-1][1].toDouble()));

            int innerIndex =0;
            while (innerIndex < innerCount){
                arrayOfCoordinates.push_back(document["features"][counter]["geometry"]["coordinates"][innerIndex][0].toDouble());
                arrayOfCoordinates.push_back(document["features"][counter]["geometry"]["coordinates"][innerIndex][1].toDouble());
                innerIndex++;
            }
            counter++;
        }
        setCoordinateLists(arrayOfCoordinates);
        setSegment(segmentCount);
        setSegmentExtremePoints(segmentExtremePoints);
        if (dataFile == "Entwurfselement_KM.dbahn"){
            // Set values fot the extreme dataPoints Km that is correcponding to segmentExtremepoints
            std::vector<double> segmentExtremeKmVals;
            counter =0;
            while (counter < count){
                QString KM_A_TEXT = document["features"][counter]["properties"]["KM_A_TEXT"].toString();
                QString KM_E_TEXT = document["features"][counter]["properties"]["KM_E_TEXT"].toString();
                QList<QString> KM_A_SPLIT = KM_A_TEXT.split(QRegularExpression("\\+"), Qt::SkipEmptyParts);
                QList<QString> KM_E_SPLIT = KM_E_TEXT.split(QRegularExpression("\\+"), Qt::SkipEmptyParts);
                double p1_km,p1_m, p2_km, p2_m, p1_final, p2_final;
                p1_km = KM_A_SPLIT[0].replace(",",".").toDouble();
                p1_m = KM_A_SPLIT[1].replace(",",".").toDouble();
                p1_final = p1_km + p1_m/1000;

                p2_km = KM_E_SPLIT[0].replace(",",".").toDouble();
                p2_m = KM_E_SPLIT[1].replace(",",".").toDouble();
                p2_final = p2_km + p2_m/1000;
                segmentExtremeKmVals.push_back(p1_final);
                segmentExtremeKmVals.push_back(p2_final);
                counter++;
            }
            setSegmentExtremeKmValues(segmentExtremeKmVals);
        }
        break;
    }
    default: {
        break;
    }
    }
}

const std::vector<float> &Coordinates::getCoordinateLists() const
{
    return coordinateLists;
}

void Coordinates::setCoordinateLists(const std::vector<float> &newCoordinateLists)
{
    coordinateLists = newCoordinateLists;
}

const std::vector<int> &Coordinates::getSegment() const
{
    return segment;
}

void Coordinates::setSegment(const std::vector<int> &newSegment)
{
    segment = newSegment;
}

const std::vector<QMap<QString, QString> > &Coordinates::getMap() const
{
    return map;
}

void Coordinates::setMap(const std::vector<QMap<QString, QString> > &newMap)
{
    map = newMap;
}

const std::vector<QPointF> &Coordinates::getSegmentExtremePoints() const
{
    return segmentExtremePoints;
}

void Coordinates::setSegmentExtremePoints(const std::vector<QPointF> &newSegmentExtremePoints)
{
    segmentExtremePoints = newSegmentExtremePoints;
}

const std::vector<double> &Coordinates::getSegmentExtremeKmValues() const
{
    return segmentExtremeKmValues;
}

void Coordinates::setSegmentExtremeKmValues(const std::vector<double> &newSegmentExtremeKmValues)
{
    segmentExtremeKmValues = newSegmentExtremeKmValues;
}

const QList<QString> &Coordinates::getDirection() const
{
    return direction;
}

void Coordinates::setDirection(const QList<QString> &newDirection)
{
    direction = newDirection;
}

void Coordinates::setupData(int to, QJsonDocument document )
{
    int fro =0;
    QList<QString> dir; //RITZ
    while(fro < to){
        QMap<QString, QString> object;
        QJsonObject currentObj = document["features"][fro]["properties"].toObject();
        QJsonObject::Iterator iter;
        for (iter = currentObj.begin(); iter != currentObj.end(); ++iter){
            QString currentKey = iter.key();
            QString currentValue = iter.value().isString() ? iter.value().toString() : QString::number(iter.value().toDouble(), 'f', 0);
            object.insert(currentKey, currentValue);
        }
        map.push_back(object);

        // Also set the direction
        if (!document["features"][fro]["properties"]["RIKZ"].isUndefined() && document["features"][fro]["properties"]["RIKZ"].isString()){
            dir.append(document["features"][fro]["properties"]["RIKZ"].toString());
        }else{
            dir.append(QString::number(document["features"][fro]["properties"]["RIKZ"].toDouble()));
        }
        fro++;
    }
    this->setMap(map);
    this->setDirection(dir);
}
