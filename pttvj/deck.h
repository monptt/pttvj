#ifndef DECK_H
#define DECK_H

#include <QLabel>

class Deck : public QLabel
{
    Q_OBJECT
public:
    Deck(const QString &text="", QWidget *parent=NULL);

signals:
    // クリック時に発生させるシグナル
    void clicked();

protected:
    // 左クリック(LButtonDown)時に呼ばれる
    void mousePressEvent(QMouseEvent *e);
};

#endif // DECK_H
