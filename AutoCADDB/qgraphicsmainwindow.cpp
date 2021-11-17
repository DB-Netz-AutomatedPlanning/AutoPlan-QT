#include "qgraphicsmainwindow.h"
#include "ui_qgraphicsmainwindow.h"
#include "symbolcontainer.h"

//#include <QGraphicsPixmapItem>
//#include <QWheelEvent>
//#include <QKeyEvent>

QGraphicsMainWindow::QGraphicsMainWindow(QWidget *parent) :
   QWidget(parent),
   ui(new Ui::QGraphicsMainWindow)

{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    tracks = new Tracks(this);

    tracks->setBoolParameters();
    tracks->getUpdateRect();

    scene->setSceneRect(tracks->getUsedRect()[0],tracks->getUsedRect()[1],tracks->getUsedRect()[2],tracks->getUsedRect()[3]);
//    scene->setBackgroundBrush(QBrush(Qt::yellow, Qt::Dense7Pattern));


    tracks->setScene(scene);
    tracks->getMultiplierEffect();
    tracks->addGleiskanten();
    tracks->addHoehe();
    tracks->addKMline();
    tracks->addLage();
    tracks->addUberhohung();
    tracks->addSymbol();

    ui->verticalLayout->addWidget(tracks);
    ui->checkBoxGridLine->setChecked(tracks->getDrawGrids());
    ui->checkBoxKanten->setChecked(tracks->getDrawGleiskanten());
    ui->checkBoxKantenDP->setChecked(tracks->getDrawGleiskantenDP());
    ui->checkBoxHO->setChecked(tracks->getDrawHoehe());
    ui->checkBoxHODP->setChecked(tracks->getDrawHoeheDP());
    ui->checkBoxKM->setChecked(tracks->getDrawKmLine());
    ui->checkBoxKMDP->setChecked(tracks->getDrawKmLineDP());
    ui->checkBoxLA->setChecked(tracks->getDrawLage());
    ui->checkBoxLADP->setChecked(tracks->getDrawLageDP());
    ui->checkBoxUH->setChecked(tracks->getDrawUberhohung());
    ui->checkBoxUHDP->setChecked(tracks->getDrawUberhohungDP());






//    setDragMode(QGraphicsView::ScrollHandDrag);
//    QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(QPixmap(":/icons/assets/fifteenSvgs/Ersatzsignal.svg"));
//    pixmapItem->setTransformationMode(Qt::SmoothTransformation);

//    QGraphicsScene *scene = new QGraphicsScene();
//    scene->addItem(pixmapItem);
//    pixmapItem->setFlags(QGraphicsItem::ItemIsMovable);
//    setScene(scene);
}

QGraphicsMainWindow::~QGraphicsMainWindow()
{
    delete ui;
}

//void QGraphicsMainWindow::setMouseDragMode(bool drag)
//{
//    tracks->setDragMode(drag);
//}


//void QGraphicsMainWindow::keyPressEvent(QKeyEvent *event)
//{

//    if(event->key() == Qt::Key_Left)
//        rotate(1);
//      else if(event->key() == Qt::Key_Right)
//        rotate(-1);
//}

//void QGraphicsMainWindow::wheelEvent(QWheelEvent *event)
//{

//    QPoint numDegrees = event->angleDelta();

//    if(numDegrees.y()>0){
//             scale(1.25, 1.25);
//    }else {
//          scale(0.8, 0.8);
//    }

//}

void QGraphicsMainWindow::on_checkBoxGridLine_toggled(bool checked)
{
    tracks->setDrawGrids(checked);
}


void QGraphicsMainWindow::on_checkBoxGridLine2_clicked()
{
//    scene->update();
    ui->checkBoxGridLine->setChecked(tracks->getDrawGrids());
    ui->checkBoxKanten->setChecked(tracks->getDrawGleiskanten());
    ui->checkBoxKantenDP->setChecked(tracks->getDrawGleiskantenDP());
    ui->checkBoxHO->setChecked(tracks->getDrawHoehe());
    ui->checkBoxHODP->setChecked(tracks->getDrawHoeheDP());
    ui->checkBoxKM->setChecked(tracks->getDrawKmLine());
    ui->checkBoxKMDP->setChecked(tracks->getDrawKmLineDP());
    ui->checkBoxLA->setChecked(tracks->getDrawLage());
    ui->checkBoxLADP->setChecked(tracks->getDrawLageDP());
    ui->checkBoxUH->setChecked(tracks->getDrawUberhohung());
    ui->checkBoxUHDP->setChecked(tracks->getDrawUberhohungDP());
    tracks->deleteAll();
    tracks->updateAll();
}


void QGraphicsMainWindow::on_checkBoxKanten_toggled(bool checked)
{
    tracks->setDrawGleiskanten(checked);
}


void QGraphicsMainWindow::on_checkBoxKantenDP_toggled(bool checked)
{
    tracks->setDrawGleiskantenDP(checked);
}


void QGraphicsMainWindow::on_checkBoxHO_toggled(bool checked)
{
    tracks->setDrawHoehe(checked);

}


void QGraphicsMainWindow::on_checkBoxHODP_toggled(bool checked)
{
    tracks->setDrawHoeheDP(checked);

}


void QGraphicsMainWindow::on_checkBoxKM_toggled(bool checked)
{
    tracks->setDrawKmLine(checked);
}


void QGraphicsMainWindow::on_checkBoxKMDP_toggled(bool checked)
{
    tracks->setDrawKmLineDP(checked);
}


void QGraphicsMainWindow::on_checkBoxLA_toggled(bool checked)
{
    tracks->setDrawLage(checked);
}


void QGraphicsMainWindow::on_checkBoxLADP_toggled(bool checked)
{
    tracks->setDrawLageDP(checked);
}


void QGraphicsMainWindow::on_checkBoxUH_toggled(bool checked)
{
    tracks->setDrawUberhohung(checked);
}


void QGraphicsMainWindow::on_checkBoxUHDP_toggled(bool checked)
{
    tracks->setDrawUberhohungDP(checked);
}

