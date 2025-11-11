#ifndef COURSE_H
#define COURSE_H

#include "Student.h"

using namespace std;

class Course {
private:
    string courseCode;
    string courseName;
    int maxStudents;
    Student* students;
    int currentStudents;
public:
    Course(string code, string name, int max);
    Course();
    void addStudent(const Student& s);
    void displayCourseInfo();
    ~Course();
};

#endif
