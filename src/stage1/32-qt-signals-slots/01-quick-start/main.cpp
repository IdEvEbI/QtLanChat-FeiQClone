#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>
#include "Counter.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    Counter counter;

    // 连接信号和槽：当 valueChanged 信号发出时，执行 lambda 表达式
    // 注意：Lambda 表达式是 C++11 的特性，已在 26-lambda-expressions.md 中学习过
    // qDebug() 是 Qt 的调试输出函数，类似于 std::cout，用于输出调试信息
    QObject::connect(&counter, &Counter::valueChanged,
                     [](int value) {
                         qDebug() << "Value changed to:" << value;
                     });

    // 调用槽函数，触发信号
    counter.increment();                // 输出：Counter value: 1
                                        //       Value changed to: 1
    counter.increment();                // 输出：Counter value: 2
                                        //       Value changed to: 2

    return 0;
}

