#include "displaywindow.h"
#include "ui_displaywindow.h"
#include "setting.h"

#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <QDebug>

// コンストラクタ
DisplayWindow::DisplayWindow(QWidget *parent) : QWidget(parent),ui(new Ui::DisplayWindow)
{
    ui->setupUi(this);

    // OpenCVで画像を読み込む
    this->cvFrame = cv::imread(Setting::exePath+"/img/p.png");

}

DisplayWindow::~DisplayWindow()
{
    delete ui;
}

// 画面クリックでフルスクリーンに
void DisplayWindow::mouseReleaseEvent(QMouseEvent *e){
    if(this->fullscreen){
        this->fullscreen = false;
        this->showNormal();
        this->setFixedSize(640,360);
    }else{
        this->fullscreen = true;
        this->showFullScreen();
    }
}

void DisplayWindow::updateFrame(){
    cv::Mat frameL = Setting::deckL->cvFrame;
    cv::Mat frameR = Setting::deckR->cvFrame;

    cv::Mat mixedFrame;
    cv::addWeighted(frameL, (1-Setting::LR), frameR, Setting::LR, 0, mixedFrame);

    this->cvFrame = mixedFrame.clone();

    if(this->cvFrame.empty()){
        qDebug()<<"empty image";
    }else{
        QImage qimage(this->cvFrame.data,
                     this->cvFrame.cols, this->cvFrame.rows,
                     QImage::Format_RGB888);
        qimage = qimage.rgbSwapped();
        qimage = qimage.scaled(this->width(), this->height());
        ui->displayLabel->setPixmap(QPixmap::fromImage(qimage));
    }
}
