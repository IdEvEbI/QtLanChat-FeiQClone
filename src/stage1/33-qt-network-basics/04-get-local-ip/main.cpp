#include "NetworkUtils.h"
#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>

int main(int argc, char *argv[]) {
  QCoreApplication app(argc, argv);

  qDebug() << "=== Get Local IP Address ===";

  // 获取第一个 IPv4 地址
  QString localIp = NetworkUtils::getLocalIpAddress();
  if (!localIp.isEmpty()) {
    qDebug() << "Local IP Address:" << localIp;
  } else {
    qDebug() << "No IPv4 address found";
  }

  // 获取所有 IPv4 地址
  qDebug() << "\nAll IPv4 Addresses:";
  QStringList allIps = NetworkUtils::getAllLocalIpAddresses();
  for (const QString &ip : allIps) {
    qDebug() << "  -" << ip;
  }

  return 0;
}
