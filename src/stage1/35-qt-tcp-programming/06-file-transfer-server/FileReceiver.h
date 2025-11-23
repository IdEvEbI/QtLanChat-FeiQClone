#ifndef FILERECEIVER_H
#define FILERECEIVER_H

#include <QtCore/QObject>
#include <QtNetwork/QTcpSocket>
#include <QtCore/QFile>

class FileReceiver : public QObject
{
    Q_OBJECT

public:
    explicit FileReceiver(QTcpSocket *socket, QObject *parent = nullptr);
    ~FileReceiver();

signals:
    void progressChanged(qint64 bytesReceived, qint64 totalBytes);
    void fileReceived(const QString &fileName, qint64 fileSize);
    void errorOccurred(const QString &errorString);

private slots:
    void onReadyRead();
    void onDisconnected();

private:
    QTcpSocket *m_socket;
    QFile *m_file;
    QString m_fileName;
    qint64 m_fileSize;
    qint64 m_bytesReceived;
};

#endif // FILERECEIVER_H

