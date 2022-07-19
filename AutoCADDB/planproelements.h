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
    std::vector<std::vector<QString> > top_kanten();
private:
//    QString xml_Path;
//    QString output_JsonPath;
    QJsonDocument document;

};

#endif // PLANPROELEMENTS_H
