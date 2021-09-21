#ifndef NOPREVIEWDELETE_H
#define NOPREVIEWDELETE_H

#include <QDialog>
#include <QDirIterator>
#include <QMessageBox>

namespace Ui {
class NoPreviewDelete;
}

class NoPreviewDelete : public QDialog
{
    Q_OBJECT

public:
    explicit NoPreviewDelete(QWidget *parent = nullptr);
    ~NoPreviewDelete();
    void checkButtonStatus (bool isON);

private slots:
    void on_btnLoad_6_clicked();

    void on_comboAllFolder_6_currentTextChanged();

    void on_checkBoxEntireStation_toggled(bool checked);

    void on_btnCancel_6_clicked();

    void on_btnDelete_6_clicked();

private:
    Ui::NoPreviewDelete *ui;
};

#endif // NOPREVIEWDELETE_H
