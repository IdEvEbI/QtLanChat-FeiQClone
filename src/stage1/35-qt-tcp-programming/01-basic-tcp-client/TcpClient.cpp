#include "TcpClient.h"
#include <QtCore/QDebug>

TcpClient::TcpClient(QObject *parent)
    : QObject(parent)
{
    m_socket = new QTcpSocket(this);

    // 连接信号
    connect(m_socket, &QTcpSocket::connected, this, &TcpClient::onConnected);
    connect(m_socket, &QTcpSocket::disconnected, this, &TcpClient::onDisconnected);
    connect(m_socket, &QTcpSocket::readyRead, this, &TcpClient::onReadyRead);
    connect(m_socket, &QTcpSocket::errorOccurred, this, &TcpClient::onError);
}

TcpClient::~TcpClient()
{
    if (m_socket) {
        m_socket->disconnectFromHost();
    }
}

void TcpClient::connectToServer(const QString &host, quint16 port)
{
    m_socket->connectToHost(host, port);
    qDebug() << "正在连接到服务器：" << host << ":" << port;
}

void TcpClient::sendData(const QByteArray &data)
{
    if (m_socket->state() == QAbstractSocket::ConnectedState) {
        m_socket->write(data);
        m_socket->flush(); // 确保数据立即发送
        qDebug() << "发送数据：" << data;
    } else {
        qDebug() << "未连接到服务器，无法发送数据";
    }
}

void TcpClient::disconnectFromServer()
{
    m_socket->disconnectFromHost();
}

void TcpClient::onConnected()
{
    qDebug() << "连接成功！";
    emit connected();
}

void TcpClient::onDisconnected()
{
    qDebug() << "连接已断开";
    emit disconnected();
}

void TcpClient::onReadyRead()
{
    QByteArray data = m_socket->readAll();
    qDebug() << "收到数据：" << data;
    emit dataReceived(data);
}

void TcpClient::onError(QAbstractSocket::SocketError error)
{
    QString errorString = m_socket->errorString();
    qDebug() << "发生错误：" << errorString;
    emit errorOccurred(errorString);
}

