#include <QtWidgets/QApplication>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("QScrollArea 示例");
    window.resize(400, 300);

    QVBoxLayout *layout = new QVBoxLayout(&window);

    // 创建滚动区域
    QScrollArea *scrollArea = new QScrollArea(&window);
    scrollArea->setWidgetResizable(true);  // 允许内容调整大小

    // 创建内容控件（一个很长的标签）
    QWidget *contentWidget = new QWidget(scrollArea);
    QVBoxLayout *contentLayout = new QVBoxLayout(contentWidget);

    for (int i = 0; i < 20; ++i) {
        QLabel *label = new QLabel(QString("这是第 %1 行内容").arg(i + 1), contentWidget);
        contentLayout->addWidget(label);
    }

    // 设置内容控件
    scrollArea->setWidget(contentWidget);

    // 添加到布局
    layout->addWidget(scrollArea);

    window.show();
    return app.exec();
}

