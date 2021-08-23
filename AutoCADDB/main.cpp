#include "mainwindow.h"

#include <QApplication>

//#include <GL/glut.h>

#include<QSurfaceFormat>



int main(int argc, char *argv[])
{
   // qlutInit(&argc, argv);
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.setWindowState(Qt::WindowMaximized);
//    w.show();
//    return a.exec();

    QApplication a(argc,argv);
    QSurfaceFormat format;
    format.setRenderableType(QSurfaceFormat::OpenGL);
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setVersion(3,3);



    MainWindow w;

    w.show();

    return a.exec();


}
