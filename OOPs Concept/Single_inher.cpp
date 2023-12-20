#include<iostream>
using namespace std;

class Dog
{
    public :
    int weights;
    string color;
    void getdata(int wei , string col)
    {
        this->weights = wei;
        this->color = col;
    }
    void display();

};

class German_Sepherd : public Dog
{
    public :
    int population;
    void getdata(int pop)
    {
        population = pop;
    }
    void display()
    {
        cout<<"Population of German Sepherd = "<<this->population<<endl;
        cout<<"Average Weights of Dog = "<<weights<<endl;
        cout<<"Color of German Sepherd = "<<color<<endl;
    }
};

int main()
{
    Dog obj2;
    German_Sepherd obj1;
    obj1.weights = 72;
    obj1.color = "Brown";
    obj1.getdata(2000);
    obj1.display();
    return 0;
}