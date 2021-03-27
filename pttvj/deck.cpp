#include <QDebug>
#include <QFileDialog>

#include "deck.h"
#include "setting.h"

Deck::Deck(const QString &text, QWidget *parent) : QLabel(text, parent)
{
    this->setStyleSheet("Deck {background-color:white;}");
    this->setFixedSize(parent->width(),parent->height());

    this->frameMode = "image";
    this->cvFrame = cv::Mat::zeros(this->height(), this->width(), CV_32F)+100;
}

// クリック時の動作
void Deck::mousePressEvent(QMouseEvent *e)
{
    qDebug() << "Deck clicked";

    // クリックでファイル読み込み
    QFileDialog::getOpenFileName(this, tr("Load image or video from File"), "c:/",
                                 tr("Text files(*.txt);;All Files(*.*)"));

    // シグナル送信
    emit clicked();
}

void Deck::updateFrame(){
    if(this->cvFrame.empty()){
        qDebug()<<"empty image";
    }else{
        cv::Mat frame = this->cvFrame.clone();
        QImage qimage(frame.data,
                     frame.cols, frame.rows,
                     QImage::Format_RGB888);
        qimage = qimage.rgbSwapped();

        qimage = qimage.scaled(this->width(), this->height());
        this->setPixmap(QPixmap::fromImage(qimage));
    }
}

void Deck::setImageFile(std::string filename){
    cv::Mat img = cv::imread(Setting::exePath+"/img/"+filename);
    cv::Mat img_resized;
    cv::resize(img, img_resized, cv::Size(Setting::cvWidth,Setting::cvHeight));
    this->cvFrame = img_resized.clone();
}
