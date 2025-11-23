#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>
#include <QtCore/QTimer>
#include "MulticastSender.h"
#include "MulticastReceiver.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // 创建接收方
    MulticastReceiver receiver;
    if (!receiver.bind(12345)) {
        return 1;
    }

    // 加入多播组
    QHostAddress multicastAddr("224.0.0.1");
    if (!receiver.joinMulticastGroup(multicastAddr)) {
        return 1;
    }

    // 创建发送方
    MulticastSender sender;

    // 延迟发送消息，确保接收方已准备好
    QTimer::singleShot(500, [&sender, multicastAddr]() {
        sender.sendMessage("Hello, Multicast!", multicastAddr, 12345);
    });

    // 3秒后退出
    QTimer::singleShot(3000, &app, &QCoreApplication::quit);

    return app.exec();
}

