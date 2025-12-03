#include <QtCore/QDebug>
#include <QtWidgets/QApplication>
#include <QtWidgets/QInputDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  QWidget window;
  window.setWindowTitle("QInputDialog 示例");
  window.resize(400, 300);

  QVBoxLayout *layout = new QVBoxLayout(&window);

  // 文本输入
  QPushButton *textButton = new QPushButton("输入文本", &window);
  QObject::connect(textButton, &QPushButton::clicked, []() {
    bool ok;
    QString text = QInputDialog::getText(nullptr, "输入文本", "请输入用户名：",
                                         QLineEdit::Normal, "", &ok);
    if (ok && !text.isEmpty()) {
      qDebug() << "输入的文本：" << text;
    }
  });

  // 整数输入
  QPushButton *intButton = new QPushButton("输入整数", &window);
  QObject::connect(intButton, &QPushButton::clicked, []() {
    bool ok;
    int value = QInputDialog::getInt(nullptr, "输入整数", "请输入年龄：", 20, 0,
                                     150, 1, &ok);
    if (ok) {
      qDebug() << "输入的整数：" << value;
    }
  });

  // 浮点数输入
  QPushButton *doubleButton = new QPushButton("输入浮点数", &window);
  QObject::connect(doubleButton, &QPushButton::clicked, []() {
    bool ok;
    double value = QInputDialog::getDouble(
        nullptr, "输入浮点数", "请输入价格：", 0.0, 0.0, 10000.0, 2, &ok);
    if (ok) {
      qDebug() << "输入的浮点数：" << value;
    }
  });

  // 下拉选择
  QPushButton *itemButton = new QPushButton("选择选项", &window);
  QObject::connect(itemButton, &QPushButton::clicked, []() {
    QStringList items;
    items << "选项1" << "选项2" << "选项3";
    bool ok;
    QString item = QInputDialog::getItem(
        nullptr, "选择选项", "请选择一个选项：", items, 0, false, &ok);
    if (ok && !item.isEmpty()) {
      qDebug() << "选择的选项：" << item;
    }
  });

  layout->addWidget(textButton);
  layout->addWidget(intButton);
  layout->addWidget(doubleButton);
  layout->addWidget(itemButton);

  window.show();
  return app.exec();
}
