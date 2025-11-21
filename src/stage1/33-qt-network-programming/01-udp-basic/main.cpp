#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>
#include <QtCore/QThread>
#include <QtNetwork/QHostAddress>
#include "UdpSender.h"
#include "UdpReceiver.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // 创建接收者
    UdpReceiver receiver;
    
    // 等待一下，确保接收者已经绑定端口
    QThread::msleep(100);
    
    // 创建发送者
    UdpSender sender;
    
    // 发送消息到本地回环地址（127.0.0.1）的 12345 端口
    sender.sendMessage("Hello, UDP!", QHostAddress::LocalHost, 12345);
    
    // 启动事件循环，等待信号触发
    return app.exec();
}

