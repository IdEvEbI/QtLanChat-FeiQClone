#ifndef RELIABLEUDPSENDER_H
#define RELIABLEUDPSENDER_H

#include <QtCore/QObject>
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QHostAddress>
#include <QtCore/QTimer>
#include <QtCore/QMap>
#include "Message.h"

class ReliableUdpSender : public QObject {
    Q_OBJECT

public:
    explicit ReliableUdpSender(QObject* parent = nullptr);
    void sendMessage(const QString& message, const QHostAddress& targetAddr, quint16 port);

private slots:
    void onReadyRead();
    void onAckTimeout(quint32 seqNum);

private:
    QUdpSocket* m_socket;
    quint32 m_nextSeqNum;
    QMap<quint32, QTimer*> m_ackTimers;  // 序列号 -> 超时定时器（QMap 是 Qt 提供的映射容器，类似 std::map）
    QMap<quint32, Message> m_pendingMessages;  // 序列号 -> 待确认消息
    QHostAddress m_targetAddr;
    quint16 m_targetPort;
};

#endif // RELIABLEUDPSENDER_H

