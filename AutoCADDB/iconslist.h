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

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;


private slots:
    void on_checkBox_clicked();


    void on_sh1_clicked();

    void on_sh1_mehra_clicked();

    void on_chk_ersatz_clicked();

    void on_chk_shrimsh1_clicked();

    void on_chk_gegen_clicked();

    void on_chc_sh1exp_clicked();

    void on_chk_exp_clicked();

    void on_chk_T_clicked();

    void on_chk_stumpA_clicked();

    void on_chk_sh1stump_clicked();

    void on_chk_backArrow_clicked();

    void on_chk_backerstaz_clicked();

    void on_chk_frontarrow_clicked();

    void on_chk_ersatzRght_clicked();

private:
    Ui::IconsList *ui;
    QPixmap *pixmap;
    QPainter *painter;

};

#endif // ICONSLIST_H
