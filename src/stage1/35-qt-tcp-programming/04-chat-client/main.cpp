#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>
#include <QtCore/QTimer>
#include "ChatClient.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    qDebug() << "=== TCP 聊天客户端示例 ===";
    qDebug() << "";

    ChatClient client;

    QObject::connect(&client, &ChatClient::connected, []() {
        qDebug() << "[客户端] 已连接到服务器";
    });

    QObject::connect(&client, &ChatClient::disconnected, []() {
        qDebug() << "[客户端] 已断开连接";
    });

    QObject::connect(&client, &ChatClient::messageReceived, [](const QString &message) {
        qDebug() << "[客户端] 收到消息：" << message;
    });

    QObject::connect(&client, &ChatClient::errorOccurred, [](const QString &errorString) {
        qDebug() << "[客户端] 错误：" << errorString;
    });

    QString host = "127.0.0.1";
    quint16 port = 12346;
    client.connectToServer(host, port);

    // 设置超时退出（演示用）
    QTimer::singleShot(15000, &app, &QCoreApplication::quit);

    return app.exec();
}

