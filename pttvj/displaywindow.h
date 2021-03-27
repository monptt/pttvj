#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include <QWidget>
#include <opencv2/opencv.hpp>

namespace Ui {
class DisplayWindow;
}

class DisplayWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayWindow(QWidget *parent = nullptr);
    ~DisplayWindow();

    void updateFrame();
    bool fullscreen = false;


private:
    cv::Mat cvFrame;
    Ui::DisplayWindow *ui;

protected:
    // 左クリック(LButtonDown)時に呼ばれる
    void mousePressEvent(QMouseEvent *e);
};

#endif // DISPLAYWINDOW_H
