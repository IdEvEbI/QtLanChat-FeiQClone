#ifndef CALCULATORWINDOW_H
#define CALCULATORWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QButtonGroup>

class CalculatorWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CalculatorWindow(QWidget *parent = nullptr);

private slots:
    void calculate();

private:
    QLineEdit *m_num1Edit;
    QLineEdit *m_num2Edit;
    QButtonGroup *m_buttonGroup;
    QLabel *m_resultLabel;
};

#endif // CALCULATORWINDOW_H

