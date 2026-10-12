#include "FileManager.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

void FileManager::saveQuestions(const Question q[], int count, const string& filename) {
    ofstream out(filename.c_str());
    if (!out) throw runtime_error("Could not open question file for saving.");
    for (int i = 0; i < count; i++) {
        out << q[i].getId() << "|" << q[i].getText();
        for (int j = 0; j < 4; j++) out << "|" << q[i].getOption(j);
        out << "|" << q[i].getCorrectOption() << "\n";
    }
}
int FileManager::loadQuestions(Question q[], int capacity, const string& filename) {
    ifstream in(filename.c_str());
    if (!in) return 0;
    string line;
    int count = 0;
    while (count < capacity && getline(in, line)) {
        string fields[7];
        stringstream ss(line);
        int k = 0;
        while (k < 7 && getline(ss, fields[k], '|')) k++;
        if (k == 7) {
            try {
                q[count++] = Question(stoi(fields[0]), fields[1], fields[2], fields[3],
                                      fields[4], fields[5], stoi(fields[6]));
            } catch (...) { /* skip malformed line */ }
        }
    }
    return count;
}
void FileManager::saveAttempts(const Attempt a[], int count, const string& filename) {
    ofstream out(filename.c_str());
    if (!out) throw runtime_error("Could not open attempt file for saving.");
    for (int i = 0; i < count; i++)
        out << a[i].getStudentId() << "|" << a[i].getScore() << "|" << a[i].getTotal() << "\n";
}
int FileManager::loadAttempts(Attempt a[], int capacity, const string& filename) {
    ifstream in(filename.c_str());
    if (!in) return 0;
    int id, score, total, count = 0;
    char bar1, bar2;
    while (count < capacity && in >> id >> bar1 >> score >> bar2 >> total) {
        if (bar1 == '|' && bar2 == '|') a[count++] = Attempt(id, score, total);
    }
    return count;
}
