#include <GL/glew.h>

#include "openglclass.h"
#include <QOpenGLWidget>
#include <QtWidgets>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QColor>

#include <QColor>
#include <QImage>
#include <QPoint>
#include <QWidget>

#include <QtWidgets>

#include <QtOpenGL>
//SAVE
#include <QPainter>

#include<QOpenGLFunctions_3_3_Compatibility>




#if defined(QT_PRINTSUPPORT_LIB)
#include <QtPrintSupport/qtprintsupportglobal.h>
#if QT_CONFIG(printdialog)
#include <QPrinter>
#include <QPrintDialog>
#endif
#endif

OpenGLClass::OpenGLClass(QWidget *parent):QOpenGLWidget(parent)
{
    xRot = 0;
    yRot = 0;
    zRot = 0;
    setAttribute(Qt::WA_StaticContents);
}
OpenGLClass::~OpenGLClass()
{
}

QSize OpenGLClass::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize OpenGLClass::sizeHint() const
{
    return QSize(400, 400);
}

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360)
        angle -= 360 * 16;
}

void OpenGLClass::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != xRot) {
        xRot = angle;
        emit xRotationChanged(angle);
       update();
    }
}

void OpenGLClass::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != yRot) {
        yRot = angle;
        emit yRotationChanged(angle);
       update();
    }
}

void OpenGLClass::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != zRot) {
        zRot = angle;
        emit zRotationChanged(angle);
       update();
    }
}





void OpenGLClass::initializeGL()
{
  //glClearColor(0,0,0,0);
initializeOpenGLFunctions();
glewExperimental = true;
GLenum error = glewInit();

if(error!= GLEW_OK){
    fprintf(stderr,"Glew is not ok");
}

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    static GLfloat lightPosition[4] = { 0, 0, 10, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    //GLuint VertexArrayID;
//    glGenVertexArrays(1,&VertexArrayID);
//    glBindVertexArray(VertexArrayID);

}



void OpenGLClass::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
    glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
    glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);
    draw();
}

void OpenGLClass::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
#ifdef QT_OPENGL_ES_1
    glOrthof(-2, +2, -2, +2, 1.0, 15.0);
#else
    glOrtho(-2, +2, -2, +2, 1.0, 15.0);
#endif
    glMatrixMode(GL_MODELVIEW);
}

void OpenGLClass::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void OpenGLClass::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        setXRotation(xRot + 8 * dy);
        setYRotation(yRot + 8 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        setXRotation(xRot + 8 * dy);
        setZRotation(zRot + 8 * dx);
    }

    lastPos = event->pos();
}

void OpenGLClass::draw()
{
  //  qglColor(Qt::red);
    glBegin(GL_QUADS);
        glNormal3f(0,0,-1);
        glVertex3f(-1,-1,0);
        glVertex3f(-1,1,0);
        glVertex3f(1,1,0);
        glVertex3f(1,-1,0);

    glEnd();
    glBegin(GL_TRIANGLES);
        glNormal3f(0,-1,0.707);
        glVertex3f(-1,-1,0);
        glVertex3f(1,-1,0);
        glVertex3f(0,0,1.2);
    glEnd();
    glBegin(GL_TRIANGLES);
        glNormal3f(1,0, 0.707);
        glVertex3f(1,-1,0);
        glVertex3f(1,1,0);
        glVertex3f(0,0,1.2);
    glEnd();
    glBegin(GL_TRIANGLES);
        glNormal3f(0,1,0.707);
        glVertex3f(1,1,0);
        glVertex3f(-1,1,0);
        glVertex3f(0,0,1.2);
    glEnd();
    glBegin(GL_TRIANGLES);
        glNormal3f(-1,0,0.707);
        glVertex3f(-1,1,0);
        glVertex3f(-1,-1,0);
        glVertex3f(0,0,1.2);
    glEnd();
}


void OpenGLClass::setPenColor(const QColor &newColor)
//! [5] //! [6]
{
    myPenColor = newColor;
}
void OpenGLClass::setPenWidth(int newWidth)
//! [7] //! [8]
{
    myPenWidth = newWidth;
}




