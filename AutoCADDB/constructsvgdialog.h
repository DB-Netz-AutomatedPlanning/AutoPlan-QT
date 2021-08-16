#ifndef CONSTRUCTSVGDIALOG_H
#define CONSTRUCTSVGDIALOG_H

#include <QMainWindow>
#include <QString>

class SvgDialogView;

QT_BEGIN_NAMESPACE
class QAction;
class QGraphicsView;
class QGraphicsScene;
class QGraphicsRectItem;
class QLabel;
QT_END_NAMESPACE

namespace Ui {
class ConstructSvgDialog;
}

class ConstructSvgDialog : public QMainWindow
{
    Q_OBJECT

public:
     ConstructSvgDialog();
     bool loadFile(const QString &path);


public slots:
    void openFile();
    void saveSvg();
    //void setRenderer(int renderMode);

private slots:
    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

    void on_checkBox_4_clicked();

private:
    Ui::ConstructSvgDialog *ui;

    SvgDialogView *m_view;
    QLabel *m_zoomLabel;
    QString m_currentPath;
     QString selectedOption;
       QString path;
};

#endif // CONSTRUCTSVGDIALOG_H
