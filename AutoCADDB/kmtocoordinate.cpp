#include "kmtocoordinate.h"
#include <QLineF>
#include <QPointF>
#include<QMap>
#include<math.h>


KmToCoordinate::KmToCoordinate(QString pPath, QString pName)
{
    this->pPath = pPath;
    this->pName = pName;

    coord = new Coordinates(pPath,pName);
    coord->readCoordinates("Entwurfselement_KM.dbahn");
    setSegmentExtremeKmValues(coord->getSegmentExtremeKmValues());
    setSegmentExtremePoints(coord->getSegmentExtremePoints());

}

const std::vector<double> &KmToCoordinate::getSegmentExtremeKmValues() const
{
    return segmentExtremeKmValues;
}

void KmToCoordinate::setSegmentExtremeKmValues(const std::vector<double> &newSegmentExtremeKmValues)
{
    segmentExtremeKmValues = newSegmentExtremeKmValues;
}

const std::vector<QPointF> &KmToCoordinate::getSegmentExtremePoints() const
{
    return segmentExtremePoints;
}

void KmToCoordinate::setSegmentExtremePoints(const std::vector<QPointF> &newSegmentExtremePoints)
{
    segmentExtremePoints = newSegmentExtremePoints;
}

const std::vector<std::vector<QPointF> > &KmToCoordinate::getSegmentAllPoints() const
{
    return segmentAllPoints;
}

void KmToCoordinate::setSegmentAllPoints(const std::vector<std::vector<QPointF> > &newSegmentAllPoints)
{
    segmentAllPoints = newSegmentAllPoints;
}


void KmToCoordinate::calculateSegmentPointDistance()
{
    std::vector<std::vector<QPointF>> segmentAllPts = getSegmentAllPoints();
    std::vector<std::vector<double>> segmentPtDis;

    int counter =0;
    foreach (auto val, segmentAllPts){
        segmentPtDis.push_back(std::vector<double>());

        for (int i = 0; i< static_cast<int>(val.size()-1); i++){
            double dist = QLineF( val[i], val[i+1] ).length();
            segmentPtDis[counter].push_back(dist);
        }
        counter++;
    }
    setSegmentPointDistance(segmentPtDis);
}

const std::vector<std::vector<double> > &KmToCoordinate::getSegmentPointDistance() const
{
    return segmentPointDistance;
}

void KmToCoordinate::setSegmentPointDistance(const std::vector<std::vector<double> > &newSegmentPointDistance)
{
    segmentPointDistance = newSegmentPointDistance;
}

const std::vector<double> &KmToCoordinate::getSegmentLengths() const
{
    return segmentLengths;
}

void KmToCoordinate::setSegmentLengths(const std::vector<double> &newSegmentLengths)
{
    segmentLengths = newSegmentLengths;
}

void KmToCoordinate::calculateSegmentLength()
{
    std::vector<double> segmentExtremeKmVals = getSegmentExtremeKmValues();
    std::vector<double> lenghts;
    for(int i =0; i< (int)segmentExtremeKmVals.size(); i=i+2){
        double val = segmentExtremeKmVals[i+1] - segmentExtremeKmVals[i];
        lenghts.push_back(val);
    }
    setSegmentLengths(lenghts);

    calculateSegmentAllPoints();
    calculateSegmentPointDistance();
    std::vector<std::vector<double>> segPtDistance = getSegmentPointDistance();
    std::vector<double> lenghts_asAdded;

    for (int i=0; i< (int)segPtDistance.size(); i++){
        double sum =0;
        foreach (double val, segPtDistance[i]){
            sum+=val;
        }
        lenghts_asAdded.push_back(sum);
    }
    setSegmentLengths_FromAddedValues(lenghts_asAdded);
}

const std::vector<double> &KmToCoordinate::getSegmentLengths_FromAddedValues() const
{
    return segmentLengths_FromAddedValues;
}

void KmToCoordinate::setSegmentLengths_FromAddedValues(const std::vector<double> &newSegmentLengths_FromAddedValues)
{
    segmentLengths_FromAddedValues = newSegmentLengths_FromAddedValues;
}

const std::vector<std::vector<double> > &KmToCoordinate::getRealKmValues() const
{
    return realKmValues;
}

void KmToCoordinate::setRealKmValues(const std::vector<std::vector<double> > &newRealKmValues)
{
    realKmValues = newRealKmValues;
}

void KmToCoordinate::calculateRealKmValues()
{
    int extremeCounter =0;
    std::vector<double> extremeKm = getSegmentExtremeKmValues();
    std::vector<double> actualSegLength = getSegmentLengths();
    std::vector<double> sumDist = getSegmentLengths_FromAddedValues(); // Length obtain by adding all the smaller segments;
    std::vector<std::vector<double>> segPtDist = getSegmentPointDistance();

    std::vector<std::vector<double>> real_Km_Values;

    for (int i=0; i<(int)segPtDist.size(); i++){
        double sum =0;
        real_Km_Values.push_back(std::vector<double>());
        sum += extremeKm[extremeCounter];
        real_Km_Values[i].push_back(sum);

        foreach(double val, segPtDist[i]){
            double estimate = estimateActualLength(actualSegLength[i],sumDist[i],val);
            sum += estimate;
            real_Km_Values[i].push_back(sum);
        }
        extremeCounter += 2;
    }

    setRealKmValues(real_Km_Values);
}

