#include "setting.h"
#include <QApplication>
#include <QDebug>
#include <map>


std::map<std::string, bool> Setting::effectFlags = {
  std::make_pair<std::string, bool>("grayscale",false)
};

int Setting::fps = 24;
double Setting::bpm = 120;
void Setting::setBpm(int bpm){
    Setting::bpm = bpm;
}


int Setting::cvWidth = 16*100;
int Setting::cvHeight = 9*100;

std::string Setting::exePath = "";

Deck *Setting::deckL = NULL;
Deck *Setting::deckR = NULL;
double Setting::LR=0;

int16_t Setting::waveform[2048] = {};

void Setting::initSetting(){
    // 実行ファイルのパスを取得
    Setting::exePath = QApplication::applicationDirPath().toStdString();
}

