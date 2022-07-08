#include "qgraphicsmainwindow.h"
#include "ui_qgraphicsmainwindow.h"
#include "symbolcontainer.h"
#include <QTimer>

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


//    QPalette pal = QPalette();

//    // set black background
//    // Qt::black / "#000000" / "black"
//    pal.setColor(QPalette::Window, Qt::blue);
//    pal.setColor(QPalette::Text, Qt::darkGreen);

//    setAutoFillBackground(true);
//    setPalette(pal);

    scene->setSceneRect(tracks->getUsedRect()[0],tracks->getUsedRect()[1],
            tracks->getUsedRect()[2],tracks->getUsedRect()[3]);
    //    scene->setBackgroundBrush(QBrush(Qt::yellow, Qt::Dense7Pattern));

    tracks->setScene(scene);
    tracks->getMultiplierEffect();

    tracks->addGleiskanten();
    tracks->addHoehe();
    tracks->addKMline();
    tracks->addLage();
    tracks->addUberhohung();
    tracks->addGleisknoten();
    //tracks->addSignals(); // if using euxml and it's available
    tracks->addSignals2();

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
    ui->checkBoxKnotenDP->setChecked(tracks->getDrawGleisknotenDP());

    disableNonDataCheckbox();

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &QGraphicsMainWindow::displayXandYCoord);
    timer->start();
}

QGraphicsMainWindow::~QGraphicsMainWindow()
{
    delete ui;
}

void QGraphicsMainWindow::on_checkBoxGridLine_toggled(bool checked)
{
    tracks->setDrawGrids(checked);
//    qDebug()<< "SceneGeometry: "<<tracks->screen()->geometry();
//    qDebug()<< "SceneRect: "<<tracks->sceneRect();
//    qDebug()<< "SceneHeight: "<<tracks->scene()->height();
//    qDebug()<< "SceneWidth: "<<tracks->scene()->width();
//    tracks->grab(scene->sceneRect().toRect());
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

//void QGraphicsMainWindow::on_rortatebtn_clicked()
//{

//}

void QGraphicsMainWindow::on_horizontalSlider_valueChanged(int value)
{
    tracks->sceneSelectedItems(value);
}

void QGraphicsMainWindow::on_checkBoxKnotenDP_toggled(bool checked)
{
    tracks->setDrawGleisknotenDP(checked);
}

void QGraphicsMainWindow::on_spinBox_RotateView_valueChanged(int arg1)
{
//    QTransform transform;
//    transform.scale(zoomSpinBox->value() /100.00 , zoomSpinBox->value()/100.00 );
//    transform.rotate(rotation_angle);
////    view->setTransform(transform);
//    tracks->setTransform(transform);

    if((arg1 - rotation_angle) > 0) tracks->rotate(5);
    else if((arg1 - rotation_angle) < 0) tracks->rotate(-5);
    rotation_angle = arg1;
}

void QGraphicsMainWindow::displayXandYCoord()
{
    ui->valueXCoord->setText(QString::number(tracks->getXCoord()));
    ui->valueYCoord->setText(QString::number(tracks->getYCoord()));
}

void QGraphicsMainWindow::disableNonDataCheckbox()
{
//    if (!ui->checkBoxKanten->isChecked()){
//        ui->checkBoxKanten->setEnabled(false);
//        ui->checkBoxKantenDP->setEnabled(false);
//    }
    if (!ui->checkBoxHO->isChecked()){
        ui->checkBoxHO->setEnabled(false);
        ui->checkBoxHODP->setEnabled(false);
    }
    if (!ui->checkBoxKM->isChecked()){
        ui->checkBoxKM->setEnabled(false);
        ui->checkBoxKMDP->setEnabled(false);
    }
    if(!ui->checkBoxLA->isChecked()){
        ui->checkBoxLA->setEnabled(false);
        ui->checkBoxLADP->setEnabled(false);
    }
    if(!ui->checkBoxUH->isChecked()){
        ui->checkBoxUH->setEnabled(false);
        ui->checkBoxUHDP->setEnabled(false);
    }
    if (!ui->checkBoxKnotenDP->isChecked()) {
        ui->checkBoxKnotenDP->setEnabled(false);
    }
}
