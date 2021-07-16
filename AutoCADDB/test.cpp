#include "test.h"
#include "ui_test.h"
#include <QTabWidget>
#include <QTabBar>
#include<QDebug>
#include<QWidget>
#include<QLabel>
#include<QPushButton>
#include<QToolButton>
#include<QMdiArea>
#include<QMdiSubWindow>
Test::Test(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Test)
{
    ui->setupUi(this);


   // setSurfaceType(QWindow::OpenGLSurface);
//    QToolButton *tb = new QToolButton();
//    tb->setText("+");
//    connect(tb, SIGNAL(clicked()), this, SLOT(addTab()));
//    ui->tabWidget->tabBar()->setTabButton(ui->tabWidget->tabBar()->count()-1, QTabBar::LeftSide, tb);;


        // Create button what must be placed in tabs row
        QToolButton* tb = new QToolButton(this);
        tb->setText("+");

        // Add empty, not enabled tab to tabWidget
        ui->tabWidget->addTab(new QLabel("Add tabs by pressing \"+\""), QString());
        ui->tabWidget->setTabEnabled(ui->tabWidget->tabBar()->count()-1, false);

        // Add tab button to current tab. Button will be enabled, but tab -- not
        ui->tabWidget->tabBar()->setTabButton(ui->tabWidget->tabBar()->count()-1, QTabBar::RightSide, tb);

        // Setting tabs closable and movable
        ui->tabWidget->setTabsClosable(true);
        ui->tabWidget->setMovable(true);
        connect(tb,SIGNAL(clicked()),this,SLOT(addTab()));
        connect(ui->tabWidget,SIGNAL(tabCloseRequested(int)),this,SLOT(slotCloseTab(int)));




        connect(ui->actionver, SIGNAL(triggered()), this, SLOT(tileSubWindowsVertically()));
        connect(ui->actionhori, SIGNAL(triggered()), this, SLOT(tileSubWindowsHorizontally()));

}



Test::~Test()
{
    delete ui;
}




void Test::addTab()
{
     ui->tabWidget->insertTab(ui->tabWidget->count() - 1,new QWidget(),QString("Tab %0").arg(ui->tabWidget->count() + 1));
     ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 2);
}

void Test::slotCloseTab(int index)
{
    delete ui->tabWidget->widget(index);
}

void Test::on_pushButton_clicked()
{

//    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
//        QString connectString = QStringLiteral(
//            "Driver={PostgreSQL Unicode(x64)};"
//            "Database=C:/database/eventDB;" //fullpath without extension
//            "Port=8082;"
//            "Server=localhost;");
//        db.setDatabaseName(connectString);
//        bool ok = db.open("sa","");

//        if(!ok){
//            qDebug() << db.lastError();
//        }
//        else{
//            qDebug() << "ok";
//        }


//    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
//    db.setHostName("192.168.10.1:8082");
//    db.setUserName("sa");
//    db.setPassword("");
//    db.setDatabaseName("CUSTOMER");

//    if(db.open()){
//        QMessageBox::information(this, "Connection","Connected");
//    }
//    else{
//        QSqlError error = db.lastError();
//        //With this you get to know better why the connection failed
//               QMessageBox::information(this, "Connection", error.databaseText());
//        //if you change databaseText() by text() you get the error reported by the driver and the database
//             }
    }


void Test::tileSubWindowsVertically()
{
    QHBoxLayout *hLayout = new QHBoxLayout();

    hLayout->addItem(new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Expanding));
    hLayout->addWidget(ui->tabWidget);
    hLayout->addItem(new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Expanding));

    ui->centralwidget->setLayout(hLayout);

}
void Test::tileSubWindowsHorizontally()
{

    QVBoxLayout *vLayout = new QVBoxLayout();

    vLayout->addItem(new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Expanding));
    vLayout->addWidget(ui->tabWidget);
    vLayout->addItem(new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Expanding));

    ui->centralwidget->setLayout(vLayout);
//    if (mdiArea->subWindowList().isEmpty())
//        return;

//    QPoint position(0, 0);

//    foreach (QMdiSubWindow *window, mdiArea->subWindowList()) {
//        QRect rect(0, 0, mdiArea->width() / mdiArea->subWindowList().count(), mdiArea->height());
//        window->setGeometry(rect);
//        window->move(position);
//        position.setX(position.x() + window->width());
//    }
}


