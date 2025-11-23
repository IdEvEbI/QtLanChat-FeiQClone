#include "FileReceiver.h"
#include <QtCore/QDebug>

FileReceiver::FileReceiver(QTcpSocket *socket, QObject *parent)
    : QObject(parent)
    , m_socket(socket)
    , m_file(nullptr)
    , m_fileSize(0)
    , m_bytesReceived(0)
{
    connect(m_socket, &QTcpSocket::readyRead, this, &FileReceiver::onReadyRead);
    connect(m_socket, &QTcpSocket::disconnected, this, &FileReceiver::onDisconnected);
}

FileReceiver::~FileReceiver()
{
    if (m_file) {
        m_file->close();
        delete m_file;
    }
}

void FileReceiver::onReadyRead()
{
    QByteArray data = m_socket->readAll();
    QString dataStr = QString::fromUtf8(data);

    if (dataStr.startsWith("FILE_INFO:")) {
        // 解析文件信息
        // split(":") 将字符串按 ":" 分割成多个部分
        // 例如 "FILE_INFO:test.txt:1024" 分割后得到 ["FILE_INFO", "test.txt", "1024"]
        QStringList parts = dataStr.split(":");
        if (parts.size() >= 3) {
            m_fileName = parts[1];              // 文件名：parts[1]
            m_fileSize = parts[2].toLongLong(); // 文件大小：parts[2]，转换为整数
            m_bytesReceived = 0;

            qDebug() << "开始接收文件：" << m_fileName << "，大小：" << m_fileSize << "字节";

            // 创建文件
            m_file = new QFile("received_" + m_fileName, this);
            if (m_file->open(QIODevice::WriteOnly)) {
                qDebug() << "文件创建成功：" << m_file->fileName();
                m_socket->write("OK");
                m_socket->flush();
            } else {
                qDebug() << "无法创建文件：" << m_fileName;
                m_socket->disconnectFromHost();
                emit errorOccurred(QString("无法创建文件：%1").arg(m_fileName));
            }
        }
    } else if (dataStr.startsWith("FILE_DATA:")) {
        // 接收文件数据
        // mid(10) 表示从第 10 个字符开始提取（跳过 "FILE_DATA:" 前缀）
        // toUtf8() 将 QString 转换为 QByteArray（二进制数据）
        QByteArray fileData = dataStr.mid(10).toUtf8();
        m_file->write(fileData);
        m_bytesReceived += fileData.size();

        int percent = (m_bytesReceived * 100) / m_fileSize;
        qDebug() << "已接收：" << m_bytesReceived << "/" << m_fileSize << "字节 ("
                 << percent << "%)";

        emit progressChanged(m_bytesReceived, m_fileSize);

        m_socket->write("OK");
        m_socket->flush();
    } else if (dataStr == "FILE_END") {
        // 文件传输完成
        m_file->close();
        qDebug() << "文件接收完成：" << m_fileName;
        m_socket->write("FILE_RECEIVED");
        m_socket->flush();
        emit fileReceived(m_fileName, m_fileSize);
    } else {
        qDebug() << "收到未知数据：" << dataStr;
    }
}

void FileReceiver::onDisconnected()
{
    qDebug() << "客户端断开连接";
}

