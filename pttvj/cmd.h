#ifndef CMD_H
#define CMD_H

#include <QtCore/QDebug>
typedef std::vector<std::string> Args;

namespace cmd {
// 各種コマンド
int setVideo(Args args);
int setBpm(Args args);

// コマンド解読
void readCmd(QString s);
}

#endif // CMD_H
