#include <QtCore/QDebug>
#include <QtGui/QAction>
#include <QtGui/QCloseEvent>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

class SettingsDialog : public QDialog {
  Q_OBJECT

public:
  explicit SettingsDialog(QWidget *parent = nullptr) : QDialog(parent) {
    setWindowTitle("设置");
    setModal(false);
    resize(400, 300);

    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *serverLabel = new QLabel("服务器地址：", this);
    m_serverEdit = new QLineEdit(this);
    m_serverEdit->setPlaceholderText("例如：192.168.1.100");

    QLabel *portLabel = new QLabel("端口：", this);
    m_portEdit = new QLineEdit(this);
    m_portEdit->setPlaceholderText("例如：12345");

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    QPushButton *applyButton = new QPushButton("应用", this);
    QPushButton *cancelButton = new QPushButton("取消", this);

    connect(applyButton, &QPushButton::clicked, this,
            &SettingsDialog::onApplyClicked);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::close);

    buttonLayout->addWidget(applyButton);
    buttonLayout->addWidget(cancelButton);

    layout->addWidget(serverLabel);
    layout->addWidget(m_serverEdit);
    layout->addWidget(portLabel);
    layout->addWidget(m_portEdit);
    layout->addLayout(buttonLayout);
  }

signals:
  void settingsApplied(const QString &server, const QString &port);

private slots:
  void onApplyClicked() {
    QString server = m_serverEdit->text();
    QString port = m_portEdit->text();

    if (server.isEmpty() || port.isEmpty()) {
      QMessageBox::warning(this, "警告", "请填写完整的服务器地址和端口");
      return;
    }

    emit settingsApplied(server, port);
    QMessageBox::information(this, "提示", "设置已应用");
    close();
  }

private:
  QLineEdit *m_serverEdit;
  QLineEdit *m_portEdit;
};

class AboutDialog : public QDialog {
  Q_OBJECT

public:
  explicit AboutDialog(QWidget *parent = nullptr) : QDialog(parent) {
    setWindowTitle("关于");
    setModal(true);
    resize(350, 200);

    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *titleLabel = new QLabel("QtLanChat", this);
    titleLabel->setStyleSheet("font-size: 18px; font-weight: bold;");

    QLabel *versionLabel = new QLabel("版本 1.0", this);
    QLabel *descLabel =
        new QLabel("一个局域网聊天软件\n支持文字聊天、文件传输等功能", this);
    descLabel->setWordWrap(true);

    QPushButton *okButton = new QPushButton("确定", this);
    connect(okButton, &QPushButton::clicked, this, &QDialog::accept);

    layout->addWidget(titleLabel);
    layout->addWidget(versionLabel);
    layout->addWidget(descLabel);
    layout->addWidget(okButton);
  }
};

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
    setWindowTitle("QtLanChat - 主窗口");
    resize(600, 500);

    // 创建菜单栏
    QMenuBar *menuBar = this->menuBar();
    QMenu *fileMenu = menuBar->addMenu("文件");
    QMenu *settingsMenu = menuBar->addMenu("设置");
    QMenu *helpMenu = menuBar->addMenu("帮助");

    // 文件菜单
    QAction *exitAction = fileMenu->addAction("退出");
    connect(exitAction, &QAction::triggered, this, &QWidget::close);

    // 设置菜单
    QAction *settingsAction = settingsMenu->addAction("设置");
    connect(settingsAction, &QAction::triggered, this,
            &MainWindow::openSettings);

    // 帮助菜单
    QAction *aboutAction = helpMenu->addAction("关于");
    connect(aboutAction, &QAction::triggered, this, &MainWindow::showAbout);

    // 创建中央控件
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // 消息显示区域
    m_messageEdit = new QTextEdit(centralWidget);
    m_messageEdit->setReadOnly(true);
    m_messageEdit->setPlainText("欢迎使用 QtLanChat！\n");

    // 输入区域
    QHBoxLayout *inputLayout = new QHBoxLayout();
    m_inputEdit = new QLineEdit(centralWidget);
    m_inputEdit->setPlaceholderText("输入消息...");
    QPushButton *sendButton = new QPushButton("发送", centralWidget);

    connect(sendButton, &QPushButton::clicked, this, &MainWindow::sendMessage);
    connect(m_inputEdit, &QLineEdit::returnPressed, this,
            &MainWindow::sendMessage);

    inputLayout->addWidget(m_inputEdit);
    inputLayout->addWidget(sendButton);

    layout->addWidget(m_messageEdit);
    layout->addLayout(inputLayout);

    // 状态栏
    statusBar()->showMessage("就绪");
  }

private slots:
  void openSettings() {
    if (!m_settingsDialog) {
      m_settingsDialog = new SettingsDialog(this);
      connect(m_settingsDialog, &SettingsDialog::settingsApplied, this,
              &MainWindow::onSettingsApplied);
    }
    m_settingsDialog->show();
    m_settingsDialog->raise();
    m_settingsDialog->activateWindow();
  }

  void showAbout() {
    AboutDialog about(this);
    about.exec();
  }

  void sendMessage() {
    QString message = m_inputEdit->text();
    if (!message.isEmpty()) {
      m_messageEdit->append("我：" + message);
      m_inputEdit->clear();
      statusBar()->showMessage("消息已发送", 2000);
    }
  }

  void onSettingsApplied(const QString &server, const QString &port) {
    statusBar()->showMessage(
        QString("服务器：%1，端口：%2").arg(server).arg(port), 3000);
    qDebug() << "设置已应用 - 服务器：" << server << "，端口：" << port;
  }

protected:
  void closeEvent(QCloseEvent *event) override {
    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "确认", "确定要退出吗？", QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
      event->accept();
    } else {
      event->ignore();
    }
  }

private:
  QTextEdit *m_messageEdit;
  QLineEdit *m_inputEdit;
  SettingsDialog *m_settingsDialog = nullptr;
};

#include "main.moc"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  MainWindow window;
  window.show();

  return app.exec();
}
