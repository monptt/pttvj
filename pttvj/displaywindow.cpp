#include "displaywindow.h"
#include "ui_displaywindow.h"

#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

// コンストラクタ
DisplayWindow::DisplayWindow(QWidget *parent) : QWidget(parent),ui(new Ui::DisplayWindow)
{
    ui->setupUi(this);

    // OpenCVで画像を読み込む
    cv::Mat image = cv::imread("P:/pttvj/build-pttvj-Desktop_Qt_5_15_2_MSVC2015_64bit-Debug/debug/img/p.png");

    if(image.empty()){

    }else{
        QImage qimage(image.data,
                     image.cols, image.rows,
                     QImage::Format_RGB888);
        qimage = qimage.rgbSwapped();
        ui->display->setPixmap(QPixmap::fromImage(qimage));
    }
}

DisplayWindow::~DisplayWindow()
{
    delete ui;
}
