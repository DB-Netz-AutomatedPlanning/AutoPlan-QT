#include "symbolinopengl.h"

SymbolInOpengl::SymbolInOpengl()
{

}

void SymbolInOpengl::drawRectangleWithLine(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate)
{

        drawFilledRectangle(buffer, xCoordinate, yCoordinate);
        drawNotFilledRectangle(buffer, xCoordinate+8, yCoordinate);

        drawCornerShapeSquare(buffer, xCoordinate+8, yCoordinate);

        drawFilledRectangle(buffer, xCoordinate+18, yCoordinate);
}

void SymbolInOpengl::drawFilledRectangle(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate)
{
    vector<vector<GLfloat>> polygonCoordinate = {};
    vector<GLfloat> eachPolygonCoordinate = {};


    eachPolygonCoordinate.push_back(xCoordinate);
    eachPolygonCoordinate.push_back(yCoordinate);
    eachPolygonCoordinate.push_back(xCoordinate);
    eachPolygonCoordinate.push_back(yCoordinate+0.5);
    eachPolygonCoordinate.push_back(xCoordinate+6);
    eachPolygonCoordinate.push_back(yCoordinate+0.5);
    eachPolygonCoordinate.push_back(xCoordinate+6);
    eachPolygonCoordinate.push_back(yCoordinate);
    eachPolygonCoordinate.push_back(xCoordinate+6);
    eachPolygonCoordinate.push_back(yCoordinate-0.5);
    eachPolygonCoordinate.push_back(xCoordinate);
    eachPolygonCoordinate.push_back(yCoordinate-0.5);
    polygonCoordinate.push_back(eachPolygonCoordinate);

    for(unsigned int i=0;i<polygonCoordinate.size();i++){
        //for(unsigned int j=0;j<polygonCoordinate[i].size();j++){
            buffer.allocate( polygonCoordinate[i].size() *sizeof (GLfloat));
            buffer.write(0, &polygonCoordinate[i][0], polygonCoordinate[i].size() *sizeof (GLfloat));
            glDrawArrays(GL_POLYGON, 0, polygonCoordinate[i].size()/2);
        //}
    }
}

void SymbolInOpengl::drawCornerShapeSquare(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate)
{
    vector<vector<GLfloat>> lineCoordinates = {};
        vector<GLfloat> eachLineCoordinates = {};

        eachLineCoordinates.push_back(xCoordinate);
        eachLineCoordinates.push_back(yCoordinate);
        eachLineCoordinates.push_back(xCoordinate+1.5);
        eachLineCoordinates.push_back(yCoordinate+2);
        eachLineCoordinates.push_back(xCoordinate+3);
        eachLineCoordinates.push_back(yCoordinate);
        eachLineCoordinates.push_back(xCoordinate+1.5);
        eachLineCoordinates.push_back(yCoordinate-2);
        eachLineCoordinates.push_back(xCoordinate);
        eachLineCoordinates.push_back(yCoordinate);

        lineCoordinates.push_back(eachLineCoordinates);

        for(unsigned int i=0;i<lineCoordinates.size();i++){
                buffer.allocate( lineCoordinates[i].size() *sizeof (GLfloat));
                buffer.write(0, &lineCoordinates[i][0], lineCoordinates[i].size() *sizeof (GLfloat));
                glDrawArrays(GL_LINE_STRIP, 0, lineCoordinates[i].size()/2);
        }

}

