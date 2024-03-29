#ifndef SIGNALFROMUNPROCESSEDJSON_H
#define SIGNALFROMUNPROCESSEDJSON_H

#include <QObject>
#include <QJsonDocument>

class SignalFromUnprocessedJson : public QObject
{
    Q_OBJECT
public:
    explicit SignalFromUnprocessedJson(QObject *parent = nullptr, QString filePath = "", const QString &newFilePath= "");
    std::vector<QString> lookForCoord(QString currentRef);
    void searchName();
    void searchLocation();
    void searchLateralSideAndDirection();
    void createSignalJson();
    QJsonObject properties(std::vector<QString> name, std::vector<QString> direction, std::vector<QString> side, std::vector<QString> location, int index);

    const std::vector<QString> &getName() const;
    void setName(const std::vector<QString> &newName);

    const std::vector<QString> &getLocation() const;
    void setLocation(const std::vector<QString> &newLocation);

    const std::vector<QString> &getLateralSide() const;
    void setLateralSide(const std::vector<QString> &newLateralSide);

    const std::vector<QString> &getDirection() const;
    void setDirection(const std::vector<QString> &newDirection);

signals:


private:
    QString filePath ="";
    QString newFilePath = "";
    std::vector<QString> name;
    std::vector<QString> lateralSide;
    std::vector<QString> direction;
    std::vector<QString> location;

    QJsonDocument document;
};

#endif // SIGNALFROMUNPROCESSEDJSON_H
