#include<iostream>
using namespace std;

int main()
{
    int n ;
    cin>>n;

    for(int i = 0 ; i<n/2 ; i++)
    {
        for(int j = 0 ; j<=n/2-i ; j++)
        {
            cout<<"*";
        }
        for(int space = 0 ; space < 2*i+1 ; space++)
        {
            cout<<" ";
        }
        for(int k = n/2-i ; k>0 ; k--)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i = 0 ; i<n/2 ; i++)
    {
        for(int j = 0 ; j<=i ; j++)
        {
            cout<<"*";
        }
        for(int space = 2*(n/2 - i)-1 ; space>0 ; space--)
        {
            cout<<" ";
        }
        for(int j = 0 ; j<=i ;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}