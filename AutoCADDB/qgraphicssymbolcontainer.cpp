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
    ui->lbl_stellwerksbedient->setPixmap(*pixmap);
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


}

QGraphicsSymbolContainer::~QGraphicsSymbolContainer()
{
    delete ui;
}


void QGraphicsSymbolContainer::on_pb1_clicked()
{
    defaultObjectName = "Abfahrsignal";
    tracks->addSymbol("Abfahrsignal");
}


void QGraphicsSymbolContainer::on_pb2_clicked()
{
    defaultObjectName = "Achszahlkontakt";
    tracks->addSymbol("Achszahlkontakt");
}


void QGraphicsSymbolContainer::on_pb3_clicked()
{
    defaultObjectName = "AutomatikETSchild";
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
    tracks->addSymbol("Ankundetafel");
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
    tracks->addSymbol("balisengruppeLinks");
}


void QGraphicsSymbolContainer::on_pb16_clicked()
{
    tracks->addSymbol("balisengruppeRechts");
}


void QGraphicsSymbolContainer::on_pb17_clicked()
{
    tracks->addSymbol("BalisengruppeunGesteuert");
}


void QGraphicsSymbolContainer::on_pb18_clicked()
{
     tracks->addSymbol("BalisengruppeUngesteuertTri");
}


void QGraphicsSymbolContainer::on_pb19_clicked()
{
     tracks->addSymbol("Bereichskennungswechsel");
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
     tracks->addSymbol("EinzelbaliseGesteuert");
}


void QGraphicsSymbolContainer::on_pb33_clicked()
{
     tracks->addSymbol("EinzelbaliseLinks");
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
     tracks->addSymbol("ETCSstopTafelOne");
}


void QGraphicsSymbolContainer::on_pb38_clicked()
{
     tracks->addSymbol("ETCSstopTafelTwo");
}


void QGraphicsSymbolContainer::on_stellwerksbedient_clicked()
{
     tracks->addSymbol("stellwerksbedient");
}



void QGraphicsSymbolContainer::on_chk_stellArrow_clicked()
{
    pixmap=new QPixmap(100,20);
    pixmap->fill(Qt::transparent);
    painter=new QPainter(pixmap);

    if (ui->chk_stellArrow->isChecked()) {
        painter->drawPixmap(0, 0, QPixmap(":/icons/assets/qgraphics/stellwerksbedient.svg"));
        painter->drawPixmap(0, 0, QPixmap(":/icons/assets/qgraphics/hauptSignalbegriffe.svg"));
    } else {
         painter->drawPixmap(0, 0, QPixmap(":/icons/assets/qgraphics/stellwerksbedient.svg"));
    }
     painter->end();
     ui->lbl_stellwerksbedient->setPixmap(*pixmap);
}


void QGraphicsSymbolContainer::on_pb_hauptSignalbegriffe_clicked()
{
    if(ui->chk_stellArrow->isChecked()){
         tracks->addSymbol("stellwerksbedient_arrow");
    }else{
         tracks->addSymbol("stellwerksbedient");
    }

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
        ui->lbl_zugbedient->setIcon(QIcon(":/icons/assets/qgraphics/hauptSignalbegriffe.svg"));

        if((ui->chb_zug_filled->isChecked())){
            ui->lbl_zugbedient->setIcon(QIcon(":/icons/assets/qgraphics/stellwerksbedient.svg"));

        }
        if((ui->chb_zug_nofill->isChecked())){
            ui->lbl_zugbedient->setIcon(QIcon(":/icons/assets/qgraphics/zugbedient.svg"));
        }
        if((ui->chb_zug_partial->isChecked())){
            ui->lbl_zugbedient->setIcon(QIcon(":/icons/assets/qgraphics/zugOderStellwerksbedient.svg"));
        }
    } else {
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

    if (ui->checkBox_vorStellwerksbedient->isChecked()) {
        ui->pushbutton_vorZugbedient->setIcon(QIcon(":/icons/assets/qgraphics/vorStellwerksbedient.svg"));
    } else {
         ui->pushbutton_vorZugbedient->setIcon(QIcon(":/icons/assets/qgraphics/vorZugbedient.svg"));
    }
}


void QGraphicsSymbolContainer::on_checkBox_vorZugbedient_clicked()
{
    ui->checkBox_vorStellwerksbedient->setChecked(false);
    ui->checkBox_vorZugoderStellwerksbedient->setChecked(false);


         ui->pushbutton_vorZugbedient->setIcon(QIcon(":/icons/assets/qgraphics/vorZugbedient.svg"));

}


void QGraphicsSymbolContainer::on_checkBox_vorZugoderStellwerksbedient_clicked()
{
    ui->checkBox_vorStellwerksbedient->setChecked(false);


    if (ui->checkBox_vorZugoderStellwerksbedient->isChecked()) {
        ui->pushbutton_vorZugbedient->setIcon(QIcon(":/icons/assets/qgraphics/vorZugoderStellwerksbedient.svg"));
    } else {
         ui->pushbutton_vorZugbedient->setIcon(QIcon(":/icons/assets/qgraphics/vorZugbedient.svg"));
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


void QGraphicsSymbolContainer::on_checkBox_mehraZugoderStellwerksbedient_clicked()
{
    ui->checkBox_mehrasStellwerksbedient->setChecked(false);
    ui->checkBox_mehraausanderemStellbereich->setChecked(false);

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

