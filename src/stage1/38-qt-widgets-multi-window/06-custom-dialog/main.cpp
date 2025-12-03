#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMessageBox>
#include <QtCore/QDebug>

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr)
        : QDialog(parent)
    {
        setWindowTitle("登录");
        setModal(true);
        resize(300, 150);

        QVBoxLayout *layout = new QVBoxLayout(this);

        // 用户名输入
        QLabel *usernameLabel = new QLabel("用户名：", this);
        m_usernameEdit = new QLineEdit(this);
        m_usernameEdit->setPlaceholderText("请输入用户名");

        // 密码输入
        QLabel *passwordLabel = new QLabel("密码：", this);
        m_passwordEdit = new QLineEdit(this);
        m_passwordEdit->setPlaceholderText("请输入密码");
        m_passwordEdit->setEchoMode(QLineEdit::Password);

        // 按钮
        QHBoxLayout *buttonLayout = new QHBoxLayout();
        QPushButton *okButton = new QPushButton("确定", this);
        QPushButton *cancelButton = new QPushButton("取消", this);

        // 连接信号槽
        connect(okButton, &QPushButton::clicked, this, &LoginDialog::onOkClicked);
        connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);

        buttonLayout->addWidget(okButton);
        buttonLayout->addWidget(cancelButton);

        layout->addWidget(usernameLabel);
        layout->addWidget(m_usernameEdit);
        layout->addWidget(passwordLabel);
        layout->addWidget(m_passwordEdit);
        layout->addLayout(buttonLayout);
    }

    QString username() const { return m_usernameEdit->text(); }
    QString password() const { return m_passwordEdit->text(); }

private slots:
    void onOkClicked()
    {
        if (m_usernameEdit->text().isEmpty() || m_passwordEdit->text().isEmpty()) {
            QMessageBox::warning(this, "警告", "请输入用户名和密码");
            return;
        }
        accept();
    }

private:
    QLineEdit *m_usernameEdit;
    QLineEdit *m_passwordEdit;
};

#include "main.moc"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    LoginDialog dialog;
    if (dialog.exec() == QDialog::Accepted) {
        qDebug() << "用户名：" << dialog.username();
        qDebug() << "密码：" << dialog.password();
    }

    return app.exec();
}

