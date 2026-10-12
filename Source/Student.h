#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
#include <string>
using namespace std;

class Student : public Person {
private:
    int studentId;
public:
    Student();
    Student(int id, string n);
    ~Student();
    int getId() const;
    string getName() const;
    void display() const override;
};
#endif
