#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>
#include "TcpServer.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    qDebug() << "=== TCP 服务器基础示例 ===";
    qDebug() << "";

    TcpServer server;

    // 连接信号
    QObject::connect(&server, &TcpServer::clientConnected, [](const QString &address, quint16 port) {
        qDebug() << "[主程序] 客户端已连接：" << address << ":" << port;
    });

    QObject::connect(&server, &TcpServer::clientDisconnected, [](const QString &address) {
        qDebug() << "[主程序] 客户端已断开：" << address;
    });

    QObject::connect(&server, &TcpServer::dataReceived, [](const QString &address, const QByteArray &data) {
        qDebug() << "[主程序] 收到客户端数据 [" << address << "]：" << QString::fromUtf8(data);
    });

    // 启动服务器
    quint16 port = 12345;
    if (!server.startServer(port)) {
        return 1;
    }

    qDebug() << "";
    qDebug() << "服务器正在运行，等待客户端连接...";
    qDebug() << "可以使用 01-basic-tcp-client 程序连接到此服务器";
    qDebug() << "";

    return app.exec();
}

