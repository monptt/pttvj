#include "mainwindow.h"
#include "setting.h"
#include "audioprocess.h"
#include "glwidget.h"
#include <QApplication>
#include <QtCore/QDebug>
#include <QtCore/QTimer>

#include <QElapsedTimer>

#include <QGLWidget>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    AudioProcess *audioProcess = new AudioProcess();

    Setting::initSetting();
    qDebug() << QString::fromStdString(Setting::exePath);

    MainWindow *mainWindow = new MainWindow(NULL);
    mainWindow->show();

    glWidget *glwidget = new glWidget(NULL);
    glwidget->setFixedSize(640,360);
    glwidget->show();


    glWidget *preview = new glWidget(mainWindow);
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

        glwidget->update();
        preview->update();

    });
    timer->start(33);

    // メインループ開始
    return app.exec();
}

