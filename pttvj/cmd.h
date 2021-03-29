#ifndef CMD_H
#define CMD_H
#include <QtCore/QDebug>
typedef std::vector<std::string> Args;

namespace cmd {
//// 各種コマンド
//int setvideo(Args args);


// コマンド解釈
void readCmd();
void hello();
}
#endif // CMD_H
