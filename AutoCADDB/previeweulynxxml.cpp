#include "previeweulynxxml.h"
#include "ui_previeweulynxxml.h"

PreviewEulynxXml::PreviewEulynxXml(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreviewEulynxXml)
{
    ui->setupUi(this);
    this->setWindowTitle("Success");
}

PreviewEulynxXml::~PreviewEulynxXml()
{
    delete ui;
}

void PreviewEulynxXml::on_btnOk_clicked()
{
    this->close();
}

