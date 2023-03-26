#include <iostream>

using namespace std;

static int Tnum;;

class Student {
private:
    int rollno;
    string name;
    int batch;
    int no_courses;
    class Course {
    public:
        string ccode;
        string cname;
        char cgrade;
    }*course;
    //Course *course;
    double CGPA;
    string degree;
    int month;
    int day;
    int year;
    string dob;
    //static int Tnum = 0;
public:
    // provide definitions of following functions...
    Student();// default constructor
    Student(string str);
    Student(double);
    Student(const Student&);
    void EnterData();
    //implement mutators for all private data members
    //implement accessors for all private data members
    //you have to implement the following functions think about the parameters required and return type of the followingfunctions
    void DisplayCourses();//displays the courses Student is registered in
    void DisplayGrade();//display grades in each course
    void Display1Grade(string);
    void Display();//displays the transcript
    //string name();
    Student comparesStudent(Student *&, string);//static function that returns the student with better score in a given course
    static void sortStudents(Student *&);//static function that sorts the students in ascending order onthe basis of GPA
    ~Student();

    int getRollno() {
        return this->rollno;
    }
    void setRollno(int rollno) {
        this->rollno = rollno;
    }
    string getName() {
        return this->name;
    }
    void setName(string name) {
        this->name = name;
    }
    int getBatch() {
        return this->batch;
    }
    void setBatch(int batch) {
        this->batch = batch;
    }


    int getNo_courses() {
        return this->no_courses;
    }
    void setNo_courses(int no_courses) {
        this->no_courses = no_courses;
    }

    string getCourseCode(int i) {
        return course[i].ccode;
    }
    void setCourseCode(string c, int i) {
        course[i].ccode = c;
    }
    string getCourseName(int i) {
        return course[i].cname;
    }
    void setCourseName(string c, int i) {
        course[i].cname = c;
    }
    char getCourseGrade(int i) {
        return course[i].cgrade;
    }
    void setCourseGrade(char c, int i) {
        course[i].cgrade = c;
    }


    double getCGPA() {
        return this->CGPA;
    }
    void setCGPA(double CGPA) {
        this->CGPA = CGPA;
    }


    string getDegree() {
        return this->degree;
    }
    void setDegree(string degree) {
        this->degree = degree;
    }


    int getMonth() {
        return this->month;
    }
    void setMonth(int month) {
        this->month = month;
    }


    int getDay() {
        return this->day;
    }
    void setDay(int day) {
        this->day = day;
    }


    int getYear() {
        return this->year;
    }
    void setYear(int year) {
        this->year = year;
    }


    string getDob() {
        return this->dob;
    }
    void setDob(string dob) {
        this->dob = dob;
    }

};


