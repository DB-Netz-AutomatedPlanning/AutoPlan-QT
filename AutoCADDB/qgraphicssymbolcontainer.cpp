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
    //    tracks->addSymbol("Abfahrsignal");
    if (symbolIsSelected && selectedSymbolName == "Abfahrsignal"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);

    } else{
        symbolIsSelected = true;
        selectedSymbolName = "Abfahrsignal";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Abfahrsignal.svg"));
        tracks->setCursor(cursor_default);
    }
}

void QGraphicsSymbolContainer::on_pb2_clicked()
{
    if (symbolIsSelected && (selectedSymbolName == "ZweiBuSchaltkontakt" || selectedSymbolName == "Schaltkontakt"
                             || selectedSymbolName == "Achszahlkontakt")) {
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        if(ui->checkBox_ZweiBuSchaltkontakt->isChecked()){
            selectedSymbolName = "ZweiBuSchaltkontakt";
            //            tracks->addSymbol("ZweiBuSchaltkontakt");
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/ZweiBuSchaltkontakt.svg"));
            tracks->setCursor(cursor_default);
        } else if(ui->checkBox_Schaltkontakt->isChecked()){
            selectedSymbolName = "Schaltkontakt";
            //            tracks->addSymbol("Schaltkontakt");
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Schaltkontakt.svg"));
            tracks->setCursor(cursor_default);
        }else{
            selectedSymbolName = "Achszahlkontakt";
            //            tracks->addSymbol("Achszahlkontakt");
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Achszahlkontakt.svg"));
            tracks->setCursor(cursor_default);
        }
    }
}


//void QGraphicsSymbolContainer::on_pb3_clicked()
//{
//    tracks->addSymbol("AutomatikETSchild");
//}


void QGraphicsSymbolContainer::on_pb5_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Andreaskreuz"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);

    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Andreaskreuz";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Andreaskreuz.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pb6_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "AndreaskreuzAmPeitschenmast"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);

    } else {
        symbolIsSelected = true;
        selectedSymbolName = "AndreaskreuzAmPeitschenmast";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/AndreaskreuzAmPeitschenmast.svg"));
        tracks->setCursor(cursor_default);
    }
}


//void QGraphicsSymbolContainer::on_pb7_clicked()
//{
//    tracks->addSymbol("Anfangsschleife");
//}


void QGraphicsSymbolContainer::on_pb8_clicked()
{
    if (symbolIsSelected && (selectedSymbolName == "AutomatikETSchild" || selectedSymbolName == "BuBuTafel" || selectedSymbolName == "AutomatikHETSchild" ||
                             selectedSymbolName == "BuAnkundetafel" ||  selectedSymbolName == "Ankundetafel")){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);

    } else {
        symbolIsSelected = true;
        if(ui->checkBox_AutomatikETSchild->isChecked()){
            selectedSymbolName = "AutomatikETSchild";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/AutomatikETSchild.svg"));
            tracks->setCursor(cursor_default);
        }else if(ui->checkBox_BuBuTafel->isChecked()){
            selectedSymbolName = "BuBuTafel";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/BuBuTafel.svg"));
            tracks->setCursor(cursor_default);
        }else if(ui->checkBox_AutomatikHETSchild->isChecked()){
            selectedSymbolName = "AutomatikHETSchild";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/AutomatikHETSchild.svg"));
            tracks->setCursor(cursor_default);
        }else if(ui->checkBox_BuAnkundetafel->isChecked()){
            selectedSymbolName = "BuAnkundetafel";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/BuAnkundetafel.svg"));
            tracks->setCursor(cursor_default);
        }else{
            selectedSymbolName = "Ankundetafel";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Ankundetafel.svg"));
            tracks->setCursor(cursor_default);
        }
    }
}


void QGraphicsSymbolContainer::on_pb9_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Ankundigungsbake"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);

    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Ankundigungsbake";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Ankundigungsbake.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pb10_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "AusschaltEinschalt"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);

    } else {
        symbolIsSelected = true;
        selectedSymbolName = "AusschaltEinschalt";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/AusschaltEinschalt.svg"));
        tracks->setCursor(cursor_default);
    }
}


//void QGraphicsSymbolContainer::on_pb11_clicked()
//{
//    tracks->addSymbol("AutomatikETSchild");
//}


//void QGraphicsSymbolContainer::on_pb12_clicked()
//{
//    tracks->addSymbol("AutomatikHETSchild");
//}


//void QGraphicsSymbolContainer::on_pb13_clicked()
//{
//    tracks->addSymbol("BalisengruppeGesteuert");
//}


//void QGraphicsSymbolContainer::on_pb14_clicked()
//{
//    tracks->addSymbol("BalisengruppeGesteuertTri");
//}


void QGraphicsSymbolContainer::on_pb15_clicked()
{
    if (symbolIsSelected && (selectedSymbolName == "balisengruppeRechts" || selectedSymbolName == "balisengruppeLinks")){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);

    } else {
        symbolIsSelected = true;
        if(ui->checkBox_balisengruppeLinks->isChecked()){
            selectedSymbolName = "balisengruppeRechts";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/balisengruppeRechts.svg"));
            tracks->setCursor(cursor_default);
        }else{
            selectedSymbolName = "balisengruppeLinks";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/balisengruppeLinks.svg"));
            tracks->setCursor(cursor_default);
        }
    }
}


