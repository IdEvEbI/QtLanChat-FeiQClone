#include "TemperatureDisplay.h"
#include "TemperatureSensor.h"
#include <QtCore/QCoreApplication>

int main(int argc, char *argv[]) {
  QCoreApplication app(argc, argv);

  TemperatureSensor sensor;
  TemperatureDisplay display;

  QObject::connect(&sensor, &TemperatureSensor::temperatureChanged, &display,
                   &TemperatureDisplay::onTemperatureChanged);

  sensor.setTemperature(25.0);
  sensor.setTemperature(30.5);
  sensor.setTemperature(35.0);

  return 0;
}
