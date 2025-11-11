#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
protected:
    string name;
    int id;
public:
    Person(string n, int i);
    Person();
    void display();
    ~Person();
};

#endif
