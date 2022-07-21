#ifndef PLANPROELEMENTS_H
#define PLANPROELEMENTS_H

#include <QObject>
#include <QJsonDocument>

class PlanProElements : public QObject
{
    Q_OBJECT
public:
    explicit PlanProElements(QObject *parent = nullptr); //, QString xml_Path = "", const QString &output_JsonPath =""

public:
    void geoIndex();
    std::vector<std::vector<QString> > top_kanten();
    QMap<QString, QString> top_knoten();
    QMap <QString, std::vector<QString>> geo_punkt();

    int getCounter() const;
    void setCounter(int newCounter);

    const QString &getWerk() const;
    void setWerk(const QString &newWerk);

private:
//    QString xml_Path;
//    QString output_JsonPath;
    QJsonDocument document;
    int counter;
    QString werk;

};

#endif // PLANPROELEMENTS_H
