#include "qgraphicssymbolcontainer.h"
#include "ui_qgraphicssymbolcontainer.h"
#include "symbolcontainer.h"
#include <QSvgRenderer>
#include <QGraphicsSvgItem>


bool zugCutomiseBtn = false;
bool vorStellwerksbedientCutomiseBtn = false;
bool wartezeichenCustomiseBtn = false;
bool AchszahlkontaktCustomiseBtn = false;
bool AnkundetafelCustomiseBtn = false;
bool balisengruppeLinksCustomiseBtn = false;
bool BalisengruppeUngesteuertTriCustomiseBtn = false;
bool BereichskennungswechselCustomiseBtn = false;
bool balisengruppeGesteuertCustomiseBtn = false;
bool EinzelbaliseRechtsCustomiseBtn = false;
bool EinzelbaliseUngesteuertCustomiseBtn = false;
bool ETCSstopTafelTwoCustomiseBtn = false;
bool FahrstrassensymboleReiseCustomiseBtn = false;
bool FestprellbockCustomiseBtn = false;
bool FruhhaltanzeigerCustomiseBtn = false;
bool GegengleisanzeigerLichtsignalCustomiseBtn = false;
bool GeschwindigkeitsCustomiseBtn = false;
bool GeshLichtsignalCustomiseBtn = false;
bool gesteuertRechtsCustomiseBtn = false;
bool hauptTunnelnCustomiseBtn = false;
bool KabelverteilerCustomiseBtn = false;
bool mehraCustomiseBtn = false;
bool MTafelCustomiseBtn = false;
bool reflektierendenCustomiseBtn = false;
bool SpeisegeratCustomiseBtn = false;
bool VorsignalbakenFiveCustomiseBtn = false;
bool KabelschrankCustomiseBtn = false;
bool WeitereOneCustomiseBtn = false;
bool zweiAktivenCustomiseBtn = false;


QGraphicsSymbolContainer::QGraphicsSymbolContainer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QGraphicsSymbolContainer)
{
    ui->setupUi(this);
    setWindowTitle("Add Symbols");

    pixmap=new QPixmap(100, 50);
    pixmap->fill(Qt::transparent);
    painter=new QPainter(pixmap);
    painter->drawPixmap(0, 0,  QPixmap(":/icons/assets/qgraphics/stellwerksbedient.svg"));
    painter->end();

    //HIDE ALL THE FRAMES

    ui->widget_zugbedient->hide();
    ui->widget_vorStellwerksbedient->hide();
    ui->frame_Wartezeichen->hide();
    ui->frame_Achszahlkontakt->hide();
    ui->frame_Ankundetafel->hide();
    ui->frame_balisengruppeLinks->hide();
    ui->frame_BalisengruppeUngesteuertTri->hide();
    ui->frame_Bereichskennungswechsel->hide();
    ui->frame_BalisengruppeGesteuert->hide();
    ui->frame_EinzelbaliseUngesteuert->hide();
    ui->frame_EinzelbaliseRechts->hide();
    ui->frame_ETCSstopTafelTwo->hide();
    ui->frame_FahrstrassensymboleReise->hide();
    ui->frame_Festprellbock->hide();
    ui->frame_Fruhhaltanzeiger->hide();
    ui->frame_GegengleisanzeigerLichtsignal->hide();
    ui->frame_Geschwindigkeits->hide();
    ui->frame_GeshLichtsignal->hide();
    ui->frame_gesteuertRechts->hide();
    ui->frame_hauptTunneln->hide();
    ui->frame_Kabelverteiler->hide();
    ui->frame_mehraZugbedient->hide();
    ui->frame_MTafel->hide();
    ui->frame_reflektierenden->hide();
    ui->frame_Speisegerat->hide();
    ui->frame_VorsignalbakenFive->hide();
    ui->frame_Kabelschrank->hide();
    ui->frame_WeitereOne->hide();
    ui->frame_zweiAktiven->hide();

}

QGraphicsSymbolContainer::~QGraphicsSymbolContainer()
{
    delete ui;
}


void QGraphicsSymbolContainer::on_pb1_clicked()
{
    tracks->addSymbol("Abfahrsignal");
//    QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Abfahrsignal.svg"));
//    tracks->setCursor(cursor_default);
}


void QGraphicsSymbolContainer::on_pb2_clicked()
{
    if(ui->checkBox_ZweiBuSchaltkontakt->isChecked()){
        tracks->addSymbol("ZweiBuSchaltkontakt");
    } else if(ui->checkBox_Schaltkontakt->isChecked()){
        tracks->addSymbol("Schaltkontakt");
    }else{
        tracks->addSymbol("Achszahlkontakt");
    }

}


void QGraphicsSymbolContainer::on_pb3_clicked()
{
    tracks->addSymbol("AutomatikETSchild");
}


void QGraphicsSymbolContainer::on_pb5_clicked()
{
    tracks->addSymbol("Andreaskreuz");
}


void QGraphicsSymbolContainer::on_pb6_clicked()
{
    tracks->addSymbol("AndreaskreuzAmPeitschenmast");
}


void QGraphicsSymbolContainer::on_pb7_clicked()
{
    tracks->addSymbol("Anfangsschleife");
}


void QGraphicsSymbolContainer::on_pb8_clicked()
{
    if(ui->checkBox_AutomatikETSchild->isChecked()){
        tracks->addSymbol("AutomatikETSchild");
    }else if(ui->checkBox_BuBuTafel->isChecked()){
        tracks->addSymbol("BuBuTafel");
    }else if(ui->checkBox_AutomatikHETSchild->isChecked()){
        tracks->addSymbol("AutomatikHETSchild");
    }else if(ui->checkBox_BuAnkundetafel->isChecked()){
        tracks->addSymbol("BuAnkundetafel");
    }else{
        tracks->addSymbol("Ankundetafel");
    }

}


void QGraphicsSymbolContainer::on_pb9_clicked()
{
    tracks->addSymbol("Ankundigungsbake");
}


void QGraphicsSymbolContainer::on_pb10_clicked()
{
    tracks->addSymbol("AusschaltEinschalt");
}


void QGraphicsSymbolContainer::on_pb11_clicked()
{
    tracks->addSymbol("AutomatikETSchild");
}


void QGraphicsSymbolContainer::on_pb12_clicked()
{
    tracks->addSymbol("AutomatikHETSchild");
}


void QGraphicsSymbolContainer::on_pb13_clicked()
{
    tracks->addSymbol("BalisengruppeGesteuert");
}


void QGraphicsSymbolContainer::on_pb14_clicked()
{
    tracks->addSymbol("BalisengruppeGesteuertTri");
}


void QGraphicsSymbolContainer::on_pb15_clicked()
{

    if(ui->checkBox_balisengruppeLinks->isChecked()){
       tracks->addSymbol("balisengruppeRechts");
    }else{
       tracks->addSymbol("balisengruppeLinks");
    }

}


void QGraphicsSymbolContainer::on_pb16_clicked()
{
    tracks->addSymbol("balisengruppeRechts");
}


void QGraphicsSymbolContainer::on_pb17_clicked()
{
    if(ui->checkBox_BalisengruppeGesteuert->isChecked()){
       tracks->addSymbol("BalisengruppeGesteuert");
    }else{
       tracks->addSymbol("BalisengruppeunGesteuert");
    }

}


void QGraphicsSymbolContainer::on_pb18_clicked()
{
    if(ui->checkBox_BalisengruppeGesteuertTri->isChecked()){
       tracks->addSymbol("BalisengruppeGesteuertTri");
    }else{
       tracks->addSymbol("BalisengruppeUngesteuertTri");
    }

}


void QGraphicsSymbolContainer::on_pb19_clicked()
{
    if(ui->checkBox_Bereichskennungswechsel->isChecked()){
       tracks->addSymbol("Bereichskennungswechselortungsneutral");
    }else{
       tracks->addSymbol("Bereichskennungswechsel");
    }

}


void QGraphicsSymbolContainer::on_pb20_clicked()
{
     tracks->addSymbol("Bereichskennungswechselortungsneutral");
}


void QGraphicsSymbolContainer::on_pb21_clicked()
{
     tracks->addSymbol("Blockkennzeichen");
}


void QGraphicsSymbolContainer::on_pb22_clicked()
{
     tracks->addSymbol("Blockschaltbilder");
}


void QGraphicsSymbolContainer::on_pb23_clicked()
{
     tracks->addSymbol("Bremsprellbock");
}


void QGraphicsSymbolContainer::on_pb24_clicked()
{
     tracks->addSymbol("Bremsprobe");
}


void QGraphicsSymbolContainer::on_pb25_clicked()
{
     tracks->addSymbol("BuAnkundetafel");
}


void QGraphicsSymbolContainer::on_pb26_clicked()
{
     tracks->addSymbol("BuAnkundetafelWiederholer");
}


void QGraphicsSymbolContainer::on_pb27_clicked()
{
     tracks->addSymbol("BuAnkundetafelWiederholerOne");
}


void QGraphicsSymbolContainer::on_pb28_clicked()
{
     tracks->addSymbol("BuBetonschalthaus");
}


void QGraphicsSymbolContainer::on_pb29_clicked()
{
     tracks->addSymbol("BuBuTafel");
}


void QGraphicsSymbolContainer::on_pb30_clicked()
{
     tracks->addSymbol("BuSchaltkontakt");
}


void QGraphicsSymbolContainer::on_pb31_clicked()
{
     tracks->addSymbol("EinschaltGleisAusschaltmagnet");
}


void QGraphicsSymbolContainer::on_pb32_clicked()
{
    if(ui->checkBox_EinzelbaliseUngesteuert->isChecked()){
         tracks->addSymbol("EinzelbaliseUngesteuert");
    }else{
        tracks->addSymbol("EinzelbaliseGesteuert");
    }
}


