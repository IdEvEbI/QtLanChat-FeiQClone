#ifndef UNICASTSENDER_H
#define UNICASTSENDER_H

#include <QtCore/QObject>
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QHostAddress>

class UnicastSender : public QObject {
    Q_OBJECT

public:
    explicit UnicastSender(QObject* parent = nullptr);
    void sendMessage(const QString& message, const QHostAddress& targetAddr, quint16 port);

private:
    QUdpSocket* m_socket;
};

#endif // UNICASTSENDER_H

