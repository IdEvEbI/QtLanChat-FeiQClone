#include "FileTransferClient.h"
#include <QtCore/QDebug>

FileTransferClient::FileTransferClient(QObject *parent)
    : QObject(parent)
    , m_file(nullptr)
    , m_bytesSent(0)
    , m_fileSize(0)
{
    m_socket = new QTcpSocket(this);

    connect(m_socket, &QTcpSocket::connected, this, &FileTransferClient::onConnected);
    connect(m_socket, &QTcpSocket::disconnected, this, &FileTransferClient::onDisconnected);
    connect(m_socket, &QTcpSocket::readyRead, this, &FileTransferClient::onReadyRead);
    connect(m_socket, &QTcpSocket::errorOccurred, this, &FileTransferClient::onError);
}

FileTransferClient::~FileTransferClient()
{
    if (m_file) {
        m_file->close();
        delete m_file;
    }
    if (m_socket) {
        m_socket->disconnectFromHost();
    }
}

void FileTransferClient::sendFile(const QString &filePath, const QString &host, quint16 port)
{
    m_filePath = filePath;
    m_socket->connectToHost(host, port);
}

void FileTransferClient::onConnected()
{
    qDebug() << "连接成功，开始发送文件：" << m_filePath;

    m_file = new QFile(m_filePath, this);
    if (!m_file->open(QIODevice::ReadOnly)) {
        qDebug() << "无法打开文件：" << m_filePath;
        m_socket->disconnectFromHost();
        emit errorOccurred(QString("无法打开文件：%1").arg(m_filePath));
        return;
    }

    QFileInfo fileInfo(*m_file);
    QString fileName = fileInfo.fileName();
    m_fileSize = fileInfo.size();

    qDebug() << "文件信息 - 名称：" << fileName << "，大小：" << m_fileSize << "字节";

    // 发送文件信息：FILE_INFO:文件名:文件大小
    QByteArray fileInfoData = QString("FILE_INFO:%1:%2").arg(fileName).arg(m_fileSize).toUtf8();
    m_socket->write(fileInfoData);
    m_socket->flush();

    m_bytesSent = 0;
    emit connected();
}

void FileTransferClient::onReadyRead()
{
    QByteArray response = m_socket->readAll();
    QString responseStr = QString::fromUtf8(response);

    if (responseStr == "OK") {
        // 服务器确认接收，发送文件数据
        sendFileData();
    } else if (responseStr == "FILE_RECEIVED") {
        qDebug() << "文件传输完成！";
        m_file->close();
        m_socket->disconnectFromHost();
        emit transferCompleted();
    } else {
        qDebug() << "收到未知响应：" << responseStr;
    }
}

void FileTransferClient::sendFileData()
{
    const qint64 chunkSize = 4096; // 每次发送 4KB
    QByteArray buffer = m_file->read(chunkSize);

    if (!buffer.isEmpty()) {
        // 将文件数据包装成协议格式：FILE_DATA:数据内容
        QByteArray dataPacket = "FILE_DATA:" + buffer;
        m_socket->write(dataPacket);
        m_socket->flush();

        m_bytesSent += buffer.size();
        qDebug() << "已发送：" << m_bytesSent << "/" << m_fileSize << "字节 ("
                 << (m_bytesSent * 100 / m_fileSize) << "%)";

        emit progressChanged(m_bytesSent, m_fileSize);

        // 如果文件发送完成，发送结束标志
        if (m_bytesSent >= m_fileSize) {
            m_socket->write("FILE_END");
            m_socket->flush();
        }
    } else {
        // 文件读取完成
        if (m_bytesSent >= m_fileSize) {
            m_socket->write("FILE_END");
            m_socket->flush();
        }
    }
}

void FileTransferClient::onDisconnected()
{
    qDebug() << "连接已断开";
    emit disconnected();
}

void FileTransferClient::onError(QAbstractSocket::SocketError error)
{
    QString errorString = m_socket->errorString();
    qDebug() << "发生错误：" << errorString;
    emit errorOccurred(errorString);
}

