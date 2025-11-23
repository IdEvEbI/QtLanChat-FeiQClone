#include "UdpReceiver.h"
#include <QtCore/QDebug>

UdpReceiver::UdpReceiver(QObject* parent) : QObject(parent) {
    m_socket = new QUdpSocket(this);

    // 连接 readyRead 信号到槽函数
    connect(m_socket, &QUdpSocket::readyRead, this, &UdpReceiver::onReadyRead);
}

bool UdpReceiver::bind(quint16 port) {
    if (m_socket->bind(QHostAddress::AnyIPv4, port)) {
        qDebug() << "Bound to port" << port;
        return true;
    } else {
        qDebug() << "Bind failed:" << m_socket->errorString();
        return false;
    }
}

void UdpReceiver::onReadyRead() {
    while (m_socket->hasPendingDatagrams()) {
        QByteArray buffer;
        buffer.resize(m_socket->pendingDatagramSize());

        QHostAddress senderAddr;
        quint16 senderPort;

        qint64 bytesRead = m_socket->readDatagram(buffer.data(), buffer.size(),
                                                   &senderAddr, &senderPort);

        if (bytesRead > 0) {
            QString message = QString::fromUtf8(buffer);
            qDebug() << "Received from" << senderAddr.toString() << ":" << senderPort
                     << "Message:" << message;
        }
    }
}

