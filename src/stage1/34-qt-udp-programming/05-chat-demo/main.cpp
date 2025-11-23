#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>
#include <QtCore/QTimer>
#include "ChatClient.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    ChatClient client;

    // 启动聊天客户端
    if (!client.start(12345)) {
        return 1;
    }

    // 连接消息接收信号
    QObject::connect(&client, &ChatClient::messageReceived,
                     [](const QString& message, const QHostAddress& senderAddr, quint16 senderPort) {
        qDebug() << "\n=== Message Received ===";
        qDebug() << "From:" << senderAddr.toString() << ":" << senderPort;
        qDebug() << "Message:" << message;
        qDebug() << "========================";
    });

    // 发送测试消息
    QTimer::singleShot(1000, [&client]() {
        qDebug() << "\nSending unicast message...";
        QHostAddress targetAddr("127.0.0.1");
        client.sendMessage("Hello, Unicast!", ChatClient::Unicast, targetAddr);
    });

    QTimer::singleShot(2000, [&client]() {
        qDebug() << "\nSending broadcast message...";
        client.sendMessage("Hello, Broadcast!", ChatClient::Broadcast);
    });

    QTimer::singleShot(3000, [&client]() {
        qDebug() << "\nSending multicast message...";
        client.sendMessage("Hello, Multicast!", ChatClient::Multicast);
    });

    // 5 秒后退出
    QTimer::singleShot(5000, &app, &QCoreApplication::quit);

    return app.exec();
}

