#ifndef QGRAPHICSMAINWINDOW_H
#define QGRAPHICSMAINWINDOW_H

#include"tracks.h"
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
//#include <QGraphicsItem>
namespace Ui {
class QGraphicsMainWindow;
}

class QGraphicsMainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit QGraphicsMainWindow(QWidget *parent = nullptr);
    ~QGraphicsMainWindow();

private slots:
    void on_checkBoxGridLine_toggled(bool checked);

    void on_checkBoxGridLine2_clicked();

    void on_checkBoxKanten_toggled(bool checked);

    void on_checkBoxKantenDP_toggled(bool checked);

    void on_checkBoxHO_toggled(bool checked);

    void on_checkBoxHODP_toggled(bool checked);

private:
    Ui::QGraphicsMainWindow *ui;
    Tracks *tracks;
    QGraphicsScene *scene;

//protected slots:
//     void wheelEvent(QWheelEvent *event);
//     void keyPressEvent(QKeyEvent *event);
};

#endif // QGRAPHICSMAINWINDOW_H
