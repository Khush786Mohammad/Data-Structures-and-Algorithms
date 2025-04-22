#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums, int low , int mid, int high)
{
    int i = low;
    int j = mid+1;
    int n = high-low+1;
    vector<int> temp;

    while(i<=mid && j<=high)
    {
        if(nums[i] < nums[j])
        {
            temp.push_back(nums[i++]);
        }
        else
        {
            temp.push_back(nums[j++]);
        }
    }
    while(i<=mid)
    {
        temp.push_back(nums[i++]);
    }
    while(j<=high)
    {
        temp.push_back(nums[j++]);
    }
    for(int p = 0, q=low ; p<n ; p++,q++)
    {
        nums[q] = temp[p];
    }
}

void mergeSort(vector<int>& nums, int low , int high)
{
    if(low < high)
    {
        int mid = low +(high-low)/2;
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        merge(nums,low,mid,high);
    }
}

int main()
{
    vector<int> nums = {3,2,8,5,1,4,6};
    mergeSort(nums,0,nums.size()-1);
    for(int obj: nums)
    {
        cout<<obj<<" ";
    }
    return 0;
}