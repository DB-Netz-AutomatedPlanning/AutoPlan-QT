#ifndef COORDINATES_H
#define COORDINATES_H

#include <QObject>

#include <QFile>
#include<QDebug>
#include <QJsonDocument>
#include<QJsonArray>
#include<QJsonObject>
#include <QDataStream>

class Coordinates : public QObject
{
    Q_OBJECT
public:
    Coordinates(QString pPath, QString pName);      //QString station);
    void readCoordinates(QString dataFile = "", int dataCodeNumber = 0);
    void readProperties();


    const std::vector<float> &getCoordinateLists() const;
    void setCoordinateLists(const std::vector<float> &newCoordinateLists);

    const std::vector<int> &getSegment() const;
    void setSegment(const std::vector<int> &newSegment);

    const std::vector<QMap<QString, QString> > &getMap() const;
    void setMap(const std::vector<QMap<QString, QString> > &newMap);

signals:

private:
    QString pPath;
    QString pName;
    //QString station;
    std::vector<float> coordinateLists;
    std::vector<int> segment;
    std::vector<QMap<QString, QString>> map;

};

#endif // COORDINATES_H
