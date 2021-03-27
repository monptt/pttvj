#include "deck.h"
#include <QDebug>
#include <QFileDialog>

Deck::Deck(const QString &text, QWidget *parent) : QLabel(text, parent)
{
    this->setStyleSheet("Deck {background-color:white;}");
    this->setFixedSize(parent->width(),parent->height());

    this->cvFrame = cv::Mat::zeros(160, 90, CV_32F)+100;
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
        QImage qimage(this->cvFrame.data,
                     this->cvFrame.cols, this->cvFrame.rows,
                     QImage::Format_RGB888);
        qimage = qimage.rgbSwapped();

        this->setPixmap(QPixmap::fromImage(qimage));
    }
}
