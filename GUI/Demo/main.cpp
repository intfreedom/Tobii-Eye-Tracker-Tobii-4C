#include <tobii/tobii.h>
#include <tobii/tobii_streams.h>
#include <stdio.h>
#include <assert.h>
#include <cstring>
#include <QDebug>
#include "mainwindow.h"

#include <QApplication> //应用程序类
#include <QLabel>
#include "myemit.h"

double X=0.0;
double Y=0.0;

MyEmit::MyEmit(QObject *parent):QObject(parent)
{

}

void MyEmit::send_emit()
{

    getPoint();
    double a = X;
    //QString b = "hello";
    int b=1;

    emit start_emit(a,b);

}


void gaze_point_callback(tobii_gaze_point_t const *gaze_point, void *user_data) {
    if (gaze_point->validity == TOBII_VALIDITY_VALID){
        printf("Gaze point: %f, %f\n",
               static_cast<double>(gaze_point->position_xy[0]),
               static_cast<double>(gaze_point->position_xy[1]));
        X=static_cast<double>(gaze_point->position_xy[0]);
        Y=static_cast<double>(gaze_point->position_xy[1]);
    }
}

static void url_receiver(char const *url, void *user_data) {
    char *buffer = (char *) user_data;
    if (*buffer != '\0') return; // only keep first value

    if (strlen(url) < 256)
        strcpy(buffer, url);
}

int getPoint(){
    tobii_api_t *api;
    tobii_error_t error = tobii_api_create(&api, NULL, NULL);
    assert(error == TOBII_ERROR_NO_ERROR);

    char url[256] = {0};
    error = tobii_enumerate_local_device_urls(api, url_receiver, url);
    assert(error == TOBII_ERROR_NO_ERROR && *url != '\0');

    tobii_device_t *device;
    error = tobii_device_create(api, url, &device);
    assert(error == TOBII_ERROR_NO_ERROR);

    error = tobii_gaze_point_subscribe(device, gaze_point_callback, 0);
    assert(error == TOBII_ERROR_NO_ERROR);

    int is_running = 10; // in this sample, exit after some iterations  1000 to 100 to 10
    while (--is_running > 0) {
        error = tobii_wait_for_callbacks(1, &device);//这里注释之后，4C启动之后，就闪一下停止；
        assert(error == TOBII_ERROR_NO_ERROR || error == TOBII_ERROR_TIMED_OUT);

        error = tobii_device_process_callbacks(device);
        assert(error == TOBII_ERROR_NO_ERROR);
    }

    error = tobii_gaze_point_unsubscribe(device);
    assert(error == TOBII_ERROR_NO_ERROR);

    error = tobii_device_destroy(device);
    assert(error == TOBII_ERROR_NO_ERROR);

    error = tobii_api_destroy(api);
    assert(error == TOBII_ERROR_NO_ERROR);
    return 0;
}

int main(int argc, char *argv[]) {

    QApplication a(argc, argv); //a应用程序对象，QT中有且仅有一个应用程序对象；
    MainWindow w;   //创建一个自定义窗口；
    w.show();


    qDebug() <<"-------------";
    qDebug() <<"Print QWidget:geometry().x.() = "<<w.geometry().x();
    qDebug() <<"Print QWidget:geometry().y.() = "<<w.geometry().y();
    qDebug() <<"Print QWidget:geometry().x.() = "<<w.x();
    qDebug() <<"Print QWidget:geometry().y.() = "<<w.y();
    qDebug() <<"Print QWidget:geometry().x.() = "<<w.width();
    qDebug() <<"Print QWidget:geometry().y.() = "<<w.height();
    qDebug() <<"Print QWidget:geometry().x.() = "<<w.frameGeometry().x();
    qDebug() <<"Print QWidget:geometry().y.() = "<<w.frameGeometry().y();

    return a.exec();    //a.exec()进入消息循环机制
}
