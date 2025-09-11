#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <iostream>
using namespace std;

const int NUM_STUDENTS = 3;
const int NUM_GRADES = 3;

class Student {
public:
    string name;
    int grades[NUM_GRADES];
    Student(string studentName = "", int initGrades[NUM_GRADES] = nullptr);
    int calcAverage();
};

// helper function prototypes
int chooseStudent(Student arr[], int size);
void changeName(Student arr[], int size);
void displayAverage(Student arr[], int size);
void inputStudents(Student arr[], int size);
void enterGrades(Student arr[], int size);
void findHighestAverage(Student arr[], int size);
void allStudentsAverage(Student arr[], int size);
void display_menu();
int f_exit();

#endif
