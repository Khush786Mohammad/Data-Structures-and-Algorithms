/*
     * 
    * *
   *   *
  *     *
 *       *

*/
#include<iostream>
using namespace std;

int main(){
     int n ;
    cin>> n;

    for(int i = 0 ; i<n ; i++)
    {
        for(int space = n-1-i ; space>=0 ; space--)
        {
            cout<<" ";
        }
        for(int j = 0 ; j<=i ;j++)
        {
            if(j == 0 || j == i)
        {
            cout<<"*"<<" ";
        }
        else
        {
            cout<<" "<<" ";
        }
        }
        cout<<endl;
    }
    return 0;
}

   