void QGraphicsSymbolContainer::on_pb33_clicked()
{
    if(ui->checkBox_EinzelbaliseRechts->isChecked()){
         tracks->addSymbol("EinzelbaliseRechts");
    }else{
        tracks->addSymbol("EinzelbaliseLinks");
    }

}


void QGraphicsSymbolContainer::on_pb34_clicked()
{
     tracks->addSymbol("EinzelbaliseRechts");
}


void QGraphicsSymbolContainer::on_pb35_clicked()
{
     tracks->addSymbol("EinzelbaliseUngesteuert");
}


void QGraphicsSymbolContainer::on_pb36_clicked()
{
     tracks->addSymbol("ErsatzsignalHauptsignalschirm");
}


void QGraphicsSymbolContainer::on_pb37_clicked()
{
    if(ui->checkBox_ETCSstopTafelTwo->isChecked()){
         tracks->addSymbol("ETCSstopTafelTwo");
    }else{
        tracks->addSymbol("ETCSstopTafelOne");
    }

}


void QGraphicsSymbolContainer::on_pb38_clicked()
{
     tracks->addSymbol("ETCSstopTafelTwo");
}


void QGraphicsSymbolContainer::on_stellwerksbedient_clicked()
{
     tracks->addSymbol("stellwerksbedient");
}


void QGraphicsSymbolContainer::on_pb_hauptSignalbegriffe_clicked()
{
         tracks->addSymbol("stellwerksbedient");
}


void QGraphicsSymbolContainer::on_pb_fdurchfarten_clicked()
{
   tracks->addSymbol("FahrstrassensymboleDurchfahrten");
}


void QGraphicsSymbolContainer::on_pb_FDurchGuterzuge_clicked()
{
   tracks->addSymbol("FahrstrassensymboleDurchGuterzuge");

}


void QGraphicsSymbolContainer::on_btn_zugbedient_clicked()
{
    if(zugCutomiseBtn){
        zugCutomiseBtn = false;
        ui->widget_zugbedient->hide();
    }else{
        zugCutomiseBtn = true;
        ui->widget_zugbedient->show();
    }
}


void QGraphicsSymbolContainer::on_chb_zug_filled_clicked()
{
    ui->chb_zug_partial->setChecked(false);
    ui->chb_zug_nofill->setChecked(false);
    ui->chb_zug_arrow->setChecked(false);

    if (ui->chb_zug_filled->isChecked()) {
        ui->lbl_zugbedient->setIcon(QIcon(":/icons/assets/qgraphics/stellwerksbedient.svg"));
    } else {
        ui->lbl_zugbedient->setIcon(QIcon(":/icons/assets/qgraphics/zugbedient.svg"));
    }
}


void QGraphicsSymbolContainer::on_chb_zug_partial_clicked()
{
    ui->chb_zug_nofill->setChecked(false);
    ui->chb_zug_filled->setChecked(false);
    ui->chb_zug_arrow->setChecked(false);

    if (ui->chb_zug_partial->isChecked()) {
        ui->lbl_zugbedient->setIcon(QIcon(":/icons/assets/qgraphics/zugOderStellwerksbedient.svg"));
    } else {
         ui->lbl_zugbedient->setIcon(QIcon(":/icons/assets/qgraphics/zugbedient.svg"));
    }
}


void QGraphicsSymbolContainer::on_chb_zug_arrow_clicked()
{

    if (ui->chb_zug_arrow->isChecked()) {
ui->lbl_zugbedient->setIcon(QIcon(":/icons/assets/qgraphics/zugbedientArrow.svg"));

        if((ui->chb_zug_filled->isChecked())){
            ui->lbl_zugbedient->setIcon(QIcon(":/icons/assets/qgraphics/stellwerksbedientArrow.svg"));
        }
        if((ui->chb_zug_nofill->isChecked())){
            ui->lbl_zugbedient->setIcon(QIcon(":/icons/assets/qgraphics/zugbedientArrow.svg"));
        }
        if((ui->chb_zug_partial->isChecked())){
            ui->lbl_zugbedient->setIcon(QIcon(":/icons/assets/qgraphics/zugOderStellwerksbedientArrow.svg"));
        }
    } else {
        ui->lbl_zugbedient->setIcon(QIcon(":/icons/assets/qgraphics/zugbedient.svg"));
         if((ui->chb_zug_filled->isChecked())){
            ui->lbl_zugbedient->setIcon(QIcon(":/icons/assets/qgraphics/stellwerksbedient.svg"));
         }
         if((ui->chb_zug_nofill->isChecked())){
             ui->lbl_zugbedient->setIcon(QIcon(":/icons/assets/qgraphics/zugbedient.svg"));
         }
         if((ui->chb_zug_partial->isChecked())){
             ui->lbl_zugbedient->setIcon(QIcon(":/icons/assets/qgraphics/zugOderStellwerksbedient.svg"));
         }
    }
}


void QGraphicsSymbolContainer::on_chb_zug_nofill_clicked()
{
    ui->chb_zug_partial->setChecked(false);
    ui->chb_zug_filled->setChecked(false);
    ui->chb_zug_arrow->setChecked(false);
    if (ui->chb_zug_nofill->isChecked()) {
        ui->lbl_zugbedient->setIcon(QIcon(":/icons/assets/qgraphics/zugbedient.svg"));
    } else {
         painter->drawPixmap(0, 0, QPixmap(":/icons/assets/qgraphics/zugbedient.svg"));
    }
}


void QGraphicsSymbolContainer::on_pushButton_vorStellwerksbedient_clicked()
{
    if(vorStellwerksbedientCutomiseBtn){
        vorStellwerksbedientCutomiseBtn = false;
        ui->widget_vorStellwerksbedient->hide();
    }else{
        vorStellwerksbedientCutomiseBtn = true;
        ui->widget_vorStellwerksbedient->show();
    }
}


void QGraphicsSymbolContainer::on_checkBox_vorStellwerksbedient_clicked()
{
    ui->checkBox_vorZugoderStellwerksbedient->setChecked(false);
    ui->checkBox_Arrow->setChecked(false);

    if (ui->checkBox_vorStellwerksbedient->isChecked()) {
        ui->pushbutton_vorZugbedient->setIcon(QIcon(":/icons/assets/qgraphics/vorStellwerksbedient.svg"));
    } else {
         ui->pushbutton_vorZugbedient->setIcon(QIcon(":/icons/assets/qgraphics/vorZugbedient.svg"));
    }
}

void QGraphicsSymbolContainer::on_checkBox_vorZugoderStellwerksbedient_clicked()
{
    ui->checkBox_vorStellwerksbedient->setChecked(false);
    ui->checkBox_Arrow->setChecked(false);

    if (ui->checkBox_vorZugoderStellwerksbedient->isChecked()) {
        ui->pushbutton_vorZugbedient->setIcon(QIcon(":/icons/assets/qgraphics/vorZugoderStellwerksbedient.svg"));
    } else {
         ui->pushbutton_vorZugbedient->setIcon(QIcon(":/icons/assets/qgraphics/vorZugbedient.svg"));
    }
}

void QGraphicsSymbolContainer::on_checkBox_Arrow_clicked()
{
    if (ui->checkBox_Arrow->isChecked()) {
         ui->pushbutton_vorZugbedient->setIcon(QIcon(":/icons/assets/qgraphics/vorZugbedientArrow.svg"));
        if(ui->checkBox_vorZugoderStellwerksbedient->isChecked()){
             ui->pushbutton_vorZugbedient->setIcon(QIcon(":/icons/assets/qgraphics/vorZugoderStellwerksbedientArrow.svg"));
        }
        if(ui->checkBox_vorStellwerksbedient->isChecked()){
             ui->pushbutton_vorZugbedient->setIcon(QIcon(":/icons/assets/qgraphics/vorStellwerksbedientArrow.svg"));
        }
    } else {
         ui->pushbutton_vorZugbedient->setIcon(QIcon(":/icons/assets/qgraphics/vorZugbedient.svg"));
        if(ui->checkBox_vorZugoderStellwerksbedient->isChecked()){
             ui->pushbutton_vorZugbedient->setIcon(QIcon(":/icons/assets/qgraphics/vorZugoderStellwerksbedient.svg"));
        }
        if(ui->checkBox_vorStellwerksbedient->isChecked()){
             ui->pushbutton_vorZugbedient->setIcon(QIcon(":/icons/assets/qgraphics/vorStellwerksbedien.svg"));
        }
    }
}


void QGraphicsSymbolContainer::on_pushButton_Wartezeichen_clicked()
{
    if(wartezeichenCustomiseBtn){
        wartezeichenCustomiseBtn = false;
        ui->frame_Wartezeichen->hide();
    }else{
        wartezeichenCustomiseBtn = true;
        ui->frame_Wartezeichen->show();
    }
}


void QGraphicsSymbolContainer::on_checkBox_Wartezeichenmit_clicked()
{
    if (ui->checkBox_Wartezeichenmit->isChecked()) {
        ui->pushButton_WartezeichenMain->setIcon(QIcon(":/icons/assets/qgraphics/Wartezeichenmit.svg"));
    } else {
         ui->pushButton_WartezeichenMain->setIcon(QIcon(":/icons/assets/qgraphics/Wartezeichen.svg"));
    }
}


void QGraphicsSymbolContainer::on_pushButton_Achszahlkontakt_clicked()
{
        if(AchszahlkontaktCustomiseBtn){
            AchszahlkontaktCustomiseBtn = false;
            ui->frame_Achszahlkontakt->hide();
        }else{
            AchszahlkontaktCustomiseBtn = true;
            ui->frame_Achszahlkontakt->show();
        }
}


