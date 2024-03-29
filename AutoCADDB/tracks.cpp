#include "tracks.h"
#include "coordinates.h"
#include "readeulynxsignals.h"
#include "symbolcontainer.h"
#include "mainwindow.h"
#include "kmtocoordinate.h"
#include "qgraphicsmainwindow.h"
#include "signalsfromunprocessedjson.h"
#include <QGraphicsPathItem>
#include <QPainter>
#include <QPainterPath>
#include <QPointF>
#include <QWheelEvent>
#include <QRegularExpression>
#include <QSvgRenderer>
#include <QMouseEvent>
#include <QHoverEvent>
#include <QGraphicsSceneHoverEvent>
#include <QFlags>
#include <QInputDialog>
#include <QMenu>
//#include <QGraphicsTextItem>

Tracks::Tracks(QWidget *parent) : QGraphicsView(parent), multiplierDone(false), drawGrids(true),
    drawGleiskanten(false),drawGleiskantenDP(false), drawHoehe(false), drawHoeheDP(false), drawKmLine(false),
    drawKmLineDP(false), drawLage(false), drawLageDP(false), drawUberhohung(false), drawUberhohungDP(false),
    drawGleisknotenDP(false), dark_Mode(false), darkTheme(true), lightRules(false), symbolIsActive(false)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scale(1, -1);
    //    setAttribute(Qt::WA_TransparentForMouseEvents);
    setMouseTracking(true);
    //    setAcceptDrops(true);

