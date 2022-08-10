#include "signalsfromunprocessedjson.h"
#include "symbolcontainer.h"
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>

SignalsFromUnprocessedJson::SignalsFromUnprocessedJson(QObject *parent, QString filePath)
    : QObject{parent}
{
    this->filePath = filePath;
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

    // Populate Signal Types
    allTypes.insert("0","Main");
    allTypes.insert("1","MainShunting");
    allTypes.insert("2", "MultiSection");
    allTypes.insert("3", "MultiSectionShunting");
    allTypes.insert("4", "Shunting");
    allTypes.insert("5", "Distant");
    allTypes.insert("6", "Repeater");
    allTypes.insert("7", "Train Protection");

    // Populate Signal Functions
    allFunctions.insert("0","entry");
    allFunctions.insert("1","exit");
    allFunctions.insert("2", "intermediate");
    allFunctions.insert("3", "advance");
    allFunctions.insert("4", "block");
    allFunctions.insert("5", "protection");
    allFunctions.insert("6", "train protection");
    allFunctions.insert("7", "groupMain");
    allFunctions.insert("8","groupIntermediate");
    allFunctions.insert("9","groupMainAndIntermediate");
    allFunctions.insert("10", "standAloneIndicator");
    allFunctions.insert("11", "trainDestinationOnlySignal");
    allFunctions.insert("12", "intermediateExitSignal");
    allFunctions.insert("13", "entryAndExit");
    allFunctions.insert("14", "entryAndBlock");
    allFunctions.insert("15", "further");
    allFunctions.insert("16","lxProtectionSignal");
    allFunctions.insert("17","distantOrRepeater");
}

std::vector<QString> SignalsFromUnprocessedJson::searchID()
{
    std::vector<QString> id;
    int i=0;
    while (!document["hasDataContainer"][0]["ownsRsmEntities"]["ownsSignal"][i].isUndefined()){
//        qDebug()<< "RSM_ID: " << document["hasDataContainer"][0]["ownsRsmEntities"]["ownsSignal"][i]["id"].toString();
        id.push_back(document["hasDataContainer"][0]["ownsRsmEntities"]["ownsSignal"][i]["id"].toString());
        i+=1;
    }
    return id;
}

std::vector<QString> SignalsFromUnprocessedJson::ownSignalTypes()
{
    std::vector<QString> allSignalTypes;
    std::vector<QString> id = searchID();
    for (int i=0; i < (int)id.size(); i++){
        QString currentID = id.at(i);
        int j=0;
        while (!document["hasDataContainer"][0]["ownsSignallingEntities"]["ownsTrackAsset"][j].isUndefined()){
            if (!document["hasDataContainer"][0]["ownsSignallingEntities"]["ownsTrackAsset"][j]["refersToRsmSignal"].isUndefined() &&
                    (currentID == document["hasDataContainer"][0]["ownsSignallingEntities"]["ownsTrackAsset"][j]["refersToRsmSignal"]["ref"].toString())){
//                qDebug()<< "JValue: "<< j;
                QString id_eulynx = document["hasDataContainer"][0]["ownsSignallingEntities"]["ownsTrackAsset"][j]["id"].toString();
                int k=0;
                bool signalTypeFound = false;
                while (!document["hasDataContainer"][0]["ownsSignallingEntities"]["ownsSignalType"][k].isUndefined()){
                    if (!document["hasDataContainer"][0]["ownsSignallingEntities"]["ownsSignalType"][k]["appliesToSignal"].isUndefined() &&
                            (document["hasDataContainer"][0]["ownsSignallingEntities"]["ownsSignalType"][k]["appliesToSignal"]["ref"].toString() == id_eulynx)){
                        QString signalType = QString::number(document["hasDataContainer"][0]["ownsSignallingEntities"]["ownsSignalType"][k]["isOfSignalTypeType"].toInt());
                        allSignalTypes.push_back(getSignalType(signalType));
                        signalTypeFound = true;
//                        qDebug() << "SignalType: " << getSignalType(signalType);
                        break;
                    } else k++;
                }
                if (!signalTypeFound) allSignalTypes.push_back("N/A");
                break;
            } else j++;
        }
    }
    return allSignalTypes;
}


