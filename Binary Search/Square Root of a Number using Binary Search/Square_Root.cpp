#include<bits/stdc++.h>
using namespace std;

int findSquareRoot(int n)
{
    if(n == 0)
    return 0;

    int low = 1;
    int high = n;
    int ans;
    while(low <= high)
    {
        long long mid = low + (high-low)/2;
        if(pow(mid,2) == n)
        return mid;
        else if(pow(mid,2) < n)
        {
            ans = mid;
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return ans;
}

double precision(int n , int precise , int value)
{
    double factor = 1;
    double ans = value;
    for(int i = 0 ; i<precise ; i++)
    {
        factor = factor/10;
        for(double j = ans ; j*j < n ; j += factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{
    int num;
    cin>>num;

    int root = findSquareRoot(num);
    cout<<"Square Root is: "<<precision(num,3,root);
    return 0;
}