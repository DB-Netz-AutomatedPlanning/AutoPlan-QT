#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QWidget>
#include <QtOpenGL>
#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QOpenGLFunctions_3_0>

//


#include <QWindow>
#include <QOpenGLFunctions>

QT_BEGIN_NAMESPACE
class QPainter;
class QOpenGLContext;
class QOpenGLPaintDevice;
QT_END_NAMESPACE

class GLWidget : public QWindow, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit GLWidget(QWindow *parent = 0);
    ~GLWidget();


void initializeGL();
void paintGL();
void resize(int w, int h);
signals:

};

#endif // GLWIDGET_H
