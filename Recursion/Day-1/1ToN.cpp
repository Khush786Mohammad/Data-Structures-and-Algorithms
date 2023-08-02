#include<iostream>
using namespace std;
// void f(int i , int n)
// {
//     if(i > n)
//     return ;
//     cout<<i<<" ";
//     i++;
//     f(i,n);
// }
void f(int n)
{
    if(n < 1)
    return ;
    cout<<n<<" ";
    n = n-1;
    f(n);
}
int main()
{
    int n;
    cin>>n;

    int i = 1;
    // f(i,n);
    f(n);
    return 0;
}