//void QGraphicsSymbolContainer::on_pb16_clicked()
//{
//    tracks->addSymbol("balisengruppeRechts");
//}


void QGraphicsSymbolContainer::on_pb17_clicked()
{
    if (symbolIsSelected && (selectedSymbolName == "BalisengruppeGesteuert" || selectedSymbolName == "BalisengruppeunGesteuert")){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);

    } else {
        symbolIsSelected = true;
        if(ui->checkBox_BalisengruppeGesteuert->isChecked()){
            selectedSymbolName = "BalisengruppeGesteuert";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/BalisengruppeGesteuert.svg"));
            tracks->setCursor(cursor_default);
        }else{
            selectedSymbolName = "BalisengruppeunGesteuert";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/BalisengruppeunGesteuert.svg"));
            tracks->setCursor(cursor_default);
        }
    }
}


void QGraphicsSymbolContainer::on_pb18_clicked()
{
    if (symbolIsSelected && (selectedSymbolName == "BalisengruppeGesteuertTri" || selectedSymbolName == "BalisengruppeUngesteuertTri")){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);

    } else {
        symbolIsSelected = true;
        if(ui->checkBox_BalisengruppeGesteuertTri->isChecked()){
            selectedSymbolName = "BalisengruppeGesteuertTri";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/BalisengruppeGesteuertTri.svg"));
            tracks->setCursor(cursor_default);
        }else{
            selectedSymbolName = "BalisengruppeUngesteuertTri";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/BalisengruppeUngesteuertTri.svg"));
            tracks->setCursor(cursor_default);
        }
    }
}


void QGraphicsSymbolContainer::on_pb19_clicked()
{
    if (symbolIsSelected && (selectedSymbolName == "Bereichskennungswechselortungsneutral" || selectedSymbolName == "Bereichskennungswechsel")){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);

    } else {
        symbolIsSelected = true;
        if(ui->checkBox_Bereichskennungswechsel->isChecked()){
            selectedSymbolName = "Bereichskennungswechselortungsneutral";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Bereichskennungswechselortungsneutral.svg"));
            tracks->setCursor(cursor_default);
        }else{
            selectedSymbolName = "Bereichskennungswechsel";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Bereichskennungswechsel.svg"));
            tracks->setCursor(cursor_default);
        }
    }
}


//void QGraphicsSymbolContainer::on_pb20_clicked()
//{
//     tracks->addSymbol("Bereichskennungswechselortungsneutral");
//}


void QGraphicsSymbolContainer::on_pb21_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Blockkennzeichen"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);

    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Blockkennzeichen";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Blockkennzeichen.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pb22_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Blockschaltbilder"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);

    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Blockschaltbilder";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Blockschaltbilder.svg"));
        tracks->setCursor(cursor_default);
    }
}


//void QGraphicsSymbolContainer::on_pb23_clicked()
//{
//     tracks->addSymbol("Bremsprellbock");
//}


void QGraphicsSymbolContainer::on_pb24_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Bremsprobe"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);

    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Bremsprobe";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Bremsprobe.svg"));
        tracks->setCursor(cursor_default);
    }
}


//void QGraphicsSymbolContainer::on_pb25_clicked()
//{
//     tracks->addSymbol("BuAnkundetafel");
//}


void QGraphicsSymbolContainer::on_pb26_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "BuAnkundetafelWiederholer"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);

    } else {
        symbolIsSelected = true;
        selectedSymbolName = "BuAnkundetafelWiederholer";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/BuAnkundetafelWiederholer.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pb27_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "BuAnkundetafelWiederholerOne"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);

    } else {
        symbolIsSelected = true;
        selectedSymbolName = "BuAnkundetafelWiederholerOne";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/BuAnkundetafelWiederholerOne.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pb28_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "BuBetonschalthaus"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);

    } else {
        symbolIsSelected = true;
        selectedSymbolName = "BuBetonschalthaus";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/BuBetonschalthaus.svg"));
        tracks->setCursor(cursor_default);
    }
}


//void QGraphicsSymbolContainer::on_pb29_clicked()
//{
//     tracks->addSymbol("BuBuTafel");
//}


void QGraphicsSymbolContainer::on_pb30_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "BuSchaltkontakt"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);

    } else {
        symbolIsSelected = true;
        selectedSymbolName = "BuSchaltkontakt";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/BuSchaltkontakt.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pb31_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "EinschaltGleisAusschaltmagnet"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);

    } else {
        symbolIsSelected = true;
        selectedSymbolName = "EinschaltGleisAusschaltmagnet";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/EinschaltGleisAusschaltmagnet.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pb32_clicked()
{
    if (symbolIsSelected && (selectedSymbolName == "EinzelbaliseUngesteuert" || selectedSymbolName == "EinzelbaliseGesteuert")){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);

    } else {
        symbolIsSelected = true;
        if(ui->checkBox_EinzelbaliseUngesteuert->isChecked()){
            selectedSymbolName = "EinzelbaliseUngesteuert";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/EinzelbaliseUngesteuert.svg"));
            tracks->setCursor(cursor_default);
        }else{
            selectedSymbolName = "EinzelbaliseGesteuert";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/EinzelbaliseGesteuert.svg"));
            tracks->setCursor(cursor_default);
        }
    }
}


