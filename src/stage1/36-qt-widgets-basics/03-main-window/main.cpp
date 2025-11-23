#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QtCore/QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMainWindow window;
    window.setWindowTitle("QMainWindow 示例");
    window.resize(400, 300);

    // 创建菜单栏
    QMenuBar *menuBar = window.menuBar();
    QMenu *fileMenu = menuBar->addMenu("文件");
    // QMenu 和 QAction 是菜单相关的类（将在后续文档 38-qt-widgets-multi-window.md 中详细介绍）
    fileMenu->addAction("新建");
    fileMenu->addAction("打开");
    fileMenu->addAction("保存");
    fileMenu->addAction("退出");

    QMenu *editMenu = menuBar->addMenu("编辑");
    editMenu->addAction("复制");
    editMenu->addAction("粘贴");
    editMenu->addAction("剪切");

    QMenu *helpMenu = menuBar->addMenu("帮助");
    helpMenu->addAction("关于");

    // 创建状态栏
    QStatusBar *statusBar = window.statusBar();
    statusBar->showMessage("就绪");

    // 创建中央控件
    QWidget *centralWidget = new QWidget(&window);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    QPushButton *button = new QPushButton("点击我", centralWidget);
    QObject::connect(button, &QPushButton::clicked, [statusBar]() {
        statusBar->showMessage("按钮被点击了！", 2000);
        qDebug() << "按钮被点击了！";
    });

    layout->addWidget(button);
    layout->addStretch();

    window.setCentralWidget(centralWidget);
    window.show();

    return app.exec();
}

