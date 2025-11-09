#include <iostream>
#include <string>

enum Priority {
    Low,
    Medium,
    High
};

struct Task {
    std::string name;
    Priority priority;
};

void printTask(const Task& task) {
    std::cout << "任务: " << task.name << std::endl;
    std::cout << "优先级: ";

    switch (task.priority) {
        case Priority::Low:
            std::cout << "低" << std::endl;
            break;
        case Priority::Medium:
            std::cout << "中" << std::endl;
            break;
        case Priority::High:
            std::cout << "高" << std::endl;
            break;
    }
}

int main() {
    Task task1 = {"完成报告", Priority::High};
    Task task2 = {"回复邮件", Priority::Medium};

    printTask(task1);
    printTask(task2);

    return 0;
}
