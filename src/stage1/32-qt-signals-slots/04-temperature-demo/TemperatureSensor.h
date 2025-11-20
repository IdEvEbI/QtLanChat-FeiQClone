#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#include <QtCore/QObject>

class TemperatureSensor : public QObject {
    Q_OBJECT

public:
    explicit TemperatureSensor(QObject* parent = nullptr) : QObject(parent), m_temperature(0.0) {}

    void setTemperature(double temp) {
        if (m_temperature != temp) {
            m_temperature = temp;
            emit temperatureChanged(m_temperature);
        }
    }

    double temperature() const { return m_temperature; }

signals:
    void temperatureChanged(double temperature);

private:
    double m_temperature;
};

#endif // TEMPERATURESENSOR_H

