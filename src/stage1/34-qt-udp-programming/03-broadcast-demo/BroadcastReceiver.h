#ifndef BROADCASTRECEIVER_H
#define BROADCASTRECEIVER_H

#include <QtCore/QObject>
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QHostAddress>

class BroadcastReceiver : public QObject {
    Q_OBJECT

public:
    explicit BroadcastReceiver(QObject* parent = nullptr);
    bool bind(quint16 port);

private slots:
    void onReadyRead();

private:
    QUdpSocket* m_socket;
};

#endif // BROADCASTRECEIVER_H

