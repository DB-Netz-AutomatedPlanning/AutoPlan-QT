#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qgraphicsmainwindow.h"
#include "qgraphicssymbolcontainer.h"
#include <QMainWindow>
#include <QProgressDialog>
#include <QProcess>
#include <QWidget>
#include <QSlider>
#include <QList>
#include <QPainter>
#include <QPrinter>
#include <QPushButton>
#include <QMouseEvent>
#include <QTableWidget>
#include <QSpinBox>
#include <QComboBox>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class PlanningTable;
class QString;
class QGraphicsView;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

     void createViewToolBar();
     void removeGabageData();
     void darkTheme();
     void findOS();

     void paintEvent(QPaintEvent *event) override;
     const QString &getApp() const;
     void setApp(const QString &newApp);

     const QString &getEndl() const;
     void setEndl(const QString &newEndl);

public slots:
  void on_actionEULYNX_Validator_triggered();
  void stateChanged(int state);
  void textFunctionToggled(bool isActive);

private slots:

    void on_actionSave_triggered();

    void closeTab(int);
    void transformation(int);
    void print();
    void exit();
    void on_actionOpen_triggered();

    //Validator
    void setXMLPath();
    void setOutputpath();
    void setxsdPath();
    void timeOut();

    //MENU
    void save();

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

    void on_grabBtn_2_clicked();
    void onClicked_xml_json();

    void on_actionDelete_Items_triggered();
    void on_actionSelection_Mode_toggled(bool arg1);

    // Right click (Context Menu)
    void showContextMenu(QPoint pos);
    void createDock();
    void createSignalObjects();
    void on_actionPlanning_Tab_toggled(bool arg1);
    void on_actionAbout_Qt_triggered();

    // Background Grids
    void darkThemeSelected(bool isSelected);
    void lightRulesSelected(bool isSelected);

    void onClickOSM_triggered();
    void OSMFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void OSMStarted();
    void OSMTimeOut();

private:
    Ui::MainWindow *ui;

    QString readFile;
    QMenu *viewDockSubMenu;
    QString app;
    QString endl;
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
    QComboBox *versionCombo;
    QLineEdit *xmlPath;
    QLineEdit *outputPath;
    QLineEdit *xsdPath;
    QProgressDialog *progress;
    QProcess *python;
    bool cSharpIsDone = false;
    QTimer *timer;
    QTimer *OSMtimer;
    int progressValue;
    int OSMProgressValue;
    int lastRotation;

    QSpinBox *zoomSpinBox;
    int currentSpinNumber;

protected:
    void keyPressEvent(QKeyEvent *event) override;
};
#endif // MAINWINDOW_H
