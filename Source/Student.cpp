#include "Student.h"
#include <iostream>
using namespace std;
Student::Student() : Person(), studentId(0) {}
Student::Student(int id, string n) : Person(n), studentId(id) {}
Student::~Student() {}
int Student::getId() const { return studentId; }
string Student::getName() const { return name; }
void Student::display() const {
    cout << "Student ID: " << studentId << ", Name: " << name << endl;
}
