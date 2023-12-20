// #include<iostream>
// using namespace std;

// class hero
// {
//    private: 

//    int health;
//    string name;

//    //setter method
//    public:

//    void getdata(int health , string name)
//    {
//     this->health = health;
//     this->name = name;
//    }
//    //getter method
//    int gethealth()
//    {
//     return health;
//    }
//    string getname()
//    {
//     return name;
//    }
// };

// int main()
// {
//     hero h1;
//     h1.getdata(90,"khush");
//     cout<<"Name is : "<<h1.gethealth()<<endl;
//     cout<<"Health = "<<h1.getname()<<endl;

//     cout<<sizeof(h1);
//     return 0;
// }

#include<iostream>
using namespace std;

class hero
{
   private: 

   int health;
   string name;

   //setter method
   public:

   void getdata(int health , string name)
   {
    this->health = health;
    this->name = name;
   }
   //getter method
   int gethealth()
   {
    return health;
   }
   string getname()
   {
    return name;
   }
};

int main()
{
    cout<<"Static Memory Allocation:\n";
    hero h1;//static allocation of objects;
    h1.getdata(80,"khush");

    cout<<"Name is : "<<h1.gethealth()<<endl;
    cout<<"Health = "<<h1.getname()<<endl;

    hero *h2 = new hero;
    h2->getdata(100,"Malton");

    cout<<"Dynamic Memory Allocation:\n";

    cout<<"Name is : "<<(*h2).gethealth()<<endl;
    cout<<"Health = "<<(*h2).getname()<<endl;
    return 0;
}