#include<iostream>
using namespace std;

class student
{
    public: 

    string name;
    int roll_no;
    int student_id;

    void getdata(string name , int roll_no, int student_id)
    {
        this->name = name;
        this->roll_no = roll_no;
        this->student_id = student_id;
    } 
};

class son : public student
{
    public : 

    int age;

    void getdata(int age)
    {
        this->age = age;
    }
};

int main()
{
    son obj1;
    obj1.name = "Khush";
    obj1.roll_no = 14;
    obj1.student_id = 2094013;
    obj1.age = 21;
    cout<<obj1.name<<endl<<obj1.roll_no<<endl<<obj1.student_id<<endl<<obj1.age<<endl;

    return 0;
}