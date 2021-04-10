#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/QDebug>
#include <QtMultimedia/QCameraInfo>
#include <QLabel>
#include <QKeyEvent>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <string>
#include <cmath>
#include "cmd.h"
#include "deck.h"
#include "setting.h"

// コンストラクタ
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() << "MainWindow start";

    // メニューバー
    connect(ui->actionCamera, SIGNAL(triggered()) , this, SLOT(cameraDialog()) );

    // デッキ
    Deck *deckL = new Deck("deckL", ui->deckLWidget);
    Setting::deckL = deckL;
    deckL->show();
    Deck *deckR = new Deck("deckR", ui->deckRWidget);
    Setting::deckR = deckR;
    deckR->show();

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
    cmd::readCmd(cmdStr);
}

void MainWindow::on_cmdLine_returnPressed()
{
    QString cmdStr = ui->cmdLine->text();
    ui->cmdLine->clear();

    // コマンドを呼ぶ
    cmd::readCmd(cmdStr);
}


void MainWindow::updateFrame(){
    ui->bpmLabel->setText(QString::fromStdString(std::_Floating_to_string("%3.1lf",Setting::bpm)));
    ui->LRSlider->setValue(std::round(Setting::LR*100));
    // effect関連の同期
    ui->checkGrayscale->setChecked(Setting::effectFlags["grayscale"]);
    ui->checkWaveform->setChecked(Setting::effectFlags["waveform"]);
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    int key = event->key();
    if(ui->cmdLine->hasFocus()){
        if(key == Qt::Key_Escape){
            this->setFocus();
        }
    }else{
        if(key == Qt::Key_Escape){
            ui->cmdLine->setFocus();
        }else if(key == Qt::Key_G){
            Setting::effectFlags["grayscale"] = true;
        }else if(key == Qt::Key_W){
            Setting::effectFlags["waveform"] = true;
        }
    }
}
void MainWindow::keyReleaseEvent(QKeyEvent *event){
    int key = event->key();
    if(ui->cmdLine->hasFocus()){

    }else{
        if(key == Qt::Key_G){
                    Setting::effectFlags["grayscale"] = false;
        }else if(key == Qt::Key_W){
            Setting::effectFlags["waveform"] = false;
        }
    }
}



void MainWindow::on_LRSlider_valueChanged(int value)
{
        Setting::LR = value/100.0;
}

void MainWindow::cameraDialog(){
    cv::VideoCapture camera;
    int device_counts = 0;
    while ( true ) {
        if ( !camera.open(device_counts++) ) {
            break;
        }
    }
    qDebug() << QString::number(device_counts);
}



void MainWindow::on_checkGrayscale_stateChanged(int arg1)
{
    Setting::effectFlags["grayscale"] = ui->checkGrayscale->isChecked();
}

void MainWindow::on_checkWaveform_stateChanged(int arg1)
{
    Setting::effectFlags["waveform"] = ui->checkWaveform->isChecked();
}
