#include "MulticastSender.h"
#include <QtCore/QDebug>

MulticastSender::MulticastSender(QObject* parent) : QObject(parent) {
    m_socket = new QUdpSocket(this);
}

void MulticastSender::sendMessage(const QString& message, const QHostAddress& multicastAddr, quint16 port) {
    QByteArray data = message.toUtf8();
    qint64 bytesWritten = m_socket->writeDatagram(data, multicastAddr, port);

    if (bytesWritten == -1) {
        qDebug() << "Multicast send failed:" << m_socket->errorString();
    } else {
        qDebug() << "Sent multicast message:" << bytesWritten << "bytes to" << multicastAddr.toString() << ":" << port;
    }
}

