#ifndef SYMBOLINOPENGL_H
#define SYMBOLINOPENGL_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLContext>
#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QtOpenGL/QOpenGLShaderProgram>
//#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <cmath>

using namespace std;


class SymbolInOpengl
{
public:
    SymbolInOpengl();
    void drawRectangleWithLine(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate);
    void drawFilledRectangle(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate);
    void drawCornerShapeSquare(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate);
    void drawNotFilledRectangle(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate);
    void filledCornerShapedSquare(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate);
    void drawRectangleWithLineWithFilledCornerSquare(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate);
    void drawRectangleWithLineWithFilledCornerSquareAtRight(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate);
    void tail(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate);
    void Trapeztafel(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate);
    void Vorsignaltafel(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate);
    void Haltepunkttafel(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate);
    void angleLine(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate);

    void drawRectangleWithRightCornerSquare(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate);
    void halfCircle(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate, double angle);
    void filledHalfCircle(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate, double angle);
    void boxOpenedRight(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate);
    void boxOpenedLeft(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate);
    void KsHauptsignalZugbedient(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate);
    void KsVorsignalZugbedient(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate);

};

#endif // SYMBOLINOPENGL_H
