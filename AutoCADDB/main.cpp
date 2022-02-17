#include "mainwindow.h"
#include <QApplication>
#include <QFile>

//#include <GL/glut.h>

#include<QSurfaceFormat>
#include "coordinates.h"
#include "kmtocoordinate.h"


int main(int argc, char *argv[])
{

   // qlutInit(&argc, argv);
   QApplication a(argc, argv);
   QFile styleFile(":/icons/assets/stylesheet/HackBook.qss"); //
   //QFile styleFile("./HackBook.qss");  //./Medize.qss, ./Gravira.qss, ./Filmovio.qss, ./Dtor.qss, ./MailSy.qss
   styleFile.open(QFile::ReadOnly);
   QString styleSheet = QLatin1String(styleFile.readAll());
   a.setStyleSheet(styleSheet);

   MainWindow w;
   w.setWindowState(Qt::WindowMaximized);
   w.show();





//   std::vector<std::vector<float>> vec;
//   Coordinates *coord = new Coordinates("C:/Users/DR-PHELZ/Documents/pdf","Meggen");
//   coord->readCoordinates("Gleiskanten.dbahn");

//   int segmentSize = coord->getSegment().size();

//   for (int i=0; i<segmentSize-1; i++){
//       vec.push_back(std::vector<float>());
//       for (int j=coord->getSegment()[i]; j< coord->getSegment()[i+1]; j++){
//           vec[i].push_back(coord->getCoordinateLists()[j]);
//       }
//   }

//   std::vector<QMap<QString, QString>> map = coord->getMap();

//   foreach (auto val, map){
//       qInfo()<< "{";
//       qInfo()<< val.keys();
//       qInfo()<< val.values();
//       qInfo()<< "}";
//   }



//   foreach (auto val, vec){
//       qInfo()<< "{";
//       int count =0;
//       while (count < static_cast<int>(val.size())){
//           qInfo()<< val[count] << "  ,  "<< val[count+1];
//           count =  count +2;
//       }
//       //counter++;
//       qInfo()<< "}";
//   }


//   foreach (auto val, vec){
//       qInfo()<< "{";
//       foreach(auto each, val){
//           qInfo()<< each;
//       }
//       qInfo()<< "}";
//   }


    return a.exec();
}


