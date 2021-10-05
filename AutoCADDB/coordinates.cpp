#include "coordinates.h"

Coordinates::Coordinates(QString station)
{
    this->station = station;
}

void Coordinates::readCoordinates(QString dataFile, int dataCodeNumber)
{
    /* readCoordinates(QString dataFile, int dataCodeNumber)
      dataFile can only be ...
      "Gleisknoten.geojson" corresponding to dataCodeNumber 1
      "Gleiskanten.geojson" corresponding to dataCodeNumber 2
      "Entwurfselement_Hoehe.geojson" corresponding to dataCodeNumber 3
      "Entwurfselement_KMLinie.geojson" corresponding to dataCodeNumber 4
      "Entwurfselement_Ueberhoehung.geojson" corresponding to dataCodeNumber 5
      "Entwurfselement_Lage.geojson" corresponding to dataCodeNumber 6

      The dataCodeNumber is neglected if user can produce the intended dataFile name to extract coordinates
    */

    if (dataFile == ""){
        switch (dataCodeNumber) {
        case 1: dataFile = "Gleisknoten.geojson";
            break;
        case 2: dataFile = "Gleiskanten.geojson";
            break;
        case 3: dataFile = "Entwurfselement_Hoehe.geojson";
            break;
        case 4: dataFile = "Entwurfselement_KMLinie.geojson";
            break;
        case 5: dataFile = "Entwurfselement_Ueberhoehung.geojson";
            break;
        case 6: dataFile = "Entwurfselement_Lage.geojson";
            break;
        default:
            qInfo()<< "You have entered invalid dataCodeNumber...\n "
                      "Please enter a valid dataCodeNumber between  1 to 5";
            return;
        }
    }

    QFile file ("Data/"+station+"/" + dataFile);
    if (!file.exists()){
        qInfo() << "File Not exist ... Also check that you've entered correct file name";
        return;
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qInfo()<< file.errorString();
        return;
    }
    QString jsonData;
    jsonData = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonData.toUtf8());

    int count =0;
    while(!document["features"][count].isUndefined()){
        count = count+1;
    }

    if (count == 0){
        qInfo() << "Coordinates cannot be found in your prefered data... Please use data preview section";
        return;
    }

    int value =0; // assign arbitrary value to data seleceted to be used for switch case statement;
    if (dataFile == "Gleisknoten.geojson"){
        value = 1;
    }else if (dataFile == "Gleiskanten.geojson" || dataFile =="Entwurfselement_Hoehe.geojson" || dataFile =="Entwurfselement_KMLinie.geojson" ||
              dataFile == "Entwurfselement_Ueberhoehung.geojson" || dataFile == "Entwurfselement_Lage.geojson"){
        value =2;
    }else {
        qInfo()<< "Please enter a valid data name";
        return;
    }
    qInfo()<< "Count"<<count;

    switch (value) {

    case 1:{

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
        std::vector<float> arrayOfCoordinates;
        std::vector<int> segmentCount;
        segmentCount.push_back(0);
        int globalCount =0;
        int counter =0;
        while (counter < count){
            int innerCount =0;

            while(!document["features"][counter]["geometry"]["coordinates"][innerCount].isUndefined()){
                innerCount++;
            }
            globalCount+=(innerCount*2);
            segmentCount.push_back(globalCount);

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
