#ifndef SVGDIALOGVIEW_H
#define SVGDIALOGVIEW_H

#include <QGraphicsView>

QT_BEGIN_NAMESPACE
class QGraphicsSvgItem;
class QSvgRenderer;
class QWheelEvent;
class QPaintEvent;
class QGraphicsScene;
class QGraphicsPixmapItem;
QT_END_NAMESPACE

class SvgDialogView : public QGraphicsView
{

Q_OBJECT

public:

    enum RendererType { Native };
    explicit SvgDialogView(QWidget *parent = nullptr);

    bool openFile(const QString &fileName);
    void setRenderer(RendererType type = Native);
    void drawBackground(QPainter *p, const QRectF &rect) override;

    QSize svgSize() const;
    void displaySymbol(QString &selectedOption);
    void saveSVG();



public slots:

    void setViewBackground(bool enable);



protected:

    void paintEvent(QPaintEvent *event) override;

private:
   //void zoomBy(qreal factor);
    QGraphicsSvgItem *m_svgItem;
    QGraphicsRectItem *m_backgroundItem;
    RendererType m_renderer;
    QGraphicsScene* imgScene;
    QGraphicsPixmapItem* imgItem;

    QGraphicsPixmapItem* imgFilled;
    QGraphicsPixmapItem* imgMehr;
    QGraphicsPixmapItem* imgHs;
    QGraphicsPixmapItem* imgArrow;
    QImage m_image;
};
#endif // SVGVIEW_H
