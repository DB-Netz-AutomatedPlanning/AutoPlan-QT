#include "tracks.h"
#include "coordinates.h"
#include "symbolcontainer.h"
#include "mainwindow.h"
#include "qgraphicsmainwindow.h"
#include <QGraphicsPathItem>
#include <QPainter>
#include <QPainterPath>
#include <QPointF>
#include <QWheelEvent>
#include <QRegularExpression>


Tracks::Tracks(QWidget *parent) : QGraphicsView(parent), multiplierDone(false), drawGrids(false),
    drawGleiskanten(false),drawGleiskantenDP(false), drawHoehe(false), drawHoeheDP(false), drawKmLine(false),
    drawKmLineDP(false), drawLage(false), drawLageDP(false), drawUberhohung(false), drawUberhohungDP(false)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scale(1, -1);
    setMouseTracking(true);

}

void Tracks::addGleiskanten()
{
    QFile file (projectPath+"/"+projectName+"/temp/Gleiskanten.dbahn");
    if (!file.exists()) return;

    QVector<QVector<float>> vec = allVec(projectPath, projectName, "Gleiskanten.dbahn");
    QList<QString> dir = getDirection();
    int segmentCount =0;

    // To obtain and add the data object to appropriate section
    Coordinates *coord = new Coordinates(projectPath, projectName);
    coord->readCoordinates("Gleiskanten.dbahn");
    std::vector<QMap<QString, QString>> map = coord->getMap();
    int dataSegCount =0;
    int signalKey =0;

    // Add line tracks
    bool isFirstSegment = true;
    foreach (auto val, vec){
        QPainterPath path;
        QPolygonF segment;

        int count =0;
        while (count < static_cast<int>(val.size())){
            segment << QPointF(val[count]*getMultiplierValue(), val[count+1]*getMultiplierValue());
            count =  count +2;
        }
        path.addPolygon(segment);

        if (isFirstSegment){
            gleiskanten_Parent = new QGraphicsPathItem(path);
            if (dir[segmentCount] =="1" || dir[segmentCount] =="2"){
                gleiskanten_Parent->setPen(QPen(Qt::black, 1));
                segmentCount++;                
                gleiskanten_Parent->setData(signalKey, map[dataSegCount].keys() );
                gleiskanten_Parent->setData(signalKey+1, map[dataSegCount].values() );
            } else if (countryCode == "fr"){  // This condition should be removed when there is data about directions
                gleiskanten_Parent->setPen(QPen(Qt::black, 1));      
            }
            else {
                gleiskanten_Parent->setPen(QPen(Qt::black, 0.3));
                segmentCount++;
                gleiskanten_Parent->setData(signalKey, map[dataSegCount].keys() );
                gleiskanten_Parent->setData(signalKey+1, map[dataSegCount].values() );
            }
            gleiskanten_Parent->setToolTip("Gleiskanten_"+QString::number(signalKey));
            signalKey +=2;
            dataSegCount++;
            gleiskanten_Parent->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
            scene()->addItem(gleiskanten_Parent);
            isFirstSegment = !isFirstSegment;
        } else {
            QGraphicsPathItem *gleiskanten = new QGraphicsPathItem(path);
            if (dir[segmentCount] =="1" || dir[segmentCount] =="2"){
                gleiskanten->setPen(QPen(Qt::black, 1));
                segmentCount++;
                gleiskanten->setData(signalKey, map[dataSegCount].keys() );
                gleiskanten->setData(signalKey+1, map[dataSegCount].values() );
            } else if (countryCode == "fr"){  // This condition should be removed when there is data about directions
                gleiskanten->setPen(QPen(Qt::black, 1));
            } else {
                gleiskanten->setPen(QPen(Qt::black, 0.3));
                segmentCount++;
                gleiskanten->setData(signalKey, map[dataSegCount].keys() );
                gleiskanten->setData(signalKey+1, map[dataSegCount].values() );
            }
            gleiskanten->setToolTip("Gleiskanten_"+QString::number(signalKey));
            signalKey +=2;
            dataSegCount++;
            gleiskanten->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
            gleiskanten->setParentItem(gleiskanten_Parent);
        }
    }

    if (!parentItems.contains("gleiskanten_Parent")) parentItems << "gleiskanten_Parent";

    // Add DataPoints
    bool isFirstPoint = true;
    foreach (auto val, vec){

        //QPointF point;
        int count =0;
        while (count < static_cast<int>(val.size())){
            if (isFirstPoint){
                QPainterPath path;
                path.addEllipse(val[count]*getMultiplierValue(), val[count+1]*getMultiplierValue(),1,1);
                gleiskantenDP_Parent = new QGraphicsPathItem(path);

                gleiskantenDP_Parent->setPen(QPen(Qt::blue));
                gleiskantenDP_Parent->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
                gleiskantenDP_Parent->setToolTip("x: "+QString::number(val[count])+"\n y: "+QString::number(val[count+1]));
                scene()->addItem(gleiskantenDP_Parent);
                isFirstPoint = !isFirstPoint;
            } else {
                QPainterPath path;
                path.addEllipse(val[count]*getMultiplierValue(), val[count+1]*getMultiplierValue(),1,1);
                QGraphicsPathItem *gleiskantenDP = new QGraphicsPathItem(path);
                gleiskantenDP->setPen(QPen(Qt::blue));
                gleiskantenDP->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
                gleiskantenDP->setToolTip("x: "+QString::number(val[count])+"\n y: "+QString::number(val[count+1]));
                gleiskantenDP->setParentItem(gleiskantenDP_Parent);
            }
            count =  count +2;
        }
    }
    if (!parentItems.contains("gleiskantenDP_Parent")) parentItems << "gleiskantenDP_Parent";
    gleiskanten_Parent->setVisible(getDrawGleiskanten());
    gleiskantenDP_Parent->setVisible(getDrawGleiskantenDP());
}


