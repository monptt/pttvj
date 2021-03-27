#include "setting.h"
#include <QApplication>
#include <QDebug>

double Setting::bpm = 120;

int Setting::cvWidth = 16*100;
int Setting::cvHeight = 9*100;

std::string Setting::exePath = "";

Deck *Setting::deckL = NULL;
Deck *Setting::deckR = NULL;

void Setting::initSetting(){
    // 実行ファイルのパスを取得
    Setting::exePath = QApplication::applicationDirPath().toStdString();

}
