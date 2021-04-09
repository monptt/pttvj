#include "mainwindow.h"
#include "displaywindow.h"
#include "setting.h"
#include "audioprocess.h"

#include <QApplication>
#include <QtCore/QDebug>
#include <QtCore/QTimer>

#include <QElapsedTimer>

void timer();

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    AudioProcess *audioProcess = new AudioProcess();

    Setting::initSetting();
    qDebug() << QString::fromStdString(Setting::exePath);

    MainWindow *mainWindow = new MainWindow(NULL);
    mainWindow->show();


    DisplayWindow *displayWindow = new DisplayWindow(NULL);
    displayWindow->show();

    DisplayWindow *preview = new DisplayWindow(mainWindow);
    preview->setGeometry(100, 30, 16*25, 9*25);
    preview->show();

    // 一定時間ごとに実行する処理を設定
    QTimer *timer = new QTimer(NULL);
    // 時間計測用
    QElapsedTimer etimer;
    etimer.start();
    qint64 prevt = 0;
    QObject::connect(timer, &QTimer::timeout, &app, [&](){
        qint64 t = etimer.elapsed();
        qint64 dt = t-prevt;
        prevt = t;

        mainWindow->updateFrame();
        Setting::deckL->updateFrame(dt);
        Setting::deckR->updateFrame(dt);
        displayWindow->updateFrame();
        preview->updateFrame();

    });
    timer->start(33);

    // メインループ開始
    return app.exec();
}

