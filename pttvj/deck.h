#ifndef DECK_H
#define DECK_H

#include <QLabel>
#include <opencv2/opencv.hpp>
class Deck : public QLabel
{
    Q_OBJECT
public:
    Deck(const QString &text="", QWidget *parent=NULL);
    void updateFrame();

private:
    cv::Mat cvFrame;

signals:
    // クリック時に発生させるシグナル
    void clicked();

protected:
    // 左クリック(LButtonDown)時に呼ばれる
    void mousePressEvent(QMouseEvent *e);
};

#endif // DECK_H
