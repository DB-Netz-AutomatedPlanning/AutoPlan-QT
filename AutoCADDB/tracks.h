#ifndef TRACKS_H
#define TRACKS_H

#include <QWidget>
#include <QGraphicsView>
#include <QSet>

class Tracks : public QGraphicsView
{
    Q_OBJECT
public:
    explicit Tracks(QWidget *parent = nullptr);
//    enum Object {
//        gleiskanten,
//        gleisknoten,
//        entwurfselement_HO,
//        entwurfselement_KM,
//        entwurfselement_UH,
//        entwurfselement_LA
//    };
    void addGleiskanten();
    void addHoehe();
    void addKMline();
    void addLage();
    void addUberhohung();
    void setBoolParameters();
    void reload();
    void addSymbol(QString str);

    void deleteAll();
    void updateAll();
    QGraphicsPixmapItem *pixmapItem;
//    void itemInteractWithMouse(bool canInteract);


//    Object getCurrentObject() const;
//    void setCurrentObject(Object newCurrentObject);

    void getMultiplierEffect();   // most inportant function for setting the multiplier
    void getUpdateRect ();
    int getMultiplierValue() const;

    void setMultiplierValue(int newMultiplierValue);

    const QVector<float> &getUsedRect() const;
    void setUsedRect(const QVector<float> &newUsedRect);

    bool getDrawGrids() const;
    void setDrawGrids(bool newDrawGrids);

    double getXCoord() const;
    void setXCoord(double newXCoord);

    double getYCoord() const;
    void setYCoord(double newYCoord);

    bool getDrawHoehe() const;
    void setDrawHoehe(bool newDrawHoehe);

    bool getDrawGleiskanten() const;
    void setDrawGleiskanten(bool newDrawGleiskanten);

    bool getDrawGleiskantenDP() const;
    void setDrawGleiskantenDP(bool newDrawGleiskantenDP);

    bool getDrawHoeheDP() const;
    void setDrawHoeheDP(bool newDrawHoeheDP);

    bool getDrawKmLine() const;
    void setDrawKmLine(bool newDrawKmLine);

    bool getDrawKmLineDP() const;
    void setDrawKmLineDP(bool newDrawKmLineDP);

    bool getDrawLage() const;
    void setDrawLage(bool newDrawLage);

    bool getDrawUberhohung() const;
    void setDrawUberhohung(bool newDrawUberhohung);

    bool getDrawUberhohungDP() const;
    void setDrawUberhohungDP(bool newDrawUberhohungDP);

    bool getDrawLageDP() const;
    void setDrawLageDP(bool newDrawLageDP);

    bool getDragModeMouse() const;
    void setDragModeMouse();

signals:

private:
    QVector<QVector<float>> allVec(QString pPath, QString pName, QString fileName);
    std::vector<float> allVecKnoten(QString pPath, QString pName, QString fileName);
    std::vector<float> unsegmentedVec (QString pPath, QString pName, QString fileName);
    QGraphicsPathItem *gleiskanten_Parent;
    QGraphicsPathItem *gleiskantenDP_Parent;
    QGraphicsPathItem *hoehe_Parent;
    QGraphicsPathItem *hoeheDP_Parent;
    QGraphicsPathItem *kmLine_Parent;
    QGraphicsPathItem *kmLineDP_Parent;
    QGraphicsPathItem *lage_Parent;
    QGraphicsPathItem *lageDP_Parent;
    QGraphicsPathItem *uberhohung_Parent;
    QGraphicsPathItem *uberhohungDP_Parent;
    void multiplierEffect(float x, float y);
    int multiplierValue = 1;
    bool multiplierDone;
    QVector <float> boundingRect = {100000000,100000000,1,1};
    QVector <float> usedRect = {0,0,1,1};     // used sceneRect
    QSet <QString> parentItems;   // QLists of all parent items
    bool drawGrids;
    bool drawGleiskanten;
    bool drawGleiskantenDP;
    bool drawHoehe;
    bool drawHoeheDP;
    bool drawKmLine;
    bool drawKmLineDP;
    bool drawLage;
    bool drawLageDP;
    bool drawUberhohung;
    bool drawUberhohungDP;
    bool dragModeMouse;
    double xCoord;
    double yCoord;
    int ttt = 0;
    // To be changed
//    QString pPath = "C:/Users/DR-PHELZ/Documents/pdf";
//    QString pName = "Meggen";


//    Object currentObject;


    // QGraphicsView interface
protected:
    void drawBackground(QPainter *painter, const QRectF &rect) override;
    void drawForeground(QPainter *painter, const QRectF &rect) override;

    // QWidget interface
protected:
    void wheelEvent(QWheelEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
//    void mouseMoveEvent(QMouseEvent *event) override;



    // QWidget interface
//protected:
//    void mousePressEvent(QMouseEvent *event) override;
};

#endif // TRACKS_H
