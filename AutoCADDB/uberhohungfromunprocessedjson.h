#ifndef UBERHOHUNGFROMUNPROCESSEDJSON_H
#define UBERHOHUNGFROMUNPROCESSEDJSON_H

#include <QObject>
#include <QJsonDocument>

class UberhohungFromUnprocessedJson : public QObject
{
    Q_OBJECT
public:
    explicit UberhohungFromUnprocessedJson(QObject *parent = nullptr, QString filePath = "", const QString &newFilePath= "");
    void searchNameAndID();
    void searchStartRefAndStartKm();
    void createJson();
    QJsonObject geometry(std::vector<double> coord);
    QJsonObject properties (std::vector<QString> id, std::vector<QString> startRef, std::vector<QString> endRef,
                            std::vector<QString> startValue, std::vector<QString> endValue, int index);
    QJsonObject Features(QJsonObject properties, QJsonObject geometry);
    std::vector<QString> lookForCoord(QString currentRef);
    std::vector<std::vector<double> > arrayOfCoordinates();

    const std::vector<QString> &getId() const;
    void setId(const std::vector<QString> &newId);
    const std::vector<QString> &getStartRef() const;
    void setStartRef(const std::vector<QString> &newStartRef);

    const std::vector<QString> &getEndRef() const;
    void setEndRef(const std::vector<QString> &newEndRef);

    const std::vector<QString> &getStartValues() const;
    void setStartValues(const std::vector<QString> &newStartValues);

    const std::vector<QString> &getEndValues() const;
    void setEndValues(const std::vector<QString> &newEndValues);

signals:

private:
    QString filePath ="";
    QString newFilePath = "";
    std::vector<QString> id;
    std::vector<QString> startRef;
    std::vector<QString> endRef;
    std::vector<QString> startValues;
    std::vector<QString> endValues;

    QJsonDocument document;

};

#endif // UBERHOHUNGFROMUNPROCESSEDJSON_H
