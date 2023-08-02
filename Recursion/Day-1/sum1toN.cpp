#include<iostream>
using namespace std;

// void sumission(int i ,int &sum)
// {
//     if(i < 1)
//     {
//         cout<<sum;
//         return;
//     }
//     sum += i;
//     i--;
    
//     sumission(i,sum);
// }
int sumi(int n)
{
    if(n == 0)
    return 0;
    return n + sumi(n-1);
}
int main()
{
    int n;
    cin>>n;

    int sum = 0;
    int i = n;
    // sumission(i,sum);
    cout<<sumi(n);
    return 0;

}