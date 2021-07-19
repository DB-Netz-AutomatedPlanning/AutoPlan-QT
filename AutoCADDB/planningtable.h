#ifndef PLANNINGTABLE_H
#define PLANNINGTABLE_H

#include <QMainWindow>

namespace Ui {
class PlanningTable;
}

class PlanningTable : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlanningTable(QWidget *parent = nullptr);
    ~PlanningTable();

private:
    Ui::PlanningTable *ui;
};

#endif // PLANNINGTABLE_H
