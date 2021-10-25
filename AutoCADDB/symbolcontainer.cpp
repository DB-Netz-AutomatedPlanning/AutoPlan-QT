#include "symbolcontainer.h"
#include "ui_symbolcontainer.h"

// OpenGl variables
bool isActive = false;
QString stationName = "Sayli";
QString geoJsonFileName = "Saif";
int geoJsonCodeNo = 0;

// Preview Eulynx variables
QString folderPath = "";
QString stationLocation = "";

// project data locatio
QString projectPath = "";
QString projectName = "";

QString glbObjectName = "sayli";
QString defaultObjectName = "default name";


SymbolContainer::SymbolContainer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SymbolContainer)
{
    ui->setupUi(this);
   glbObjectName = "sayli";
}

SymbolContainer::~SymbolContainer()
{

    glbObjectName = "sayli";
    delete ui ;
}
