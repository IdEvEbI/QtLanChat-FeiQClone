#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QMenu>
#include <QtGui/QAction>
#include <QtCore/QString>
#include <QtCore/QLoggingCategory>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr)
        : QMainWindow(parent)
        , m_isDarkTheme(false)
    {
        setWindowTitle("主题切换示例");
        resize(400, 300);

        QWidget *centralWidget = new QWidget(this);
        setCentralWidget(centralWidget);

        QVBoxLayout *layout = new QVBoxLayout(centralWidget);

        m_button = new QPushButton("切换主题", this);
        connect(m_button, &QPushButton::clicked, this, &MainWindow::toggleTheme);

        layout->addWidget(m_button);

        // 创建菜单
        QMenuBar *menuBar = this->menuBar();
        QMenu *themeMenu = menuBar->addMenu("主题");
        QAction *lightAction = themeMenu->addAction("浅色主题");
        QAction *darkAction = themeMenu->addAction("深色主题");

        connect(lightAction, &QAction::triggered, this, &MainWindow::setLightTheme);
        connect(darkAction, &QAction::triggered, this, &MainWindow::setDarkTheme);

        // 应用初始主题（浅色）
        setLightTheme();
    }

private slots:
    void toggleTheme()
    {
        if (m_isDarkTheme) {
            setLightTheme();
        } else {
            setDarkTheme();
        }
    }

    void setLightTheme()
    {
        m_isDarkTheme = false;
        qApp->setStyleSheet(
            "QMainWindow {"
            "    background-color: #FFFFFF;"
            "}"
            "QPushButton {"
            "    background-color: #4CAF50;"
            "    color: white;"
            "    padding: 10px;"
            "    border-radius: 5px;"
            "    border: none;"
            "}"
            "QPushButton:hover {"
            "    background-color: #66BB6A;"
            "}"
            "QMenuBar {"
            "    background-color: #F5F5F5;"
            "    color: #333333;"
            "}"
            "QMenu {"
            "    background-color: white;"
            "    color: #333333;"
            "}"
        );
    }

    void setDarkTheme()
    {
        m_isDarkTheme = true;
        qApp->setStyleSheet(
            "QMainWindow {"
            "    background-color: #1E1E1E;"
            "}"
            "QPushButton {"
            "    background-color: #4CAF50;"
            "    color: white;"
            "    padding: 10px;"
            "    border-radius: 5px;"
            "    border: none;"
            "}"
            "QPushButton:hover {"
            "    background-color: #66BB6A;"
            "}"
            "QMenuBar {"
            "    background-color: #2D2D2D;"
            "    color: #FFFFFF;"
            "}"
            "QMenu {"
            "    background-color: #2D2D2D;"
            "    color: #FFFFFF;"
            "}"
        );
    }

private:
    QPushButton *m_button;
    bool m_isDarkTheme;
};

#include "main.moc"

int main(int argc, char *argv[])
{
    // 抑制 macOS 上的 IMK 相关警告消息
    QLoggingCategory::setFilterRules("qt.qpa.input*.debug=false");

    QApplication app(argc, argv);

    MainWindow window;
    window.show();

    return app.exec();
}

