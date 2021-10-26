#include "tracks.h"
#include "coordinates.h"
#include "symbolcontainer.h"
#include <QGraphicsPathItem>

Tracks::Tracks(QWidget *parent) : QGraphicsView(parent)
{

}

Tracks::Object Tracks::getCurrentObject() const
{
    return currentObject;
}

void Tracks::setCurrentObject(Object newCurrentObject)
{
    currentObject = newCurrentObject;
}

void Tracks::addGleiskanten()
{
    Coordinates *coord = new Coordinates(projectPath, projectName);
    coord->readCoordinates("Gleiskanten.dbahn");
    QPainterPath path;

    std::vector<std::vector<float>> vec;
    int segmentSize = coord->getSegment().size();

    for (int i=0; i<segmentSize-1; i++){
        vec.push_back(std::vector<float>());
        for (int j=coord->getSegment()[i]; j< coord->getSegment()[i+1]; j++){
            vec[i].push_back(coord->getCoordinateLists()[j]);
        }
    }

    foreach (auto val, vec){
        //qInfo()<< "{";
        QPolygonF segment;
        int count =0;
        while (count < static_cast<int>(val.size())){
            segment << QPointF(val[count], val[count+1]);
            //qInfo()<< val[count] << "  ,  "<< val[count+1];
            count =  count +2;
        }
        //qInfo()<< "}";
        path.addPolygon(segment);
    }

    QGraphicsPathItem *gleiskanten = new QGraphicsPathItem(path);
    gleiskanten->setPen(QPen(Qt::black, 6));
    gleiskanten->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
    scene()->addItem(gleiskanten);
}
