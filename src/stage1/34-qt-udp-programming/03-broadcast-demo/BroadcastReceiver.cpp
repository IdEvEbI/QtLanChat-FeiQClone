#include "BroadcastReceiver.h"
#include <QtCore/QDebug>

BroadcastReceiver::BroadcastReceiver(QObject* parent) : QObject(parent) {
    m_socket = new QUdpSocket(this);

    // 连接 readyRead 信号
    connect(m_socket, &QUdpSocket::readyRead, this, &BroadcastReceiver::onReadyRead);
}

bool BroadcastReceiver::bind(quint16 port) {
    // 绑定端口（必需）
    if (!m_socket->bind(QHostAddress::AnyIPv4, port)) {
        qDebug() << "Bind failed:" << m_socket->errorString();
        return false;
    }
    qDebug() << "Broadcast receiver bound to port" << port;
    return true;
}

void BroadcastReceiver::onReadyRead() {
    while (m_socket->hasPendingDatagrams()) {
        QByteArray buffer;
        buffer.resize(m_socket->pendingDatagramSize());

        QHostAddress senderAddr;
        quint16 senderPort;

        m_socket->readDatagram(buffer.data(), buffer.size(), &senderAddr, &senderPort);

        qDebug() << "Received broadcast from" << senderAddr.toString() << ":" << senderPort
                 << "Data:" << buffer;
    }
}

