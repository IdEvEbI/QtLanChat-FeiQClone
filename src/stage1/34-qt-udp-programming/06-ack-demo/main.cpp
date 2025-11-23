#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>
#include <QtCore/QTimer>
#include "ReliableUdpSender.h"
#include "ReliableUdpReceiver.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // 创建接收方
    ReliableUdpReceiver receiver;
    if (!receiver.bind(12345)) {
        return 1;
    }

    // 连接消息接收信号
    QObject::connect(&receiver, &ReliableUdpReceiver::messageReceived,
                     [](const QString& message, const QHostAddress& senderAddr, quint16 senderPort) {
        qDebug() << "\n=== Message Received ===";
        qDebug() << "From:" << senderAddr.toString() << ":" << senderPort;
        qDebug() << "Message:" << message;
        qDebug() << "========================";
    });

    // 创建发送方
    ReliableUdpSender sender;

    // 1秒后发送消息
    QTimer::singleShot(1000, [&sender]() {
        QHostAddress targetAddr("127.0.0.1");
        sender.sendMessage("Hello, Reliable UDP!", targetAddr, 12345);
    });

    // 5秒后退出
    QTimer::singleShot(5000, &app, &QCoreApplication::quit);

    return app.exec();
}

