#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>
#include "MessageSender.h"
#include "MessageReceiver.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // 创建发送者和接收者
    MessageSender sender;
    MessageReceiver receiver1("Receiver1");
    MessageReceiver receiver2("Receiver2");

    // 连接信号和槽：一个信号连接多个槽（一对多）
    QObject::connect(&sender, &MessageSender::messageSent,
                     &receiver1, &MessageReceiver::onMessageReceived);
    QObject::connect(&sender, &MessageSender::messageSent,
                     &receiver2, &MessageReceiver::onMessageReceived);

    // 发送消息，触发信号，所有连接的槽函数都会被调用
    sender.sendMessage("Hello, Qt!");
    sender.sendMessage("This is a signal-slot demo");

    return 0;
}

