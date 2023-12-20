//Different access modifier public , protected , private inheritance
#include<iostream>
using namespace std;

class super
{
    public:

    int roll_no;
};

class sub : protected super
{
    public:

    int getdata(int var)
    {
        return this->roll_no = var;
    }
};

int main()
{
    sub obj1;
    
    
    cout<<obj1.getdata(14)<<endl;

    return 0;
}


