#ifndef PREVIEWEULYNXXML_H
#define PREVIEWEULYNXXML_H

#include <QDialog>

namespace Ui {
class PreviewEulynxXml;
}

class PreviewEulynxXml : public QDialog
{
    Q_OBJECT

public:
    explicit PreviewEulynxXml(QWidget *parent = nullptr);
    ~PreviewEulynxXml();

private slots:
    void on_btnOk_clicked();

private:
    Ui::PreviewEulynxXml *ui;
};

#endif // PREVIEWEULYNXXML_H
