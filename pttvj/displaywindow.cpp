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
void DisplayWindow::mousePressEvent(QMouseEvent *e){
    if(this->fullscreen){
        this->fullscreen = false;
        this->showNormal();
    }else{
        this->fullscreen = true;
        this->showFullScreen();
    }
}

void DisplayWindow::updateFrame(){
    if(this->cvFrame.empty()){
        qDebug()<<"empty image";
    }else{
        QImage qimage(this->cvFrame.data,
                     this->cvFrame.cols, this->cvFrame.rows,
                     QImage::Format_RGB888);
        qimage = qimage.rgbSwapped();

        ui->displayLabel->setPixmap(QPixmap::fromImage(qimage));
    }
}
