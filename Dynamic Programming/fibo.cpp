#include<iostream>
#include<vector>
using namespace std;

int fibo(int n,vector<int>& dp)
{
    if(n == 0)
    return 0;

    else if(n == 1)
    return 1;

    else 
    if(dp[n] != -1)
    return dp[n];
    return dp[n] = fibo(n-1,dp)+fibo(n-2,dp);
}

int main()
{
    int num;
    cout<<"Enter a number\n";
    cin>>num;
    vector<int> dp(num+1,-1);
    cout<<fibo(num,dp);
    return 0;
}