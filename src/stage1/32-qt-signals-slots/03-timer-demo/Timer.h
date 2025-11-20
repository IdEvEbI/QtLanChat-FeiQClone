#ifndef TIMER_H
#define TIMER_H

#include <QtCore/QObject>
#include <QtCore/QTimer>
// QTimer 是 Qt 的定时器类，用于定时触发事件（将在后续文档中详细学习）

class Timer : public QObject {
    Q_OBJECT

public:
    explicit Timer(QObject* parent = nullptr) : QObject(parent) {
        // 创建 QTimer 对象，this 参数表示 m_timer 是 Timer 对象的子对象
        // 当 Timer 对象销毁时，Qt 会自动销毁所有子对象，不需要手动 delete
        m_timer = new QTimer(this);
        QObject::connect(m_timer, &QTimer::timeout, this, &Timer::onTimeout);
    }

    // 注意：不需要手动编写析构函数来销毁 m_timer
    // 因为 m_timer 是 Timer 的子对象（通过 this 参数设置），Qt 会自动管理其生命周期

    void start(int intervalMs = 1000) {
        m_timer->start(intervalMs);
    }

    void stop() {
        // stop() 函数用于正常停止定时器（例如在程序逻辑中需要停止定时器时调用）
        // 如果程序被 Ctrl+C 强制终止，stop() 函数不会被调用，程序会直接退出
        m_timer->stop();
    }

signals:
    void timeout();                     // 声明信号

private slots:
    void onTimeout() {
        emit timeout();                 // 发出信号
    }

private:
    QTimer* m_timer;
};

#endif // TIMER_H

