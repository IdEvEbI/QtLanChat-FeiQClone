#ifndef NETWORKVALIDATOR_H
#define NETWORKVALIDATOR_H

#include <QtCore/QDebug>
#include <QtCore/QObject>
#include <QtNetwork/QHostAddress>

class NetworkValidator : public QObject {
  Q_OBJECT

public:
  explicit NetworkValidator(QObject *parent = nullptr);

private:
  void validateAddresses();
  void validatePorts();
};

#endif // NETWORKVALIDATOR_H
