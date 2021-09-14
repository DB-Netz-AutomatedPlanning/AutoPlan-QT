#ifndef OPENGLCLASS_H
#define OPENGLCLASS_H

#include <QOpenGLWidget>
#include <QMouseEvent>
#include <QColor>
#include <QOpenGLFunctions>
#include <QPoint>
#include <QColor>


class OpenGLClass : public QOpenGLWidget, public QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit OpenGLClass(QWidget *parent = 0);
    ~OpenGLClass();


signals:


protected:

    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;


public slots:

    void setPenColor(const QColor &newColor);
    QColor penColor() const { return myPenColor; }
    void setPenWidth(int newWidth);
    int penWidth() const { return myPenWidth; }



private:

    QColor myPenColor = Qt::blue;
    int myPenWidth = 1;

};

#endif // OPENGLCLASS_H
