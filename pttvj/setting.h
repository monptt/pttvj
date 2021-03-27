#ifndef SETTING_H
#define SETTING_H

#include<iostream>

class Setting
{
private:
    Setting();

public:
    static std::string exePath;
    static double bpm;

    static void initSetting();
};

#endif // SETTING_H
