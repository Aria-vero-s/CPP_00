#include "student.hpp"

int Student::calcAverage() {
    int sum = 0;
    for (int i = 0; i < NUM_GRADES; i++)
        sum = sum + grades[i];
    return sum / NUM_GRADES;
}

int chooseStudent(Student arr[], int size) {
    int j = 0;
    int student = 0;
    cout << "Select a student:" << endl;
    while (j < size)
    {
        cout << "[" << j << "]" << arr[j].name << endl;
        j++;
    }
    cin >> student;
    while (1)
    {
        if (student > size || student < 0)
        {
            student = 0;
            cout << "please type a valid option" << endl;
            cin >> student;
        }
        else
            break;
    }
    return (student);
}

void inputStudents(Student arr[], int size) {
    int i = 0;
    cout << "Enter 3 students names: " << endl;
    while (i < NUM_STUDENTS)
    {
        cin >> arr[i].name;
        i++;
    }
}

void enterGrades(Student arr[], int size) {
    int i = 0;
    int j = 0;
    cout << "Enter student's grades: " << endl;
    while (i < NUM_STUDENTS)
    {
        cout << "for: " << arr[i].name << endl;
        j = 0;
        while (j < NUM_GRADES)
        {
            cin >> arr[i].grades[j];
            j++;
        }
        i++;
    }
    cout << "Great! You've entered the grades of all 3 students" << endl;
}

int findHighestAverage(Student arr[], int size) {
    int i = 0;
    int j = 0;
    int average = 0;
    int temp = 0;
    while (j < NUM_STUDENTS)
    {
        average = arr[j].calcAverage();
        if (average > temp)
            temp = average;
        j++;
    }
    j = 0;
    cout << "The highest average is:" << temp << endl;
    while (j < NUM_STUDENTS)
    {
        average = arr[j].calcAverage();
        if (average == temp)
            break;
        else
            j++;
    }
    return (j);
}

void allStudentsAverage(Student arr[], int size) {
    int i = 0;
    int average = 0;
    cout << "all students average:" << endl;
    while (i < size)
    {
        cout << arr[i].name << endl;
        average = arr[i].calcAverage();
        cout << average << endl;
        cout << "---------------" << endl;
        i++;
    }
}