void QGraphicsSymbolContainer::on_checkBox_ZweiBuSchaltkontakt_clicked()
{
    ui->checkBox_Schaltkontakt->setChecked(false);
    if (ui->checkBox_ZweiBuSchaltkontakt->isChecked()) {
        ui->pb2->setIcon(QIcon(":/icons/assets/qgraphics/ZweiBuSchaltkontakt.svg"));
    } else {
         ui->pb2->setIcon(QIcon(":/icons/assets/qgraphics/Achszahlkontakt.svg"));
    }
}

void QGraphicsSymbolContainer::on_checkBox_Schaltkontakt_clicked()
{
    ui->checkBox_ZweiBuSchaltkontakt->setChecked(false);
    if (ui->checkBox_Schaltkontakt->isChecked()) {
        ui->pb2->setIcon(QIcon(":/icons/assets/qgraphics/Schaltkontakt.svg"));
    } else {
         ui->pb2->setIcon(QIcon(":/icons/assets/qgraphics/Achszahlkontakt.svg"));
    }
}


void QGraphicsSymbolContainer::on_pushButton_Ankundetafel_clicked()
{
            if(AnkundetafelCustomiseBtn){
                AnkundetafelCustomiseBtn = false;
                ui->frame_Ankundetafel->hide();
            }else{
                AnkundetafelCustomiseBtn = true;
                ui->frame_Ankundetafel->show();
            }
}


void QGraphicsSymbolContainer::on_checkBox_AutomatikETSchild_clicked()
{
        ui->checkBox_AutomatikHETSchild->setChecked(false);
        ui->checkBox_BuAnkundetafel->setChecked(false);
        ui->checkBox_BuBuTafel->setChecked(false);


        if (ui->checkBox_AutomatikETSchild->isChecked()) {
            ui->pb8->setIcon(QIcon(":/icons/assets/qgraphics/AutomatikETSchild.svg"));
        } else {
             ui->pb8->setIcon(QIcon(":/icons/assets/qgraphics/Ankundetafel.svg"));
        }
}


void QGraphicsSymbolContainer::on_checkBox_AutomatikHETSchild_clicked()
{
    ui->checkBox_AutomatikETSchild->setChecked(false);
    ui->checkBox_BuAnkundetafel->setChecked(false);
    ui->checkBox_BuBuTafel->setChecked(false);

    if (ui->checkBox_AutomatikHETSchild->isChecked()) {
        ui->pb8->setIcon(QIcon(":/icons/assets/qgraphics/AutomatikHETSchild.svg"));
    } else {
         ui->pb8->setIcon(QIcon(":/icons/assets/qgraphics/Ankundetafel.svg"));
    }
}


void QGraphicsSymbolContainer::on_checkBox_BuAnkundetafel_clicked()
{
    ui->checkBox_AutomatikHETSchild->setChecked(false);
    ui->checkBox_AutomatikETSchild->setChecked(false);
    ui->checkBox_BuBuTafel->setChecked(false);

    if (ui->checkBox_BuAnkundetafel->isChecked()) {
        ui->pb8->setIcon(QIcon(":/icons/assets/qgraphics/BuAnkundetafel.svg"));
    } else {
         ui->pb8->setIcon(QIcon(":/icons/assets/qgraphics/Ankundetafel.svg"));
    }
}


void QGraphicsSymbolContainer::on_checkBox_BuBuTafel_clicked()
{
    ui->checkBox_AutomatikHETSchild->setChecked(false);
    ui->checkBox_BuAnkundetafel->setChecked(false);
    ui->checkBox_AutomatikETSchild->setChecked(false);

    if (ui->checkBox_BuBuTafel->isChecked()) {
        ui->pb8->setIcon(QIcon(":/icons/assets/qgraphics/BuBuTafel.svg"));
    } else {
         ui->pb8->setIcon(QIcon(":/icons/assets/qgraphics/Ankundetafel.svg"));
    }
}


void QGraphicsSymbolContainer::on_pushButton_balisengruppeLinks_clicked()
{
            if(balisengruppeLinksCustomiseBtn){
                balisengruppeLinksCustomiseBtn = false;
                ui->frame_balisengruppeLinks->hide();
            }else{
                balisengruppeLinksCustomiseBtn = true;
                ui->frame_balisengruppeLinks->show();
            }
}


void QGraphicsSymbolContainer::on_checkBox_balisengruppeLinks_clicked()
{

    if (ui->checkBox_balisengruppeLinks->isChecked()) {
        ui->pb15->setIcon(QIcon(":/icons/assets/qgraphics/balisengruppeRechts.svg"));
    } else {
         ui->pb15->setIcon(QIcon(":/icons/assets/qgraphics/balisengruppeLinks.svg"));
    }
}


void QGraphicsSymbolContainer::on_pushButton_BalisengruppeUngesteuertTri_clicked()
{
    if(BalisengruppeUngesteuertTriCustomiseBtn){
        BalisengruppeUngesteuertTriCustomiseBtn = false;
        ui->frame_BalisengruppeUngesteuertTri->hide();
    }else{
        BalisengruppeUngesteuertTriCustomiseBtn = true;
        ui->frame_BalisengruppeUngesteuertTri->show();
    }
}


void QGraphicsSymbolContainer::on_checkBox_BalisengruppeGesteuertTri_clicked()
{
    if (ui->checkBox_BalisengruppeGesteuertTri->isChecked()) {
        ui->pb18->setIcon(QIcon(":/icons/assets/qgraphics/BalisengruppeGesteuertTri.svg"));
    } else {
         ui->pb18->setIcon(QIcon(":/icons/assets/qgraphics/BalisengruppeUngesteuertTri.svg"));
    }
}


void QGraphicsSymbolContainer::on_pushButton_Bereichskennungswechsel_clicked()
{
        if(BereichskennungswechselCustomiseBtn){
            BereichskennungswechselCustomiseBtn = false;
            ui->frame_Bereichskennungswechsel->hide();
        }else{
            BereichskennungswechselCustomiseBtn = true;
            ui->frame_Bereichskennungswechsel->show();
        }
}


void QGraphicsSymbolContainer::on_checkBox_Bereichskennungswechsel_clicked()
{
    if (ui->checkBox_Bereichskennungswechsel->isChecked()) {
        ui->pb19->setIcon(QIcon(":/icons/assets/qgraphics/Bereichskennungswechselortungsneutral.svg"));
    } else {
         ui->pb19->setIcon(QIcon(":/icons/assets/qgraphics/Bereichskennungswechsel.svg"));
    }
}


void QGraphicsSymbolContainer::on_pushButton_BalisengruppeGesteuert_clicked()
{

    if(balisengruppeGesteuertCustomiseBtn){
        balisengruppeGesteuertCustomiseBtn = false;
        ui->frame_BalisengruppeGesteuert->hide();
    }else{
        balisengruppeGesteuertCustomiseBtn = true;
        ui->frame_BalisengruppeGesteuert->show();
    }
}


void QGraphicsSymbolContainer::on_checkBox_BalisengruppeGesteuert_clicked()
{
    if (ui->checkBox_BalisengruppeGesteuert->isChecked()) {
        ui->pb17->setIcon(QIcon(":/icons/assets/qgraphics/BalisengruppeGesteuert.svg"));
    } else {
         ui->pb17->setIcon(QIcon(":/icons/assets/qgraphics/BalisengruppeunGesteuert.svg"));
    }
}


void QGraphicsSymbolContainer::on_pushButton_EinzelbaliseUngesteuert_clicked()
{
    if(EinzelbaliseUngesteuertCustomiseBtn){
        EinzelbaliseUngesteuertCustomiseBtn = false;
        ui->frame_EinzelbaliseUngesteuert->hide();
    }else{
        EinzelbaliseUngesteuertCustomiseBtn = true;
        ui->frame_EinzelbaliseUngesteuert->show();
    }
}


void QGraphicsSymbolContainer::on_checkBox_EinzelbaliseUngesteuert_clicked()
{
    if (ui->checkBox_EinzelbaliseUngesteuert->isChecked()) {
        ui->pb32->setIcon(QIcon(":/icons/assets/qgraphics/EinzelbaliseUngesteuert.svg"));
    } else {
         ui->pb32->setIcon(QIcon(":/icons/assets/qgraphics/EinzelbaliseGesteuert.svg"));
    }
}


void QGraphicsSymbolContainer::on_pushButton_EinzelbaliseRechts_clicked()
{
    if(EinzelbaliseRechtsCustomiseBtn){
        EinzelbaliseRechtsCustomiseBtn = false;
        ui->frame_EinzelbaliseRechts->hide();
    }else{
        EinzelbaliseRechtsCustomiseBtn = true;
        ui->frame_EinzelbaliseRechts->show();
    }
}


void QGraphicsSymbolContainer::on_checkBox_EinzelbaliseRechts_clicked()
{
    if (ui->checkBox_EinzelbaliseRechts->isChecked()) {
        ui->pb33->setIcon(QIcon(":/icons/assets/qgraphics/EinzelbaliseRechts.svg"));
    } else {
         ui->pb33->setIcon(QIcon(":/icons/assets/qgraphics/EinzelbaliseLinks.svg"));
    }
}


void QGraphicsSymbolContainer::on_pushButton_ETCSstopTafelTwo_clicked()
{
    if(ETCSstopTafelTwoCustomiseBtn){
        ETCSstopTafelTwoCustomiseBtn = false;
        ui->frame_ETCSstopTafelTwo->hide();
    }else{
        ETCSstopTafelTwoCustomiseBtn = true;
        ui->frame_ETCSstopTafelTwo->show();
    }
}