// ToDo: Comment here
double KmToCoordinate::estimateActualLength(double actualDist, double sumDist, double distToEstimate)
{
    return (actualDist*distToEstimate)/sumDist;
}

const QMap<double, QPointF> &KmToCoordinate::getKmAndCoord() const
{
    return kmAndCoord;
}

void KmToCoordinate::setKmAndCoord(const QMap<double, QPointF> &newKmAndCoord)
{
    kmAndCoord = newKmAndCoord;
}

void KmToCoordinate::mapKmAndCoord()
{
//    calculateSegmentAllPoints();
//    calculateSegmentPointDistance();
    calculateSegmentLength();
    calculateRealKmValues();
    std::vector<std::vector<double>> real_Km_Values = getRealKmValues();
    std::vector<std::vector<QPointF>> allPoints = getSegmentAllPoints();
    QMap<double, QPointF> km_And_Coord;
    int sum =0;
    for(int i=0; i< (int)allPoints.size(); i++){
        for(int j=0; j< (int)allPoints[i].size(); j++){
            km_And_Coord.insert(real_Km_Values[i][j],allPoints[i][j]);
            sum++;
        }
    }
    setKmAndCoord(km_And_Coord);
    qDebug()<< "Total = "<< sum;
}

// this function return the nearest Km value to the provided Km value
double KmToCoordinate::searchNearestKmValue(double value)
{
    QMap<double, QPointF> km_And_Coord = getKmAndCoord();
    QList<double> keys = km_And_Coord.keys();
    std::sort(keys.begin(),keys.end(), std::less<>());
    std::vector<std::vector<double>> real_Km_Values = getRealKmValues();

    for (int i=0; i< (int)realKmValues.size(); i++){
        if (value < keys[0] || value > keys[keys.size()-1]){
            qDebug()<< "Your input km value is not within your considered track range \n"
                       "ensure you have input correct value" ;
            break;

        }
        else if((value >= real_Km_Values[i][0] && value <= realKmValues[i][real_Km_Values[i].size() -1]) ||
                (value <= real_Km_Values[i][0] && value >= realKmValues[i][real_Km_Values[i].size() -1])){
            QMap<double, double> diff; // differences map with the Km values
            for (int j=0; j< (int)realKmValues[i].size(); j++){
                double factor = abs(realKmValues[i][j] - value);
                diff.insert(factor, realKmValues[i][j]);

            }
            QList<double> diffkeys = diff.keys();
            std::sort(diffkeys.begin(),diffkeys.end(), std::less<>());
            return diff[diffkeys[0]];
        }
    }
    return INT_MIN;
}

QPointF KmToCoordinate::getNearestCoordFromKmValue(double value)
{
    QMap<double, QPointF> km_And_Coord = getKmAndCoord();
    double val = searchNearestKmValue(value);
    if (val == INT_MIN){
        return QPointF(INT_MIN, INT_MIN);
    }
    else {
        return km_And_Coord[val];
    }
}

double KmToCoordinate::getAngleFromKmValue(double value)
{
    QMap<double, QPointF> km_And_Coord = getKmAndCoord();
    QList<double> keys = km_And_Coord.keys();
    std::sort(keys.begin(),keys.end(), std::less<>());
    double val = searchNearestKmValue(value);
    QList<double> allAngles = getAngles();
    int count =0;
    int counter =0;
    for (int i=0;i<keys.size(); i++){
        if (keys[i] == val){
            count++;
            counter++;
            break;
        } else {
            counter++;
        }
    }
    if (count ==1){
        return allAngles[counter-1];
    }
    else {
        qDebug()<< "Invalid Km value / Not within range";
        return INT_MIN;
    }
}


const QList<double> &KmToCoordinate::getAngles() const
{
    return angles;
}

void KmToCoordinate::setAngles(const QList<double> &newAngles)
{
    angles = newAngles;
}


void KmToCoordinate::calculateSegmentAllPoints()
{
    std::vector<std::vector<float>> vec;
    int segmentSize = coord->getSegment().size();

    for (int i=0; i<segmentSize-1; i++){
        vec.push_back(std::vector<float>());
        for (int j=coord->getSegment()[i]; j< coord->getSegment()[i+1]; j++){
            vec[i].push_back(coord->getCoordinateLists()[j]);
        }
    }
    std::vector<std::vector<QPointF>> allPoints;

    int counter =0;
    foreach (auto val, vec){
        int count =0;
        allPoints.push_back(std::vector<QPointF>());

        while (count < static_cast<int>(val.size())){

            allPoints[counter].push_back(QPointF(val[count],val[count+1]));
            count =  count +2;
        }
        counter++;
    }
    setSegmentAllPoints(allPoints);
}

void KmToCoordinate::calculateAngles()
{
    QMap<double, QPointF> km_And_Coord = getKmAndCoord();
    QList<QPointF> onlyPts = km_And_Coord.values();
    QList<double> angles;
    for (int i=0; i<onlyPts.size()-1; i++){
        double deltaY = onlyPts[i+1].y() - onlyPts[i].y();
        double deltaX = onlyPts[i+1].x() - onlyPts[i].x();
        double angle = atan2(deltaY, deltaX) * 180/M_PI;
        angles.append(angle);
    }
    setAngles(angles);
}

