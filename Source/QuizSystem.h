#ifndef QUIZSYSTEM_H
#define QUIZSYSTEM_H
#include "Question.h"
#include "Attempt.h"
#include "Quiz.h"
#include "Student.h"

class QuizSystem {
private:
    Question* questions;
    Attempt* attempts;
    int questionCount;
    int attemptCount;
    int capacity;
    Quiz quiz;
    void clearInput();
    int findQuestionIndex(int id) const;
    void addQuestion();
    void displayQuestions() const;
    void searchQuestion();
    void updateQuestion();
    void deleteQuestion();
    void takeQuiz();
    void showReport() const;
public:
    QuizSystem();
    ~QuizSystem();
    void loadData();
    void saveData() const;
    void run();
};
#endif