void QGraphicsSymbolContainer::on_checkBox_ETCSstopTafelTwo_clicked()
{
    if (ui->checkBox_ETCSstopTafelTwo->isChecked()) {
        ui->pb37->setIcon(QIcon(":/icons/assets/qgraphics/ETCSstopTafelTwo.svg"));
    } else {
         ui->pb37->setIcon(QIcon(":/icons/assets/qgraphics/ETCSstopTafelOne.svg"));
    }
}


void QGraphicsSymbolContainer::on_pushButton_FahrstrassensymboleReise_clicked()
{
    if(FahrstrassensymboleReiseCustomiseBtn){
        FahrstrassensymboleReiseCustomiseBtn = false;
        ui->frame_FahrstrassensymboleReise->hide();
    }else{
        FahrstrassensymboleReiseCustomiseBtn = true;
        ui->frame_FahrstrassensymboleReise->show();
    }
}


void QGraphicsSymbolContainer::on_checkBox_FahrstrassensymboleRangierfahrten_clicked()
{
    ui->checkBox_FahrstrassensymboleGuterzuge->setChecked(false);
    ui->checkBox_FahrstrassensymboleDurchGuterzuge->setChecked(false);
    ui->checkBox_FahrstrassensymboleDurchfahrten->setChecked(false);

    if (ui->checkBox_FahrstrassensymboleRangierfahrten->isChecked()) {
        ui->pb_FahrstrassensymboleReise->setIcon(QIcon(":/icons/assets/qgraphics/FahrstrassensymboleRangierfahrten.svg"));
    } else {
         ui->pb_FahrstrassensymboleReise->setIcon(QIcon(":/icons/assets/qgraphics/FahrstrassensymboleReise.svg"));
    }
}


void QGraphicsSymbolContainer::on_checkBox_FahrstrassensymboleGuterzuge_clicked()
{
    ui->checkBox_FahrstrassensymboleRangierfahrten->setChecked(false);
    ui->checkBox_FahrstrassensymboleDurchGuterzuge->setChecked(false);
    ui->checkBox_FahrstrassensymboleDurchfahrten->setChecked(false);

    if (ui->checkBox_FahrstrassensymboleGuterzuge->isChecked()) {
        ui->pb_FahrstrassensymboleReise->setIcon(QIcon(":/icons/assets/qgraphics/FahrstrassensymboleGuterzuge.svg"));
    } else {
         ui->pb_FahrstrassensymboleReise->setIcon(QIcon(":/icons/assets/qgraphics/FahrstrassensymboleReise.svg"));
    }
}


void QGraphicsSymbolContainer::on_checkBox_FahrstrassensymboleDurchGuterzuge_clicked()
{
    ui->checkBox_FahrstrassensymboleGuterzuge->setChecked(false);
    ui->checkBox_FahrstrassensymboleRangierfahrten->setChecked(false);
    ui->checkBox_FahrstrassensymboleDurchfahrten->setChecked(false);
    if (ui->checkBox_FahrstrassensymboleDurchGuterzuge->isChecked()) {
        ui->pb_FahrstrassensymboleReise->setIcon(QIcon(":/icons/assets/qgraphics/FahrstrassensymboleDurchGuterzuge.svg"));
    } else {
         ui->pb_FahrstrassensymboleReise->setIcon(QIcon(":/icons/assets/qgraphics/FahrstrassensymboleReise.svg"));
    }
}


void QGraphicsSymbolContainer::on_checkBox_FahrstrassensymboleDurchfahrten_clicked()
{
    ui->checkBox_FahrstrassensymboleGuterzuge->setChecked(false);
    ui->checkBox_FahrstrassensymboleDurchGuterzuge->setChecked(false);
    ui->checkBox_FahrstrassensymboleRangierfahrten->setChecked(false);

    if (ui->checkBox_FahrstrassensymboleDurchfahrten->isChecked()) {
        ui->pb_FahrstrassensymboleReise->setIcon(QIcon(":/icons/assets/qgraphics/FahrstrassensymboleDurchfahrten.svg"));
    } else {
         ui->pb_FahrstrassensymboleReise->setIcon(QIcon(":/icons/assets/qgraphics/FahrstrassensymboleReise.svg"));
    }
}


void QGraphicsSymbolContainer::on_pushButton_Festprellbock_clicked()
{
    if(FestprellbockCustomiseBtn){
        FestprellbockCustomiseBtn = false;
        ui->frame_Festprellbock->hide();
    }else{
        FestprellbockCustomiseBtn = true;
        ui->frame_Festprellbock->show();
    }
}


void QGraphicsSymbolContainer::on_checkBox_Bremsprellbock_clicked()
{
    ui->checkBox_Abklappbarer->setChecked(false);
    ui->checkBox_Anfangsschleife->setChecked(false);

    if (ui->checkBox_Bremsprellbock->isChecked()) {
        ui->pb_Festprellbock->setIcon(QIcon(":/icons/assets/qgraphics/Bremsprellbock.svg"));
    } else {
         ui->pb_Festprellbock->setIcon(QIcon(":/icons/assets/qgraphics/Festprellbock.svg"));
    }
}


void QGraphicsSymbolContainer::on_checkBox_Abklappbarer_clicked()
{
    ui->checkBox_Bremsprellbock->setChecked(false);
    ui->checkBox_Anfangsschleife->setChecked(false);

    if (ui->checkBox_Abklappbarer->isChecked()) {
        ui->pb_Festprellbock->setIcon(QIcon(":/icons/assets/qgraphics/Abklappbarer.svg"));
    } else {
         ui->pb_Festprellbock->setIcon(QIcon(":/icons/assets/qgraphics/Festprellbock.svg"));
    }
}


void QGraphicsSymbolContainer::on_checkBox_Anfangsschleife_clicked()
{
    ui->checkBox_Abklappbarer->setChecked(false);
    ui->checkBox_Bremsprellbock->setChecked(false);

    if (ui->checkBox_Anfangsschleife->isChecked()) {
        ui->pb_Festprellbock->setIcon(QIcon(":/icons/assets/qgraphics/Anfangsschleife.svg"));
    } else {
         ui->pb_Festprellbock->setIcon(QIcon(":/icons/assets/qgraphics/Festprellbock.svg"));
    }
}


void QGraphicsSymbolContainer::on_pushButton_Fruhhaltanzeiger_clicked()
{
    if(FruhhaltanzeigerCustomiseBtn){
        FruhhaltanzeigerCustomiseBtn = false;
        ui->frame_Fruhhaltanzeiger->hide();
    }else{
        FruhhaltanzeigerCustomiseBtn = true;
        ui->frame_Fruhhaltanzeiger->show();
    }
}






void QGraphicsSymbolContainer::on_checkBox_GegengleisanzeigerHauptsignalschirm_clicked()
{
    ui->checkBox_Geschwindigkeitsanzeiger->setChecked(false);
    ui->checkBox_hauptRichtungsanzeiger->setChecked(false);
    ui->checkBox_HauptGegengleisanzeiger->setChecked(false);


    if (ui->checkBox_GegengleisanzeigerHauptsignalschirm->isChecked()) {
        ui->pb_Fruhhaltanzeiger->setIcon(QIcon(":/icons/assets/qgraphics/GegengleisanzeigerHauptsignalschirm.svg"));
    } else {
         ui->pb_Fruhhaltanzeiger->setIcon(QIcon(":/icons/assets/qgraphics/Fruhhaltanzeiger.svg"));
    }

}


void QGraphicsSymbolContainer::on_checkBox_Geschwindigkeitsanzeiger_clicked()
{
    ui->checkBox_GegengleisanzeigerHauptsignalschirm->setChecked(false);
    ui->checkBox_hauptRichtungsanzeiger->setChecked(false);
    ui->checkBox_HauptGegengleisanzeiger->setChecked(false);


    if (ui->checkBox_Geschwindigkeitsanzeiger->isChecked()) {
        ui->pb_Fruhhaltanzeiger->setIcon(QIcon(":/icons/assets/qgraphics/Geschwindigkeitsanzeiger.svg"));
    } else {
         ui->pb_Fruhhaltanzeiger->setIcon(QIcon(":/icons/assets/qgraphics/Fruhhaltanzeiger.svg"));
    }
}


void QGraphicsSymbolContainer::on_checkBox_hauptRichtungsanzeiger_clicked()
{
    ui->checkBox_GegengleisanzeigerHauptsignalschirm->setChecked(false);
    ui->checkBox_Geschwindigkeitsanzeiger->setChecked(false);
    ui->checkBox_HauptGegengleisanzeiger->setChecked(false);


    if (ui->checkBox_hauptRichtungsanzeiger->isChecked()) {
        ui->pb_Fruhhaltanzeiger->setIcon(QIcon(":/icons/assets/qgraphics/hauptRichtungsanzeiger.svg"));
    } else {
         ui->pb_Fruhhaltanzeiger->setIcon(QIcon(":/icons/assets/qgraphics/Fruhhaltanzeiger.svg"));
    }
}


void QGraphicsSymbolContainer::on_checkBox_HauptGegengleisanzeiger_clicked()
{
    ui->checkBox_GegengleisanzeigerHauptsignalschirm->setChecked(false);
    ui->checkBox_Geschwindigkeitsanzeiger->setChecked(false);
    ui->checkBox_hauptRichtungsanzeiger->setChecked(false);


    if (ui->checkBox_HauptGegengleisanzeiger->isChecked()) {
        ui->pb_Fruhhaltanzeiger->setIcon(QIcon(":/icons/assets/qgraphics/HauptGegengleisanzeiger.svg"));
    } else {
         ui->pb_Fruhhaltanzeiger->setIcon(QIcon(":/icons/assets/qgraphics/Fruhhaltanzeiger.svg"));
    }
}


