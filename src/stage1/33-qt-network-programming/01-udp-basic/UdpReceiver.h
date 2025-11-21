#ifndef UDPRECEIVER_H
#define UDPRECEIVER_H

#include <QtCore/QObject>
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QHostAddress>
#include <QtCore/QDebug>

class UdpReceiver : public QObject {
    Q_OBJECT

public:
    explicit UdpReceiver(QObject* parent = nullptr) : QObject(parent) {
        m_socket = new QUdpSocket(this);
        
        // 绑定端口，监听 UDP 数据
        if (!m_socket->bind(QHostAddress::AnyIPv4, 12345)) {
            qDebug() << "Failed to bind port 12345:" << m_socket->errorString();
            return;
        }
        
        // 连接 readyRead 信号到槽函数：当有数据到达时，自动调用 onReadyRead
        // readyRead 信号：当 Socket 有数据可读时发出
        connect(m_socket, &QUdpSocket::readyRead, this, &UdpReceiver::onReadyRead);
        
        qDebug() << "UDP Receiver listening on port 12345";
    }

private slots:
    void onReadyRead() {
        // 读取数据
        while (m_socket->hasPendingDatagrams()) {
            QByteArray datagram;
            datagram.resize(m_socket->pendingDatagramSize());
            
            QHostAddress senderAddress;
            quint16 senderPort;
            
            // 接收数据，获取发送者地址和端口
            qint64 bytesRead = m_socket->readDatagram(datagram.data(), datagram.size(),
                                                      &senderAddress, &senderPort);
            
            if (bytesRead > 0) {
                QString message = QString::fromUtf8(datagram);
                qDebug() << "Received from" << senderAddress.toString() << ":" << senderPort
                         << "Message:" << message;
            }
        }
    }

private:
    QUdpSocket* m_socket;
};

#endif // UDPRECEIVER_H

