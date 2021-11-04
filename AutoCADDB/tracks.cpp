#include "tracks.h"
#include "coordinates.h"
#include "symbolcontainer.h"
#include <QGraphicsPathItem>
#include <QPainter>


Tracks::Tracks(QWidget *parent) : QGraphicsView(parent), multiplierDone(false), drawGrids(true)
{

}

//Tracks::Object Tracks::getCurrentObject() const
//{
//    return currentObject;
//}

//void Tracks::setCurrentObject(Object newCurrentObject)
//{
//    currentObject = newCurrentObject;
//}

void Tracks::addGleiskanten()
{
    QString pPath = "C:/Users/DR-PHELZ/Documents/pdf";
    QString pName = "Meggen";


//    QVector<QVector<float>> vec = allVec(projectPath, projectName, "Gleiskanten.dbahn");
    QVector<QVector<float>> vec = allVec(pPath, pName, "Gleiskanten.dbahn");

    // Add line tracks
    bool isFirstSegment = true;
    foreach (auto val, vec){
        QPainterPath path;
        QPolygonF segment;

        int count =0;
        while (count < static_cast<int>(val.size())){
            segment << QPointF(val[count]*getMultiplierValue(), val[count+1]*getMultiplierValue());
//            segment << QPointF(val[count], val[count+1]);
            count =  count +2;
        }
        path.addPolygon(segment);

        if (isFirstSegment){
            gleiskanten_Parent = new QGraphicsPathItem(path);
            gleiskanten_Parent->setPen(QPen(Qt::black));
            gleiskanten_Parent->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
            scene()->addItem(gleiskanten_Parent);
            isFirstSegment = !isFirstSegment;
        } else {
            QGraphicsPathItem *gleiskanten = new QGraphicsPathItem(path);
            gleiskanten->setPen(QPen(Qt::black));
            gleiskanten->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
            gleiskanten->setParentItem(gleiskanten_Parent);
        }
    }

    // Add DataPoints
    bool isFirstPoint = true;
    foreach (auto val, vec){

        //QPointF point;
        int count =0;
        while (count < static_cast<int>(val.size())){
            if (isFirstPoint){
                QPainterPath path;
                path.addEllipse(val[count]*getMultiplierValue(), val[count+1]*getMultiplierValue(),1,1);
//                path.addEllipse(val[count], val[count+1],1,1);
                gleiskantenDP_Parent = new QGraphicsPathItem(path);

                gleiskantenDP_Parent->setPen(QPen(Qt::blue));
                gleiskantenDP_Parent->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
                scene()->addItem(gleiskantenDP_Parent);
                isFirstPoint = !isFirstPoint;
            } else {
                QPainterPath path;
                path.addEllipse(val[count]*getMultiplierValue(), val[count+1]*getMultiplierValue(),1,1);
//                path.addEllipse(val[count], val[count+1],1,1);
                QGraphicsPathItem *gleiskantenDP = new QGraphicsPathItem(path);
                gleiskantenDP->setPen(QPen(Qt::blue));
                gleiskantenDP->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
                gleiskantenDP->setParentItem(gleiskantenDP_Parent);
            }
            count =  count +2;
        }
    }
}


QVector<QVector<float> > Tracks::allVec(QString pPath, QString pName, QString fileName)
{
    QVector<QVector<float>> vec;
    if (fileName != "Gleisknoten.dbahn"){

        Coordinates *coord = new Coordinates(pPath, pName);
        coord->readCoordinates(fileName);
        int segmentSize = coord->getSegment().size();

        for (int i=0; i<segmentSize-1; i++){
            vec.push_back(QVector<float>());
            for (int j=coord->getSegment()[i]; j< coord->getSegment()[i+1]; j++){
                vec[i].push_back(coord->getCoordinateLists()[j]);
            }
        }
    }

    return vec;
}

