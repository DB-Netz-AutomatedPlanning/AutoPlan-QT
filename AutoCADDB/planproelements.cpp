#include "planproelements.h"
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>
#include "xml2json.h"
#include "symbolcontainer.h"

PlanProElements::PlanProElements(QObject *parent, const QString &newKanten_Path, const QString &newKnoten_Path) //, QString xml_Path, const QString &output_JsonPath
    : QObject{parent}
{
    this->newKanten_Path = newKanten_Path;
    this->newKnoten_Path = newKnoten_Path;

    // Establish path to the converted planPro (json)
    QString filePath = projectPath +"/"+projectName+ "/planPro.json";

    QFile file (filePath);
    if (!file.exists()){
        qInfo() << "PlanPro File Not exist ... Also check that you've entered correct file name";
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


void PlanProElements::geoIndex()
{
    QString werk;
    int counter=0;
    while (!document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"][counter]
           ["Untergewerk_Art"]["Wert"].isUndefined()) {
        werk = document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"][counter]
                ["Untergewerk_Art"]["Wert"].toString();
        if (werk  == "Geo") break;
        else counter++;
    }
    setCounter(counter);
    setWerk(werk);
}


// ID of start and end point of nodes contained in the top kanten (edges)
std::vector<std::vector<QString>> PlanProElements::top_kanten()
{
    std::vector<std::vector<QString>> topKanten;
    geoIndex();
    int counter = getCounter();
    if (getWerk() != "Geo") return topKanten;
    int topKanten_Count =0;
    while (!document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"][counter]
           ["LST_Zustand_Ziel"]["Container"]["TOP_Kante"][topKanten_Count].isUndefined()){
        std::vector<QString> points;  // start and end points
        QString ID_TOP_Knoten_A = document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"][counter]
                ["LST_Zustand_Ziel"]["Container"]["TOP_Kante"][topKanten_Count]["ID_TOP_Knoten_A"]["Wert"].toString();
        QString ID_TOP_Knoten_B = document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"][counter]
                ["LST_Zustand_Ziel"]["Container"]["TOP_Kante"][topKanten_Count]["ID_TOP_Knoten_B"]["Wert"].toString();
        points.push_back(ID_TOP_Knoten_A);
        points.push_back(ID_TOP_Knoten_B);
        topKanten.push_back(points);
        topKanten_Count++;
    }
    return topKanten;
}


/* the ID from top_kanen would be used to match corresponding top_knoten ID,
 * This is in order to extract ID Geo_Knoten
 */
QMap<QString, QString> PlanProElements::top_knoten()
{
    QMap<QString, QString> topKnoten;
    geoIndex();
    int counter = getCounter();
    if (getWerk() != "Geo") return topKnoten;
    std::vector<std::vector<QString>> topKanten = top_kanten();
    foreach (std::vector<QString> knoten, topKanten){
        for (int i=0; i<2; i++){
            QString currentID_TOP_KNOTEN = knoten.at(i);

            int topKnoten_Count =0;
            while (!document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"][counter]
                   ["LST_Zustand_Ziel"]["Container"]["TOP_Knoten"][topKnoten_Count].isUndefined()){

                QString Identity =  document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"][counter]
                        ["LST_Zustand_Ziel"]["Container"]["TOP_Knoten"][topKnoten_Count]["Identitaet"]["Wert"].toString();
                if (Identity == currentID_TOP_KNOTEN) {
                    QString ID_GEO_Knoten = document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"][counter]
                            ["LST_Zustand_Ziel"]["Container"]["TOP_Knoten"][topKnoten_Count]["ID_GEO_Knoten"]["Wert"].toString();
                    topKnoten.insert(currentID_TOP_KNOTEN, ID_GEO_Knoten);
                    break;
                } else topKnoten_Count++;
            }
        }
    }
    return topKnoten;
}

// Get the kanten reference and their actual geo point values (x and y)
QMap<QString, std::vector<double>> PlanProElements::topKnotenGeo_punkt()
{
    QMap<QString, std::vector<double>> topKnotenGeoPunkt;
    QMap<QString, QString> topKnoten = top_knoten();
    QStringList kantenID = topKnoten.keys();
    QStringList idGeoKnoten = topKnoten.values();

    geoIndex();
    int counter = getCounter();
    if (getWerk() != "Geo") return topKnotenGeoPunkt;

    int geoPunkt_Count  =0;
    int KantenID_Counter =0;
    foreach(QString id, idGeoKnoten){
        QString kanten_ID = kantenID.at(KantenID_Counter);

        while (!document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"][counter]
               ["LST_Zustand_Ziel"]["Container"]["GEO_Punkt"][geoPunkt_Count].isUndefined()){

            QString ID_GEO_Knoten = document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"][counter]
                    ["LST_Zustand_Ziel"]["Container"]["GEO_Punkt"][geoPunkt_Count]["ID_GEO_Knoten"]["Wert"].toString();
            if (ID_GEO_Knoten == id){
                std::vector<double> locationPt;
                QString x = document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"][counter]
                        ["LST_Zustand_Ziel"]["Container"]["GEO_Punkt"][geoPunkt_Count]["GEO_Punkt_Allg"]["GK_X"]["Wert"].toString();
                QString y = document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"][counter]
                        ["LST_Zustand_Ziel"]["Container"]["GEO_Punkt"][geoPunkt_Count]["GEO_Punkt_Allg"]["GK_Y"]["Wert"].toString();
                locationPt.push_back(x.toDouble());
                locationPt.push_back(y.toDouble());
                topKnotenGeoPunkt.insert(kanten_ID, locationPt);
                geoPunkt_Count =0;
                KantenID_Counter++;
                break;
            }else geoPunkt_Count++;
        }
    }
    return topKnotenGeoPunkt;
}

int PlanProElements::getCounter() const
{
    return counter;
}

void PlanProElements::setCounter(int newCounter)
{
    counter = newCounter;
}

const QString &PlanProElements::getWerk() const
{
    return werk;
}

void PlanProElements::setWerk(const QString &newWerk)
{
    werk = newWerk;
}

std::vector<double> PlanProElements::lookForCoord(QString ID_GEO_Knoten)
{
    std::vector<double> coord;
    geoIndex();
    int counter = getCounter();
    if (getWerk() != "Geo") return coord;

    int geoPunkt_Count =0;
    while (!document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"][counter]
           ["LST_Zustand_Ziel"]["Container"]["GEO_Punkt"][geoPunkt_Count].isUndefined()){
        QString current_ID_GEO_knoten = document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"][counter]
                ["LST_Zustand_Ziel"]["Container"]["GEO_Punkt"][geoPunkt_Count]["ID_GEO_Knoten"]["Wert"].toString();
        if (ID_GEO_Knoten == current_ID_GEO_knoten){
            QString x = document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"][counter]
                    ["LST_Zustand_Ziel"]["Container"]["GEO_Punkt"][geoPunkt_Count]["GEO_Punkt_Allg"]["GK_X"]["Wert"].toString();
            QString y = document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"][counter]
                    ["LST_Zustand_Ziel"]["Container"]["GEO_Punkt"][geoPunkt_Count]["GEO_Punkt_Allg"]["GK_Y"]["Wert"].toString();
            coord.push_back(x.toDouble());
            coord.push_back(y.toDouble());
            break;
        } else geoPunkt_Count++;
    }
    return coord;
}

std::vector<std::vector<double> > PlanProElements::arrayOfCoordinates()
{
    std::vector<std::vector<double> > allCoord;
    geoIndex();
    int counter = getCounter();
    if (getWerk() != "Geo") return allCoord;

    int geoKante_Count =0;
    while (!document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"][counter]
           ["LST_Zustand_Ziel"]["Container"]["GEO_Kante"][geoKante_Count].isUndefined()){
        std::vector<double> segmentData;
        QString ID_GEO_Knoten_A = document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"][counter]
                ["LST_Zustand_Ziel"]["Container"]["GEO_Kante"][geoKante_Count]["ID_GEO_Knoten_A"]["Wert"].toString();
        QString ID_GEO_Knoten_B = document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"][counter]
                ["LST_Zustand_Ziel"]["Container"]["GEO_Kante"][geoKante_Count]["ID_GEO_Knoten_B"]["Wert"].toString();
        std::vector<double> pointA = lookForCoord(ID_GEO_Knoten_A);
        std::vector<double> pointB = lookForCoord(ID_GEO_Knoten_B);
        segmentData.push_back(pointA[0]);
        segmentData.push_back(pointA[1]);
        segmentData.push_back(pointB[0]);
        segmentData.push_back(pointB[1]);
        allCoord.push_back(segmentData);
        geoKante_Count++;
    }
    return allCoord;
}

void PlanProElements::setKantenParameters()
{
    std::vector<QString> geo_form;
    std::vector<QString> geo_laenge;
    std::vector<QString> geo_radiusA;
    std::vector<QString> geo_radiusB;
    std::vector<QString> geo_richtungswinkel;
    std::vector<QString> geo_quelle;
    std::vector<QString> geo_art;

    geoIndex();
    int counter = getCounter();
    if (getWerk() != "Geo") return;

    int geoKante_Count =0;
    while (!document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"][counter]
           ["LST_Zustand_Ziel"]["Container"]["GEO_Kante"][geoKante_Count].isUndefined()){
        if(!document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"]
                [counter]["LST_Zustand_Ziel"]["Container"]["GEO_Kante"][geoKante_Count]
                ["GEO_Kante_Allg"]["GEO_Form"]["Wert"].isUndefined()){

            geo_form.push_back(document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]
                    ["Ausgabe_Fachdaten"][counter]["LST_Zustand_Ziel"]["Container"]["GEO_Kante"]
                    [geoKante_Count]["GEO_Kante_Allg"]["GEO_Form"]["Wert"].toString());
        }else geo_form.push_back("Null");

        if(!document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"]
                [counter]["LST_Zustand_Ziel"]["Container"]["GEO_Kante"][geoKante_Count]
                ["GEO_Kante_Allg"]["GEO_Laenge"]["Wert"].isUndefined()){

            geo_laenge.push_back(document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]
                    ["Ausgabe_Fachdaten"][counter]["LST_Zustand_Ziel"]["Container"]["GEO_Kante"]
                    [geoKante_Count]["GEO_Kante_Allg"]["GEO_Laenge"]["Wert"].toString());
        }else geo_laenge.push_back("Null");

        if(!document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"]
                [counter]["LST_Zustand_Ziel"]["Container"]["GEO_Kante"][geoKante_Count]
                ["GEO_Kante_Allg"]["GEO_Radius_A"]["Wert"].isUndefined()){

            geo_radiusA.push_back(document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]
                    ["Ausgabe_Fachdaten"][counter]["LST_Zustand_Ziel"]["Container"]["GEO_Kante"]
                    [geoKante_Count]["GEO_Kante_Allg"]["GEO_Radius_A"]["Wert"].toString());
        }else geo_radiusA.push_back("Null");

        if(!document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"]
                [counter]["LST_Zustand_Ziel"]["Container"]["GEO_Kante"][geoKante_Count]
                ["GEO_Kante_Allg"]["GEO_Radius_B"]["Wert"].isUndefined()){

            geo_radiusB.push_back(document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]
                    ["Ausgabe_Fachdaten"][counter]["LST_Zustand_Ziel"]["Container"]["GEO_Kante"]
                    [geoKante_Count]["GEO_Kante_Allg"]["GEO_Radius_B"]["Wert"].toString());
        }else geo_radiusB.push_back("Null");

        if(!document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"]
                [counter]["LST_Zustand_Ziel"]["Container"]["GEO_Kante"][geoKante_Count]
                ["GEO_Kante_Allg"]["GEO_Richtungswinkel"]["Wert"].isUndefined()){

            geo_richtungswinkel.push_back(document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]
                    ["Ausgabe_Fachdaten"][counter]["LST_Zustand_Ziel"]["Container"]["GEO_Kante"]
                    [geoKante_Count]["GEO_Kante_Allg"]["GEO_Richtungswinkel"]["Wert"].toString());
        }else geo_richtungswinkel.push_back("Null");

        if(!document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"]
                [counter]["LST_Zustand_Ziel"]["Container"]["GEO_Kante"][geoKante_Count]
                ["GEO_Kante_Allg"]["Plan_Quelle"]["Wert"].isUndefined()){

            geo_quelle.push_back(document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]
                    ["Ausgabe_Fachdaten"][counter]["LST_Zustand_Ziel"]["Container"]["GEO_Kante"]
                    [geoKante_Count]["GEO_Kante_Allg"]["Plan_Quelle"]["Wert"].toString());
        }else geo_quelle.push_back("Null");

        if(!document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"]
                [counter]["LST_Zustand_Ziel"]["Container"]["GEO_Kante"][geoKante_Count]
                ["ID_GEO_Art"]["Wert"].isUndefined()){

            geo_art.push_back(document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]
                    ["Ausgabe_Fachdaten"][counter]["LST_Zustand_Ziel"]["Container"]["GEO_Kante"]
                    [geoKante_Count]["ID_GEO_Art"]["Wert"].toString());
        }else geo_art.push_back("Null");

        geoKante_Count++;
    }
    setGeo_form(geo_form);
    setGeo_laenge(geo_laenge);
    setGeo_radiusA(geo_radiusA);
    setGeo_radiusB(geo_radiusB);
    setGeo_richtungswinkel(geo_richtungswinkel);
    setGeo_quelle(geo_quelle);
    setGeo_art(geo_art);
}


