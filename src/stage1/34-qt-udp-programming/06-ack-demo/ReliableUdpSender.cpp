#include "ReliableUdpSender.h"
#include <QtCore/QDebug>

ReliableUdpSender::ReliableUdpSender(QObject* parent) : QObject(parent),
    m_socket(nullptr),
    m_nextSeqNum(1) {
    m_socket = new QUdpSocket(this);
    connect(m_socket, &QUdpSocket::readyRead, this, &ReliableUdpSender::onReadyRead);
}

void ReliableUdpSender::sendMessage(const QString& message, const QHostAddress& targetAddr, quint16 port) {
    m_targetAddr = targetAddr;
    m_targetPort = port;

    // 创建消息
    Message msg;
    msg.type = MSG_DATA;
    msg.seqNum = m_nextSeqNum++;
    msg.data = message.toUtf8();

    // 保存待确认消息
    m_pendingMessages[msg.seqNum] = msg;

    // 发送消息
    QByteArray buffer = msg.toByteArray();
    qint64 bytesWritten = m_socket->writeDatagram(buffer, targetAddr, port);

    if (bytesWritten == -1) {
        qDebug() << "Send failed:" << m_socket->errorString();
        m_pendingMessages.remove(msg.seqNum);
        return;
    }

    qDebug() << "Sent message seqNum:" << msg.seqNum << "to" << targetAddr.toString() << ":" << port;

    // 创建超时定时器（3秒）
    QTimer* ackTimer = new QTimer(this);
    ackTimer->setSingleShot(true);
    ackTimer->setInterval(3000);

    // 连接超时信号
    connect(ackTimer, &QTimer::timeout, [this, seqNum = msg.seqNum]() {
        onAckTimeout(seqNum);
    });

    m_ackTimers[msg.seqNum] = ackTimer;
    ackTimer->start();
}

void ReliableUdpSender::onReadyRead() {
    while (m_socket->hasPendingDatagrams()) {
        QByteArray buffer;
        buffer.resize(m_socket->pendingDatagramSize());

        QHostAddress senderAddr;
        quint16 senderPort;
        m_socket->readDatagram(buffer.data(), buffer.size(), &senderAddr, &senderPort);

        // 解析 ACK 消息
        Message msg = Message::fromByteArray(buffer);
        if (msg.type == MSG_ACK) {
            qDebug() << "Received ACK for seqNum:" << msg.seqNum;

            // 停止超时定时器
            if (m_ackTimers.contains(msg.seqNum)) {
                m_ackTimers[msg.seqNum]->stop();
                m_ackTimers[msg.seqNum]->deleteLater();
                m_ackTimers.remove(msg.seqNum);
            }

            // 移除待确认消息
            m_pendingMessages.remove(msg.seqNum);
        }
    }
}

void ReliableUdpSender::onAckTimeout(quint32 seqNum) {
    qDebug() << "ACK timeout for seqNum:" << seqNum << ", resending...";

    // 重发消息
    if (m_pendingMessages.contains(seqNum)) {
        Message msg = m_pendingMessages[seqNum];
        QByteArray buffer = msg.toByteArray();
        m_socket->writeDatagram(buffer, m_targetAddr, m_targetPort);

        // 重启定时器
        QTimer* ackTimer = new QTimer(this);
        ackTimer->setSingleShot(true);
        ackTimer->setInterval(3000);
        connect(ackTimer, &QTimer::timeout, [this, seqNum]() {
            onAckTimeout(seqNum);
        });
        m_ackTimers[seqNum] = ackTimer;
        ackTimer->start();
    }
}

