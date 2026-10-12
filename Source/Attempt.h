#ifndef ATTEMPT_H
#define ATTEMPT_H
class Attempt {
private:
    int studentId;
    int score;
    int total;
public:
    Attempt();
    Attempt(int id, int s, int t);
    ~Attempt();
    int getStudentId() const;
    int getScore() const;
    int getTotal() const;
    void display() const;
};
#endif
