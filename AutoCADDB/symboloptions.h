#ifndef SYMBOLOPTIONS_H
#define SYMBOLOPTIONS_H

#include <QDialog>

namespace Ui {
class SymbolOptions;
}

class SymbolOptions : public QDialog
{
    Q_OBJECT

public:
    explicit SymbolOptions(QWidget *parent = nullptr);
    ~SymbolOptions();

private:
    Ui::SymbolOptions *ui;
};

#endif // SYMBOLOPTIONS_H
