#ifndef UDPRECEIVER_H
#define UDPRECEIVER_H

#include <QtCore/QObject>
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QHostAddress>

class UdpReceiver : public QObject {
    Q_OBJECT

public:
    explicit UdpReceiver(QObject* parent = nullptr);
    bool bind(quint16 port);

private slots:
    void onReadyRead();

private:
    QUdpSocket* m_socket;
};

#endif // UDPRECEIVER_H

