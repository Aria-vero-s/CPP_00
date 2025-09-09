#include "student.hpp"

int main() {
    Student arr[NUM_STUDENTS];
    int j = 0;
    int input = 0;
    int student = 0;
    int temp = 0;
    int average = 0;

    inputStudents(arr, NUM_STUDENTS);
    enterGrades(arr, NUM_STUDENTS);
    while (1)
    {
        cout << "Select an option:" << endl << "[1]view a student's average grade" << endl;
        cout << "[2]modify an existing student's name" << endl << "[3]display the highest average student" << endl;
        cout << "[4]View all student's average" << endl << "[5]exit" << endl;
        cin >> input;
        if (input == 1)
        {
            student = chooseStudent(arr, NUM_STUDENTS);
            cout << arr[student].name << "'s average is: " << arr[student].calcAverage() << endl;
        }
        else if (input == 2)
        {
            student = chooseStudent(arr, NUM_STUDENTS);
            cout << "Type new name for :" << arr[student].name << endl;
            cin >> arr[student].name;
            cout << "Changed student's name to:" << arr[student].name << endl;
        }
        else if (input == 3)
        {
            j = findHighestAverage(arr, NUM_STUDENTS);
            cout << "The highest average goes to... " << arr[j].name << "!" << endl;
        }
        else if (input == 4)
            allStudentsAverage(arr, NUM_STUDENTS);
        else if (input == 5)
        {
            cout << "bye!" << endl;
            break;
        }
        else   
            cout << "please type a valid option (1,2,3 or 4)" << endl;
    }
    return 0;
}
