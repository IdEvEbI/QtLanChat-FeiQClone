#ifndef NETWORKUTILS_H
#define NETWORKUTILS_H

#include <QtCore/QString>
#include <QtNetwork/QNetworkInterface>

class NetworkUtils {
public:
  // 获取本机的第一个 IPv4 地址（非回环）
  static QString getLocalIpAddress();

  // 获取所有 IPv4 地址
  static QStringList getAllLocalIpAddresses();
};

#endif // NETWORKUTILS_H
