#include "Student.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string cc;
    Student* S;
    Student S1;
    cout << "--------------------------------------------\n";
    cout << "Enter Total Number of Students: "; cin >> Tnum;
    cout << "--------------------------------------------\n";
    S = new Student[Tnum];

    cout << "           ENTER STUDENTS DATA\n";
    cout << "--------------------------------------------\n";

    for (int i = 0; i < Tnum; i ++ ) {
        S[i].EnterData();
        cout << "--------------------------------------------\n";
    }

    for (int i = 0; i < Tnum; i++) {
        S[i].DisplayCourses();
        cout << "--------------------------------------------\n";
    }

    for (int i = 0; i < Tnum; i++) {
        S[i].DisplayGrade();
        cout << "--------------------------------------------\n";
    }

    for (int i = 0; i < Tnum; i++) {
        S[i].Display();
        cout << "--------------------------------------------\n";
    }

    cout << "Which course do you want to compare? \nEnter Course Code: ";
    cin >> cc;
    cout << "--------------------------------------------\n";
    
    S1 = S1.comparesStudent(S, cc);
    cout<<"Name: " << S1.getName() << endl;
    S1.Display1Grade(cc);
    cout << "--------------------------------------------\n\n";

    Student :: sortStudents(S);
    cout << "--------------------------------------------\n";

    for (int i = 0; i < Tnum; i++) {
        cout << i + 1 << ". " << S[i].getName() << endl;
        cout << "--------------------------------------------\n";
    }


    return 0;
}


