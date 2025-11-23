#include "UdpSender.h"
#include <QtCore/QDebug>

UdpSender::UdpSender(QObject* parent) : QObject(parent) {
    m_socket = new QUdpSocket(this);
}

void UdpSender::sendMessage(const QString& message, const QHostAddress& targetAddr, quint16 port) {
    QByteArray data = message.toUtf8();
    qint64 bytesWritten = m_socket->writeDatagram(data, targetAddr, port);

    if (bytesWritten == -1) {
        qDebug() << "Send failed:" << m_socket->errorString();
    } else {
        qDebug() << "Sent" << bytesWritten << "bytes to" << targetAddr.toString() << ":" << port;
    }
}

