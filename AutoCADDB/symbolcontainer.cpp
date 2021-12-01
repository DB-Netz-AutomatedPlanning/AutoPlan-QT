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
int rightPanelTable = 0;

//RIGHT PANEL
QString kantenID ="id";
QString kantenLAENGE_ENT ="ent";
QString kantenRIKZ ="rikz";
QString kantenRIKZ_L ="rikzl";
QString kantenSTATUS ="status";

//KM
QString kmID ="id";
QString kmSTRECKENR ="stre";
QString kmEELK_ELTYP ="etlyp";
QString kmEELK_PARAM ="param";
QString kmEELK_PAR_1 ="par1";
QString kmEELK_PAR_2 = "par2";
QString kmKM_A_TEXT ="a";
QString kmKM_E_TEXT ="e";

//HOEHE
QString hoID ="ID";
QString hoPAD_A ="pad";
QString hoELTYP ="etly";
QString hoELTYP_L ="l";
QString hoPARAM1 ="1";
QString hoPARAM2 ="2";
QString hoPARAM3 ="3";
QString hoPARAM4 ="4";
QString hoRIKZ="riks";
QString hoRIKZ_L="l";
QString hoKM_A_KM="de";
QString hoKM_A_M="m";
QString hoKM_E_KM="km";
QString hoKM_E_M="em";
QString hoHOEHE_A="a";
QString hoHOEHE_E="e";


//LA Variables
QString laID="e";
QString laPAD_A="e";
QString laPAD_E="e";
QString laELTYP="e";
QString laELTYP_L="e";
QString laPARAM1="e";
QString laPARAM2="e";
QString laPARAM3="e";
QString laPARAM4="e";
QString laPARAM4_L="e";
QString laWINKEL_ANF="e";
QString laRIKZ="e";
QString laRIKZ_L="e";
QString laKM_A_KM="e";
QString laKM_A_M="e";
QString laKM_E_KM="e";
QString laKM_E_M="e";

//UH Variables
QString uhID="e";
QString uhPAD_A="e";
QString uhPAD_E="e";
QString uhELTYP="e";
QString uhELTYP_L="e";
QString uhPARAM1="e";
QString uhPARAM2="e";
QString uhPARAM3="e";
QString uhPARAM4="e";
QString uhRIKZ="e";
QString uhRIKZ_L="e";
QString uhKM_A_KM="e";
QString uhKM_A_M="e";
QString uhKM_E_KM="e";
QString uhKM_E_M="0.000000";

//KNOTEN Variables
QString knotenID="e";
QString kntKNOTENNAME="e";
QString kntKNOTENBESC="e";
QString kntTYP="e";
QString kntTYP_L="e";
QString kntSTATUS="e";
QString kntKM_KM="e";
QString kntKM_M="e";

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
