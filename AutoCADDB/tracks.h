#ifndef TRACKS_H
#define TRACKS_H

#include <QWidget>
#include <QGraphicsView>

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

signals:

private:
    QVector<QVector<float>> allVec(QString pPath, QString pName, QString fileName);
    std::vector<float> allVecKnoten(QString pPath, QString pName, QString fileName);
    std::vector<float> unsegmentedVec (QString pPath, QString pName, QString fileName);
    QGraphicsPathItem *gleiskanten_Parent;
    QGraphicsPathItem *gleiskantenDP_Parent;
    QGraphicsPathItem *hoehe_Parent;
    QGraphicsPathItem *hoeheDP_Parent;
    void multiplierEffect(float x, float y);
    int multiplierValue = 1;
    bool multiplierDone;
    QVector <float> boundingRect = {100000000,100000000,1,1};
    QVector <float> usedRect = {0,0,1,1};     // used sceneRect
    bool drawGrids;
    bool drawGleiskanten;
    bool drawGleiskantenDP;
    bool drawHoehe;
    bool drawHoeheDP;
    double xCoord;
    double yCoord;
    int ttt = 0;


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
