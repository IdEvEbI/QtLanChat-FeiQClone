#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>
#include <QtCore/QTimer>
#include "TcpClient.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    qDebug() << "=== TCP 客户端基础示例 ===";
    qDebug() << "";

    TcpClient client;

    // 连接信号
    QObject::connect(&client, &TcpClient::connected, []() {
        qDebug() << "[主程序] 客户端已连接";
    });

    QObject::connect(&client, &TcpClient::dataReceived, [](const QByteArray &data) {
        qDebug() << "[主程序] 收到服务器响应：" << QString::fromUtf8(data);
    });

    QObject::connect(&client, &TcpClient::errorOccurred, [](const QString &errorString) {
        qDebug() << "[主程序] 发生错误：" << errorString;
    });

    // 连接到服务器（需要先启动服务器）
    QString host = "127.0.0.1";
    quint16 port = 12345;
    client.connectToServer(host, port);

    // 使用标志位跟踪连接状态
    bool isConnected = false;
    QObject::connect(&client, &TcpClient::connected, [&isConnected]() {
        isConnected = true;
    });

    // 延迟发送数据，等待连接建立
    QTimer::singleShot(1000, [&client, &isConnected]() {
        if (!isConnected) {
            qDebug() << "提示：请先启动 TCP 服务器（02-basic-tcp-server）";
            qDebug() << "然后重新运行此客户端程序";
            QCoreApplication::exit(1);
            return;
        }
        qDebug() << "";
        qDebug() << "发送消息到服务器...";
        client.sendData("Hello, TCP Server!");
    });

    // 设置超时退出
    QTimer::singleShot(5000, &app, &QCoreApplication::quit);

    return app.exec();
}