std::vector<QString> SignalsFromUnprocessedJson::ownSignalFunction()
{
    std::vector<QString> allSignalFunctionTypes;
    std::vector<QString> id = searchID();
    for (int i=0; i < (int)id.size(); i++){
        QString currentID = id.at(i);
        int j=0;
        while (!document["hasDataContainer"][0]["ownsSignallingEntities"]["ownsTrackAsset"][j].isUndefined()){
            if (!document["hasDataContainer"][0]["ownsSignallingEntities"]["ownsTrackAsset"][j]["refersToRsmSignal"].isUndefined() &&
                    (currentID == document["hasDataContainer"][0]["ownsSignallingEntities"]["ownsTrackAsset"][j]["refersToRsmSignal"]["ref"].toString())){
                QString id_eulynx = document["hasDataContainer"][0]["ownsSignallingEntities"]["ownsTrackAsset"][j]["id"].toString();
                int k=0;
                bool signalFunctionFound = false;
                while (!document["hasDataContainer"][0]["ownsSignallingEntities"]["ownsSignalFunction"][k].isUndefined()){
                    if (!document["hasDataContainer"][0]["ownsSignallingEntities"]["ownsSignalFunction"][k]["appliesToSignal"].isUndefined() &&
                            (document["hasDataContainer"][0]["ownsSignallingEntities"]["ownsSignalFunction"][k]["appliesToSignal"]["ref"].toString() == id_eulynx)){
                        // Get the enum value and use it to get the signal Function
                        QString signalFunctionType = QString::number(document["hasDataContainer"][0]["ownsSignallingEntities"]["ownsSignalFunction"][k]["isOfSignalFunctionType"].toInt());
                        allSignalFunctionTypes.push_back(getSignalFunction(signalFunctionType));
                        signalFunctionFound = true;
                        break;
                    } else k++;
                }
                if (!signalFunctionFound) allSignalFunctionTypes.push_back("N/A");
                break;
            } else j++;
        }
    }
    return allSignalFunctionTypes;
}

//ToDo: Implement location getter and setter also for infrastructures that are not associated with the Net Element
void SignalsFromUnprocessedJson::searchLocation()
{
    std::vector<QString> kmValues;
    std::vector <std::vector<double>> geoValues;
    int j=0;
    while (!document["hasDataContainer"][0]["ownsRsmEntities"]["ownsSignal"][j].isUndefined()){

        // first get the ref of the location
        QString locationRef = document["hasDataContainer"][0]["ownsRsmEntities"]["ownsSignal"][j]["locations"][0]["ref"].toString();
//        qDebug()<< "Location ref: "<< locationRef;
        QString usesLocationRef_Km;
        QString usesLocationRef_Geo;

        // Match current locationRef with usesLocationRef;
        int l=0;
        while (!document["hasDataContainer"][0]["ownsRsmEntities"]["usesLocation"][l].isUndefined()){
            QString locationID = document["hasDataContainer"][0]["ownsRsmEntities"]["usesLocation"][l]["id"].toString();

            if(locationRef == locationID){
                // check for the linear coordinate ref
//                qDebug()<< "Same with ID: "<< locationID;
                usesLocationRef_Km = document["hasDataContainer"][0]["ownsRsmEntities"]["usesLocation"][l]["associatedNetElements"][0]["bounds"]
                        [0]["coordinates"][0]["ref"].isUndefined() ? "" : document["hasDataContainer"][0]["ownsRsmEntities"]["usesLocation"][l]["associatedNetElements"][0]["bounds"]
                        [0]["coordinates"][0]["ref"].toString();
//                qDebug()<< "usesLocationRef_Km: "<< usesLocationRef_Km;

                // Check the non-associated coordinate (linear coordinate ref)
                if (usesLocationRef_Km == "") {
                    usesLocationRef_Km = document["hasDataContainer"][0]["ownsRsmEntities"]["usesLocation"][l]["coordinates"][0]["ref"].isUndefined() ? "" : document["hasDataContainer"][0]
                            ["ownsRsmEntities"]["usesLocation"][l]["coordinates"][0]["ref"].toString();
                }
                // checking for the geographical coordinate ref
                usesLocationRef_Geo = document["hasDataContainer"][0]["ownsRsmEntities"]["usesLocation"][l]["associatedNetElements"][0]["bounds"]
                        [0]["coordinates"][1]["ref"].isUndefined() ? "" : document["hasDataContainer"][0]["ownsRsmEntities"]["usesLocation"][l]["associatedNetElements"][0]["bounds"]
                        [0]["coordinates"][1]["ref"].toString();

                // Also check the non-associated coordinate (Geo coordinate ref)
                if(usesLocationRef_Geo == ""){
                    usesLocationRef_Geo = document["hasDataContainer"][0]["ownsRsmEntities"]["usesLocation"][l]["coordinates"][1]["ref"].isUndefined() ? "" : document["hasDataContainer"][0]
                            ["ownsRsmEntities"]["usesLocation"][l]["coordinates"][1]["ref"].toString();
                }
                break;
            }
            l++;
        }
        std::vector<double> pointData;
//        qDebug()<< "usesLocationRef_Km: "<< usesLocationRef_Km;
        if (usesLocationRef_Km != ""){
            std::vector <QString> coordValue = lookForCoord(usesLocationRef_Km);
            kmValues.push_back(coordValue[0]);
        } else kmValues.push_back(QString::number(0));
        if (usesLocationRef_Geo != ""){
            std::vector<QString> coordValue = lookForCoord(usesLocationRef_Geo);
            //qDebug()<< "0 :"<< coordValue[0].toDouble() << "   1 :  "<< coordValue[1]<< "     2 :   " << coordValue[2];
            pointData.push_back(coordValue[0].toDouble());
            pointData.push_back(coordValue[1].toDouble());
            pointData.push_back(coordValue[2].toDouble());
        } else {
            // else, make the coordinate 0,0,0
            pointData.push_back(0);
            pointData.push_back(0);
            pointData.push_back(0);
        }
        geoValues.push_back(pointData);
        j++;
    }
    setLocation(kmValues);
    setAllNetGeoValues(geoValues);
//    qDebug() << "Length of KmValues: " << (int)getLocation().size();
//    qDebug() << "Length of geoValues: " << (int)getAllNetGeoValues().size();
}


