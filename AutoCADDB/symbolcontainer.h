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

//Kanten variables
extern QString kantenID ;
extern QString kantenLAENGE_ENT;
extern QString kantenRIKZ;
extern QString kantenRIKZ_L;
extern QString kantenSTATUS;

//KM Variables
extern QString kmID;
extern QString kmSTRECKENR;
extern QString kmEELK_ELTYP;
extern QString kmEELK_PARAM;
extern QString kmEELK_PAR_1;
extern QString kmEELK_PAR_2;
extern QString kmKM_A_TEXT;
extern QString kmKM_E_TEXT;

//Hoehe Variables
extern QString hoID;
extern QString hoPAD_A;
extern QString hoELTYP;
extern QString hoELTYP_L;
extern QString hoPARAM1;
extern QString hoPARAM2;
extern QString hoPARAM3;
extern QString hoPARAM4;
extern QString hoRIKZ;
extern QString hoRIKZ_L;
extern QString hoKM_A_KM;
extern QString hoKM_A_M;
extern QString hoKM_E_KM;
extern QString hoKM_E_M;
extern QString hoHOEHE_A;
extern QString hoHOEHE_E;

//LA Variables
extern QString laID;
extern QString laPAD_A;
extern QString laPAD_E;
extern QString laELTYP;
extern QString laELTYP_L;
extern QString laPARAM1;
extern QString laPARAM2;
extern QString laPARAM3;
extern QString laPARAM4;
extern QString laPARAM4_L;
extern QString laWINKEL_ANF;
extern QString laRIKZ;
extern QString laRIKZ_L;
extern QString laKM_A_KM;
extern QString laKM_A_M;
extern QString laKM_E_KM;
extern QString laKM_E_M;

//UH Variables
extern QString uhID;
extern QString uhPAD_A;
extern QString uhPAD_E;
extern QString uhELTYP;
extern QString uhELTYP_L;
extern QString uhPARAM1;
extern QString uhPARAM2;
extern QString uhPARAM3;
extern QString uhPARAM4;
extern QString uhRIKZ;
extern QString uhRIKZ_L;
extern QString uhKM_A_KM;
extern QString uhKM_A_M;
extern QString uhKM_E_KM;
extern QString uhKM_E_M;

//KNOTEN Variables
extern QString knotenID;
extern QString kntKNOTENNAME;
extern QString kntKNOTENBESC;
extern QString kntTYP;
extern QString kntTYP_L;
extern QString kntSTATUS;
extern QString kntKM_KM;
extern QString kntKM_M;

//trackname
extern QString nameOfTrack;

#endif // SYMBOLCONTAINER_H
