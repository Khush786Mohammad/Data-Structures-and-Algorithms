#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& arr , int n , int target)
{
    int low = 0;
    int high = n-1;
    int pos = n;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid] >= target)
        {
            pos = mid;
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return pos;
}

int main()
{
    vector<int> v = {1,3,5,6};

    int n = v.size();
    int key = 7;
    int idx = binarySearch(v,n,key);
    cout<<"Insert Index is: "<<idx;
    return 0;
}