void SymbolInOpengl::drawNotFilledRectangle(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate)
{
    vector<vector<GLfloat>> lineCoordinates = {};
    vector<GLfloat> eachLineCoordinates = {};

    eachLineCoordinates.push_back(xCoordinate);
    eachLineCoordinates.push_back(yCoordinate);
    eachLineCoordinates.push_back(xCoordinate);
    eachLineCoordinates.push_back(yCoordinate+2);
    eachLineCoordinates.push_back(xCoordinate+8);
    eachLineCoordinates.push_back(yCoordinate+2);
    eachLineCoordinates.push_back(xCoordinate+8);
    eachLineCoordinates.push_back(yCoordinate);
    eachLineCoordinates.push_back(xCoordinate+8);
    eachLineCoordinates.push_back(yCoordinate-2);
    eachLineCoordinates.push_back(xCoordinate);
    eachLineCoordinates.push_back(yCoordinate-2);
    eachLineCoordinates.push_back(xCoordinate);
    eachLineCoordinates.push_back(yCoordinate);

    lineCoordinates.push_back(eachLineCoordinates);

    for(unsigned int i=0;i<lineCoordinates.size();i++){
            buffer.allocate( lineCoordinates[i].size() *sizeof (GLfloat));
            buffer.write(0, &lineCoordinates[i][0], lineCoordinates[i].size() *sizeof (GLfloat));
            glDrawArrays(GL_LINE_STRIP, 0, lineCoordinates[i].size()/2);
    }
}

void SymbolInOpengl::filledCornerShapedSquare(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate)
{
    vector<vector<GLfloat>> lineCoordinates = {};
    vector<GLfloat> eachLineCoordinates = {};

    eachLineCoordinates.push_back(xCoordinate);
    eachLineCoordinates.push_back(yCoordinate);
    eachLineCoordinates.push_back(xCoordinate+1.5);
    eachLineCoordinates.push_back(yCoordinate+2);
    eachLineCoordinates.push_back(xCoordinate+3);
    eachLineCoordinates.push_back(yCoordinate);
    eachLineCoordinates.push_back(xCoordinate+1.5);
    eachLineCoordinates.push_back(yCoordinate-2);

    lineCoordinates.push_back(eachLineCoordinates);

     for(unsigned int i=0;i<lineCoordinates.size();i++){
         //for(unsigned int j=0;j<lineCoordinates[i].size();j++){
             buffer.allocate( lineCoordinates[i].size() *sizeof (GLfloat));
             buffer.write(0, &lineCoordinates[i][0], lineCoordinates[i].size() *sizeof (GLfloat));
             glDrawArrays(GL_POLYGON, 0, lineCoordinates[i].size()/2);
         //}
     }
}

void SymbolInOpengl::drawRectangleWithLineWithFilledCornerSquare(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate)
{
    drawFilledRectangle(buffer, xCoordinate, yCoordinate);
    drawNotFilledRectangle(buffer, xCoordinate+8, yCoordinate);

    filledCornerShapedSquare(buffer, xCoordinate+8, yCoordinate);

    drawFilledRectangle(buffer, xCoordinate+18, yCoordinate);
}

void SymbolInOpengl::drawRectangleWithLineWithFilledCornerSquareAtRight(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate)
{
    drawFilledRectangle(buffer, xCoordinate, yCoordinate);
    drawNotFilledRectangle(buffer, xCoordinate+8, yCoordinate);

    filledCornerShapedSquare(buffer, xCoordinate+13, yCoordinate);

    drawFilledRectangle(buffer, xCoordinate+18, yCoordinate);
}

void SymbolInOpengl::Trapeztafel(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate)
{
    vector<vector<GLfloat>> lineCoordinates = {};
    vector<GLfloat> eachLineCoordinates = {};

    tail(buffer, xCoordinate, yCoordinate);

    eachLineCoordinates.push_back(xCoordinate+10);
    eachLineCoordinates.push_back(yCoordinate);
    eachLineCoordinates.push_back(xCoordinate+10);
    eachLineCoordinates.push_back(yCoordinate+5);
    eachLineCoordinates.push_back(xCoordinate+16);
    eachLineCoordinates.push_back(yCoordinate+3);
    eachLineCoordinates.push_back(xCoordinate+16);
    eachLineCoordinates.push_back(yCoordinate-3);
    eachLineCoordinates.push_back(xCoordinate+10);
    eachLineCoordinates.push_back(yCoordinate-5);
    eachLineCoordinates.push_back(xCoordinate+10);
    eachLineCoordinates.push_back(yCoordinate);
    lineCoordinates.push_back(eachLineCoordinates);

    for(unsigned int i=0;i<lineCoordinates.size();i++){
            buffer.allocate( lineCoordinates[i].size() *sizeof (GLfloat));
            buffer.write(0, &lineCoordinates[i][0], lineCoordinates[i].size() *sizeof (GLfloat));
            glDrawArrays(GL_LINE_STRIP, 0, lineCoordinates[i].size()/2);
    }



}

