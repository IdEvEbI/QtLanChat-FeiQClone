#include "NetworkInfo.h"

NetworkInfo::NetworkInfo(QObject *parent) : QObject(parent) {
  printNetworkInfo();
}

void NetworkInfo::printNetworkInfo() {
  QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();

  qDebug() << "=== Network Interfaces ===";

  for (const QNetworkInterface &interface : interfaces) {
    // 跳过非活动接口
    if (!interface.flags().testFlag(QNetworkInterface::IsUp)) {
      continue;
    }

    qDebug() << "\nInterface:" << interface.name();
    qDebug() << "  Hardware Address:" << interface.hardwareAddress();
    qDebug() << "  Is Loopback:"
             << interface.flags().testFlag(QNetworkInterface::IsLoopBack);
    qDebug() << "  Is Up:"
             << interface.flags().testFlag(QNetworkInterface::IsUp);

    // 获取 IP 地址
    QList<QNetworkAddressEntry> entries = interface.addressEntries();
    for (const QNetworkAddressEntry &entry : entries) {
      QHostAddress addr = entry.ip();
      if (addr.protocol() == QAbstractSocket::IPv4Protocol) {
        qDebug() << "  IPv4 Address:" << addr.toString();
        qDebug() << "  Netmask:" << entry.netmask().toString();
        qDebug() << "  Broadcast:" << entry.broadcast().toString();
      }
    }
  }
}
