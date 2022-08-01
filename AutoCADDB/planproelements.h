#ifndef PLANPROELEMENTS_H
#define PLANPROELEMENTS_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>

class PlanProElements : public QObject
{
    Q_OBJECT
public:
    explicit PlanProElements(QObject *parent = nullptr, const QString &newKanten_Path = "", const QString &newKnoten_Path =""); //, QString xml_Path = "", const QString &output_JsonPath =""

public:
    void geoIndex();
    std::vector<std::vector<QString> > top_kanten();
    QMap<QString, QString> top_knoten();
    QMap<QString, std::vector<double> > topKnotenGeo_punkt();

    int getCounter() const;
    void setCounter(int newCounter);

    const QString &getWerk() const;
    void setWerk(const QString &newWerk);
    std::vector<double> lookForCoord(QString ID_GEO_Knoten);
    std::vector<std::vector<double> > arrayOfCoordinates();
    void setKantenParameters();
    QJsonObject kantenGeometry(std::vector<double> coord);
    QJsonObject knotenGeometry(std::vector<double>coord);

    QJsonObject properties (std::vector<QString> name, std::vector<QString> id, std::vector<QString> elementLength,
                            std::vector<QString> startRef, std::vector<QString> endRef, std::vector<QString> startValue,
                            std::vector<QString> geo_art, int index);
    QJsonObject knotenProperties (QList<QString> id, int index);

    QJsonObject Features(QJsonObject properties, QJsonObject geometry);
    void createJson();
    void createKnotenJson();

    const std::vector<QString> &getGeo_form() const;
    void setGeo_form(const std::vector<QString> &newGeo_form);

    const std::vector<QString> &getGeo_laenge() const;
    void setGeo_laenge(const std::vector<QString> &newGeo_laenge);

    const std::vector<QString> &getGeo_radiusA() const;
    void setGeo_radiusA(const std::vector<QString> &newGeo_radiusA);

    const std::vector<QString> &getGeo_radiusB() const;
    void setGeo_radiusB(const std::vector<QString> &newGeo_radiusB);

    const std::vector<QString> &getGeo_richtungswinkel() const;
    void setGeo_richtungswinkel(const std::vector<QString> &newGeo_richtungswinkel);

    const std::vector<QString> &getGeo_quelle() const;
    void setGeo_quelle(const std::vector<QString> &newGeo_quelle);

    const std::vector<QString> &getGeo_art() const;
    void setGeo_art(const std::vector<QString> &newGeo_art);

private:
//    QString xml_Path;
//    QString output_JsonPath;
    QJsonDocument document;
    int counter;
    QString werk;

    std::vector<QString> geo_form;
    std::vector<QString> geo_laenge;
    std::vector<QString> geo_radiusA;
    std::vector<QString> geo_radiusB;
    std::vector<QString> geo_richtungswinkel;
    std::vector<QString> geo_quelle;
    std::vector<QString> geo_art;

    QString newKanten_Path ="";
    QString newKnoten_Path ="";

};



#endif // PLANPROELEMENTS_H
