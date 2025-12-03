#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QMenu>
#include <QtWidgets/QStatusBar>
#include <QtGui/QAction>
#include <QtCore/QString>
#include <QtCore/QLoggingCategory>

class ChatWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChatWindow(QWidget *parent = nullptr)
        : QMainWindow(parent)
    {
        setWindowTitle("QtLanChat - 美化版");
        resize(800, 600);

        // 创建菜单栏
        QMenuBar *menuBar = this->menuBar();
        QMenu *fileMenu = menuBar->addMenu("文件");
        QMenu *viewMenu = menuBar->addMenu("视图");
        QMenu *helpMenu = menuBar->addMenu("帮助");

        QAction *exitAction = fileMenu->addAction("退出");
        connect(exitAction, &QAction::triggered, this, &QWidget::close);

        QAction *lightThemeAction = viewMenu->addAction("浅色主题");
        QAction *darkThemeAction = viewMenu->addAction("深色主题");
        connect(lightThemeAction, &QAction::triggered, this, &ChatWindow::setLightTheme);
        connect(darkThemeAction, &QAction::triggered, this, &ChatWindow::setDarkTheme);

        // 创建中央控件
        QWidget *centralWidget = new QWidget(this);
        setCentralWidget(centralWidget);

        QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);
        mainLayout->setSpacing(0);
        mainLayout->setContentsMargins(0, 0, 0, 0);

        // 用户列表
        QWidget *userListWidget = new QWidget(centralWidget);
        userListWidget->setFixedWidth(200);
        QVBoxLayout *userListLayout = new QVBoxLayout(userListWidget);
        userListLayout->setContentsMargins(0, 0, 0, 0);

        QLabel *userListTitle = new QLabel("在线用户", userListWidget);
        userListTitle->setObjectName("userListTitle");

        m_userList = new QListWidget(userListWidget);
        m_userList->addItem("用户 1");
        m_userList->addItem("用户 2");
        m_userList->addItem("用户 3");

        userListLayout->addWidget(userListTitle);
        userListLayout->addWidget(m_userList);

        // 聊天区域
        QWidget *chatWidget = new QWidget(centralWidget);
        QVBoxLayout *chatLayout = new QVBoxLayout(chatWidget);
        chatLayout->setContentsMargins(0, 0, 0, 0);
        chatLayout->setSpacing(0);

        m_messageArea = new QTextEdit(chatWidget);
        m_messageArea->setReadOnly(true);
        m_messageArea->setPlainText("欢迎使用 QtLanChat！\n");

        QWidget *inputWidget = new QWidget(chatWidget);
        QHBoxLayout *inputLayout = new QHBoxLayout(inputWidget);
        inputLayout->setContentsMargins(10, 10, 10, 10);

        m_inputEdit = new QLineEdit(inputWidget);
        m_inputEdit->setPlaceholderText("输入消息...");

        m_sendButton = new QPushButton("发送", inputWidget);
        m_sendButton->setObjectName("sendButton");

        connect(m_sendButton, &QPushButton::clicked, this, &ChatWindow::sendMessage);
        connect(m_inputEdit, &QLineEdit::returnPressed, this, &ChatWindow::sendMessage);

        inputLayout->addWidget(m_inputEdit);
        inputLayout->addWidget(m_sendButton);

        chatLayout->addWidget(m_messageArea);
        chatLayout->addWidget(inputWidget);

        mainLayout->addWidget(userListWidget);
        mainLayout->addWidget(chatWidget);

        // 状态栏
        statusBar()->showMessage("就绪");

        // 应用初始主题
        setLightTheme();
    }

