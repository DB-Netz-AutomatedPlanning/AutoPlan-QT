#ifndef QGRAPHICSSYMBOLCONTAINER_H
#define QGRAPHICSSYMBOLCONTAINER_H

#include <QDialog>

namespace Ui {
class QGraphicsSymbolContainer;
}

class QGraphicsSymbolContainer : public QDialog
{
    Q_OBJECT

public:
    explicit QGraphicsSymbolContainer(QWidget *parent = nullptr);
    ~QGraphicsSymbolContainer();

private slots:
    void on_pb1_clicked();

    void on_pb2_clicked();

    void on_pb3_clicked();



    void on_pb5_clicked();

    void on_pb6_clicked();

    void on_pb7_clicked();

    void on_pb8_clicked();

    void on_pb9_clicked();

    void on_pb10_clicked();

    void on_pb11_clicked();

    void on_pb12_clicked();

    void on_pb13_clicked();

    void on_pb14_clicked();

    void on_pb15_clicked();

    void on_pb16_clicked();

    void on_pb17_clicked();

    void on_pb18_clicked();

    void on_pb19_clicked();

    void on_pb20_clicked();

    void on_pb21_clicked();

    void on_pb22_clicked();

    void on_pb23_clicked();

    void on_pb24_clicked();

    void on_pb25_clicked();

    void on_pb26_clicked();

    void on_pb27_clicked();

    void on_pb28_clicked();

    void on_pb29_clicked();

    void on_pb30_clicked();

    void on_pb31_clicked();

    void on_pb32_clicked();

    void on_pb33_clicked();

    void on_pb34_clicked();

    void on_pb35_clicked();

    void on_pb36_clicked();

    void on_pb37_clicked();

    void on_pb38_clicked();

    void on_stellwerksbedient_clicked();

    void on_pb_hauptSignalbegriffe_clicked();

    void on_pb_fdurchfarten_clicked();

    void on_pb_FDurchGuterzuge_clicked();

    void on_btn_zugbedient_clicked();

    void on_chb_zug_filled_clicked();

    void on_chb_zug_partial_clicked();

    void on_chb_zug_arrow_clicked();

    void on_chb_zug_nofill_clicked();

    void on_pushButton_vorStellwerksbedient_clicked();

    void on_checkBox_vorStellwerksbedient_clicked();



    void on_checkBox_vorZugoderStellwerksbedient_clicked();

    void on_pushButton_Wartezeichen_clicked();

    void on_checkBox_Wartezeichenmit_clicked();

    void on_pushButton_Achszahlkontakt_clicked();

    void on_checkBox_ZweiBuSchaltkontakt_clicked();

    void on_checkBox_Schaltkontakt_clicked();

    void on_pushButton_Ankundetafel_clicked();

    void on_checkBox_AutomatikETSchild_clicked();

    void on_checkBox_AutomatikHETSchild_clicked();

    void on_checkBox_BuAnkundetafel_clicked();

    void on_checkBox_BuBuTafel_clicked();

    void on_pushButton_balisengruppeLinks_clicked();

    void on_checkBox_balisengruppeLinks_clicked();

    void on_pushButton_BalisengruppeUngesteuertTri_clicked();

    void on_checkBox_BalisengruppeGesteuertTri_clicked();

    void on_pushButton_Bereichskennungswechsel_clicked();

    void on_checkBox_Bereichskennungswechsel_clicked();

    void on_pushButton_BalisengruppeGesteuert_clicked();

    void on_checkBox_BalisengruppeGesteuert_clicked();

    void on_pushButton_EinzelbaliseUngesteuert_clicked();

    void on_checkBox_EinzelbaliseUngesteuert_clicked();

    void on_pushButton_EinzelbaliseRechts_clicked();

    void on_checkBox_EinzelbaliseRechts_clicked();

    void on_pushButton_ETCSstopTafelTwo_clicked();

