#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class glWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    glWidget(QWidget *parent);
private:
    QWidget *parent = NULL;

    bool fullscreen = false;
    GLuint textureHandles[3];
protected:
    void mouseReleaseEvent(QMouseEvent *e);    // クリック時に呼ばれる

    void initializeGL();        //  OpenGL 初期化
    void resizeGL(int, int);    //  ウィジットリサイズ時のハンドラ
    void paintGL();             //  描画処理
};

#endif // GLWIDGET_H
