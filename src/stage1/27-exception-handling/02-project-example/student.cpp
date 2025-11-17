#include "student.h"
#include <stdexcept>

Student::Student(const std::string& name, int score)
    : name(name), score(score) {
    if (score < 0 || score > 100) {
        throw std::invalid_argument("成绩必须在 0-100 之间");
    }
}

std::string Student::getName() const {
    return name;
}

int Student::getScore() const {
    return score;
}

void Student::setScore(int score) {
    if (score < 0 || score > 100) {
        throw std::invalid_argument("成绩必须在 0-100 之间");
    }
    this->score = score;
}

