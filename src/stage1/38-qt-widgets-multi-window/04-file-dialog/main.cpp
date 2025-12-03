#include <QtCore/QDebug>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  QWidget window;
  window.setWindowTitle("QFileDialog 示例");
  window.resize(400, 300);

  QVBoxLayout *layout = new QVBoxLayout(&window);

  // 打开单个文件
  QPushButton *openFileButton = new QPushButton("打开文件", &window);
  QObject::connect(openFileButton, &QPushButton::clicked, []() {
    QString fileName = QFileDialog::getOpenFileName(
        nullptr, "打开文件", "", "文本文件 (*.txt);;所有文件 (*.*)");
    if (!fileName.isEmpty()) {
      qDebug() << "选择的文件：" << fileName;
    }
  });

  // 打开多个文件
  QPushButton *openFilesButton = new QPushButton("打开多个文件", &window);
  QObject::connect(openFilesButton, &QPushButton::clicked, []() {
    QStringList fileNames = QFileDialog::getOpenFileNames(
        nullptr, "打开文件", "", "文本文件 (*.txt);;所有文件 (*.*)");
    if (!fileNames.isEmpty()) {
      qDebug() << "选择的文件：";
      for (const QString &fileName : fileNames) {
        qDebug() << "  -" << fileName;
      }
    }
  });

  // 保存文件
  QPushButton *saveFileButton = new QPushButton("保存文件", &window);
  QObject::connect(saveFileButton, &QPushButton::clicked, []() {
    QString fileName = QFileDialog::getSaveFileName(
        nullptr, "保存文件", "", "文本文件 (*.txt);;所有文件 (*.*)");
    if (!fileName.isEmpty()) {
      qDebug() << "保存的文件：" << fileName;
    }
  });

  // 选择目录
  QPushButton *selectDirButton = new QPushButton("选择目录", &window);
  QObject::connect(selectDirButton, &QPushButton::clicked, []() {
    QString dirName =
        QFileDialog::getExistingDirectory(nullptr, "选择目录", "");
    if (!dirName.isEmpty()) {
      qDebug() << "选择的目录：" << dirName;
    }
  });

  layout->addWidget(openFileButton);
  layout->addWidget(openFilesButton);
  layout->addWidget(saveFileButton);
  layout->addWidget(selectDirButton);

  window.show();
  return app.exec();
}
