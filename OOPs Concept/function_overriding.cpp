#include<iostream>
using namespace std;

class animal
{
    public:

    virtual void eating() = 0;
    
    virtual void size() = 0;
};

class dog : public animal
{
    public:
    void eating() override
    {
        cout<<"Dogs favouirate food is pedigree:\n";
    }
    void size() override
    {
     cout<<"Size of dog is about half meter:\n";
    }
};

int main()
{
    dog obj2;
    obj2.eating();
    obj2.size();
    return 0;
}