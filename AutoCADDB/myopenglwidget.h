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
#include <QMap>
#include <QCoreApplication>
#include <QTimer>

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
 void testingFnt(QLabel *lbl);

 QString aPlanProjectName;
 QString aPlanProjectPath;
 QString aPlanFileName;


 QString* s;

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    QOpenGLVertexArrayObject  m_vao;
    QOpenGLBuffer buffer;
    GLuint m_MVPMatrixLoc;
    QMatrix4x4 modelMatrix;
    QMatrix4x4 viewMatrix;
    QMatrix4x4 projectionMatrix;
    QMatrix4x4 mvp;
    QOpenGLShaderProgram *shaderProg;

    int m_normalMatrixLoc = 0;

    double x = 3432800.00000000;
    double y = 5665700.00000000;
    float z = 10000.0f;
    float highestZoomScale  = 25000.0f;
    float lowestZoomScale  = 200.0f;

    bool mouseLeftButtonPressed;
    bool mouseRightButtonPressed;
    int temp = 0;
    double dx = 0;
    double dy = 0;
    double scaleSpeed = 500.0;
    double zoomScale = 2;
    double testZ = 0.0;
    double testX = x;
    double testY = y;
    double getLowestCoordinateX;
    double getLowestCoordinateY;
    double minToCenterChangeValueX;
    double minToCenterChangeValueY;
    double powerValueOfTwo = 1;
    int power = 0;
    int testPower = 0;
    float compareTestZ = 10000.0f;

    double xForGrid = 3432800.00000000;
    double yForGrid = 5665700.00000000;
    QMap<QString,QString> segmentInfoFromCoordinate;

    const QString PARAMETER = "GLeiskanten.geojson";


    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;


    void showGleisknoten(QString path, QString projectName);

    void setSegmentInfoForCoordinate(double xCoordinate, double yCoordinate);
    void drawGrid();

    QPushButton *btnSender;

    QObject *object;

    private:
    QString str;
    QLabel *newIcon;

public:
    const QMap<QString,QString> &getSegmentInfoForCoordinate() const;
    void setCoordinateinRightTable(QMap<QString, QString>);


public slots:
    void cleanup();
    void ctxMenu(const QPoint &pos);




};

#endif // MYOPENGLWIDGET_H
