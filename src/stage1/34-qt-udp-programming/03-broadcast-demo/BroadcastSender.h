#ifndef BROADCASTSENDER_H
#define BROADCASTSENDER_H

#include <QtCore/QObject>
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QHostAddress>

class BroadcastSender : public QObject {
    Q_OBJECT

public:
    explicit BroadcastSender(QObject* parent = nullptr);
    void sendMessage(const QString& message, quint16 port);

private:
    QUdpSocket* m_socket;
};

#endif // BROADCASTSENDER_H

