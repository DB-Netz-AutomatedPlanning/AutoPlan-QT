#ifndef SYMBOLCONTAINER_H
#define SYMBOLCONTAINER_H

#include <QWidget>
class QString;
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
#endif // SYMBOLCONTAINER_H
