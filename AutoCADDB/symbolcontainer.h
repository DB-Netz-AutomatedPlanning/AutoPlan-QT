#ifndef SYMBOLCONTAINER_H
#define SYMBOLCONTAINER_H

#include <QWidget>
class QString;
class QLabel;

namespace Ui {
class SymbolContainer;
}

class SymbolContainer : public QWidget
{
    Q_OBJECT

public:
    explicit SymbolContainer(QWidget *parent = nullptr);
    ~SymbolContainer();

private:
    Ui::SymbolContainer *ui;
};
extern QString glbObjectName;
extern QString defaultObjectName;
extern bool isActive;
extern QString stationName;
extern QString geoJsonFileName;
extern int geoJsonCodeNo;
extern QString folderPath;
extern QString stationLocation;

extern QString projectPath;
extern QString projectName;
extern bool createNewProject;
extern int countOfQmapCoordinates;

//String for Entwurfselement_HO

extern QString ELTYP;
extern QString ELTYP_L;
extern QString HOEHE_A;
extern QString HOEHE_E;
extern QString ID;
extern QString KM_A_KM;
extern QString KM_A_M;
extern QString KM_E_KM;
extern QString KM_E_M;
extern QString PAD_A;
extern QString PARAM1;
extern QString PARAM2;
extern QString PARAM3;
extern QString PARAM4;
extern QString RIKZ;
extern QString RIKZ_L;

#endif // SYMBOLCONTAINER_H
