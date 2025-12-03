#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtCore/QLoggingCategory>

int main(int argc, char *argv[])
{
    // 抑制 macOS 上的 IMK 相关警告消息
    QLoggingCategory::setFilterRules("qt.qpa.input*.debug=false");

    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("QSS 示例");
    window.resize(300, 200);

    QVBoxLayout *layout = new QVBoxLayout(&window);

    // 为按钮设置样式表
    QPushButton *button1 = new QPushButton("红色按钮", &window);
    button1->setStyleSheet(
        "QPushButton {"
        "    background-color: #ff4444;"
        "    color: white;"
        "    border: none;"
        "    padding: 10px;"
        "    border-radius: 5px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #ff6666;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #ff2222;"
        "}"
    );

    // 为按钮设置样式表（圆角）
    QPushButton *button2 = new QPushButton("蓝色按钮", &window);
    button2->setStyleSheet(
        "QPushButton {"
        "    background-color: #4444ff;"
        "    color: white;"
        "    border: none;"
        "    padding: 10px;"
        "    border-radius: 10px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #6666ff;"
        "}"
    );

    layout->addWidget(button1);
    layout->addWidget(button2);

    window.show();
    return app.exec();
}

