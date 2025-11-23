#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <QtCore/QObject>
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QHostAddress>
#include <QtCore/QString>

class ChatClient : public QObject {
    Q_OBJECT

public:
    enum MessageType {
        Unicast,    // 单播
        Broadcast,  // 广播
        Multicast   // 多播
    };

    explicit ChatClient(QObject* parent = nullptr);
    ~ChatClient();

    bool start(quint16 port);
    void stop();

    void sendMessage(const QString& message, MessageType type,
                     const QHostAddress& targetAddr = QHostAddress());

signals:
    void messageReceived(const QString& message, const QHostAddress& senderAddr, quint16 senderPort);

private slots:
    void onReadyRead();

private:
    QUdpSocket* m_socket;
    QHostAddress m_multicastAddr;
    quint16 m_port;
    bool m_isMulticastJoined;
};

#endif // CHATCLIENT_H

