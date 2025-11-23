#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>
#include <QtCore/QTimer>
#include "BroadcastSender.h"
#include "BroadcastReceiver.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // 创建接收方
    BroadcastReceiver receiver;
    if (!receiver.bind(12345)) {
        return 1;
    }

    // 创建发送方
    BroadcastSender sender;

    // 延迟发送消息，确保接收方已准备好
    QTimer::singleShot(500, [&sender]() {
        sender.sendMessage("Hello, Broadcast!", 12345);
    });

    // 3秒后退出
    QTimer::singleShot(3000, &app, &QCoreApplication::quit);

    return app.exec();
}

