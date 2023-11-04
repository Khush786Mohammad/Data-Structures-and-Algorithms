#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& v , int n , int key)
{
    int low = 0;
    int high = n-1;

    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(v[mid] == key)
        return mid;

        else if(v[mid] > key)
        high = mid-1;

        else
        low = mid+1;
    }
    return -1;
}

int main()
{
    vector<int> v = {2,4,5,6,7,8,9,10};
    int n = v.size();
    int key = 9;
    int idx = binarySearch(v,n,key);
    if(idx == -1)
    {
        cout<<"Key element is not present";
    }
    else
    {
        cout<<"Key element is present at index "<<idx<<": "<<v[idx];
    }
    return 0;
}