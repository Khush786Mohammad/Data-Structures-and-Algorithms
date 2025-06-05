#include<bits/stdc++.h>
using namespace std;

int findFirstOccurence(vector<int>& nums , int n , int target)
{
    int low = 0;
    int high = n-1;
    int index = -1;

    while(low <=high)
    {
        int mid = low + (high - low)/2;
        if(nums[mid] == target)
        {
            index = mid;
            high = mid-1;
        }
        else if(nums[mid] > target)
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return index;
}

int findLastOccurence(vector<int>& nums , int n , int target)
{
    int low = 0;
    int high = n-1;
    int index = -1;

    while(low <=high)
    {
        int mid = low + (high-low)/2;
        if(nums[mid] == target)
        {
            index = mid;
            low = mid+1;
        }
        else if(nums[mid] > target)
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return index;
}

pair<int,int> firstAndLastOccurence(vector<int>& nums , int n , int target)
{
    int firstOccurence = findFirstOccurence(nums,n,target);
    int lastOccurence = findLastOccurence(nums,n,target);
    pair<int,int> p = make_pair(firstOccurence,lastOccurence);
    return p;
}

int main()
{
    vector<int> v = {2,4,6,8,8,8,11,13};
    int n = v.size();
    int target = 8;

    pair<int,int> ans = firstAndLastOccurence(v,n,target);
    cout<<ans.first<<" "<<ans.second;

    return 0;
}