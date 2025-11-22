#include "NetworkUtils.h"
#include <QtCore/QDebug>

QString NetworkUtils::getLocalIpAddress() {
  QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();

  for (const QNetworkInterface &interface : interfaces) {
    // 跳过回环接口和非活动接口
    if (interface.flags().testFlag(QNetworkInterface::IsLoopBack) ||
        !interface.flags().testFlag(QNetworkInterface::IsUp)) {
      continue;
    }

    QList<QNetworkAddressEntry> entries = interface.addressEntries();
    for (const QNetworkAddressEntry &entry : entries) {
      QHostAddress addr = entry.ip();
      // 返回第一个 IPv4 地址
      if (addr.protocol() == QAbstractSocket::IPv4Protocol &&
          !addr.isLoopback()) {
        return addr.toString();
      }
    }
  }

  return QString(); // 未找到
}

QStringList NetworkUtils::getAllLocalIpAddresses() {
  QStringList ipList;
  QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();

  for (const QNetworkInterface &interface : interfaces) {
    // 跳过回环接口和非活动接口
    if (interface.flags().testFlag(QNetworkInterface::IsLoopBack) ||
        !interface.flags().testFlag(QNetworkInterface::IsUp)) {
      continue;
    }

    QList<QNetworkAddressEntry> entries = interface.addressEntries();
    for (const QNetworkAddressEntry &entry : entries) {
      QHostAddress addr = entry.ip();
      if (addr.protocol() == QAbstractSocket::IPv4Protocol &&
          !addr.isLoopback()) {
        ipList.append(addr.toString());
      }
    }
  }

  return ipList;
}