QJsonObject PlanProElements::kantenGeometry(std::vector<double> coord)
{
    QJsonObject geom;
    QJsonArray allCoord;
    for (int i=0; i< (int)coord.size(); i=i+2){
        QJsonArray currentArr;
        currentArr.append(coord.at(i));
        currentArr.append(coord.at(i+1));
        allCoord.append(currentArr);
    }

    geom.insert("type", "LineString");
    geom.insert("coordinates", allCoord);
    return geom;
}

QJsonObject PlanProElements::knotenGeometry(std::vector<double> coord)
{
    QJsonObject geom;
    QJsonArray allCoord;

    allCoord.append(coord.at(0));
    allCoord.append(coord.at(0+1));

    geom.insert("type", "Point");
    geom.insert("coordinates", allCoord);

    return geom;
}


QJsonObject PlanProElements::properties(std::vector<QString> geo_form, std::vector<QString> geo_laenge,
                                        std::vector<QString> geo_radiusA, std::vector<QString> geo_radiusB,
                                        std::vector<QString> geo_richtungswinkel, std::vector<QString> geo_quelle,
                                        std::vector<QString> geo_art, int index)
{
    QJsonObject prop;
    prop.insert("GEO_Form", geo_form.at(index));
    prop.insert("GEO_Laenge", geo_laenge.at(index));
    prop.insert("GEO_Radius_A", geo_radiusA.at(index));
    prop.insert("GEO_Radius_B", geo_radiusB.at(index));
    prop.insert("GEO_Richtungswinkel", geo_richtungswinkel.at(index));
    prop.insert("Plan_Quelle", geo_quelle.at(index));
    prop.insert("ID_GEO_Art", geo_art.at(index));
    return prop;
}