//! [1]
bool OpenGLClass::openImage(const QString &fileName)
//! [1] //! [2]
{
    QImage loadedImage;
    if (!loadedImage.load(fileName))
        return false;

    QSize newSize = loadedImage.size().expandedTo(size());
    resizeImage(&loadedImage, newSize);
    image = loadedImage;
    modified = false;
    update();
    return true;
}
//! [2]

//! [3]
bool OpenGLClass::saveImage(const QString &fileName, const char *fileFormat)
//! [3] //! [4]
{
    QImage visibleImage = image;
    resizeImage(&visibleImage, size());

    if (visibleImage.save(fileName, fileFormat)) {
        modified = false;
        return true;
    }
    return false;
}
//! [4]

void OpenGLClass::resizeImage(QImage *image, const QSize &newSize)
//! [19] //! [20]
{
    if (image->size() == newSize)
        return;

    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}

void OpenGLClass::resizeEvent(QResizeEvent *event)
//! [15] //! [16]
{
    if (width() > image.width() || height() > image.height()) {
        int newWidth = qMax(width() + 128, image.width());
        int newHeight = qMax(height() + 128, image.height());
        resizeImage(&image, QSize(newWidth, newHeight));
        update();
    }
    QWidget::resizeEvent(event);
}

//! [9]
void OpenGLClass::clearImage()
//! [9] //! [10]
{
    image.fill(qRgb(255, 255, 255));
    modified = true;
    update();
}
//! [10]

//! [21]
void OpenGLClass::print()
{
     qInfo() << "yay";
//#if defined(QT_PRINTSUPPORT_LIB) && QT_CONFIG(printdialog)
//    QPrinter printer(QPrinter::HighResolution);

//    QPrintDialog printDialog(&printer, this);
////! [21] //! [22]
//    if (printDialog.exec() == QDialog::Accepted) {
//        QPainter painter(&printer);
//        QRect rect = painter.viewport();
//        QSize size = image.size();
//        size.scale(rect.size(), Qt::KeepAspectRatio);
//        painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
//        painter.setWindow(image.rect());
//        painter.drawImage(0, 0, image);
//    }
//#endif // QT_CONFIG(printdialog)

     #if defined(QT_PRINTSUPPORT_LIB) && QT_CONFIG(printdialog)
         QPrinter printer(QPrinter::HighResolution);

         QPrintDialog printDialog(&printer, this);
     //! [21] //! [22]
         if (printDialog.exec() == QDialog::Accepted) {
             QPainter painter(&printer);
             QRect rect = painter.viewport();
             QSize size = image.size();
             size.scale(rect.size(), Qt::KeepAspectRatio);
             painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
             painter.setWindow(image.rect());
             painter.drawImage(0, 0, image);
         }
     #endif // QT_CONFIG(printdialog)


//        QPrinter printer(QPrinter::HighResolution);
//               printer.setOutputFormat(QPrinter::PdfFormat);
//               printer.setOutputFileName("output.pdf");
//               printer.setFullPage(true);
//               printer.setPageMargins(QMarginsF(0,0,0,0));


//               QSize minSize = image.minimumSizeHint();
//               int minWidth = minSize.width();
//               int minHeight = minSize.height();

//               QPainter painter(&printer);
//               painter.begin(&printer);
//               QRect rect = painter.viewport();
//                double xscale = rect.width()/double(minWidth);
//                double yscale = rect.height()/double(minHeight);
//                double scale = qMin(xscale, yscale);
//                painter.translate(rect.x() + rect.width()/2,
//                  rect.y() + rect.height()/2);
//                  painter.scale(scale, scale);
//               painter.translate(-width()/2, -height()/2);

//                      image.render(&painter);
}












////! [1]
//bool OpenGLClass::openImage(const QString &fileName)
////! [1] //! [2]
//{
//    QImage loadedImage;
//    if (!loadedImage.load(fileName))
//        return false;

//    QSize newSize = loadedImage.size().expandedTo(size());
//    resizeImage(&loadedImage, newSize);
//    image = loadedImage;
//    modified = false;
//    update();
//    return true;
//}
////! [2]

