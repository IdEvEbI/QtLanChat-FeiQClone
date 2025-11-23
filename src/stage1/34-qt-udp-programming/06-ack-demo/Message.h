#ifndef MESSAGE_H
#define MESSAGE_H

#include <QtCore/QByteArray>
#include <QtCore/QDataStream>

enum MessageType {
    MSG_DATA = 0x01,        // 数据消息
    MSG_ACK  = 0x02         // ACK 确认消息
};

struct Message {
    quint8  type;           // 消息类型（MSG_DATA 或 MSG_ACK）
    quint32 seqNum;         // 序列号
    QByteArray data;        // 消息数据

    // 序列化
    QByteArray toByteArray() const {
        QByteArray buffer;
        QDataStream stream(&buffer, QIODevice::WriteOnly);
        stream << type << seqNum << data;
        return buffer;
    }

    // 反序列化
    static Message fromByteArray(const QByteArray& buffer) {
        Message msg;
        QDataStream stream(buffer);
        stream >> msg.type >> msg.seqNum >> msg.data;
        return msg;
    }
};

#endif // MESSAGE_H

