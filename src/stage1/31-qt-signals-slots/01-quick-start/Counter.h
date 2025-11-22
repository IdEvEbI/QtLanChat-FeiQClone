#ifndef COUNTER_H
#define COUNTER_H

#include <QtCore/QObject>
#include <QtCore/QDebug>

class Counter : public QObject {
    Q_OBJECT                            // 必须添加，用于 MOC 处理信号槽

public:
    // explicit 关键字：防止隐式类型转换
    // 例如：如果没有 explicit，可以写 Counter c = nullptr;（隐式转换）
    //       有了 explicit，必须写 Counter c(nullptr);（显式调用）
    //       这样可以避免意外的类型转换，提高代码安全性
    explicit Counter(QObject* parent = nullptr) : QObject(parent), m_value(0) {}

    int value() const { return m_value; }

public slots:
    void increment() {
        m_value++;
        qDebug() << "Counter value:" << m_value;
        emit valueChanged(m_value);     // 发出信号
    }

signals:
    void valueChanged(int newValue);    // 声明信号

private:
    int m_value;
};

#endif // COUNTER_H

