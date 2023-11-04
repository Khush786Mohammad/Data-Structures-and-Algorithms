#include<iostream>
#include<vector>
using namespace std;

int lowerBound(vector<int>& arr , int n , int x)
{
    int low = 0;
    int high = n-1;
    int ans = n;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid] >= x)
        {
            ans = mid;
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return ans;
}

int upperBound(vector<int>& arr , int n , int x)
{
    int low = 0;
    int high = n-1;
    int ans = n;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid] > x)
        {
            ans = mid;
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return ans;  
}

int main()
{
    vector<int> v = {2,4,5,6,7,8,8,9,12,17,18,18,18,19,19,110};
    int n = v.size();
    int x = 18;
    int idx = lowerBound(v,n,x);
        cout<<"Lower Bound is at index: "<<idx;
    cout<<endl;

    int idx2 = upperBound(v,n,x);
        cout<<"Upper Bound is at index: "<<idx2;
    return 0;
}