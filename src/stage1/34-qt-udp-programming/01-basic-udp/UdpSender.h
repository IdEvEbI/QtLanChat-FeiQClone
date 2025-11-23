#ifndef UDPSENDER_H
#define UDPSENDER_H

#include <QtCore/QObject>
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QHostAddress>

class UdpSender : public QObject {
    Q_OBJECT

public:
    explicit UdpSender(QObject* parent = nullptr);
    void sendMessage(const QString& message, const QHostAddress& targetAddr, quint16 port);

private:
    QUdpSocket* m_socket;
};

#endif // UDPSENDER_H

