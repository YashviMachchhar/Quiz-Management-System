#ifndef QUIZ_H
#define QUIZ_H
#include <string>
using namespace std;

class Quiz {
private:
    int quizId;
    string title;
public:
    Quiz();
    Quiz(int id, string t);
    ~Quiz();
    int getId() const;
    string getTitle() const;
    void display() const;
};
#endif
