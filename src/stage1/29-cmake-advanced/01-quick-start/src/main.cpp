#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    qDebug() << "Hello from Qt6!";
    qDebug() << "Qt Version:" << QT_VERSION_STR;

    return 0;
}
