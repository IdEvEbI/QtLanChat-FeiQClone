#ifndef MULTICASTRECEIVER_H
#define MULTICASTRECEIVER_H

#include <QtCore/QObject>
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QHostAddress>

class MulticastReceiver : public QObject {
    Q_OBJECT

public:
    explicit MulticastReceiver(QObject* parent = nullptr);
    bool bind(quint16 port);
    bool joinMulticastGroup(const QHostAddress& multicastAddr);
    void leaveMulticastGroup(const QHostAddress& multicastAddr);

private slots:
    void onReadyRead();

private:
    QUdpSocket* m_socket;
    QHostAddress m_multicastAddr;
    bool m_isJoined;
};

#endif // MULTICASTRECEIVER_H

