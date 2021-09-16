#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLContext>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QMatrix4x4>
#include <QMouseEvent>
#include <QLabel>
#include <QPushButton>

using namespace std;



class MyOpenglWidget : public QOpenGLWidget, public QOpenGLFunctions
{
    Q_OBJECT
public:
    MyOpenglWidget(QWidget *parent = nullptr);
    ~MyOpenglWidget();
 void sendObjectProperties(QString);
 void assignObjectName(QString);


 QString* s;

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    QOpenGLBuffer buffer;
    GLuint m_MVPMatrixLoc;
    QMatrix4x4 modelMatrix;
    QMatrix4x4 viewMatrix;
    QMatrix4x4 projectionMatrix;
    QMatrix4x4 mvp;
    QOpenGLShaderProgram shaderProg;

    double x = 3432800;
    double y = 5665700;
    float z = 10000.0f;


    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

    QPushButton *btnSender;

    QObject *object;

    private:
    QString str;
    QLabel *newIcon;


};

#endif // MYOPENGLWIDGET_H