void Tracks::addHoehe()
{
    QFile file (projectPath+"/"+projectName+"/temp/Entwurfselement_HO.dbahn");
    if (!file.exists()) return;

    QVector<QVector<float>> vec = allVec(projectPath, projectName, "Entwurfselement_HO.dbahn");

    QList<QString> dir = getDirection();
    int segmentCount =0;

    // To obtain and add the data object to appropriate section
    Coordinates *coord = new Coordinates(projectPath, projectName);
    coord->readCoordinates("Entwurfselement_HO.dbahn");
    std::vector<QMap<QString, QString>> map = coord->getMap();
    int dataSegCount =0;
    int signalKey =0;

    // Add line tracks
    bool isFirstSegment = true;
    foreach (auto val, vec){
        QPainterPath path;
        QPolygonF segment;

        int count =0;
        while (count < static_cast<int>(val.size())){
            segment << QPointF(val[count]*getMultiplierValue(), val[count+1]*getMultiplierValue());
            count =  count +2;
        }
        path.addPolygon(segment);

        if (isFirstSegment){
            hoehe_Parent = new QGraphicsPathItem(path);
            if (dir[segmentCount] =="1" || dir[segmentCount] =="2"){
                hoehe_Parent->setPen(QPen(Qt::black, 1));
                segmentCount++;

            } else {
                hoehe_Parent->setPen(QPen(Qt::black, 0.3));
                segmentCount++;
            }
            hoehe_Parent->setData(signalKey, map[dataSegCount].keys() );
            hoehe_Parent->setData(signalKey+1, map[dataSegCount].values() );

            hoehe_Parent->setToolTip("Hoehe_"+QString::number(signalKey));
            signalKey +=2;
            dataSegCount++;
            hoehe_Parent->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
            scene()->addItem(hoehe_Parent);
            isFirstSegment = !isFirstSegment;
        } else {
            QGraphicsPathItem *hoehe = new QGraphicsPathItem(path);
            if (dir[segmentCount] =="1" || dir[segmentCount] =="2"){
                hoehe->setPen(QPen(Qt::black, 1));
                segmentCount++;
            } else {
                hoehe->setPen(QPen(Qt::black, 0.3));
                segmentCount++;
            }
            hoehe->setData(signalKey, map[dataSegCount].keys() );
            hoehe->setData(signalKey+1, map[dataSegCount].values() );

            hoehe->setToolTip("Hoehe_"+QString::number(signalKey));
            signalKey +=2;
            dataSegCount++;
            hoehe->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
            hoehe->setParentItem(hoehe_Parent);
        }
    }
    if (!parentItems.contains("hoehe_Parent")) parentItems << "hoehe_Parent";

    // Add DataPoints
    bool isFirstPoint = true;
    foreach (auto val, vec){

        //QPointF point;
        int count =0;
        while (count < static_cast<int>(val.size())){
            if (isFirstPoint){
                QPainterPath path;
                path.addEllipse(val[count]*getMultiplierValue(), val[count+1]*getMultiplierValue(),1,1);
                hoeheDP_Parent = new QGraphicsPathItem(path);
                hoeheDP_Parent->setPen(QPen(Qt::blue));
                hoeheDP_Parent->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
                hoeheDP_Parent->setToolTip("x: "+QString::number(val[count])+"\n y: "+QString::number(val[count+1]));
                scene()->addItem(hoeheDP_Parent);
                isFirstPoint = !isFirstPoint;
            } else {
                QPainterPath path;
                path.addEllipse(val[count]*getMultiplierValue(), val[count+1]*getMultiplierValue(),1,1);
                //                path.addEllipse(val[count], val[count+1],1,1);
                QGraphicsPathItem *hoeheDP = new QGraphicsPathItem(path);
                hoeheDP->setPen(QPen(Qt::blue));
                hoeheDP->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
                hoeheDP->setToolTip("x: "+QString::number(val[count])+"\ny: "+QString::number(val[count+1]));
                hoeheDP->setParentItem(hoeheDP_Parent);
            }
            count =  count +2;
        }
    }
    if (!parentItems.contains("hoeheDP_Parent")) parentItems << "hoeheDP_Parent";
    hoehe_Parent->setVisible(getDrawHoehe());
    hoeheDP_Parent->setVisible(getDrawHoeheDP());
}

void Tracks::addKMline()
{

    QFile file (projectPath+"/"+projectName+"/temp/Entwurfselement_KM.dbahn");

    if (!file.exists()) return;
    QVector<QVector<float>> vec = allVec(projectPath, projectName, "Entwurfselement_KM.dbahn");

    int dataSegCount=0;

    // To obtain and add the data object to appropriate section
    Coordinates *coord = new Coordinates(projectPath, projectName);
    coord->readCoordinates("Entwurfselement_KM.dbahn");
    std::vector<QMap<QString, QString>> map = coord->getMap();
    int signalKey =0;

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
            kmLine_Parent = new QGraphicsPathItem(path);
            kmLine_Parent->setPen(QPen(Qt::black));
            kmLine_Parent->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
            kmLine_Parent->setData(signalKey, map[dataSegCount].keys() );
            kmLine_Parent->setData(signalKey+1, map[dataSegCount].values() );

            kmLine_Parent->setToolTip("KMLine_"+QString::number(signalKey));
            signalKey +=2;
            dataSegCount++;

            scene()->addItem(kmLine_Parent);
            isFirstSegment = !isFirstSegment;
        } else {
            QGraphicsPathItem *kmLine = new QGraphicsPathItem(path);
            kmLine->setPen(QPen(Qt::black));
            kmLine->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
            kmLine->setData(signalKey, map[dataSegCount].keys() );
            kmLine->setData(signalKey+1, map[dataSegCount].values() );

            kmLine->setToolTip("KMLine_"+QString::number(signalKey));
            signalKey +=2;
            dataSegCount++;
            kmLine->setParentItem(kmLine_Parent);
        }
    }

    if (!parentItems.contains("kmLine_Parent")) parentItems << "kmLine_Parent";

    // Add DataPoints
    bool isFirstPoint = true;
    foreach (auto val, vec){

        //QPointF point;
        int count =0;
        while (count < static_cast<int>(val.size())){
            if (isFirstPoint){
                QPainterPath path;
                path.addEllipse(val[count]*getMultiplierValue(), val[count+1]*getMultiplierValue(),1,1);
                kmLineDP_Parent = new QGraphicsPathItem(path);
                kmLineDP_Parent->setPen(QPen(Qt::blue));
                kmLineDP_Parent->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
                kmLineDP_Parent->setToolTip("x: "+QString::number(val[count])+"\n y: "+QString::number(val[count+1]));
                scene()->addItem(kmLineDP_Parent);
                isFirstPoint = !isFirstPoint;
            } else {
                QPainterPath path;
                path.addEllipse(val[count]*getMultiplierValue(), val[count+1]*getMultiplierValue(),1,1);
                //                path.addEllipse(val[count], val[count+1],1,1);
                QGraphicsPathItem *kmLineDP = new QGraphicsPathItem(path);
                kmLineDP->setPen(QPen(Qt::blue));
                kmLineDP->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
                kmLineDP->setToolTip("x: "+QString::number(val[count])+"\n y: "+QString::number(val[count+1]));
                kmLineDP->setParentItem(kmLineDP_Parent);
            }
            count =  count +2;
        }
    }
    if (!parentItems.contains("kmLineDP_Parent")) parentItems << "kmLineDP_Parent";
    kmLine_Parent->setVisible(getDrawKmLine());
    kmLineDP_Parent->setVisible(getDrawKmLineDP());
}