void QGraphicsSymbolContainer::on_pb33_clicked()
{
    if (symbolIsSelected && (selectedSymbolName == "EinzelbaliseRechts" || selectedSymbolName == "EinzelbaliseLinks")){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);

    } else {
        symbolIsSelected = true;
        if(ui->checkBox_EinzelbaliseRechts->isChecked()){
            selectedSymbolName = "EinzelbaliseRechts";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/EinzelbaliseRechts.svg"));
            tracks->setCursor(cursor_default);
        }else{
            selectedSymbolName = "EinzelbaliseLinks";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/EinzelbaliseLinks.svg"));
            tracks->setCursor(cursor_default);
        }
    }
}


//void QGraphicsSymbolContainer::on_pb34_clicked()
//{
//     tracks->addSymbol("EinzelbaliseRechts");
//}


//void QGraphicsSymbolContainer::on_pb35_clicked()
//{
//     tracks->addSymbol("EinzelbaliseUngesteuert");
//}


void QGraphicsSymbolContainer::on_pb36_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "ErsatzsignalHauptsignalschirm"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);

    } else {
        symbolIsSelected = true;
        selectedSymbolName = "ErsatzsignalHauptsignalschirm";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/ErsatzsignalHauptsignalschirm.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pb37_clicked()
{
    if (symbolIsSelected && (selectedSymbolName == "ETCSstopTafelTwo" || selectedSymbolName == "ETCSstopTafelOne")){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);

    } else {
        symbolIsSelected = true;
        if(ui->checkBox_ETCSstopTafelTwo->isChecked()){
            selectedSymbolName = "ETCSstopTafelTwo";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/ETCSstopTafelTwo.svg"));
            tracks->setCursor(cursor_default);
        }else{
            selectedSymbolName = "ETCSstopTafelOne";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/ETCSstopTafelOne.svg"));
            tracks->setCursor(cursor_default);
        }
    }
}


//void QGraphicsSymbolContainer::on_pb38_clicked()
//{
//     tracks->addSymbol("ETCSstopTafelTwo");
//}


//void QGraphicsSymbolContainer::on_stellwerksbedient_clicked()
//{
//     tracks->addSymbol("stellwerksbedient");
//}


//void QGraphicsSymbolContainer::on_pb_hauptSignalbegriffe_clicked()
//{
//         tracks->addSymbol("stellwerksbedient");
//}


//void QGraphicsSymbolContainer::on_pb_fdurchfarten_clicked()
//{
//   tracks->addSymbol("FahrstrassensymboleDurchfahrten");
//}


//void QGraphicsSymbolContainer::on_pb_FDurchGuterzuge_clicked()
//{
//   tracks->addSymbol("FahrstrassensymboleDurchGuterzuge");

//}


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
    if (symbolIsSelected && (selectedSymbolName == "FahrstrassensymboleDurchfahrten" || selectedSymbolName == "FahrstrassensymboleGuterzuge" ||
                             selectedSymbolName == "FahrstrassensymboleRangierfahrten" || selectedSymbolName == "FahrstrassensymboleDurchGuterzuge" ||
                             selectedSymbolName == "FahrstrassensymboleReise")){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);

    } else {
        symbolIsSelected = true;
        if(ui->checkBox_FahrstrassensymboleDurchfahrten->isChecked()){
            selectedSymbolName = "FahrstrassensymboleDurchfahrten";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/FahrstrassensymboleDurchfahrten.svg"));
            tracks->setCursor(cursor_default);
        } else if(ui->checkBox_FahrstrassensymboleGuterzuge->isChecked()){
            selectedSymbolName = "FahrstrassensymboleGuterzuge";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/FahrstrassensymboleGuterzuge.svg"));
            tracks->setCursor(cursor_default);
        }else if(ui->checkBox_FahrstrassensymboleRangierfahrten->isChecked()){
            selectedSymbolName = "FahrstrassensymboleRangierfahrten";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/FahrstrassensymboleRangierfahrten.svg"));
            tracks->setCursor(cursor_default);
        }else if(ui->checkBox_FahrstrassensymboleDurchGuterzuge->isChecked()){
            selectedSymbolName = "FahrstrassensymboleDurchGuterzuge";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/FahrstrassensymboleDurchGuterzuge.svg"));
            tracks->setCursor(cursor_default);
        }else{
            selectedSymbolName = "FahrstrassensymboleReise";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/FahrstrassensymboleReise.svg"));
            tracks->setCursor(cursor_default);
        }
    }

//    if(ui->checkBox_FahrstrassensymboleDurchfahrten->isChecked()){
//        tracks->addSymbol("FahrstrassensymboleDurchfahrten");
//    } else if(ui->checkBox_FahrstrassensymboleGuterzuge->isChecked()){
//        tracks->addSymbol("FahrstrassensymboleGuterzuge");
//    }else if(ui->checkBox_FahrstrassensymboleRangierfahrten->isChecked()){
//        tracks->addSymbol("FahrstrassensymboleRangierfahrten");
//    }else if(ui->checkBox_FahrstrassensymboleDurchGuterzuge->isChecked()){
//        tracks->addSymbol("FahrstrassensymboleDurchGuterzuge");
//    }else{
//        tracks->addSymbol("FahrstrassensymboleReise");
//    }
}


