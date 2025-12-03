#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtCore/QString>
#include <QtCore/QLoggingCategory>

class ColorPalette
{
public:
    // 主色调
    static constexpr const char* PRIMARY = "#4CAF50";
    static constexpr const char* PRIMARY_DARK = "#388E3C";
    static constexpr const char* PRIMARY_LIGHT = "#66BB6A";

    // 辅助色
    static constexpr const char* SECONDARY = "#2196F3";
    static constexpr const char* SECONDARY_DARK = "#1976D2";
    static constexpr const char* SECONDARY_LIGHT = "#64B5F6";

    // 语义色
    static constexpr const char* SUCCESS = "#4CAF50";
    static constexpr const char* WARNING = "#FF9800";
    static constexpr const char* ERROR = "#F44336";
    static constexpr const char* INFO = "#2196F3";

    // 中性色
    static constexpr const char* BACKGROUND = "#FFFFFF";
    static constexpr const char* SURFACE = "#F5F5F5";
    static constexpr const char* TEXT_PRIMARY = "#212121";
    static constexpr const char* TEXT_SECONDARY = "#757575";
};

int main(int argc, char *argv[])
{
    // 抑制 macOS 上的 IMK 相关警告消息
    QLoggingCategory::setFilterRules("qt.qpa.input*.debug=false");

    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("自定义调色板示例");
    window.resize(300, 300);

    QVBoxLayout *layout = new QVBoxLayout(&window);

    QPushButton *primaryButton = new QPushButton("主要按钮", &window);
    primaryButton->setObjectName("primaryButton");
    QPushButton *secondaryButton = new QPushButton("次要按钮", &window);
    secondaryButton->setObjectName("secondaryButton");
    QPushButton *successButton = new QPushButton("成功", &window);
    successButton->setObjectName("successButton");
    QPushButton *warningButton = new QPushButton("警告", &window);
    warningButton->setObjectName("warningButton");
    QPushButton *errorButton = new QPushButton("错误", &window);
    errorButton->setObjectName("errorButton");

    // 使用自定义调色板
    QString styleSheet = QString(
        "QPushButton {"
        "    padding: 10px;"
        "    border-radius: 5px;"
        "    border: none;"
        "    color: white;"
        "}"
        "QPushButton#primaryButton {"
        "    background-color: %1;"
        "}"
        "QPushButton#primaryButton:hover {"
        "    background-color: %2;"
        "}"
        "QPushButton#secondaryButton {"
        "    background-color: %3;"
        "}"
        "QPushButton#secondaryButton:hover {"
        "    background-color: %4;"
        "}"
        "QPushButton#successButton {"
        "    background-color: %5;"
        "}"
        "QPushButton#warningButton {"
        "    background-color: %6;"
        "}"
        "QPushButton#errorButton {"
        "    background-color: %7;"
        "}"
    ).arg(ColorPalette::PRIMARY)
     .arg(ColorPalette::PRIMARY_LIGHT)
     .arg(ColorPalette::SECONDARY)
     .arg(ColorPalette::SECONDARY_LIGHT)
     .arg(ColorPalette::SUCCESS)
     .arg(ColorPalette::WARNING)
     .arg(ColorPalette::ERROR);

    app.setStyleSheet(styleSheet);

    layout->addWidget(primaryButton);
    layout->addWidget(secondaryButton);
    layout->addWidget(successButton);
    layout->addWidget(warningButton);
    layout->addWidget(errorButton);

    window.show();
    return app.exec();
}

