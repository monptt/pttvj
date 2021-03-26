#include "mainwindow.h"
#include <QApplication>

#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <QtCore/QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qDebug() << "start";
    qDebug() << app.applicationDirPath();
    cv::Mat image = cv::imread(app.applicationDirPath().toStdString()+"\\img\\p.png");

    if(image.empty()){
        qDebug() << "empty!";
    }else{
            cv::imshow("opencv_logo", image);
            cv::waitKey(0);
    }




    MainWindow window;
    window.setWindowTitle("pttvj - mainWindow");
    window.show();

    return app.exec();
}
