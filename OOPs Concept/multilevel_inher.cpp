#include<iostream>
using namespace std;

class A
{
    public : 
    void func()
    {
        cout<<"Inside Class A\n";
    }
};
class B
{
    public :
    void func()
    {
        cout<<"Inside Class B:\n";
    }
};
class C : public A,public B
{
    public :
    C()
    {
        cout<<"Constructor of C\n";
    }
};

int main()
{
    C obj1;
    cout<<"JSKJFL\n";
    obj1.A::func();
    obj1.B::func();
    return 0;
}