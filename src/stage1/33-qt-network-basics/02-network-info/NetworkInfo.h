#ifndef NETWORKINFO_H
#define NETWORKINFO_H

#include <QtCore/QDebug>
#include <QtCore/QObject>
#include <QtNetwork/QNetworkInterface>

class NetworkInfo : public QObject {
  Q_OBJECT

public:
  explicit NetworkInfo(QObject *parent = nullptr);

private:
  void printNetworkInfo();
};

#endif // NETWORKINFO_H
