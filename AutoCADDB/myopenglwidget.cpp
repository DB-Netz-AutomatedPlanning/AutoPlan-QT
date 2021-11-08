#include "myopenglwidget.h"
#include "mainwindow.h"
#include <QtWidgets>

#include <QWidget>
#include <QSvgRenderer>
#include <QDebug>
#include "symbolinformation.h"
#include <QGraphicsProxyWidget>
#include <QGraphicsView>

QString glb;
QList<QString> listo ;

#include "coordinates.h"
#include "symbolcontainer.h"

static int countLoop = 0;
static int countLoopGleisKanten = 0;
bool countOkay = false;




MyOpenglWidget::MyOpenglWidget(QWidget *parent) : QOpenGLWidget(parent)
{
    setFormat(QSurfaceFormat::defaultFormat());
    setAcceptDrops(true);
}

MyOpenglWidget::~MyOpenglWidget()
{
    //cleanup();
    //window()->setStyleSheet("QLineEdit { border: none }");


}

void MyOpenglWidget::cleanup()
{
    makeCurrent();
    delete shaderProg;
    shaderProg = 0;
    doneCurrent();
}

//void MyOpenglWidget::delay()
//{
//    QTime dieTime= QTime::currentTime().addSecs(2);
//    while (QTime::currentTime() < dieTime)
//        qInfo()<< "";
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//}



struct EventInfo
{
int mcstrCMD_ID;
QString mcstrTYPE;
QString mcsKEYBOARDEVENT;
QString mcstrX;
QString mcstrY;
}eventInfo;

static const char *vertexShaderSource =
        "#version 430 core  \n"
        "layout(location = 0) in vec4 vPosition;\n"
        "uniform mat4 MVP ;\n"
        "void main()   \n"
        "{  \n"
        "   gl_Position = MVP * vPosition;   \n"
        "}\n";

static const char *fragmentShaderSource =
        "#version 430 core   \n"
           "out vec4 fColor;\n"
           "void main()\n"
           "{           \n"
           "   fColor = vec4(0.9, 0.0, 0.0, 1.0);   \n"
           "}";



//std::vector<std::vector<GLfloat>> vec;

const std::vector<std::vector<GLfloat>> testVector;


