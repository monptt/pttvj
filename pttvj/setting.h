#ifndef SETTING_H
#define SETTING_H

#include <iostream>
#include <map>
#include "deck.h"

class Setting
{
private:
    Setting();

public:
    static std::string exePath;

    // エフェクトのON/OFF
    static std::map<std::string, bool> effectFlags;

    static int fps;
    static double bpm;
    static void setBpm(int bpm);

    static int cvHeight;
    static int cvWidth;

    // Deckの実体はmainwindow.cpp内で宣言している
    static Deck *deckL;
    static Deck *deckR;

    static double LR;

    static void initSetting();

};

#endif // SETTING_H
