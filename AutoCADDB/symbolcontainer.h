#ifndef SYMBOLCONTAINER_H
#define SYMBOLCONTAINER_H

#include <QWidget>
#include "tracks.h"

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
extern bool mouseDragMode;
extern QString countryCode;
extern QString fileFormat;

extern Tracks *tracks;
extern QString projectName;

//Rotation Angle
extern int rotation_angle;

extern bool rightPanelTable;
extern bool showMessageBox;  // previewEulynxXML

extern bool isEuXml;
extern int totalValue;
extern int progressValue;

// path to remember
extern QString exportPath;
extern QString planningOutputPath;
extern QString newProjectPath;

//trackname
extern QString nameOfTrack;

#endif // SYMBOLCONTAINER_H
