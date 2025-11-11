#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <string>
#using namespace std;

class Student : public Person {
private:
    int yearLevel;
    string major;
public:
    Student(string n, int i, int y, string m);
    Student();
    void display();
    string getName();
    int getID();
    ~Student();
};

#endif