    void on_checkBox_ETCSstopTafelTwo_clicked();

    void on_pushButton_FahrstrassensymboleReise_clicked();

    void on_checkBox_FahrstrassensymboleRangierfahrten_clicked();

    void on_checkBox_FahrstrassensymboleGuterzuge_clicked();

    void on_checkBox_FahrstrassensymboleDurchGuterzuge_clicked();

    void on_checkBox_FahrstrassensymboleDurchfahrten_clicked();

    void on_pushButton_Festprellbock_clicked();

    void on_checkBox_Bremsprellbock_clicked();

    void on_checkBox_Abklappbarer_clicked();

    void on_checkBox_Anfangsschleife_clicked();

    void on_pushButton_Fruhhaltanzeiger_clicked();

    void on_checkBox_GegengleisanzeigerHauptsignalschirm_clicked();

    void on_checkBox_Geschwindigkeitsanzeiger_clicked();

    void on_checkBox_hauptRichtungsanzeiger_clicked();

    void on_checkBox_HauptGegengleisanzeiger_clicked();

    void on_pushButton_GegengleisanzeigerLichtsignal_clicked();

    void on_checkBox_GegengleisanzeigerLichtsignal_clicked();

    void on_pushButton_Geschwindigkeits_clicked();

    void on_checkBox_Geschwindigkeits_clicked();

    void on_pushButton_GeshLichtsignal_clicked();

    void on_checkBox_GeshLichtsignal_clicked();

    void on_pushButton_gesteuertRechts_clicked();

    void on_checkBox_gesteuertRechts_clicked();

    void on_pushButton_hauptTunneln_clicked();

    void on_checkBox_hauptTunneln_clicked();

    void on_pushButton_Kabelverteiler_clicked();

    void on_checkBox_Kabelverteiler_clicked();

    void on_pushButton_mehraZugbedient_clicked();

    void on_checkBox_mehraZugoderStellwerksbedient_clicked();

    void on_checkBox_mehrasStellwerksbedient_clicked();

    void on_checkBox_mehraausanderemStellbereich_clicked();

    void on_pushButton_MTafel_clicked();

    void on_checkBox_Richtungsanzeiger_clicked();

    void on_checkBox_Stumpfgleis_clicked();

    void on_pushButton_reflektierenden_clicked();

    void on_checkBox_reflektierenden_clicked();

    void on_pushButton_Speisegerat_clicked();

    void on_checkBox_Signalhaltmelder_clicked();

    void on_checkBox_Sperrsignal_clicked();

    void on_checkBox_SperrsignalKennlicht_clicked();

    void on_pushButton_VorsignalbakenFive_clicked();

    void on_checkBox_VorsignalbakenOne_clicked();

    void on_checkBox_VorsignalbakenTwo_clicked();

    void on_checkBox_VorsignalbakenThree_clicked();

    void on_checkBox_VorsignalbakenFour_clicked();

    void on_pushButton_Vorsignaltafel_clicked();

    void on_checkBox_Kabelschrank_clicked();

    void on_pushButton_WeitereOne_clicked();

    void on_checkBox_WeitereTwo_clicked();

    void on_checkBox_WeitereTwo_2_clicked();

    void on_pushButton_zweiAktiven_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_Arrow_clicked();

    void on_checkBox_mehraArrow_clicked();

    void on_pb_FahrstrassensymboleReise_clicked();

    void on_pb_Fahrtanzeiger_clicked();

    void on_pb_Fahrzeugsensor_clicked();

    void on_pb_Festprellbock_clicked();

    void on_pb_Flachstellenortungsanlage_clicked();

    void on_pb_Fruhhaltanzeiger_clicked();

    void on_pb_Funkanruckmelder_clicked();

    void on_pb_FusgangermaskeundAndreaskreuz_clicked();

    void on_pb_GegengleisanzeigerLichtsignal_clicked();

    void on_pb_Geschwindigkeits_clicked();

