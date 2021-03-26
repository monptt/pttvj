#include "mainwindow.h"
#include <QApplication>

#include <QtCore/QDebug>
#include <QtCore/QTimer>

void aaaa(){
    qDebug() << "aaaa";
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow window;
    window.setWindowTitle("pttvj - mainWindow");
    window.show();

    QTimer *timer = new QTimer(NULL);
    QObject::connect(timer, &QTimer::timeout, &app, aaaa);
    timer->start(33);

    // メインループ開始
    return app.exec();
}
