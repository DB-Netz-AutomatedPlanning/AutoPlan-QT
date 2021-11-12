#include "coordinates.h"
#include <QPointF>


Coordinates::Coordinates(QString pPath, QString pName )      //QString station)
{
    //this->station = station;
    this->pPath = pPath;
    this->pName = pName;
}

void Coordinates::readCoordinates(QString dataFile, int dataCodeNumber)
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

//    QJsonDocument document = QJsonDocument::fromJson(jsonData.toUtf8());
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
            double ID = document["features"][counter1]["properties"]["ID"].toDouble();
            QString KNOTENNAME = document["features"][counter1]["properties"]["KNOTENNAME"].toString();
            QString KNOTENBESC = document["features"][counter1]["properties"]["KNOTENBESC"].toString();
            double TYP = document["features"][counter1]["properties"]["TYP"].toDouble();
            QString TYP_L = document["features"][counter1]["properties"]["TYP_L"].toString();
            QString STATUS = document["features"][counter1]["properties"]["STATUS"].toString();
            QString KM_KM = document["features"][counter1]["properties"]["KM_KM"].toString();
            QString KM_M = document["features"][counter1]["properties"]["KM_M"].toString();
            object.insert("ID", QString::number(ID, 'f',0));
            object.insert("KNOTENNAME", KNOTENNAME);
            object.insert("KNOTENBESC", KNOTENBESC);
            object.insert("TYP", QString::number(TYP,'f',0));

            object.insert("TYP_L", TYP_L);
            object.insert("STATUS", STATUS);
            object.insert("KM_KM", KM_KM);
            object.insert("KM_M", KM_M);
            map.push_back(object);
            counter1++;
        }
        this->setMap(map);

        std::vector<float> arrayOfCoordinates;
        int counter =0;
        while (counter < count){
            int innerIndex =0;
            while (innerIndex < 2){
                arrayOfCoordinates.push_back(document["features"][counter]["geometry"]["coordinates"][0].toDouble());
                arrayOfCoordinates.push_back(document["features"][counter]["geometry"]["coordinates"][1].toDouble());
                innerIndex++;
            }
            counter++;
        }
        setCoordinateLists(arrayOfCoordinates);
        break;
    }


    case 2: {

        int counter1 =0;
        if (dataFile == "Gleiskanten.dbahn"){
            while(counter1 < count){
                QMap<QString, QString> object;
                double ID = document["features"][counter1]["properties"]["ID"].toDouble();
                QString LAENGE_ENT = document["features"][counter1]["properties"]["LAENGE_ENT"].toString();
                QString STATUS = document["features"][counter1]["properties"]["STATUS"].toString();
                double RIKZ = document["features"][counter1]["properties"]["RIKZ"].toDouble();
                QString RIKZ_L = document["features"][counter1]["properties"]["RIKZ_L"].toString();
                object.insert("ID", QString::number(ID, 'f',0));
                object.insert("LAENGE_ENT", LAENGE_ENT);
                object.insert("STATUS", STATUS);
                object.insert("RIKZ", QString::number(RIKZ,'f',0));
                object.insert("RIKZ_L", RIKZ_L);
                map.push_back(object);
                counter1++;
            }
            this->setMap(map);
        }
        else if (dataFile == "Entwurfselement_HO.dbahn"){
            while (counter1 < count){
                QMap<QString, QString> object;
                double ID = document["features"][counter1]["properties"]["ID"].toDouble();
                QString PAD_A = document["features"][counter1]["properties"]["PAD_A"].toString();
                QString ELTYP = document["features"][counter1]["properties"]["ELTYP"].toString();
                QString ELTYP_L = document["features"][counter1]["properties"]["ELTYP_L"].toString();
                double PARAM1 = document["features"][counter1]["properties"]["PARAM1"].toDouble();
                double PARAM2 = document["features"][counter1]["properties"]["PARAM2"].toDouble();
                double PARAM3 = document["features"][counter1]["properties"]["PARAM3"].toDouble();
                double PARAM4 = document["features"][counter1]["properties"]["PARAM4"].toDouble();
                QString RIKZ = document["features"][counter1]["properties"]["RIKZ"].toString();
                QString RIKZ_L = document["features"][counter1]["properties"]["RIKZ_L"].toString();
                double KM_A_KM = document["features"][counter1]["properties"]["KM_A_KM"].toDouble();
                double KM_A_M = document["features"][counter1]["properties"]["KM_A_M"].toDouble();
                double KM_E_KM = document["features"][counter1]["properties"]["KM_E_KM"].toDouble();
                double KM_E_M = document["features"][counter1]["properties"]["KM_E_M"].toDouble();
                double HOEHE_A = document["features"][counter1]["properties"]["HOEHE_A"].toDouble();
                double HOEHE_E = document["features"][counter1]["properties"]["HOEHE_E"].toDouble();
                object.insert("ID", QString::number(ID,'f',0));
                object.insert("PAD_A", PAD_A);
                object.insert("ELTYP", ELTYP);
                object.insert("ELTYP_L",ELTYP_L);
                object.insert("PARAM1", QString::number(PARAM1,'f') );
                object.insert("PARAM2", QString::number(PARAM2,'f'));
                object.insert("PARAM3", QString::number(PARAM3,'f'));
                object.insert("PARAM4", QString::number(PARAM4,'f'));
                object.insert("RIKZ", RIKZ);
                object.insert("RIKZ_L", RIKZ_L);
                object.insert("KM_A_KM", QString::number(KM_A_KM,'f') );
                object.insert("KM_A_M", QString::number(KM_A_M,'f')  );
                object.insert("KM_E_KM", QString::number(KM_E_KM,'f'));
                object.insert("KM_E_M", QString::number(KM_E_M,'f'));
                object.insert("HOEHE_A", QString::number(HOEHE_A,'f'));
                object.insert("HOEHE_E", QString::number(HOEHE_E,'f'));
                map.push_back(object);
                counter1++;
            }
            this->setMap(map);
        }

        else if (dataFile == "Entwurfselement_LA.dbahn"){
            while(counter1 < count){
                QMap<QString, QString> object;
                double ID = document["features"][counter1]["properties"]["ID"].toDouble();
                QString PAD_A = document["features"][counter1]["properties"]["PAD_A"].toString();
                QString PAD_E = document["features"][counter1]["properties"]["PAD_E"].toString();
                QString ELTYP = document["features"][counter1]["properties"]["ELTYP"].toString();
                QString ELTYP_L = document["features"][counter1]["properties"]["ELTYP_L"].toString();
                double PARAM1 = document["features"][counter1]["properties"]["PARAM1"].toDouble();
                double PARAM2 = document["features"][counter1]["properties"]["PARAM2"].toDouble();
                double PARAM3 = document["features"][counter1]["properties"]["PARAM3"].toDouble();
                double PARAM4 = document["features"][counter1]["properties"]["PARAM4"].toDouble();
                QString PARAM4_L = document["features"][counter1]["properties"]["PARAM4_L"].toString();
                double WINKEL_ANF = document["features"][counter1]["properties"]["WINKEL_ANF"].toDouble();
                QString RIKZ = document["features"][counter1]["properties"]["RIKZ"].toString();
                QString RIKZ_L = document["features"][counter1]["properties"]["RIKZ_L"].toString();
                double KM_A_KM = document["features"][counter1]["properties"]["KM_A_KM"].toDouble();
                double KM_A_M = document["features"][counter1]["properties"]["KM_A_M"].toDouble();
                double KM_E_KM = document["features"][counter1]["properties"]["KM_E_KM"].toDouble();
                double KM_E_M = document["features"][counter1]["properties"]["KM_E_M"].toDouble();

                object.insert("ID", QString::number( ID,'f',0));
                object.insert("PAD_A", PAD_A);
                object.insert("PAD_E", PAD_E);
                object.insert("ELTYP",ELTYP);
                object.insert("ELTYP_L",ELTYP_L);
                object.insert("PARAM1", QString::number( PARAM1,'f'));
                object.insert("PARAM2", QString::number( PARAM2,'f'));
                object.insert("PARAM3", QString::number( PARAM3,'f'));
                object.insert("PARAM4", QString::number( PARAM4,'f'));
                object.insert("PARAM4_L",  PARAM4_L);
                object.insert("WINKEL_ANF", QString::number( WINKEL_ANF,'f'));
                object.insert("RIKZ", RIKZ);
                object.insert("RIKZ_L", RIKZ_L);
                object.insert("KM_A_KM", QString::number( KM_A_KM,'f') );
                object.insert("KM_A_M", QString::number( KM_A_M,'f') );
                object.insert("KM_E_KM", QString::number( KM_E_KM,'f') );
                object.insert("KM_E_M", QString::number( KM_E_M,'f') );
                map.push_back(object);
                counter1++;
            }
            this->setMap(map);
        }
        else if(dataFile == "Entwurfselement_UH.dbahn"){
            while (counter1 < count){
                QMap<QString, QString> object;
                double ID = document["features"][counter1]["properties"]["ID"].toDouble();
                QString PAD_A = document["features"][counter1]["properties"]["PAD_A"].toString();
                QString PAD_E = document["features"][counter1]["properties"]["PAD_E"].toString();
                QString ELTYP = document["features"][counter1]["properties"]["ELTYP"].toString();
                QString ELTYP_L = document["features"][counter1]["properties"]["ELTYP_L"].toString();
                double PARAM1 = document["features"][counter1]["properties"]["PARAM1"].toDouble();
                double PARAM2 = document["features"][counter1]["properties"]["PARAM2"].toDouble();
                double PARAM3 = document["features"][counter1]["properties"]["PARAM3"].toDouble();
                double PARAM4 = document["features"][counter1]["properties"]["PARAM4"].toDouble();
                QString RIKZ = document["features"][counter1]["properties"]["RIKZ"].toString();
                QString RIKZ_L = document["features"][counter1]["properties"]["RIKZ_L"].toString();
                double KM_A_KM = document["features"][counter1]["properties"]["KM_A_KM"].toDouble();
                double KM_A_M = document["features"][counter1]["properties"]["KM_A_M"].toDouble();
                double KM_E_KM = document["features"][counter1]["properties"]["KM_E_KM"].toDouble();
                double KM_E_M = document["features"][counter1]["properties"]["KM_E_M"].toDouble();

                object.insert("ID", QString::number( ID,'f',0));
                object.insert("PAD_A", PAD_A);
                object.insert("PAD_E", PAD_E);
                object.insert("ELTYP",ELTYP);
                object.insert("ELTYP_L",ELTYP_L);
                object.insert("PARAM1", QString::number( PARAM1,'f'));
                object.insert("PARAM2", QString::number( PARAM2,'f'));
                object.insert("PARAM3", QString::number( PARAM3,'f'));
                object.insert("PARAM4", QString::number( PARAM4,'f'));
                object.insert("RIKZ", RIKZ);
                object.insert("RIKZ_L", RIKZ_L);
                object.insert("KM_A_KM", QString::number( KM_A_KM,'f') );
                object.insert("KM_A_M", QString::number( KM_A_M,'f') );
                object.insert("KM_E_KM", QString::number( KM_E_KM,'f') );
                object.insert("KM_E_M", QString::number( KM_E_M,'f') );
                map.push_back(object);
                counter1++;
            }
            this->setMap(map);
        }

        else if (dataFile == "Entwurfselement_KM.dbahn"){
            while(counter1 < count){
                QMap<QString, QString> object;
                double ID = document["features"][counter1]["properties"]["ID"].toDouble();
                QString STRECKENR = document["features"][counter1]["properties"]["STRECKENR"].toString();
                QString EELK_ELTYP = document["features"][counter1]["properties"]["EELK_ELTYP"].toString();
                double EELK_PARAM = document["features"][counter1]["properties"]["EELK_PARAM"].toDouble();
                double EELK_PAR_1 = document["features"][counter1]["properties"]["EELK_PAR_1"].toDouble();
                double EELK_PAR_2 = document["features"][counter1]["properties"]["EELK_PAR_2"].toDouble();
                QString KM_A_TEXT = document["features"][counter1]["properties"]["KM_A_TEXT"].toString();
                QString KM_E_TEXT = document["features"][counter1]["properties"]["KM_E_TEXT"].toString();
                //QString::number(ID);
                object.insert("ID", QString::number(ID,'f',0));
                object.insert("STRECKENR", STRECKENR);
                object.insert("EELK_ELTYP", EELK_ELTYP);
                object.insert("EELK_PARAM", QString::number(EELK_PARAM,'f',0));
                object.insert("EELK_PAR_1", QString::number(EELK_PAR_1,'f',0));
                object.insert("EELK_PAR_2", QString::number(EELK_PAR_2,'f',0));
                object.insert("KM_A_TEXT", KM_A_TEXT);
                object.insert("KM_E_TEXT", KM_E_TEXT);
                map.push_back(object);
                counter1++;
            }
            this->setMap(map);
        }

        std::vector<float> arrayOfCoordinates;
        std::vector<int> segmentCount;
        std::vector<QPointF> segmentExtremePoints;
//        std::vector<double> segmentExtremeKmValues;


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
