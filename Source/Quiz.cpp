#include "Quiz.h"
#include <iostream>
using namespace std;
Quiz::Quiz() : quizId(1), title("General Knowledge") {}
Quiz::Quiz(int id, string t) : quizId(id), title(t) {}
Quiz::~Quiz() {}
int Quiz::getId() const { return quizId; }
string Quiz::getTitle() const { return title; }
void Quiz::display() const { cout << "Quiz " << quizId << ": " << title << endl; }
