#include "progressdialogues.h"
#include "symbolcontainer.h"
#include <QtConcurrent>

ProgressDialogues::ProgressDialogues(QWidget *parent)
    : QWidget{parent}
{
    if (isEuXml){
        pgd = new QProgressDialog ("Operation in progress", "Cancel", 0, 7);
    }
}

void ProgressDialogues::setInitialValue()
{
    pgd->setValue(progressValue);
}
