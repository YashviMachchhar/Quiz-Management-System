#include "QuizSystem.h"
#include "FileManager.h"
#include <iostream>
#include <limits>
#include <stdexcept>
using namespace std;

QuizSystem::QuizSystem() : questionCount(0), attemptCount(0), capacity(100), quiz(1, "General Knowledge") {
    questions = new Question[capacity];
    attempts = new Attempt[capacity];
}
QuizSystem::~QuizSystem() {
    delete[] questions;
    delete[] attempts;
}
void QuizSystem::clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
int QuizSystem::findQuestionIndex(int id) const {
    for (int i = 0; i < questionCount; i++)
        if (questions[i].getId() == id) return i;
    return -1;
}
void QuizSystem::loadData() {
    questionCount = FileManager::loadQuestions(questions, capacity, "Data/questions.txt");
    attemptCount = FileManager::loadAttempts(attempts, capacity, "Data/attempts.txt");
}
void QuizSystem::saveData() const {
    FileManager::saveQuestions(questions, questionCount, "Data/questions.txt");
    FileManager::saveAttempts(attempts, attemptCount, "Data/attempts.txt");
}
void QuizSystem::addQuestion() {
    if (questionCount >= capacity) { cout << "Question storage is full.\n"; return; }
    int id, correct;
    string text, a, b, c, d;
    cout << "Enter question ID: "; cin >> id; clearInput();
    if (findQuestionIndex(id) != -1) { cout << "ID already exists.\n"; return; }
    cout << "Enter question: "; getline(cin, text);
    cout << "Option 1: "; getline(cin, a);
    cout << "Option 2: "; getline(cin, b);
    cout << "Option 3: "; getline(cin, c);
    cout << "Option 4: "; getline(cin, d);
    cout << "Correct option (1-4): "; cin >> correct; clearInput();
    if (correct < 1 || correct > 4 || text.empty()) {
        cout << "Invalid question or answer. Record not added.\n"; return;
    }
    questions[questionCount++] = Question(id, text, a, b, c, d, correct);
    cout << "Question added.\n";
}
void QuizSystem::displayQuestions() const {
    if (!questionCount) { cout << "No questions available.\n"; return; }
    for (int i = 0; i < questionCount; i++) questions[i].display();
}
void QuizSystem::searchQuestion() {
    int id; cout << "Enter question ID: "; cin >> id; clearInput();
    int index = findQuestionIndex(id);
    if (index == -1) cout << "Question not found.\n";
    else questions[index].display();
}
void QuizSystem::updateQuestion() {
    int id; string text;
    cout << "Enter question ID to update: "; cin >> id; clearInput();
    int index = findQuestionIndex(id);
    if (index == -1) { cout << "Question not found.\n"; return; }
    cout << "Enter new question text: "; getline(cin, text);
    if (text.empty()) { cout << "Text cannot be empty.\n"; return; }
    questions[index].setText(text);
    cout << "Question updated. Options and correct answer remain unchanged.\n";
}
void QuizSystem::deleteQuestion() {
    int id; cout << "Enter question ID to delete: "; cin >> id; clearInput();
    int index = findQuestionIndex(id);
    if (index == -1) { cout << "Question not found.\n"; return; }
    for (int i = index; i < questionCount - 1; i++) questions[i] = questions[i + 1];
    questionCount--;
    cout << "Question deleted.\n";
}
void QuizSystem::takeQuiz() {
    if (!questionCount) { cout << "Add questions before taking the quiz.\n"; return; }
    int studentId, score = 0;
    string name;
    cout << "Enter student ID: "; cin >> studentId; clearInput();
    cout << "Enter student name: "; getline(cin, name);
    Student student(studentId, name);
    cout << "\nStarting "; quiz.display();
    for (int i = 0; i < questionCount; i++) {
        questions[i].display();
        int answer;
        cout << "Your answer (1-4): "; cin >> answer; clearInput();
        if (answer == questions[i].getCorrectOption()) score++;
    }
    if (attemptCount < capacity) {
        attempts[attemptCount++] = Attempt(student.getId(), score, questionCount);
    }
    cout << "Quiz completed. Score: " << score << "/" << questionCount << "\n";
}
void QuizSystem::showReport() const {
    cout << "\n--- Quiz Report ---\n";
    cout << "Total questions: " << questionCount << "\n";
    cout << "Total attempts: " << attemptCount << "\n";
    for (int i = 0; i < attemptCount; i++) attempts[i].display();
}
void QuizSystem::run() {
    int choice = 0;
    do {
        cout << "\n===== QUIZ MANAGEMENT SYSTEM =====\n"
             << "1. Add Record (Question)\n2. Display Records\n3. Search Record\n"
             << "4. Update Record\n5. Delete Record\n6. Take Quiz\n"
             << "7. Report\n8. Save/Load Data\n9. Exit\nChoice: ";
        if (!(cin >> choice)) { clearInput(); cout << "Enter a number from 1 to 9.\n"; continue; }
        clearInput();
        try {
            switch (choice) {
                case 1: addQuestion(); break;
                case 2: displayQuestions(); break;
                case 3: searchQuestion(); break;
                case 4: updateQuestion(); break;
                case 5: deleteQuestion(); break;
                case 6: takeQuiz(); break;
                case 7: showReport(); break;
                case 8:
                    saveData();
                    loadData();
                    cout << "Data saved and loaded successfully.\n";
                    break;
                case 9:
                    saveData();
                    cout << "Data saved. Goodbye!\n";
                    break;
                default: cout << "Invalid choice. Select 1-9.\n";
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << "\n";
        }
    } while (choice != 9);
}
