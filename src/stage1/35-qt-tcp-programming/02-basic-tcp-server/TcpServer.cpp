#include "TcpServer.h"
#include <QtCore/QDebug>
#include <QtNetwork/QHostAddress>

TcpServer::TcpServer(QObject *parent)
    : QObject(parent)
{
    m_server = new QTcpServer(this);

    // 连接信号
    connect(m_server, &QTcpServer::newConnection, this, &TcpServer::onNewConnection);
}

TcpServer::~TcpServer()
{
    stopServer();
}

bool TcpServer::startServer(quint16 port)
{
    if (m_server->listen(QHostAddress::AnyIPv4, port)) {
        qDebug() << "服务器启动成功，监听端口：" << port;
        return true;
    } else {
        qDebug() << "服务器启动失败：" << m_server->errorString();
        return false;
    }
}

void TcpServer::stopServer()
{
    if (m_server->isListening()) {
        m_server->close();
        qDebug() << "服务器已停止";
    }
}

void TcpServer::onNewConnection()
{
    // 获取新连接的 Socket
    QTcpSocket *clientSocket = m_server->nextPendingConnection();
    if (!clientSocket) {
        return;
    }

    QString address = clientSocket->peerAddress().toString();
    quint16 port = clientSocket->peerPort();

    qDebug() << "新客户端连接："
             << address
             << ":" << port;

    // 添加到客户端列表
    m_clients.append(clientSocket);

    // 连接客户端的信号
    connect(clientSocket, &QTcpSocket::readyRead, this, &TcpServer::onClientReadyRead);
    connect(clientSocket, &QTcpSocket::disconnected, this, &TcpServer::onClientDisconnected);

    emit clientConnected(address, port);
}

void TcpServer::onClientReadyRead()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (!clientSocket) {
        return;
    }

    QByteArray data = clientSocket->readAll();
    QString address = clientSocket->peerAddress().toString();

    qDebug() << "收到客户端数据 [" << address << "]：" << data;

    // 处理数据并发送响应
    QByteArray response = "服务器收到：" + data;
    clientSocket->write(response);
    clientSocket->flush();

    emit dataReceived(address, data);
}

void TcpServer::onClientDisconnected()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (!clientSocket) {
        return;
    }

    QString address = clientSocket->peerAddress().toString();

    qDebug() << "客户端断开连接：" << address;

    // 从列表中移除
    m_clients.removeAll(clientSocket);

    // 延迟删除，确保信号处理完成
    clientSocket->deleteLater();

    emit clientDisconnected(address);
}

