#ifndef QGRAPHICSSYMBOLCONTAINER_H
#define QGRAPHICSSYMBOLCONTAINER_H

#include <QDialog>

namespace Ui {
class QGraphicsSymbolContainer;
}

class QGraphicsSymbolContainer : public QDialog
{
    Q_OBJECT

public:
    explicit QGraphicsSymbolContainer(QWidget *parent = nullptr);
    ~QGraphicsSymbolContainer();

private slots:
    void on_pb1_clicked();

    void on_pb2_clicked();

    void on_pb3_clicked();

private:
    Ui::QGraphicsSymbolContainer *ui;
};

#endif // QGRAPHICSSYMBOLCONTAINER_H
