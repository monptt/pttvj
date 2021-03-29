#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/QDebug>
#include <QLabel>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include "cmd.h"
#include "deck.h"
#include "setting.h"

// コンストラクタ
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() << "MainWindow start";

    // デッキ
    Deck *deckL = new Deck("deckL", ui->deckLWidget);
    Setting::deckL = deckL;
    deckL->show();
    Deck *deckR = new Deck("deckR", ui->deckRWidget);
    Setting::deckR = deckR;
    deckR->show();


    // OpenCVで画像を読み込む
    cv::Mat image = cv::imread("P:/pttvj/build-pttvj-Desktop_Qt_5_15_2_MSVC2015_64bit-Debug/debug/img/p.png");

    if(image.empty()){
        qDebug() << "empty!";
    }else{
        QImage qimage(image.data,
                     image.cols, image.rows,
                     QImage::Format_RGB888);
        qimage = qimage.rgbSwapped();
        deckL->setPixmap(QPixmap::fromImage(qimage));

    }
}

// デストラクタ
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_cmdBtn_clicked()
{
    QString cmdStr = ui->cmdLine->text();
    ui->cmdLine->clear();

    // コマンドを呼ぶ
//    cmd::processor(cmdStr);
}

void MainWindow::on_cmdLine_returnPressed()
{
    QString cmdStr = ui->cmdLine->text();
    ui->cmdLine->clear();

    // コマンドを呼ぶ
//    cmd::processor(cmdStr);
    cmd::hello();
}

void MainWindow::on_LRSlider_sliderMoved(int position)
{
    Setting::LR = position/100.0;
}
