#ifndef SYMBOLINFORMATION_H
#define SYMBOLINFORMATION_H

#include <QWidget>
#include <QLabel>
namespace Ui {
class SymbolInformation;
}

class SymbolInformation : public QWidget
{
    Q_OBJECT

public:
    explicit SymbolInformation(QWidget *parent = nullptr);

    ~SymbolInformation();


void paintEvent(QPaintEvent *event) override;

public slots:
    void updateLabel();
    void updateUi();

private:
    QLabel *label1;
    Ui::SymbolInformation *ui;
};

#endif // SYMBOLINFORMATION_H
