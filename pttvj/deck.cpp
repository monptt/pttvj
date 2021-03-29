#include <QDebug>
#include <QFileDialog>
#include <QWidget>
#include <QMouseEvent>
#include "deck.h"
#include "setting.h"

Deck::Deck(const QString &text, QWidget *parent) : QLabel(text, parent)
{
    this->setStyleSheet("Deck {background-color:white;}");
    this->setFixedSize(parent->width(),parent->height());

    // 初期画像をセット
    this->setImageFile("p.png");
}

// クリック時の動作
void Deck::mouseReleaseEvent(QMouseEvent *e)
{
    qDebug() << "Deck clicked";

    if(e->button()==Qt::RightButton){
        // 右クリックでファイル読み込み
        QFileDialog::getOpenFileName(this, tr("Load image or video from File"), "c:/",
                                     tr("png(*.png);;All Files(*.*)"));
    }

    // シグナル送信
    emit clicked();
}

void Deck::updateFrame(){
    if(this->frameMode=="image"){
        //画像の場合setしてから更新なし
    }else if(this->frameMode=="video"){
        // 映像ファイルの場合，videoCaptureから読み込み
        cv::Mat newFrame;
        for(int i=0; i<Setting::t_to_process/33; i++){
            this->videoCapture >> newFrame;
        }

        if(!newFrame.empty()){
            cv::Mat img_resized;
            cv::resize(newFrame, img_resized, cv::Size(Setting::cvWidth,Setting::cvHeight));
            this->cvFrame = img_resized.clone();
        }
    }

    // QLabelに表示
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
    this->frameMode = "image";
    cv::Mat img = cv::imread(Setting::exePath+"/image/"+filename);
    cv::Mat img_resized;
    cv::resize(img, img_resized, cv::Size(Setting::cvWidth,Setting::cvHeight));
    this->cvFrame = img_resized.clone();
}

void Deck::setVideoFile(std::string filename){
    this->frameMode = "video";
    this->videoCapture = cv::VideoCapture(Setting::exePath+"/video/"+filename);
}
