#include <QtCore/QDebug>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  QMainWindow mainWindow;
  mainWindow.setWindowTitle("模态与非模态对话框对比");
  mainWindow.resize(400, 300);

  QWidget *centralWidget = new QWidget(&mainWindow);
  mainWindow.setCentralWidget(centralWidget);

  QVBoxLayout *layout = new QVBoxLayout(centralWidget);

  // 模态对话框按钮
  QPushButton *modalButton = new QPushButton("打开模态对话框", centralWidget);
  QObject::connect(modalButton, &QPushButton::clicked, []() {
    QDialog dialog;
    dialog.setWindowTitle("模态对话框");
    dialog.setModal(true);
    dialog.resize(300, 200);

    QVBoxLayout *dialogLayout = new QVBoxLayout(&dialog);
    QLabel *label =
        new QLabel("这是一个模态对话框\n必须处理完才能继续", &dialog);
    QPushButton *okButton = new QPushButton("确定", &dialog);

    QObject::connect(okButton, &QPushButton::clicked, &dialog,
                     &QDialog::accept);

    dialogLayout->addWidget(label);
    dialogLayout->addWidget(okButton);

    int result = dialog.exec();
    qDebug() << "模态对话框返回值：" << result;
  });

  // 非模态对话框按钮
  QPushButton *modelessButton =
      new QPushButton("打开非模态对话框", centralWidget);
  QObject::connect(modelessButton, &QPushButton::clicked, [&mainWindow]() {
    QDialog *dialog = new QDialog(&mainWindow);
    dialog->setWindowTitle("非模态对话框");
    dialog->setModal(false);
    dialog->resize(300, 200);

    QVBoxLayout *dialogLayout = new QVBoxLayout(dialog);
    QLabel *label =
        new QLabel("这是一个非模态对话框\n可以同时操作主窗口", dialog);
    QPushButton *closeButton = new QPushButton("关闭", dialog);

    QObject::connect(closeButton, &QPushButton::clicked, dialog,
                     &QDialog::close);

    dialogLayout->addWidget(label);
    dialogLayout->addWidget(closeButton);

    dialog->show();
    qDebug() << "非模态对话框已显示，主窗口仍然可以操作";
  });

  layout->addWidget(modalButton);
  layout->addWidget(modelessButton);

  mainWindow.show();
  return app.exec();
}