QJsonObject PlanProElements::knotenProperties(QList<QString> id, int index)
{
    QJsonObject prop;
    prop.insert("ID_GEO_Knoten", id.at(index));
    return prop;
}

QJsonObject PlanProElements::Features(QJsonObject properties, QJsonObject geometry)
{
    QJsonObject eachFeature;
    eachFeature.insert("type", "Feature");
    eachFeature.insert("properties", properties);
    eachFeature.insert("geometry", geometry);
    return eachFeature;
}

void PlanProElements::createJson()
{
    setKantenParameters();

    std::vector<QString> geo_form = getGeo_form();
    std::vector<QString> geo_laenge = getGeo_laenge();
    std::vector<QString> geo_radiusA = getGeo_radiusA();
    std::vector<QString> geo_radiusB = getGeo_radiusB();
    std::vector<QString> geo_richtungswinkel = getGeo_richtungswinkel();
    std::vector<QString> geo_quelle = getGeo_quelle();
    std::vector<QString> geo_art = getGeo_art();

    std::vector<std::vector<double> > allCoord = arrayOfCoordinates();

    qDebug()<< "All cord size: " << (int)allCoord.size();
    qDebug()<< "Geo_art: " << geo_art.at(1);
    QJsonArray allFeatures;
    for (int i=0; i< (int)allCoord.size(); i++){

        QJsonObject prop = properties (geo_form, geo_laenge, geo_radiusA, geo_radiusB,
                                       geo_richtungswinkel, geo_quelle, geo_art, i);
        QJsonObject geom = kantenGeometry(allCoord.at(i));
        QJsonObject features = Features(prop, geom);
        allFeatures.append(features);
    }

    /* If there is no Topology data (coordinate(s)), there is nothing to
    view, Hence, no need of creating internal json document*/
    if (allFeatures.isEmpty()) {
        //        progressValue++;
        qDebug()<< "Empty planpro kanten ";
        return;
    }
    QJsonObject content;
    content.insert("type", "FeatureCollection");
    content.insert("name", "Gleiskanten");
    content.insert("features", allFeatures);

    QJsonDocument document;
    document.setObject( content );
    QByteArray bytes = document.toJson( QJsonDocument::Indented );
    QFile file( newKanten_Path );
    if( file.open( QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate ) )
    {
        QTextStream iStream( &file );
        //iStream.setCodec( "utf-8" );
        iStream << bytes;
        file.close();
    }
    else
    {
        qDebug()<< "PlanPro: New File opening failed: " << file.errorString();
        //        std::cout << "file open failed: " << path.toStdString() << std::endl;
    }
    //    progressValue++;
    qDebug()<< "Planpro Progress Completed : "; //<< progressValue;
}

