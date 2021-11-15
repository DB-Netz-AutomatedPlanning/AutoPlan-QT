#include "kmtocoordinate.h"
#include <QLineF>
#include <QPointF>


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

