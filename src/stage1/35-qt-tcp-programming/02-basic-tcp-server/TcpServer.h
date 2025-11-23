#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QtCore/QObject>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>

class TcpServer : public QObject
{
    Q_OBJECT

public:
    explicit TcpServer(QObject *parent = nullptr);
    ~TcpServer();

    bool startServer(quint16 port);
    void stopServer();

signals:
    void clientConnected(const QString &address, quint16 port);
    void clientDisconnected(const QString &address);
    void dataReceived(const QString &address, const QByteArray &data);

private slots:
    void onNewConnection();
    void onClientReadyRead();
    void onClientDisconnected();

private:
    QTcpServer *m_server;
    QList<QTcpSocket*> m_clients;
};

#endif // TCPSERVER_H