void MyOpenglWidget::initializeGL()
{
    //--------------------------------------



    //------------------------------------------
    //qDebug()<< "initialize start";
         connect(context(), &QOpenGLContext::aboutToBeDestroyed, this, &MyOpenglWidget::cleanup);

         initializeOpenGLFunctions(); // obvious
         glClearColor(0.0, 0.0, 0.0, 1.0);

         shaderProg = new QOpenGLShaderProgram;


         shaderProg->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
         shaderProg->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);

         Q_ASSERT(shaderProg->link());

         Q_ASSERT(shaderProg->bind());
         m_MVPMatrixLoc = shaderProg->uniformLocation("MVP");


         //vertex array object
         m_vao.create();
         QOpenGLVertexArrayObject::Binder vaoBinder(&m_vao);

         //setup vertex buffer object

         buffer = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
         buffer.setUsagePattern(QOpenGLBuffer::StaticDraw);
         Q_ASSERT(buffer.create());
         Q_ASSERT(buffer.bind());

         // Store the vertex attribute bindings for the program.

         const int vPosition = 0;

         glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0, NULL);

         glEnableVertexAttribArray(vPosition);

 //        viewMatrix.lookAt(
 //                    QVector3D(x, y, z), // Camera is at (x,y,z), in World Space
 //                    QVector3D(x, y, 0), // and looks at (x,y)
 //                    QVector3D(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
 //                    );

         shaderProg->release();

      // qDebug()<< "initialize end";


}
std::vector<std::vector<GLfloat>> vec;
std::vector<GLfloat> gleischknotenVector;
std::vector<std::vector<GLfloat>> GleiskantenVector;
void MyOpenglWidget::paintGL()
{

    //-------------------------------------------

    aPlanProjectPath = "E:/QT/Meggen";
    aPlanProjectName = "Meggen";

    countLoop +=1;
    if(countLoop <=1){
        aPlanFileName = "Entwurfselement_HO.dbahn";

        Coordinates *coord = new Coordinates(aPlanProjectPath, aPlanProjectName);
        coord->readCoordinates(aPlanFileName);

       int segmentSize = coord->getSegment().size();

       for (int i=0; i<segmentSize-1; i++){
           vec.push_back(std::vector<GLfloat>());
           for (int j=coord->getSegment()[i]; j< coord->getSegment()[i+1]; j++){
               vec[i].push_back(coord->getCoordinateLists()[j]);
           }
       }
      // qDebug()<< "Inside the if statement end";
    }



//    Coordinates *coord = new Coordinates("Meggen");
//    coord->readCoordinates("",2);

//    int rows=0;
//    foreach (int i, coord->getSegment()){
//        rows++;
//    }


//    for (int i=0; i<rows; i++){
//        vec.push_back(std::vector<GLfloat>());
//        for (int j=coord->getSegment()[i]; j< coord->getSegment()[i+1]; j++){
//            vec[i].push_back(coord->getCoordinateLists()[j]);
//        }
//    }



    //-------------------------------------------
   // qDebug()<< "start";

    //const std::vector<std::vector<GLfloat>> testVec = vec;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    shaderProg->enableAttributeArray("vPosition");

    QOpenGLVertexArrayObject::Binder vaoBinder(&m_vao);
    shaderProg->bind();

    modelMatrix.setToIdentity();

    mvp = projectionMatrix * viewMatrix * modelMatrix;

    shaderProg->setUniformValue(m_MVPMatrixLoc, mvp);

      showGleisknoten(aPlanProjectPath, aPlanProjectName);

      for(unsigned int i=0;i<vec.size();i++){
          for(unsigned int j=0;j<vec[i].size();j++){
              buffer.allocate( vec[i].size() *sizeof (GLfloat));
              buffer.write(0, &vec[i][0], vec[i].size() *sizeof (GLfloat));
              glDrawArrays(GL_LINE_STRIP, 0, vec[i].size()/2);
          }
      }

      viewMatrix.setToIdentity();
      viewMatrix.lookAt(
                  QVector3D(x, y, z), // Camera is at (x,y,z), in World Space
                  QVector3D(x, y, 0), // and looks at (x,y)
                  QVector3D(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
                  );

      projectionMatrix.setToIdentity();
      projectionMatrix.perspective(45.0f, (float)width()/(float)height(), z, z/1000);

      shaderProg->release();
     // qDebug()<< "end";
}


void MyOpenglWidget::openGLUpdate()
{
    update();
}


void MyOpenglWidget::mousePressEvent(QMouseEvent *event)
{
    //---------------- saif start -----------------
    if(event->button() == Qt::LeftButton){
        mouseLeftButtonPressed = true;
    }else if(event->button() == Qt::RightButton){
        mouseRightButtonPressed = true;
    }else if(event->button() == Qt::MiddleButton){
        scaleSpeed = scaleSpeed/1.1;
        qDebug()<< "Scale Speed : " <<scaleSpeed;
    }
    update();

    //----------------------------- saif end =------------

    QLabel *child = static_cast<QLabel*>(childAt(event->position().toPoint()));
    if (!child)
        return;
    str = child->objectName() ;

    //initiliaze glb string with object name
    if(!str.isNull()){
        glbObjectName=str;
        defaultObjectName = str;
    }


    QPixmap pixmap = child->pixmap(Qt::ReturnByValue);

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << pixmap << QPoint(event->position().toPoint() - child->pos());
//! [1]

//! [2]
    QMimeData *mimeData = new QMimeData;
    mimeData->setData("application/x-dnditemdata", itemData);

//! [2]

//! [3]
    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(event->position().toPoint() - child->pos());

    QPoint s = event->position().toPoint() - child->pos();
    QPointF f = s;
    //int ss =s;

//! [3]


    QPixmap tempPixmap = pixmap;
    QPainter painter;
    painter.begin(&tempPixmap);
    painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));

    painter.end();

    child->setPixmap(tempPixmap);

    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
        child->close();
    } else {
        child->show();
        child->setPixmap(pixmap);
    }



    testingFnt(child);




}
void MyOpenglWidget::testingFnt(QLabel *lbl) {
qInfo() << lbl;

}

