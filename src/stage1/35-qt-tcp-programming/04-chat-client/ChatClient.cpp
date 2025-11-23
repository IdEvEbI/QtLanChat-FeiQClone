#include "ChatClient.h"
#include <QtCore/QDebug>

ChatClient::ChatClient(QObject *parent)
    : QObject(parent)
    , m_messageCount(0)
{
    m_socket = new QTcpSocket(this);

    connect(m_socket, &QTcpSocket::connected, this, &ChatClient::onConnected);
    connect(m_socket, &QTcpSocket::disconnected, this, &ChatClient::onDisconnected);
    connect(m_socket, &QTcpSocket::readyRead, this, &ChatClient::onReadyRead);
    connect(m_socket, &QTcpSocket::errorOccurred, this, &ChatClient::onError);

    // 创建自动发送定时器（用于演示）
    m_autoSendTimer = new QTimer(this);
    m_autoSendTimer->setInterval(3000); // 每3秒发送一条消息
    connect(m_autoSendTimer, &QTimer::timeout, this, [this]() {
        sendMessage(QString("自动消息 #%1").arg(++m_messageCount));
    });
}

ChatClient::~ChatClient()
{
    if (m_socket) {
        m_socket->disconnectFromHost();
    }
}

void ChatClient::connectToServer(const QString &host, quint16 port)
{
    m_socket->connectToHost(host, port);
    qDebug() << "正在连接到聊天服务器：" << host << ":" << port;
}

void ChatClient::sendMessage(const QString &message)
{
    if (m_socket->state() == QAbstractSocket::ConnectedState) {
        QByteArray data = message.toUtf8();
        m_socket->write(data);
        m_socket->flush();
        qDebug() << "发送消息：" << message;
    } else {
        qDebug() << "未连接到服务器，无法发送消息";
    }
}

void ChatClient::disconnectFromServer()
{
    m_socket->disconnectFromHost();
}

void ChatClient::onConnected()
{
    qDebug() << "已连接到聊天服务器";
    emit connected();

    // 启动自动发送定时器（用于演示）
    m_autoSendTimer->start();
}

void ChatClient::onDisconnected()
{
    qDebug() << "已断开与聊天服务器的连接";
    m_autoSendTimer->stop();
    emit disconnected();
}

void ChatClient::onReadyRead()
{
    QByteArray data = m_socket->readAll();
    QString message = QString::fromUtf8(data);
    qDebug() << "收到消息：" << message;
    emit messageReceived(message);
}

void ChatClient::onError(QAbstractSocket::SocketError error)
{
    QString errorString = m_socket->errorString();
    qDebug() << "发生错误：" << errorString;
    emit errorOccurred(errorString);
}

