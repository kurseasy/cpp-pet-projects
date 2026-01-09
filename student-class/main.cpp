#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int grade;

    Student(string n, int g) : name(n), grade(g) {}

    void printInfo() {
        cout << name << " имеет оценку " << grade << endl;
    }
};

int main() {
    Student s("Milana", 10);
    s.printInfo();
    return 0;
}
