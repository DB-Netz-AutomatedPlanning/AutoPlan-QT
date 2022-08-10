#include "mainwindow.h"
#include <QApplication>
#include <QFile>

//#include <GL/glut.h>

#include<QSurfaceFormat>
#include "coordinates.h"
#include "kmtocoordinate.h"
#include "symbolcontainer.h"
#include <QDirIterator>
#include <QDir>
#include <QFileInfoList>
#include <QFile>
#include<QFileDialog>
#include<QFileDevice>
#include<QTime>
#include "gleiskantenfromunprocessedjson.h"
#include "lagefromunprocessedjson.h"
#include "connecttocsharp.h"
#include "xml2json.h"
#include "planproelements.h"



int main(int argc, char *argv[])
{

    // qlutInit(&argc, argv);
    QApplication a(argc, argv);
    //    QFile styleFile(":/icons/assets/home/HackBook.qss"); //:/icons/assets/stylesheet/HackBook.qss
    ////    QFile styleFile("./HackBook.qss");  //./Medize.qss, ./Gravira.qss, ./Filmovio.qss, ./Dtor.qss, ./MailSy.qss
    //    if (!styleFile.open(QFile::ReadOnly)) qInfo() << "Cannot open Stylesheet file";
    //    else {
    //        QString styleSheet = QLatin1String(styleFile.readAll());
    //        a.setStyleSheet(styleSheet);
    //    }


    //    QString input = "D:/Users/BKU/OlatunjiAjala/Desktop/Data/Data/DSG_01-01_Neubau ESTW_2021-06-01_08-41.ppxml";
    //    QString output = "D:/Users/BKU/OlatunjiAjala/Documents/output/planpro.json";

    //    Xml2Json *json = new Xml2Json(nullptr, input, output);
    //    json->serializeXml2Json();



//    projectPath = "D:/Users/BKU/OlatunjiAjala/Documents";
//    projectName = "output";

//    PlanProElements *pp = new PlanProElements(nullptr);

//    std::vector<std::vector<QString>> topKanten = pp->top_kanten();
//    foreach (std::vector<QString> each, topKanten){
//        qInfo() << "{";
//        foreach (QString point, each){
//            qInfo() << point;
//        }
//        qInfo() << "}";
//    }


//    qInfo()<< "\n\n\n";
//    //    std::vector<std::vector<QString>> topKanten = pp->top_kanten();
//    QMap<QString, QString> knoten = pp->top_knoten();
//    QStringList keys = knoten.keys();
//    QStringList values = knoten.values();

//    for (int i=0; i< keys.length(); i++){
//        qInfo() << "{";
//        qInfo()<< "Key: "<< keys.at(i);
//        qInfo()<< "Value: "<< values.at(i);
//        qInfo() << "}";
//    }

//    qInfo()<< "GEoPunkt \n\n";
//    pp->geo_punkt();


        MainWindow w;
        w.setWindowState(Qt::WindowMaximized);
        w.show();


//        projectPath = "D:/Users/BKU/OlatunjiAjala/Documents";
//        projectName = "output";

//        PlanProElements *pp = new PlanProElements(nullptr, "D:/Users/BKU/OlatunjiAjala/Documents/pdf/aLWAYS/temp/Gleiskanten.json",
//                                                  "D:/Users/BKU/OlatunjiAjala/Documents/pdf/aLWAYS/temp/Gleisknoten.json");
//        pp->createJson();
//        pp->createKnotenJson();


    //    ConnectToCSharp * cs = new ConnectToCSharp(nullptr,"D:/Users/BKU/OlatunjiAjala/Documents/pdf/eulynxhallo.euxml","D:/Users/BKU/OlatunjiAjala/Documents/output");
    //    cs->cSharp();

    //    QChar tt = cs->solutions();
    //    qInfo()<< "ddd: "<< tt;




    //    qDebug() << "Start : " << QTime::currentTime();
    //    GleiskantenFromUnprocessedJson *tryKanten = new GleiskantenFromUnprocessedJson(nullptr, "C:/Users/OlatunjiAjala/source/repos/APLAN-CORE/main/output/UnprocessedJson.json", "D:/Users/BKU/OlatunjiAjala/Documents/output/testKanten2.json");
    //    tryKanten->createJson();
    //    qDebug() << "End : " << QTime::currentTime();

    //    qDebug() << "Start : " << QTime::currentTime();
    //    LageFromUnprocessedJson * tryLage = new LageFromUnprocessedJson (nullptr, "C:/Users/OlatunjiAjala/source/repos/APLAN-CORE/main/output/UnprocessedJson.json", "D:/Users/BKU/OlatunjiAjala/Documents/output/testLage2.json");
    //    tryLage->createJson();
    //    qDebug() << "End : " << QTime::currentTime();




    return a.exec();
}


