#include<bits/stdc++.h>
using namespace std;

class hero
{
    public : 

    char *name;
    int health;
    string position;


   hero(int health , string position)
   {
    this->health = health;
    this->position = position;
   }

   void setname(char name[])
   {
    strcpy(this->name,name);
   }

    hero(const hero& h1)
    {
        this->health = h1.health;
        this->position = h1.position;
    }
    void display()
    {
        cout<<endl<<"Health = "<<health<<endl<<"position = "<<position<<endl;
    }    
};

int main()
{
    hero h1(90,"Striker");
    char name[] = "Ronaldo";
    h1.setname(name);

    h1.display();

    
   return 0;
}