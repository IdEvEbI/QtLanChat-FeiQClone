#include <QtWidgets/QApplication>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QProgressDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtCore/QTimer>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("QProgressBar 和 QProgressDialog 示例");
    window.resize(400, 300);

    QVBoxLayout *layout = new QVBoxLayout(&window);

    // ========== QProgressBar 示例 ==========
    QLabel *progressBarLabel = new QLabel("QProgressBar 示例：", &window);
    QProgressBar *progressBar = new QProgressBar(&window);
    progressBar->setMinimum(0);
    progressBar->setMaximum(100);
    progressBar->setValue(0);
    progressBar->setFormat("%p%");  // 显示百分比

    QPushButton *progressBarButton = new QPushButton("开始进度", &window);

    // 创建定时器模拟进度
    QTimer *timer = new QTimer(&window);
    int progress = 0;

    QObject::connect(timer, &QTimer::timeout, [&progress, progressBar, timer]() {
        progress += 10;
        progressBar->setValue(progress);
        if (progress >= 100) {
            timer->stop();
        }
    });

    QObject::connect(progressBarButton, &QPushButton::clicked, [&progress, progressBar, timer]() {
        progress = 0;
        progressBar->setValue(0);
        timer->start(500);  // 每 500ms 更新一次
    });

    // ========== QProgressDialog 示例 ==========
    QLabel *progressDialogLabel = new QLabel("QProgressDialog 示例：", &window);
    QPushButton *progressDialogButton = new QPushButton("开始任务", &window);

    QObject::connect(progressDialogButton, &QPushButton::clicked, [&window]() {
        // 创建进度对话框
        QProgressDialog *dialog = new QProgressDialog("正在处理...", "取消", 0, 100, &window);
        dialog->setWindowTitle("进度");
        dialog->setModal(true);
        dialog->show();

        // 模拟进度
        QTimer *dialogTimer = new QTimer(&window);
        int dialogProgress = 0;

        QObject::connect(dialogTimer, &QTimer::timeout, [&dialogProgress, dialog, dialogTimer]() {
            dialogProgress += 10;
            dialog->setValue(dialogProgress);

            if (dialogProgress >= 100 || dialog->wasCanceled()) {
                dialogTimer->stop();
                dialog->close();
                delete dialog;
            }
        });

        dialogTimer->start(500);
    });

    // 添加到布局
    layout->addWidget(progressBarLabel);
    layout->addWidget(progressBar);
    layout->addWidget(progressBarButton);
    layout->addWidget(progressDialogLabel);
    layout->addWidget(progressDialogButton);

    window.show();
    return app.exec();
}

