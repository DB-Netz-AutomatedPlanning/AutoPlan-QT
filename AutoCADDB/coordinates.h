#ifndef COORDINATES_H
#define COORDINATES_H

#include <QObject>
#include <QFile>
#include<QDebug>
#include <QJsonDocument>
#include<QJsonArray>
#include<QJsonObject>
#include <QPointF>

class Coordinates : public QObject
{
    Q_OBJECT
public:
    Coordinates(QString pPath, QString pName);      //QString station);
    void readCoordinates(QString dataFile = "", QString countryCode ="", int dataCodeNumber = 0);

    const std::vector<float> &getCoordinateLists() const;
    void setCoordinateLists(const std::vector<float> &newCoordinateLists);

    const std::vector<int> &getSegment() const;
    void setSegment(const std::vector<int> &newSegment);

    const std::vector<QMap<QString, QString> > &getMap() const;
    void setMap(const std::vector<QMap<QString, QString> > &newMap);

    const std::vector<QPointF> &getSegmentExtremePoints() const;
    void setSegmentExtremePoints(const std::vector<QPointF> &newSegmentExtremePoints);

    const std::vector<double> &getSegmentExtremeKmValues() const;
    void setSegmentExtremeKmValues(const std::vector<double> &newSegmentExtremeKmValues);

    const QList<QString> &getDirection() const;
    void setDirection(const QList<QString> &newDirection);
    void setupData (int to, QJsonDocument document);

signals:

private:
    QString pPath;
    QString pName;
    //QString station;
    std::vector<float> coordinateLists;
    std::vector<int> segment;
    std::vector<QPointF> segmentExtremePoints;
    std::vector<double> segmentExtremeKmValues;
    std::vector<QMap<QString, QString>> map;
    QList<QString> direction;

};

#endif // COORDINATES_H
