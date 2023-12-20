#include<iostream>
using namespace std;

class hero
{
    public : 

    int health;
    string position;
    static int playtime;


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
    static void func()
    {
        cout<<"Static function can only access to static data members: "<<playtime;
    }
};
int hero::playtime = 90;
int main()
{
    hero player1(95,"Striker");
    hero player2 = player1;
    cout<<"Player1 Position = "<<player1.position<<endl<<"Health = "<<player1.health;
    cout<<endl;
    cout<<"Player2 Position = "<<player2.position<<endl<<"Health = "<<player2.health;
    cout<<endl<<hero::playtime;
    player1.func();
    return 0;
}