#include "NetworkValidator.h"

NetworkValidator::NetworkValidator(QObject *parent) : QObject(parent) {
  validateAddresses();
  validatePorts();
}

void NetworkValidator::validateAddresses() {
  qDebug() << "=== IP Address Validation ===";

  // 验证 IPv4 地址
  QHostAddress addr1("192.168.1.100");
  qDebug() << "192.168.1.100 is valid:" << !addr1.isNull();
  qDebug() << "Is loopback:" << addr1.isLoopback();
  qDebug() << "Is multicast:" << addr1.isMulticast();

  // 验证多播地址
  QHostAddress addr2("224.0.0.1");
  qDebug() << "\n224.0.0.1 is multicast:" << addr2.isMulticast();

  // 验证广播地址
  QHostAddress addr3 = QHostAddress::Broadcast;
  qDebug() << "Broadcast address:" << addr3.toString();

  // 验证无效地址
  QHostAddress addr4("999.999.999.999");
  qDebug() << "\n999.999.999.999 is valid:" << !addr4.isNull();
}

void NetworkValidator::validatePorts() {
  qDebug() << "\n=== Port Validation ===";

  quint16 port1 = 80;    // HTTP
  quint16 port2 = 443;   // HTTPS
  quint16 port3 = 12345; // 自定义端口

  qDebug() << "Port 80 (HTTP):" << port1;
  qDebug() << "Port 443 (HTTPS):" << port2;
  qDebug() << "Port 12345 (Custom):" << port3;

  // 端口范围检查
  if (port1 < 1024) {
    qDebug() << "Port 80 requires administrator privileges";
  }
  if (port3 >= 1024 && port3 <= 65535) {
    qDebug() << "Port 12345 is in user range (1024-65535)";
  }
}
