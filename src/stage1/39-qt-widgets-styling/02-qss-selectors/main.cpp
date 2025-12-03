#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtCore/QString>
#include <QtCore/QLoggingCategory>

int main(int argc, char *argv[])
{
    // 抑制 macOS 上的 IMK 相关警告消息
    QLoggingCategory::setFilterRules("qt.qpa.input*.debug=false");

    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("QSS 选择器示例");
    window.resize(300, 300);

    QVBoxLayout *layout = new QVBoxLayout(&window);

    // 设置对象名称，用于 ID 选择器
    QPushButton *button1 = new QPushButton("按钮 1", &window);
    button1->setObjectName("primaryButton");

    QPushButton *button2 = new QPushButton("按钮 2", &window);
    button2->setObjectName("secondaryButton");

    QPushButton *button3 = new QPushButton("按钮 3", &window);

    // 使用全局样式表，应用不同的选择器
    app.setStyleSheet(
        // 类型选择器：所有 QPushButton
        "QPushButton {"
        "    padding: 10px;"
        "    border-radius: 5px;"
        "    font-size: 14px;"
        "}"
        // ID 选择器：特定 ID 的按钮
        "#primaryButton {"
        "    background-color: #4CAF50;"
        "    color: white;"
        "}"
        "#secondaryButton {"
        "    background-color: #2196F3;"
        "    color: white;"
        "}"
        // 类型选择器 + 伪状态：悬停状态
        "QPushButton:hover {"
        "    opacity: 0.8;"
        "}"
    );

    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button3);

    window.show();
    return app.exec();
}

