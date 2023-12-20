/*

 * * * * * 
  * * * *  
   * * *   
    * *
     *

*/
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    for(int row = n ; row > 0 ; row--)
    {
        for(int space = n-row; space>= 0 ; space--)
        cout<<" ";
        for(int col = row ; col>0 ; col--)
        {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    return 0;
}

   
