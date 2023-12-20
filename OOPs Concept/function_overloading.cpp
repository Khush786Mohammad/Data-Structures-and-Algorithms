#include<iostream>
using namespace std;

class A
{
    public : 
    void func()
    {
        cout<<"Function with no arguments:\n";
    }
    void func(int a)
    {
        cout<<"Function with one arguments:\n";
    }
    void func(int a , int b , int c = 20 , int d = 30)
    {
        cout<<"Function with multiple arguments:\n";
    }
};

int main()
{
    A *obj1 = new A();
    obj1->func();
    obj1->func(2);
    obj1->func(2,3);
    obj1->func(2,3,4);
    return 0;
}