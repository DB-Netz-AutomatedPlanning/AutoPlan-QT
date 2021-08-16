#include "svgdialogview.h"

#include <QSvgRenderer>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QGraphicsRectItem>
#include <QGraphicsSvgItem>
#include <QPaintEvent>
#include <qmath.h>
#include <QVBoxLayout>
#include <QDockWidget>
#include <QPushButton>
#include <QFrame>
#include <QGridLayout>
#include <QFileDialog>
#include <QCoreApplication>

#include <QSvgGenerator>

SvgDialogView::SvgDialogView(QWidget *parent)
  : QGraphicsView(parent)
  , m_svgItem(nullptr)
  , m_backgroundItem(nullptr)
  , m_renderer(Native)
{


    setScene(new QGraphicsScene(this));
    setTransformationAnchor(AnchorUnderMouse);
    setDragMode(ScrollHandDrag);
    setViewportUpdateMode(FullViewportUpdate);

    // Prepare background check-board pattern

    QPixmap tilePixmap(64, 64);
    tilePixmap.fill(Qt::white);
    QPainter tilePainter(&tilePixmap);
    QColor color(220, 220, 220);
    tilePainter.fillRect(0, 0, 32, 32, color);
    tilePainter.fillRect(32, 32, 32, 32, color);
    tilePainter.end();

    setBackgroundBrush(tilePixmap);

    imgScene = new QGraphicsScene();

   imgItem = new QGraphicsPixmapItem(QPixmap(":/icons/assets/svg/one.svg"));
   imgScene->addItem(imgItem);
   setScene(imgScene);



}


void SvgDialogView::drawBackground(QPainter *p, const QRectF &)
{
    p->save();
    p->resetTransform();
    p->drawTiledPixmap(viewport()->rect(), backgroundBrush().texture());
    p->restore();
}

QSize SvgDialogView::svgSize() const
{
    return m_svgItem ? m_svgItem->boundingRect().size().toSize() : QSize();
}

bool SvgDialogView::openFile(const QString &fileName)
{
    QGraphicsScene *s = scene();

    const bool drawBackground = (m_backgroundItem ? m_backgroundItem->isVisible() : false);

    QScopedPointer<QGraphicsSvgItem> svgItem(new QGraphicsSvgItem(fileName));
    if (!svgItem->renderer()->isValid())
        return false;

    //s->clear();


    resetTransform();

    m_svgItem = svgItem.take();
    m_svgItem->setFlags(QGraphicsItem::ItemClipsToShape);
    m_svgItem->setCacheMode(QGraphicsItem::NoCache);
    m_svgItem->setZValue(0);

    m_backgroundItem = new QGraphicsRectItem(m_svgItem->boundingRect());
    m_backgroundItem->setBrush(Qt::white);
    m_backgroundItem->setPen(Qt::NoPen);
    m_backgroundItem->setVisible(drawBackground);
    m_backgroundItem->setZValue(-1);

    s->addItem(m_backgroundItem);
    s->addItem(m_svgItem);
    qInfo() << "openFile";
    return true;
}



void SvgDialogView::setViewBackground(bool enable)
{
    if (!m_backgroundItem)
          return;

    m_backgroundItem->setVisible(enable);
}


void SvgDialogView::paintEvent(QPaintEvent *event)
{

        QGraphicsView::paintEvent(event);
}


void SvgDialogView::displaySymbol(QString &selectedOption){




    if(selectedOption == "Filled"){
        imgFilled = new QGraphicsPixmapItem(QPixmap(":/icons/assets/svg/halfrect.svg"));
        imgScene->addItem(imgFilled);
    }else if(selectedOption == "noFilled"){
       imgScene->removeItem(imgFilled);
    }
    else if(selectedOption == "Mehr"){
        //halfrect,rectangle , arrow
        imgMehr = new QGraphicsPixmapItem(QPixmap(":/icons/assets/svg/rectangle.svg"));
        imgScene->addItem(imgMehr);
    }else if(selectedOption == "noMehr"){
       imgScene->removeItem(imgMehr);
    }
    else if(selectedOption == "Hauptsignal"){
        imgHs = new QGraphicsPixmapItem(QPixmap(":/icons/assets/svg/square.svg"));
        imgScene->addItem(imgHs);
        }
    else if(selectedOption == "noHauptsignal"){

        imgScene->removeItem(imgHs);
        }
    else if(selectedOption == "Arrow"){
        imgArrow = new QGraphicsPixmapItem(QPixmap(":/icons/assets/svg/arrow.svg"));
        imgScene->addItem(imgArrow);
        }
        else{
            //halfrect,rectangle , arrow
            imgScene->removeItem(imgArrow);
        }




}

void SvgDialogView::saveSVG(){

//    QImage img(1024,768,QImage::Format_ARGB32_Premultiplied);
//    QPainter p(&img);
//    imgScene->render(&p);
//    p.end();
//    img.save("D:/test.svg");


    //imgScene->addRect(QRectF(0, 0, 100, 200), QPen(Qt::black), QBrush(Qt::green));

  //  qDebug() << " Scene has " << scene.items().count() << " items" ;

    QSvgGenerator svgGen;

    svgGen.setFileName( "D:/test.svg" );
    svgGen.setSize(QSize(200, 200));
    svgGen.setViewBox(QRect(0, 0, 200, 200));
    svgGen.setTitle(tr("SVG Generator Example Drawing"));
    svgGen.setDescription(tr("An SVG drawing created by the SVG Generator "
                                "Example provided with Qt."));

    QPainter painter( &svgGen );
    imgScene->render( &painter );
}