//    setContextMenuPolicy(Qt::CustomContextMenu);
//    connect(this, SIGNAL(customContextMenuRequested(QPoint)),
//            this, SLOT(showContextMenu(QPoint)));
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
    coord->readCoordinates("Gleiskanten.dbahn", countryCode);
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
            gleiskanten_Parent = new QGraphicsPathItem(path); //QColor(255, 69,0)
            if ((countryCode == "de" &&(dir[segmentCount] =="1" || dir[segmentCount] =="2")) || (countryCode == "de" && fileFormat == ".euxml")){
                //                gleiskanten_Parent->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin ));
                gleiskanten_Parent->setPen(QPen(lineColor,1));
                //                QPen::QPen(const QBrush &brush, qreal width, Qt::PenStyle style = Qt::SolidLine, Qt::PenCapStyle cap = Qt::SquareCap, Qt::PenJoinStyle join = Qt::BevelJoin)
                segmentCount++;
                gleiskanten_Parent->setData(signalKey, map[dataSegCount].keys() );
                gleiskanten_Parent->setData(signalKey+1, map[dataSegCount].values() );
            } else if (countryCode == "fr"){  // This condition should be removed when there is data about directions
                gleiskanten_Parent->setPen(QPen(lineColor, 1));  //QPen(Qt::black
                gleiskanten_Parent->setData(signalKey, map[dataSegCount].keys());
                gleiskanten_Parent->setData(signalKey+1, map[dataSegCount].values());
            }
            else {
                //                gleiskanten_Parent->setPen(QPen(Qt::black, 0.3,  Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin ));
                gleiskanten_Parent->setPen(QPen(lineColor,0.3));
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
            if ((countryCode == "de" && (dir[segmentCount] =="1" || dir[segmentCount] =="2")) || (countryCode == "de" && fileFormat == ".euxml")){
                gleiskanten->setPen(QPen(lineColor,1)); // QPen(Qt::black, 1)
                segmentCount++;
                gleiskanten->setData(signalKey, map[dataSegCount].keys() );
                gleiskanten->setData(signalKey+1, map[dataSegCount].values() );
            } else if (countryCode == "fr"){  // This condition should be removed when there is data about directions
                gleiskanten->setPen(QPen(lineColor, 1));
                gleiskanten->setData(signalKey, map[dataSegCount].keys());
                gleiskanten->setData(signalKey+1, map[dataSegCount].values());
            } else {
                //                gleiskanten->setPen(QPen(Qt::black, 0.3));
                gleiskanten->setPen(QPen(lineColor, 0.3));
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
    coord->readCoordinates("Entwurfselement_HO.dbahn", countryCode);
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
            if ((dir[segmentCount] =="1" || dir[segmentCount] =="2") || (countryCode == "de" && fileFormat == ".euxml")){
                hoehe_Parent->setPen(QPen(lineColor, 1)); //Qt::black
                segmentCount++;

            } else {
                hoehe_Parent->setPen(QPen(lineColor, 0.3));
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
            if ((dir[segmentCount] =="1" || dir[segmentCount] =="2") || (countryCode == "de" && fileFormat == ".euxml")){
                hoehe->setPen(QPen(lineColor, 1));
                segmentCount++;
            } else {
                hoehe->setPen(QPen(lineColor, 0.3));
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
    coord->readCoordinates("Entwurfselement_KM.dbahn", countryCode);
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
            kmLine_Parent->setPen(QPen(lineColor));
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
            kmLine->setPen(QPen(lineColor));
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
    coord->readCoordinates("Entwurfselement_LA.dbahn", countryCode);
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
            if ((dir[segmentCount] =="1" || dir[segmentCount] =="2") || (countryCode == "de" && fileFormat == ".euxml")){
                lage_Parent->setPen(QPen(lineColor, 1));
                segmentCount++;
            } else {
                lage_Parent->setPen(QPen(lineColor, 0.3));
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

            if ((dir[segmentCount] =="1" || dir[segmentCount] =="2") || (countryCode == "de" && fileFormat == ".euxml")){
                lage->setPen(QPen(lineColor, 1));
                segmentCount++;
            } else {
                lage->setPen(QPen(lineColor, 0.3));
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
    coord->readCoordinates("Entwurfselement_UH.dbahn", countryCode);
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
            if ((dir[segmentCount] =="1" || dir[segmentCount] =="2") || (countryCode == "de" && fileFormat == ".euxml")){
                uberhohung_Parent->setPen(QPen(lineColor, 1));
                segmentCount++;
            } else {
                uberhohung_Parent->setPen(QPen(lineColor, 0.3));
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
            if ((dir[segmentCount] =="1" || dir[segmentCount] =="2") || (countryCode == "de" && fileFormat == ".euxml")){
                uberhohung->setPen(QPen(lineColor, 1));
                segmentCount++;
            } else {
                uberhohung->setPen(QPen(lineColor, 0.3));
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

void Tracks::addGleisknoten(){
    QFile file (projectPath+"/"+projectName+"/temp/Gleisknoten.dbahn");
    if (!file.exists()) return;

    std::vector<float> vec = allVecKnoten(projectPath, projectName, "Gleisknoten.dbahn");

    // To obtain and add the data object to appropriate section
    Coordinates *coord = new Coordinates(projectPath, projectName);
    coord->readCoordinates("Gleisknoten.dbahn", countryCode);
    std::vector<QMap<QString, QString>> map = coord->getMap();
    int signalKey =0;
    int dataSegCount =0;

    // Add DataPoints
    bool isFirstPoint = true;

    //QPointF point;
    int count =0;
    qDebug()<< static_cast<int>(vec.size());
    while (count < static_cast<int>(vec.size())){
        if (isFirstPoint){
            QPainterPath path;
            path.addEllipse(vec[count]*getMultiplierValue(), vec[count+1]*getMultiplierValue(),2,2);
            gleisknotenDP_Parent = new QGraphicsPathItem(path);
            gleisknotenDP_Parent->setPen(QPen(Qt::red,0.7));
            gleisknotenDP_Parent->setBrush(QBrush(Qt::black));
            gleisknotenDP_Parent->setData(signalKey, map[dataSegCount].keys());
            gleisknotenDP_Parent->setData(signalKey+1, map[dataSegCount].values());
            gleisknotenDP_Parent->setToolTip("Gleisknoten_"+QString::number(signalKey));
            //            gleisknotenDP_Parent->setToolTip("Gleisknoten_"+QString::number(signalKey) +
            //                                             "\n x: "+QString::number(vec[count])+"\n y: "+QString::number(vec[count+1]));
            signalKey +=2;
            dataSegCount++;

            gleisknotenDP_Parent->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
            scene()->addItem(gleisknotenDP_Parent);
            isFirstPoint = !isFirstPoint;
        } else {
            QPainterPath path;
            path.addEllipse(vec[count]*getMultiplierValue(), vec[count+1]*getMultiplierValue(),2,2);
            QGraphicsPathItem *gleisknotenDP = new QGraphicsPathItem(path);
            gleisknotenDP->setPen(QPen(Qt::red, 0.7));
            gleisknotenDP->setBrush(QBrush(Qt::black));

            gleisknotenDP->setData(signalKey, map[dataSegCount].keys());
            gleisknotenDP->setData(signalKey+1, map[dataSegCount].values());
            gleisknotenDP->setToolTip("Gleisknoten_"+QString::number(signalKey));
            //            gleisknotenDP->setToolTip("Gleisknoten_"+QString::number(signalKey) +
            //                                             "\n x: "+QString::number(vec[count])+"\n y: "+QString::number(vec[count+1]));
            signalKey +=2;
            dataSegCount++;

            gleisknotenDP->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
            gleisknotenDP->setParentItem(gleisknotenDP_Parent);
        }
        count =  count +2;
    }
    if (!parentItems.contains("gleisknotenDP_Parent")) parentItems << "gleisknotenDP_Parent";
    gleisknotenDP_Parent->setVisible(getDrawGleisknotenDP());
}


// This function is only used when signal parameter is extracted from the EULYNX XML
void Tracks::addSignals()
{
    QFile file (projectPath+"/"+projectName+"/temp/Signal.dbahn");
    if (!file.exists()) return;

    // Add Symbols/Signals -- only if KmLine data is available (Json)
    QFile km_file (projectPath+"/"+projectName+"/temp/Entwurfselement_KM.dbahn");
    if (!km_file.exists()) return;
    qDebug()<< "signal2";

    KmToCoordinate *kmToCoord = new KmToCoordinate(projectPath,projectName);
    kmToCoord->mapKmAndCoord();
    kmToCoord->calculateAngles();

    // Get main signal data
    ReadEulnxSignals *euSignal = new ReadEulnxSignals(projectPath, projectName);
    euSignal->readMainSignals();
    std::vector<QMap<QString, QString>> each = euSignal->getParameters();

    for (int i=0; i< static_cast<int>(each.size()); i++){

        double val = (each.at(i)["Linear Coordinate"]).toDouble(); //    table[i][1].toDouble();
        double lateralDistance = (each.at(i)["Lateral Distance"]).toDouble();
        QString lateralSide =(each.at(i)["Lateral Side"]);

        // getFinalPosition(value, lateralDist, orientation)
        QPointF position = kmToCoord->getFinalPosition(val,lateralDistance,lateralSide);  //getNearestCoordFromKmValue(val);
        double angle = kmToCoord->getAngleFromKmValue(val);
        if (each.at(i)["DB Signal Function"] == "Entry Signal" && each.at(i)["Direction"] == "1"){
            addAutomateSignal("Ankundigungsbake", position, angle, each.at(i)["DB Signal Function"],
                    each.at(i)["Linear Coordinate"], each.at(i)["Lateral Distance"], each.at(i)["Lateral Side"], each.at(i)["Direction"]);
        }
        else if (each.at(i)["DB Signal Function"] == "Entry Signal" && each.at(i)["Direction"] == "2"){
            //Then add 180 to the angle (to make symbol rotate/turn to other direction
            addAutomateSignal("Ankundigungsbake",position, angle+180,  each.at(i)["DB Signal Function"],
                    each.at(i)["Linear Coordinate"], each.at(i)["Lateral Distance"], each.at(i)["Lateral Side"], each.at(i)["Direction"]);
        }
        else if (each.at(i)["DB Signal Function"] == "Exit Signal" && each.at(i)["Direction"] == "1"){
            addAutomateSignal("Abfahrsignal",position, angle, each.at(i)["DB Signal Function"],
                    each.at(i)["Linear Coordinate"], each.at(i)["Lateral Distance"], each.at(i)["Lateral Side"], each.at(i)["Direction"]);
        }
        else if (each.at(i)["DB Signal Function"] == "Exit Signal" && each.at(i)["Direction"] == "2"){
            //Then add 180 to the angle (to make symbol rotate/turn to other direction
            addAutomateSignal("Abfahrsignal",position, angle+180, each.at(i)["DB Signal Function"],
                    each.at(i)["Linear Coordinate"], each.at(i)["Lateral Distance"], each.at(i)["Lateral Side"], each.at(i)["Direction"]);
        }
        else qDebug()<< "None";
    }
}

void Tracks::addSignals2()
{
    QFile file (projectPath+"/"+projectName+"/temp2/UnprocessedJson.json");
    if (!file.exists()) return;
    SignalsFromUnprocessedJson *signal = new SignalsFromUnprocessedJson(nullptr, projectPath+"/"+projectName+"/temp2/UnprocessedJson.json"); //D:/Users/BKU/OlatunjiAjala/Documents/pdf/scheiben/temp2/UnprocessedJson.json  ; D:/Users/BKU/OlatunjiAjala/Documents/pdf/ETCS/temp2/UnprocessedJson.json  ; D:/Users/BKU/OlatunjiAjala/Documents/pdf/new2/temp2/UnprocessedJson.json
    std::vector< std::vector<QString>> all = signal->signalInfos();
    if ((int)all.size() ==0) return;

    // Add Symbols/Signals -- only if KmLine data /or Gleiskanen is available (Json)
    QFile km_file (projectPath+"/"+projectName+"/temp/Entwurfselement_KM.dbahn");
    QFile la_File(projectPath+"/"+projectName+"/temp/Entwurfselement_LA.dbahn"); // Gleiskanten.dbahn
    if (!km_file.exists() && !la_File.exists()) return;
    KmToCoordinate *kmToCoord = new KmToCoordinate(projectPath,projectName);
    kmToCoord->mapKmAndCoord();
    kmToCoord->calculateAngles();

    qDebug() << "\n\n" "S/No. " << "|  Type " << "  Function" << "  Lateral Side " << "  Direction" << "  Linear Km" << " coordX" << "  CoordY " << "  CoordZ ";
    qDebug() << "--------|------------------------------------------------------------------------------------------------------";
    for (int i=0; i< static_cast<int>(all.size()); i++){
        QString type = all.at(i)[0];
        QString function = all.at(i)[1];
        QString lateralSide =all.at(i)[2];   // Left or Right
        QString direction = (all.at(i)[3]);  // 1 or 2
        double linearKm = (all.at(i)[4]).toDouble();
        double lateralDistance = 3.1;
        QPointF position;

        // Check if the location geometry already defined in the inout data. If not, it needs to be evaluated
        if ((all.at(i)[5] =="0") && (all.at(i)[4] != "0")) {
            position = kmToCoord->getFinalPosition(linearKm,lateralDistance,lateralSide);  //getNearestCoordFromKmValue(val);
        } else if (all.at(i)[5] != "0") {
            position = QPointF((all.at(i)[5]).toDouble(), (all.at(i)[6]).toDouble());
        }
        else if ((all.at(i)[5] =="0") && (all.at(i)[4] == "0")) continue;
        double angle = kmToCoord->getAngleFromKmValue(linearKm);

//        qDebug()<< "Type: " << type;
//        qDebug()<< "Function: " << function;
//        qDebug()<< "LateralSide: " << lateralSide;
//        qDebug()<< "Direction: "<< direction;
//        qDebug()<< "Lateral Distance: " << lateralDistance;
//        qDebug()<< "Position: " <<position;
//        qDebug() << "Angle "<< angle;
        // ToDo: re-implement based on the specific function name
        if (direction == "1") addAutomateSignal("Achszahlkontakt", position, angle, function, QString::number(linearKm), "3.1", lateralSide, direction);
        //Then add 180 to the angle (to make symbol rotate/turn to other direction
        else if (direction == "2") addAutomateSignal("Achszahlkontakt", position, angle+180, function, QString::number(linearKm), "3.1", lateralSide, direction);
        else qDebug()<< "None";
    }
}


void Tracks::setBoolParameters()
{
    QFile file (projectPath+"/"+projectName+"/temp/Gleiskanten.dbahn");
    QFile file2 (projectPath+"/"+projectName+"/temp/Entwurfselement_HO.dbahn");
    QFile file3 (projectPath+"/"+projectName+"/temp/Entwurfselement_KM.dbahn");
    QFile file4 (projectPath+"/"+projectName+"/temp/Entwurfselement_UH.dbahn");
    QFile file5 (projectPath+"/"+projectName+"/temp/Entwurfselement_LA.dbahn");
    QFile file6 (projectPath+"/"+projectName+"/temp/Gleisknoten.dbahn");

    //    drawGleiskanten = file.exists() ? true : false;
    drawHoehe = file2.exists() ? true : false;
    drawKmLine = file3.exists() ? true : false;
    drawUberhohung = file4.exists() ? true : false;
    drawLage = file5.exists() ? true : false;
    drawGleisknotenDP = file6.exists() ? true : false;
}

void Tracks::reload()
{
    setBoolParameters();
    deleteAll();
    updateAll();
}

// TODO:: This function to be replaced by calling all items on the scene (e.g scene()->items())... and delete iteratively

/*RESET ALL (deleteAll and updateAll...  These functions ensure that all objects drawn on the scene are removed and deleted as
soon as it discovered that the Project path and /or Projetct name changes. It further helps in
calling all relevants functions needed for the re-implementation based on the new data available*/

void Tracks::deleteAll()
{
    foreach (QGraphicsItem *item, scene()->items()){
        scene()->removeItem(item);
        delete item;
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
    addGleisknoten();
}


QVector<QVector<float> > Tracks::allVec(QString pPath, QString pName, QString fileName)
{
    // First get the Directions (RITZ)
    // Note that Gleisknoten and KmLine cannot have the attribute of directions (RITZ)
    if (fileName != "Gleisknoten.dbahn" && fileName != "Entwurfselement_KM.dbahn" ){
        Coordinates *coord = new Coordinates(pPath, pName);
        coord->readCoordinates(fileName, countryCode);
        setDirection(coord->getDirection());
    }
    // Then get all the coordinates to be used for each segment plot
    QVector<QVector<float>> vec;
    if (fileName != "Gleisknoten.dbahn"){
        Coordinates *coord = new Coordinates(pPath, pName);
        coord->readCoordinates(fileName, countryCode);
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
        coord->readCoordinates(fileName, countryCode);
        vec = coord->getCoordinateLists();
    }
    return vec;
}

std::vector<float> Tracks::unsegmentedVec(QString pPath, QString pName, QString fileName)
{
    std::vector<float> vec;
    Coordinates *coord = new Coordinates(pPath, pName);
    coord->readCoordinates(fileName, countryCode);
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

void Tracks::setLightRules(bool newLightRules)
{
    lightRules = newLightRules;
    rotate(1);
    rotate(-1);
}

void Tracks::setDarkTheme(bool newDarkTheme)
{
    darkTheme = newDarkTheme;
    rotate(1);
    rotate(-1);
}

const QStringList &Tracks::getDataValues() const
{
    return dataValues;
}

void Tracks::setDataValues(const QStringList &newDataValues)
{
    dataValues = newDataValues;
}

const QStringList &Tracks::getDataKeys() const
{
    return dataKeys;
}

void Tracks::setDataKeys(const QStringList &newDataKeys)
{
    dataKeys = newDataKeys;
}

bool Tracks::getDrawGleisknotenDP() const
{
    return drawGleisknotenDP;
}

void Tracks::setDrawGleisknotenDP(bool newDrawGleisknotenDP)
{
    QFile file (projectPath+"/"+projectName+"/temp/Gleisknoten.dbahn");
    if (!file.exists()) return;

    if (drawGleisknotenDP != newDrawGleisknotenDP){
        drawGleisknotenDP = newDrawGleisknotenDP;
        gleisknotenDP_Parent->setVisible(newDrawGleisknotenDP);
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
    if (mouseDragMode){
        setDragMode(QGraphicsView::ScrollHandDrag);
        setInteractive(false);
    }
    else {
        setDragMode(QGraphicsView::NoDrag);
        setInteractive(true);
    }
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
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
{
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
    getSegementObjects();

    painter->save();
    if (drawGrids && darkTheme){
        qreal left = int(rect.left()) - (int(rect.left()) % mGridSize);
        qreal top = int(rect.top()) - (int(rect.top()) % mGridSize);

        QVarLengthArray<QLineF, 100> lines;

        for (qint64 x = left; x < rect.right(); x += mGridSize)
            lines.append(QLineF(x, rect.top(), x, rect.bottom()));
        for (qint64 y = top; y < rect.bottom(); y += mGridSize)
            lines.append(QLineF(rect.left(), y, rect.right(), y));

        QVarLengthArray<QLineF, 100> thickLines;

        for (qint64 x = left; x < rect.right(); x += mGridSize * 5)
            thickLines.append(QLineF(x, rect.top(), x, rect.bottom()));
        for (qint64 y = top; y < rect.bottom(); y += mGridSize * 5)
            thickLines.append(QLineF(rect.left(), y, rect.right(), y));

        QPen myPen(Qt::NoPen);
        painter->setBrush(QBrush(QColor(55, 55, 55, 255)));
        painter->setPen(myPen);
        painter->drawRect(rect);

        QPen penHLines(QColor(75, 75, 75), 1, Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
        painter->setPen(penHLines);
        painter->drawLines(lines.data(), lines.size());

        painter->setPen(QPen(QColor(100, 100, 100), 2, Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin));
        painter->drawLines(thickLines.data(), thickLines.size());
        painter->setPen(Qt::blue);

        QVector<QPointF> points;
        for (qint64 x = left; x < rect.right(); x += mGridSize) {
            for (qint64 y = top; y < rect.bottom(); y += mGridSize) {
                points.append(QPointF(x, y));
            }
        }
        painter->drawPoints(points.data(), points.size());
    } else QGraphicsView::drawBackground(painter, rect);
    painter->restore();
    update();
}

void Tracks::drawForeground(QPainter *painter, const QRectF &rect)
{
    painter->save();
    if (drawGrids && lightRules){
        //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

        //        // Point as background
        //                QPen pen;
        //                painter->setPen(pen);
        //                qreal left = int(rect.left()) - (int(rect.left()) % 20); //gridSize
        //                qreal top = int(rect.top()) - (int(rect.top()) % 20);
        //                QVector<QPointF> points;
        //                for (qreal x = left; x < rect.right(); x += 20){
        //                    for (qreal y = top; y < rect.bottom(); y += 20){
        //                        points.append(QPointF(x,y));
        //                    }
        //                }
        //                painter->drawPoints(points.data(), points.size());

        //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


        //         Line through

        QPen pen;
        pen.setCosmetic(true);
        pen.setWidthF(0.6);
        pen.setColor(QColor(95,52,21,90));
        painter->setPen(pen);

        //        painter->setPen(QColor(95,52,21,90));
        for (int i = 0; i< rect.width()/50; i++) {
            painter->drawLine(rect.x()+(50*i), rect.y(), rect.x()+(50*i),
                              rect.y()+rect.height());
        }
        for(int i =0; i < rect.height()/50; i++){
            painter->drawLine(rect.x(),rect.y()+(i*50),
                              rect.x()+rect.width(), rect.y()+(i*50));
        }

        //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


        // Line as Background
        //        for (int i = 0; i< getUsedRect()[2]/50; i++) {
        //            painter->drawLine(getUsedRect()[0]+(50*i),getUsedRect()[1], getUsedRect()[0]+(50*i),
        //                    getUsedRect()[1]+getUsedRect()[3]);
        //        }
        //        for(int i =0; i < getUsedRect()[3]/50; i++){
        //            painter->drawLine(getUsedRect()[0],getUsedRect()[1]+(i*50),
        //                    getUsedRect()[0]+getUsedRect()[2], getUsedRect()[1]+(i*50));
        //        }

        //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

    } else {
        QGraphicsView::drawForeground(painter, rect);
    }
    painter->restore();
    update();

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
    } else {
        QGraphicsView::wheelEvent(event);
    }
}

void Tracks::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left) rotate(5);
    else if(event->key() == Qt::Key_Right) rotate(-5);

    if((event->key() == Qt::Key_Delete))
    {
        foreach (QGraphicsItem *item, scene()->selectedItems()) {
            QString toolTip = item->toolTip();

            QStringList breakToolTip = toolTip.split(QLatin1Char('_'));  //QRegularExpression("_")
            if(breakToolTip[0].isEmpty()){
                scene()->removeItem(item);
                delete item;
            }
        }
    }
    QGraphicsView::keyPressEvent(event);
}

void Tracks::mouseMoveEvent(QMouseEvent *event)
{
    QPointF pos = mapToScene((event->pos()));
    setXCoord(pos.x());
    setYCoord(pos.y());
    QGraphicsView::mouseMoveEvent(event);
}


void Tracks::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton){
        QPointF sceneCoord = mapToScene(event->pos());
        setXCoord(sceneCoord.x()/getMultiplierValue());
        setYCoord(sceneCoord.y()/getMultiplierValue());
    } else if (textModeIsActive) {
        const QPointF &pos = mapToScene(event->pos());
        bool ok;
        QString enteredText = QInputDialog::getText(this, tr("APlan"),
                                                    tr("Please enter your text"), QLineEdit::Normal, "Text Here", &ok);
        if (!ok || enteredText.isEmpty() || enteredText == "Text Here") return;

        textItem = scene()->addText(enteredText);
        QTransform transform;
        transform.scale(1,-1);
        textItem->setPos(pos);
        textItem->setTransform(transform);
        textItem->setDefaultTextColor("blue");
        textItem->setTextInteractionFlags(Qt::TextEditorInteraction | Qt::TextEditable );
        textItem->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable | textItem->flags());
        // ToDo : Function to allow users zoom individual contents to desired scale
        textItem->setScale(1.5);
    }
    if (symbolIsSelected && (selectedSymbolName != "")){
        const QPointF &pos = mapToScene(event->pos());
        addSymbol(selectedSymbolName, pos);
    }
    QGraphicsView::mousePressEvent(event);
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

//void Tracks::showContextMenu(QPoint pos)
//{
//    QMenu contextMenu(tr("Context Menu"), this);
//    QAction action1("Dark Mode: Torggle (Testing)", this);
//    connect(&action1, SIGNAL(triggered()), this, SLOT(darkMode()));
//    contextMenu.addAction(&action1);
//    contextMenu.exec(mapToGlobal(pos));
//}


void Tracks::setMultiplierValue(int newMultiplierValue)
{
    multiplierValue = newMultiplierValue;
}


void Tracks::addSymbol(QString str, const QPointF &pos)
{   
    defaultObjectName = str;
    glbObjectName = str;
    QSvgRenderer *renderer = new QSvgRenderer(QString(":/icons/assets/qgraphics/"+str+".svg"));
    QGraphicsSvgItem *otherSignal = new QGraphicsSvgItem();
    otherSignal->setSharedRenderer(renderer);
    otherSignal->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    otherSignal->setData(0, "OtherSignal");
    otherSignal->setData(1, str);
    // set transformation
    QTransform transform;
    transform.scale(1,-1);
    otherSignal->setTransform(transform);
    otherSignal->setPos(pos);
//    otherSignal->setPos(getUsedRect()[0] +(getUsedRect()[2]/2) , getUsedRect()[1]+(getUsedRect()[3]/2));
    scene()->addItem(otherSignal);
}


void Tracks :: sceneSelectedItems(int degree){
    foreach (QGraphicsItem *item, scene()->selectedItems()) {
        QString toolTip = item->toolTip();

        QStringList breakToolTip = toolTip.split(QLatin1String("_")); //QRegularExpression("_")
        if(breakToolTip[0].isEmpty()){
            QPointF rotationPt = item->boundingRect().center();
            item->setTransformOriginPoint(rotationPt);
            item->setRotation(degree);
        }
    }
}

// Write Data (Only for signals/Symbols)
bool Tracks::writeOperator(QString fileName)
{
    QFile file (fileName);
    if (!file.open(QIODevice::WriteOnly)){
        return false;
    }
    QDataStream out (&file);
    out.setVersion(QDataStream::Qt_6_1);
    foreach (QGraphicsItem *item, scene()->items()){
        QVariant data = item->data(0);
        if((data.isValid() && data == "AutomatedSignal") ||
                (data.isValid() && data == "OtherSignal")){

            // get all relevant data from the item to enhance storage
            QString type = (item->data(0)).toString();
            QString name = (item->data(1)).toString();
            QString toolTip = item->toolTip();
            qreal angle = item->rotation();
            QPointF position = item->pos();
            out << type << name << toolTip << angle << position;
        }
    }
    if(!file.flush()){
        file.close();
        return false;
    }
    return true;
}

// Read Data
bool Tracks::ReadOperator(QString fileName)
{
    QFile file (fileName);
    if (!file.open(QIODevice::ReadOnly)){
        return false;
    }
    if (file.size() == 0) return false;
    QDataStream in (&file);
    if (in.version() != QDataStream::Qt_6_1){
        qDebug()<< "Wrong File Version";
        file.close();
        return false;
    }
    while (!in.atEnd()){
        QString type;
        QString name;
        QString toolTip;
        qreal angle;
        QPointF position;
        in >> type;
        in >> name;
        in >> toolTip;
        in >> angle;
        in >> position;

        if (type == "AutomatedSignal"){
            QSvgRenderer *renderer = new QSvgRenderer(QString(":/icons/assets/qgraphics/"+name+".svg"));
            QGraphicsSvgItem *signal = new QGraphicsSvgItem();
            signal->setSharedRenderer(renderer);
            signal->setData(0, "AutomatedSignal");
            signal->setData(1, name);
            signal->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsSelectable);
            signal->setToolTip(toolTip);
            signal->setPos(position);
            signal->setRotation(angle);
            scene()->addItem(signal);
        }
        else if (type == "OtherSignal"){
            defaultObjectName = name;

            glbObjectName = name;
            QSvgRenderer *renderer = new QSvgRenderer(QString(":/icons/assets/qgraphics/"+name+".svg"));
            QGraphicsSvgItem *otherSignal = new QGraphicsSvgItem();
            otherSignal->setSharedRenderer(renderer);
            otherSignal->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
            otherSignal->setData(0, "OtherSignal");
            otherSignal->setData(1, name);
            otherSignal->setPos(position);
            otherSignal->setRotation(angle);
            scene()->addItem(otherSignal);
        }
    }
    file.close();
    return true;
}

void Tracks::addAutomateSignal(QString name, QPointF location, double angle, QString type,
                               QString position, QString latDist, QString orientation, QString direction)

{
    //    "Abfahrsignal", position, angle, function,all.at(i)[0], "3.1", lateralSide, direction
    QSvgRenderer *renderer = new QSvgRenderer(QString(":/icons/assets/qgraphics/"+name+".svg"));
    QGraphicsSvgItem *signal = new QGraphicsSvgItem();
    signal->setSharedRenderer(renderer);
    signal->setData(0, "AutomatedSignal");
    signal->setData(1, name);
    signal->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsSelectable);
    signal->setToolTip(" DB Signal Function : " +type+"\n Coordinate: "+QString::number(location.x())+" , "+QString::number(location.y())+
                       "\n Linear Coordinate(Km): "+ position+ "\n Lateral Dist: "+latDist+ "\n Lateral Side: "+orientation+ "\n Direction: "+direction);
    signal->setPos(location*getMultiplierValue());
    signal->setRotation(angle);
    scene()->addItem(signal);
}

void Tracks::getSegementObjects()
{
    rightPanelTable =0;
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
                // new Implementation
                nameOfTrack = name;
                setDataKeys(keyKanten);
                setDataValues(valKanten);
            }
        }
    }
}

bool Tracks::isTrack(QString name)
{
    Q_UNUSED(name);
    rightPanelTable = !rightPanelTable;
    return rightPanelTable;
}

// Only items that is not from the data can be deleted.
void Tracks::deleteSelectedItems()
{
    foreach (QGraphicsItem *item, scene()->selectedItems()) {
        QString toolTip = item->toolTip();
        scene()->itemsBoundingRect();
        QStringList breakToolTip = toolTip.split(QLatin1Char('_'));  //QRegularExpression("_")
        if(breakToolTip[0].isEmpty()){
            scene()->removeItem(item);
            delete item;
        }
    }
}
