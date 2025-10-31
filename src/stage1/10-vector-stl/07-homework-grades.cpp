#include <iostream>
#include <vector>

int main() {
    // 功能1：使用数组初始化方式创建初始成绩列表
    int arr[] = {85, 90, 78, 92, 88, 75, 95};
    std::vector<int> scores(arr, arr + 7);

    std::cout << "=== 学生成绩管理系统 ===" << std::endl;

    int choice;
    do {
        // 显示菜单
        std::cout << "\n当前成绩列表：";
        for (size_t i = 0; i < scores.size(); i++) {
            std::cout << scores[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "\n请选择操作：\n";
        std::cout << "1. 添加成绩（末尾）\n";
        std::cout << "2. 插入成绩（指定位置）\n";
        std::cout << "3. 删除指定成绩的所有出现\n";
        std::cout << "4. 删除所有不及格成绩\n";
        std::cout << "5. 显示统计信息\n";
        std::cout << "6. 显示所有成绩\n";
        std::cout << "0. 退出\n";
        std::cout << "\n请输入选择: ";
        std::cin >> choice;

        if (choice == 1) {
            // 功能2：动态添加成绩
            int score;
            std::cout << "请输入成绩: ";
            std::cin >> score;
            scores.push_back(score);
            std::cout << "已添加成绩: " << score << std::endl;

        } else if (choice == 2) {
            // 功能4：插入成绩
            int pos, score;
            std::cout << "请输入插入位置和成绩（如：2 99）: ";
            std::cin >> pos >> score;

            if (pos >= 0 && pos <= static_cast<int>(scores.size())) {
                scores.insert(scores.begin() + pos, score);
                std::cout << "已在位置 " << pos << " 插入成绩: " << score << std::endl;
            } else {
                std::cout << "位置非法！" << std::endl;
            }

        } else if (choice == 3) {
            // 功能5：删除指定成绩的所有出现
            int target;
            std::cout << "请输入要删除的成绩: ";
            std::cin >> target;

            int count = 0;
            for (auto it = scores.begin(); it != scores.end(); ) {
                if (*it == target) {
                    it = scores.erase(it);
                    count++;
                } else {
                    ++it;
                }
            }

            if (count > 0) {
                std::cout << "已删除 " << count << " 个成绩: " << target << std::endl;
            } else {
                std::cout << "未找到成绩: " << target << std::endl;
            }

        } else if (choice == 4) {
            // 功能5：删除所有不及格成绩（< 60）
            int count = 0;
            for (auto it = scores.begin(); it != scores.end(); ) {
                if (*it < 60) {
                    it = scores.erase(it);
                    count++;
                } else {
                    ++it;
                }
            }
            std::cout << "已删除 " << count << " 个不及格成绩" << std::endl;

        } else if (choice == 5) {
            // 功能3：显示统计信息
            if (scores.empty()) {
                std::cout << "成绩列表为空！" << std::endl;
                continue;
            }

            int sum = 0;
            int max = scores[0];
            int min = scores[0];

            for (size_t i = 0; i < scores.size(); i++) {
                sum += scores[i];
                if (scores[i] > max) max = scores[i];
                if (scores[i] < min) min = scores[i];
            }

            double average = static_cast<double>(sum) / scores.size();

            std::cout << "\n=== 统计信息 ===" << std::endl;
            std::cout << "平均分: " << average << std::endl;
            std::cout << "最高分: " << max << std::endl;
            std::cout << "最低分: " << min << std::endl;
            std::cout << "成绩数量: " << scores.size() << std::endl;

        } else if (choice == 6) {
            // 功能6：显示所有成绩
            std::cout << "\n=== 所有成绩 ===" << std::endl;
            if (scores.empty()) {
                std::cout << "成绩列表为空！" << std::endl;
            } else {
                for (size_t i = 0; i < scores.size(); i++) {
                    std::cout << "学生" << (i + 1) << ": " << scores[i] << "分" << std::endl;
                }
            }
        }

    } while (choice != 0);

    std::cout << "\n感谢使用！" << std::endl;
    return 0;
}

