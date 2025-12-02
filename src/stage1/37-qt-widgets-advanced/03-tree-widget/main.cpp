#include <QtWidgets/QApplication>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QtCore/QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("QTreeWidget 示例");
    window.resize(400, 400);

    QVBoxLayout *layout = new QVBoxLayout(&window);

    // 创建树形控件
    QTreeWidget *treeWidget = new QTreeWidget(&window);
    treeWidget->setHeaderLabels(QStringList() << "名称" << "类型");

    // 创建顶级节点
    QTreeWidgetItem *root1 = new QTreeWidgetItem(treeWidget);
    root1->setText(0, "文件夹1");
    root1->setText(1, "文件夹");

    // 创建子节点
    QTreeWidgetItem *child1 = new QTreeWidgetItem(root1);
    child1->setText(0, "文件1.txt");
    child1->setText(1, "文件");

    QTreeWidgetItem *child2 = new QTreeWidgetItem(root1);
    child2->setText(0, "文件2.txt");
    child2->setText(1, "文件");

    // 创建另一个顶级节点
    QTreeWidgetItem *root2 = new QTreeWidgetItem(treeWidget);
    root2->setText(0, "文件夹2");
    root2->setText(1, "文件夹");

    QTreeWidgetItem *child3 = new QTreeWidgetItem(root2);
    child3->setText(0, "文件3.txt");
    child3->setText(1, "文件");

    // 连接信号槽
    QObject::connect(treeWidget, &QTreeWidget::itemClicked, [](QTreeWidgetItem *item, int column) {
        qDebug() << "点击了：" << item->text(0);
    });

    // 创建按钮
    QPushButton *button = new QPushButton("显示选中项", &window);
    QObject::connect(button, &QPushButton::clicked, [treeWidget]() {
        QTreeWidgetItem *item = treeWidget->currentItem();
        if (item) {
            qDebug() << "选中的项：" << item->text(0);
        }
    });

    // 添加到布局
    layout->addWidget(treeWidget);
    layout->addWidget(button);

    window.show();
    return app.exec();
}

