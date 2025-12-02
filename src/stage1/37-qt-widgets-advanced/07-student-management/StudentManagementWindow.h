#ifndef STUDENTMANAGEMENTWINDOW_H
#define STUDENTMANAGEMENTWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>

class StudentManagementWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentManagementWindow(QWidget *parent = nullptr);

private slots:
    void addStudent();
    void deleteStudent();
    void updateListSelection();
    void selectStudent(QListWidgetItem *item);

private:
    void addSampleData();

    QListWidget *m_studentList;
    QTableWidget *m_studentTable;
    QLineEdit *m_nameEdit;
    QLineEdit *m_ageEdit;
    QLineEdit *m_scoreEdit;
    QProgressBar *m_progressBar;
};

#endif // STUDENTMANAGEMENTWINDOW_H

