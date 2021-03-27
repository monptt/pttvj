#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/QDebug>

#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include "cmd.h"

// コンストラクタ
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() << "MainWindow start";


    // OpenCVで画像を読み込む
    cv::Mat image = cv::imread("P:/pttvj/build-pttvj-Desktop_Qt_5_15_2_MSVC2015_64bit-Debug/debug/img/p.png");

    if(image.empty()){
        qDebug() << "empty!";
    }else{
        QImage qimage(image.data,
                     image.cols, image.rows,
                     QImage::Format_RGB888);
        qimage = qimage.rgbSwapped();
        ui->deck1->setPixmap(QPixmap::fromImage(qimage));

    }

}

// デストラクタ
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_cmdBtn_clicked()
{
    QString str = ui->cmdLine->text();
    ui->cmdLine->clear();
    qDebug() << str;
}

void MainWindow::on_cmdLine_returnPressed()
{
    QString cmdStr = ui->cmdLine->text();
    ui->cmdLine->clear();
    qDebug() << cmdStr;

    // コマンドを呼ぶ
    cmd::hello(cmdStr);
}
