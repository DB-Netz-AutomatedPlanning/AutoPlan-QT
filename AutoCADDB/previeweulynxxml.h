#ifndef PREVIEWEULYNXXML_H
#define PREVIEWEULYNXXML_H

#include <QDialog>
#include <QFile>
#include <QMessageBox>

namespace Ui {
class PreviewEulynxXml;
class ExportDialog;
}

class PreviewEulynxXml : public QDialog
{
    Q_OBJECT

public:
    explicit PreviewEulynxXml(QWidget *parent = nullptr);
    ~PreviewEulynxXml();

private slots:
    void on_btnOk_clicked();


    void on_btnValidateXML_clicked();

private:
    Ui::PreviewEulynxXml *ui;
    Ui::ExportDialog *uiE;
};

#endif // PREVIEWEULYNXXML_H
