#include <iostream>

int main() {
    int score;
    std::cout << "请输入成绩（0-100）: ";
    std::cin >> score;

    char grade;
    
    // 将分数转换为等级
    switch (score / 10) {
        case 10:
        case 9:
            grade = 'A';
            break;
        case 8:
            grade = 'B';
            break;
        case 7:
            grade = 'C';
            break;
        case 6:
            grade = 'D';
            break;
        default:
            grade = 'E';
            break;
    }

    std::cout << "等级: " << grade << std::endl;

    return 0;
}

