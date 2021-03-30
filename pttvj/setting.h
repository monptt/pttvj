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
    static void setBpm(int bpm);

    static int cvHeight;
    static int cvWidth;

    // Deckの実体はmainwindow.cpp内で宣言している
    static Deck *deckL;
    static Deck *deckR;

    static double LR;

    static void initSetting();

    static int t_to_process;
};

#endif // SETTING_H
