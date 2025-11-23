#include "ReliableUdpReceiver.h"
#include <QtCore/QDebug>

ReliableUdpReceiver::ReliableUdpReceiver(QObject* parent) : QObject(parent),
    m_socket(nullptr) {
    m_socket = new QUdpSocket(this);
    connect(m_socket, &QUdpSocket::readyRead, this, &ReliableUdpReceiver::onReadyRead);
}

bool ReliableUdpReceiver::bind(quint16 port) {
    if (m_socket->bind(QHostAddress::AnyIPv4, port)) {
        qDebug() << "Bound to port" << port;
        return true;
    } else {
        qDebug() << "Bind failed:" << m_socket->errorString();
        return false;
    }
}

void ReliableUdpReceiver::onReadyRead() {
    while (m_socket->hasPendingDatagrams()) {
        QByteArray buffer;
        buffer.resize(m_socket->pendingDatagramSize());

        QHostAddress senderAddr;
        quint16 senderPort;
        m_socket->readDatagram(buffer.data(), buffer.size(), &senderAddr, &senderPort);

        // 解析消息
        Message msg = Message::fromByteArray(buffer);

        if (msg.type == MSG_DATA) {
            // 检查是否已接收过（去重）
            if (m_receivedSeqNums.contains(msg.seqNum)) {
                qDebug() << "Duplicate message seqNum:" << msg.seqNum << ", ignoring";
            } else {
                // 记录已接收的序列号
                m_receivedSeqNums.insert(msg.seqNum);

                // 处理消息
                QString message = QString::fromUtf8(msg.data);
                qDebug() << "Received message seqNum:" << msg.seqNum << "from" << senderAddr.toString() << ":" << senderPort;
                qDebug() << "Message:" << message;

                // 发送信号
                emit messageReceived(message, senderAddr, senderPort);
            }

            // 发送 ACK 确认
            Message ackMsg;
            ackMsg.type = MSG_ACK;
            ackMsg.seqNum = msg.seqNum;
            ackMsg.data = QByteArray();  // ACK 不需要数据

            QByteArray ackBuffer = ackMsg.toByteArray();
            m_socket->writeDatagram(ackBuffer, senderAddr, senderPort);
            qDebug() << "Sent ACK for seqNum:" << msg.seqNum;
        }
    }
}

