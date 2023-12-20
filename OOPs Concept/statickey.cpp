#include<iostream>
using namespace std;

class Student
{
    public :
    static int marks;
    static string name;
    
    // Student(int marks,string name){
    //     this->marks = marks;
    //     this->name = name;
        
    //     cout<<name<<":"<<marks;
    // }

    void print() const{
        cout<<name<<" "<<marks;
    }
};

int Student::marks;
string Student::name;

int main()
{
    Student s1;
    s1.marks = 20;
    s1.name = "khush";
    s1.print();

    Student s2;
    s2.marks = 30;
    s2.name="Loki";
    s2.print();
    s1.print();
    return 0;
}