void QGraphicsSymbolContainer::on_pb_Fahrtanzeiger_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Fahrtanzeiger"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);

    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Fahrtanzeiger";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Fahrtanzeiger.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pb_Fahrzeugsensor_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Fahrzeugsensor"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);

    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Fahrzeugsensor";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Fahrzeugsensor.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pb_Festprellbock_clicked()
{
    if (symbolIsSelected && (selectedSymbolName == "Bremsprellbock" || selectedSymbolName == "Abklappbarer"
                             || selectedSymbolName == "Anfangsschleife" || selectedSymbolName == "Festprellbock")){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);

    } else {
        symbolIsSelected = true;
        if(ui->checkBox_Bremsprellbock->isChecked()){
            selectedSymbolName = "Bremsprellbock";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Bremsprellbock.svg"));
            tracks->setCursor(cursor_default);
        } else if(ui->checkBox_Abklappbarer->isChecked()){
            selectedSymbolName = "Abklappbarer";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Abklappbarer.svg"));
            tracks->setCursor(cursor_default);
        }else if(ui->checkBox_Anfangsschleife->isChecked()){
            selectedSymbolName = "Anfangsschleife";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Anfangsschleife.svg"));
            tracks->setCursor(cursor_default);
        }else{
            selectedSymbolName = "Festprellbock";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Festprellbock.svg"));
            tracks->setCursor(cursor_default);
        }
    }
}


void QGraphicsSymbolContainer::on_pb_Flachstellenortungsanlage_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Flachstellenortungsanlage"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Flachstellenortungsanlage";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Flachstellenortungsanlage.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pb_Fruhhaltanzeiger_clicked()
{
    if (symbolIsSelected && (selectedSymbolName == "GegengleisanzeigerHauptsignalschirm" || selectedSymbolName == "Geschwindigkeitsanzeiger"
                             || selectedSymbolName == "hauptRichtungsanzeiger" || selectedSymbolName == "HauptGegengleisanzeiger"
                             || selectedSymbolName == "Fruhhaltanzeiger")){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);

    } else {
        symbolIsSelected = true;
        if(ui->checkBox_GegengleisanzeigerHauptsignalschirm->isChecked()){
            selectedSymbolName = "GegengleisanzeigerHauptsignalschirm";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/GegengleisanzeigerHauptsignalschirm.svg"));
            tracks->setCursor(cursor_default);
        }else if(ui->checkBox_Geschwindigkeitsanzeiger->isChecked()){
            selectedSymbolName = "Geschwindigkeitsanzeiger";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Geschwindigkeitsanzeiger.svg"));
            tracks->setCursor(cursor_default);
        }else if(ui->checkBox_hauptRichtungsanzeiger->isChecked()){
            selectedSymbolName = "hauptRichtungsanzeiger";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/hauptRichtungsanzeiger.svg"));
            tracks->setCursor(cursor_default);
        }else if(ui->checkBox_HauptGegengleisanzeiger->isChecked()){
            selectedSymbolName = "HauptGegengleisanzeiger";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/HauptGegengleisanzeiger.svg"));
            tracks->setCursor(cursor_default);
        }else{
            selectedSymbolName = "Fruhhaltanzeiger";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Fruhhaltanzeiger.svg"));
            tracks->setCursor(cursor_default);
        }
    }
}


void QGraphicsSymbolContainer::on_pb_Funkanruckmelder_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Funkanruckmelder"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Funkanruckmelder";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Funkanruckmelder.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pb_FusgangermaskeundAndreaskreuz_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "FusgangermaskeundAndreaskreuz"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "FusgangermaskeundAndreaskreuz";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/FusgangermaskeundAndreaskreuz.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pb_GegengleisanzeigerLichtsignal_clicked()
{
    if (symbolIsSelected && (selectedSymbolName == "Gegengleisanzeiger" || selectedSymbolName == "GegengleisanzeigerLichtsignal")){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        if(ui->checkBox_GegengleisanzeigerLichtsignal->isChecked()){
            selectedSymbolName = "Gegengleisanzeiger";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Gegengleisanzeiger.svg"));
            tracks->setCursor(cursor_default);
        }else{
            selectedSymbolName = "GegengleisanzeigerLichtsignal";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/GegengleisanzeigerLichtsignal.svg"));
            tracks->setCursor(cursor_default);
        }
    }
}


void QGraphicsSymbolContainer::on_pb_Geschwindigkeits_clicked()
{
    if (symbolIsSelected && (selectedSymbolName == "GeschwindigkeirRichtungspfeil" || selectedSymbolName == "Geschwindigkeits")){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        if(ui->checkBox_Geschwindigkeits->isChecked()){
            selectedSymbolName = "GeschwindigkeirRichtungspfeil";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/GeschwindigkeirRichtungspfeil.svg"));
            tracks->setCursor(cursor_default);
        }else{
            selectedSymbolName = "Geschwindigkeits";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Geschwindigkeits.svg"));
            tracks->setCursor(cursor_default);
        }
    }
}


void QGraphicsSymbolContainer::on_pushButton_Geschwindigkeitssignal_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Geschwindigkeitssignal"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Geschwindigkeitssignal";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Geschwindigkeitssignal.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_Geschwindigkeitswechsel_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Geschwindigkeitswechsel"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Geschwindigkeitswechsel";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Geschwindigkeitswechsel.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pb_GeshLichtsignal_clicked()
{
    if (symbolIsSelected && (selectedSymbolName == "Richtungsvoranzeiger" || selectedSymbolName == "GeshLichtsignal")){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        if(ui->checkBox_GeshLichtsignal->isChecked()){
            selectedSymbolName = "Richtungsvoranzeiger";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Richtungsvoranzeiger.svg"));
            tracks->setCursor(cursor_default);
        }else{
            selectedSymbolName = "GeshLichtsignal";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/GeshLichtsignal.svg"));
            tracks->setCursor(cursor_default);
        }
    }
}


