#include "deck.h"
#include <QDebug>

Deck::Deck(const QString &text, QWidget *parent) : QLabel(text, parent)
{
    this->setStyleSheet("Deck {background-color:white;}");
    this->setFixedSize(parent->width(),parent->height());
}

// クリック時の動作
void Deck::mousePressEvent(QMouseEvent *e)
{
    qDebug() << "Deck clicked";
    // シグナル送信
    emit clicked();
}
