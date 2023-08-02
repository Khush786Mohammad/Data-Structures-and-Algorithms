#include<iostream>
using namespace std;

void f(int i, int n)
{
    if(i >= n)
    return ;
    i++;
    cout<<"Khush\n";
    f(i,n);
}
int main()
{
    int n;
    cin>>n;
    int i = 0;
    f(i,n);
    return 0;
}