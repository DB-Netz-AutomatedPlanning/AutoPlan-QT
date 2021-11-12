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
//    void setMouseDragMode(bool drag);

private slots:
    void on_checkBoxGridLine_toggled(bool checked);

    void on_checkBoxGridLine2_clicked();

    void on_checkBoxKanten_toggled(bool checked);

    void on_checkBoxKantenDP_toggled(bool checked);

    void on_checkBoxHO_toggled(bool checked);

    void on_checkBoxHODP_toggled(bool checked);

    void on_checkBoxKM_toggled(bool checked);

    void on_checkBoxKMDP_toggled(bool checked);

    void on_checkBoxLA_toggled(bool checked);

    void on_checkBoxLADP_toggled(bool checked);

    void on_checkBoxUH_toggled(bool checked);

    void on_checkBoxUHDP_toggled(bool checked);

private:
    Ui::QGraphicsMainWindow *ui;
    QGraphicsScene *scene;

//protected slots:
//     void wheelEvent(QWheelEvent *event);
//     void keyPressEvent(QKeyEvent *event);
};

#endif // QGRAPHICSMAINWINDOW_H
