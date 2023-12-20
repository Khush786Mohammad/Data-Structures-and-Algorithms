#include<iostream>
using namespace std;

class hero
{
    public : 
    
    string name;
    int health;
    string position;


   hero(string name , int health , string position)
   {
    this->name = name;
    this->health = health;
    this->position = position;
   }
    hero(const hero& h1)
    {
        this->name = h1.name;
        this->health = h1.health;
        this->position = h1.position;
    }
    void display()
    {
        cout<<"Name = "<<name<<endl<<"Health = "<<health<<endl<<"Position = "<<position<<endl;
    }
    
};

int main()
{
    hero h1("Pual" , 90 , "Reaper");
    h1.display();
    hero h2("Lucifer",80,"Smasher");
    h2.display();

    h1=h2;
    h1.display();
    return 0;
}