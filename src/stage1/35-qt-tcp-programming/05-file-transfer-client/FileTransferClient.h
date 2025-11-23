#ifndef FILETRANSFERCLIENT_H
#define FILETRANSFERCLIENT_H

#include <QtCore/QObject>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QAbstractSocket>
#include <QtCore/QFile>
#include <QtCore/QFileInfo>

class FileTransferClient : public QObject
{
    Q_OBJECT

public:
    explicit FileTransferClient(QObject *parent = nullptr);
    ~FileTransferClient();

    void sendFile(const QString &filePath, const QString &host, quint16 port);

signals:
    void connected();
    void disconnected();
    void progressChanged(qint64 bytesSent, qint64 totalBytes);
    void transferCompleted();
    void errorOccurred(const QString &errorString);

private slots:
    void onConnected();
    void onDisconnected();
    void onReadyRead();
    void onError(QAbstractSocket::SocketError error);

private:
    void sendFileData();

    QTcpSocket *m_socket;
    QString m_filePath;
    QFile *m_file;
    qint64 m_bytesSent;
    qint64 m_fileSize;
};

#endif // FILETRANSFERCLIENT_H

