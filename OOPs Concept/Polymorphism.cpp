#include<iostream>
using namespace std;

class A
{
    public :
    void func()
    {
        cout<<"Function with no parameters\n";
    }
    void func(int i)
    {
        cout<<"Function with Integer Parameter\n";
    }
    void func(string s)
    {
        cout<<"Function with String Parameters:\n";
    }
};

int main()
{
    A obj1;
    obj1.func();
    obj1.func(10);
    obj1.func("khush");
    return 0;
}