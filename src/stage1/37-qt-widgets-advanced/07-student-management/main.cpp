#include "StudentManagementWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    StudentManagementWindow window;
    window.show();

    return app.exec();
}

