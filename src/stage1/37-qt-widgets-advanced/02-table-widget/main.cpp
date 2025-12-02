#include <QtWidgets/QApplication>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QtCore/QDebug>
// 注意：QAbstractItemView 通过 QTableWidget 头文件间接包含，无需单独包含

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("QTableWidget 示例");
    window.resize(600, 400);

    QVBoxLayout *layout = new QVBoxLayout(&window);

    // 创建表格控件
    QTableWidget *tableWidget = new QTableWidget(&window);
    tableWidget->setRowCount(3);
    tableWidget->setColumnCount(3);

    // 设置表头
    QStringList headers;
    headers << "姓名" << "年龄" << "城市";
    tableWidget->setHorizontalHeaderLabels(headers);

    // 填充数据
    tableWidget->setItem(0, 0, new QTableWidgetItem("张三"));
    tableWidget->setItem(0, 1, new QTableWidgetItem("25"));
    tableWidget->setItem(0, 2, new QTableWidgetItem("北京"));

    tableWidget->setItem(1, 0, new QTableWidgetItem("李四"));
    tableWidget->setItem(1, 1, new QTableWidgetItem("30"));
    tableWidget->setItem(1, 2, new QTableWidgetItem("上海"));

    tableWidget->setItem(2, 0, new QTableWidgetItem("王五"));
    tableWidget->setItem(2, 1, new QTableWidgetItem("28"));
    tableWidget->setItem(2, 2, new QTableWidgetItem("广州"));

    // 设置选择模式（行选择）
    // QAbstractItemView 是所有视图控件的基类，提供了选择行为等通用功能
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    // 创建按钮
    QPushButton *button = new QPushButton("显示选中行", &window);

    // 连接信号槽
    QObject::connect(button, &QPushButton::clicked, [tableWidget]() {
        QList<QTableWidgetItem*> selectedItems = tableWidget->selectedItems();
        if (!selectedItems.isEmpty()) {
            qDebug() << "选中的行：";
            for (QTableWidgetItem *item : selectedItems) {
                qDebug() << "  -" << item->text();
            }
        }
    });

    // 添加到布局
    layout->addWidget(tableWidget);
    layout->addWidget(button);

    window.show();
    return app.exec();
}

