#ifndef QGRAPHICSMAINWINDOW_H
#define QGRAPHICSMAINWINDOW_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
namespace Ui {
class QGraphicsMainWindow;
}

class QGraphicsMainWindow : public QGraphicsView
{
    Q_OBJECT

public:
    explicit QGraphicsMainWindow(QWidget *parent = nullptr);
    ~QGraphicsMainWindow();

private:
    Ui::QGraphicsMainWindow *ui;

protected slots:
     void wheelEvent(QWheelEvent *event);
     void keyPressEvent(QKeyEvent *event);
};

#endif // QGRAPHICSMAINWINDOW_H
