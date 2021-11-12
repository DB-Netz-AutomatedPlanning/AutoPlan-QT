#ifndef KMTOCOORDINATE_H
#define KMTOCOORDINATE_H

#include <QObject>

class KmToCoordinate : public QObject
{
    Q_OBJECT
public:
    explicit KmToCoordinate(QString pPath, QString pName);


signals:

private:
    QString pPath;
    QString pName;

};

#endif // KMTOCOORDINATE_H
