#ifndef RELIABLEUDPRECEIVER_H
#define RELIABLEUDPRECEIVER_H

#include <QtCore/QObject>
#include <QtNetwork/QUdpSocket>
#include <QtCore/QSet>
#include "Message.h"

class ReliableUdpReceiver : public QObject {
    Q_OBJECT

public:
    explicit ReliableUdpReceiver(QObject* parent = nullptr);
    bool bind(quint16 port);

signals:
    void messageReceived(const QString& message, const QHostAddress& senderAddr, quint16 senderPort);

private slots:
    void onReadyRead();

private:
    QUdpSocket* m_socket;
    QSet<quint32> m_receivedSeqNums;  // 已接收的序列号（用于去重，QSet 是 Qt 提供的集合容器，类似 std::set）
};

#endif // RELIABLEUDPRECEIVER_H

