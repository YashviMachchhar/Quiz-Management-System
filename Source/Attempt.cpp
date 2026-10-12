#include "Attempt.h"
#include <iostream>
using namespace std;
Attempt::Attempt() : studentId(0), score(0), total(0) {}
Attempt::Attempt(int id, int s, int t) : studentId(id), score(s), total(t) {}
Attempt::~Attempt() {}
int Attempt::getStudentId() const { return studentId; }
int Attempt::getScore() const { return score; }
int Attempt::getTotal() const { return total; }
void Attempt::display() const {
    cout << "Student ID: " << studentId << " | Score: " << score << "/" << total << endl;
}
