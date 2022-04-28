#ifndef READEULYNXSIGNALS_H
#define READEULYNXSIGNALS_H

#include<QObject>
#include <QMap>

class ReadEulnxSignals : public QObject
{
    Q_OBJECT
public:
    ReadEulnxSignals(QString pPath, QString pName);
    void readMainSignals();

    const std::vector<QMap<QString, QString> > &getParameters() const;
    void setParameters(const std::vector<QMap<QString, QString> > &newParameters);

signals:

private:
    QString pPath;
    QString pName;
    std::vector<QMap<QString, QString>> parameters;


};

#endif // READEULYNXSIGNALS_H
