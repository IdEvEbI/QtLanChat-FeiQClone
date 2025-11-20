#ifndef COUNTER_H
#define COUNTER_H

#include <QtCore/QObject>
#include <QtCore/QDebug>

class Counter : public QObject {
    Q_OBJECT  // 必须添加，用于 MOC 处理信号槽

public:
    explicit Counter(QObject* parent = nullptr) : QObject(parent), m_value(0) {}

    int value() const { return m_value; }

public slots:
    void increment() {
        m_value++;
        qDebug() << "Counter value:" << m_value;
        emit valueChanged(m_value);  // 发出信号
    }

signals:
    void valueChanged(int newValue);  // 声明信号

private:
    int m_value;
};

#endif // COUNTER_H