void SymbolInOpengl::Vorsignaltafel(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate)
{
    vector<vector<GLfloat>> lineCoordinates = {};
    vector<GLfloat> eachLineCoordinates = {};

    tail(buffer, xCoordinate, yCoordinate);

    eachLineCoordinates.push_back(xCoordinate+10);
    eachLineCoordinates.push_back(yCoordinate);
    eachLineCoordinates.push_back(xCoordinate+10);
    eachLineCoordinates.push_back(yCoordinate+3);
    eachLineCoordinates.push_back(xCoordinate+20);
    eachLineCoordinates.push_back(yCoordinate+3);
    eachLineCoordinates.push_back(xCoordinate+20);
    eachLineCoordinates.push_back(yCoordinate-3);
    eachLineCoordinates.push_back(xCoordinate+10);
    eachLineCoordinates.push_back(yCoordinate-3);
    eachLineCoordinates.push_back(xCoordinate+10);
    eachLineCoordinates.push_back(yCoordinate);
    lineCoordinates.push_back(eachLineCoordinates);

    eachLineCoordinates.push_back(xCoordinate+10);
    eachLineCoordinates.push_back(yCoordinate+3);
    eachLineCoordinates.push_back(xCoordinate+20);
    eachLineCoordinates.push_back(yCoordinate-3);
    lineCoordinates.push_back(eachLineCoordinates);

    eachLineCoordinates.push_back(xCoordinate+10);
    eachLineCoordinates.push_back(yCoordinate-3);
    eachLineCoordinates.push_back(xCoordinate+20);
    eachLineCoordinates.push_back(yCoordinate+3);
    lineCoordinates.push_back(eachLineCoordinates);

    for(unsigned int i=0;i<lineCoordinates.size();i++){
            buffer.allocate( lineCoordinates[i].size() *sizeof (GLfloat));
            buffer.write(0, &lineCoordinates[i][0], lineCoordinates[i].size() *sizeof (GLfloat));
            glDrawArrays(GL_LINE_STRIP, 0, lineCoordinates[i].size()/2);
    }


}

void SymbolInOpengl::Haltepunkttafel(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate)
{
    vector<vector<GLfloat>> lineCoordinates = {};
    vector<GLfloat> eachLineCoordinates = {};

    tail(buffer,xCoordinate, yCoordinate+5);
    tail(buffer,xCoordinate, yCoordinate-5);

    angleLine(buffer, xCoordinate+10, yCoordinate+6);
    angleLine(buffer, xCoordinate+10, yCoordinate+2);
    angleLine(buffer, xCoordinate+10, yCoordinate-2);

    eachLineCoordinates.push_back(xCoordinate+10);
    eachLineCoordinates.push_back(yCoordinate);
    eachLineCoordinates.push_back(xCoordinate+10);
    eachLineCoordinates.push_back(yCoordinate+8);
    eachLineCoordinates.push_back(xCoordinate+14);
    eachLineCoordinates.push_back(yCoordinate+8);
    eachLineCoordinates.push_back(xCoordinate+14);
    eachLineCoordinates.push_back(yCoordinate-8);
    eachLineCoordinates.push_back(xCoordinate+10);
    eachLineCoordinates.push_back(yCoordinate-8);
    eachLineCoordinates.push_back(xCoordinate+10);
    eachLineCoordinates.push_back(yCoordinate);
    lineCoordinates.push_back(eachLineCoordinates);


    for(unsigned int i=0;i<lineCoordinates.size();i++){
            buffer.allocate( lineCoordinates[i].size() *sizeof (GLfloat));
            buffer.write(0, &lineCoordinates[i][0], lineCoordinates[i].size() *sizeof (GLfloat));
            glDrawArrays(GL_LINE_STRIP, 0, lineCoordinates[i].size()/2);
    }



}

