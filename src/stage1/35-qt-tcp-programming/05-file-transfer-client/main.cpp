#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>
#include <QtCore/QFileInfo>
#include "FileTransferClient.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    qDebug() << "=== TCP 文件传输客户端示例 ===";
    qDebug() << "";

    if (argc < 2) {
        qDebug() << "用法：" << argv[0] << " <文件路径>";
        qDebug() << "示例：" << argv[0] << " /path/to/file.txt";
        return 1;
    }

    QString filePath = argv[1];
    QFileInfo fileInfo(filePath);

    if (!fileInfo.exists()) {
        qDebug() << "错误：文件不存在：" << filePath;
        return 1;
    }

    qDebug() << "准备发送文件：" << filePath;
    qDebug() << "文件大小：" << fileInfo.size() << "字节";
    qDebug() << "";

    FileTransferClient client;

    QObject::connect(&client, &FileTransferClient::connected, []() {
        qDebug() << "[客户端] 已连接到服务器";
    });

    QObject::connect(&client, &FileTransferClient::progressChanged, [](qint64 bytesSent, qint64 totalBytes) {
        int percent = (bytesSent * 100) / totalBytes;
        qDebug() << "[客户端] 传输进度：" << percent << "% (" << bytesSent << "/" << totalBytes << "字节)";
    });

    QObject::connect(&client, &FileTransferClient::transferCompleted, []() {
        qDebug() << "[客户端] 文件传输完成！";
        QCoreApplication::exit(0);
    });

    QObject::connect(&client, &FileTransferClient::errorOccurred, [](const QString &errorString) {
        qDebug() << "[客户端] 错误：" << errorString;
        QCoreApplication::exit(1);
    });

    QString host = "127.0.0.1";
    quint16 port = 12347;
    client.sendFile(filePath, host, port);

    return app.exec();
}

