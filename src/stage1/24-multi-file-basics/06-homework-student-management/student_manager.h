// student_manager.h
#pragma once

#include "student.h"
#include <vector>

class StudentManager {
private:
    std::vector<Student> students;

public:
    void addStudent(const Student& student);
    void displayAll() const;
    double getAverageScore() const;
};