void MyOpenglWidget::ctxMenu(const QPoint &pos) {
    QMenu *menu = new QMenu;
    menu->addAction(tr("Test Item"), this, SLOT(test_slot()));
    menu->exec();
}

void MyOpenglWidget::mouseReleaseEvent(QMouseEvent *event)
{
    //--------------------- saif start -------------------------
        update();
        double currentX = event->position().x();
        double currentY = (height()-1) - event->position().y();
        minToCenterChangeValueX = (8360*powerValueOfTwo);
        minToCenterChangeValueY = (4130*powerValueOfTwo);

        getLowestCoordinateX = (x-minToCenterChangeValueX);
        getLowestCoordinateY = (y-minToCenterChangeValueY);


        double getCoordinateX =getLowestCoordinateX + (((double)minToCenterChangeValueX/(((double)width())/2)) * currentX);
        double getCoordinateY =getLowestCoordinateY + (((double)minToCenterChangeValueY/(double)(height()/2)) * currentY);

       // qDebug()<<"(" <<currentX<<","<<currentY<<")";
        //qDebug() << qSetRealNumberPrecision( 15 ) << "x = " << x<< " y=" <<y<< " z= "<<z;
        //qDebug()<< qSetRealNumberPrecision( 15 ) <<"X Coordinate = "<< getCoordinateX;
        //qDebug()<< qSetRealNumberPrecision( 15 ) <<"Y Coordinate = "<< getCoordinateY;
        //qDebug()<< qSetRealNumberPrecision( 15 ) <<"Z Coordinate = "<< z;

        Q_UNUSED(event);
        mouseLeftButtonPressed = false;
        mouseRightButtonPressed = false;


        setSegmentInfoForCoordinate(getCoordinateX, getCoordinateY);
        QMap<QString, QString> map = getSegmentInfoForCoordinate();
       // setCoordinateinRightTable(map);
        // qInfo()<< getSegmentInfoForCoordinate();
      //  qInfo() << "count of" << getSegmentInfoForCoordinate().count();
        //countOfQmapCoordinates = getSegmentInfoForCoordinate().count();
         ELTYP = map["ELTYP"];
         ELTYP_L = map["ELTYP_L"];
         HOEHE_A = map["HOEHE_A"];
         HOEHE_E = map["HOEHE_E"];
         ID = map["ID"];
         KM_A_KM = map["KM_A_KM"];
         KM_A_M = map["KM_A_M"];
         KM_E_KM = map["KM_E_KM"];
         KM_E_M = map["KM_E_M"];
         PAD_A = map["PAD_A"];
         PARAM1 = map["PARAM1"];
         PARAM2 = map["PARAM2"];
         PARAM3 = map["PARAM3"];
         PARAM4 = map["PARAM4"];
         RIKZ = map["RIKZ"];
         RIKZ_L = map["RIKZ_L"];




        qInfo()<< map["ELTYP"];
        qInfo()<< map["ELTYP_L"];
        qInfo()<< map["HOEHE_A"];
        qInfo()<< map["HOEHE_E"];
        qInfo()<< map["ID"];
        qInfo()<< map["KM_A_KM"];
        qInfo()<< map["KM_A_M"];
        qInfo()<< map["KM_E_KM"];
        qInfo()<< map["KM_E_M"];
        qInfo()<< map["PAD_A"];
        qInfo()<< map["PARAM1"];
        qInfo()<< map["PARAM2"];
        qInfo()<< map["PARAM3"];
        qInfo()<< map["PARAM4"];
        qInfo()<< map["RIKZ"];
        qInfo()<< map["RIKZ_L"];
















//        double mouseX = event->position().rx();
//        double mouseY = (height()-1) - event->position().ry();

//        QMatrix4x4 inverseProjectionMatrix = projectionMatrix.inverted();
//        QMatrix4x4 inverseViewMatrix = viewMatrix.inverted();
//        QMatrix4x4 inverseModelMatrix = modelMatrix.inverted();
//        QMatrix4x4 inverseMVP = inverseProjectionMatrix * inverseViewMatrix * inverseModelMatrix;







//        double presentX, presentY;
//        presentX = (mouseX/ (float)width())*2.0f -1.0f;
//        presentY = (mouseY/ (float)height())*2.0f -1.0f;

//        QVector4D tmp = QVector4D(presentX, 0, 0, 1);
//        QVector4D xResult = tmp*inverseProjectionMatrix*inverseViewMatrix*inverseModelMatrix;
//        presentX = xResult.x();


//        //qDebug()<<  presentX;

        //-------------------------- saif end ------------------------------
}

