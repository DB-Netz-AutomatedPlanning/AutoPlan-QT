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

    void on_chk_stellArrow_clicked();

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

    void on_checkBox_vorZugbedient_clicked();

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

private:
    Ui::QGraphicsSymbolContainer *ui;
    QPixmap *pixmap;
    QPainter *painter;
};

#endif // QGRAPHICSSYMBOLCONTAINER_H
