#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QtCore/QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("基础控件示例");
    window.resize(400, 500);

    QVBoxLayout *layout = new QVBoxLayout(&window);

    // 1. QPushButton 示例
    QPushButton *button1 = new QPushButton("普通按钮", &window);
    QPushButton *button2 = new QPushButton("禁用按钮", &window);
    QPushButton *button3 = new QPushButton("切换按钮", &window);
    button2->setEnabled(false);
    button3->setCheckable(true);

    QObject::connect(button1, &QPushButton::clicked, []() {
        qDebug() << "普通按钮被点击了！";
    });

    QObject::connect(button3, &QPushButton::toggled, [](bool checked) {
        qDebug() << "切换按钮状态：" << (checked ? "选中" : "未选中");
    });

    layout->addWidget(new QLabel("QPushButton 示例：", &window));
    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button3);

    // 2. QLineEdit 示例
    QLineEdit *lineEdit1 = new QLineEdit(&window);
    lineEdit1->setPlaceholderText("请输入用户名");
    QLineEdit *lineEdit2 = new QLineEdit(&window);
    lineEdit2->setPlaceholderText("请输入密码");
    lineEdit2->setEchoMode(QLineEdit::Password);

    QObject::connect(lineEdit1, &QLineEdit::textChanged, [](const QString &text) {
        qDebug() << "文本改变：" << text;
    });

    layout->addWidget(new QLabel("QLineEdit 示例：", &window));
    layout->addWidget(lineEdit1);
    layout->addWidget(lineEdit2);

    // 3. QTextEdit 示例
    QTextEdit *textEdit = new QTextEdit(&window);
    // 注意：QTextEdit 没有 setPlaceholderText() 方法
    textEdit->setPlainText("请输入多行文本...\n");

    layout->addWidget(new QLabel("QTextEdit 示例：", &window));
    layout->addWidget(textEdit);

    // 4. QLabel 示例
    QLabel *label1 = new QLabel("普通文本标签", &window);
    QLabel *label2 = new QLabel("居中对齐的标签", &window);
    label2->setAlignment(Qt::AlignCenter);
    QLabel *label3 = new QLabel("这是一个很长的文本标签，支持自动换行功能，当文本超过控件宽度时会自动换行显示", &window);
    label3->setWordWrap(true);

    layout->addWidget(new QLabel("QLabel 示例：", &window));
    layout->addWidget(label1);
    layout->addWidget(label2);
    layout->addWidget(label3);

    // 5. QCheckBox 示例
    QCheckBox *checkBox1 = new QCheckBox("选项 1", &window);
    QCheckBox *checkBox2 = new QCheckBox("选项 2", &window);
    QCheckBox *checkBox3 = new QCheckBox("选项 3（默认选中）", &window);
    checkBox3->setChecked(true);

    QObject::connect(checkBox1, &QCheckBox::toggled, [](bool checked) {
        qDebug() << "选项 1：" << (checked ? "选中" : "未选中");
    });

    layout->addWidget(new QLabel("QCheckBox 示例：", &window));
    layout->addWidget(checkBox1);
    layout->addWidget(checkBox2);
    layout->addWidget(checkBox3);

    // 6. QRadioButton 示例
    QButtonGroup *buttonGroup = new QButtonGroup(&window);
    QRadioButton *radio1 = new QRadioButton("选项 1", &window);
    QRadioButton *radio2 = new QRadioButton("选项 2", &window);
    QRadioButton *radio3 = new QRadioButton("选项 3", &window);

    buttonGroup->addButton(radio1, 1);
    buttonGroup->addButton(radio2, 2);
    buttonGroup->addButton(radio3, 3);
    radio1->setChecked(true);

    // 在 Qt 6 中，使用 idClicked 信号来获取按钮 ID
    QObject::connect(buttonGroup, QOverload<int>::of(&QButtonGroup::idClicked), [](int id) {
        qDebug() << "选中的选项 ID：" << id;
    });

    layout->addWidget(new QLabel("QRadioButton 示例：", &window));
    layout->addWidget(radio1);
    layout->addWidget(radio2);
    layout->addWidget(radio3);

    layout->addStretch();

    window.show();
    return app.exec();
}

