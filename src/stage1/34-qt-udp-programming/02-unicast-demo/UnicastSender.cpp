#include "UnicastSender.h"
#include <QtCore/QDebug>

UnicastSender::UnicastSender(QObject* parent) : QObject(parent) {
    m_socket = new QUdpSocket(this);
}

void UnicastSender::sendMessage(const QString& message, const QHostAddress& targetAddr, quint16 port) {
    QByteArray data = message.toUtf8();
    qint64 bytesWritten = m_socket->writeDatagram(data, targetAddr, port);

    if (bytesWritten == -1) {
        qDebug() << "Send failed:" << m_socket->errorString();
    } else {
        qDebug() << "Sent unicast message:" << bytesWritten << "bytes to" << targetAddr.toString() << ":" << port;
    }
}