void MyOpenglWidget::mouseMoveEvent(QMouseEvent *event)
{
    //----------------------- saif start --------------------------
    double currentX = event->position().x();
    double currentY = event->position().y();

    //qDebug()<< currentX;

    if(mouseLeftButtonPressed == true){
        if(dx < currentX){
            dx = currentX;
            x = x - scaleSpeed;
           // qDebug()<< "X increased value: "<< x;
        }else if(dx == currentX){
            dx = currentX;
           // qDebug()<< "X equal value: "<< x;
        }else{
            dx = currentX;
            x = x + scaleSpeed;
           // qDebug()<< "X decreased value: "<< x;
        }

        if(dy <currentY){
            dy = currentY;
            y = y + scaleSpeed;
           // qDebug()<< "Y increased value: "<< y;
        }else if(dy == currentY){
            dy = currentY;
           // qDebug()<< "Y equal value: "<< y;
        }else{
            dy = currentY;
            y = y - scaleSpeed;
           // qDebug()<< "Y decreased value: "<< y;
        }
    }
    update();

    // ------------------------ saif end ------------------------
}

void MyOpenglWidget::wheelEvent(QWheelEvent *event)
{
    // ------------------ saif start ---------------------
    QPoint numDegrees = event->angleDelta();
    if(numDegrees.y()>0){
        if(z>lowestZoomScale){
            z = z/zoomScale;
            if(z < compareTestZ){
                power = power -1;
                powerValueOfTwo = pow(2,power);
            }
          //  qDebug() << "Power Value: "<< powerValueOfTwo;
           // qDebug()<< "Z value: "<< z;
           // qDebug() << "CompareTestZ" << compareTestZ;
            compareTestZ = z;
        }
        update();
    }else if(numDegrees.y()<0){
        if(z<highestZoomScale){
            z = z*zoomScale;
            if(z > compareTestZ){
                power = power + 1;
                powerValueOfTwo = pow(2,power);
            }
          //  qDebug() << "PowerValue of 2 : "<< powerValueOfTwo;
           // qDebug()<< "Z value: "<< z;
           // qDebug() << "CompareTestZ" << compareTestZ;
            compareTestZ = z;
        }
        update();
    }

    // ---------------------- saif end -----------------------------
}

void MyOpenglWidget::resizeGL(int w, int h)
{
      Q_UNUSED(w); Q_UNUSED(h);
    setMaximumHeight(558);
    setMaximumWidth(1128);

    setMinimumHeight(558);
    setMinimumWidth(1128);
      //glViewport(0, 0, (GLint)width(), (GLint)height());
      //projectionMatrix.perspective(45.0f, (float)width()/(float)height(), z, z/1000);

}


//Drag icons
void MyOpenglWidget::dragEnterEvent(QDragEnterEvent *event)
{

    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();

        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }






}

void MyOpenglWidget::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }



}

