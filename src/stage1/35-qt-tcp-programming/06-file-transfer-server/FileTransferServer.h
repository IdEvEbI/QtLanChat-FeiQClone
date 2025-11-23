#ifndef FILETRANSFERSERVER_H
#define FILETRANSFERSERVER_H

#include <QtCore/QObject>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>

class FileReceiver;

class FileTransferServer : public QObject
{
    Q_OBJECT

public:
    explicit FileTransferServer(QObject *parent = nullptr);
    ~FileTransferServer();

    bool startServer(quint16 port);
    void stopServer();

signals:
    void clientConnected(const QString &address);
    void clientDisconnected(const QString &address);
    void fileReceived(const QString &fileName, qint64 fileSize);

private slots:
    void onNewConnection();

private:
    QTcpServer *m_server;
};

#endif // FILETRANSFERSERVER_H

