#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QSlider>
#include <QList>
#include <QPainter>
#include <QPrinter>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class OpenGLClass;
class Calculator;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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

    void on_actionOpen_triggered();

    //MENU
    void save();
    void open();

private:
    Ui::MainWindow *ui;
    bool hideMenuBar;
    bool hideFileTab;
    bool hideTabView;
    QString readFile;
    OpenGLClass *scribbleArea;
  //  QPainter painter;
   // QPrinter printer(QPrinter);
    //MENU
    //bool maybeSave();
    bool saveFile(const QByteArray &fileFormat);
    bool maybeSave();


protected:
    void keyPressEvent(QKeyEvent *event);

};
#endif // MAINWINDOW_H