void SymbolInOpengl::angleLine(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate)
{

    vector<vector<GLfloat>> lineCoordinates = {};
    vector<GLfloat> eachLineCoordinates = {};


    eachLineCoordinates.push_back(xCoordinate);
    eachLineCoordinates.push_back(yCoordinate);
    eachLineCoordinates.push_back(xCoordinate+4);
    eachLineCoordinates.push_back(yCoordinate-4);
    lineCoordinates.push_back(eachLineCoordinates);

    for(unsigned int i=0;i<lineCoordinates.size();i++){
            buffer.allocate( lineCoordinates[i].size() *sizeof (GLfloat));
            buffer.write(0, &lineCoordinates[i][0], lineCoordinates[i].size() *sizeof (GLfloat));
            glDrawArrays(GL_LINE_STRIP, 0, lineCoordinates[i].size()/2);
    }
}



void SymbolInOpengl::tail(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate)
{
    vector<vector<GLfloat>> lineCoordinates = {};
    vector<GLfloat> eachLineCoordinates = {};

    eachLineCoordinates.push_back(xCoordinate);
    eachLineCoordinates.push_back(yCoordinate);
    eachLineCoordinates.push_back(xCoordinate);
    eachLineCoordinates.push_back(yCoordinate+2);
    eachLineCoordinates.push_back(xCoordinate);
    eachLineCoordinates.push_back(yCoordinate-2);
    lineCoordinates.push_back(eachLineCoordinates);


    eachLineCoordinates.push_back(xCoordinate);
    eachLineCoordinates.push_back(yCoordinate);
    eachLineCoordinates.push_back(xCoordinate+10);
    eachLineCoordinates.push_back(yCoordinate);
    lineCoordinates.push_back(eachLineCoordinates);




    for(unsigned int i=0;i<lineCoordinates.size();i++){
            buffer.allocate( lineCoordinates[i].size() *sizeof (GLfloat));
            buffer.write(0, &lineCoordinates[i][0], lineCoordinates[i].size() *sizeof (GLfloat));
            glDrawArrays(GL_LINE_STRIP, 0, lineCoordinates[i].size()/2);
    }
}

void SymbolInOpengl::drawRectangleWithRightCornerSquare(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate)
{

    drawFilledRectangle(buffer, xCoordinate, yCoordinate);
    drawNotFilledRectangle(buffer, xCoordinate+8, yCoordinate);

    drawCornerShapeSquare(buffer, xCoordinate+13, yCoordinate);

    drawFilledRectangle(buffer, xCoordinate+18, yCoordinate);
}

void SymbolInOpengl::halfCircle(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate, double angle)
{

    GLint numberOfSide = 300;
    GLint numberOfVertices = numberOfSide + 1;
    GLfloat doublePI = M_PI;
    GLfloat radius = 4;


    vector<GLfloat> halfCircleEachPoint = {};
    vector<vector<GLfloat>> halfCircle = {};

    for(int i=angle; i< numberOfVertices+angle; i++){
        halfCircleEachPoint.push_back( xCoordinate + (radius * cos(i * doublePI / numberOfSide)));
        halfCircleEachPoint.push_back( yCoordinate + (radius * sin(i * doublePI / numberOfSide)));
    }

    halfCircle.push_back(halfCircleEachPoint);

    for(unsigned int i=0; i<halfCircle.size() ; i++){
            buffer.allocate( halfCircle[i].size() *sizeof (GLfloat));
            buffer.write(0, &halfCircle[i][0], halfCircle[i].size() *sizeof (GLfloat));
            glDrawArrays(GL_LINE_STRIP, 0, halfCircle[i].size()/2);
    }










}

