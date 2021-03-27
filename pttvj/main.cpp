#include "mainwindow.h"
#include "displaywindow.h"
#include "setting.h"

#include <QApplication>
#include <QtCore/QDebug>
#include <QtCore/QTimer>

void timer();

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Setting::initSetting();
    qDebug() << QString::fromStdString(Setting::exePath);

    MainWindow *window = new MainWindow(NULL);
    window->show();

    DisplayWindow *displayWindow = new DisplayWindow(NULL);
    displayWindow->show();

    // 一定時間ごとに実行する処理を設定
    QTimer *timer = new QTimer(NULL);
    QObject::connect(timer, &QTimer::timeout, &app, [&](){
        displayWindow->updateFrame();
    });
    timer->start(1000);

    // メインループ開始
    return app.exec();
}

