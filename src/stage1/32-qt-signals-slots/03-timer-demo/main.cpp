#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>
#include <QtCore/QDateTime>
// QDateTime 是 Qt 的日期时间类，用于处理日期和时间
#include "Timer.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    // QCoreApplication 是 Qt 应用程序的核心类，提供事件循环和应用程序管理功能

    Timer timer;

    // 连接信号和槽
    QObject::connect(&timer, &Timer::timeout, []() {
        qDebug() << "Current time:" << QDateTime::currentDateTime().toString();
    });

    timer.start(1000);                  // 每秒触发一次

    // app.exec() 启动事件循环，程序会持续运行
    // 事件循环会不断检查定时器事件，每秒触发一次 timeout 信号
    // 程序会一直运行，直到按 Ctrl+C 强制终止，或者调用 app.quit()
    // 注意：按 Ctrl+C 终止程序时，不会调用 timer.stop()，程序会直接退出
    return app.exec();
}

