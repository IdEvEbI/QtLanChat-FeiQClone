#include "LoginWindow.h"
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

LoginWindow::LoginWindow(QWidget *parent) : QWidget(parent) {
  setWindowTitle("登录窗口");
  resize(300, 150);

  QVBoxLayout *mainLayout = new QVBoxLayout(this);

  QFormLayout *formLayout = new QFormLayout();
  m_usernameEdit = new QLineEdit(this);
  m_passwordEdit = new QLineEdit(this);
  m_passwordEdit->setEchoMode(QLineEdit::Password);

  formLayout->addRow("用户名：", m_usernameEdit);
  formLayout->addRow("密码：", m_passwordEdit);
  mainLayout->addLayout(formLayout);

  QPushButton *loginButton = new QPushButton("登录", this);
  mainLayout->addWidget(loginButton);

  m_resultLabel = new QLabel("", this);
  mainLayout->addWidget(m_resultLabel);

  connect(loginButton, &QPushButton::clicked, this, &LoginWindow::login);
}

void LoginWindow::login() {
  QString username = m_usernameEdit->text();
  QString password = m_passwordEdit->text();

  // 简单验证（实际应用中应该连接数据库或网络验证）
  if (username == "admin" && password == "123456") {
    m_resultLabel->setText("登录成功！");
    m_resultLabel->setStyleSheet(
        "color: green;"); // 设置样式表，将文字颜色设为绿色
  } else {
    m_resultLabel->setText("用户名或密码错误！");
    m_resultLabel->setStyleSheet(
        "color: red;"); // 设置样式表，将文字颜色设为红色
  }
}
