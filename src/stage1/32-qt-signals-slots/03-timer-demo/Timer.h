#ifndef TIMER_H
#define TIMER_H

#include <QtCore/QObject>
#include <QtCore/QTimer>

class Timer : public QObject {
    Q_OBJECT

public:
    explicit Timer(QObject* parent = nullptr) : QObject(parent) {
        m_timer = new QTimer(this);
        QObject::connect(m_timer, &QTimer::timeout, this, &Timer::onTimeout);
    }

    void start(int intervalMs = 1000) {
        m_timer->start(intervalMs);
    }

    void stop() {
        m_timer->stop();
    }

signals:
    void timeout();  // 声明信号

private slots:
    void onTimeout() {
        emit timeout();  // 发出信号
    }

private:
    QTimer* m_timer;
};

#endif // TIMER_H

