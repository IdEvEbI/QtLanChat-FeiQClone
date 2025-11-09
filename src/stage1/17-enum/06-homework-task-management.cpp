#include <iostream>
#include <string>
#include <vector>

enum Priority {
    Low,
    Medium,
    High
};

enum TaskStatus {
    Todo,
    InProgress,
    Completed
};

struct Task {
    std::string name;
    Priority priority;
    TaskStatus status;
};

void printTask(const Task& task) {
    std::cout << "任务: " << task.name << std::endl;
    std::cout << "优先级: ";

    switch (task.priority) {
        case Priority::Low:
            std::cout << "低";
            break;
        case Priority::Medium:
            std::cout << "中";
            break;
        case Priority::High:
            std::cout << "高";
            break;
    }

    std::cout << " | 状态: ";

    switch (task.status) {
        case TaskStatus::Todo:
            std::cout << "待办";
            break;
        case TaskStatus::InProgress:
            std::cout << "进行中";
            break;
        case TaskStatus::Completed:
            std::cout << "已完成";
            break;
    }

    std::cout << std::endl;
}

void printAllTasks(const std::vector<Task>& tasks) {
    std::cout << "=== 任务列表 ===" << std::endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        std::cout << (i + 1) << ". ";
        printTask(tasks[i]);
    }
}

void updateTaskStatus(Task& task, TaskStatus newStatus) {
    task.status = newStatus;
    std::cout << "任务状态已更新" << std::endl;
}

int main() {
    std::vector<Task> tasks;

    // 添加任务
    tasks.push_back({"完成报告", Priority::High, TaskStatus::Todo});
    tasks.push_back({"回复邮件", Priority::Medium, TaskStatus::InProgress});
    tasks.push_back({"准备会议", Priority::Low, TaskStatus::Completed});

    // 显示所有任务
    printAllTasks(tasks);

    // 更新任务状态
    std::cout << "\n=== 更新任务状态 ===" << std::endl;
    updateTaskStatus(tasks[0], TaskStatus::InProgress);
    printTask(tasks[0]);

    return 0;
}
