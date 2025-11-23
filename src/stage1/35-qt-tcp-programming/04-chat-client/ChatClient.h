#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <QtCore/QObject>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QAbstractSocket>
#include <QtCore/QTimer>

class ChatClient : public QObject
{
    Q_OBJECT

public:
    explicit ChatClient(QObject *parent = nullptr);
    ~ChatClient();

    void connectToServer(const QString &host, quint16 port);
    void sendMessage(const QString &message);
    void disconnectFromServer();

signals:
    void connected();
    void disconnected();
    void messageReceived(const QString &message);
    void errorOccurred(const QString &errorString);

private slots:
    void onConnected();
    void onDisconnected();
    void onReadyRead();
    void onError(QAbstractSocket::SocketError error);

private:
    QTcpSocket *m_socket;
    QTimer *m_autoSendTimer;
    int m_messageCount;
};

#endif // CHATCLIENT_H

