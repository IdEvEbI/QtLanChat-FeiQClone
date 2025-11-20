#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>
#include <QtCore/QDateTime>
#include "Timer.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    Timer timer;

    // 连接信号和槽
    QObject::connect(&timer, &Timer::timeout, []() {
        qDebug() << "Current time:" << QDateTime::currentDateTime().toString();
    });

    timer.start(1000);  // 每秒触发一次

    return app.exec();
}