    void on_pushButton_Geschwindigkeitssignal_clicked();

    void on_pushButton_Geschwindigkeitswechsel_clicked();

    void on_pb_GeshLichtsignal_clicked();

    void on_pb_gesteuertRechts_clicked();

    void on_pushButton_Gleislangen_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_hauptGeschwindigkeitsanzeiger_clicked();

    void on_pushButton_hauptSignalbegriffe_clicked();

    void on_pushButton_HauptsignalIdentificationFour_clicked();

    void on_pushButton_Haltepunkttafel_clicked();

    void on_pb_hauptTunneln_clicked();

    void on_pushButton_Heisslauferortungsanlage_clicked();

    void on_pushButton_Hektometerangabe_clicked();

    void on_pushButton_Kabelformstein_clicked();

    void on_pushButton_Kabelmuffe_clicked();

    void on_pushButton_Kabelschacht_clicked();

    void on_pb_Kabelverteiler_clicked();

    void on_pushButton_Kennzeichentafel_clicked();

    void on_pushButton_KombinationBlockkennzeichen_clicked();

    void on_pushButton_Lautsprechersaule_clicked();

    void on_pushButton_Lichtzeichen_clicked();

    void on_pushButton_LinienleiterschleifeNummer_clicked();

    void on_pushButton_Luftstromungsanlage_clicked();

    void on_pushButton_Magnetschienenkontakt_clicked();

    void on_pb_mehra_clicked();

    void on_pushButton_Merkpfahl_clicked();

    void on_pb_MTafel_clicked();

    void on_pushButton_Nachbarzentrale_clicked();

    void on_pushButton_Nachschieben_clicked();

    void on_pushButton_Oberirdischer_clicked();

    void on_pushButton_Rangierhalttafel_clicked();

    void on_pushButton_Rautentafel_clicked();

    void on_pb_reflektierenden_clicked();

    void on_pushButton_Richtungspfeilmaske_clicked();

    void on_pushButton_Schachbretttafel_clicked();

    void on_pushButton_Schrankenantrieb_clicked();

    void on_pushButton_SchrankenbaumRechteck_clicked();

    void on_pushButton_Seitenlichtzeichen_clicked();

    void on_pushButton_SiBetonschalthaus_clicked();

    void on_pushButton_SignalElOne_clicked();

    void on_pushButton_SignalElTwo_clicked();

    void on_pb_Speisegerat_clicked();

    void on_pushButton_StrasensignalmitBlinklicht_clicked();

    void on_pushButton_Strassensignal_clicked();

    void on_pushButton_Trapeztafel_clicked();

    void on_pushButton_uberspannteGleise_clicked();

    void on_pushButton_Uberwachungslampe_clicked();

    void on_pushButton_uberwachungssignal_clicked();

    void on_pushButton_Verstarker_clicked();

    void on_pushButton_VorsichtsignalHauptsignalschirm_clicked();

    void on_pushButton_vorstellwerksbedientVorsignalwiederholer_clicked();

    void on_pushButton_Warntafel_clicked();

    void on_pushButton_Windmeldeanlage_clicked();

    void on_pushButton_Zahlpfeile_clicked();

    void on_pushButton_Zugdeckungssignal_clicked();

    void on_pushButton_Weichenantrieb_clicked();

    void on_pushButton_Weichensignal_clicked();

    void on_pb_VorsignalbakenFive_clicked();

    void on_pb_Kabelschrank_clicked();

    void on_pushButton_WartezeichenMain_clicked();

    void on_pb_WeitereOne_clicked();

    void on_pb_zweiAktiven_clicked();

    void on_lbl_zugbedient_clicked();

    void on_pushbutton_vorZugbedient_clicked();

private:
    Ui::QGraphicsSymbolContainer *ui;
    QPixmap *pixmap;
    QPainter *painter;
};

#endif // QGRAPHICSSYMBOLCONTAINER_H