////! [3]
//bool OpenGLClass::saveImage(const QString &fileName, const char *fileFormat)
////! [3] //! [4]
//{
//    QImage visibleImage = image;
//    resizeImage(&visibleImage, size());

//    if (visibleImage.save(fileName, fileFormat)) {
//        modified = false;
//        return true;
//    }
//    return false;
//}
////! [4]

////! [5]
//void OpenGLClass::setPenColor(const QColor &newColor)
////! [5] //! [6]
//{
//    myPenColor = newColor;
//}
////! [6]

////! [7]
//void OpenGLClass::setPenWidth(int newWidth)
////! [7] //! [8]
//{
//    myPenWidth = newWidth;
//}
////! [8]

////! [9]
//void OpenGLClass::clearImage()
////! [9] //! [10]
//{
//    image.fill(qRgb(255, 255, 255));
//    modified = true;
//    update();
//}
////! [10]

////! [11]
//void OpenGLClass::mousePressEvent(QMouseEvent *event)
////! [11] //! [12]
//{
//    if (event->button() == Qt::LeftButton) {
//        lastPoint = event->position().toPoint();
//        scribbling = true;
//    }
//}

//void OpenGLClass::mouseMoveEvent(QMouseEvent *event)
//{
//    if ((event->buttons() & Qt::LeftButton) && scribbling)
//        drawLineTo(event->position().toPoint());
//}

//void OpenGLClass::mouseReleaseEvent(QMouseEvent *event)
//{
//    if (event->button() == Qt::LeftButton && scribbling) {
//        drawLineTo(event->position().toPoint());
//        scribbling = false;
//    }
//}

////! [12] //! [13]
//void OpenGLClass::paintEvent(QPaintEvent *event)
////! [13] //! [14]
//{
//    QPainter painter(this);
//    QRect dirtyRect = event->rect();
//    painter.drawImage(dirtyRect, image, dirtyRect);
//}
////! [14]

////! [15]
//void OpenGLClass::resizeEvent(QResizeEvent *event)
////! [15] //! [16]
//{
//    if (width() > image.width() || height() > image.height()) {
//        int newWidth = qMax(width() + 128, image.width());
//        int newHeight = qMax(height() + 128, image.height());
//        resizeImage(&image, QSize(newWidth, newHeight));
//        update();
//    }
//    QWidget::resizeEvent(event);
//}
////! [16]

////! [17]
//void OpenGLClass::drawLineTo(const QPoint &endPoint)
////! [17] //! [18]
//{
//    QPainter painter(&image);
//    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
//                        Qt::RoundJoin));
//    painter.drawLine(lastPoint, endPoint);
//    modified = true;

//    int rad = (myPenWidth / 2) + 2;
//    update(QRect(lastPoint, endPoint).normalized()
//                                     .adjusted(-rad, -rad, +rad, +rad));
//    lastPoint = endPoint;
//}
////! [18]

////! [19]
//void OpenGLClass::resizeImage(QImage *image, const QSize &newSize)
////! [19] //! [20]
//{
//    if (image->size() == newSize)
//        return;

//    QImage newImage(newSize, QImage::Format_RGB32);
//    newImage.fill(qRgb(255, 255, 255));
//    QPainter painter(&newImage);
//    painter.drawImage(QPoint(0, 0), *image);
//    *image = newImage;
//}
////! [20]

////! [21]
//void OpenGLClass::print()
//{
//#if defined(QT_PRINTSUPPORT_LIB) && QT_CONFIG(printdialog)
//    QPrinter printer(QPrinter::HighResolution);

//    QPrintDialog printDialog(&printer, this);
////! [21] //! [22]
//    if (printDialog.exec() == QDialog::Accepted) {
//        QPainter painter(&printer);
//        QRect rect = painter.viewport();
//        QSize size = image.size();
//        size.scale(rect.size(), Qt::KeepAspectRatio);
//        painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
//        painter.setWindow(image.rect());
//        painter.drawImage(0, 0, image);
//    }
//#endif // QT_CONFIG(printdialog)
//}
//! [22]

