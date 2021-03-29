#include "cmd.h"
#include <QtCore/QDebug>

namespace cmd {

void hello(QString str){
    qDebug() << "hello " << str ;
}

}
