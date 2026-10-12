#ifndef QUESTION_H
#define QUESTION_H
#include <string>
using namespace std;

class Question {
private:
    int id;
    string text;
    string options[4];
    int correctOption;
public:
    Question();
    Question(int i, string t, string a, string b, string c, string d, int correct);
    ~Question();
    int getId() const;
    string getText() const;
    string getOption(int index) const;
    int getCorrectOption() const;
    void setText(string t);
    void display() const;
};
#endif
