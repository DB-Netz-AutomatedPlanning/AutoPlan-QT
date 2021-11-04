#include "qgraphicsmainwindow.h"
#include "ui_qgraphicsmainwindow.h"

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
    tracks->getUpdateRect();
    scene->setSceneRect(tracks->getUsedRect()[0],tracks->getUsedRect()[1],tracks->getUsedRect()[2],tracks->getUsedRect()[3]);

    tracks->setScene(scene);
    tracks->getMultiplierEffect();
    tracks->addGleiskanten();


    ui->verticalLayout->addWidget(tracks);
    ui->checkBoxGridLine->setChecked(tracks->getDrawGrids());






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