void QGraphicsSymbolContainer::on_pb_gesteuertRechts_clicked()
{
    if (symbolIsSelected && (selectedSymbolName == "gesteuertLinks" || selectedSymbolName == "gesteuertRechts")){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        if(ui->checkBox_gesteuertRechts->isChecked()){
            selectedSymbolName = "gesteuertLinks";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/gesteuertLinks.svg"));
            tracks->setCursor(cursor_default);
        }else{
            selectedSymbolName = "gesteuertRechts";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/gesteuertRechts.svg"));
            tracks->setCursor(cursor_default);
        }
    }
}


void QGraphicsSymbolContainer::on_pushButton_Gleislangen_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Gleislangen"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Gleislangen";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Gleislangen.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_27_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "HaltetafelmitZuord"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "HaltetafelmitZuord";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/HaltetafelmitZuord.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_hauptGeschwindigkeitsanzeiger_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "hauptGeschwindigkeitsanzeiger"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "hauptGeschwindigkeitsanzeiger";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/hauptGeschwindigkeitsanzeiger.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_hauptSignalbegriffe_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "hauptSignalbegriffe"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "hauptSignalbegriffe";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/hauptSignalbegriffe.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_HauptsignalIdentificationFour_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "HauptsignalIdentificationFour"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "HauptsignalIdentificationFour";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/HauptsignalIdentificationFour.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_Haltepunkttafel_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Haltepunkttafel"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Haltepunkttafel";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Haltepunkttafel.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pb_hauptTunneln_clicked()
{
    if (symbolIsSelected && (selectedSymbolName == "HauptBahnsteigdach" || selectedSymbolName == "hauptTunneln")){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        if(ui->checkBox_hauptTunneln->isChecked()){
            selectedSymbolName = "HauptBahnsteigdach";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/HauptBahnsteigdach.svg"));
            tracks->setCursor(cursor_default);
        }else{
            selectedSymbolName = "hauptTunneln";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/hauptTunneln.svg"));
            tracks->setCursor(cursor_default);
        }
    }
}


void QGraphicsSymbolContainer::on_pushButton_Heisslauferortungsanlage_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Heisslauferortungsanlage"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Heisslauferortungsanlage";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Heisslauferortungsanlage.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_Hektometerangabe_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Hektometerangabe"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Hektometerangabe";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Hektometerangabe.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_Kabelformstein_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Kabelformstein"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Kabelformstein";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Kabelformstein.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_Kabelmuffe_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Kabelmuffe"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Kabelmuffe";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Kabelmuffe.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_Kabelschacht_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Kabelschacht"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Kabelschacht";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Kabelschacht.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pb_Kabelverteiler_clicked()
{
    if (symbolIsSelected && (selectedSymbolName == "Kilometerangabe" || selectedSymbolName == "Kabelverteiler")){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        if(ui->checkBox_Kabelverteiler->isChecked()){
            selectedSymbolName = "Kilometerangabe";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Kilometerangabe.svg"));
            tracks->setCursor(cursor_default);
        }else{
            selectedSymbolName = "Kabelverteiler";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Kabelverteiler.svg"));
            tracks->setCursor(cursor_default);
        }
    }
}


void QGraphicsSymbolContainer::on_pushButton_Kennzeichentafel_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Kennzeichentafel"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Kennzeichentafel";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Kennzeichentafel.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_KombinationBlockkennzeichen_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "KombinationBlockkennzeichen"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "KombinationBlockkennzeichen";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/KombinationBlockkennzeichen.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_Lautsprechersaule_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Lautsprechersaule"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Lautsprechersaule";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Lautsprechersaule.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_Lichtzeichen_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Lichtzeichen"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Lichtzeichen";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Lichtzeichen.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_LinienleiterschleifeNummer_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "LinienleiterschleifeNummer"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "LinienleiterschleifeNummer";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/LinienleiterschleifeNummer.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_Luftstromungsanlage_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Luftstromungsanlage"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Luftstromungsanlage";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Luftstromungsanlage.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_Magnetschienenkontakt_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Magnetschienenkontakt"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Magnetschienenkontakt";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Magnetschienenkontakt.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pb_mehra_clicked()
{
    if (symbolIsSelected && (selectedSymbolName == "mehraZugoderStellwerksbedientArrow" || selectedSymbolName == "mehrasStellwerksbedientArrow" || selectedSymbolName == "mehraausanderemStellbereichArrow"
                             || selectedSymbolName == "mehraZugoderStellwerksbedient" || selectedSymbolName == "mehrasStellwerksbedient" || selectedSymbolName == "mehraausanderemStellbereich"
                             || selectedSymbolName == "mehraZugbedientArrow" || selectedSymbolName == "mehraZugbedient")){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        if(ui->checkBox_mehraArrow->isChecked() && ui->checkBox_mehraZugoderStellwerksbedient->isChecked()){
            selectedSymbolName = "mehraZugoderStellwerksbedientArrow";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/mehraZugoderStellwerksbedientArrow.svg"));
            tracks->setCursor(cursor_default);
        }else if(ui->checkBox_mehraArrow->isChecked() && ui->checkBox_mehrasStellwerksbedient->isChecked()){
            selectedSymbolName = "mehrasStellwerksbedientArrow";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/mehrasStellwerksbedientArrow.svg"));
            tracks->setCursor(cursor_default);
        }else if(ui->checkBox_mehraArrow->isChecked() && ui->checkBox_mehraausanderemStellbereich->isChecked()){
            selectedSymbolName = "mehraausanderemStellbereichArrow";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/mehraausanderemStellbereichArrow.svg"));
            tracks->setCursor(cursor_default);
        }
        else if(ui->checkBox_mehraZugoderStellwerksbedient->isChecked()){
            selectedSymbolName = "mehraZugoderStellwerksbedient";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/mehraZugoderStellwerksbedient.svg"));
            tracks->setCursor(cursor_default);
        } else if(ui->checkBox_mehrasStellwerksbedient->isChecked()){
            selectedSymbolName = "mehrasStellwerksbedient";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/mehrasStellwerksbedient.svg"));
            tracks->setCursor(cursor_default);
        }else if(ui->checkBox_mehraausanderemStellbereich->isChecked()){
            selectedSymbolName = "mehraausanderemStellbereich";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/mehraausanderemStellbereich.svg"));
            tracks->setCursor(cursor_default);
        }else if(ui->checkBox_mehraArrow->isChecked()){
            selectedSymbolName = "mehraZugbedientArrow";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/mehraZugbedientArrow.svg"));
            tracks->setCursor(cursor_default);
        } else{
            selectedSymbolName = "mehraZugbedient";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/mehraZugbedient.svg"));
            tracks->setCursor(cursor_default);
        }
    }
}


