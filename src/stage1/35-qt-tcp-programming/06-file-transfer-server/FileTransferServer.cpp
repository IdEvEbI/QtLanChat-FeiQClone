#include "FileTransferServer.h"
#include "FileReceiver.h"
#include <QtCore/QDebug>
#include <QtNetwork/QHostAddress>

FileTransferServer::FileTransferServer(QObject *parent)
    : QObject(parent)
{
    m_server = new QTcpServer(this);
    connect(m_server, &QTcpServer::newConnection, this, &FileTransferServer::onNewConnection);
}

FileTransferServer::~FileTransferServer()
{
    stopServer();
}

bool FileTransferServer::startServer(quint16 port)
{
    if (m_server->listen(QHostAddress::AnyIPv4, port)) {
        qDebug() << "文件传输服务器启动成功，监听端口：" << port;
        return true;
    } else {
        qDebug() << "文件传输服务器启动失败：" << m_server->errorString();
        return false;
    }
}

void FileTransferServer::stopServer()
{
    if (m_server->isListening()) {
        m_server->close();
        qDebug() << "文件传输服务器已停止";
    }
}

void FileTransferServer::onNewConnection()
{
    QTcpSocket *clientSocket = m_server->nextPendingConnection();
    if (!clientSocket) {
        return;
    }

    QString address = clientSocket->peerAddress().toString();
    qDebug() << "新客户端连接：" << address;

    // 为每个客户端创建文件接收器
    FileReceiver *receiver = new FileReceiver(clientSocket, this);

    connect(receiver, &FileReceiver::fileReceived, this, [this, address](const QString &fileName, qint64 fileSize) {
        qDebug() << "[服务器] 文件接收完成：" << fileName << "，大小：" << fileSize << "字节";
        emit fileReceived(fileName, fileSize);
    });

    connect(clientSocket, &QTcpSocket::disconnected, receiver, &FileReceiver::deleteLater);
    connect(clientSocket, &QTcpSocket::disconnected, this, [this, address]() {
        qDebug() << "[服务器] 客户端断开连接：" << address;
        emit clientDisconnected(address);
    });

    emit clientConnected(address);
}

