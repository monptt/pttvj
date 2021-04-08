#include <QDebug>
#include <QFileDialog>
#include <QWidget>
#include <QMouseEvent>
#include "deck.h"
#include "setting.h"

Deck::Deck(const QString &text, QWidget *parent) : QLabel(text, parent)
{
    this->time = 0;

    this->setStyleSheet("Deck {background-color:white;}");
    this->setFixedSize(parent->width(),parent->height());

    // 初期画像をセット
    this->setImageFile(Setting::exePath+"/resources/"+"empty.jpg");
}

// クリック時の動作
void Deck::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button()==Qt::RightButton){
        // 右クリックでファイル読み込み
        QString filePath = QFileDialog::getOpenFileName(this, tr("Load image or video from File"), QString::fromStdString(Setting::exePath),
                                     tr("File(*.mp4 *.png *.jpg);;Video File(*.mp4);;Image File(*.png *.jpg)"));
        QString ext = QFileInfo(filePath).suffix().toLower();
        if(ext=="mp4"){
            this->setVideoFile(filePath.toStdString());
        }else if(ext=="png" || ext=="jpg"){
            this->setImageFile(filePath.toStdString());
        }
    }

    // シグナル送信
    emit clicked();
}

void Deck::updateFrame(int dt){
    this->time += dt;

    if(this->frameMode=="image"){
        //画像の場合setしてから更新なし
        this->time = 0;
    }else if(this->frameMode=="video"){
        // 映像ファイルの場合，videoCaptureから読み込み
        cv::Mat newFrame;
        int time_per_frame = 1000/this->videoCapture.get(CV_CAP_PROP_FPS);
        while(this->time >= time_per_frame){
            this->videoCapture >> newFrame;
            this->time -= time_per_frame;
        }

        if(!newFrame.empty()){
            cv::Mat img_resized;
            cv::resize(newFrame, img_resized, cv::Size(Setting::cvWidth,Setting::cvHeight), cv::INTER_AREA);
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

void Deck::setImageFile(std::string filePath){
    this->frameMode = "image";
    cv::Mat img = cv::imread(filePath);
    cv::Mat img_resized;
    cv::resize(img, img_resized, cv::Size(Setting::cvWidth,Setting::cvHeight));
    this->cvFrame = img_resized.clone();
}

void Deck::setVideoFile(std::string filePath){
    this->frameMode = "video";
    this->videoCapture = cv::VideoCapture(filePath);
}