void Tracks::addLage()
{
    QFile file (projectPath+"/"+projectName+"/temp/Entwurfselement_LA.dbahn");

    if (!file.exists()) return;
    QVector<QVector<float>> vec = allVec(projectPath, projectName, "Entwurfselement_LA.dbahn");

    QList<QString> dir = getDirection();
    int segmentCount =0;

    // To obtain and add the data object to appropriate section
    Coordinates *coord = new Coordinates(projectPath, projectName);
    coord->readCoordinates("Entwurfselement_LA.dbahn");
    std::vector<QMap<QString, QString>> map = coord->getMap();
    int signalKey =0;
    int dataSegCount =0;

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
            lage_Parent = new QGraphicsPathItem(path);
            if (dir[segmentCount] =="1" || dir[segmentCount] =="2"){
                lage_Parent->setPen(QPen(Qt::black, 1));
                segmentCount++;
            } else {
                lage_Parent->setPen(QPen(Qt::black, 0.3));
                segmentCount++;
            }
            lage_Parent->setData(signalKey, map[dataSegCount].keys() );
            lage_Parent->setData(signalKey+1, map[dataSegCount].values() );

            lage_Parent->setToolTip("Lage_"+QString::number(signalKey));
            signalKey +=2;
            dataSegCount++;
            lage_Parent->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
            scene()->addItem(lage_Parent);
            isFirstSegment = !isFirstSegment;
        } else {
            QGraphicsPathItem *lage = new QGraphicsPathItem(path);

            if (dir[segmentCount] =="1" || dir[segmentCount] =="2"){
                lage->setPen(QPen(Qt::black, 1));
                segmentCount++;
            } else {
                lage->setPen(QPen(Qt::black, 0.3));
                segmentCount++;
            }
            lage->setData(signalKey, map[dataSegCount].keys() );
            lage->setData(signalKey+1, map[dataSegCount].values() );

            lage->setToolTip("Lage_"+QString::number(signalKey));
            signalKey +=2;
            dataSegCount++;
            lage->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
            lage->setParentItem(lage_Parent);
        }
    }

    if (!parentItems.contains("lage_Parent")) parentItems << "lage_Parent";

    // Add DataPoints
    bool isFirstPoint = true;
    foreach (auto val, vec){

        //QPointF point;
        int count =0;
        while (count < static_cast<int>(val.size())){
            if (isFirstPoint){
                QPainterPath path;
                path.addEllipse(val[count]*getMultiplierValue(), val[count+1]*getMultiplierValue(),1,1);
                lageDP_Parent = new QGraphicsPathItem(path);
                lageDP_Parent->setPen(QPen(Qt::blue));
                lageDP_Parent->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
                lageDP_Parent->setToolTip("x: "+QString::number(val[count])+"\n y: "+QString::number(val[count+1]));
                scene()->addItem(lageDP_Parent);
                isFirstPoint = !isFirstPoint;
            } else {
                QPainterPath path;
                path.addEllipse(val[count]*getMultiplierValue(), val[count+1]*getMultiplierValue(),1,1);
                QGraphicsPathItem *lageDP = new QGraphicsPathItem(path);
                lageDP->setPen(QPen(Qt::blue));
                lageDP->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
                lageDP->setToolTip("x: "+QString::number(val[count])+"\n y: "+QString::number(val[count+1]));
                lageDP->setParentItem(lageDP_Parent);
            }
            count =  count +2;
        }
    }
    if (!parentItems.contains("lageDP_Parent")) parentItems << "lageDP_Parent";
    lage_Parent->setVisible(getDrawLage());
    lageDP_Parent->setVisible(getDrawLageDP());
}



void Tracks::addUberhohung()
{
    QFile file (projectPath+"/"+projectName+"/temp/Entwurfselement_UH.dbahn");
    if (!file.exists()) return;

    QVector<QVector<float>> vec = allVec(projectPath, projectName, "Entwurfselement_UH.dbahn");
    QList<QString> dir = getDirection();
    int segmentCount =0;
    // To obtain and add the data object to appropriate section
    Coordinates *coord = new Coordinates(projectPath, projectName);
    coord->readCoordinates("Entwurfselement_UH.dbahn");
    std::vector<QMap<QString, QString>> map = coord->getMap();
    int signalKey =0;
    int dataSegCount =0;

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
            uberhohung_Parent = new QGraphicsPathItem(path);
            if (dir[segmentCount] =="1" || dir[segmentCount] =="2"){
                uberhohung_Parent->setPen(QPen(Qt::black, 1));
                segmentCount++;
            } else {
                uberhohung_Parent->setPen(QPen(Qt::black, 0.3));
                segmentCount++;
            }
            uberhohung_Parent->setData(signalKey, map[dataSegCount].keys() );
            uberhohung_Parent->setData(signalKey+1, map[dataSegCount].values() );
            uberhohung_Parent->setToolTip("Uberhohung_"+QString::number(signalKey));
            signalKey +=2;
            dataSegCount++;
            uberhohung_Parent->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
            scene()->addItem(uberhohung_Parent);
            isFirstSegment = !isFirstSegment;
        } else {
            QGraphicsPathItem *uberhohung = new QGraphicsPathItem(path);
            if (dir[segmentCount] =="1" || dir[segmentCount] =="2"){
                uberhohung->setPen(QPen(Qt::black, 1));
                segmentCount++;
            } else {
                uberhohung->setPen(QPen(Qt::black, 0.3));
                segmentCount++;
            }
            uberhohung->setData(signalKey, map[dataSegCount].keys() );
            uberhohung->setData(signalKey+1, map[dataSegCount].values() );
            uberhohung->setToolTip("Uberhohung_"+QString::number(signalKey));
            signalKey +=2;
            dataSegCount++;
            uberhohung->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
            uberhohung->setParentItem(uberhohung_Parent);
        }
    }

    if (!parentItems.contains("uberhohung_Parent")) parentItems << "uberhohung_Parent";

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
                uberhohungDP_Parent = new QGraphicsPathItem(path);

                uberhohungDP_Parent->setPen(QPen(Qt::blue));
                uberhohungDP_Parent->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
                uberhohungDP_Parent->setToolTip("x: "+QString::number(val[count])+"\n y: "+QString::number(val[count+1]));
                scene()->addItem(uberhohungDP_Parent);
                isFirstPoint = !isFirstPoint;
            } else {
                QPainterPath path;
                path.addEllipse(val[count]*getMultiplierValue(), val[count+1]*getMultiplierValue(),1,1);
                //                path.addEllipse(val[count], val[count+1],1,1);
                QGraphicsPathItem *uberhohungDP = new QGraphicsPathItem(path);
                uberhohungDP->setPen(QPen(Qt::blue));
                uberhohungDP->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
                uberhohungDP->setToolTip("x: "+QString::number(val[count])+"\n y: "+QString::number(val[count+1]));
                uberhohungDP->setParentItem(uberhohungDP_Parent);
            }
            count =  count +2;
        }
    }
    if (!parentItems.contains("uberhohungDP_Parent")) parentItems << "uberhohungDP_Parent";
    uberhohung_Parent->setVisible(getDrawUberhohung());
    uberhohungDP_Parent->setVisible(getDrawUberhohungDP());
}

