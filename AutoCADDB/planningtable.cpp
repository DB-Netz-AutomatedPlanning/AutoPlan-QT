#include "planningtable.h"
#include "ui_planningtable.h"

PlanningTable::PlanningTable(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlanningTable)
{
    ui->setupUi(this);

}

PlanningTable::~PlanningTable()
{
    delete ui;
}
