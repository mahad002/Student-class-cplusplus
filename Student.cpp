#include "../Assignment 2_Q1/Student.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

Student::Student()
{
    rollno = 0;
    name = "";
    batch = 0;
    no_courses = 0;
    CGPA = 0.0;
    degree = "";
    month = 0;
    day = 0;
    year = 0;
    dob = to_string(month) + "/" + to_string(day) + "/" + to_string(year);
    //Tnum++;
}

Student::Student(string s) :Student()
{
    name = s;
    //Tnum++;
}

Student::Student(double rnum) :Student()
{
    CGPA = rnum;
    //Tnum++;
}

Student::Student(const Student& S1)
{
    rollno = S1.rollno;
    name = S1.name;
    batch = S1.batch;
    no_courses = S1.no_courses;
    course = new Course [no_courses];

    for (int i = 0; i < no_courses; i++)
    {
        course[i].ccode = S1.course[i].ccode;
        course[i].cname = S1.course[i].cname;
        course[i].cgrade = S1.course[i].cgrade;
    }
    CGPA = S1.CGPA;
    degree = S1.degree;
    month = S1.month;
    day = S1.day;
    year = S1.year;
    dob = to_string(month) + "/" + to_string(day) + "/" + to_string(year);
    //cout << "This Is Done Too\n";
    //Tnum++;
}

Student:: ~Student()
{
    delete[] course;
}

void Student::EnterData()
{
    cout << "Enter Roll Number: \n";
    cin >> rollno;
    cin.clear();
    cin.ignore();
    cout << "Enter Name: \n";
    getline(cin, name);

    cout << "Enter Batch Year" << BOLD_FONTTYPE << "(Note; Only write the last two digits e.g 21, 20, 19): \n";
    cin >> batch;

    cout << "Enter No of Courses: \n";
    cin >> no_courses;

    course = new Course [no_courses];
    cin.clear();
    cin.ignore();
    for (int i = 0; i < no_courses; i++)
    {
        cout << "Enter Course " << i+1 << " Code: ";
        getline(cin,course[i].ccode);
        cout << "Enter Course " << i+1 << " Name: ";
        getline(cin, course[i].cname);
        cout << "Enter Course " << i + 1 << " Grade: ";
        cin >> course[i].cgrade;
        cin.clear();
        cin.ignore();
    }

    cout << "Enter CGPA: " << endl;
    cin >> CGPA;

    cout << "Enter Degree: " << endl;
    cin >> degree;

    cout << "Enter Month of Birth: ";
    cin >> month;
    cout << "Enter Day of Birth: ";
    cin >> day;
    cout << "Enter Year of Birth: ";
    cin >> year;

    cin.clear();
    cin.ignore();

    dob = to_string(month) + "/" + to_string(day) + "/" + to_string(year);

    cout << endl << endl;
}

void Student::DisplayCourses()
{
    cout << "--------------------------------------------\n";
    cout << "            Courses\n";
    cout << "--------------------------------------------\n";
    for (int i = 0; i < no_courses; i++)
    {
        cout << i + 1 <<course[i].ccode << "\t" << course[i].cname << endl;
    }
    cout << "--------------------------------------------\n\n";
}

void Student::DisplayGrade()
{
    cout << "--------------------------------------------\n";
    cout << "            Courses\n";
    cout << "--------------------------------------------\n";
    for (int i = 0; i < no_courses; i++)
    {
        cout << i + 1 << course[i].ccode << "\t" << course[i].cname << "\tGrade: "<<course[i].cgrade << endl;
    }
    cout << "--------------------------------------------\n\n";

}
void Student::Display1Grade(string c)
{
    cout << "--------------------------------------------\n";
    cout << "            Courses\n";
    cout << "--------------------------------------------\n";
    for (int i = 0; i < no_courses; i++)
    {
        if(course[i].ccode==c)
            cout <<"Code: "<< course[i].ccode << "\t" << course[i].cname << "\tGrade: " << course[i].cgrade << endl;
    }
    cout << "--------------------------------------------\n\n";

}


void Student::Display()
{
    cout << "--------------------------------------------\n";
    cout << "          Transcript\n";
    cout << "--------------------------------------------\n";
    cout << "Roll Number: " << rollno << endl;
    cout << "Name: " << name << endl;
    cout << "Batch: " << batch << endl;
    cout << "Degree: " << degree << endl;
    cout << "COURSES\n\n";
    for (int i = 0; i < no_courses; i++)
    {
        cout << i + 1 << course[i].ccode << "\t" << course[i].cname << "\tGrade: " << course[i].cgrade << endl;
    }
    cout << "CGPA: " << CGPA << endl;
    cout << "DOB: " << dob << endl;
    cout << "--------------------------------------------\n\n";

}

Student Student ::comparesStudent(Student*& S1, string c)
{
    int max=0;
    for (int i = 0; i < Tnum; i++) {
        for (int j = 0; j < S1[i].getNo_courses(); j++) {
            if (S1[i].getCourseCode(j) == c) {
                max = i;
            }
        }
    }

    for (int i = 0; i < Tnum; i++)
    {
        for (int j = 0; j < S1[i].getNo_courses(); j++)
        {
            if ((S1[i].getCourseGrade(j) < S1[max].getCourseGrade(j)) && (S1[i].getCourseCode(j) == c))
            {
                max=i;
            }
        }
    }
    return S1[max];
}

void Student::sortStudents(Student *& S1)
{
    Student temp;
    int j;
    bool nomoreswaps = false;
    while (nomoreswaps == false)
    {
        nomoreswaps = true;
        for (j = 0; j < Tnum; j++)
        {
            if (S1[j].CGPA < S1[j + 1].CGPA)
            {
                temp = S1[j];
                S1[j] = S1[j + 1];
                S1[j + 1] = temp;
                nomoreswaps = false;
            }
        }
    }
}