#pragma once

#include <string>

class Student {
public:
    Student(const std::string& name, int score);

    std::string getName() const;
    int getScore() const;
    void setScore(int score);

private:
    std::string name;
    int score;
};