void Tracks::setBoolParameters()
{
    QFile file (projectPath+"/"+projectName+"/temp/Gleiskanten.dbahn");
    QFile file2 (projectPath+"/"+projectName+"/temp/Entwurfselement_HO.dbahn");
    QFile file3 (projectPath+"/"+projectName+"/temp/Entwurfselement_KM.dbahn");
    QFile file4 (projectPath+"/"+projectName+"/temp/Entwurfselement_UH.dbahn");
    QFile file5 (projectPath+"/"+projectName+"/temp/Entwurfselement_LA.dbahn");
    QFile file6 (projectPath+"/"+projectName+"/temp/Gleisknoten.dbahn");

    drawGleiskanten = file.exists() ? true : false;
    drawHoehe = file2.exists() ? true : false;
    drawKmLine = file3.exists() ? true : false;
    drawUberhohung = file4.exists() ? true : false;
    drawLage = file5.exists() ? true : false;
    //    drawGleisknoten = file6.exists() ? true : false;
}

void Tracks::reload()
{
    setBoolParameters();
    deleteAll();
    updateAll();

}


/*RESET ALL (deleteAll and updateAll...  These functions ensure that all objects drawn on the scene are removed and deleted as
soon as it discovered that the Project path and /or Projetct name changes. It further helps in
calling all relevants functions needed for the re-implementation based on the new data available*/

void Tracks::deleteAll()
{
    if (parentItems.isEmpty()) return;

    if (parentItems.contains("gleiskanten_Parent")){
        scene()->removeItem(gleiskanten_Parent);
        delete gleiskanten_Parent;
        parentItems.remove("gleiskanten_Parent");
    }
    if (parentItems.contains("gleiskantenDP_Parent")){
        scene()->removeItem(gleiskantenDP_Parent);
        delete gleiskantenDP_Parent;
        parentItems.remove("gleiskantenDP_Parent");
    }
    if (parentItems.contains("hoehe_Parent")){
        scene()->removeItem(hoehe_Parent);
        delete hoehe_Parent;
        parentItems.remove("hoehe_Parent");
    }
    if (parentItems.contains("hoeheDP_Parent")){
        scene()->removeItem(hoeheDP_Parent);
        delete hoeheDP_Parent;
        parentItems.remove("hoeheDP_Parent");
    }

    if (parentItems.contains("kmLine_Parent")){
        scene()->removeItem(kmLine_Parent);
        delete kmLine_Parent;
        parentItems.remove("kmLine_Parent");
    }
    if (parentItems.contains("kmLineDP_Parent")){
        scene()->removeItem(kmLineDP_Parent);
        delete kmLineDP_Parent;
        parentItems.remove("kmLineDP_Parent");
    }

    if (parentItems.contains("lage_Parent")){
        scene()->removeItem(lage_Parent);
        delete lage_Parent;
        parentItems.remove("lage_Parent");
    }
    if (parentItems.contains("lageDP_Parent")){
        scene()->removeItem(lageDP_Parent);
        delete lageDP_Parent;
        parentItems.remove("lageDP_Parent");
    }

    if (parentItems.contains("uberhohung_Parent")){
        scene()->removeItem(uberhohung_Parent);
        delete uberhohung_Parent;
        parentItems.remove("uberhohung_Parent");
    }
    if (parentItems.contains("uberhohungDP_Parent")){
        scene()->removeItem(uberhohungDP_Parent);
        delete uberhohungDP_Parent;
        parentItems.remove("uberhohungDP_Parent");
    }
}


void Tracks::updateAll()
{
    getUpdateRect();
    getMultiplierEffect();
    addGleiskanten();
    addHoehe();
    addKMline();
    addLage();
    addUberhohung();
}


