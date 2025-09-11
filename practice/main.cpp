#include <iostream>
using namespace std;

const int NUM_GRADES = 3;

class Student {
public:
    string name;
    int grades[NUM_GRADES];

    // Constructor with defaults
    Student(string initName = "Unnamed", int initGrades[] = nullptr) {
        name = initName;
        if (initGrades != nullptr) {
            for (int i = 0; i < NUM_GRADES; i++) {
                cout << "if" << endl;
                grades[i] = initGrades[i];
            }
        } else {
            for (int i = 0; i < NUM_GRADES; i++) {
                cout << "else" << endl;
                grades[i] = 0; // safe default
            }
        }
    }

    void printGrades() {
        cout << name << "'s grades: ";
        for (int g : grades) cout << g << " ";
        cout << endl;
    }
};

int main() {
    int paulGrades[NUM_GRADES] = {10, 10, 10};
    Student s1("Paul", paulGrades); // uses Paul's grades
    cout << "test" << endl;
    Student s2;                     // no grades passed → defaults to 0

    s1.printGrades(); // Paul’s grades: 10 10 10
    s2.printGrades(); // Unnamed’s grades: 0 0 0
}