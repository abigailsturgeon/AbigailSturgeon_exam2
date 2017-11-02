//empmult.cpp
//multiple inheritance with employees and degrees
#include <iostream>
using namespace std;
const int LEN = 80;           //maximum length of names
////////////////////////////////////////////////////////////////
class Student                 //educational background
{
private:
    char school[LEN];       //name of school or university
    char degree[LEN];       //highest degree earned
public:
    void getedu()
    {
        cout << "   Enter name of school or university: ";
        cin >> school;
        cout << "   Enter highest degree earned \n";
        cout << "   (Highschool, Bachelor's, Master's, PhD): ";
        cin >> degree;
    }
    void putedu() const
    {
        cout << "\n   School or university: " << school;
        cout << "\n   Highest degree earned: " << degree;
    }
};
////////////////////////////////////////////////////////////////
class Employee
{
private:
    char name[LEN];         //employee name
    unsigned long number;   //employee number
public:
    void getdata()
    {
        cout << "\n   Enter last name: "; cin >> name;
        cout << "   Enter number: ";      cin >> number;
    }
    void putdata() const
    {
        cout << "\n   Name: " << name;
        cout << "\n   Number: " << number;
    }
};
////////////////////////////////////////////////////////////////
class Manager : private Employee, private Student  //management
{
private:
    char title[LEN];        //"vice-president" etc.
    double dues;            //golf club dues
public:
    void getdata()
    {
        Employee::getdata();
        cout << "   Enter title: ";          cin >> title;
        cout << "   Enter golf club dues: "; cin >> dues;
        Student::getedu();
    }
    void putdata() const
    {
        Employee::putdata();
        cout << "\n   Title: " << title;
        cout << "\n   Golf club dues: " << dues;
        Student::putedu();
    }
};
////////////////////////////////////////////////////////////////
class Executive : public Manager
{
private:
    double bonus;
    double shares;
public:
    void getdata()
    {
        Manager::getdata();
        cout << "   Enter yearly bonus: ";
        cin >> bonus;
        cout << "   Enter share held in stock option plan: ";
        cin >> shares;
    }
    void putdata() const
    {
        Manager::putdata();
        cout << "\n   Yearly bonus: " << bonus;
        cout << "\n   Stock option shares: " << shares;
    }

};
int main()
{
    Manager m1;
    cout << endl;
    cout << "\nEnter data for manager 1";    //get data for
    m1.getdata();                            //several employees
    cout << "\nData on manager 1";           //display data for
    m1.putdata();                            //several employees

    Executive e1;
    cout << endl;
    cout << "\nEnter data for executive 1: ";
    e1.getdata();
    cout << "\nData on executive 1: ";
    e1.putdata();

    cout << endl;
    return 0;
}