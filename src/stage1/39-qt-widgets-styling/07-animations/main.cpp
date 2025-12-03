#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtCore/QPropertyAnimation>
#include <QtCore/QAbstractAnimation>
#include <QtCore/QEasingCurve>
#include <QtCore/QParallelAnimationGroup>
#include <QtCore/QEvent>
#include <QtCore/QLoggingCategory>
#include <QtGui/QColor>
#include <QtGui/QEnterEvent>

class AnimatedButton : public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(QColor backgroundColor READ backgroundColor WRITE setBackgroundColor)

public:
    explicit AnimatedButton(const QString &text, QWidget *parent = nullptr)
        : QPushButton(text, parent)
        , m_backgroundColor(QColor("#4CAF50"))
    {
        updateStyle();
    }

    QColor backgroundColor() const { return m_backgroundColor; }
    void setBackgroundColor(const QColor &color)
    {
        m_backgroundColor = color;
        updateStyle();
    }

protected:
    void enterEvent(QEnterEvent *event) override
    {
        QPushButton::enterEvent(event);
        emit mouseEntered();
    }

    void leaveEvent(QEvent *event) override
    {
        QPushButton::leaveEvent(event);
        emit mouseLeft();
    }

signals:
    void mouseEntered();
    void mouseLeft();

private:
    void updateStyle()
    {
        setStyleSheet(QString(
            "QPushButton {"
            "    background-color: %1;"
            "    color: white;"
            "    border-radius: 5px;"
            "    border: none;"
            "    padding: 10px;"
            "}"
        ).arg(m_backgroundColor.name()));
    }

    QColor m_backgroundColor;
};

#include "main.moc"

int main(int argc, char *argv[])
{
    // 抑制 macOS 上的 IMK 相关警告消息
    QLoggingCategory::setFilterRules("qt.qpa.input*.debug=false");

    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("动画效果示例");
    window.resize(500, 400);
    window.setStyleSheet("background-color: #F5F5F5;");

    QVBoxLayout *layout = new QVBoxLayout(&window);

    // 示例 1: QPropertyAnimation 基础
    QPushButton *button1 = new QPushButton("点击我（位置动画）", &window);
    button1->setGeometry(50, 50, 150, 40);
    button1->setStyleSheet(
        "QPushButton {"
        "    background-color: #4CAF50;"
        "    color: white;"
        "    border-radius: 5px;"
        "    border: none;"
        "}"
    );

    QPropertyAnimation *animation1 = new QPropertyAnimation(button1, "geometry", &window);
    animation1->setDuration(1000);
    animation1->setStartValue(QRect(50, 50, 150, 40));
    animation1->setEndValue(QRect(300, 50, 150, 40));
    animation1->setEasingCurve(QEasingCurve::InOutQuad);

    QObject::connect(button1, &QPushButton::clicked, [animation1]() {
        if (animation1->state() == QAbstractAnimation::Running) {
            animation1->stop();
        }
        animation1->start();
    });

    // 示例 2: 并行动画组
    QPushButton *button2 = new QPushButton("按钮 2", &window);
    button2->setGeometry(50, 120, 100, 40);
    button2->setStyleSheet(
        "QPushButton {"
        "    background-color: #2196F3;"
        "    color: white;"
        "    border-radius: 5px;"
        "    border: none;"
        "}"
    );

    QPushButton *button3 = new QPushButton("按钮 3", &window);
    button3->setGeometry(50, 180, 100, 40);
    button3->setStyleSheet(
        "QPushButton {"
        "    background-color: #FF9800;"
        "    color: white;"
        "    border-radius: 5px;"
        "    border: none;"
        "}"
    );

    QParallelAnimationGroup *parallelGroup = new QParallelAnimationGroup(&window);

    QPropertyAnimation *anim2 = new QPropertyAnimation(button2, "geometry", &window);
    anim2->setDuration(1000);
    anim2->setStartValue(QRect(50, 120, 100, 40));
    anim2->setEndValue(QRect(350, 120, 100, 40));
    anim2->setEasingCurve(QEasingCurve::InOutQuad);

    QPropertyAnimation *anim3 = new QPropertyAnimation(button3, "geometry", &window);
    anim3->setDuration(1000);
    anim3->setStartValue(QRect(50, 180, 100, 40));
    anim3->setEndValue(QRect(350, 180, 100, 40));
    anim3->setEasingCurve(QEasingCurve::InOutQuad);

    parallelGroup->addAnimation(anim2);
    parallelGroup->addAnimation(anim3);

    QObject::connect(button2, &QPushButton::clicked, [parallelGroup]() {
        parallelGroup->start();
    });

    // 示例 3: 过渡动画（颜色）
    AnimatedButton *button4 = new AnimatedButton("悬停我（颜色动画）", &window);
    button4->setGeometry(50, 250, 150, 40);

    QPropertyAnimation *colorAnimation = new QPropertyAnimation(button4, "backgroundColor", &window);
    colorAnimation->setDuration(300);
    colorAnimation->setStartValue(QColor("#4CAF50"));
    colorAnimation->setEndValue(QColor("#66BB6A"));

    QPropertyAnimation *colorAnimationBack = new QPropertyAnimation(button4, "backgroundColor", &window);
    colorAnimationBack->setDuration(300);
    colorAnimationBack->setStartValue(QColor("#66BB6A"));
    colorAnimationBack->setEndValue(QColor("#4CAF50"));

    QObject::connect(button4, &AnimatedButton::mouseEntered, [colorAnimation]() {
        colorAnimation->start();
    });

    QObject::connect(button4, &AnimatedButton::mouseLeft, [colorAnimationBack]() {
        colorAnimationBack->start();
    });

    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button3);
    layout->addWidget(button4);

    window.show();
    return app.exec();
}

