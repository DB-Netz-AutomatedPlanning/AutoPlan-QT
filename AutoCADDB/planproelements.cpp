#include "planproelements.h"
#include <QFile>
#include "xml2json.h"
#include "symbolcontainer.h"

PlanProElements::PlanProElements(QObject *parent, QString xml_Path, const QString &output_JsonPath)
    : QObject{parent}
{
    this->xml_Path = xml_Path;
    this->output_JsonPath = output_JsonPath;

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


// ID of start and end point of nodes contained in the top kanten (edges)
std::vector<std::vector<QString>> PlanProElements::top_kanten()
{
    QString werk;
    std::vector<std::vector<QString>> topKanten;

    int counter=0;
    while (!document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"][counter]
           ["Untergewerk_Art"]["Wert"].isUndefined()) {
        werk = document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"][counter]
                ["Untergewerk_Art"]["Wert"].toString();
        if (werk  == "Geo") break;
        else counter++;
    }

    if (werk != "Geo") return topKanten;

    int topKanten_Count =0;
    while (!document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"][counter]
           ["LST_Zustand_Ziel"]["Container"]["TOP_Kante"][topKanten_Count].isUndefined()){
        QString ID_TOP_Knoten_A = document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"][counter]
                   ["LST_Zustand_Ziel"]["Container"]["TOP_Kante"][topKanten_Count]["ID_TOP_Knoten_A"]["Werk"].toString();
        QString ID_TOP_Knoten_B = document["PlanPro_Schnittstelle"]["LST_Planung"]["Fachdaten"]["Ausgabe_Fachdaten"][counter]
                   ["LST_Zustand_Ziel"]["Container"]["TOP_Kante"][topKanten_Count]["ID_TOP_Knoten_B"]["Werk"].toString();
        topKanten.at(topKanten_Count).push_back(ID_TOP_Knoten_A);
        topKanten.at(topKanten_Count).push_back(ID_TOP_Knoten_B);
        topKanten_Count++;
    }
    return topKanten;
}

