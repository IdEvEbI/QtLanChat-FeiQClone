// student.h
#pragma once

#include <string>

class Student {
private:
    std::string name;
    std::string id;
    double score;

public:
    Student(const std::string& n, const std::string& i, double s);
    void printInfo() const;
    double getScore() const;
    std::string getName() const;
};
