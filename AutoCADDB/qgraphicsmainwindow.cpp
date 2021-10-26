#include "qgraphicsmainwindow.h"
#include "ui_qgraphicsmainwindow.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QWheelEvent>
#include <QKeyEvent>

QGraphicsMainWindow::QGraphicsMainWindow(QWidget *parent) :
   QGraphicsView(parent)
{

    setDragMode(QGraphicsView::ScrollHandDrag);


    QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(QPixmap(":/icons/assets/fifteenSvgs/Ersatzsignal.svg"));
    pixmapItem->setTransformationMode(Qt::SmoothTransformation);

    QGraphicsScene *scene = new QGraphicsScene();
    scene->addItem(pixmapItem);
    pixmapItem->setFlags(QGraphicsItem::ItemIsMovable);
    setScene(scene);
}

QGraphicsMainWindow::~QGraphicsMainWindow()
{
    delete ui;
}
void QGraphicsMainWindow::keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_Left)
        rotate(1);
      else if(event->key() == Qt::Key_Right)
        rotate(-1);
}

void QGraphicsMainWindow::wheelEvent(QWheelEvent *event)
{

    QPoint numDegrees = event->angleDelta();

    if(numDegrees.y()>0){
             scale(1.25, 1.25);
    }else {
          scale(0.8, 0.8);
    }

}
