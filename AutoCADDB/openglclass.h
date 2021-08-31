#ifndef OPENGLCLASS_H
#define OPENGLCLASS_H

#include <QOpenGLWidget>
#include <QMouseEvent>
#include <QColor>
#include <QOpenGLFunctions>

//MENU
#include <QImage>
#include <QPoint>
#include <QWidget>

//
#include <QColor>
#include <QImage>
#include <QPoint>
#include <QWidget>
#include <QOpenGLWidget>
#include <QMouseEvent>
#include <QColor>
#include <QOpenGLFunctions>
#include<QOpenGLFunctions_3_3_Compatibility>
class OpenGLClass : public QOpenGLWidget, public QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit OpenGLClass(QWidget *parent = 0);
    ~OpenGLClass();

    //MENU
    bool openImage(const QString &fileName);
    bool saveImage(const QString &fileName, const char *fileFormat);

    bool isModified() const { return modified; }
signals:

public slots:
    void clearImage();
    void print();

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;
  //  void mousePressEvent(QMouseEvent *event);
   void mouseMoveEvent(QMouseEvent *event);
      void resizeEvent(QResizeEvent *event) override;

    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void iconClicked();

public slots:
    // slots for xyz-rotation slider
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);
    void setPenColor(const QColor &newColor);
    QColor penColor() const { return myPenColor; }
    void setPenWidth(int newWidth);
    int penWidth() const { return myPenWidth; }


signals:
    // signaling rotation from mouse movement
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);

private:
    void draw();

    int xRot;
    int yRot;
    int zRot;
    QColor myPenColor = Qt::blue;
    int myPenWidth = 1;
    QPoint lastPos;

    //MENU
    QImage image;
    bool modified = false;
    void resizeImage(QImage *image, const QSize &newSize);
};

#endif // OPENGLCLASS_H
