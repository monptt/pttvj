#include "glwidget.h"
#include "setting.h"
#include "frameProcessing.h"
#include <algorithm>
#include <opencv2/opencv.hpp>

#include <QDebug>
#include <QOpenGLFunctions>

glWidget::glWidget(QWidget *parent) : QOpenGLWidget(parent)
{
    this->parent = parent;
}

/* 画面クリックでフルスクリーンに */
void glWidget::mouseReleaseEvent(QMouseEvent *e){
    if(this->parent == NULL){
        if(this->fullscreen){
            this->fullscreen = false;
            this->showNormal();
            this->setFixedSize(640,360);
        }else{
            this->fullscreen = true;
            this->showFullScreen();
        }
    }
}

void glWidget::initializeGL()
{
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glClearColor(1.0f, 1.0f, 0.0f, 1.0f);

    /* テクスチャの設定 */
    glGenTextures(3, this->textureHandles);
    for(int i=0; i<3; i++){
        glBindTexture(GL_TEXTURE_2D, this->textureHandles[i]);
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Setting::cvWidth, Setting::cvHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    }

}


void glWidget::resizeGL(int w, int h){

}

void glWidget::paintGL(){
    /* フレームをテクスチャに変換 */
    cv::Mat mixedTexture;
    cv::addWeighted(Setting::deckL->cvFrame, (1-Setting::LR), Setting::deckR->cvFrame, Setting::LR, 0, mixedTexture);
    if(Setting::effectFlags["grayscale"]){
        mixedTexture = FrameProcessing::grayscale(mixedTexture);
    }
    cv::cvtColor(mixedTexture, mixedTexture, CV_BGR2RGB);
    glBindTexture(GL_TEXTURE_2D, this->textureHandles[2]);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, mixedTexture.cols, mixedTexture.rows, GL_RGB, GL_UNSIGNED_BYTE, mixedTexture.data);
    /* テクスチャ貼り付け */
    glBindTexture(GL_TEXTURE_2D, this->textureHandles[2]);
    glEnable(GL_TEXTURE_2D);
        glBegin(GL_POLYGON);
            glColor3f(1.0, 1.0, 1.0);
            glTexCoord2d(1.0,1.0);
            glVertex3f(1.0, -1.0, 0);
            glTexCoord2d(0.0,1.0);
            glVertex3f(-1.0, -1.0, 0);
            glTexCoord2d(0.0,0.0);
            glVertex3f(-1.0, 1.0, 0);
            glTexCoord2d(1.0,0.0);
            glVertex3f(1.0, 1.0, 0);
        glEnd();
    glDisable(GL_TEXTURE_2D);

    /* 波形を表示してみる */
    if(Setting::effectFlags["waveform"]){
        glLineWidth(1);
        glBegin(GL_LINES);
            glColor3f(1.0, 0.0, 0.0);
            glVertex2f(-1.0, 0.0);
            for(int i=0; i<2048; i++){
                int vol = Setting::waveform[i];
                glVertex2f(-1+2.0*i/2047, std::min(1.0, vol/32768.0*10));
            }
        glEnd();
    }



        cv::Mat texture0;
        cv::cvtColor(Setting::deckL->cvFrame, texture0, CV_BGR2RGB);
        glBindTexture(GL_TEXTURE_2D, this->textureHandles[0]);
        glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, texture0.cols, texture0.rows, GL_RGB, GL_UNSIGNED_BYTE, texture0.data);
        cv::Mat texture1;
        cv::cvtColor(Setting::deckL->cvFrame, texture1, CV_BGR2RGB);
        glBindTexture(GL_TEXTURE_2D, this->textureHandles[1]);
        glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, texture1.cols, texture1.rows, GL_RGB, GL_UNSIGNED_BYTE, texture1.data);
}

