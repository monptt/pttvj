#include "glwidget.h"
#include <QDebug>
#include <QOpenGLFunctions>
glWidget::glWidget(QWidget *parent) : QOpenGLWidget(parent)
{
        this->setFixedSize(640,360);
}

// 画面クリックでフルスクリーンに
void glWidget::mouseReleaseEvent(QMouseEvent *e){
    if(this->fullscreen){
        this->fullscreen = false;
        this->showNormal();
        this->setFixedSize(640,360);
    }else{
        this->fullscreen = true;
        this->showFullScreen();
    }
}

void glWidget::initializeGL()
{
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
    qDebug() << "gl start";
}


void glWidget::resizeGL(int a, int b){

}

void glWidget::paintGL(){

    glBegin(GL_TRIANGLES);

    glColor3f(1.0, 0.0, 0.0);

    glVertex3f(-1.0, -0.5, 0);

    glColor3f(0.0, 1.0, 0.0);

    glVertex3f(0.5, -0.5, 0);

    glColor3f(0.0, 0.0, 1.0);

    glVertex3f(0.0, 0.5, 0);

    glEnd();
}

