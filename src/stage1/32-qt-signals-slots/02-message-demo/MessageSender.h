#ifndef MESSAGESENDER_H
#define MESSAGESENDER_H

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QDebug>

class MessageSender : public QObject {
    Q_OBJECT

public:
    explicit MessageSender(QObject* parent = nullptr) : QObject(parent) {}

    void sendMessage(const QString& message) {
        qDebug() << "[Sender] Sending message:" << message;
        emit messageSent(message);  // 发出信号
    }

signals:
    void messageSent(const QString& message);  // 声明信号

private:
    QString m_name;
};

#endif // MESSAGESENDER_H

