#include "mainwindow.h"
#include "displaywindow.h"
#include "setting.h"

#include <QApplication>
#include <QtCore/QDebug>
#include <QtCore/QTimer>

#include <QElapsedTimer>

void timer();

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Setting::initSetting();
    qDebug() << QString::fromStdString(Setting::exePath);

    MainWindow *mainWindow = new MainWindow(NULL);
    mainWindow->show();


    DisplayWindow *displayWindow = new DisplayWindow(NULL);
    displayWindow->show();

    DisplayWindow *preview = new DisplayWindow(mainWindow);
    preview->setGeometry(250, 50, 320, 180);
    preview->show();

    // 画像読み込みテスト
//    Setting::deckL->setImageFile("p.png");
//    Setting::deckL->setVideoFile("papapa.mp4");
//    Setting::deckR->setImageFile("syaka.png");
//    Setting::deckR->setVideoFile("tomadoi.mp4");


    // 一定時間ごとに実行する処理を設定
    QTimer *timer = new QTimer(NULL);
    // 時間計測用
    QElapsedTimer etimer;
    etimer.start();
    qint64 prevt = 0;
    QObject::connect(timer, &QTimer::timeout, &app, [&](){

        qint64 t = etimer.elapsed();
        qint64 dt = t-prevt;
        Setting::t_to_process += dt;

        Setting::deckL->updateFrame();
        Setting::deckR->updateFrame();
        displayWindow->updateFrame();
        preview->updateFrame();

        Setting::t_to_process %= 33;
        prevt = t;
    });
    timer->start(33);

    // メインループ開始
    return app.exec();
}

