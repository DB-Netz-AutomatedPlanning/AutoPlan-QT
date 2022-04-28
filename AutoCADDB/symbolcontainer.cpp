#include "symbolcontainer.h"
#include "ui_symbolcontainer.h"

// OpenGl variables
bool isActive = false;
QString stationName = "";
QString geoJsonFileName = "";
int geoJsonCodeNo = 0;

// Preview Eulynx variables
QString folderPath = "";
QString stationLocation = "";

// project data and location
QString projectPath = "";
QString projectName = "";
QString countryCode ="";
QString fileFormat = "";
bool mouseDragMode = false;

QString glbObjectName = "sayli";
QString defaultObjectName = "default name";
bool createNewProject = false;

Tracks *tracks = nullptr;
bool rightPanelTable = false;

// Open Progress Bar Dialogue for euxml
bool isEuXml = false;
int totalValue =0;
int progressValue =2; // out of 8



//name
QString nameOfTrack = "";

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
