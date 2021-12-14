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
//        Gleiskanten,
//        Gleisknoten,
//        Hoehe,
//        KMLine,
//        Lage,
//        Uberhohung
//    };
    void addGleiskanten();
    void addHoehe();
    void addKMline();
    void addLage();
    void addUberhohung();
    void addGleisknoten();
    void setBoolParameters();
    void reload();
    void addSymbol(QString str);
    void addAutomateSignal(QString name, QPointF location, double angle,
                           QString type, QString position, QString latDist,
                           QString orientation, QString direction);
    void getSegementObjects();
    bool isTrack(QString name);


    void deleteAll();
    void updateAll();
    QGraphicsPixmapItem *pixmapItem;
    QGraphicsPixmapItem *pixmapItem2;
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

    bool getDrawGleisknotenDP() const;
    void setDrawGleisknotenDP(bool newDrawGleisknotenDP);

    bool getDragModeMouse() const;
    void setDragModeMouse();

    const QList<QString> &getDirection() const;
    void setDirection(const QList<QString> &newDirection);

    void sceneSelectedItems(int degree);

    void extractData(QString breakToolTip, QStringList keyK, QStringList vakK);
   // void mousePressEvent(QMouseEvent *event);
public slots:
    // void mousePressEvent(QMouseEvent *event);

signals:

private:
    QVector<QVector<float>> allVec(QString pPath, QString pName, QString fileName);
    std::vector<float> allVecKnoten(QString pPath, QString pName, QString fileName);
    std::vector<float> unsegmentedVec (QString pPath, QString pName, QString fileName);
//    QGraphicsItem *getSelectedItem();
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
    QGraphicsPathItem *gleisknotenDP_Parent;

    void multiplierEffect(float x, float y);
    int multiplierValue = 1;
    bool multiplierDone;
    QVector <float> boundingRect = {100000000,100000000,1,1};
    QVector <float> usedRect = {0,0,1,1};     // used sceneRect
    QSet <QString> parentItems;   // QLists of all parent items
    QList<QString> direction;
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
    bool drawGleisknotenDP;
    bool dragModeMouse;
    double xCoord;
    double yCoord;
    int ttt = 0;



//    Object currentObject;
    // QGraphicsView interface
public:
    void drawBackground(QPainter *painter, const QRectF &rect) override;
    void drawForeground(QPainter *painter, const QRectF &rect) override;

    // QWidget interface
    QGraphicsItemGroup *group;


protected:
    void wheelEvent(QWheelEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
//    void mouseMoveEvent(QMouseEvent *event) override;


    // QWidget interface
//protected:
//   void mousePressEvent(QMouseEvent *event) override;
};
#endif // TRACKS_H

