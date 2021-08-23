#ifndef DROPWIDGET_H
#define DROPWIDGET_H

#include <QFrame>

class DropWidget : public QFrame
{
    Q_OBJECT
public:

    explicit DropWidget(QWidget *parent = nullptr);

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

signals:

};

#endif // DROPWIDGET_H



