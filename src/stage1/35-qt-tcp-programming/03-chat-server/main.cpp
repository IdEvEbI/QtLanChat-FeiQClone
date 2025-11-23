#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>
#include "ChatServer.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    qDebug() << "=== TCP 聊天服务器示例 ===";
    qDebug() << "";

    ChatServer server;

    QObject::connect(&server, &ChatServer::clientConnected, [](const QString &address, quint16 port) {
        qDebug() << "[服务器] 客户端已连接：" << address << ":" << port;
    });

    QObject::connect(&server, &ChatServer::clientDisconnected, [](const QString &address) {
        qDebug() << "[服务器] 客户端已断开：" << address;
    });

    QObject::connect(&server, &ChatServer::messageReceived, [](const QString &address, const QString &message) {
        qDebug() << "[服务器] 收到消息 [" << address << "]：" << message;
    });

    quint16 port = 12346;
    if (!server.startServer(port)) {
        return 1;
    }

    qDebug() << "";
    qDebug() << "聊天服务器正在运行，等待客户端连接...";
    qDebug() << "可以使用 04-chat-client 程序连接到此服务器";
    qDebug() << "";

    return app.exec();
}

