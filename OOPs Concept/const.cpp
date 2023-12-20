/*
#include<iostream>
using namespace std;

class ABC{
    mutable int x ;
    int *y;

    public:
    ABC(){
        x = 0;
        y = new int(0);
    }

    int getX() const{
        x = x*2;
        return this->x;
    }

    void setX(int val){
        this->x = val;
    }

    void setY(int val){
        *y = val;
    }

    int getY(){
        return *y;
    }
};

class XYZ{
    int x;
    int y;
    int z;

    // initialization list
    XYZ(int _x , int _y, int _z): x(_x), y(_y),z(_z){}
};

int main()
{
    // const int x = 5;
    // cout<<x<<endl;

    // int *a = new int;
    // *a = 2;
    // cout<<*a<<endl;

    // const int *b = new int(10);//can't change the data but pointer can be reassign
    // cout<<*b<<endl;

    // int c = 20;
    // b = &c;

    // cout<<*b<<endl;

    // int *const a = new int(2);
    // cout<<*a<<endl;
    // *a = 222;
    // cout<<*a<<endl;
    // int b = 40;
    // a = &b;

    //const pointer and const data

    // const int *const a = new int(10);
    // cout<<*a<<endl;
    // int b = 30;
    // a = &b;
    // *a = 22;

    ABC xq;

    return 0;
}
*/

//macros

#include<iostream>
using namespace std;

#define pi 3.14

int main()
{
    cout<<"Area of circle"<<pi*5*5;

    return 0;
}