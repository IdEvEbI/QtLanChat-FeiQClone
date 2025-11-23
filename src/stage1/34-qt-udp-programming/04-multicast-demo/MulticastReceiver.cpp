#include "MulticastReceiver.h"
#include <QtCore/QDebug>

MulticastReceiver::MulticastReceiver(QObject* parent) : QObject(parent),
    m_socket(nullptr),
    m_isJoined(false) {
    m_socket = new QUdpSocket(this);

    // 连接 readyRead 信号
    connect(m_socket, &QUdpSocket::readyRead, this, &MulticastReceiver::onReadyRead);
}

bool MulticastReceiver::bind(quint16 port) {
    // 绑定端口（需要端口复用）
    if (!m_socket->bind(QHostAddress::AnyIPv4, port,
                        QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint)) {
        qDebug() << "Bind failed:" << m_socket->errorString();
        return false;
    }
    qDebug() << "Multicast receiver bound to port" << port;
    return true;
}

bool MulticastReceiver::joinMulticastGroup(const QHostAddress& multicastAddr) {
    if (m_socket->joinMulticastGroup(multicastAddr)) {
        m_multicastAddr = multicastAddr;
        m_isJoined = true;
        qDebug() << "Joined multicast group:" << multicastAddr.toString();
        return true;
    } else {
        qDebug() << "Join multicast group failed:" << m_socket->errorString();
        return false;
    }
}

void MulticastReceiver::leaveMulticastGroup(const QHostAddress& multicastAddr) {
    if (m_isJoined && m_multicastAddr == multicastAddr) {
        m_socket->leaveMulticastGroup(multicastAddr);
        m_isJoined = false;
        qDebug() << "Left multicast group:" << multicastAddr.toString();
    }
}

void MulticastReceiver::onReadyRead() {
    while (m_socket->hasPendingDatagrams()) {
        QByteArray buffer;
        buffer.resize(m_socket->pendingDatagramSize());

        QHostAddress senderAddr;
        quint16 senderPort;

        m_socket->readDatagram(buffer.data(), buffer.size(), &senderAddr, &senderPort);

        qDebug() << "Received multicast from" << senderAddr.toString() << ":" << senderPort
                 << "Data:" << buffer;
    }
}