QVector<QVector<float> > Tracks::allVec(QString pPath, QString pName, QString fileName)
{
    // First get the Directions (RITZ)
    if (fileName != "Gleisknoten.dbahn" && fileName != "Entwurfselement_KM.dbahn" ){
        Coordinates *coord = new Coordinates(pPath, pName);
        coord->readCoordinates(fileName);
        setDirection(coord->getDirection());
    }

    // Then get all the coordinates to be used for each segment plot
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

//QGraphicsItem *Tracks::getSelectedItem()
//{
//    if (scene()->selectedItems().count() >0){
//        return scene()->selectedItems().at(0);
//    }
//    return nullptr;
//}

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

const QList<QString> &Tracks::getDirection() const
{
    return direction;
}

void Tracks::setDirection(const QList<QString> &newDirection)
{
    direction = newDirection;
}

bool Tracks::getDragModeMouse() const
{
    return dragModeMouse;
}

void Tracks::setDragModeMouse()
{
    //    itemInteractWithMouse(!mouseDragMode);
    if (mouseDragMode){
        setDragMode(QGraphicsView::ScrollHandDrag);
        setInteractive(false);
        setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

    }
    else {
        setDragMode(QGraphicsView::NoDrag);
        setInteractive(true);
        setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    }
}

bool Tracks::getDrawLageDP() const
{
    return drawLageDP;
}

void Tracks::setDrawLageDP(bool newDrawLageDP)
{
    QFile file (projectPath+"/"+projectName+"/temp/Entwurfselement_LA.dbahn");

    if (!file.exists()) return;
    if (drawLageDP != newDrawLageDP){
        drawLageDP = newDrawLageDP;
        lageDP_Parent->setVisible(newDrawLageDP);
    }
}

bool Tracks::getDrawUberhohungDP() const
{
    return drawUberhohungDP;
}

void Tracks::setDrawUberhohungDP(bool newDrawUberhohungDP)
{
    QFile file (projectPath+"/"+projectName+"/temp/Entwurfselement_UH.dbahn");
    if (!file.exists()) return;

    if (drawUberhohungDP != newDrawUberhohungDP){
        drawUberhohungDP = newDrawUberhohungDP;
        uberhohungDP_Parent->setVisible(newDrawUberhohungDP);
    }
}

bool Tracks::getDrawUberhohung() const
{
    return drawUberhohung;
}

void Tracks::setDrawUberhohung(bool newDrawUberhohung)
{
    QFile file (projectPath+"/"+projectName+"/temp/Entwurfselement_UH.dbahn");
    if (!file.exists()) return;

    if (drawUberhohung != newDrawUberhohung){
        drawUberhohung = newDrawUberhohung;
        uberhohung_Parent->setVisible(newDrawUberhohung);
    }
}

bool Tracks::getDrawLage() const
{
    return drawLage;
}

void Tracks::setDrawLage(bool newDrawLage)
{;
    QFile file (projectPath+"/"+projectName+"/temp/Entwurfselement_LA.dbahn");
    if (!file.exists()) return;

    if (drawLage != newDrawLage){
        drawLage = newDrawLage;
        lage_Parent->setVisible(newDrawLage);
    }
}

bool Tracks::getDrawKmLineDP() const
{
    return drawKmLineDP;
}

void Tracks::setDrawKmLineDP(bool newDrawKmLineDP)
{
    QFile file (projectPath+"/"+projectName+"/temp/Entwurfselement_KM.dbahn");
    if (!file.exists()) return;

    if (drawKmLineDP != newDrawKmLineDP){
        drawKmLineDP = newDrawKmLineDP;
        kmLineDP_Parent->setVisible(newDrawKmLineDP);
    }
}

bool Tracks::getDrawKmLine() const
{
    return drawKmLine;
}

void Tracks::setDrawKmLine(bool newDrawKmLine)
{
    QFile file (projectPath+"/"+projectName+"/temp/Entwurfselement_KM.dbahn");
    if (!file.exists()) return;

    if (drawKmLine != newDrawKmLine){
        drawKmLine = newDrawKmLine;
        kmLine_Parent->setVisible(newDrawKmLine);
    }
}

bool Tracks::getDrawHoeheDP() const
{
    return drawHoeheDP;
}

void Tracks::setDrawHoeheDP(bool newDrawHoeheDP)
{
    QFile file (projectPath+"/"+projectName+"/temp/Entwurfselement_HO.dbahn");
    if (!file.exists()) return;
    if (drawHoeheDP != newDrawHoeheDP){
        drawHoeheDP = newDrawHoeheDP;
        hoeheDP_Parent->setVisible(newDrawHoeheDP);
    }
}

bool Tracks::getDrawGleiskantenDP() const
{
    return drawGleiskantenDP;
}

void Tracks::setDrawGleiskantenDP(bool newDrawGleiskantenDP)
{
    QFile file (projectPath+"/"+projectName+"/temp/Gleiskanten.dbahn");
    if (!file.exists()) return;
    if (drawGleiskantenDP != newDrawGleiskantenDP){
        drawGleiskantenDP = newDrawGleiskantenDP;
        gleiskantenDP_Parent->setVisible(newDrawGleiskantenDP);
    }
}

bool Tracks::getDrawGleiskanten() const
{
    return drawGleiskanten;
}

void Tracks::setDrawGleiskanten(bool newDrawGleiskanten)
{
    QFile file (projectPath+"/"+projectName+"/temp/Gleiskanten.dbahn");
    if (!file.exists()) return;

    if (drawGleiskanten != newDrawGleiskanten){
        drawGleiskanten = newDrawGleiskanten;
        gleiskanten_Parent->setVisible(newDrawGleiskanten);
    }
}

bool Tracks::getDrawHoehe() const
{
    return drawHoehe;
}

void Tracks::setDrawHoehe(bool newDrawHoehe)
{
    QFile file (projectPath+"/"+projectName+"/temp/Entwurfselement_HO.dbahn");
    if (!file.exists()) return;

    if (drawHoehe != newDrawHoehe){
        drawHoehe = newDrawHoehe;
        hoehe_Parent->setVisible(newDrawHoehe);
    }
}

double Tracks::getYCoord() const
{
    return yCoord;
}

void Tracks::setYCoord(double newYCoord)
{
    yCoord = newYCoord;
}

double Tracks::getXCoord() const
{
    return xCoord;
}

void Tracks::setXCoord(double newXCoord)
{
    xCoord = newXCoord;
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
//    painter->setBrush(QBrush(Qt::yellow, Qt::Dense7Pattern));
//    painter->drawRect(getUsedRect()[0], getUsedRect()[1], getUsedRect()[2],
//            getUsedRect()[3]);
    getSegementObjects();
    //qDebug() << getUsedRect()[0]<<" .. " <<getUsedRect()[1]<<" .. "<< getUsedRect()[2]<< "  .. "<< getUsedRect()[3];

    painter->restore();
   // qApp->processEvents();
    update();
}


void Tracks::drawForeground(QPainter *painter, const QRectF &rect)
{
  //  getSegementObjects();
    if (drawGrids){
        painter->save();
        painter->setPen(QColor(95,52,21,90));

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

void Tracks::wheelEvent(QWheelEvent *event)
{
    if (event->modifiers() & Qt::ControlModifier) {

        const ViewportAnchor anchor = transformationAnchor();
        setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        if (mouseDragMode) setTransformationAnchor(QGraphicsView::AnchorViewCenter);

        //        setTransformationAnchor(QGraphicsView::AnchorViewCenter);
        int angleY = event->angleDelta().y();
        int angleX = event->angleDelta().x();
        qreal factor;
        factor = (angleX > 0 || angleY >0) ? 1.1 : 0.9;
        scale(factor, factor);
        setTransformationAnchor(anchor);
        //        setTransformationAnchor( QGraphicsView::AnchorViewCenter);
    } else {
        QGraphicsView::wheelEvent(event);
    }
}

void Tracks::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left) rotate(1);
    else if(event->key() == Qt::Key_Right) rotate(-1);

    if((event->key() == Qt::Key_Delete))
    {
        foreach (QGraphicsItem *item, scene()->selectedItems()) {
            QString toolTip = item->toolTip();
            QStringList breakToolTip = toolTip.split(QRegularExpression("_"));
            qInfo() << breakToolTip[0];
            if(breakToolTip[0].isEmpty()){
                scene()->removeItem(item);
                delete item;
            }else{

            }

        }
    }
}

//void Tracks::mousePressEvent(QMouseEvent *event)
//{


   // getSegementObjects();

//    if (event->button() == Qt::RightButton){
//        qDebug() << "Mouse Clicked : "<< event->pos();
//        QPointF sceneCoord = mapToScene(event->pos());
//        setXCoord(sceneCoord.x()/getMultiplierValue());
//        setYCoord(sceneCoord.y()/getMultiplierValue());
//    } else {
//        setXCoord(0);
//        setYCoord(0);
//    }

//    qDebug()<< "X : " << getXCoord();
//    qDebug()<< "Y : " << getYCoord();


//}

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
    QFile file (projectPath+"/"+projectName+"/temp/Gleiskanten.dbahn");
    QFile file2 (projectPath+"/"+projectName+"/temp/Entwurfselement_HO.dbahn");
    QFile file3 (projectPath+"/"+projectName+"/temp/Entwurfselement_KM.dbahn");
    QFile file4 (projectPath+"/"+projectName+"/temp/Entwurfselement_UH.dbahn");
    QFile file5 (projectPath+"/"+projectName+"/temp/Entwurfselement_LA.dbahn");
    QFile file6 (projectPath+"/"+projectName+"/temp/Gleisknoten.dbahn");

    if (file.exists()){
        QVector<QVector<float> > kanten = allVec(projectPath, projectName, "Gleiskanten.dbahn");
        multiplierEffect(kanten[0][0], kanten[0][1]);
    }
    if (file2.exists()){
        QVector<QVector<float> > ho = allVec(projectPath, projectName, "Entwurfselement_HO.dbahn");
        multiplierEffect(ho[0][0], ho[0][1]);
    }
    if (file3.exists()){
        QVector<QVector<float> > km = allVec(projectPath, projectName, "Entwurfselement_KM.dbahn");
        multiplierEffect(km[0][0], km[0][1]);
    }
    if (file4.exists()){
        QVector<QVector<float> > uh = allVec(projectPath, projectName, "Entwurfselement_UH.dbahn");
        multiplierEffect(uh[0][0], uh[0][1]);
    }
    if (file5.exists()){
        QVector<QVector<float> > la = allVec(projectPath, projectName, "Entwurfselement_LA.dbahn");
        multiplierEffect(la[0][0], la[0][1]);
    }
    if (file6.exists()){
        std::vector<float>  knoten = allVecKnoten(projectPath, projectName, "Gleisknoten.dbahn");
        multiplierEffect(knoten[0], knoten[1]);
    }
    qDebug()<< "Multiply"<< this->getMultiplierValue();
}


