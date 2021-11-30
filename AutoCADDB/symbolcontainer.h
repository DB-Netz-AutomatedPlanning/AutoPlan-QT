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

extern int rightPanelTable;

#endif // SYMBOLCONTAINER_H
