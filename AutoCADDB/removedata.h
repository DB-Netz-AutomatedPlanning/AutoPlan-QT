#ifndef REMOVEDATA_H
#define REMOVEDATA_H

#include <QDialog>
#include <QDirIterator>
#include <QMessageBox>

namespace Ui {
class RemoveData;
}

class RemoveData : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveData(QWidget *parent = nullptr);
    ~RemoveData();

private slots:

    void on_btnLoad_clicked();

    void on_btnPreview_clicked();

    void on_comboAllFolder_currentTextChanged();

    void on_comboFiles_currentTextChanged();

    void on_btnDelete_clicked();

    void on_btnCancel_clicked();

private:
    Ui::RemoveData *ui;
};

#endif // REMOVEDATA_H
