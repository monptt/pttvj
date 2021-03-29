#include "cmd.h"
#include "setting.h"
#include <QtCore/QDebug>
#include <vector>

typedef std::vector<std::string> Args;

namespace cmd{

int setvideo(Args args){
    if(args.size() < 2){return 400;}
    std::string deck = args[0];
    std::string filename = args[1];
    if(deck=="L"){
        Setting::deckL->setVideoFile(Setting::exePath+"/video/"+filename);
    }else if(deck=="R"){
        Setting::deckR->setVideoFile(Setting::exePath+"/video/"+filename);
    }
    return 200;
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
            exitCode = setvideo(args);
        }
}


}
