#pragma once
#include "qeventloop.h"
#include <QCoreApplication>
#include <QTime>

void pause(){
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
