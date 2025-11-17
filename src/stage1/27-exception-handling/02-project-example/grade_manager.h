#pragma once

#include <map>
#include <string>
#include "student.h"

class GradeManager {
public:
    void addStudent(const std::string& name, int score);
    int getScore(const std::string& name) const;
    void updateScore(const std::string& name, int score);
    void printAllStudents() const;

private:
    std::map<std::string, Student> students;
};

