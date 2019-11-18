#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myemit.h"

int getPoint(); //获得凝视数据

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void timerEvent(QTimerEvent *event);

/* For output*/
signals:

private slots:
    void on_pushButtonCalibration_clicked();
    void read_emit(double a, int b);
    void useShellSlot();

/* For output*/

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
