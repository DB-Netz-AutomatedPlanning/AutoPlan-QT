#ifndef PROGRESSDIALOGUES_H
#define PROGRESSDIALOGUES_H

#include <QWidget>
#include <QProgressDialog>

class ProgressDialogues : public QWidget
{
    Q_OBJECT
public:
    explicit ProgressDialogues(QWidget *parent = nullptr);
    void setInitialValue();

signals:

private:
    QProgressDialog *pgd;


};

#endif // PROGRESSDIALOGUES_H
