#include <QtCore/QDebug>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  QWidget window;
  window.setWindowTitle("QMessageBox 示例");
  window.resize(400, 300);

  QVBoxLayout *layout = new QVBoxLayout(&window);

  // 信息对话框
  QPushButton *infoButton = new QPushButton("显示信息", &window);
  QObject::connect(infoButton, &QPushButton::clicked, []() {
    QMessageBox::information(nullptr, "信息", "这是一条信息消息");
  });

  // 警告对话框
  QPushButton *warningButton = new QPushButton("显示警告", &window);
  QObject::connect(warningButton, &QPushButton::clicked, []() {
    QMessageBox::warning(nullptr, "警告", "这是一条警告消息");
  });

  // 错误对话框
  QPushButton *errorButton = new QPushButton("显示错误", &window);
  QObject::connect(errorButton, &QPushButton::clicked, []() {
    QMessageBox::critical(nullptr, "错误", "这是一条错误消息");
  });

  // 问题对话框（确认对话框）
  QPushButton *questionButton = new QPushButton("显示问题", &window);
  QObject::connect(questionButton, &QPushButton::clicked, []() {
    QMessageBox::StandardButton reply =
        QMessageBox::question(nullptr, "确认", "确定要执行此操作吗？",
                              QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
      qDebug() << "用户选择了是";
    } else {
      qDebug() << "用户选择了否";
    }
  });

  // 关于对话框
  QPushButton *aboutButton = new QPushButton("显示关于", &window);
  QObject::connect(aboutButton, &QPushButton::clicked, []() {
    QMessageBox::about(nullptr, "关于", "这是一个示例应用程序\n版本 1.0");
  });

  layout->addWidget(infoButton);
  layout->addWidget(warningButton);
  layout->addWidget(errorButton);
  layout->addWidget(questionButton);
  layout->addWidget(aboutButton);

  window.show();
  return app.exec();
}
