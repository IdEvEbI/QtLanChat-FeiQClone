#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>
#include "UdpSender.h"
#include "UdpReceiver.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // 创建接收方
    UdpReceiver receiver;
    if (!receiver.bind(12345)) {
        return 1;
    }

    // 创建发送方
    UdpSender sender;

    // 发送消息到本机
    QHostAddress targetAddr("127.0.0.1");
    sender.sendMessage("Hello, UDP!", targetAddr, 12345);

    // 运行事件循环，等待接收数据
    return app.exec();
}

