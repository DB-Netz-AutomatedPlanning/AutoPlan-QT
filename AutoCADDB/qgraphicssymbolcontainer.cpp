#include "qgraphicssymbolcontainer.h"
#include "ui_qgraphicssymbolcontainer.h"
#include "symbolcontainer.h"

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

    ui->lbl_stellwerksbedient->setPixmap(*pixmap);
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



