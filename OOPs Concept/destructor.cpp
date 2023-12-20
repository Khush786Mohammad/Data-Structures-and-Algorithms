#include<iostream>
using namespace std;

class hero
{
    public : 

    int health;
    string position;

   hero(int health , string position)
   {
    this->health = health;
    this->position = position;
   }
    hero(const hero& h1)
    {
        this->health = h1.health;
        this->position = h1.position;
    }
   
    ~hero()
    {
        cout<<"Destructor is called\n";
    }
};

int main()
{
    hero player1(95,"Striker");

    cout<<"Player1 Position = "<<player1.position<<endl<<"Health = "<<player1.health<<endl;
    cout<<endl;
    
    hero *player2 = new hero(player1);
    cout<<"Player2 Position = "<<player2->position<<endl<<"Health = "<<player2->health<<endl;

    delete player2;
    
    
    return 0;
}