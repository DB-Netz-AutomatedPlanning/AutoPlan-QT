#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qgraphicsmainwindow.h"
#include "qgraphicssymbolcontainer.h"
#include <QMainWindow>
#include <QProgressDialog>
#include <QWidget>
#include <QSlider>
#include <QList>
#include <QPainter>
#include <QPrinter>
#include <QPushButton>
#include <QMouseEvent>
#include <QTableWidget>
#include <QErrorMessage>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MyOpenglWidget;
//class MyOpenglWidget;
//class Calculator;
class PlanningTable;
class QString;
class QGraphicsView;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //treeview
    void setObjNameTW(QString);
     MyOpenglWidget *myopen;

  void mousePressEvent(QMouseEvent *event) override;
  void paintEvent(QPaintEvent *event) override;
public slots:
  void on_actionEULYNX_Validator_triggered();

private slots:

    void on_actionSave_triggered();

    void closeTab(int);
    void penColor();
    void penWidth();
//    void openCalculator();
    void hideFile();
    void hideTab();
    void print();
    void exit();
    void openSvgDialog();
    void openSvgOptions();

    void on_actionOpen_triggered();
    void fetchObjectProps();
    bool writeFooBar();

    //Validator
    void setXMLPath();
    void setOutputpath();
    void setxsdPath();
    void timeOut();

    //MENU
    void save();
    void open();

    //ppview
    void exportToPicture();
   // void exportToPdf();

    void importShapeFiles();
    void planningFnt();
    void addTab();
    void onNewProjectClicked();
    void setActionMenus(bool activate);
    void writeSettings();
    void readSettings();

    void on_actionAdd_Data_triggered();
    void on_actionPreview_Data_triggered();
    void on_actionRemove_Data_triggered();
    void on_actionImport_triggered();

    void on_pushButton_77_clicked();
    void on_exportBtnPlan_clicked();
    void on_btnSymbol_clicked();
    void closeEvent (QCloseEvent *event) override;
    //void on_grabBtn_clicked();
    void on_grabBtn_toggled(bool checked);

    void on_grabBtn_2_clicked();
    void onClicked_xml_json();

    void on_actionDelete_Items_triggered();

    void on_actionSelection_Mode_toggled(bool arg1);

    // Right click (Context Menu)
    void showContextMenu(QPoint pos);

    void createDock();
    void createSignalObjects();

    void on_actionPlanning_Tab_toggled(bool arg1);



private:
    Ui::MainWindow *ui;
    bool hideMenuBar;
    bool hideFileTab;
    bool hideTabView;
    QString readFile;
    MyOpenglWidget *scribbleArea;
    MyOpenglWidget *sc;
    QMenu *viewDockSubMenu;

    bool saveFile(const QByteArray &fileFormat);
    bool maybeSave();
    bool isFirstTab = true;

    QGraphicsView* view;
    QString fileName;
    QString *clickedBtnName ;
    QPushButton *btnSender;
    QTableWidget *table;
    QDockWidget *dock1;
    QDockWidget *dock2;
    bool dockWidgetCreated;
    QGraphicsSymbolContainer *svgDialog;

    // Validator
    QLineEdit *xmlPath;
    QLineEdit *outputPath;
    QLineEdit *xsdPath;
    QProgressDialog *progress;
    QProgressBar *progressBar;
    bool cSharpIsDone = false;
    QTimer *timer;
    QErrorMessage *error;
    QErrorMessage *error2;
    int progressValue;



protected:
    void keyPressEvent(QKeyEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

};
#endif // MAINWINDOW_H
