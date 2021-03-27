#include "setting.h"
#include <QApplication>
#include <QDebug>

double Setting::bpm = 120;
std::string Setting::exePath = "";

void Setting::initSetting(){
    Setting::exePath = QApplication::applicationDirPath().toStdString();
}
