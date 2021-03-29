#include "setting.h"
#include <QApplication>
#include <QDebug>

double Setting::bpm = 120;
double Setting::LR=0;

int Setting::cvWidth = 16*100;
int Setting::cvHeight = 9*100;

std::string Setting::exePath = "";

Deck *Setting::deckL = NULL;
Deck *Setting::deckR = NULL;

void Setting::initSetting(){
    // 実行ファイルのパスを取得
    Setting::exePath = QApplication::applicationDirPath().toStdString();
}

// 今のフレームで処理されるべき時間(ms)
int Setting::t_to_process = 0;
