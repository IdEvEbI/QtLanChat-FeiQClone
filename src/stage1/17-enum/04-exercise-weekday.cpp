#include <iostream>

enum Weekday {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

void checkWeekday(Weekday day) {
    switch (day) {
        case Weekday::Monday:
        case Weekday::Tuesday:
        case Weekday::Wednesday:
        case Weekday::Thursday:
        case Weekday::Friday:
            std::cout << "工作日" << std::endl;
            break;
        case Weekday::Saturday:
        case Weekday::Sunday:
            std::cout << "周末" << std::endl;
            break;
    }
}

int main() {
    checkWeekday(Weekday::Monday);   // 输出: 工作日
    checkWeekday(Weekday::Saturday); // 输出: 周末

    return 0;
}