void QGraphicsSymbolContainer::on_pushButton_GegengleisanzeigerLichtsignal_clicked()
{
    if(GegengleisanzeigerLichtsignalCustomiseBtn){
        GegengleisanzeigerLichtsignalCustomiseBtn = false;
        ui->frame_GegengleisanzeigerLichtsignal->hide();
    }else{
        GegengleisanzeigerLichtsignalCustomiseBtn = true;
        ui->frame_GegengleisanzeigerLichtsignal->show();
    }
}


void QGraphicsSymbolContainer::on_checkBox_GegengleisanzeigerLichtsignal_clicked()
{

    if (ui->checkBox_GegengleisanzeigerLichtsignal->isChecked()) {
        ui->pb_GegengleisanzeigerLichtsignal->setIcon(QIcon(":/icons/assets/qgraphics/Gegengleisanzeiger.svg"));
    } else {
         ui->pb_GegengleisanzeigerLichtsignal->setIcon(QIcon(":/icons/assets/qgraphics/GegengleisanzeigerLichtsignal.svg"));
    }
}


void QGraphicsSymbolContainer::on_pushButton_Geschwindigkeits_clicked()
{
    if(GeschwindigkeitsCustomiseBtn){
        GeschwindigkeitsCustomiseBtn = false;
        ui->frame_Geschwindigkeits->hide();
    }else{
        GeschwindigkeitsCustomiseBtn = true;
        ui->frame_Geschwindigkeits->show();
    }
}


void QGraphicsSymbolContainer::on_checkBox_Geschwindigkeits_clicked()
{
    if (ui->checkBox_Geschwindigkeits->isChecked()) {
        ui->pb_Geschwindigkeits->setIcon(QIcon(":/icons/assets/qgraphics/GeschwindigkeirRichtungspfeil.svg"));
    } else {
         ui->pb_Geschwindigkeits->setIcon(QIcon(":/icons/assets/qgraphics/Geschwindigkeits.svg"));
    }
}


void QGraphicsSymbolContainer::on_pushButton_GeshLichtsignal_clicked()
{
    if(GeshLichtsignalCustomiseBtn){
        GeshLichtsignalCustomiseBtn = false;
        ui->frame_GeshLichtsignal->hide();
    }else{
        GeshLichtsignalCustomiseBtn = true;
        ui->frame_GeshLichtsignal->show();
    }
}


void QGraphicsSymbolContainer::on_checkBox_GeshLichtsignal_clicked()
{
    if (ui->checkBox_GeshLichtsignal->isChecked()) {
        ui->pb_GeshLichtsignal->setIcon(QIcon(":/icons/assets/qgraphics/Richtungsvoranzeiger.svg"));
    } else {
         ui->pb_GeshLichtsignal->setIcon(QIcon(":/icons/assets/qgraphics/GeshLichtsignal.svg"));
    }

}


void QGraphicsSymbolContainer::on_pushButton_gesteuertRechts_clicked()
{
    if(gesteuertRechtsCustomiseBtn){
        gesteuertRechtsCustomiseBtn = false;
        ui->frame_gesteuertRechts->hide();
    }else{
        gesteuertRechtsCustomiseBtn = true;
        ui->frame_gesteuertRechts->show();
    }
}


void QGraphicsSymbolContainer::on_checkBox_gesteuertRechts_clicked()
{
    if (ui->checkBox_gesteuertRechts->isChecked()) {
        ui->pb_gesteuertRechts->setIcon(QIcon(":/icons/assets/qgraphics/gesteuertLinks.svg"));
    } else {
        ui->pb_gesteuertRechts->setIcon(QIcon(":/icons/assets/qgraphics/gesteuertRechts.svg"));
    }
}


void QGraphicsSymbolContainer::on_pushButton_hauptTunneln_clicked()
{
    if(hauptTunnelnCustomiseBtn){
        hauptTunnelnCustomiseBtn = false;
        ui->frame_hauptTunneln->hide();
    }else{
        hauptTunnelnCustomiseBtn = true;
        ui->frame_hauptTunneln->show();
    }
}


void QGraphicsSymbolContainer::on_checkBox_hauptTunneln_clicked()
{
    if (ui->checkBox_hauptTunneln->isChecked()) {
        ui->pb_hauptTunneln->setIcon(QIcon(":/icons/assets/qgraphics/HauptBahnsteigdach.svg"));
    } else {
        ui->pb_hauptTunneln->setIcon(QIcon(":/icons/assets/qgraphics/hauptTunneln.svg"));
    }
}


void QGraphicsSymbolContainer::on_pushButton_Kabelverteiler_clicked()
{
    if(KabelverteilerCustomiseBtn){
        KabelverteilerCustomiseBtn = false;
        ui->frame_Kabelverteiler->hide();
    }else{
        KabelverteilerCustomiseBtn = true;
        ui->frame_Kabelverteiler->show();
    }
}


void QGraphicsSymbolContainer::on_checkBox_Kabelverteiler_clicked()
{
    if (ui->checkBox_Kabelverteiler->isChecked()) {
        ui->pb_Kabelverteiler->setIcon(QIcon(":/icons/assets/qgraphics/Kilometerangabe.svg"));
    } else {
        ui->pb_Kabelverteiler->setIcon(QIcon(":/icons/assets/qgraphics/Kabelverteiler.svg"));
    }
}


void QGraphicsSymbolContainer::on_pushButton_mehraZugbedient_clicked()
{
    if(mehraCustomiseBtn){
        mehraCustomiseBtn = false;
        ui->frame_mehraZugbedient->hide();
    }else{
        mehraCustomiseBtn = true;
        ui->frame_mehraZugbedient->show();
    }
}

void QGraphicsSymbolContainer::on_checkBox_mehraArrow_clicked()
{
    if(ui->checkBox_mehraArrow->isChecked()){
        ui->pb_mehra->setIcon(QIcon(":/icons/assets/qgraphics/mehraZugbedientArrow.svg"));
        if(ui->checkBox_mehraZugoderStellwerksbedient->isChecked()){
            ui->pb_mehra->setIcon(QIcon(":/icons/assets/qgraphics/mehraZugoderStellwerksbedientArrow.svg"));

        }if (ui->checkBox_mehrasStellwerksbedient->isChecked()) {
            ui->pb_mehra->setIcon(QIcon(":/icons/assets/qgraphics/mehrasStellwerksbedientArrow.svg"));
        }
        if (ui->checkBox_mehraausanderemStellbereich->isChecked()) {
            ui->pb_mehra->setIcon(QIcon(":/icons/assets/qgraphics/mehraausanderemStellbereichArrow.svg"));
        }
    }else{
        ui->pb_mehra->setIcon(QIcon(":/icons/assets/qgraphics/mehraZugbedient.svg"));
        if(ui->checkBox_mehraZugoderStellwerksbedient->isChecked()){
            ui->pb_mehra->setIcon(QIcon(":/icons/assets/qgraphics/mehraZugoderStellwerksbedient.svg"));

        }if (ui->checkBox_mehrasStellwerksbedient->isChecked()) {
            ui->pb_mehra->setIcon(QIcon(":/icons/assets/qgraphics/mehrasStellwerksbedient.svg"));
        }
        if (ui->checkBox_mehraausanderemStellbereich->isChecked()) {
            ui->pb_mehra->setIcon(QIcon(":/icons/assets/qgraphics/mehraausanderemStellbereich.svg"));
        }
    }

}


void QGraphicsSymbolContainer::on_checkBox_mehraZugoderStellwerksbedient_clicked()
{
    ui->checkBox_mehrasStellwerksbedient->setChecked(false);
    ui->checkBox_mehraausanderemStellbereich->setChecked(false);
    ui->checkBox_mehraArrow->setChecked(false);

    if (ui->checkBox_mehraZugoderStellwerksbedient->isChecked()) {
        ui->pb_mehra->setIcon(QIcon(":/icons/assets/qgraphics/mehraZugoderStellwerksbedient.svg"));
    } else {
        ui->pb_mehra->setIcon(QIcon(":/icons/assets/qgraphics/mehraZugbedient.svg"));
    }
}


void QGraphicsSymbolContainer::on_checkBox_mehrasStellwerksbedient_clicked()
{
    ui->checkBox_mehraZugoderStellwerksbedient->setChecked(false);
    ui->checkBox_mehraausanderemStellbereich->setChecked(false);
    ui->checkBox_mehraArrow->setChecked(false);

    if (ui->checkBox_mehrasStellwerksbedient->isChecked()) {
        ui->pb_mehra->setIcon(QIcon(":/icons/assets/qgraphics/mehrasStellwerksbedient.svg"));
    } else {
        ui->pb_mehra->setIcon(QIcon(":/icons/assets/qgraphics/mehraZugbedient.svg"));
    }
}


void QGraphicsSymbolContainer::on_checkBox_mehraausanderemStellbereich_clicked()
{
    ui->checkBox_mehrasStellwerksbedient->setChecked(false);
    ui->checkBox_mehraZugoderStellwerksbedient->setChecked(false);
    ui->checkBox_mehraArrow->setChecked(false);

    if (ui->checkBox_mehraausanderemStellbereich->isChecked()) {
        ui->pb_mehra->setIcon(QIcon(":/icons/assets/qgraphics/mehraausanderemStellbereich.svg"));
    } else {
        ui->pb_mehra->setIcon(QIcon(":/icons/assets/qgraphics/mehraZugbedient.svg"));
    }
}


void QGraphicsSymbolContainer::on_pushButton_MTafel_clicked()
{
    if(MTafelCustomiseBtn){
        MTafelCustomiseBtn = false;
        ui->frame_MTafel->hide();
    }else{
        MTafelCustomiseBtn = true;
        ui->frame_MTafel->show();
    }
}


