#include "ChatServer.h"
#include <QtCore/QDebug>
#include <QtNetwork/QHostAddress>

ChatServer::ChatServer(QObject *parent)
    : QObject(parent)
{
    m_server = new QTcpServer(this);
    connect(m_server, &QTcpServer::newConnection, this, &ChatServer::onNewConnection);
}

ChatServer::~ChatServer()
{
    stopServer();
}

bool ChatServer::startServer(quint16 port)
{
    if (m_server->listen(QHostAddress::AnyIPv4, port)) {
        qDebug() << "聊天服务器启动成功，监听端口：" << port;
        return true;
    } else {
        qDebug() << "聊天服务器启动失败：" << m_server->errorString();
        return false;
    }
}

void ChatServer::stopServer()
{
    if (m_server->isListening()) {
        m_server->close();
        qDebug() << "聊天服务器已停止";
    }
}

void ChatServer::onNewConnection()
{
    QTcpSocket *clientSocket = m_server->nextPendingConnection();
    if (!clientSocket) {
        return;
    }

    QString address = clientSocket->peerAddress().toString();
    quint16 port = clientSocket->peerPort();

    qDebug() << "新客户端连接：" << address << ":" << port;

    m_clients.append(clientSocket);

    connect(clientSocket, &QTcpSocket::readyRead, this, &ChatServer::onClientReadyRead);
    connect(clientSocket, &QTcpSocket::disconnected, this, &ChatServer::onClientDisconnected);

    emit clientConnected(address, port);

    // 广播新用户加入消息
    broadcastMessage("系统", QString("用户 %1:%2 加入聊天室").arg(address).arg(port));
}

void ChatServer::onClientReadyRead()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (!clientSocket) {
        return;
    }

    QByteArray data = clientSocket->readAll();
    QString message = QString::fromUtf8(data);
    QString address = clientSocket->peerAddress().toString();

    qDebug() << "收到消息 [" << address << "]：" << message;

    // 广播消息给所有客户端
    broadcastMessage(address, message);

    emit messageReceived(address, message);
}

void ChatServer::onClientDisconnected()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (!clientSocket) {
        return;
    }

    QString address = clientSocket->peerAddress().toString();

    qDebug() << "客户端断开连接：" << address;

    m_clients.removeAll(clientSocket);
    clientSocket->deleteLater();

    emit clientDisconnected(address);

    // 广播用户离开消息
    broadcastMessage("系统", QString("用户 %1 离开聊天室").arg(address));
}

void ChatServer::broadcastMessage(const QString &senderAddress, const QString &message)
{
    QString formattedMessage = QString("[%1] %2").arg(senderAddress).arg(message);
    QByteArray data = formattedMessage.toUtf8();

    // 向所有客户端发送消息
    for (QTcpSocket *client : m_clients) {
        if (client->state() == QAbstractSocket::ConnectedState) {
            client->write(data);
            client->flush();
        }
    }
}

