#include<iostream>
#include<vector>
using namespace std;

int fibo(int n,vector<int>& dp)
{
    if(n <= 1)
    return n;
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2 ; i<=n ; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main()
{
    int num;
    cout<<"Enter a number\n";
    cin>>num;
    vector<int> dp(num,-1);
    cout<<fibo(num,dp);
    return 0;
}