void QGraphicsSymbolContainer::on_checkBox_Richtungsanzeiger_clicked()
{
    ui->checkBox_Stumpfgleis->setChecked(false);

    if (ui->checkBox_Richtungsanzeiger->isChecked()) {
        ui->pb_MTafel->setIcon(QIcon(":/icons/assets/qgraphics/Richtungsanzeiger.svg"));
    } else {
        ui->pb_MTafel->setIcon(QIcon(":/icons/assets/qgraphics/MTafel.svg"));
    }
}


void QGraphicsSymbolContainer::on_checkBox_Stumpfgleis_clicked()
{
    ui->checkBox_Richtungsanzeiger->setChecked(false);

    if (ui->checkBox_Stumpfgleis->isChecked()) {
        ui->pb_MTafel->setIcon(QIcon(":/icons/assets/qgraphics/Stumpfgleis.svg"));
    } else {
        ui->pb_MTafel->setIcon(QIcon(":/icons/assets/qgraphics/MTafel.svg"));
    }

}


void QGraphicsSymbolContainer::on_pushButton_reflektierenden_clicked()
{
    if(reflektierendenCustomiseBtn){
        reflektierendenCustomiseBtn = false;
        ui->frame_reflektierenden->hide();
    }else{
        reflektierendenCustomiseBtn = true;
        ui->frame_reflektierenden->show();
    }
}


void QGraphicsSymbolContainer::on_checkBox_reflektierenden_clicked()
{
    if (ui->checkBox_reflektierenden->isChecked()) {
        ui->pb_reflektierenden->setIcon(QIcon(":/icons/assets/qgraphics/aktivengelben.svg"));
    } else {
        ui->pb_reflektierenden->setIcon(QIcon(":/icons/assets/qgraphics/reflektierenden.svg"));
    }
}


void QGraphicsSymbolContainer::on_pushButton_Speisegerat_clicked()
{

            if(SpeisegeratCustomiseBtn){
                SpeisegeratCustomiseBtn = false;
                ui->frame_Speisegerat->hide();
            }else{
                SpeisegeratCustomiseBtn = true;
                ui->frame_Speisegerat->show();
            }
}


void QGraphicsSymbolContainer::on_checkBox_Signalhaltmelder_clicked()
{
    ui->checkBox_Sperrsignal->setChecked(false);
    ui->checkBox_SperrsignalKennlicht->setChecked(false);

    if (ui->checkBox_Signalhaltmelder->isChecked()) {
        ui->pb_Speisegerat->setIcon(QIcon(":/icons/assets/qgraphics/Signalhaltmelder.svg"));
    } else {
        ui->pb_Speisegerat->setIcon(QIcon(":/icons/assets/qgraphics/Speisegerat.svg"));
    }
     ui->pb_Speisegerat->setIconSize(QSize(50,20));
}


void QGraphicsSymbolContainer::on_checkBox_Sperrsignal_clicked()
{
    ui->checkBox_Signalhaltmelder->setChecked(false);
    ui->checkBox_SperrsignalKennlicht->setChecked(false);

    if (ui->checkBox_Sperrsignal->isChecked()) {
        ui->pb_Speisegerat->setIcon(QIcon(":/icons/assets/qgraphics/Sperrsignal.svg"));
    } else {
        ui->pb_Speisegerat->setIcon(QIcon(":/icons/assets/qgraphics/Speisegerat.svg"));
    }
     ui->pb_Speisegerat->setIconSize(QSize(50,20));
}


void QGraphicsSymbolContainer::on_checkBox_SperrsignalKennlicht_clicked()
{
    ui->checkBox_Sperrsignal->setChecked(false);
    ui->checkBox_Signalhaltmelder->setChecked(false);

    if (ui->checkBox_SperrsignalKennlicht->isChecked()) {
        ui->pb_Speisegerat->setIcon(QIcon(":/icons/assets/qgraphics/SperrsignalKennlicht.svg"));
    } else {
        ui->pb_Speisegerat->setIcon(QIcon(":/icons/assets/qgraphics/Speisegerat.svg"));
    }
     ui->pb_Speisegerat->setIconSize(QSize(50,20));

}


void QGraphicsSymbolContainer::on_pushButton_VorsignalbakenFive_clicked()
{
    if(VorsignalbakenFiveCustomiseBtn){
        VorsignalbakenFiveCustomiseBtn = false;
        ui->frame_VorsignalbakenFive->hide();
    }else{
        VorsignalbakenFiveCustomiseBtn = true;
        ui->frame_VorsignalbakenFive->show();
    }
}


void QGraphicsSymbolContainer::on_checkBox_VorsignalbakenOne_clicked()
{
    ui->checkBox_VorsignalbakenTwo->setChecked(false);
    ui->checkBox_VorsignalbakenThree->setChecked(false);
    ui->checkBox_VorsignalbakenFour->setChecked(false);

    if (ui->checkBox_VorsignalbakenOne->isChecked()) {
        ui->pb_VorsignalbakenFive->setIcon(QIcon(":/icons/assets/qgraphics/VorsignalbakenOne.svg"));
    } else {
        ui->pb_VorsignalbakenFive->setIcon(QIcon(":/icons/assets/qgraphics/VorsignalbakenFive.svg"));
    }

}


void QGraphicsSymbolContainer::on_checkBox_VorsignalbakenTwo_clicked()
{
    ui->checkBox_VorsignalbakenOne->setChecked(false);
    ui->checkBox_VorsignalbakenThree->setChecked(false);
    ui->checkBox_VorsignalbakenFour->setChecked(false);

    if (ui->checkBox_VorsignalbakenTwo->isChecked()) {
        ui->pb_VorsignalbakenFive->setIcon(QIcon(":/icons/assets/qgraphics/VorsignalbakenTwo.svg"));
    } else {
        ui->pb_VorsignalbakenFive->setIcon(QIcon(":/icons/assets/qgraphics/VorsignalbakenFive.svg"));
    }
}


void QGraphicsSymbolContainer::on_checkBox_VorsignalbakenThree_clicked()
{
    ui->checkBox_VorsignalbakenTwo->setChecked(false);
    ui->checkBox_VorsignalbakenOne->setChecked(false);
    ui->checkBox_VorsignalbakenFour->setChecked(false);

    if (ui->checkBox_VorsignalbakenThree->isChecked()) {
        ui->pb_VorsignalbakenFive->setIcon(QIcon(":/icons/assets/qgraphics/VorsignalbakenThree.svg"));
    } else {
        ui->pb_VorsignalbakenFive->setIcon(QIcon(":/icons/assets/qgraphics/VorsignalbakenFive.svg"));
    }
}


void QGraphicsSymbolContainer::on_checkBox_VorsignalbakenFour_clicked()
{
    ui->checkBox_VorsignalbakenTwo->setChecked(false);
    ui->checkBox_VorsignalbakenThree->setChecked(false);
    ui->checkBox_VorsignalbakenOne->setChecked(false);

    if (ui->checkBox_VorsignalbakenFour->isChecked()) {
        ui->pb_VorsignalbakenFive->setIcon(QIcon(":/icons/assets/qgraphics/VorsignalbakenFour.svg"));
    } else {
        ui->pb_VorsignalbakenFive->setIcon(QIcon(":/icons/assets/qgraphics/VorsignalbakenFive.svg"));
    }
}


void QGraphicsSymbolContainer::on_pushButton_Vorsignaltafel_clicked()
{
    if(KabelschrankCustomiseBtn){
        KabelschrankCustomiseBtn = false;
        ui->frame_Kabelschrank->hide();
    }else{
        KabelschrankCustomiseBtn = true;
        ui->frame_Kabelschrank->show();
    }
}


void QGraphicsSymbolContainer::on_checkBox_Kabelschrank_clicked()
{



            if (ui->checkBox_Kabelschrank->isChecked()) {
                ui->pb_Kabelschrank->setIcon(QIcon(":/icons/assets/qgraphics/Kabelschrank.svg"));
            } else {
                ui->pb_Kabelschrank->setIcon(QIcon(":/icons/assets/qgraphics/Vorsignaltafel.svg"));
            }
}


void QGraphicsSymbolContainer::on_pushButton_WeitereOne_clicked()
{
    if(WeitereOneCustomiseBtn){
        WeitereOneCustomiseBtn = false;
        ui->frame_WeitereOne->hide();
    }else{
        WeitereOneCustomiseBtn = true;
        ui->frame_WeitereOne->show();
    }
}


void QGraphicsSymbolContainer::on_checkBox_WeitereTwo_clicked()
{
    ui->checkBox_WeitereTwo_2->setChecked(false);
    if (ui->checkBox_WeitereTwo->isChecked()) {
        ui->pb_WeitereOne->setIcon(QIcon(":/icons/assets/qgraphics/WeitereTwo.svg"));
    } else {
        ui->pb_WeitereOne->setIcon(QIcon(":/icons/assets/qgraphics/WeitereOne.svg"));
    }
}


void QGraphicsSymbolContainer::on_checkBox_WeitereTwo_2_clicked()
{
    ui->checkBox_WeitereTwo->setChecked(false);
    if (ui->checkBox_WeitereTwo_2->isChecked()) {
        ui->pb_WeitereOne->setIcon(QIcon(":/icons/assets/qgraphics/WeitereThree.svg"));
    } else {
        ui->pb_WeitereOne->setIcon(QIcon(":/icons/assets/qgraphics/WeitereOne.svg"));
    }
}


void QGraphicsSymbolContainer::on_pushButton_zweiAktiven_clicked()
{
    if(zweiAktivenCustomiseBtn){
        zweiAktivenCustomiseBtn = false;
        ui->frame_zweiAktiven->hide();
    }else{
        zweiAktivenCustomiseBtn = true;
        ui->frame_zweiAktiven->show();
    }
}


