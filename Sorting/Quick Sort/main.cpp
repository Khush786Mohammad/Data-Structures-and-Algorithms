#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &nums , int lb , int ub)
{
    int pivot = nums[lb];
    int start = lb;
    int end = ub;

    while(start <= end)
    {
        while(pivot >= nums[start] && start < ub)
        {
            start++;
        }
        while(pivot < nums[end] && end > lb)
        {
            end--;
        }
        if(start < end)
        {
            swap(nums[start] , nums[end]);
        }
    }
    swap(nums[lb],nums[end]);
    return end;
}

void quickSort(vector<int>&nums, int low ,int high)
{
    if(low < high)
    {
        int loc = partition(nums,low,high);
        quickSort(nums,low,loc-1);
        quickSort(nums,loc+1,high);
    }
}

int main()
{
    vector<int> nums = {4,1,7,9,3};
    int n = nums.size();

    int low = 0;
    int high = n-1;
    quickSort(nums,low,high);

    for(auto it : nums)
    cout<<it<<" ";
    return 0;
}