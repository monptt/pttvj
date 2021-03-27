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

    MainWindow *mainWindow = new MainWindow(NULL);
    mainWindow->show();


    DisplayWindow *displayWindow = new DisplayWindow(NULL);
    displayWindow->show();

    DisplayWindow *preview = new DisplayWindow(mainWindow);
    preview->setGeometry(300, 50, 240, 135);
    preview->show();

    // 画像読み込みテスト
    Setting::deckL->setImageFile("p.png");
    Setting::deckR->setImageFile("syaka.png");
    // 一定時間ごとに実行する処理を設定
    QTimer *timer = new QTimer(NULL);
    QObject::connect(timer, &QTimer::timeout, &app, [&](){
        Setting::deckL->updateFrame();
        Setting::deckR->updateFrame();
        displayWindow->updateFrame();
        preview->updateFrame();
    });
    timer->start(100);

    // メインループ開始
    return app.exec();
}

