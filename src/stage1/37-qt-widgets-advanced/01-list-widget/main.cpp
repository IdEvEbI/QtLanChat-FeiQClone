#include <QtCore/QDebug>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  QWidget window;
  window.setWindowTitle("QListWidget 示例");
  window.resize(400, 300);

  QVBoxLayout *layout = new QVBoxLayout(&window);

  // 创建列表控件
  QListWidget *listWidget = new QListWidget(&window);

  // 添加列表项
  listWidget->addItem("用户1");
  listWidget->addItem("用户2");
  listWidget->addItem("用户3");

  // 设置选择模式（多选）
  // QAbstractItemView 是所有视图控件的基类，提供了选择模式等通用功能
  listWidget->setSelectionMode(QAbstractItemView::MultiSelection);

  // 创建按钮
  QPushButton *button = new QPushButton("显示选中项", &window);

  // 连接信号槽
  QObject::connect(button, &QPushButton::clicked, [listWidget]() {
    QList<QListWidgetItem *> selectedItems = listWidget->selectedItems();
    qDebug() << "选中的项：";
    for (QListWidgetItem *item : selectedItems) {
      qDebug() << "  -" << item->text();
    }
  });

  // 连接列表项点击信号
  QObject::connect(
      listWidget, &QListWidget::itemClicked,
      [](QListWidgetItem *item) { qDebug() << "点击了：" << item->text(); });

  // 添加到布局
  layout->addWidget(listWidget);
  layout->addWidget(button);

  window.show();
  return app.exec();
}