std::vector<float> Tracks::allVecKnoten(QString pPath, QString pName, QString fileName)
{
    std::vector<float> vec;
    if (fileName == "Gleisknoten.dbahn"){
        Coordinates *coord = new Coordinates(pPath, pName);
        coord->readCoordinates(fileName);

        vec = coord->getCoordinateLists();
    }
    return vec;
}

std::vector<float> Tracks::unsegmentedVec(QString pPath, QString pName, QString fileName)
{
    std::vector<float> vec;

    Coordinates *coord = new Coordinates(pPath, pName);
    coord->readCoordinates(fileName);

    vec = coord->getCoordinateLists();

    return vec;

}

void Tracks::multiplierEffect(float x, float y)
{
    if (!multiplierDone){
        int k = 1;
        if (x >= y){
            float value = y;
            while ((value/10) >=1){
                k = k*10;
                value = value / 10;
            }
        } else {
            float value = x;
            while ((value/10) >=1){
                k = k*10;
                value = value / 10;
            }
        }

        int finalEffect = 1000000/k;
        this->setMultiplierValue(finalEffect);
        multiplierDone = !multiplierDone;
    }
}

bool Tracks::getDrawGrids() const
{
    return drawGrids;
}

void Tracks::setDrawGrids(bool newDrawGrids)
{
    if (drawGrids != newDrawGrids){
        drawGrids = newDrawGrids;
        scene()->update();
    }
}

void Tracks::drawBackground(QPainter *painter, const QRectF &rect)
{
    Q_UNUSED(rect);

    painter->save();
    painter->setBrush(QBrush(Qt::yellow, Qt::Dense7Pattern));
    painter->drawRect(getUsedRect()[0], getUsedRect()[1], getUsedRect()[2],
            getUsedRect()[3]);
    qDebug() << getUsedRect()[0]<<" .. " <<getUsedRect()[1]<<" .. "<< getUsedRect()[2]<< "  .. "<< getUsedRect()[3];

    painter->restore();
}


void Tracks::drawForeground(QPainter *painter, const QRectF &rect)
{
    if (drawGrids){
        painter->save();
        painter->setPen(QColor(95,52,21,35));

        for (int i = 0; i< getUsedRect()[2]/50; i++) {
            painter->drawLine(getUsedRect()[0]+(50*i),getUsedRect()[1], getUsedRect()[0]+(50*i),
                    getUsedRect()[1]+getUsedRect()[3] );

        }
        for(int i =0; i < getUsedRect()[3]/50; i++){
            painter->drawLine(getUsedRect()[0],getUsedRect()[1]+(i*50),
                    getUsedRect()[0]+getUsedRect()[2], getUsedRect()[1]+(i*50));
        }
        painter->restore();

    } else {
        QGraphicsView::drawForeground(painter, rect);
    }


}


const QVector<float> &Tracks::getUsedRect() const
{
    return usedRect;
}

void Tracks::setUsedRect(const QVector<float> &newUsedRect)
{
    usedRect = newUsedRect;
}