void SymbolInOpengl::filledHalfCircle(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate, double angle)
{

    GLint numberOfSide = 300;
    GLint numberOfVertices = numberOfSide + 2;
    GLfloat doublePI = M_PI;
    GLfloat radius = 4;


    vector<GLfloat> halfCircleEachPoint = {};
    vector<vector<GLfloat>> halfCircle = {};

    for(int i=angle; i< numberOfVertices+angle; i++){
        halfCircleEachPoint.push_back( xCoordinate + (radius * cos(i * doublePI / numberOfSide)));
        halfCircleEachPoint.push_back( yCoordinate + (radius * sin(i * doublePI / numberOfSide)));
    }

    halfCircle.push_back(halfCircleEachPoint);

    for(unsigned int i=0; i<halfCircle.size() ; i++){
            buffer.allocate( halfCircle[i].size() *sizeof (GLfloat));
            buffer.write(0, &halfCircle[i][0], halfCircle[i].size() *sizeof (GLfloat));
            glDrawArrays(GL_TRIANGLE_FAN, 0, halfCircle[i].size()/2);
    }
}

void SymbolInOpengl::boxOpenedRight(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate)
{
    vector<vector<GLfloat>> lineCoordinates = {};
    vector<GLfloat> eachLineCoordinates = {};

    eachLineCoordinates.push_back(xCoordinate+6);
    eachLineCoordinates.push_back(yCoordinate+4);
    eachLineCoordinates.push_back(xCoordinate);
    eachLineCoordinates.push_back(yCoordinate+4);
    eachLineCoordinates.push_back(xCoordinate);
    eachLineCoordinates.push_back(yCoordinate);
    eachLineCoordinates.push_back(xCoordinate);
    eachLineCoordinates.push_back(yCoordinate-4);
    eachLineCoordinates.push_back(xCoordinate+6);
    eachLineCoordinates.push_back(yCoordinate-4);
    lineCoordinates.push_back(eachLineCoordinates);


    for(unsigned int i=0;i<lineCoordinates.size();i++){
            buffer.allocate( lineCoordinates[i].size() *sizeof (GLfloat));
            buffer.write(0, &lineCoordinates[i][0], lineCoordinates[i].size() *sizeof (GLfloat));
            glDrawArrays(GL_LINE_STRIP, 0, lineCoordinates[i].size()/2);
    }
}

void SymbolInOpengl::boxOpenedLeft(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate)
{
    vector<vector<GLfloat>> lineCoordinates = {};
    vector<GLfloat> eachLineCoordinates = {};

    eachLineCoordinates.push_back(xCoordinate);
    eachLineCoordinates.push_back(yCoordinate+4);
    eachLineCoordinates.push_back(xCoordinate+4);
    eachLineCoordinates.push_back(yCoordinate+4);
    eachLineCoordinates.push_back(xCoordinate+4);
    eachLineCoordinates.push_back(yCoordinate);
    eachLineCoordinates.push_back(xCoordinate+4);
    eachLineCoordinates.push_back(yCoordinate-4);
    eachLineCoordinates.push_back(xCoordinate);
    eachLineCoordinates.push_back(yCoordinate-4);
    lineCoordinates.push_back(eachLineCoordinates);


    for(unsigned int i=0;i<lineCoordinates.size();i++){
            buffer.allocate( lineCoordinates[i].size() *sizeof (GLfloat));
            buffer.write(0, &lineCoordinates[i][0], lineCoordinates[i].size() *sizeof (GLfloat));
            glDrawArrays(GL_LINE_STRIP, 0, lineCoordinates[i].size()/2);
    }
}

void SymbolInOpengl::KsHauptsignalZugbedient(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate)
{
    tail(buffer, xCoordinate, yCoordinate);
    boxOpenedRight(buffer, xCoordinate+10, yCoordinate);
    halfCircle(buffer, xCoordinate+16, yCoordinate, 450);




}

void SymbolInOpengl::KsVorsignalZugbedient(QOpenGLBuffer buffer, double xCoordinate, double yCoordinate)
{
    tail(buffer, xCoordinate, yCoordinate);
    halfCircle(buffer, xCoordinate+14, yCoordinate, 150);
    boxOpenedLeft(buffer, xCoordinate+13, yCoordinate);

}
