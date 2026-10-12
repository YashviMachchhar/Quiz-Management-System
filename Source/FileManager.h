#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include "Question.h"
#include "Attempt.h"
#include <string>
using namespace std;

class FileManager {
public:
    static void saveQuestions(const Question questions[], int count, const string& filename);
    static int loadQuestions(Question questions[], int capacity, const string& filename);
    static void saveAttempts(const Attempt attempts[], int count, const string& filename);
    static int loadAttempts(Attempt attempts[], int capacity, const string& filename);
};
#endif
