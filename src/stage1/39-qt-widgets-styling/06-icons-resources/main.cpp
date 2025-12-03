#include <QtCore/QLoggingCategory>
#include <QtCore/QString>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStyle>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

int main(int argc, char *argv[]) {
  // 抑制 macOS 上的 IMK 相关警告消息
  QLoggingCategory::setFilterRules("qt.qpa.input*.debug=false");

  QApplication app(argc, argv);

  QWidget window;
  window.setWindowTitle("QIcon 示例");
  window.resize(300, 200);

  QVBoxLayout *layout = new QVBoxLayout(&window);

  // 使用 Qt 内置的标准图标
  QPushButton *button1 = new QPushButton("打开文件", &window);
  QIcon icon1 = window.style()->standardIcon(QStyle::SP_DirOpenIcon);
  button1->setIcon(icon1);
  button1->setIconSize(QSize(24, 24));

  QPushButton *button2 = new QPushButton("保存文件", &window);
  QIcon icon2 = window.style()->standardIcon(QStyle::SP_DriveHDIcon);
  button2->setIcon(icon2);
  button2->setIconSize(QSize(32, 32));

  QPushButton *button3 = new QPushButton("关于", &window);
  QIcon icon3 = window.style()->standardIcon(QStyle::SP_MessageBoxInformation);
  button3->setIcon(icon3);
  button3->setIconSize(QSize(24, 24));

  layout->addWidget(button1);
  layout->addWidget(button2);
  layout->addWidget(button3);

  window.show();
  return app.exec();
}
