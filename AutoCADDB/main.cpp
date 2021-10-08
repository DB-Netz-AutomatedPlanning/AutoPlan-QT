#include "mainwindow.h"
#include <QApplication>
#include <QFile>

//#include <GL/glut.h>

#include<QSurfaceFormat>


int main(int argc, char *argv[])
{

   // qlutInit(&argc, argv);
   QApplication a(argc, argv);
//   QFile styleFile("./Medize.qss");
//   styleFile.open(QFile::ReadOnly);
//   QString styleSheet = QLatin1String(styleFile.readAll());
//   a.setStyleSheet(styleSheet);

   MainWindow w;
   w.setWindowState(Qt::WindowMaximized);
   w.show();


    return a.exec();
}
