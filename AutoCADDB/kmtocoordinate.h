#ifndef KMTOCOORDINATE_H
#define KMTOCOORDINATE_H

#include <QObject>
#include <QPointF>
#include "coordinates.h"

class KmToCoordinate : public QObject
{
    Q_OBJECT
public:
    explicit KmToCoordinate(QString pPath, QString pName);

    const std::vector<double> &getSegmentExtremeKmValues() const;
    void setSegmentExtremeKmValues(const std::vector<double> &newSegmentExtremeKmValues);

    const std::vector<QPointF> &getSegmentExtremePoints() const;
    void setSegmentExtremePoints(const std::vector<QPointF> &newSegmentExtremePoints);
    void calculateSegmentAllPoints();
    void calculateAngles();


    const std::vector<std::vector<QPointF> > &getSegmentAllPoints() const;
    void setSegmentAllPoints(const std::vector<std::vector<QPointF> > &newSegmentAllPoints);

//    const std::vector<double> &getSegmentPointDistance() const;
//    void setSegmentPointDistance(const std::vector<double> &newSegmentPointDistance);
    void calculateSegmentPointDistance();

    const std::vector<std::vector<double> > &getSegmentPointDistance() const;
    void setSegmentPointDistance(const std::vector<std::vector<double> > &newSegmentPointDistance);

//    const std::vector<double> &getSegmentPointDist() const;
//    void setSegmentPointDist(const std::vector<double> &newSegmentPointDist);

    const std::vector<double> &getSegmentLengths() const;
    void setSegmentLengths(const std::vector<double> &newSegmentLengths);
    void calculateSegmentLength();

    const std::vector<double> &getSegmentLengths_FromAddedValues() const;
    void setSegmentLengths_FromAddedValues(const std::vector<double> &newSegmentLengths_FromAddedValues);

    const std::vector<std::vector<double> > &getRealKmValues() const;
    void setRealKmValues(const std::vector<std::vector<double> > &newRealKmValues);
    void calculateRealKmValues();
    double estimateActualLength(double actualDist, double sumDist, double distToEstimate );


    const QMap<double, QPointF> &getKmAndCoord() const;
    void setKmAndCoord(const QMap<double, QPointF> &newKmAndCoord);
    void mapKmAndCoord();
    double searchNearestKmValue (double value);
    QPointF getNearestCoordFromKmValue(double value);
    double getAngleFromKmValue(double value);
    QPointF getNextCoordFromKmValue(double value);
    QPointF getFinalPosition(double value, double lateralDist, QString orientation);

    const QList<double> &getAngles() const;
    void setAngles(const QList<double> &newAngles);

signals:

private:
    QString pPath;
    QString pName;
    std::vector<double> segmentExtremeKmValues;
    std::vector<QPointF> segmentExtremePoints;
    std::vector<std::vector<QPointF>> segmentAllPoints;
    std::vector<std::vector<double>> segmentPointDistance;
//    std::vector<double> segmentPointDist;
    std::vector<double> segmentLengths;
    QList<double> angles;
    std::vector<double> segmentLengths_FromAddedValues;
    std::vector<std::vector<double>> realKmValues;
    QMap<double, QPointF> kmAndCoord;
    Coordinates *coord;


};

#endif // KMTOCOORDINATE_H
