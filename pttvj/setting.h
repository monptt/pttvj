#ifndef SETTING_H
#define SETTING_H

#include<iostream>
#include "deck.h"

class Setting
{
private:
    Setting();

public:
    static std::string exePath;
    static double bpm;

    // Deckの実体はmainwindow.cpp内で宣言している
    static Deck *deckL;
    static Deck *deckR;

    static void initSetting();
};

#endif // SETTING_H
