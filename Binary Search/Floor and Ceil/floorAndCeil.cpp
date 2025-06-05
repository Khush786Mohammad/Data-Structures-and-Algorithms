#include<iostream>
#include<vector>
using namespace std;

int floor(vector<int>& arr , int x , int n)
{
    int low = 0;
    int high = n-1;

    int pos = -1;

    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid] <=x )
        {
            pos = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return pos;
}

int ceil(vector<int>& arr , int x , int n)
{
    int low = 0;
    int high = n-1;
    int pos = -1;

    while(low <=high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid] >= x)
        {
            pos = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return pos;
}

int main()
{
    vector<int> v = {3, 4, 4, 7, 8, 10};
    int x = 2;
    int n = v.size();
    int floor_idx = floor(v,x,n);
    int ceil_idx = ceil(v,x,n);

    if(floor_idx != -1)
    {
        cout<<"Floor Value is: "<<v[floor_idx];
    }
    else{
        cout<<"Floor Value does not exist";
    }
    cout<<endl;

    if(ceil_idx != -1)
    {
        cout<<"Ceil Value is: "<<v[ceil_idx];
    }
    else{
        cout<<"Ceil Value does not exist";
    }
    return 0;
}