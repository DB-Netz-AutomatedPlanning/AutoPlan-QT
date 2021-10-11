#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLContext>
#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QtOpenGL/QOpenGLShaderProgram>
//#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QMatrix4x4>
#include <QMouseEvent>
#include <QLabel>
#include <QPushButton>
#include <QTime>
#include <QCoreApplication>

using namespace std;



class MyOpenglWidget : public QOpenGLWidget, public QOpenGLFunctions
{
    Q_OBJECT
public:
    MyOpenglWidget(QWidget *parent = nullptr);
    ~MyOpenglWidget();
 void sendObjectProperties(QString);
 void assignObjectName(QString);
 void paintGL() override;
 void openGLUpdate();
// void delay();


 QString* s;

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    QOpenGLVertexArrayObject m_vao;
    QOpenGLBuffer buffer;
    GLuint m_MVPMatrixLoc;
    QMatrix4x4 modelMatrix;
    QMatrix4x4 viewMatrix;
    QMatrix4x4 projectionMatrix;
    QMatrix4x4 mvp;
    QOpenGLShaderProgram *shaderProg;


    double x = 3432800;
    double y = 5665700;
    float z = 10000.0f;
    float highestZoomScale  = 62000.0f;
    float lowestZoomScale  = 4200.0f;

    bool mouseLeftButtonPressed;
    bool mouseRightButtonPressed;
    int temp = 0;
    double dx = 0;
    double dy = 0;
    double scaleSpeed = 556.0;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;


    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;

    QPushButton *btnSender;

    QObject *object;

    private:
    QString str;
    QLabel *newIcon;




public slots:
    void cleanup();




};

#endif // MYOPENGLWIDGET_H
