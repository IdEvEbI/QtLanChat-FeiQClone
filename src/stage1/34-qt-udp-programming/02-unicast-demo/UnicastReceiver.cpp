#include "UnicastReceiver.h"
#include <QtCore/QDebug>

UnicastReceiver::UnicastReceiver(QObject* parent) : QObject(parent) {
    m_socket = new QUdpSocket(this);

    // 连接 readyRead 信号
    connect(m_socket, &QUdpSocket::readyRead, this, &UnicastReceiver::onReadyRead);
}

bool UnicastReceiver::bind(quint16 port) {
    // 绑定端口（必需）
    if (!m_socket->bind(QHostAddress::AnyIPv4, port)) {
        qDebug() << "Bind failed:" << m_socket->errorString();
        return false;
    }
    qDebug() << "Unicast receiver bound to port" << port;
    return true;
}

void UnicastReceiver::onReadyRead() {
    while (m_socket->hasPendingDatagrams()) {
        QByteArray buffer;
        buffer.resize(m_socket->pendingDatagramSize());

        QHostAddress senderAddr;
        quint16 senderPort;

        m_socket->readDatagram(buffer.data(), buffer.size(), &senderAddr, &senderPort);

        qDebug() << "Received unicast from" << senderAddr.toString() << ":" << senderPort
                 << "Data:" << buffer;
    }
}