void PlanProElements::createKnotenJson()
{
    QMap<QString, std::vector<double>> topKnotenGeoPunkt = topKnotenGeo_punkt();
    QList<std::vector<double>> allCoord = topKnotenGeoPunkt.values();
    QList<QString> id = topKnotenGeo_punkt().keys();
    QJsonArray allFeatures;

    for (int i=0; i< (int)allCoord.size(); i++){
        QJsonObject prop = knotenProperties (id, i);
        QJsonObject geom = knotenGeometry(allCoord.at(i));
        QJsonObject features = Features(prop, geom);
        allFeatures.append(features);
    }

    /* If there is no Topology data (coordinate(s)), there is nothing to
    view, Hence, no need of creating internal json document*/
    if (allFeatures.isEmpty()) {
//        progressValue++;
//        qDebug()<< "Progress : " << progressValue;
        return;
    }
    QJsonObject content;
    content.insert("type", "FeatureCollection");
    content.insert("name", "Gleisknoten");
    content.insert("features", allFeatures);

    QJsonDocument document;
    document.setObject(content);
    QByteArray bytes = document.toJson();
    QFile file(newKnoten_Path);
    if(file.open( QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    {
        QTextStream iStream( &file );
        iStream << bytes;
        file.close();
    }
    else
    {
        qDebug()<< "File opening failed: " << file.errorString();
        //        std::cout << "file open failed: " << path.toStdString() << std::endl;
    }
//    progressValue++;
    qDebug()<< "PlanPro Knoten Completed: " ;
}


const std::vector<QString> &PlanProElements::getGeo_form() const
{
    return geo_form;
}

void PlanProElements::setGeo_form(const std::vector<QString> &newGeo_form)
{
    geo_form = newGeo_form;
}

const std::vector<QString> &PlanProElements::getGeo_laenge() const
{
    return geo_laenge;
}

void PlanProElements::setGeo_laenge(const std::vector<QString> &newGeo_laenge)
{
    geo_laenge = newGeo_laenge;
}

const std::vector<QString> &PlanProElements::getGeo_radiusA() const
{
    return geo_radiusA;
}

void PlanProElements::setGeo_radiusA(const std::vector<QString> &newGeo_radiusA)
{
    geo_radiusA = newGeo_radiusA;
}

const std::vector<QString> &PlanProElements::getGeo_radiusB() const
{
    return geo_radiusB;
}

void PlanProElements::setGeo_radiusB(const std::vector<QString> &newGeo_radiusB)
{
    geo_radiusB = newGeo_radiusB;
}

const std::vector<QString> &PlanProElements::getGeo_richtungswinkel() const
{
    return geo_richtungswinkel;
}

void PlanProElements::setGeo_richtungswinkel(const std::vector<QString> &newGeo_richtungswinkel)
{
    geo_richtungswinkel = newGeo_richtungswinkel;
}

const std::vector<QString> &PlanProElements::getGeo_quelle() const
{
    return geo_quelle;
}

void PlanProElements::setGeo_quelle(const std::vector<QString> &newGeo_quelle)
{
    geo_quelle = newGeo_quelle;
}

const std::vector<QString> &PlanProElements::getGeo_art() const
{
    return geo_art;
}

void PlanProElements::setGeo_art(const std::vector<QString> &newGeo_art)
{
    geo_art = newGeo_art;
}
