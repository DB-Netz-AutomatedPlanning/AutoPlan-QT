#ifndef ICONSLIST_H
#define ICONSLIST_H

#include <QMainWindow>

namespace Ui {
class IconsList;
}

class IconsList : public QMainWindow
{
    Q_OBJECT

public:
    explicit IconsList(QWidget *parent = nullptr);
    ~IconsList();



private:
    Ui::IconsList *ui;

};

#endif // ICONSLIST_H
