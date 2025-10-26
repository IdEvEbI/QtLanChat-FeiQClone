#include <iostream>

int main() {
    std::cout << "=== 成绩判断系统 ===" << std::endl;
    
    int chinese = 85;
    int math = 90;
    int english = 88;
    
    // 计算平均分
    int total = chinese + math + english;
    int average = total / 3;
    
    // 判断及格和优秀
    bool isPass = (average >= 60);
    bool isExcellent = (average >= 90);
    
    // 输出结果
    std::cout << "语文: " << chinese << " 分" << std::endl;
    std::cout << "数学: " << math << " 分" << std::endl;
    std::cout << "英语: " << english << " 分" << std::endl;
    std::cout << "平均分: " << average << " 分" << std::endl;
    std::cout << "是否及格: " << isPass << std::endl;
    std::cout << "是否优秀: " << isExcellent << std::endl;
    
    return 0;
}

