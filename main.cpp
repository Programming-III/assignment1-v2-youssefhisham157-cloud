#include <iostream>
#include <string>
#include "Person.h"
#include "Student.h"
#include "Instructor.h"
#include "Course.h"


using namespace std;

class Person {
protected:
    string name;
    int id;
public:
    Person(string n, int i){
        name = n;
        id = i;
    }
    Person(){
        name ="";
        id = 0;
    }
    void display() {
        cout << "\n\nName: " << name << "\n\nID: " << id << endl;
    }
    ~Person(){}
};

class Student : public Person {
private:
int yearLevel;
string major;
public:
    Student(string n, int i, int y, string m) : Person(n, i){
        yearLevel = y;
        major = m;
    }
    Student():Person(){
        name = "";
        id = 0;
        major = "";
        yearLevel = 0;
    }
    void display() {
        cout<<"\nStudent Info: ";
        Person::display();
        cout << "\nYear: " << yearLevel << "\n\nMajor: " << major << endl;
    }
    string getName() {
        return name;
    }
    int getID(){
        return id;
    }
    ~Student(){}
};

class Instructor : public Person {
    private:
    string department;
    int experienceYears;
    public:
    Instructor(string n, int i, string d, int e) : Person(n,i){
        department = d;
        experienceYears = e;
    }
    void display() {
        cout<<"\nInstructor Info: ";
        Person::display();
        cout << "\nDepartment: " << department << "\n\nExperience: " << experienceYears << " Years\n";
    }
    ~Instructor() {}
};

class Course{
    private:
    string courseCode;
    string courseName;
    int maxStudents;
    Student* students;
    int currentStudents;
    public:
    
    Course(string code, string name, int max) {
        courseCode = code;
        courseName = name;
        maxStudents = max;
        students = new Student[max];
        currentStudents = 0;
    }

    Course(){
        courseCode = "";
        courseName = "";
        maxStudents = 0;
        currentStudents = 0;
    }

    void addStudent(const Student& s) {
        if (currentStudents < maxStudents) {
            students[currentStudents++] = s;
        } else {
            cout << "Cannot add more students, course is full." << endl;
        }
    }

    void displayCourseInfo(){
        cout<<"\nCourse: " << courseName << "\n\nMax Students: " << maxStudents << endl;
        for(int i =0; i < currentStudents; i++){
            cout << endl << students[i].getName() <<"(ID:" << students[i].getID() << ")\n";
        }
    }
    ~Course(){
        delete[] students;
    }
};



int main() {
    Student* s = new Student("Omar Nabil", 2202, 2, "Informatics");
    Instructor* i = new Instructor("Dr. Lina Khaled", 1023, "Computer Science", 5);
    Course* c = new Course("cs", "CS101 - Introduction to Programming", 3);
    c->addStudent(*s);
    c->displayCourseInfo();
    i->display();
    s->display();


    return 0;
}


