#include "ChatClient.h"
#include <QtCore/QDebug>

ChatClient::ChatClient(QObject* parent) : QObject(parent),
    m_socket(nullptr),
    m_multicastAddr("224.0.0.1"),
    m_port(0),
    m_isMulticastJoined(false) {
}

ChatClient::~ChatClient() {
    stop();
}

bool ChatClient::start(quint16 port) {
    if (m_socket) {
        qDebug() << "Socket already started";
        return false;
    }

    m_socket = new QUdpSocket(this);
    m_port = port;

    // 绑定端口（需要端口复用以支持多播）
    if (!m_socket->bind(QHostAddress::AnyIPv4, port,
                        QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint)) {
        qDebug() << "Bind failed:" << m_socket->errorString();
        delete m_socket;
        m_socket = nullptr;
        return false;
    }

    // 加入多播组
    if (m_socket->joinMulticastGroup(m_multicastAddr)) {
        m_isMulticastJoined = true;
        qDebug() << "Joined multicast group:" << m_multicastAddr.toString();
    } else {
        qDebug() << "Join multicast group failed:" << m_socket->errorString();
    }

    // 连接 readyRead 信号
    connect(m_socket, &QUdpSocket::readyRead, this, &ChatClient::onReadyRead);

    qDebug() << "Chat client started on port" << port;
    return true;
}

void ChatClient::stop() {
    if (m_socket) {
        // 离开多播组
        if (m_isMulticastJoined) {
            m_socket->leaveMulticastGroup(m_multicastAddr);
            m_isMulticastJoined = false;
        }

        m_socket->close();
        delete m_socket;
        m_socket = nullptr;
    }
}

void ChatClient::sendMessage(const QString& message, MessageType type,
                             const QHostAddress& targetAddr) {
    if (!m_socket) {
        qDebug() << "Socket not started";
        return;
    }

    QByteArray data = message.toUtf8();
    QHostAddress addr;
    quint16 port = m_port;

    switch (type) {
    case Unicast:
        if (targetAddr.isNull()) {
            qDebug() << "Target address required for unicast";
            return;
        }
        addr = targetAddr;
        break;
    case Broadcast:
        addr = QHostAddress::Broadcast;
        break;
    case Multicast:
        addr = m_multicastAddr;
        break;
    }

    qint64 bytesWritten = m_socket->writeDatagram(data, addr, port);
    if (bytesWritten == -1) {
        qDebug() << "Send failed:" << m_socket->errorString();
    } else {
        qDebug() << "Sent" << bytesWritten << "bytes to" << addr.toString() << ":" << port;
    }
}

void ChatClient::onReadyRead() {
    if (!m_socket) {
        return;
    }

    while (m_socket->hasPendingDatagrams()) {
        QByteArray buffer;
        buffer.resize(m_socket->pendingDatagramSize());

        QHostAddress senderAddr;
        quint16 senderPort;

        qint64 bytesRead = m_socket->readDatagram(buffer.data(), buffer.size(),
                                                   &senderAddr, &senderPort);

        if (bytesRead > 0) {
            QString message = QString::fromUtf8(buffer);
            emit messageReceived(message, senderAddr, senderPort);
        }
    }
}

