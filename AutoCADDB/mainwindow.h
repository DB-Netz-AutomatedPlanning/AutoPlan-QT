#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QSlider>
#include <QList>
#include <QPainter>
#include <QPrinter>
#include <QPushButton>
#include <QMouseEvent>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MyOpenglWidget;
class MyOpenglWidget;
class Calculator;
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

public slots:

private slots:

    void on_actionSave_triggered();
    void addTab();
    void closeTab(int);
    void penColor();
    void penWidth();
    void openCalculator();
    void hideFile();
    void hideTab();
    void print();
    void exit();
    void openSvgDialog();
    void openSvgOptions();

    void on_actionOpen_triggered();
    void fetchObjectProps();

    //MENU
    void save();
    void open();

    //ppview
    void exportToPicture();
   // void exportToPdf();

    //Rayhan
    void importShapeFiles();
    void planningFnt();






//    void on_planBtn_clicked();

    void on_actionAdd_Data_triggered();

    void on_actionPreview_Data_triggered();

    void on_actionRemove_Data_triggered();

private:
    Ui::MainWindow *ui;
    bool hideMenuBar;
    bool hideFileTab;
    bool hideTabView;
    QString readFile;
    MyOpenglWidget *scribbleArea;
    MyOpenglWidget *sc;

    bool saveFile(const QByteArray &fileFormat);
    bool maybeSave();

    //ppview
    QGraphicsView* view;
    QString fileName;
    QString *clickedBtnName ;
    QPushButton *btnSender;

protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event) override;

};
#endif // MAINWINDOW_H
