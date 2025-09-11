#include "student.hpp"

Student::Student(string studentName, int initGrades[NUM_GRADES]) {
    name = studentName;
    if (initGrades != nullptr) {
        for (int i = 0; i < NUM_GRADES; i++)
            grades[i] = initGrades[i];
    } else {
        for (int i = 0; i < NUM_GRADES; i++)
            grades[i] = 0; // default to 0
    }
}

int Student::calcAverage() {
    int sum = 0;
    for (int i = 0; i < NUM_GRADES; i++)
        sum = sum + grades[i];
    return sum / NUM_GRADES;
}

void displayAverage(Student arr[], int size) {
    int student = 0;
    student = chooseStudent(arr, NUM_STUDENTS);
    cout << arr[student].name << "'s average is: " << arr[student].calcAverage() << endl;
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

void    changeName(Student arr[], int size) {
    int student = 0;
    student = chooseStudent(arr, NUM_STUDENTS);
    cout << "Type new name for :" << arr[student].name << endl;
    cin >> arr[student].name;
    cout << "Changed student's name to:" << arr[student].name << endl;
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

void findHighestAverage(Student arr[], int size) {
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
    cout << "The highest average goes to... " << arr[j].name << "!" << endl;
    return ;
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

void    display_menu() 
{
    cout << "Select an option:" << endl << "[1]view a student's average grade" << endl;
    cout << "[2]modify an existing student's name" << endl << "[3]display the highest average student" << endl;
    cout << "[4]View all student's average" << endl << "[5]exit" << endl;
}

int f_exit()
{
    cout << "bye!" << endl;
    return (0);
}
