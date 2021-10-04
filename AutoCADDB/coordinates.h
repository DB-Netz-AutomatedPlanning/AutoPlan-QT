#ifndef COORDINATES_H
#define COORDINATES_H

#include <QObject>

#include <QFile>
#include<QDebug>
#include <QJsonDocument>
#include<QJsonArray>
#include<QJsonObject>

class Coordinates : public QObject
{
    Q_OBJECT
public:
    Coordinates(QString station);
    void readCoordinates(QString dataFile = "", int dataCodeNumber = 0);


    const std::vector<float> &getCoordinateLists() const;
    void setCoordinateLists(const std::vector<float> &newCoordinateLists);

signals:

private:
    QString station;
    std::vector<float> coordinateLists;

};

#endif // COORDINATES_H
