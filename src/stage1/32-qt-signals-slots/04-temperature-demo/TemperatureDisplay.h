#ifndef TEMPERATUREDISPLAY_H
#define TEMPERATUREDISPLAY_H

#include <QtCore/QObject>
#include <QtCore/QDebug>

class TemperatureDisplay : public QObject {
    Q_OBJECT

public:
    explicit TemperatureDisplay(QObject* parent = nullptr) : QObject(parent) {}

public slots:
    void onTemperatureChanged(double temperature) {
        qDebug() << "Temperature:" << temperature << "°C";
        if (temperature > 30.0) {
            qDebug() << "Warning: Temperature too high!";
        }
    }
};

#endif // TEMPERATUREDISPLAY_H

