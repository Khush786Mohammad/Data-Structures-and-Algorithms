#include<bits/stdc++.h>
using namespace std;

int findFirstOccurence(vector<int>& v, int low , int high , int target)
{
    int ans = -1;

    while(low<=high)
    {
        int mid = low+(high-low)/2;
        if(v[mid] == target)
            ans = mid;
        if(v[mid] >= target)
            high = mid-1;
        else
            low = mid+1;
    }
    return ans;
}

int findSecondOccurence(vector<int>& v , int low , int high , int target)
{
    int ans = -1;
    while(low <= high)
    {
        int mid = low+(high-low)/2;
        if(v[mid] == target)
            ans = mid;
        if(v[mid] <= target)
            low = mid+1;
        else
            high = mid-1;
    }
    return ans;
}

int countOccurence(vector<int>& v , int target)
{
    int low = 0;
    int high = v.size()-1;

    int first = findFirstOccurence(v,low,high,target);
    if(first == -1)
        return 0;
    int second = findSecondOccurence(v,low,high,target);

    return second-first+1;
}

int main()
{
    vector<int> v = {2,3,4,5,5,5,5,5,5,6,7,8,9};
    int target = 61;
    int ans = countOccurence(v,target);
    cout<<ans;
    return 0;
}