#ifndef DECK_H
#define DECK_H

#include <QLabel>
#include <opencv2/opencv.hpp>
class Deck : public QLabel
{
    Q_OBJECT
public:
    Deck(const QString &text="", QWidget *parent=NULL);
    void setImageFile(std::string filename);
    void setVideoFile(std::string filename);

    void updateFrame();
    cv::Mat cvFrame;

private:
    std::string frameMode;
    /*
     * 画像："image"
     * 映像:"video"
     * カメラ:"camera"
    */

    cv::VideoCapture videoCapture;

signals:
    // クリック時に発生させるシグナル
    void clicked();

protected:
    // クリック時に呼ばれる
    void mouseReleaseEvent(QMouseEvent *e);
};

#endif // DECK_H
