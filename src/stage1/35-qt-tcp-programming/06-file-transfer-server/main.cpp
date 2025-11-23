#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>
#include "FileTransferServer.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    qDebug() << "=== TCP 文件传输服务器示例 ===";
    qDebug() << "";

    FileTransferServer server;

    QObject::connect(&server, &FileTransferServer::clientConnected, [](const QString &address) {
        qDebug() << "[服务器] 客户端已连接：" << address;
    });

    QObject::connect(&server, &FileTransferServer::clientDisconnected, [](const QString &address) {
        qDebug() << "[服务器] 客户端已断开：" << address;
    });

    QObject::connect(&server, &FileTransferServer::fileReceived, [](const QString &fileName, qint64 fileSize) {
        qDebug() << "[服务器] 文件接收完成：" << fileName << "，大小：" << fileSize << "字节";
        qDebug() << "文件保存在：received_" << fileName;
    });

    quint16 port = 12347;
    if (!server.startServer(port)) {
        return 1;
    }

    qDebug() << "";
    qDebug() << "文件传输服务器正在运行，等待客户端连接...";
    qDebug() << "可以使用 05-file-transfer-client 程序发送文件";
    qDebug() << "示例：./FileTransferClient /path/to/file.txt";
    qDebug() << "";

    return app.exec();
}

