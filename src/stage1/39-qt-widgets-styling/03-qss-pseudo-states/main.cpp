#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtCore/QLoggingCategory>

int main(int argc, char *argv[])
{
    // 抑制 macOS 上的 IMK 相关警告消息
    QLoggingCategory::setFilterRules("qt.qpa.input*.debug=false");

    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("QSS 伪状态示例");
    window.resize(300, 200);

    QVBoxLayout *layout = new QVBoxLayout(&window);

    QPushButton *button = new QPushButton("悬停我", &window);
    QCheckBox *checkbox = new QCheckBox("选中我", &window);

    // 使用伪状态设置样式
    app.setStyleSheet(
        "QPushButton {"
        "    background-color: #4CAF50;"
        "    color: white;"
        "    padding: 10px;"
        "    border-radius: 5px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #66BB6A;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #388E3C;"
        "}"
        "QPushButton:disabled {"
        "    background-color: #CCCCCC;"
        "    color: #666666;"
        "}"
        "QCheckBox {"
        "    font-size: 14px;"
        "}"
        "QCheckBox:checked {"
        "    color: #4CAF50;"
        "}"
    );

    layout->addWidget(button);
    layout->addWidget(checkbox);

    window.show();
    return app.exec();
}