void QGraphicsSymbolContainer::on_pushButton_Merkpfahl_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Merkpfahl"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Merkpfahl";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Merkpfahl.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pb_MTafel_clicked()
{
    if (symbolIsSelected && (selectedSymbolName == "Richtungsanzeiger" ||selectedSymbolName == "Stumpfgleis"
                              || selectedSymbolName == "MTafel")){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        if(ui->checkBox_Richtungsanzeiger->isChecked()){
            selectedSymbolName = "Richtungsanzeiger";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Richtungsanzeiger.svg"));
            tracks->setCursor(cursor_default);
        }else if(ui->checkBox_Stumpfgleis->isChecked()){
            selectedSymbolName = "Stumpfgleis";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Stumpfgleis.svg"));
            tracks->setCursor(cursor_default);
        }else{
            selectedSymbolName = "MTafel";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/MTafel.svg"));
            tracks->setCursor(cursor_default);
        }
    }
}


void QGraphicsSymbolContainer::on_pushButton_Nachbarzentrale_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Nachbarzentrale"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Nachbarzentrale";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Nachbarzentrale.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_Nachschieben_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Nachschieben"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Nachschieben";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Nachschieben.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_Oberirdischer_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Oberirdischer"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Oberirdischer";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Oberirdischer.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_Rangierhalttafel_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Rangierhalttafel"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Rangierhalttafel";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Rangierhalttafel.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_Rautentafel_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Rautentafel"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Rautentafel";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Rautentafel.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pb_reflektierenden_clicked()
{
    if (symbolIsSelected && (selectedSymbolName == "aktivengelben" || selectedSymbolName == "reflektierenden")){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        if(ui->checkBox_reflektierenden->isChecked()){
            selectedSymbolName = "aktivengelben";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/aktivengelben.svg"));
            tracks->setCursor(cursor_default);
        }else{
            selectedSymbolName = "reflektierenden";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/reflektierenden.svg"));
            tracks->setCursor(cursor_default);
        }
    }
}


void QGraphicsSymbolContainer::on_pushButton_Richtungspfeilmaske_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Richtungspfeilmaske"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Richtungspfeilmaske";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Richtungspfeilmaske.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_Schachbretttafel_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Schachbretttafel"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Schachbretttafel";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Schachbretttafel.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_Schrankenantrieb_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Schrankenantrieb"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Schrankenantrieb";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Schrankenantrieb.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_SchrankenbaumRechteck_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "SchrankenbaumRechteck"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "SchrankenbaumRechteck";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/SchrankenbaumRechteck.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_Seitenlichtzeichen_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Seitenlichtzeichen"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Seitenlichtzeichen";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Seitenlichtzeichen.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_SiBetonschalthaus_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "SiBetonschalthaus"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "SiBetonschalthaus";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/SiBetonschalthaus.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_SignalElOne_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "SignalElOne"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "SignalElOne";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/SignalElOne.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_SignalElTwo_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "SignalElTwo"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "SignalElTwo";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/SignalElTwo.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pb_Speisegerat_clicked()
{
    if (symbolIsSelected && (selectedSymbolName == "Signalhaltmelder" ||selectedSymbolName == "Sperrsignal"
                             || selectedSymbolName == "SperrsignalKennlicht" || selectedSymbolName == "Speisegerat")){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        if(ui->checkBox_Signalhaltmelder->isChecked()){
            selectedSymbolName = "Signalhaltmelder";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Signalhaltmelder.svg"));
            tracks->setCursor(cursor_default);
        }else if(ui->checkBox_Sperrsignal->isChecked()){
            selectedSymbolName = "Sperrsignal";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Sperrsignal.svg"));
            tracks->setCursor(cursor_default);
        }else if(ui->checkBox_SperrsignalKennlicht->isChecked()){
            selectedSymbolName = "SperrsignalKennlicht";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/SperrsignalKennlicht.svg"));
            tracks->setCursor(cursor_default);
        }else{
            selectedSymbolName = "Speisegerat";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Speisegerat.svg"));
            tracks->setCursor(cursor_default);
        }
    }
}


