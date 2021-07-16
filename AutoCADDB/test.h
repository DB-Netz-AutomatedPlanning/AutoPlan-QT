#ifndef TEST_H
#define TEST_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QtSql>


class QMdiArea;
class QMdiSubWindow;

namespace Ui {
class Test;
}

class Test : public QMainWindow
{
    Q_OBJECT

public:
    explicit Test(QWidget *parent = nullptr);
    ~Test();



private slots:
    void addTab();
    void slotCloseTab(int);

    void on_pushButton_clicked();

    void tileSubWindowsVertically();
    void tileSubWindowsHorizontally();

private:
    Ui::Test *ui;
    int tabCount;


    QMdiArea *mdiArea;
    //MdiChild *activeMdiChild();
    QMdiSubWindow *findMdiChild(const QString &fileName);



};

#endif // TEST_H
