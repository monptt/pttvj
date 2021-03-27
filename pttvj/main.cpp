#include "mainwindow.h"
#include "displaywindow.h"

#include <QApplication>
#include <QtCore/QDebug>
#include <QtCore/QTimer>

void timerTest(){
    qDebug() << "timer test";
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow *window = new MainWindow(NULL);
    window->show();

    DisplayWindow *displayWindow = new DisplayWindow(NULL);
    displayWindow->show();

    QTimer *timer = new QTimer(NULL);
    QObject::connect(timer, &QTimer::timeout, &app, timerTest);
    timer->start(1000);

    // メインループ開始
    return app.exec();
}