void MyOpenglWidget::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPixmap pixmap;
        QPoint offset;
        dataStream >> pixmap >> offset;

        assignObjectName(glbObjectName);
        defaultObjectName = glbObjectName;


        MainWindow *w = new MainWindow();
        w->setObjNameTW(defaultObjectName);
        SymbolInformation *ss = new SymbolInformation();
        ss->updateLabel();



             newIcon->setPixmap(pixmap);
             newIcon->move(event->position().toPoint() - offset);
             newIcon->show();
             newIcon->setAttribute(Qt::WA_DeleteOnClose);


        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }



    newIcon->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(newIcon, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(ctxMenu(const QPoint &)));



}

// showGleisknoten
void MyOpenglWidget::showGleisknoten(QString path, QString projectName)
{

    Coordinates *coordinates = new Coordinates(path, projectName);
    coordinates->readCoordinates("Gleisknoten.dbahn");

    gleischknotenVector = coordinates->getCoordinateLists();

    for(unsigned int i=0;i<gleischknotenVector.size();i++){
        //for(unsigned int j=0;j<gleischknotenVector.size();j++){
            buffer.allocate( gleischknotenVector.size() *sizeof (GLfloat));
            buffer.write(0, &gleischknotenVector[0], gleischknotenVector.size() *sizeof (GLfloat));
            glDrawArrays(GL_POINTS, 0, gleischknotenVector.size()/2);
        //}
    }


}

void MyOpenglWidget::setSegmentInfoForCoordinate(double xCoordinate, double yCoordinate)
{
    QString projectPath = "E:/QT/Meggen";
    QString projectName = "Meggen";
    QString fileName = "Entwurfselement_HO.dbahn";
    Coordinates *coordinates = new Coordinates(projectPath, projectName);
    coordinates->readCoordinates(fileName);

    std::vector<QMap<QString,QString>> map = coordinates->getMap();
    QMap<QString, QString> mapTrack;

    vector<int> segmentNumberX;
    vector<int> segmentNumberY;
    int segmentNumber;



    int segmentSize = coordinates->getSegment().size()-1;



//    for (int i=0; i<segmentSize; i++){
//        for (int j=coordinates->getSegment()[i]; j< coordinates->getSegment()[i+1]; j++){
////              if(j%2 != 0){
////                 if(coordinates->getCoordinateLists()[j]>lessYYYY && coordinates->getCoordinateLists()[j]<greaterYYYY){
////                     segmentNumberY = i;
////                     qInfo()<< "Segment For Y: " <<segmentNumberY;
//////                     if(coordinates->getCoordinateLists()[j-1]>lessXXXX && coordinates->getCoordinateLists()[j-1]<greaterXXXX){
//////                         mapTrack = map[i];
//////                     }
////                     //qInfo()<< "Segment number: " <<i;
////                 }
////            }
//              if(j%2==0){
//                  if(coordinates->getCoordinateLists()[j]>lessXXXX && coordinates->getCoordinateLists()[j]<greaterXXXX){
//                      //mapTrack = map[i];
//                      segmentNumberX.push_back(i);
//                      //qInfo()<<"Segment for X: "<<segmentNumberX;
//                  }
//              }else{
//                  if(coordinates->getCoordinateLists()[j]>lessYYYY && coordinates->getCoordinateLists()[j]<greaterYYYY){
//                      segmentNumberY.push_back(i);
//                      //qInfo()<< "Segment For Y: " <<segmentNumberY;
// //                     if(coordinates->getCoordinateLists()[j-1]>lessXXXX && coordinates->getCoordinateLists()[j-1]<greaterXXXX){
// //                         mapTrack = map[i];
// //                     }
//                      //qInfo()<< "Segment number: " <<i;
//                  }
//              }

//        }
//    }

    for(int i=0; i<segmentSize; i++){
        for(int j=coordinates->getSegment()[i]; j<coordinates->getSegment()[i+1]; j++){
            if( j%2 == 0){
                if(xCoordinate>coordinates->getCoordinateLists()[j]-5 && xCoordinate < coordinates->getCoordinateLists()[j]+5 ){
                    segmentNumberX.push_back(i);
                }
            }else{
                if(yCoordinate>coordinates->getCoordinateLists()[j]-5 && yCoordinate < coordinates->getCoordinateLists()[j]+5 ){
                    segmentNumberY.push_back(i);
                }
            }
        }
    }


   // qInfo()<<"Segment X"<<segmentNumberX;

   // qInfo()<<"Segment Y"<<segmentNumberY;

    for(unsigned int i=0; i<segmentNumberX.size();i++){
        for(unsigned int j=0; j<segmentNumberY.size();j++){
            if(segmentNumberX[i] == segmentNumberY[j]){
                segmentNumber = segmentNumberX[i];
                   segmentInfoFromCoordinate = map[segmentNumber];
                return;
            }
        }
    }
    segmentInfoFromCoordinate = {};



//    qInfo()<<"Segment info: " << map[segmentNumber];

    //return mapTrack;
}

