#ifndef MESSAGERECEIVER_H
#define MESSAGERECEIVER_H

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QDebug>

class MessageReceiver : public QObject {
    Q_OBJECT

public:
    explicit MessageReceiver(const QString& name, QObject* parent = nullptr)
        : QObject(parent), m_name(name) {}

public slots:
    void onMessageReceived(const QString& message) {
        qDebug() << "[Receiver:" << m_name << "] Received:" << message;
    }

private:
    QString m_name;
};

#endif // MESSAGERECEIVER_H

