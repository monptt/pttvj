#include "cmd.h"
#include "setting.h"
#include <QtCore/QDebug>
#include <vector>

typedef std::vector<std::string> Args;

namespace cmd{

int setVideo(Args args){
    if(args.size() < 2){return 400;}
    std::string deck = args[0];
    std::string filename = args[1];
    if(deck=="L"){
        Setting::deckL->setVideoFile(Setting::exePath+"/VIDEO/"+filename);
    }else if(deck=="R"){
        Setting::deckR->setVideoFile(Setting::exePath+"/VIDEO/"+filename);
    }
    return 200;
}
int setBpm(Args args){
    if(args.size() < 1){return 400;}
    try{
        int bpm = std::stoi(args[0]);
        Setting::setBpm(bpm);
        return 200;
    }catch(std::invalid_argument e){
        return 400; // 数値への変換が行われない場合
    }catch(std::out_of_range e) {
        return 400; // 範囲外の値になった場合
    }
}

// effectのon/off切り替え
int effectOn(Args args){
    if(args.size() < 1){return 400;}
    std::string effectName = args[0];
    if(Setting::effectFlags.count(effectName)){
        Setting::effectFlags[effectName] = true;
        return 200;
    }else{
        return 404;
    }
}
int effectOff(Args args){
    if(args.size() < 1){return 400;}
    std::string effectName = args[0];
    if(Setting::effectFlags.count(effectName)){
        Setting::effectFlags[effectName] = false;
        return 200;
    }else{
        return 404;
    }
}

void readCmd(QString s){
        std::string str = s.toStdString();
        std::string cmd;
        std::vector<std::string> args;
        std::string tempStr = "";
        for(size_t i=0; i<=str.length(); i++){
            char c=str[i];
            if( (c==' ' || i==str.length()) && tempStr!=""){
                if(cmd==""){cmd=tempStr;}
                else{args.push_back(tempStr);}
                tempStr="";
            }else{
                tempStr += c;
            }
        }

        int exitCode;

        if(cmd=="setvideo"){
            exitCode = setVideo(args);
        }else if(cmd=="bpm"){
            exitCode = setBpm(args);
        }else if(cmd=="on"){
            exitCode = effectOn(args);
        }else if(cmd=="off"){
            exitCode = effectOff(args);
        }
}


}
