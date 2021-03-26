#include "mainwindow.h"
#include <QApplication>

#include <opencv2/opencv.hpp>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow window;
    window.setWindowTitle("pttvj - mainWindow");
    window.show();

    return app.exec();
}