void QGraphicsSymbolContainer::on_checkBox_2_clicked()
{

            if (ui->checkBox_2->isChecked()) {
                ui->pb_zweiAktiven->setIcon(QIcon(":/icons/assets/qgraphics/zweiReflektierenden.svg"));
            } else {
                ui->pb_zweiAktiven->setIcon(QIcon(":/icons/assets/qgraphics/zweiAktiven.svg"));
            }
}




//on click add symbol

void QGraphicsSymbolContainer::on_pb_FahrstrassensymboleReise_clicked()
{
    if(ui->checkBox_FahrstrassensymboleDurchfahrten->isChecked()){
        tracks->addSymbol("FahrstrassensymboleDurchfahrten");
    } else if(ui->checkBox_FahrstrassensymboleGuterzuge->isChecked()){
        tracks->addSymbol("FahrstrassensymboleGuterzuge");
    }else if(ui->checkBox_FahrstrassensymboleRangierfahrten->isChecked()){
        tracks->addSymbol("FahrstrassensymboleRangierfahrten");
    }else if(ui->checkBox_FahrstrassensymboleDurchGuterzuge->isChecked()){
        tracks->addSymbol("FahrstrassensymboleDurchGuterzuge");
    }else{
        tracks->addSymbol("FahrstrassensymboleReise");
    }
}


void QGraphicsSymbolContainer::on_pb_Fahrtanzeiger_clicked()
{
     tracks->addSymbol("Fahrtanzeiger");
}


void QGraphicsSymbolContainer::on_pb_Fahrzeugsensor_clicked()
{
    tracks->addSymbol("Fahrzeugsensor");
}


void QGraphicsSymbolContainer::on_pb_Festprellbock_clicked()
{
    if(ui->checkBox_Bremsprellbock->isChecked()){
        tracks->addSymbol("Bremsprellbock");
    } else if(ui->checkBox_Abklappbarer->isChecked()){
        tracks->addSymbol("Abklappbarer");
    }else if(ui->checkBox_Anfangsschleife->isChecked()){
        tracks->addSymbol("Anfangsschleife");
    }else{
        tracks->addSymbol("Festprellbock");
    }
}


void QGraphicsSymbolContainer::on_pb_Flachstellenortungsanlage_clicked()
{
    tracks->addSymbol("Flachstellenortungsanlage");
}


void QGraphicsSymbolContainer::on_pb_Fruhhaltanzeiger_clicked()
{
    if(ui->checkBox_GegengleisanzeigerHauptsignalschirm->isChecked()){
        tracks->addSymbol("GegengleisanzeigerHauptsignalschirm");
    }else if(ui->checkBox_Geschwindigkeitsanzeiger->isChecked()){
        tracks->addSymbol("Geschwindigkeitsanzeiger");
    }else if(ui->checkBox_hauptRichtungsanzeiger->isChecked()){
        tracks->addSymbol("hauptRichtungsanzeiger");
    }else if(ui->checkBox_HauptGegengleisanzeiger->isChecked()){
        tracks->addSymbol("HauptGegengleisanzeiger");
    }else{
        tracks->addSymbol("Fruhhaltanzeiger");
    }
}


void QGraphicsSymbolContainer::on_pb_Funkanruckmelder_clicked()
{
    tracks->addSymbol("Funkanruckmelder");
}


void QGraphicsSymbolContainer::on_pb_FusgangermaskeundAndreaskreuz_clicked()
{
    tracks->addSymbol("FusgangermaskeundAndreaskreuz");
}


void QGraphicsSymbolContainer::on_pb_GegengleisanzeigerLichtsignal_clicked()
{
    if(ui->checkBox_GegengleisanzeigerLichtsignal->isChecked()){
        tracks->addSymbol("Gegengleisanzeiger");
    }else{
        tracks->addSymbol("GegengleisanzeigerLichtsignal");
    }
}


void QGraphicsSymbolContainer::on_pb_Geschwindigkeits_clicked()
{
    if(ui->checkBox_Geschwindigkeits->isChecked()){
        tracks->addSymbol("GeschwindigkeirRichtungspfeil");
    }else{
        tracks->addSymbol("Geschwindigkeits");
    }
}


void QGraphicsSymbolContainer::on_pushButton_Geschwindigkeitssignal_clicked()
{
    tracks->addSymbol("Geschwindigkeitssignal");
}


void QGraphicsSymbolContainer::on_pushButton_Geschwindigkeitswechsel_clicked()
{
    tracks->addSymbol("Geschwindigkeitswechsel");
}


void QGraphicsSymbolContainer::on_pb_GeshLichtsignal_clicked()
{
    if(ui->checkBox_GeshLichtsignal->isChecked()){
        tracks->addSymbol("Richtungsvoranzeiger");
    }else{
        tracks->addSymbol("GeshLichtsignal");
    }
}


void QGraphicsSymbolContainer::on_pb_gesteuertRechts_clicked()
{
    if(ui->checkBox_gesteuertRechts->isChecked()){
        tracks->addSymbol("gesteuertLinks");
    }else{
        tracks->addSymbol("gesteuertRechts");
    }
}


void QGraphicsSymbolContainer::on_pushButton_Gleislangen_clicked()
{
    tracks->addSymbol("Gleislangen");
}


void QGraphicsSymbolContainer::on_pushButton_27_clicked()
{
    tracks->addSymbol("HaltetafelmitZuord");
}


void QGraphicsSymbolContainer::on_pushButton_hauptGeschwindigkeitsanzeiger_clicked()
{
    tracks->addSymbol("hauptGeschwindigkeitsanzeiger");
}


void QGraphicsSymbolContainer::on_pushButton_hauptSignalbegriffe_clicked()
{
    tracks->addSymbol("hauptSignalbegriffe");
}


void QGraphicsSymbolContainer::on_pushButton_HauptsignalIdentificationFour_clicked()
{
    tracks->addSymbol("HauptsignalIdentificationFour");
}


void QGraphicsSymbolContainer::on_pushButton_Haltepunkttafel_clicked()
{
    tracks->addSymbol("Haltepunkttafel");
}


void QGraphicsSymbolContainer::on_pb_hauptTunneln_clicked()
{
    if(ui->checkBox_hauptTunneln->isChecked()){
        tracks->addSymbol("HauptBahnsteigdach");
    }else{
        tracks->addSymbol("hauptTunneln");
    }
}


void QGraphicsSymbolContainer::on_pushButton_Heisslauferortungsanlage_clicked()
{
     tracks->addSymbol("Heisslauferortungsanlage");
}


void QGraphicsSymbolContainer::on_pushButton_Hektometerangabe_clicked()
{
     tracks->addSymbol("Hektometerangabe");
}


void QGraphicsSymbolContainer::on_pushButton_Kabelformstein_clicked()
{
     tracks->addSymbol("Kabelformstein");
}


void QGraphicsSymbolContainer::on_pushButton_Kabelmuffe_clicked()
{
     tracks->addSymbol("Kabelmuffe");
}


void QGraphicsSymbolContainer::on_pushButton_Kabelschacht_clicked()
{
     tracks->addSymbol("Kabelschacht");
}


void QGraphicsSymbolContainer::on_pb_Kabelverteiler_clicked()
{
    if(ui->checkBox_Kabelverteiler->isChecked()){
        tracks->addSymbol("Kilometerangabe");
    }else{
        tracks->addSymbol("Kabelverteiler");
    }
}


void QGraphicsSymbolContainer::on_pushButton_Kennzeichentafel_clicked()
{
    tracks->addSymbol("Kennzeichentafel");
}


void QGraphicsSymbolContainer::on_pushButton_KombinationBlockkennzeichen_clicked()
{
    tracks->addSymbol("KombinationBlockkennzeichen");
}


void QGraphicsSymbolContainer::on_pushButton_Lautsprechersaule_clicked()
{
    tracks->addSymbol("Lautsprechersaule");
}


void QGraphicsSymbolContainer::on_pushButton_Lichtzeichen_clicked()
{
    tracks->addSymbol("Lichtzeichen");
}


void QGraphicsSymbolContainer::on_pushButton_LinienleiterschleifeNummer_clicked()
{
    tracks->addSymbol("LinienleiterschleifeNummer");
}


void QGraphicsSymbolContainer::on_pushButton_Luftstromungsanlage_clicked()
{
    tracks->addSymbol("Luftstromungsanlage");
}


void QGraphicsSymbolContainer::on_pushButton_Magnetschienenkontakt_clicked()
{
    tracks->addSymbol("Magnetschienenkontakt");
}


void QGraphicsSymbolContainer::on_pb_mehra_clicked()
{

     if(ui->checkBox_mehraArrow->isChecked() && ui->checkBox_mehraZugoderStellwerksbedient->isChecked()){
            tracks->addSymbol("mehraZugoderStellwerksbedientArrow");
        }else if(ui->checkBox_mehraArrow->isChecked() && ui->checkBox_mehrasStellwerksbedient->isChecked()){
            tracks->addSymbol("mehrasStellwerksbedientArrow");
        }else if(ui->checkBox_mehraArrow->isChecked() && ui->checkBox_mehraausanderemStellbereich->isChecked()){
            tracks->addSymbol("mehraausanderemStellbereichArrow");
     }
            else if(ui->checkBox_mehraZugoderStellwerksbedient->isChecked()){
        tracks->addSymbol("mehraZugoderStellwerksbedient");
    } else if(ui->checkBox_mehrasStellwerksbedient->isChecked()){
        tracks->addSymbol("mehrasStellwerksbedient");
    }else if(ui->checkBox_mehraausanderemStellbereich->isChecked()){
        tracks->addSymbol("mehraausanderemStellbereich");

    }else if(ui->checkBox_mehraArrow->isChecked()){
        tracks->addSymbol("mehraZugbedientArrow");
    } else{
         tracks->addSymbol("mehraZugbedient");
     }
}


