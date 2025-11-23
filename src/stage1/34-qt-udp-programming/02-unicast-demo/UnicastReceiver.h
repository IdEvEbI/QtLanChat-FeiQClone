#ifndef UNICASTRECEIVER_H
#define UNICASTRECEIVER_H

#include <QtCore/QObject>
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QHostAddress>

class UnicastReceiver : public QObject {
    Q_OBJECT

public:
    explicit UnicastReceiver(QObject* parent = nullptr);
    bool bind(quint16 port);

private slots:
    void onReadyRead();

private:
    QUdpSocket* m_socket;
};

#endif // UNICASTRECEIVER_H

