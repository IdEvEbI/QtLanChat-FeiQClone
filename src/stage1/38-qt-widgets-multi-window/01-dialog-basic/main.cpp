#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtCore/QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QDialog dialog;
    dialog.setWindowTitle("简单对话框");
    dialog.resize(300, 200);

    QVBoxLayout *layout = new QVBoxLayout(&dialog);

    QLabel *label = new QLabel("这是一个对话框", &dialog);
    QPushButton *okButton = new QPushButton("确定", &dialog);
    QPushButton *cancelButton = new QPushButton("取消", &dialog);

    // 连接信号槽
    QObject::connect(okButton, &QPushButton::clicked, &dialog, &QDialog::accept);
    QObject::connect(cancelButton, &QPushButton::clicked, &dialog, &QDialog::reject);

    layout->addWidget(label);
    layout->addWidget(okButton);
    layout->addWidget(cancelButton);

    // 显示模态对话框
    int result = dialog.exec();
    if (result == QDialog::Accepted) {
        qDebug() << "用户点击了确定";
    } else {
        qDebug() << "用户点击了取消";
    }

    return app.exec();
}

