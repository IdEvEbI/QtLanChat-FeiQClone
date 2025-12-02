#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QtCore/QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("QComboBox 示例");
    window.resize(400, 200);

    QVBoxLayout *layout = new QVBoxLayout(&window);

    // 创建组合框
    QComboBox *comboBox = new QComboBox(&window);
    comboBox->addItem("选项1");
    comboBox->addItem("选项2");
    comboBox->addItem("选项3");

    // 创建标签
    QLabel *label = new QLabel("当前选择：选项1", &window);

    // 连接信号槽
    QObject::connect(comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
                     [label, comboBox](int index) {
        QString text = comboBox->currentText();
        label->setText("当前选择：" + text);
        qDebug() << "选择了：" << text;
    });

    // 添加到布局
    layout->addWidget(comboBox);
    layout->addWidget(label);

    window.show();
    return app.exec();
}