void Tracks::getMultiplierEffect()
{
    QString pPath = "C:/Users/DR-PHELZ/Documents/pdf";
    QString pName = "Meggen";
    QFile file (pPath+"/"+pName+"/temp/Gleiskanten.dbahn");
    QFile file2 (pPath+"/"+pName+"/temp/Entwurfselement_HO.dbahn");
    QFile file3 (pPath+"/"+pName+"/temp/Entwurfselement_KM.dbahn");
    QFile file4 (pPath+"/"+pName+"/temp/Entwurfselement_UH.dbahn");
    QFile file5 (pPath+"/"+pName+"/temp/Entwurfselement_LA.dbahn");
    QFile file6 (pPath+"/"+pName+"/temp/Gleisknoten.dbahn");

    if (file.exists()){
        QVector<QVector<float> > kanten = allVec(pPath, pName, "Gleiskanten.dbahn");
        multiplierEffect(kanten[0][0], kanten[0][1]);
    }
    if (file2.exists()){
        QVector<QVector<float> > ho = allVec(pPath, pName, "Entwurfselement_HO.dbahn");
        multiplierEffect(ho[0][0], ho[0][1]);
    }
    if (file3.exists()){
        QVector<QVector<float> > km = allVec(pPath, pName, "Entwurfselement_KM.dbahn");
        multiplierEffect(km[0][0], km[0][1]);
    }
    if (file4.exists()){
        QVector<QVector<float> > uh = allVec(pPath, pName, "Entwurfselement_UH.dbahn");
        multiplierEffect(uh[0][0], uh[0][1]);
    }
    if (file5.exists()){
        QVector<QVector<float> > la = allVec(pPath, pName, "Entwurfselement_LA.dbahn");
        multiplierEffect(la[0][0], la[0][1]);
    }
    if (file6.exists()){
        std::vector<float>  knoten = allVecKnoten(pPath, pName, "Gleisknoten.dbahn");
        multiplierEffect(knoten[0], knoten[1]);
    }
    qDebug()<< "Multiply"<< this->getMultiplierValue();
}