void QGraphicsSymbolContainer::on_pushButton_StrasensignalmitBlinklicht_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "StrasensignalmitBlinklicht"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "StrasensignalmitBlinklicht";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/StrasensignalmitBlinklicht.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_Strassensignal_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Strassensignal"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Strassensignal";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Strassensignal.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_Trapeztafel_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Trapeztafel"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Trapeztafel";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Trapeztafel.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_uberspannteGleise_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "uberspannteGleise"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "uberspannteGleise";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/uberspannteGleise.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_Uberwachungslampe_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Uberwachungslampe"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Uberwachungslampe";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Uberwachungslampe.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_uberwachungssignal_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "uberwachungssignal"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "uberwachungssignal";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/uberwachungssignal.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_Verstarker_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Verstarker"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Verstarker";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Verstarker.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_VorsichtsignalHauptsignalschirm_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "VorsichtsignalHauptsignalschirm"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "VorsichtsignalHauptsignalschirm";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/VorsichtsignalHauptsignalschirm.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_vorstellwerksbedientVorsignalwiederholer_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "vorstellwerksbedientVorsignalwiederholer"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "vorstellwerksbedientVorsignalwiederholer";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/vorstellwerksbedientVorsignalwiederholer.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_Warntafel_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Warntafel"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Warntafel";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Warntafel.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_Windmeldeanlage_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Windmeldeanlage"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Windmeldeanlage";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Windmeldeanlage.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_Zahlpfeile_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Zahlpfeile"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Zahlpfeile";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Zahlpfeile.svg"));
        tracks->setCursor(cursor_default);
    }
}
void QGraphicsSymbolContainer::on_lbl_zugbedient_clicked()
{
    if (symbolIsSelected && (selectedSymbolName == "stellwerksbedientArrow" || selectedSymbolName == "zugOderStellwerksbedientArrow" || selectedSymbolName == "zugbedientArrow"
                             || selectedSymbolName == "stellwerksbedient" || selectedSymbolName == "zugOderStellwerksbedient" || selectedSymbolName == "zugbedient"
                             || selectedSymbolName == "zugbedientArrow" || selectedSymbolName == "zugbedient")){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        if(ui->chb_zug_arrow->isChecked() && ui->chb_zug_filled->isChecked()){
            selectedSymbolName = "stellwerksbedientArrow";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/stellwerksbedientArrow.svg"));
            tracks->setCursor(cursor_default);
        }else if(ui->chb_zug_arrow->isChecked() && ui->chb_zug_partial->isChecked()){
            selectedSymbolName = "zugOderStellwerksbedientArrow";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/zugOderStellwerksbedientArrow.svg"));
            tracks->setCursor(cursor_default);
        }else if (ui->chb_zug_arrow->isChecked() && ui->chb_zug_nofill->isChecked()){
            selectedSymbolName = "zugbedientArrow";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/zugbedientArrow.svg"));
            tracks->setCursor(cursor_default);
        }else if (ui->chb_zug_filled->isChecked()){
            selectedSymbolName = "stellwerksbedient";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/stellwerksbedient.svg"));
            tracks->setCursor(cursor_default);
        }else if (ui->chb_zug_partial->isChecked()){
            selectedSymbolName = "zugOderStellwerksbedient";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/zugOderStellwerksbedient.svg"));
            tracks->setCursor(cursor_default);
        } else if (ui->chb_zug_nofill->isChecked()){
            selectedSymbolName = "zugbedient";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/zugbedient.svg"));
            tracks->setCursor(cursor_default);
        }
        else if (ui->chb_zug_arrow->isChecked()){
            selectedSymbolName = "zugbedientArrow";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/zugbedientArrow.svg"));
            tracks->setCursor(cursor_default);
        }
        else{
            selectedSymbolName = "zugbedient";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/zugbedient.svg"));
            tracks->setCursor(cursor_default);
        }
    }
}


void QGraphicsSymbolContainer::on_pushbutton_vorZugbedient_clicked()
{
    if (symbolIsSelected && (selectedSymbolName == "vorStellwerksbedientArrow" || selectedSymbolName == "vorZugoderStellwerksbedientArrow"
                             || selectedSymbolName == "vorZugoderStellwerksbedient" || selectedSymbolName == "vorStellwerksbedient"
                             || selectedSymbolName == "vorZugbedientArrow" || selectedSymbolName == "vorZugbedient")){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        if(ui->checkBox_Arrow->isChecked() && ui->checkBox_vorStellwerksbedient->isChecked()){
            selectedSymbolName = "vorStellwerksbedientArrow";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/vorStellwerksbedientArrow.svg"));
            tracks->setCursor(cursor_default);
        }else if(ui->checkBox_Arrow->isChecked() && ui->checkBox_vorZugoderStellwerksbedient->isChecked()){
            selectedSymbolName = "vorZugoderStellwerksbedientArrow";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/vorZugoderStellwerksbedientArrow.svg"));
            tracks->setCursor(cursor_default);
        }else if (ui->checkBox_vorZugoderStellwerksbedient->isChecked()){
            selectedSymbolName = "vorZugoderStellwerksbedient";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/vorZugoderStellwerksbedient.svg"));
            tracks->setCursor(cursor_default);
        }else if (ui->checkBox_vorStellwerksbedient->isChecked()){
            selectedSymbolName = "vorStellwerksbedient";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/vorStellwerksbedient.svg"));
            tracks->setCursor(cursor_default);
        }else if (ui->checkBox_Arrow->isChecked()){
            selectedSymbolName = "vorZugbedientArrow";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/vorZugbedientArrow.svg"));
            tracks->setCursor(cursor_default);
        }
        else{
            selectedSymbolName = "vorZugbedient";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/vorZugbedient.svg"));
            tracks->setCursor(cursor_default);
        }
    }
}


