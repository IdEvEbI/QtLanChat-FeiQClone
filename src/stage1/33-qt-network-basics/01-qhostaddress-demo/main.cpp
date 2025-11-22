#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>
#include <QtNetwork/QHostAddress>

int main(int argc, char *argv[]) {
  QCoreApplication app(argc, argv);

  qDebug() << "=== QHostAddress Demo ===";

  // 创建 IP 地址对象
  QHostAddress addr1("192.168.1.100");
  QHostAddress addr2 = QHostAddress::LocalHost; // 127.0.0.1
  QHostAddress addr3 = QHostAddress::Broadcast; // 255.255.255.255

  qDebug() << "\n1. Basic IP Address Operations:";
  qDebug() << "   addr1:" << addr1.toString(); // 输出: "192.168.1.100"
  qDebug() << "   addr2 (LocalHost):" << addr2.toString(); // 输出: "127.0.0.1"
  qDebug() << "   addr3 (Broadcast):"
           << addr3.toString(); // 输出: "255.255.255.255"

  // 判断地址类型
  qDebug() << "\n2. Address Type Checking:";
  qDebug() << "   addr1 is null:" << addr1.isNull();
  qDebug() << "   addr1 is loopback:" << addr1.isLoopback();
  qDebug() << "   addr1 is multicast:" << addr1.isMulticast();

  qDebug() << "\n   addr2 is loopback:" << addr2.isLoopback(); // true
  qDebug() << "   addr3 is multicast:"
           << addr3.isMulticast(); // false (broadcast is not multicast)

  // 验证多播地址
  QHostAddress multicastAddr("224.0.0.1");
  qDebug() << "\n3. Multicast Address:";
  qDebug() << "   224.0.0.1 is multicast:"
           << multicastAddr.isMulticast(); // true

  // 验证无效地址
  QHostAddress invalidAddr("999.999.999.999");
  qDebug() << "\n4. Invalid Address:";
  qDebug() << "   999.999.999.999 is null:"
           << invalidAddr.isNull(); // true (invalid address)

  // 使用常量
  qDebug() << "\n5. QHostAddress Constants:";
  qDebug() << "   Null:" << QHostAddress(QHostAddress::Null).toString();
  qDebug() << "   LocalHost:"
           << QHostAddress(QHostAddress::LocalHost).toString();
  qDebug() << "   Broadcast:"
           << QHostAddress(QHostAddress::Broadcast).toString();
  qDebug() << "   AnyIPv4:" << QHostAddress(QHostAddress::AnyIPv4).toString();

  return 0;
}
