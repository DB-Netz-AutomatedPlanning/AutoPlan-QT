#include "planproelements.h"
#include <QFile>
#include "xml2json.h"
#include "symbolcontainer.h"

PlanProElements::PlanProElements(QObject *parent) //, QString xml_Path, const QString &output_JsonPath
    : QObject{parent}
{
    //    this->xml_Path = xml_Path;
    //    this->output_JsonPath = output_JsonPath;

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
QMap<QString, std::vector<QString>> PlanProElements::geo_punkt()
{
    QMap<QString, std::vector<QString>> geoPunkt;
    QMap<QString, QString> topKnoten = top_knoten();
    QStringList kantenID = topKnoten.keys();
    QStringList idGeoKnoten = topKnoten.values();

    geoIndex();
    int counter = getCounter();
    if (getWerk() != "Geo") return geoPunkt;

    int geoPunkt_Count  =0;
    int KantenID_Counter =0;

    foreach(QString id, idGeoKnoten){
        QString kanten_ID = kantenID.at(KantenID_Counter);

        while (!document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"][counter]
               ["LST_Zustand_Ziel"]["Container"]["GEO_Punkt"][geoPunkt_Count].isUndefined()){

            QString ID_GEO_Knoten = document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"][counter]
                    ["LST_Zustand_Ziel"]["Container"]["GEO_Punkt"][geoPunkt_Count]["ID_GEO_Knoten"]["Wert"].toString();

            if (ID_GEO_Knoten == id){
                std::vector<QString> locationPt;
                QString x = document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"][counter]
                        ["LST_Zustand_Ziel"]["Container"]["GEO_Punkt"][geoPunkt_Count]["GEO_Punkt_Allg"]["GK_X"]["Wert"].toString();
                qDebug() << "x: " << x;
                QString y = document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"][counter]
                        ["LST_Zustand_Ziel"]["Container"]["GEO_Punkt"][geoPunkt_Count]["GEO_Punkt_Allg"]["GK_Y"]["Wert"].toString();
                qDebug() << "y: " << y;

                locationPt.push_back(x);
                locationPt.push_back(y);
                geoPunkt.insert(kanten_ID, locationPt);
                geoPunkt_Count =0;
                KantenID_Counter++;
                break;
            }else geoPunkt_Count++;
        }
    }
    return geoPunkt;
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
