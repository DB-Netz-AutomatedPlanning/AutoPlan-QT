#ifndef TRACKS_H
#define TRACKS_H

#include <QWidget>
#include <QGraphicsView>
#include <QSet>
#include <QHoverEvent>
#include <QGraphicsSvgItem>
#include <QDataStream>
#include <QGraphicsTextItem>
#include <QTextCursor>


class Tracks : public QGraphicsView
{
    Q_OBJECT
public:
    explicit Tracks(QWidget *parent = nullptr);

    void addGleiskanten();
    void addHoehe();
    void addKMline();
    void addLage();
    void addUberhohung();
    void addGleisknoten();
    void addSignals();
    void addSignals2();
    void setBoolParameters();
    void reload();
    void addSymbol(QString str, const QPointF &pos);
    void addAutomateSignal(QString name, QPointF location, double angle,
                           QString type, QString position, QString latDist,
                           QString orientation, QString direction);
    void getSegementObjects();
    bool isTrack(QString name);
    void deleteSelectedItems();

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

    bool writeOperator(QString fileName);
    bool ReadOperator(QString fileName);

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
    QGraphicsPathItem *gleisknotenDP_Parent;

    QGraphicsTextItem *textItem;
    QTextCursor cursor;

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
    bool dark_Mode;
    double xCoord;
    double yCoord;
    int ttt = 0;
    int mGridSize = 20;
    bool darkTheme;
    bool lightRules;
    bool symbolIsActive;
    QStringList dataKeys;
    QStringList dataValues;

    QColor lineColor = QColor(255,69,0); // orangeRed

public:
    void drawBackground(QPainter *painter, const QRectF &rect) override;
    void drawForeground(QPainter *painter, const QRectF &rect) override;

    // QWidget interface
    QGraphicsItemGroup *group;


    const QStringList &getDataKeys() const;
    void setDataKeys(const QStringList &newDataKeys);

    const QStringList &getDataValues() const;
    void setDataValues(const QStringList &newDataValues);

    // QWidget interface
    void setDarkTheme(bool newDarkTheme);

    void setLightRules(bool newLightRules);

protected:
    void wheelEvent(QWheelEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // TRACKS_H

