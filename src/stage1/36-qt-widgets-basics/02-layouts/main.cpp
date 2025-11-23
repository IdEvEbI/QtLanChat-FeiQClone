#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("布局管理器示例");
    window.resize(500, 600);

    QVBoxLayout *mainLayout = new QVBoxLayout(&window);

    // 1. QVBoxLayout 示例
    QLabel *label1 = new QLabel("QVBoxLayout（垂直布局）示例：", &window);
    QWidget *vboxWidget = new QWidget(&window);
    QVBoxLayout *vboxLayout = new QVBoxLayout(vboxWidget);
    QPushButton *vbtn1 = new QPushButton("按钮 1", vboxWidget);
    QPushButton *vbtn2 = new QPushButton("按钮 2", vboxWidget);
    QPushButton *vbtn3 = new QPushButton("按钮 3", vboxWidget);
    vboxLayout->addWidget(vbtn1);
    vboxLayout->addWidget(vbtn2);
    vboxLayout->addWidget(vbtn3);
    mainLayout->addWidget(label1);
    mainLayout->addWidget(vboxWidget);

    // 2. QHBoxLayout 示例
    QLabel *label2 = new QLabel("QHBoxLayout（水平布局）示例：", &window);
    QWidget *hboxWidget = new QWidget(&window);
    QHBoxLayout *hboxLayout = new QHBoxLayout(hboxWidget);
    QPushButton *hbtn1 = new QPushButton("按钮 1", hboxWidget);
    QPushButton *hbtn2 = new QPushButton("按钮 2", hboxWidget);
    QPushButton *hbtn3 = new QPushButton("按钮 3", hboxWidget);
    hboxLayout->addWidget(hbtn1);
    hboxLayout->addWidget(hbtn2);
    hboxLayout->addWidget(hbtn3);
    mainLayout->addWidget(label2);
    mainLayout->addWidget(hboxWidget);

    // 3. QGridLayout 示例
    QLabel *label3 = new QLabel("QGridLayout（网格布局）示例：", &window);
    QWidget *gridWidget = new QWidget(&window);
    QGridLayout *gridLayout = new QGridLayout(gridWidget);
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            QPushButton *btn = new QPushButton(
                QString("%1,%2").arg(row + 1).arg(col + 1), gridWidget);
            gridLayout->addWidget(btn, row, col);
        }
    }
    mainLayout->addWidget(label3);
    mainLayout->addWidget(gridWidget);

    // 4. QFormLayout 示例
    QLabel *label4 = new QLabel("QFormLayout（表单布局）示例：", &window);
    QWidget *formWidget = new QWidget(&window);
    QFormLayout *formLayout = new QFormLayout(formWidget);
    QLineEdit *nameEdit = new QLineEdit(formWidget);
    QLineEdit *emailEdit = new QLineEdit(formWidget);
    QLineEdit *phoneEdit = new QLineEdit(formWidget);
    formLayout->addRow("姓名：", nameEdit);
    formLayout->addRow("邮箱：", emailEdit);
    formLayout->addRow("电话：", phoneEdit);
    mainLayout->addWidget(label4);
    mainLayout->addWidget(formWidget);

    mainLayout->addStretch();

    window.show();
    return app.exec();
}

