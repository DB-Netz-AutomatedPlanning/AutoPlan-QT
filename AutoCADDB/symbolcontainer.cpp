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
bool createNewProject = false;
int countOfQmapCoordinates = 0;
 QString ELTYP = "";
 QString ELTYP_L = "";
 QString HOEHE_A = "";
 QString HOEHE_E = "";
 QString ID= "";
 QString KM_A_KM= "";
 QString KM_A_M= "";
 QString KM_E_KM= "";
 QString KM_E_M= "";
 QString PAD_A= "";
 QString PARAM1= "";
 QString PARAM2= "";
 QString PARAM3= "";
 QString PARAM4= "";
 QString RIKZ= "";
 QString RIKZ_L= "";


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
