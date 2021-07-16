#include "glwidget.h"
#include <QOpenGLFunctions>
#include <QtOpenGL>
//#include <GL/glut.h>

#include <QOpenGLContext>
#include <QOpenGLPaintDevice>
#include <QPainter>

GLWidget::GLWidget(QWindow *parent)
    : QWindow(parent)
 {
     setSurfaceType(QWindow::OpenGLSurface);
 }


void GLWidget::initializeGL()
{

    glClearColor(0.9,1,0,1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);

}

void GLWidget::paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glColor3b(1,0,0);

}

void GLWidget::resize(int w, int h)
{

}
