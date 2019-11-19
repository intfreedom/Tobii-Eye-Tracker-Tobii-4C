#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>
#include <QMenuBar>
#include <QLabel>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int a=1;
    int b=2;
    QPushButton *btn = new QPushButton;
    btn->setParent(this);
    btn->resize(300,100);
    btn->move(100,750);
    btn->setText(QString::number(a,10));

    QPushButton *btn2 = new QPushButton(tr("%1").arg(b,10), this);
    btn2->resize(300,100);
    btn2->move(1600,750);
    connect(btn2, &QPushButton::clicked, this, &QMainWindow::close);

    QPushButton *myButton = new QPushButton;
    myButton->setParent(this);
    myButton->resize(280,100);
    myButton->move(1600,300);
    myButton->setText("start");
    connect(myButton,&QPushButton::clicked, this, &MainWindow::useShellSlot);

    QPushButton *positionButton = new QPushButton;
    positionButton->setParent(this);
    positionButton->resize(300,100);
    positionButton->move(108,308);
//    QPoint p = positionButton->pos();
//    QPoint qp = positionButton::QCursor::pos();
//    QPoint q = positionButton->mapToGlobal(positionButton->pos());
    QPoint q = mapToGlobal(mapToParent(positionButton->pos()));



    positionButton->setText(QString("(%1, %2)").arg(q.x()).arg(q.y()));

    resize(2000,1500);//set windows size;

    QMenuBar *bar = menuBar();//菜单栏，只有一个
    setMenuBar(bar);

    QMenu * fileMenu = bar->addMenu("File");//setting 菜单
    QAction * newAction = fileMenu->addAction("New");
}

void MainWindow::timerEvent(QTimerEvent *event){

    getPoint();

    int W = 0;
    if(X>0.5){
        W=2;
    }
    else{
        W=1;
    }

//    QMainWindow->positionButton;
//    QMainWindow::
    MainWindow win;

//    win.positionButton->setText(QString("(%1, %2)").arg(q.x()).arg(q.y()));
    ui->lineEdit->setText(QString("(%1, %2)").arg(X).arg(Y));
    ui->lineEdit_2->setText(QString::number(W));
//    ui->lineEdit->setText(QString());

}

void MainWindow::useShellSlot()
{
    startTimer(500);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* For output*/
void MainWindow::on_pushButtonCalibration_clicked()
{
//    MyEmit myemit;
    QProcess *process = new QProcess();
    process->start("/opt/TobiiProEyeTrackerManager/TobiiProEyeTrackerManager");
//    connect(&myemit,SIGNAL(start_emit(double, int)),this,SLOT(read_emit(double,int)));
//    myemit.send_emit();
}

void MainWindow::read_emit(double a, int b)
{
    QString aa = QString("%1").arg(a);  //把double a，相关的改为float a，就会出现警告" implicit conversion increases floating-point precision: 'float' to 'double' ".
//    QString bb = QString::number(b,10);
//    QString bb = QString("%1").arg(QString::number(ui->lineEdit_2->mapFromGlobal(QCursor::pos()).x()));//鼠标点击在标签上的位置；
//    QString bb = QString("%1 %2").arg(QString::number(ui->lineEdit_2->mapFromGlobal(QWidget::pos()).x())).arg(QString::number(ui->lineEdit_2->mapFromGlobal(QWidget::pos()).y()));
    QString bb = QString("%1 %2").arg(ui->lineEdit_2->QWidget::pos().QPoint::x()).arg(ui->lineEdit_2->QWidget::pos().QPoint::ry());
    ui->lineEdit->setText(aa);
    ui->lineEdit_2->setText(bb);
//    QString aa = QString("%1").arg(a);
    //只能获得这个对应当前应用的坐标，如果全屏的话，就相当于屏幕坐标了
    //弄清几大控件之间的关系；然后试着获取全局坐标；1.2各个坐标的位置控制
    //布局坐标，如何达到全屏状态，如何记录按钮等控件相对屏幕的全局坐标；
    /*
     关于QT中，为何直接指定一个on_pushButton_clicked就可以与UI中拖拽的控件连接，并可以进行点击响应;
     这是因为在UI里创建的这个按钮，objectName为: pushButton;若改为pushButtonA，则同理on_pushButtonA_clicked；
     注意，UI里以这种方式创建的需要，双击鼠标，以上用代码创建的,以connect连接的，单击鼠标，以实现按钮的功能；
     以代码创建的控件以connect()方式连接，不能以on_pushButton_clicked方式连接;
    */

}
/* For output*/