void QGraphicsSymbolContainer::on_pushButton_Zugdeckungssignal_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Zugdeckungssignal"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Zugdeckungssignal";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Zugdeckungssignal.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_Weichenantrieb_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Weichenantrieb"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Weichenantrieb";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Weichenantrieb.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pushButton_Weichensignal_clicked()
{
    if (symbolIsSelected && selectedSymbolName == "Weichensignal"){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        selectedSymbolName = "Weichensignal";
        QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Weichensignal.svg"));
        tracks->setCursor(cursor_default);
    }
}


void QGraphicsSymbolContainer::on_pb_VorsignalbakenFive_clicked()
{
    if (symbolIsSelected && (selectedSymbolName == "VorsignalbakenOne" || selectedSymbolName == "VorsignalbakenTwo"
                             || selectedSymbolName == "VorsignalbakenThree" || selectedSymbolName == "VorsignalbakenFour"
                             || selectedSymbolName == "VorsignalbakenFive")){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        if(ui->checkBox_VorsignalbakenOne->isChecked()){
            selectedSymbolName = "VorsignalbakenOne";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/VorsignalbakenOne.svg"));
            tracks->setCursor(cursor_default);
        }else if(ui->checkBox_VorsignalbakenTwo->isChecked()){
            selectedSymbolName = "VorsignalbakenTwo";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/VorsignalbakenTwo.svg"));
            tracks->setCursor(cursor_default);
        }else if(ui->checkBox_VorsignalbakenThree->isChecked()){
            selectedSymbolName = "VorsignalbakenThree";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/VorsignalbakenThree.svg"));
            tracks->setCursor(cursor_default);
        }else if(ui->checkBox_VorsignalbakenFour->isChecked()){
            selectedSymbolName = "VorsignalbakenFour";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/VorsignalbakenFour.svg"));
            tracks->setCursor(cursor_default);
        }else{
            selectedSymbolName = "VorsignalbakenFive";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/VorsignalbakenFive.svg"));
            tracks->setCursor(cursor_default);
        }
    }
}


void QGraphicsSymbolContainer::on_pb_Kabelschrank_clicked()
{
    if (symbolIsSelected && (selectedSymbolName == "Kabelschrank" || selectedSymbolName == "Vorsignaltafel")){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        if(ui->checkBox_Kabelschrank->isChecked()){
            selectedSymbolName = "Kabelschrank";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Kabelschrank.svg"));
            tracks->setCursor(cursor_default);
        }else{
            selectedSymbolName = "Vorsignaltafel";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Vorsignaltafel.svg"));
            tracks->setCursor(cursor_default);
        }
    }
}


void QGraphicsSymbolContainer::on_pushButton_WartezeichenMain_clicked()
{
    if (symbolIsSelected && (selectedSymbolName == "Wartezeichenmit" || selectedSymbolName == "Wartezeichen")){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        if(ui->checkBox_Wartezeichenmit->isChecked()){
            selectedSymbolName = "Wartezeichenmit";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Wartezeichenmit.svg"));
            tracks->setCursor(cursor_default);
        }else{
            selectedSymbolName = "Wartezeichen";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/Wartezeichen.svg"));
            tracks->setCursor(cursor_default);
        }
    }
}


void QGraphicsSymbolContainer::on_pb_WeitereOne_clicked()
{
    if (symbolIsSelected && (selectedSymbolName == "WeitereTwo" || selectedSymbolName == "WeitereThree" ||
                             selectedSymbolName == "WeitereOne")){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        if(ui->checkBox_WeitereTwo->isChecked()){
            selectedSymbolName = "WeitereTwo";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/WeitereTwo.svg"));
            tracks->setCursor(cursor_default);
        }else if(ui->checkBox_WeitereTwo_2->isChecked()){
            selectedSymbolName = "WeitereThree";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/WeitereThree.svg"));
            tracks->setCursor(cursor_default);
        }else{
            selectedSymbolName = "WeitereOne";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/WeitereOne.svg"));
            tracks->setCursor(cursor_default);
        }
    }
}


void QGraphicsSymbolContainer::on_pb_zweiAktiven_clicked()
{
    if (symbolIsSelected && (selectedSymbolName == "zweiReflektierenden" || selectedSymbolName == "zweiAktiven")){
        symbolIsSelected = !symbolIsSelected;
        selectedSymbolName = "";
        tracks->setCursor(Qt::ArrowCursor);
    } else {
        symbolIsSelected = true;
        if(ui->checkBox_2->isChecked()){
            selectedSymbolName = "zweiReflektierenden";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/zweiReflektierenden.svg"));
            tracks->setCursor(cursor_default);
        }else{
            selectedSymbolName = "zweiAktiven";
            QCursor cursor_default = QCursor(QPixmap(":/icons/assets/qgraphics/zweiAktiven.svg"));
            tracks->setCursor(cursor_default);
        }
    }
}



