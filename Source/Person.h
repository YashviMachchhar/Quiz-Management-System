#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

class Person {
protected:
    string name;
public:
    Person();
    Person(string n);
    virtual ~Person();
    virtual void display() const = 0;
};
#endif
