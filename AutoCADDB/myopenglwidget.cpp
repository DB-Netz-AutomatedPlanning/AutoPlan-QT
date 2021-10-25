#include "myopenglwidget.h"
#include "mainwindow.h"
#include <QtWidgets>
// #include <QOpenGLWidget>
#include <QWidget>
#include <QSvgRenderer>
#include <QDebug>
QString glb;
QList<QString> listo ;

#include "coordinates.h"
#include "symbolcontainer.h"

static int countLoop = 0;
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
    qDebug()<< "initialize start";
         connect(context(), &QOpenGLContext::aboutToBeDestroyed, this, &MyOpenglWidget::cleanup);

         initializeOpenGLFunctions(); // obvious
         glClearColor(1.0, 1.0, 1.0, 1.0);

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

       qDebug()<< "initialize end";


}
std::vector<std::vector<GLfloat>> vec;
void MyOpenglWidget::paintGL()
{
    if(isActive){

    //-------------------------------------------

    countLoop +=1;
    if(countLoop <=1){
        Coordinates *coord = new Coordinates(projectPath, projectName);
        coord->readCoordinates(geoJsonFileName,geoJsonCodeNo);

       int segmentSize = coord->getSegment().size();

       for (int i=0; i<segmentSize; i++){
           vec.push_back(std::vector<GLfloat>());
           for (int j=coord->getSegment()[i]; j< coord->getSegment()[i+1]; j++){
               vec[i].push_back(coord->getCoordinateLists()[j]);
           }
       }
       qDebug()<< "Inside the if statement end";
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
    qDebug()<< "start";

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
      qDebug()<< "end";
    }
}


void MyOpenglWidget::openGLUpdate()
{
    update();
}


void MyOpenglWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        mouseLeftButtonPressed = true;
    }else if(event->button() == Qt::RightButton){
        mouseRightButtonPressed = true;
        scaleSpeed = scaleSpeed*1.1;
        qDebug()<< "Scale Speed : " <<scaleSpeed;
    }else if(event->button() == Qt::MiddleButton){
        scaleSpeed = scaleSpeed/1.1;
        qDebug()<< "Scale Speed : " <<scaleSpeed;
    }

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


    qInfo() << "--------------------------";
    qInfo() << "Position from top-left corner :";
    qInfo() << event->position().toPoint() - child->pos();
   qInfo() << "--------------------------";
    qInfo() << "Symbol Position :";
    qInfo() << f;
     qInfo() << "--------------------------";
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

       MainWindow *w = new MainWindow();
       w->setObjNameTW("radsensor");


     //  QLabel *st = new QLabel(this);


}


void MyOpenglWidget::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    mouseLeftButtonPressed = false;
    mouseRightButtonPressed = false;
}

void MyOpenglWidget::mouseMoveEvent(QMouseEvent *event)
{

    double currentX = event->position().x();
    double currentY = event->position().y();

    if(mouseLeftButtonPressed == true){
        if(dx < currentX){
            dx = currentX;
            x = x - scaleSpeed;
            qDebug()<< "X increased value: "<< x;
        }else if(dx == currentX){
            dx = currentX;
            qDebug()<< "X equal value: "<< x;
        }else{
            dx = currentX;
            x = x + scaleSpeed;
            qDebug()<< "X decreased value: "<< x;
        }

        if(dy <currentY){
            dy = currentY;
            y = y + scaleSpeed;
            qDebug()<< "Y increased value: "<< y;
        }else if(dy == currentY){
            dy = currentY;
            qDebug()<< "Y equal value: "<< y;
        }else{
            dy = currentY;
            y = y - scaleSpeed;
            qDebug()<< "Y decreased value: "<< y;
        }
    }
    update();
}

void MyOpenglWidget::wheelEvent(QWheelEvent *event)
{
    QPoint numDegrees = event->angleDelta();

    if(numDegrees.y()>0){
            z = z/1.1;
    }else if(numDegrees.y()<0){
        if(z<highestZoomScale){
            z = z*1.1;
        }
    }
    qDebug()<< "Z value: "<<z;

    update();
}

void MyOpenglWidget::resizeGL(int w, int h)
{
      Q_UNUSED(w); Q_UNUSED(h);
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

        QTableWidget *tableWidget = new QTableWidget(this);
        tableWidget->setRowCount(2);
        tableWidget->setColumnCount(2);
        QTableWidgetItem *newItem = new QTableWidgetItem(tr("%0").arg("Name"));
        tableWidget->setItem(0, 0, newItem);
        QTableWidgetItem *newItem1 = new QTableWidgetItem(tr("%1").arg(defaultObjectName));
        tableWidget->setItem(0, 1, newItem1);
        QTableWidgetItem *newItem2 = new QTableWidgetItem(tr("%1").arg("Position"));
        tableWidget->setItem(1, 0, newItem2);

        tableWidget->setFixedSize(217,87);
        tableWidget->show();

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




}

void MyOpenglWidget::sendObjectProperties(QString str){
    glb = str;
    listo.append(glb);
}

void MyOpenglWidget::assignObjectName(QString str){
    qInfo() << "Symbol Name :"+str;
     qInfo() << "--------------------------";

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
