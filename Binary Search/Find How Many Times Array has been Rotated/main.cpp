#include<bits/stdc++.h>
using namespace std;

void findRotation(vector<int>& v)
{
    int low = 0;
    int high = v.size()-1;

    int ans = v[0];

    while(low < high)
    {
        int mid = low + (high-low)/2;
        if(v[mid] >= v[0])
            low = mid+1;
        else
            high = mid;
    }

    if(v[high] < v[0])
        cout<<high;
    else
        cout<<v.size();
    
}

int main()
{
    vector<int> v = {5,6,7,8,9,4};
    findRotation(v);
    return 0;
}