const QMap<QString, QString> &MyOpenglWidget::getSegmentInfoForCoordinate() const
{
    return segmentInfoFromCoordinate;
}

void MyOpenglWidget::sendObjectProperties(QString str){
    glb = str;
    listo.append(glb);
}

void MyOpenglWidget::assignObjectName(QString str){
   // qInfo() << "Symbol Name :"+str;
     //qInfo() << "--------------------------";

    if(str== "radsensor"){
             newIcon = new QLabel(this);

             newIcon->setObjectName("radsensor");

    }
    if(str== "hauptsignal"){
             newIcon = new QLabel(this);
              newIcon->setObjectName("hauptsignal");

    }
    if(str== "rangier"){
             newIcon = new QLabel(this);
             newIcon->setObjectName("rangier");

    }
    if(str== "vorsignal"){
              newIcon = new QLabel(this);
              newIcon->setObjectName("vorsignal");
    }
    if(str== "haltetafel"){
             newIcon = new QLabel(this);
             newIcon->setObjectName("haltetafel");
    }
    if(str== "schutzhalt"){
              newIcon = new QLabel(this);
              newIcon->setObjectName("schutzhalt");
    }
    if(str== "lbl_rightSignal"){
             newIcon = new QLabel(this);
             newIcon->setObjectName("lbl_rightSignal");
    }
    if(str== "lbl_vorsignal"){
             newIcon = new QLabel(this);
              newIcon->setObjectName("lbl_vorsignal");
    }
    if(str== "lbl_expanded"){
             newIcon = new QLabel(this);
             newIcon->setObjectName("lbl_expanded");
    }
    if(str== "lbl_stump"){
              newIcon = new QLabel(this);
              newIcon->setObjectName("lbl_stump");
    }
    if(str== "label_21"){
             newIcon = new QLabel(this);
             newIcon->setObjectName("label_21");
    }
    if(str== "lbl_shrim"){
              newIcon = new QLabel(this);
              newIcon->setObjectName("lbl_shrim");
    }
    if(str== "lbl_mehra"){
              newIcon = new QLabel(this);
              newIcon->setObjectName("lbl_mehra");
    }
}

void setCoordinateinRightTable(QMap<QString, QString> map){



   // qInfo()<< map["ELTYP"];
    // qInfo()<< map["ELTYP_L"];
    // qInfo()<< map["HOEHE_A"];
    // qInfo()<< map["HOEHE_E"];
    // qInfo()<< map["ID"];
    // qInfo()<< map["KM_A_KM"];
    // qInfo()<< map["KM_A_M"];
    // qInfo()<< map["KM_E_KM"];
    //qInfo()<< map["KM_E_M"];
    //qInfo()<< map["PAD_A"];
    //qInfo()<< map["PARAM1"];
    //qInfo()<< map["PARAM2"];
    //qInfo()<< map["PARAM3"];
    //qInfo()<< map["PARAM4"];
    //qInfo()<< map["RIKZ"];
    //qInfo()<< map["RIKZ_L"];

}
