#include "Question.h"
#include <iostream>
using namespace std;

Question::Question() : id(0), text(""), correctOption(1) {}
Question::Question(int i, string t, string a, string b, string c, string d, int correct)
    : id(i), text(t), correctOption(correct) {
    options[0] = a; options[1] = b; options[2] = c; options[3] = d;
}
Question::~Question() {}
int Question::getId() const { return id; }
string Question::getText() const { return text; }
string Question::getOption(int index) const {
    if (index < 0 || index > 3) return "";
    return options[index];
}
int Question::getCorrectOption() const { return correctOption; }
void Question::setText(string t) { text = t; }
void Question::display() const {
    cout << "\nID: " << id << "\n" << text << "\n";
    for (int i = 0; i < 4; i++) cout << i + 1 << ". " << options[i] << "\n";
}
