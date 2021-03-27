#include "deck.h"
#include <QDebug>
#include <QFileDialog>

Deck::Deck(const QString &text, QWidget *parent) : QLabel(text, parent)
{
    this->setStyleSheet("Deck {background-color:white;}");
    this->setFixedSize(parent->width(),parent->height());
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
