#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
private:
    string name;
    int id;
public:
    Person(string n, int i);
    Person();
    void display();
    string getName();
    int getID();
    ~Person();
};

#endif
