#include "BroadcastSender.h"
#include <QtCore/QDebug>

BroadcastSender::BroadcastSender(QObject* parent) : QObject(parent) {
    m_socket = new QUdpSocket(this);
}

void BroadcastSender::sendMessage(const QString& message, quint16 port) {
    // 使用广播地址
    QHostAddress broadcastAddr = QHostAddress::Broadcast;  // 255.255.255.255
    QByteArray data = message.toUtf8();

    qint64 bytesWritten = m_socket->writeDatagram(data, broadcastAddr, port);

    if (bytesWritten == -1) {
        qDebug() << "Broadcast send failed:" << m_socket->errorString();
    } else {
        qDebug() << "Sent broadcast message:" << bytesWritten << "bytes to" << broadcastAddr.toString() << ":" << port;
    }
}