private slots:
    void sendMessage()
    {
        QString message = m_inputEdit->text();
        if (!message.isEmpty()) {
            m_messageArea->append("我：" + message);
            m_inputEdit->clear();
            statusBar()->showMessage("消息已发送", 2000);
        }
    }

    void setLightTheme()
    {
        qApp->setStyleSheet(
            "QMainWindow {"
            "    background-color: #FFFFFF;"
            "}"
            "QMenuBar {"
            "    background-color: #F5F5F5;"
            "    color: #212121;"
            "    border-bottom: 1px solid #E0E0E0;"
            "}"
            "QMenu {"
            "    background-color: white;"
            "    color: #212121;"
            "    border: 1px solid #E0E0E0;"
            "}"
            "QMenu::item:selected {"
            "    background-color: #E3F2FD;"
            "}"
            "QLabel#userListTitle {"
            "    background-color: #2196F3;"
            "    color: white;"
            "    padding: 10px;"
            "    font-size: 14px;"
            "    font-weight: bold;"
            "}"
            "QListWidget {"
            "    background-color: #FAFAFA;"
            "    border: none;"
            "    font-size: 14px;"
            "}"
            "QListWidget::item {"
            "    padding: 8px;"
            "    border-bottom: 1px solid #E0E0E0;"
            "}"
            "QListWidget::item:hover {"
            "    background-color: #E3F2FD;"
            "}"
            "QListWidget::item:selected {"
            "    background-color: #2196F3;"
            "    color: white;"
            "}"
            "QTextEdit {"
            "    background-color: white;"
            "    border: none;"
            "    font-size: 14px;"
            "    padding: 10px;"
            "}"
            "QLineEdit {"
            "    background-color: white;"
            "    border: 1px solid #E0E0E0;"
            "    border-radius: 4px;"
            "    padding: 8px;"
            "    font-size: 14px;"
            "}"
            "QLineEdit:focus {"
            "    border: 2px solid #2196F3;"
            "}"
            "QPushButton#sendButton {"
            "    background-color: #2196F3;"
            "    color: white;"
            "    border: none;"
            "    border-radius: 4px;"
            "    padding: 8px 20px;"
            "    font-size: 14px;"
            "    font-weight: bold;"
            "}"
            "QPushButton#sendButton:hover {"
            "    background-color: #1976D2;"
            "}"
            "QPushButton#sendButton:pressed {"
            "    background-color: #1565C0;"
            "}"
            "QStatusBar {"
            "    background-color: #F5F5F5;"
            "    color: #757575;"
            "    border-top: 1px solid #E0E0E0;"
            "}"
        );
    }

    void setDarkTheme()
    {
        qApp->setStyleSheet(
            "QMainWindow {"
            "    background-color: #1E1E1E;"
            "}"
            "QMenuBar {"
            "    background-color: #2D2D2D;"
            "    color: #FFFFFF;"
            "    border-bottom: 1px solid #404040;"
            "}"
            "QMenu {"
            "    background-color: #2D2D2D;"
            "    color: #FFFFFF;"
            "    border: 1px solid #404040;"
            "}"
            "QMenu::item:selected {"
            "    background-color: #404040;"
            "}"
            "QLabel#userListTitle {"
            "    background-color: #0D7377;"
            "    color: white;"
            "    padding: 10px;"
            "    font-size: 14px;"
            "    font-weight: bold;"
            "}"
            "QListWidget {"
            "    background-color: #252526;"
            "    border: none;"
            "    color: #CCCCCC;"
            "    font-size: 14px;"
            "}"
            "QListWidget::item {"
            "    padding: 8px;"
            "    border-bottom: 1px solid #404040;"
            "}"
            "QListWidget::item:hover {"
            "    background-color: #2A2D2E;"
            "}"
            "QListWidget::item:selected {"
            "    background-color: #0D7377;"
            "    color: white;"
            "}"
            "QTextEdit {"
            "    background-color: #1E1E1E;"
            "    border: none;"
            "    color: #CCCCCC;"
            "    font-size: 14px;"
            "    padding: 10px;"
            "}"
            "QLineEdit {"
            "    background-color: #252526;"
            "    border: 1px solid #404040;"
            "    border-radius: 4px;"
            "    color: #CCCCCC;"
            "    padding: 8px;"
            "    font-size: 14px;"
            "}"
            "QLineEdit:focus {"
            "    border: 2px solid #0D7377;"
            "}"
            "QPushButton#sendButton {"
            "    background-color: #0D7377;"
            "    color: white;"
            "    border: none;"
            "    border-radius: 4px;"
            "    padding: 8px 20px;"
            "    font-size: 14px;"
            "    font-weight: bold;"
            "}"
            "QPushButton#sendButton:hover {"
            "    background-color: #14A085;"
            "}"
            "QPushButton#sendButton:pressed {"
            "    background-color: #0A5D61;"
            "}"
            "QStatusBar {"
            "    background-color: #2D2D2D;"
            "    color: #CCCCCC;"
            "    border-top: 1px solid #404040;"
            "}"
        );
    }

private:
    QListWidget *m_userList;
    QTextEdit *m_messageArea;
    QLineEdit *m_inputEdit;
    QPushButton *m_sendButton;
};

#include "main.moc"

int main(int argc, char *argv[])
{
    // 抑制 macOS 上的 IMK 相关警告消息
    QLoggingCategory::setFilterRules("qt.qpa.input*.debug=false");

    QApplication app(argc, argv);

    ChatWindow window;
    window.show();

    return app.exec();
}