void Tracks::getUpdateRect()
{
    QFile file (projectPath+"/"+projectName+"/temp/Gleiskanten.dbahn");
    QFile file2 (projectPath+"/"+projectName+"/temp/Entwurfselement_HO.dbahn");
    QFile file3 (projectPath+"/"+projectName+"/temp/Entwurfselement_KM.dbahn");
    QFile file4 (projectPath+"/"+projectName+"/temp/Entwurfselement_UH.dbahn");
    QFile file5 (projectPath+"/"+projectName+"/temp/Entwurfselement_LA.dbahn");
    QFile file6 (projectPath+"/"+projectName+"/temp/Gleisknoten.dbahn");

    getMultiplierEffect();    // in preparation to use the value
    if (file.exists()){
        std::vector<float>vec = unsegmentedVec(projectPath, projectName, "Gleiskanten.dbahn");
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
    if (file2.exists()){
        std::vector<float>vec = unsegmentedVec(projectPath, projectName, "Entwurfselement_HO.dbahn");
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
        std::vector<float>vec = unsegmentedVec(projectPath, projectName, "Entwurfselement_KM.dbahn");
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
        std::vector<float>vec = unsegmentedVec(projectPath, projectName, "Entwurfselement_UH.dbahn");
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
        std::vector<float>vec = unsegmentedVec(projectPath, projectName, "Entwurfselement_LA.dbahn");
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
        std::vector<float>vec = unsegmentedVec(projectPath, projectName, "Gleisknoten.dbahn");
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




void Tracks::addSymbol(QString str)
{
    defaultObjectName = str;
    if(str == "stellwerksbedient_arrow"){

        pixmapItem = new QGraphicsPixmapItem(QPixmap(":/icons/assets/qgraphics/stellwerksbedient.svg"));
        pixmapItem->setTransformationMode(Qt::SmoothTransformation);
        pixmapItem->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
        pixmapItem->setPos(getUsedRect()[0] +(getUsedRect()[2]/2) , getUsedRect()[1]+(getUsedRect()[3]/2));

        pixmapItem2 =  new QGraphicsPixmapItem(QPixmap(":/icons/assets/qgraphics/hauptSignalbegriffe.svg"));
        pixmapItem2->setTransformationMode(Qt::SmoothTransformation);
        pixmapItem2->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
        pixmapItem2->setPos(getUsedRect()[0] +(getUsedRect()[2]/2) , getUsedRect()[1]+(getUsedRect()[3]/2));

        group = new QGraphicsItemGroup(0);
        group->setFlags(QGraphicsItemGroup::ItemIsSelectable | QGraphicsItemGroup::ItemIsMovable);

        group->addToGroup(pixmapItem);
        group->addToGroup(pixmapItem2);


        scene()->addItem(group);


    }else{
        glbObjectName = str;
        pixmapItem = new QGraphicsPixmapItem(QPixmap(":/icons/assets/qgraphics/"+str+".svg"));
        pixmapItem->setTransformationMode(Qt::SmoothTransformation);
        pixmapItem->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
        pixmapItem->setPos(getUsedRect()[0] +(getUsedRect()[2]/2) , getUsedRect()[1]+(getUsedRect()[3]/2));
      //  pixmapItem->setToolTip(str);
        scene()->addItem(pixmapItem);
    }

}
void Tracks :: sceneSelectedItems(int degree){

        //QPointF offset = group->sceneBoundingRect().center();
        //QTransform transform;
       // transform.translate(offset.x(),offset.y());
        //transform.rotate(degree);
        //transform.translate(-offset.x(),-offset.y());
        //group->setTransform(transform);

    foreach (QGraphicsItem *item, scene()->selectedItems()) {



        foreach (QGraphicsItem *item, scene()->selectedItems()) {
            QString toolTip = item->toolTip();
            QStringList breakToolTip = toolTip.split(QRegularExpression("_"));
            qInfo() << breakToolTip[0];
            if(breakToolTip[0].isEmpty()){
                 item->setRotation(degree);


            }else{

            }

        }


    }
   // group = scene()->createItemGroup(scene()->selectedItems());
    //QPointF offset = group->sceneBoundingRect().center();
    //QTransform transform;
    //transform.translate(offset.x(),offset.y());
    //transform.rotate(degree);
    //transform.translate(-offset.x(),-offset.y());
    //group->setTransform(transform);

}

void Tracks::addAutomateSignal(QString name, QPointF location, double angle, QString type,
                               QString position, QString latDist, QString orientation, QString direction)
{
    QGraphicsPixmapItem *signal = new QGraphicsPixmapItem(QPixmap(":/icons/assets/qgraphics/"+name+".svg"));
    signal->setTransformationMode(Qt::SmoothTransformation);
    signal->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    signal->setToolTip(" DB Signal Function : " +type+"\n Coordinate: "+QString::number(location.x())+" , "+QString::number(location.y())+
                       "\n Linear Coordinate(Km): "+ position+ "\n Lateral Dist: "+latDist+ "\n Lateral Side: "+orientation+ "\n Direction: "+direction);

    signal->setPos(location*getMultiplierValue());
    signal->setRotation(angle);
    scene()->addItem(signal);
}

void Tracks::getSegementObjects()
{
    kantenID = "";
    kantenLAENGE_ENT = "";
    kantenRIKZ = "";
    kantenRIKZ_L="";
    kantenSTATUS="";

    kmID ="";
    kmSTRECKENR ="";
    kmEELK_ELTYP ="";
    kmEELK_PARAM ="";
    kmEELK_PAR_1 ="";
    kmEELK_PAR_2 = "";
    kmKM_A_TEXT ="";
    kmKM_E_TEXT ="";

    hoID ="";
    hoPAD_A ="";
    hoELTYP ="";
    hoELTYP_L ="";
    hoPARAM1 ="";
     hoPARAM2 ="";
     hoPARAM3 ="";
     hoPARAM4 ="";
     hoRIKZ="";
     hoRIKZ_L="";
     hoKM_A_KM="";
     hoKM_A_M="";
     hoKM_E_KM="";
     hoKM_E_M="";
     hoHOEHE_A="";
     hoHOEHE_E="";

     //LA Variables
     laID="";
      laPAD_A="";
      laPAD_E="";
      laELTYP="";
      laELTYP_L="";
      laPARAM1="";
      laPARAM2="";
      laPARAM3="";
      laPARAM4="";
      laPARAM4_L="";
      laWINKEL_ANF="";
      laRIKZ="";
      laRIKZ_L="";
      laKM_A_KM="";
      laKM_A_M="";
      laKM_E_KM="";
      laKM_E_M="";

     //UH Variables
      uhID="";
      uhPAD_A="";
      uhPAD_E="";
      uhELTYP="";
      uhELTYP_L="";
      uhPARAM1="";
      uhPARAM2="";
      uhPARAM3="";
      uhPARAM4="";
      uhRIKZ="";
      uhRIKZ_L="";
      uhKM_A_KM="";
      uhKM_A_M="";
      uhKM_E_KM="";
      uhKM_E_M="";

     //KNOTEN Variables
      knotenID="";
      kntKNOTENNAME="";
      kntKNOTENBESC="";
      kntTYP="";
      kntTYP_L="";
      kntSTATUS="";
      kntKM_KM="";
      kntKM_M="";



    if (scene()->selectedItems().count() >0){
        QGraphicsItem *item = scene()->selectedItems()[0];
       // foreach (QGraphicsItem *item, scene()->selectedItems()){
            QString toolTip = item->toolTip();
            QStringList breakToolTip;
            if (!toolTip.isNull() || !toolTip.isEmpty()){
                 breakToolTip = toolTip.split(QRegularExpression("_"));

                 if (breakToolTip.length()==2 && isTrack(breakToolTip[0])){
                         QList keyKanten = item->data(breakToolTip[1].toInt()).toStringList();
                         QList valKanten = item->data(breakToolTip[1].toInt()+1).toStringList();
                         QString name = breakToolTip[0];
                         extractData(name, keyKanten, valKanten);
                 }

            }

       // }
    }
}

bool Tracks::isTrack(QString name)
{
    nameOfTrack = name;
    if (name == "Gleiskanten" ){
          rightPanelTable = 2;
          return true;
    }else if (name == "Gleisknoten"){
          rightPanelTable = 1;
          return true;
    }else if(name == "KMLine"){
          rightPanelTable = 4;

          return true;
    }else if(name == "Lage"){
          rightPanelTable = 6;
          return true;
    }else if(name == "Uberhohung"){
          rightPanelTable = 5;
          return true;
    }else if(name == "Hoehe"){
          rightPanelTable = 3;
          return true;
    }else{

    }
    return false;
}



void Tracks::extractData(QString name, QStringList keyKanten, QStringList valKanten){
    nameOfTrack = name;
    if(name == "Gleiskanten"){
        for(int i = 0; i < keyKanten.count(); i++){
            if(keyKanten[i] == "ID"){
                kantenID = valKanten[i];
            } else if(keyKanten[i] == "LAENGE_ENT"){
                kantenLAENGE_ENT = valKanten[i];
            } else if(keyKanten[i] == "RIKZ"){
                kantenRIKZ = valKanten[i];
            } else if(keyKanten[i] == "RIKZ_L"){
                kantenRIKZ_L = valKanten[i];
            } else if(keyKanten[i] == "STATUS"){
                kantenSTATUS = valKanten[i];
            }
        }
    }
    else if(name == "KMLine"){
        for(int i = 0; i < keyKanten.count(); i++){
            if(keyKanten[i] == "ID"){
                kmID = valKanten[i];
            } else if(keyKanten[i] == "STRECKENR"){
                kmSTRECKENR = valKanten[i];
            } else if(keyKanten[i] == "EELK_ELTYP"){
                kmEELK_ELTYP = valKanten[i];
            } else if(keyKanten[i] == "EELK_PARAM"){
                kmEELK_PARAM = valKanten[i];
            } else if(keyKanten[i] == "EELK_PAR_1"){
                kmEELK_PAR_1 = valKanten[i];
            } else if(keyKanten[i] == "EELK_PAR_2"){
                kmEELK_PAR_2 = valKanten[i];
            } else if(keyKanten[i] == "KM_A_TEXT"){
                kmKM_A_TEXT = valKanten[i];
            } else if(keyKanten[i] == "KM_E_TEXT"){
                kmKM_E_TEXT = valKanten[i];
            }
        }
    }
    else if(name == "Hoehe"){
        for(int i = 0; i < keyKanten.count(); i++){
            if(keyKanten[i] == "ID"){
                hoID = valKanten[i];
            } else if(keyKanten[i] == "PAD_A"){
                hoPAD_A = valKanten[i];
            } else if(keyKanten[i] == "ELTYP"){
                hoELTYP = valKanten[i];
            } else if(keyKanten[i] == "ELTYP_L"){
                hoELTYP_L = valKanten[i];
            } else if(keyKanten[i] == "PARAM1"){
                hoPARAM1 = valKanten[i];
            } else if(keyKanten[i] == "PARAM2"){
                hoPARAM2 = valKanten[i];
            } else if(keyKanten[i] == "PARAM3"){
                hoPARAM3 = valKanten[i];
            } else if(keyKanten[i] == "PARAM4"){
                hoPARAM4 = valKanten[i];
            } else if(keyKanten[i] == "RIKZ"){
                hoRIKZ = valKanten[i];
            } else if(keyKanten[i] == "RIKZ_L"){
                hoRIKZ_L = valKanten[i];
            } else if(keyKanten[i] == "KM_A_KM"){
                hoKM_A_KM = valKanten[i];
            } else if(keyKanten[i] == "KM_A_M"){
                hoKM_A_M = valKanten[i];
            } else if(keyKanten[i] == "KM_E_KM"){
                hoKM_E_KM = valKanten[i];
            } else if(keyKanten[i] == "KM_E_M"){
                hoKM_E_M = valKanten[i];
            } else if(keyKanten[i] == "HOEHE_A"){
                hoHOEHE_A = valKanten[i];
            } else if(keyKanten[i] == "HOEHE_E"){
                hoHOEHE_E = valKanten[i];
            }
        }
    }


    else if(name == "Lage"){
        for(int i = 0; i < keyKanten.count(); i++){
            if(keyKanten[i] == "ID"){
                laID = valKanten[i];
            } else if(keyKanten[i] == "PAD_A"){
                laPAD_A = valKanten[i];
            } else if(keyKanten[i] == "PAD_E"){
                laPAD_E = valKanten[i];
            } else if(keyKanten[i] == "ELTYP"){
                laELTYP = valKanten[i];
            } else if(keyKanten[i] == "ELTYP_L"){
                laELTYP_L = valKanten[i];
            } else if(keyKanten[i] == "PARAM1"){
                laPARAM1 = valKanten[i];
            } else if(keyKanten[i] == "PARAM2"){
                laPARAM2 = valKanten[i];
            } else if(keyKanten[i] == "PARAM3"){
                laPARAM3 = valKanten[i];
            } else if(keyKanten[i] == "PARAM4"){
                laPARAM4 = valKanten[i];
            } else if(keyKanten[i] == "PARAM4_L"){
                laPARAM4_L = valKanten[i];
            }else if(keyKanten[i] == "WINKEL_ANF"){
                laWINKEL_ANF = valKanten[i];
            } else if(keyKanten[i] == "RIKZ"){
                laRIKZ = valKanten[i];
            } else if(keyKanten[i] == "RIKZ_L"){
                laRIKZ_L = valKanten[i];
            } else if(keyKanten[i] == "KM_A_KM"){
                laKM_A_KM = valKanten[i];
            } else if(keyKanten[i] == "KM_A_M"){
                laKM_A_M = valKanten[i];
            } else if(keyKanten[i] == "KM_E_KM"){
                laKM_E_KM = valKanten[i];
            } else if(keyKanten[i] == "KM_E_M"){
                laKM_E_M = valKanten[i];
            }
        }
    }

    else if(name == "Uberhohung"){
        for(int i = 0; i < keyKanten.count(); i++){
            if(keyKanten[i] == "ID"){
                uhID = valKanten[i];
            } else if(keyKanten[i] == "PAD_A"){
                uhPAD_A = valKanten[i];
            } else if(keyKanten[i] == "ELTYP"){
                uhPAD_E = valKanten[i];
            } else if(keyKanten[i] == "ELTYP_L"){
                uhELTYP = valKanten[i];
            } else if(keyKanten[i] == "PARAM1"){
                uhELTYP_L = valKanten[i];
            } else if(keyKanten[i] == "PARAM2"){
                uhPARAM1 = valKanten[i];
            } else if(keyKanten[i] == "PARAM3"){
                uhPARAM2 = valKanten[i];
            } else if(keyKanten[i] == "PARAM4"){
                uhPARAM3 = valKanten[i];
            } else if(keyKanten[i] == "RIKZ"){
                uhPARAM4 = valKanten[i];
            } else if(keyKanten[i] == "RIKZ_L"){
                uhRIKZ = valKanten[i];
            } else if(keyKanten[i] == "KM_A_KM"){
                uhRIKZ_L = valKanten[i];
            } else if(keyKanten[i] == "KM_A_M"){
                uhKM_A_KM = valKanten[i];
            } else if(keyKanten[i] == "KM_E_KM"){
                uhKM_A_M = valKanten[i];
            } else if(keyKanten[i] == "KM_E_M"){
                uhKM_E_KM = valKanten[i];
            } else if(keyKanten[i] == "HOEHE_A"){
                uhKM_E_M = valKanten[i];
            }
        }
    }

    else if(name == "Gleisknoten"){
        for(int i = 0; i < keyKanten.count(); i++){
            if(keyKanten[i] == "ID"){
                knotenID = valKanten[i];
            } else if(keyKanten[i] == "KNOTENNAME"){
                kntKNOTENNAME = valKanten[i];
            } else if(keyKanten[i] == "KNOTENBESC"){
                kntKNOTENBESC = valKanten[i];
            } else if(keyKanten[i] == "TYP"){
                kntTYP = valKanten[i];
            } else if(keyKanten[i] == "PATYP_LRAM1"){
                kntTYP_L = valKanten[i];
            } else if(keyKanten[i] == "STATUS"){
                kntSTATUS = valKanten[i];
            } else if(keyKanten[i] == "KM_KM"){
                kntKM_KM = valKanten[i];
            } else if(keyKanten[i] == "KM_M"){
                kntKM_M = valKanten[i];
            }
        }
    }


 // qDebug()<< "ID: "<< kantenID <<"LAENGE_ENT: "<<kantenLAENGE_ENT <<"RIKZ: "<< kantenRIKZ <<"RIKZ_L: " << kantenRIKZ_L << "STATUS: " <<kantenSTATUS;
  //qDebug()<< "Keys: "<< keyKanten;
  //qDebug()<< "Values: "<< valKanten;



}