void QGraphicsSymbolContainer::on_pushButton_Merkpfahl_clicked()
{
    tracks->addSymbol("Merkpfahl");
}


void QGraphicsSymbolContainer::on_pb_MTafel_clicked()
{
    if(ui->checkBox_Richtungsanzeiger->isChecked()){
        tracks->addSymbol("Richtungsanzeiger");
    }else if(ui->checkBox_Stumpfgleis->isChecked()){
        tracks->addSymbol("Stumpfgleis");
    }else{
        tracks->addSymbol("MTafel");
    }
}


void QGraphicsSymbolContainer::on_pushButton_Nachbarzentrale_clicked()
{
    tracks->addSymbol("Nachbarzentrale");
}


void QGraphicsSymbolContainer::on_pushButton_Nachschieben_clicked()
{
    tracks->addSymbol("Nachschieben");
}


void QGraphicsSymbolContainer::on_pushButton_Oberirdischer_clicked()
{
    tracks->addSymbol("Oberirdischer");
}


void QGraphicsSymbolContainer::on_pushButton_Rangierhalttafel_clicked()
{
    tracks->addSymbol("Rangierhalttafel");
}


void QGraphicsSymbolContainer::on_pushButton_Rautentafel_clicked()
{
    tracks->addSymbol("Rautentafel");
}


void QGraphicsSymbolContainer::on_pb_reflektierenden_clicked()
{
    if(ui->checkBox_reflektierenden->isChecked()){
        tracks->addSymbol("aktivengelben");
    }else{
        tracks->addSymbol("reflektierenden");
    }
}


void QGraphicsSymbolContainer::on_pushButton_Richtungspfeilmaske_clicked()
{
    tracks->addSymbol("Richtungspfeilmaske");
}


void QGraphicsSymbolContainer::on_pushButton_Schachbretttafel_clicked()
{
    tracks->addSymbol("Schachbretttafel");
}


void QGraphicsSymbolContainer::on_pushButton_Schrankenantrieb_clicked()
{
    tracks->addSymbol("Schrankenantrieb");
}


void QGraphicsSymbolContainer::on_pushButton_SchrankenbaumRechteck_clicked()
{
    tracks->addSymbol("SchrankenbaumRechteck");
}


void QGraphicsSymbolContainer::on_pushButton_Seitenlichtzeichen_clicked()
{
    tracks->addSymbol("Seitenlichtzeichen");
}


void QGraphicsSymbolContainer::on_pushButton_SiBetonschalthaus_clicked()
{
    tracks->addSymbol("SiBetonschalthaus");
}


void QGraphicsSymbolContainer::on_pushButton_SignalElOne_clicked()
{
    tracks->addSymbol("SignalElOne");
}


void QGraphicsSymbolContainer::on_pushButton_SignalElTwo_clicked()
{
    tracks->addSymbol("SignalElTwo");
}


void QGraphicsSymbolContainer::on_pb_Speisegerat_clicked()
{

    if(ui->checkBox_Signalhaltmelder->isChecked()){
        tracks->addSymbol("Signalhaltmelder");
    }else if(ui->checkBox_Sperrsignal->isChecked()){
        tracks->addSymbol("Sperrsignal");
    }else if(ui->checkBox_SperrsignalKennlicht->isChecked()){
        tracks->addSymbol("SperrsignalKennlicht");
    }else{
        tracks->addSymbol("Speisegerat");
    }
}


void QGraphicsSymbolContainer::on_pushButton_StrasensignalmitBlinklicht_clicked()
{
    tracks->addSymbol("StrasensignalmitBlinklicht");
}


void QGraphicsSymbolContainer::on_pushButton_Strassensignal_clicked()
{
    tracks->addSymbol("Strassensignal");
}


void QGraphicsSymbolContainer::on_pushButton_Trapeztafel_clicked()
{
    tracks->addSymbol("Trapeztafel");
}


void QGraphicsSymbolContainer::on_pushButton_uberspannteGleise_clicked()
{
    tracks->addSymbol("uberspannteGleise");
}


void QGraphicsSymbolContainer::on_pushButton_Uberwachungslampe_clicked()
{
    tracks->addSymbol("Uberwachungslampe");
}


void QGraphicsSymbolContainer::on_pushButton_uberwachungssignal_clicked()
{
    tracks->addSymbol("uberwachungssignal");
}


void QGraphicsSymbolContainer::on_pushButton_Verstarker_clicked()
{
    tracks->addSymbol("Verstarker");
}


void QGraphicsSymbolContainer::on_pushButton_VorsichtsignalHauptsignalschirm_clicked()
{
    tracks->addSymbol("VorsichtsignalHauptsignalschirm");
}


void QGraphicsSymbolContainer::on_pushButton_vorstellwerksbedientVorsignalwiederholer_clicked()
{
    tracks->addSymbol("vorstellwerksbedientVorsignalwiederholer");
}


void QGraphicsSymbolContainer::on_pushButton_Warntafel_clicked()
{
    tracks->addSymbol("Warntafel");
}


void QGraphicsSymbolContainer::on_pushButton_Windmeldeanlage_clicked()
{
    tracks->addSymbol("Windmeldeanlage");
}


void QGraphicsSymbolContainer::on_pushButton_Zahlpfeile_clicked()
{
    tracks->addSymbol("Zahlpfeile");
}


void QGraphicsSymbolContainer::on_pushButton_Zugdeckungssignal_clicked()
{
    tracks->addSymbol("Zugdeckungssignal");
}


void QGraphicsSymbolContainer::on_pushButton_Weichenantrieb_clicked()
{
    tracks->addSymbol("Weichenantrieb");
}


void QGraphicsSymbolContainer::on_pushButton_Weichensignal_clicked()
{
    tracks->addSymbol("Weichensignal");
}


void QGraphicsSymbolContainer::on_pb_VorsignalbakenFive_clicked()
{
    if(ui->checkBox_VorsignalbakenOne->isChecked()){
        tracks->addSymbol("VorsignalbakenOne");
    }else if(ui->checkBox_VorsignalbakenTwo->isChecked()){
        tracks->addSymbol("VorsignalbakenTwo");
    }else if(ui->checkBox_VorsignalbakenThree->isChecked()){
        tracks->addSymbol("VorsignalbakenThree");
    }else if(ui->checkBox_VorsignalbakenFour->isChecked()){
        tracks->addSymbol("VorsignalbakenFour");
    }else{
        tracks->addSymbol("VorsignalbakenFive");
    }
}


void QGraphicsSymbolContainer::on_pb_Kabelschrank_clicked()
{
    if(ui->checkBox_Kabelschrank->isChecked()){
        tracks->addSymbol("Kabelschrank");
    }else{
        tracks->addSymbol("Vorsignaltafel");
    }
}


void QGraphicsSymbolContainer::on_pushButton_WartezeichenMain_clicked()
{
    if(ui->checkBox_Wartezeichenmit->isChecked()){
        tracks->addSymbol("Wartezeichenmit");
    }else{
        tracks->addSymbol("Wartezeichen");
    }
}


void QGraphicsSymbolContainer::on_pb_WeitereOne_clicked()
{
    if(ui->checkBox_WeitereTwo->isChecked()){
        tracks->addSymbol("WeitereTwo");
    }else if(ui->checkBox_WeitereTwo_2->isChecked()){
        tracks->addSymbol("WeitereThree");
    }else{
        tracks->addSymbol("WeitereOne");
    }
}


void QGraphicsSymbolContainer::on_pb_zweiAktiven_clicked()
{
    if(ui->checkBox_2->isChecked()){
        tracks->addSymbol("zweiReflektierenden");
    }else{
        tracks->addSymbol("zweiAktiven");
    }
}


void QGraphicsSymbolContainer::on_lbl_zugbedient_clicked()
{
    if(ui->chb_zug_arrow->isChecked() && ui->chb_zug_filled->isChecked()){
        tracks->addSymbol("stellwerksbedientArrow");
    }else if(ui->chb_zug_arrow->isChecked() && ui->chb_zug_partial->isChecked()){
        tracks->addSymbol("zugOderStellwerksbedientArrow");
    }else if (ui->chb_zug_arrow->isChecked() && ui->chb_zug_nofill->isChecked()){
        tracks->addSymbol("zugbedientArrow");
    }else if (ui->chb_zug_filled->isChecked()){
        tracks->addSymbol("stellwerksbedient");
    }else if (ui->chb_zug_partial->isChecked()){
         tracks->addSymbol("zugOderStellwerksbedient");
    } else if (ui->chb_zug_nofill->isChecked()){
             tracks->addSymbol("zugbedient");
        }
    else if (ui->chb_zug_arrow->isChecked()){
                 tracks->addSymbol("zugbedientArrow");
            }
    else{
         tracks->addSymbol("zugbedient");
    }
}


void QGraphicsSymbolContainer::on_pushbutton_vorZugbedient_clicked()
{
    if(ui->checkBox_Arrow->isChecked() && ui->checkBox_vorStellwerksbedient->isChecked()){
        tracks->addSymbol("vorStellwerksbedientArrow");
    }else if(ui->checkBox_Arrow->isChecked() && ui->checkBox_vorZugoderStellwerksbedient->isChecked()){
        tracks->addSymbol("vorZugoderStellwerksbedientArrow");
    }else if (ui->checkBox_vorZugoderStellwerksbedient->isChecked()){
        tracks->addSymbol("vorZugoderStellwerksbedient");
    }else if (ui->checkBox_vorStellwerksbedient->isChecked()){
        tracks->addSymbol("vorStellwerksbedient");
    }else if (ui->checkBox_Arrow->isChecked()){
         tracks->addSymbol("vorZugbedientArrow");
    }
    else{
         tracks->addSymbol("vorZugbedient");
    }
}