void SignalsFromUnprocessedJson::searchLateralSideAndDirection()
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
//                qDebug()<< "TempSide: " << tempSide;
                if (tempSide == "1"){
                    lateralSide = "left";
                } else if (tempSide == "2") {
                    lateralSide = "right";
                } else lateralSide = "null";
                tempDir = QString::number(document["hasDataContainer"][0]["ownsRsmEntities"]["usesLocation"][l]["associatedNetElements"][0]["appliesInDirection"].toDouble());
//                qDebug()<< "TempDir "<< tempDir;
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
//    qDebug() << "Length of LateralSides: " << (int)getLateralSide().size();
//    qDebug() << "Length of KmValues: " << (int)getDirection().size();
}

QString SignalsFromUnprocessedJson::getSignalType(QString enumValue)
{
    if (enumValue.toInt() <0 || enumValue.toInt() > (allTypes.size()-1)) return "SignalType Not in Range";
    return allTypes[enumValue];
}

QString SignalsFromUnprocessedJson::getSignalFunction(QString enumValue)
{
    if (enumValue.toInt() <0 || enumValue.toInt() > (allFunctions.size()-1)) return "SignalFunction Not in Range";
    return allFunctions[enumValue];
}


std::vector<std::vector<QString> > SignalsFromUnprocessedJson::signalInfos()
{
    std::vector< std::vector<QString>> signalInfos;
    std::vector<QString> allSignalTypes = ownSignalTypes();
    std::vector<QString> allSignalFunctionTypes = ownSignalFunction();
    searchLateralSideAndDirection();
    searchLocation();
    std::vector<QString> sides = getLateralSide();
    std::vector<QString> direction = getDirection();
    std::vector<QString> location = getLocation();
    std::vector< std::vector<double>> geo = getAllNetGeoValues();

    for (int i =0; i< (int)allSignalTypes.size(); i++){
        std::vector<QString> eachSignal;
        eachSignal.push_back(allSignalTypes.at(i));
        eachSignal.push_back(allSignalFunctionTypes.at(i));
        eachSignal.push_back(sides.at(i));
        eachSignal.push_back(direction.at(i));
        eachSignal.push_back(location.at(i));
        eachSignal.push_back(QString::number(geo.at(i)[0]));
        eachSignal.push_back(QString::number(geo.at(i)[1]));
        eachSignal.push_back(QString::number(geo.at(i)[2]));
        signalInfos.push_back(eachSignal);
    }
    return signalInfos;
}


std::vector<QString> SignalsFromUnprocessedJson::lookForCoord(QString currentRef)
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

const std::vector<QString> &SignalsFromUnprocessedJson::getLocation() const
{
    return location;
}

void SignalsFromUnprocessedJson::setLocation(const std::vector<QString> &newLocation)
{
    location = newLocation;
}

const std::vector<QString> &SignalsFromUnprocessedJson::getLateralSide() const
{
    return lateralSide;
}

void SignalsFromUnprocessedJson::setLateralSide(const std::vector<QString> &newLateralSide)
{
    lateralSide = newLateralSide;
}

const std::vector<QString> &SignalsFromUnprocessedJson::getDirection() const
{
    return direction;
}

void SignalsFromUnprocessedJson::setDirection(const std::vector<QString> &newDirection)
{
    direction = newDirection;
}

const std::vector<std::vector<double> > &SignalsFromUnprocessedJson::getAllNetGeoValues() const
{
    return allNetGeoValues;
}

void SignalsFromUnprocessedJson::setAllNetGeoValues(const std::vector<std::vector<double> > &newAllNetGeoValues)
{
    allNetGeoValues = newAllNetGeoValues;
}
