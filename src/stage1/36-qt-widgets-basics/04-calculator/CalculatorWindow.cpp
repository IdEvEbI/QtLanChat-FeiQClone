#include "CalculatorWindow.h"
#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

CalculatorWindow::CalculatorWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("简单计算器");
    resize(400, 300);

    // 创建中央控件
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // 创建主布局
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    // 创建表单布局（输入框）
    QFormLayout *formLayout = new QFormLayout();
    m_num1Edit = new QLineEdit(this);
    m_num2Edit = new QLineEdit(this);
    formLayout->addRow("数字 1：", m_num1Edit);
    formLayout->addRow("数字 2：", m_num2Edit);
    mainLayout->addLayout(formLayout);

    // 创建运算符选择（单选按钮）
    QLabel *operatorLabel = new QLabel("运算符：", this);
    mainLayout->addWidget(operatorLabel);

    QHBoxLayout *operatorLayout = new QHBoxLayout();
    m_buttonGroup = new QButtonGroup(this);

    QRadioButton *addRadio = new QRadioButton("加法", this);
    QRadioButton *subRadio = new QRadioButton("减法", this);
    QRadioButton *mulRadio = new QRadioButton("乘法", this);
    QRadioButton *divRadio = new QRadioButton("除法", this);

    m_buttonGroup->addButton(addRadio, 0); // 加法
    m_buttonGroup->addButton(subRadio, 1); // 减法
    m_buttonGroup->addButton(mulRadio, 2); // 乘法
    m_buttonGroup->addButton(divRadio, 3); // 除法

    addRadio->setChecked(true); // 默认选择加法

    operatorLayout->addWidget(addRadio);
    operatorLayout->addWidget(subRadio);
    operatorLayout->addWidget(mulRadio);
    operatorLayout->addWidget(divRadio);
    mainLayout->addLayout(operatorLayout);

    // 创建计算按钮
    QPushButton *calcButton = new QPushButton("计算", this);
    mainLayout->addWidget(calcButton);

    // 创建结果显示标签
    m_resultLabel = new QLabel("结果：", this);
    m_resultLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(m_resultLabel);

    // 添加弹性空间
    mainLayout->addStretch();

    // 连接信号槽
    connect(calcButton, &QPushButton::clicked, this, &CalculatorWindow::calculate);
}

void CalculatorWindow::calculate()
{
    // 获取输入的数字
    bool ok1, ok2;
    double num1 = m_num1Edit->text().toDouble(&ok1);
    double num2 = m_num2Edit->text().toDouble(&ok2);

    if (!ok1 || !ok2) {
        m_resultLabel->setText("结果：输入错误，请输入数字！");
        return;
    }

    // 获取选中的运算符
    int operatorId = m_buttonGroup->checkedId();
    double result = 0.0;

    switch (operatorId) {
    case 0: // 加法
        result = num1 + num2;
        break;
    case 1: // 减法
        result = num1 - num2;
        break;
    case 2: // 乘法
        result = num1 * num2;
        break;
    case 3: // 除法
        if (num2 == 0.0) {
            m_resultLabel->setText("结果：除数不能为 0！");
            return;
        }
        result = num1 / num2;
        break;
    }

    // 显示结果
    m_resultLabel->setText(QString("结果：%1").arg(result));
}

