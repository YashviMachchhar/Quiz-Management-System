#include "QuizSystem.h"
#include <iostream>
#include <exception>
using namespace std;

int main() {
    try {
        QuizSystem system;
        system.loadData();
        system.run();
    } catch (const exception& e) {
        cout << "Program error: " << e.what() << endl;
    }
    return 0;
}
