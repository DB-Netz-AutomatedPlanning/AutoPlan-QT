#include "mainwindow.h"
#include "connecttocsharp.h"
#include <QApplication>

//#include <GL/glut.h>

#include<QSurfaceFormat>



int main(int argc, char *argv[])
{
   // qlutInit(&argc, argv);
   QApplication a(argc, argv);
   MainWindow w;
   w.setWindowState(Qt::WindowMaximized);
   w.show();



   //Felix code
   // ConnectToCSharp test(nullptr,"11.11","22.22");
    //test.cSharp();
//  foreach(QString val, test.solutions()){

  //    qInfo()<< val;
    //}

    return a.exec();



}
