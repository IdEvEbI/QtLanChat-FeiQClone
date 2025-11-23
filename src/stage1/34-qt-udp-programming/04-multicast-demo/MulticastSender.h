#ifndef MULTICASTSENDER_H
#define MULTICASTSENDER_H

#include <QtCore/QObject>
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QHostAddress>

class MulticastSender : public QObject {
    Q_OBJECT

public:
    explicit MulticastSender(QObject* parent = nullptr);
    void sendMessage(const QString& message, const QHostAddress& multicastAddr, quint16 port);

private:
    QUdpSocket* m_socket;
};

#endif // MULTICASTSENDER_H

