#include "StudentManagementWindow.h"
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtCore/QDebug>

StudentManagementWindow::StudentManagementWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("学生管理系统");
    resize(800, 600);

    // 创建中央控件
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // 创建主布局
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);

    // 左侧：学生列表
    QWidget *leftWidget = new QWidget(centralWidget);
    QVBoxLayout *leftLayout = new QVBoxLayout(leftWidget);

    QLabel *listLabel = new QLabel("学生列表", leftWidget);
    m_studentList = new QListWidget(leftWidget);

    leftLayout->addWidget(listLabel);
    leftLayout->addWidget(m_studentList);

    // 右侧：学生信息表格
    QWidget *rightWidget = new QWidget(centralWidget);
    QVBoxLayout *rightLayout = new QVBoxLayout(rightWidget);

    QLabel *tableLabel = new QLabel("学生信息", rightWidget);
    m_studentTable = new QTableWidget(rightWidget);
    m_studentTable->setColumnCount(3);
    m_studentTable->setHorizontalHeaderLabels(QStringList() << "姓名" << "年龄" << "成绩");
    // QAbstractItemView 是所有视图控件的基类，提供了选择行为等通用功能
    m_studentTable->setSelectionBehavior(QAbstractItemView::SelectRows);

    // 输入区域
    QWidget *inputWidget = new QWidget(rightWidget);
    QHBoxLayout *inputLayout = new QHBoxLayout(inputWidget);

    m_nameEdit = new QLineEdit(inputWidget);
    m_nameEdit->setPlaceholderText("姓名");
    m_ageEdit = new QLineEdit(inputWidget);
    m_ageEdit->setPlaceholderText("年龄");
    m_scoreEdit = new QLineEdit(inputWidget);
    m_scoreEdit->setPlaceholderText("成绩");

    QPushButton *addButton = new QPushButton("添加", inputWidget);
    QPushButton *deleteButton = new QPushButton("删除", inputWidget);

    inputLayout->addWidget(m_nameEdit);
    inputLayout->addWidget(m_ageEdit);
    inputLayout->addWidget(m_scoreEdit);
    inputLayout->addWidget(addButton);
    inputLayout->addWidget(deleteButton);

    // 进度条
    QLabel *progressLabel = new QLabel("数据加载进度", rightWidget);
    m_progressBar = new QProgressBar(rightWidget);
    m_progressBar->setMinimum(0);
    m_progressBar->setMaximum(100);
    m_progressBar->setValue(0);

    rightLayout->addWidget(tableLabel);
    rightLayout->addWidget(m_studentTable);
    rightLayout->addWidget(inputWidget);
    rightLayout->addWidget(progressLabel);
    rightLayout->addWidget(m_progressBar);

    // 添加到主布局
    mainLayout->addWidget(leftWidget, 1);
    mainLayout->addWidget(rightWidget, 2);

    // 连接信号槽
    connect(addButton, &QPushButton::clicked, this, &StudentManagementWindow::addStudent);
    connect(deleteButton, &QPushButton::clicked, this, &StudentManagementWindow::deleteStudent);
    connect(m_studentTable, &QTableWidget::itemSelectionChanged, this, &StudentManagementWindow::updateListSelection);
    connect(m_studentList, &QListWidget::itemClicked, this, &StudentManagementWindow::selectStudent);

    // 初始化数据
    addSampleData();
}

void StudentManagementWindow::addStudent()
{
    QString name = m_nameEdit->text();
    QString age = m_ageEdit->text();
    QString score = m_scoreEdit->text();

    if (name.isEmpty() || age.isEmpty() || score.isEmpty()) {
        qDebug() << "请填写完整信息";
        return;
    }

    // 添加到表格
    int row = m_studentTable->rowCount();
    m_studentTable->insertRow(row);
    m_studentTable->setItem(row, 0, new QTableWidgetItem(name));
    m_studentTable->setItem(row, 1, new QTableWidgetItem(age));
    m_studentTable->setItem(row, 2, new QTableWidgetItem(score));

    // 添加到列表
    m_studentList->addItem(name);

    // 清空输入框
    m_nameEdit->clear();
    m_ageEdit->clear();
    m_scoreEdit->clear();

    // 更新进度条
    int progress = (m_studentTable->rowCount() * 100) / 10;  // 假设最多 10 个学生
    m_progressBar->setValue(qMin(progress, 100));
}

void StudentManagementWindow::deleteStudent()
{
    int currentRow = m_studentTable->currentRow();
    if (currentRow >= 0) {
        m_studentTable->removeRow(currentRow);
        QListWidgetItem *item = m_studentList->takeItem(currentRow);
        delete item;
    }
}

void StudentManagementWindow::updateListSelection()
{
    int currentRow = m_studentTable->currentRow();
    if (currentRow >= 0) {
        m_studentList->setCurrentRow(currentRow);
    }
}

void StudentManagementWindow::selectStudent(QListWidgetItem *item)
{
    int row = m_studentList->row(item);
    m_studentTable->selectRow(row);
}

void StudentManagementWindow::addSampleData()
{
    // 添加示例数据
    QStringList names = {"张三", "李四", "王五"};
    QStringList ages = {"20", "21", "22"};
    QStringList scores = {"85", "90", "88"};

    for (int i = 0; i < names.size(); ++i) {
        int row = m_studentTable->rowCount();
        m_studentTable->insertRow(row);
        m_studentTable->setItem(row, 0, new QTableWidgetItem(names[i]));
        m_studentTable->setItem(row, 1, new QTableWidgetItem(ages[i]));
        m_studentTable->setItem(row, 2, new QTableWidgetItem(scores[i]));
        m_studentList->addItem(names[i]);
    }
}

