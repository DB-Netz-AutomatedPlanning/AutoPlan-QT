#ifndef IMPORTFOLDER_H
#define IMPORTFOLDER_H

#include <QDialog>

namespace Ui {
class ImportFolder;
}

class ImportFolder : public QDialog
{
    Q_OBJECT

public:
    explicit ImportFolder(QWidget *parent = nullptr);
    ~ImportFolder();

private:
    Ui::ImportFolder *ui;
};

#endif // IMPORTFOLDER_H