void Tracks::getUpdateRect()
{
    QString pPath = "C:/Users/DR-PHELZ/Documents/pdf";
    QString pName = "Meggen";
    QFile file (pPath+"/"+pName+"/temp/Gleiskanten.dbahn");
    QFile file2 (pPath+"/"+pName+"/temp/Entwurfselement_HO.dbahn");
    QFile file3 (pPath+"/"+pName+"/temp/Entwurfselement_KM.dbahn");
    QFile file4 (pPath+"/"+pName+"/temp/Entwurfselement_UH.dbahn");
    QFile file5 (pPath+"/"+pName+"/temp/Entwurfselement_LA.dbahn");
    QFile file6 (pPath+"/"+pName+"/temp/Gleisknoten.dbahn");

    getMultiplierEffect();    // in preparation to use the value

    if (file.exists()){
        std::vector<float>vec = unsegmentedVec(pPath, pName, "Gleiskanten.dbahn");
        QPainterPath path;
        QVector<QPointF> polyPoints;

        for (int i=0; i< static_cast<int>(vec.size()); i=i+2){
            polyPoints << QPointF(vec[i]*getMultiplierValue(), vec[i+1]*getMultiplierValue());
//            polyPoints << QPointF(vec[i], vec[i+1]);
        }
        path.addPolygon(polyPoints);
        QRectF brect = path.boundingRect();
        qDebug() << "Brect " << brect;
        if (brect.left()< boundingRect[0]) boundingRect[0] = brect.left();
        if (brect.top() < boundingRect[1]) boundingRect[1]= brect.top();
        if (brect.width() > boundingRect[2]) boundingRect[2] = brect.width();
        if (brect.height() > boundingRect[3]) boundingRect[3] = brect.height();
        qDebug()<< "BoundingRect" <<boundingRect;
    }
    if (file2.exists()){
        std::vector<float>vec = unsegmentedVec(pPath, pName, "Entwurfselement_HO.dbahn");
        QPainterPath path;
        QVector<QPointF> polyPoints;

        for (int i=0; i< static_cast<int>(vec.size()); i=i+2){
            polyPoints << QPointF(vec[i]*getMultiplierValue(), vec[i+1]*getMultiplierValue());
//            polyPoints << QPointF(vec[i], vec[i+1]);
        }
        path.addPolygon(polyPoints);
        QRectF brect = path.boundingRect();
        if (brect.left()< boundingRect[0]) boundingRect[0] = brect.left();
        if (brect.top() < boundingRect[1]) boundingRect[1]= brect.top();
        if (brect.width() > boundingRect[2]) boundingRect[2] = brect.width();
        if (brect.height() > boundingRect[3]) boundingRect[3] = brect.height();
    }

    if (file3.exists()){
        std::vector<float>vec = unsegmentedVec(pPath, pName, "Entwurfselement_KM.dbahn");
        QPainterPath path;
        QVector<QPointF> polyPoints;

        for (int i=0; i< static_cast<int>(vec.size()); i=i+2){
            polyPoints << QPointF(vec[i]*getMultiplierValue(), vec[i+1]*getMultiplierValue());
//            polyPoints << QPointF(vec[i], vec[i+1]);
        }
        path.addPolygon(polyPoints);
        QRectF brect = path.boundingRect();
        if (brect.left()< boundingRect[0]) boundingRect[0] = brect.left();
        if (brect.top() < boundingRect[1]) boundingRect[1]= brect.top();
        if (brect.width() > boundingRect[2]) boundingRect[2] = brect.width();
        if (brect.height() > boundingRect[3]) boundingRect[3] = brect.height();
    }

    if (file4.exists()){
        std::vector<float>vec = unsegmentedVec(pPath, pName, "Entwurfselement_UH.dbahn");
        QPainterPath path;
        QVector<QPointF> polyPoints;

        for (int i=0; i< static_cast<int>(vec.size()); i=i+2){
            polyPoints << QPointF(vec[i]*getMultiplierValue(), vec[i+1]*getMultiplierValue());
//            polyPoints << QPointF(vec[i], vec[i+1]);
        }
        path.addPolygon(polyPoints);
        QRectF brect = path.boundingRect();
        if (brect.left()< boundingRect[0]) boundingRect[0] = brect.left();
        if (brect.top() < boundingRect[1]) boundingRect[1]= brect.top();
        if (brect.width() > boundingRect[2]) boundingRect[2] = brect.width();
        if (brect.height() > boundingRect[3]) boundingRect[3] = brect.height();
    }

    if (file5.exists()){
        std::vector<float>vec = unsegmentedVec(pPath, pName, "Entwurfselement_LA.dbahn");
        QPainterPath path;
        QVector<QPointF> polyPoints;

        for (int i=0; i< static_cast<int>(vec.size()); i=i+2){
            polyPoints << QPointF(vec[i]*getMultiplierValue(), vec[i+1]*getMultiplierValue());
//            polyPoints << QPointF(vec[i], vec[i+1]);
        }
        path.addPolygon(polyPoints);
        QRectF brect = path.boundingRect();
        if (brect.left()< boundingRect[0]) boundingRect[0] = brect.left();
        if (brect.top() < boundingRect[1]) boundingRect[1]= brect.top();
        if (brect.width() > boundingRect[2]) boundingRect[2] = brect.width();
        if (brect.height() > boundingRect[3]) boundingRect[3] = brect.height();
    }


    if (file6.exists()){
        std::vector<float>vec = unsegmentedVec(pPath, pName, "Gleisknoten.dbahn");
        QPainterPath path;
        QVector<QPointF> polyPoints;

        for (int i=0; i< static_cast<int>(vec.size()); i=i+2){
            polyPoints << QPointF(vec[i]*getMultiplierValue(), vec[i+1]*getMultiplierValue());
//            polyPoints << QPointF(vec[i], vec[i+1]);
        }
        path.addPolygon(polyPoints);
        QRectF brect = path.boundingRect();
        if (brect.left()< boundingRect[0]) boundingRect[0] = brect.left();
        if (brect.top() < boundingRect[1]) boundingRect[1]= brect.top();
        if (brect.width() > boundingRect[2]) boundingRect[2] = brect.width();
        if (brect.height() > boundingRect[3]) boundingRect[3] = brect.height();
    }

    QVector <float> newUsedRect = {boundingRect[0]-boundingRect[2]/2, boundingRect[1]-boundingRect[3]/2,
                                  boundingRect[2]*2, boundingRect[3]*2};
    setUsedRect(newUsedRect);
}



int Tracks::getMultiplierValue() const
{
    return multiplierValue;
}


void Tracks::setMultiplierValue(int newMultiplierValue)
{
    multiplierValue = newMultiplierValue;
}
