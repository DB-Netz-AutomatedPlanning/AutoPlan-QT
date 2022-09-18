#ifndef SIGNALSFROMUNPROCESSEDJSON_H
#define SIGNALSFROMUNPROCESSEDJSON_H

#include <QObject>
#include <QJsonDocument>
#include <QMap>

class SignalsFromUnprocessedJson : public QObject
{
    Q_OBJECT
public:
    explicit SignalsFromUnprocessedJson(QObject *parent = nullptr, QString filePath="");

    std::vector<QString> lookForCoord(QString currentRef);

    std::vector<QString> searchID();
    std::vector<QString> ownSignalTypes();   // returns an enum of signal types
    std::vector<QString> ownSignalFunction();  // returns enum of signal functions
    void searchLocation();
    void searchLateralSideAndDirection();
    QString getSignalType(QString enumValue);
    QString getSignalFunction (QString enumValue);
    void createSignalJson();
    QJsonObject properties(std::vector<QString> name, std::vector<QString> direction, std::vector<QString> side, std::vector<QString> location, int index);

    std::vector<std::vector<QString>> signalInfos();

    const std::vector<QString> &getLocation() const;
    void setLocation(const std::vector<QString> &newLocation);

    const std::vector<QString> &getLateralSide() const;
    void setLateralSide(const std::vector<QString> &newLateralSide);

    const std::vector<QString> &getDirection() const;
    void setDirection(const std::vector<QString> &newDirection);

    const std::vector<std::vector<double> > &getAllNetGeoValues() const;
    void setAllNetGeoValues(const std::vector<std::vector<double> > &newAllNetGeoValues);

signals:


private:
    QString filePath ="";
    std::vector<QString> lateralSide;
    std::vector<QString> direction;
    std::vector<QString> location;
    std::vector <std::vector<double>> allNetGeoValues;

    QJsonDocument document;
    QMap <QString, QString> allTypes;
    QMap <QString, QString> allFunctions;
};

#endif // SIGNALSFROMUNPROCESSEDJSON_H
