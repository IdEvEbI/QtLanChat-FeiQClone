#ifndef UDPSENDER_H
#define UDPSENDER_H

#include <QtCore/QObject>
#include <QtNetwork/QUdpSocket>
#include <QtCore/QDebug>

class UdpSender : public QObject {
    Q_OBJECT

public:
    explicit UdpSender(QObject* parent = nullptr) : QObject(parent) {
        m_socket = new QUdpSocket(this);  // 创建 UDP Socket，this 作为父对象，自动管理内存
    }

    void sendMessage(const QString& message, const QHostAddress& address, quint16 port) {
        QByteArray data = message.toUtf8();  // QString 转换为 QByteArray
        qint64 bytesWritten = m_socket->writeDatagram(data, address, port);
        
        if (bytesWritten == -1) {
            qDebug() << "Failed to send message:" << m_socket->errorString();
        } else {
            qDebug() << "Sent" << bytesWritten << "bytes to" << address.toString() << ":" << port;
        }
    }

private:
    QUdpSocket* m_socket;
};

#endif // UDPSENDER_H

