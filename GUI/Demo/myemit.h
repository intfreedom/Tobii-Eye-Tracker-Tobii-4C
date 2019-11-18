#ifndef MYEMIT_H
#define MYEMIT_H

#include<QObject>   //QObject是当前的基类
extern double X, Y;

class MyEmit:public QObject
{
    Q_OBJECT    //Q_OBJECT 提供Qt中的信号和槽；
public:
    explicit MyEmit(QObject *parent = nullptr);
    void send_emit();

signals:
    void start_emit(double, int);
public slots:
};

#endif // MYEMIT_H
