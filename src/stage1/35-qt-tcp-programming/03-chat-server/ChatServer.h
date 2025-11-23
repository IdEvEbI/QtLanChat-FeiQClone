#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <QtCore/QObject>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>

class ChatServer : public QObject
{
    Q_OBJECT

public:
    explicit ChatServer(QObject *parent = nullptr);
    ~ChatServer();

    bool startServer(quint16 port);
    void stopServer();

signals:
    void clientConnected(const QString &address, quint16 port);
    void clientDisconnected(const QString &address);
    void messageReceived(const QString &address, const QString &message);

private slots:
    void onNewConnection();
    void onClientReadyRead();
    void onClientDisconnected();

private:
    void broadcastMessage(const QString &senderAddress, const QString &message);

    QTcpServer *m_server;
    QList<QTcpSocket*> m_clients;
};

#endif // CHATSERVER_H

